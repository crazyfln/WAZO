// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "PlayVideoActiveX.h"
#include "MainDialog.h"
#include "afxdialogex.h"


// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{
	m_LoginID = 0;
	m_hPlayBack = 0;
	m_nChannelCount = 0;
	m_nChannelID = 0;
}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)

END_MESSAGE_MAP()


// CMainDialog 消息处理程序


void CMainDialog::OnBtnLogin(LPCTSTR strIPAddress, USHORT nPort, LPCTSTR strUsername, LPCTSTR strPassword)
{
	// TODO: 在此添加控件通知处理程序代码

	int err = 0;	//Storage the possible returned errror value
	char* pchDVRIP = (LPSTR)(LPCSTR)strIPAddress;
	WORD wDVRPort = (WORD)nPort;
	char *pchUserName = (LPSTR)(LPCSTR)strUsername;
	char *pchPassword = (LPSTR)(LPCSTR)strPassword;
	//Device message
	NET_DEVICEINFO deviceInfo;
	//Call login interface
	LLONG lRet = CLIENT_LoginEx(pchDVRIP, wDVRPort, pchUserName, pchPassword, EM_LOGIN_SPEC_CAP_TCP, NULL, &deviceInfo, &err);
	if (0 == lRet)
	{
		//Display log in failed reason
		ShowLoginErrorReason(err);
	}
	else
	{
		m_LoginID = lRet;
		m_nChannelCount = deviceInfo.byChanNum;
	}

}


BOOL CMainDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitNetSDK();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//Initialize net SDK
void CMainDialog::InitNetSDK()
{
	BOOL ret = CLIENT_Init(DisConnectFunc, (LDWORD)this);
	if (!ret)
	{
		CWnd::MessageBox("Initialize SDK failed!", "Prompt");
	}
}

//Callback function when device disconnected
void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
	if (dwUser == 0)
	{
		return;
	}
	CMainDialog *dlg = (CMainDialog *)dwUser;
	dlg->DeviceDisConnect(lLoginID, pchDVRIP, nDVRPort);
}

//Process status callback
void CALLBACK DownLoadPosCallBackFunc(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser)
{
	if (dwUser == 0)
		return;

	CMainDialog *dlg = (CMainDialog *)dwUser;
	if (dwDownLoadSize == -1)
		dlg->OnButtonStop();
}

//Process when device disconnected.
void CMainDialog::DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort)
{
	//Add device disconnection process code
	CWnd::MessageBox("Network disconnected!", "Prompt");
}

//Display log in failure reason
void CMainDialog::ShowLoginErrorReason(int nError)
{
	if (1 == nError)		CWnd::MessageBox("Invalid password!", "Prompt");
	else if (2 == nError)	CWnd::MessageBox("Invalid account!", "Prompt");
	else if (3 == nError)	CWnd::MessageBox("Timeout!", "Prompt");
	else if (4 == nError)	CWnd::MessageBox("The user has logged in!", "Prompt");
	else if (5 == nError)	CWnd::MessageBox("The user has been locked!", "Prompt");
	else if (6 == nError)	CWnd::MessageBox("The user has listed into illegal!", "Prompt");
	else if (7 == nError)	CWnd::MessageBox("The system is busy!", "Prompt");
	else if (9 == nError)	CWnd::MessageBox("You Can't find the network server!", "Prompt");
	else	CWnd::MessageBox("Login failed!", "Prompt");
}

void CMainDialog::OnBtnLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	if (0 != m_hPlayBack)
	{
		CLIENT_StopPlayBack(m_hPlayBack);
		m_hPlayBack = 0;
	}

	BOOL bRet = CLIENT_Logout(m_LoginID);
	//Log off and then clear log in handle
	if (bRet)
	{
		m_LoginID = 0;
		m_nChannelCount = 0;
	}
	else
	{
		CWnd::MessageBox("Logout failed!", "Prompt");
	}
}

int CMainDialog::Compare(const NET_TIME *pSrcTime, const NET_TIME *pDestTime)
{
	SYSTEMTIME srcTime = { 0 }, destTime = { 0 };
	
	srcTime.wYear = (WORD)pSrcTime->dwYear;
	srcTime.wMonth = (WORD)pSrcTime->dwMonth;
	srcTime.wDay = (WORD)pSrcTime->dwDay;
	srcTime.wHour = (WORD)pSrcTime->dwHour;
	srcTime.wMinute = (WORD)pSrcTime->dwMinute;
	srcTime.wSecond = (WORD)pSrcTime->dwSecond;

	destTime.wYear = (WORD)pDestTime->dwYear;
	destTime.wMonth = (WORD)pDestTime->dwMonth;
	destTime.wDay = (WORD)pDestTime->dwDay;
	destTime.wHour = (WORD)pDestTime->dwHour;
	destTime.wMinute = (WORD)pDestTime->dwMinute;
	destTime.wSecond = (WORD)pDestTime->dwSecond;
	FILETIME srcFileTime = { 0 }, destFileTime = { 0 };
	SystemTimeToFileTime(&srcTime, &srcFileTime);
	SystemTimeToFileTime(&destTime, &destFileTime);
	return CompareFileTime(&srcFileTime, &destFileTime);
}

//Close video 
void CMainDialog::ClosePlayBack()
{
	//Close video directly
	if (0 != m_hPlayBack)
	{
		CLIENT_StopPlayBack(m_hPlayBack);
		m_hPlayBack = 0;
	}
}


void CMainDialog::OnButtonPlay(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond)
{
	// TODO: 在此添加控件通知处理程序代码
	bool bPlaySuccess = false;

	if (0 != m_LoginID)
	{
		ClosePlayBack();
		m_hPlayBack = 0;

		//Time
		NET_TIME netTimeFrom, netTimeTo;
		netTimeFrom.dwYear = nStartYear;
		netTimeFrom.dwMonth = nStartMonth;
		netTimeFrom.dwDay = nStartDay;
		netTimeFrom.dwHour = nStartHour;
		netTimeFrom.dwMinute = nStartMinute;
		netTimeFrom.dwSecond = nStartSecond;
		netTimeTo.dwYear = nEndYear;
		netTimeTo.dwMonth = nEndMonth;
		netTimeTo.dwDay = nEndDay;
		netTimeTo.dwHour = nEndHour;
		netTimeTo.dwMinute = nEndMinute;
		netTimeTo.dwSecond = nEndSecond;

		if (Compare(&netTimeFrom, &netTimeTo) >= 0)
		{
			CWnd::MessageBox("Invalid time!", "Prompt");
			return;
		}

		HWND hPlayBack = GetDlgItem(IDC_SCREEN_PLAYBACK)->m_hWnd;

		for (int i = 0; i < 10; i++)
		{
			LLONG lHandle = CLIENT_PlayBackByTimeEx(m_LoginID, nChannel, &netTimeFrom, &netTimeTo, hPlayBack, DownLoadPosCallBackFunc, (LDWORD)this, 0, 0);
			if (0 != lHandle)
			{
				m_nChannelID = nChannel;
				m_hPlayBack = lHandle;
				bPlaySuccess = true;
				break;
			}
			else
				Sleep(1000);
		}

		if (!bPlaySuccess)
			CWnd::MessageBox("Playback failed!", "Prompt");
	}
	else
		CWnd::MessageBox("Please login first!", "Prompt");
}

void CMainDialog::OnButtonStop()
{
	if (0 != m_hPlayBack)
	{
		ClosePlayBack();
		m_hPlayBack = 0;
		GetDlgItem(IDC_SCREEN_PLAYBACK)->Invalidate();
	}
}
