// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "PlayVideoActiveX.h"
#include "MainDialog.h"
#include "afxdialogex.h"

CMainDialog *g_dlg;

// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{
	m_LoginID = 0;
	m_nChannelCount = 0;

	for (int i = 0; i < MAX_CHANNELS; i++)
	{
		m_hPlayBack[i] = 0;
		m_Wnd[i] = 0;
	}
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
		g_dlg = this;
		m_Wnd[0] = GetDlgItem(IDC_SCREEN_PLAYBACK1);
		m_Wnd[1] = GetDlgItem(IDC_SCREEN_PLAYBACK2);
		m_Wnd[2] = GetDlgItem(IDC_SCREEN_PLAYBACK3);
		m_Wnd[3] = GetDlgItem(IDC_SCREEN_PLAYBACK4);
		m_Wnd[4] = GetDlgItem(IDC_SCREEN_PLAYBACK5);
		m_Wnd[5] = GetDlgItem(IDC_SCREEN_PLAYBACK6);
		m_Wnd[6] = GetDlgItem(IDC_SCREEN_PLAYBACK7);
		m_Wnd[7] = GetDlgItem(IDC_SCREEN_PLAYBACK8);
		m_Wnd[8] = GetDlgItem(IDC_SCREEN_PLAYBACK9);

		/*CString strMsg, strTemp;
		strMsg.Format("Login success! LoginID = %d\n", m_LoginID);
		for (int i = 0; i < MAX_CHANNELS; i++)
		{
			strTemp.Format("HWND[%d] = %d\n", i, m_Wnd[i]->m_hWnd);
			strMsg += strTemp;
		}
		MessageBox(strMsg, "Prompt");*/
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
		MessageBox("Initialize SDK failed!", "Prompt");
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

	int nChannel = (int)dwUser;
	if (dwDownLoadSize == -1)
		g_dlg->ClosePlayBack(nChannel);
}

//Process when device disconnected.
void CMainDialog::DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort)
{
	//Add device disconnection process code
	MessageBox("Network disconnected!", "Prompt");
}

//Display log in failure reason
void CMainDialog::ShowLoginErrorReason(int nError)
{
	if (1 == nError)		MessageBox("Invalid password!", "Prompt");
	else if (2 == nError)	MessageBox("Invalid account!", "Prompt");
	else if (3 == nError)	MessageBox("Timeout!", "Prompt");
	else if (4 == nError)	MessageBox("The user has logged in!", "Prompt");
	else if (5 == nError)	MessageBox("The user has been locked!", "Prompt");
	else if (6 == nError)	MessageBox("The user has listed into illegal!", "Prompt");
	else if (7 == nError)	MessageBox("The system is busy!", "Prompt");
	else if (9 == nError)	MessageBox("You Can't find the network server!", "Prompt");
	else	MessageBox("Login failed!", "Prompt");
}

void CMainDialog::OnBtnLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < MAX_CHANNELS; i++)
	{
		ClosePlayBack(i);
	}

	BOOL bRet = CLIENT_Logout(m_LoginID);
	//Log off and then clear log in handle
	if (bRet)
	{
		m_LoginID = 0;
		m_nChannelCount = 0;
		g_dlg = 0;
		for (int i = 0; i < MAX_CHANNELS; i++)
			m_Wnd[i] = 0;

		MessageBox("Logout success!", "Prompt");
	}
	else
	{
		MessageBox("Logout failed!", "Prompt");
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
void CMainDialog::ClosePlayBack(USHORT nChannel)
{
	//Close video directly
	if (0 != m_hPlayBack[nChannel])
	{
		CLIENT_StopPlayBack(m_hPlayBack[nChannel]);
		m_hPlayBack[nChannel] = 0;
		m_Wnd[nChannel]->Invalidate();
	}
}

void CMainDialog::OnButtonPlay(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond)
{
	// TODO: 在此添加控件通知处理程序代码
	bool bPlaySuccess = false;

	if (0 != m_LoginID)
	{
		ClosePlayBack(nChannel);

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
			MessageBox("Invalid time!", "Prompt");
			return;
		}

		for (int i = 0; i < 10; i++)
		{
			LLONG lHandle = CLIENT_PlayBackByTimeEx(m_LoginID, nChannel, &netTimeFrom, &netTimeTo, m_Wnd[nChannel]->m_hWnd, DownLoadPosCallBackFunc, (LDWORD)nChannel, 0, 0);
			/*CString strMsg;
			strMsg.Format("Login = %d, Channel = %d, HWND = %d", m_LoginID, nChannel, m_Wnd[nChannel]->m_hWnd);
			MessageBox(strMsg, "Debug");*/

			if (0 != lHandle)
			{
				m_hPlayBack[nChannel] = lHandle;
				bPlaySuccess = true;
				break;
			}
			else
				Sleep(1000);
		}

		if (!bPlaySuccess)
		{
			CString strMsg;
			strMsg.Format("Playback channel %d failed!", nChannel + 1);
			MessageBox(strMsg, "Prompt");
		}
	}
	else
		MessageBox("Please login first!", "Prompt");
}

void CMainDialog::OnButtonStop(USHORT nChannel)
{
	ClosePlayBack(nChannel);
}
