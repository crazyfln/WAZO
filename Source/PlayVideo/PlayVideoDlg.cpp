
// PlayVideoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PlayVideo.h"
#include "PlayVideoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlayVideoDlg �Ի���



CPlayVideoDlg::CPlayVideoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PLAYVIDEO_DIALOG, pParent)
	, m_nPort(37777)
	, m_strUserName(_T("admin"))
	, m_strPwd(_T("admin"))
	, m_dateFrom(COleDateTime::GetCurrentTime())
	, m_timeFrom(COleDateTime::GetCurrentTime())
	, m_dateTo(COleDateTime::GetCurrentTime())
	, m_timeTo(COleDateTime::GetCurrentTime())
	, m_bSaveVideo(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlayVideoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_DVRIP, m_ctlDvrIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_DVRPWD, m_strPwd);
	DDX_Control(pDX, IDC_COMBO_CHANNEL, m_ctlChannel);
	DDX_DateTimeCtrl(pDX, IDC_DATE_FROM, m_dateFrom);
	DDX_DateTimeCtrl(pDX, IDC_TIME_FROM, m_timeFrom);
	DDX_DateTimeCtrl(pDX, IDC_DATE_TO, m_dateTo);
	DDX_DateTimeCtrl(pDX, IDC_TIME_TO, m_timeTo);
	DDX_Check(pDX, IDC_CHECK_SAVEVIDEO, m_bSaveVideo);
}

BEGIN_MESSAGE_MAP(CPlayVideoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CPlayVideoDlg::OnBtnLogin)
	ON_BN_CLICKED(IDC_BTN_LOGOUT, &CPlayVideoDlg::OnBtnLogout)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, &CPlayVideoDlg::OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE_PICTURE, &CPlayVideoDlg::OnButtonCapturePicture)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CPlayVideoDlg::OnButtonStop)
END_MESSAGE_MAP()


// CPlayVideoDlg ��Ϣ�������

BOOL CPlayVideoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//Device default IP
	m_ctlDvrIP.SetAddress(127, 0, 0, 1);
	InitNetSDK();

	for (int i = 0; i < MAX_CHANNELS; i++)
	{
		m_hPlayBack[i] = 0;
	}
	m_Wnd[0] = GetDlgItem(IDC_SCREEN_PLAYBACK1);
	m_Wnd[1] = GetDlgItem(IDC_SCREEN_PLAYBACK2);
	m_Wnd[2] = GetDlgItem(IDC_SCREEN_PLAYBACK3);
	m_Wnd[3] = GetDlgItem(IDC_SCREEN_PLAYBACK4);
	m_Wnd[4] = GetDlgItem(IDC_SCREEN_PLAYBACK5);
	m_Wnd[5] = GetDlgItem(IDC_SCREEN_PLAYBACK6);
	m_Wnd[6] = GetDlgItem(IDC_SCREEN_PLAYBACK7);
	m_Wnd[7] = GetDlgItem(IDC_SCREEN_PLAYBACK8);
	m_Wnd[8] = GetDlgItem(IDC_SCREEN_PLAYBACK9);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPlayVideoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPlayVideoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPlayVideoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPlayVideoDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	for (int i = 0; i < MAX_CHANNELS; i++)
	{
		ClosePlayBack(i);
		m_Wnd[i] = 0;
	}

	//Log off
	if (0 != m_LoginID)
	{
		BOOL bLogout = CLIENT_Logout(m_LoginID);
		m_LoginID = 0;
	}

	//Clear SDK and then release occupied resources.
	CLIENT_Cleanup();
}

//Initialize net SDK
void CPlayVideoDlg::InitNetSDK()
{
	BOOL ret = CLIENT_Init(DisConnectFunc, (LDWORD)this);
	if (!ret)
	{
		MessageBox("��ʼ��SDKʧ��!", "��ʾ");
	}
}

//Callback function when device disconnected
void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
	if (dwUser == 0)
		return;
	
	CPlayVideoDlg *dlg = (CPlayVideoDlg *)dwUser;
	dlg->DeviceDisConnect(lLoginID, pchDVRIP, nDVRPort);
}

//Process status callback
void CALLBACK DownLoadPosCallBackFunc(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser)
{
	if (dwUser == 0)
		return;

	CPlayVideoDlg *dlg = (CPlayVideoDlg *)dwUser;
	if (dwDownLoadSize == -1)
		dlg->OnButtonStop();
}

int CALLBACK DataCallBackFunc(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser)
{
	static int nVideoCount = 0;
	char szFileName[64] = { 0 };

	CPlayVideoDlg *dlg = (CPlayVideoDlg *)dwUser;
	if (dlg->m_bSaveVideo)
	{
		sprintf_s(szFileName, 63, "Video_%02d_%04d%02d%02d_%02d%02d%02d_%04d%02d%02d_%02d%02d%02d.mp4", dlg->m_nChannelID + 1,
			dlg->m_dateFrom.GetYear(), dlg->m_dateFrom.GetMonth(), dlg->m_dateFrom.GetDay(), dlg->m_timeFrom.GetHour(), dlg->m_timeFrom.GetMinute(), dlg->m_timeFrom.GetSecond(),
			dlg->m_dateTo.GetYear(), dlg->m_dateTo.GetMonth(), dlg->m_dateTo.GetDay(), dlg->m_timeTo.GetHour(), dlg->m_timeTo.GetMinute(), dlg->m_timeTo.GetSecond());

		FILE *file = NULL;
		fopen_s(&file, szFileName, "a+b");
		if (file)
		{
			fwrite(pBuffer, 1, dwBufSize, file);
			fclose(file);
		}
	}

	return 1;
}

//Process when device disconnected.
void CPlayVideoDlg::DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort)
{
	//Add device disconnection process code
	MessageBox("����Ͽ�!", "��ʾ");
}

//Get DVR IP address
CString CPlayVideoDlg::GetDvrIP()
{
	CString strRet = "";
	BYTE nField0, nField1, nField2, nField3;
	m_ctlDvrIP.GetAddress(nField0, nField1, nField2, nField3);
	strRet.Format("%d.%d.%d.%d", nField0, nField1, nField2, nField3);
	return strRet;
}

//Display log in failure reason
void CPlayVideoDlg::ShowLoginErrorReason(int nError)
{
	if (1 == nError)		MessageBox("�������!", "��ʾ");
	else if (2 == nError)	MessageBox("��Ч�û���!", "��ʾ");
	else if (3 == nError)	MessageBox("���ӳ�ʱ!", "��ʾ");
	else if (4 == nError)	MessageBox("�û��ѵ�¼!", "��ʾ");
	else if (5 == nError)	MessageBox("�û�������!", "��ʾ");
	else if (6 == nError)	MessageBox("�û��ں�������!", "��ʾ");
	else if (7 == nError)	MessageBox("ϵͳæ!", "��ʾ");
	else if (9 == nError)	MessageBox("�Ҳ���������!", "��ʾ");
	else	MessageBox("��¼ʧ��!", "��ʾ");
}

void CPlayVideoDlg::OnBtnLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL bValid = UpdateData(TRUE);
	if (bValid)
	{
		int err = 0;	//Storage the possible returned errror value
		char *pchDVRIP;
		CString strDvrIP = GetDvrIP();
		pchDVRIP = (LPSTR)(LPCSTR)strDvrIP;
		WORD wDVRPort = (WORD)m_nPort;
		char *pchUserName = (LPSTR)(LPCSTR)m_strUserName;
		char *pchPassword = (LPSTR)(LPCSTR)m_strPwd;
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
			InitComboBox(m_nChannelCount);

			GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(TRUE);
			GetDlgItem(IDC_COMBO_CHANNEL)->EnableWindow(TRUE);
			GetDlgItem(IDC_DATE_FROM)->EnableWindow(TRUE);
			GetDlgItem(IDC_TIME_FROM)->EnableWindow(TRUE);
			GetDlgItem(IDC_DATE_TO)->EnableWindow(TRUE);
			GetDlgItem(IDC_TIME_TO)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CAPTURE_PICTURE)->EnableWindow(TRUE);
		}
	}
}

void CPlayVideoDlg::InitComboBox(int nChannel)
{
	int nIndex = 0;
	int i = 0;
	CString str;
	m_ctlChannel.ResetContent();
	for (i = 0; i < nChannel; i++)
	{
		str.Format("%d", i + 1);
		nIndex = m_ctlChannel.AddString(str);
		m_ctlChannel.SetItemData(nIndex, i);
	}
	m_ctlChannel.SetCurSel(0);
}

void CPlayVideoDlg::OnBtnLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		InitComboBox(m_nChannelCount);

		GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_PLAY)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CAPTURE_PICTURE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_CHANNEL)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATE_FROM)->EnableWindow(FALSE);
		GetDlgItem(IDC_TIME_FROM)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATE_TO)->EnableWindow(FALSE);
		GetDlgItem(IDC_TIME_TO)->EnableWindow(FALSE);
	}
	else
	{
		MessageBox("ע��ʧ��!", "��ʾ");
	}
}

void CPlayVideoDlg::OnButtonPlay()
{
	bool bPlaySuccess = false;

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (0 != m_LoginID)
	{
		UpdateData(TRUE);
		
		//Channel
		int nChannelId = 0;
		int nIndex = m_ctlChannel.GetCurSel();
		int nChannelID = (int)m_ctlChannel.GetItemData(nIndex);

		//Time
		NET_TIME netTimeFrom = ConvertToDateTime(m_dateFrom, m_timeFrom);
		NET_TIME netTimeTo = ConvertToDateTime(m_dateTo, m_timeTo);
		if (Compare(&netTimeFrom, &netTimeTo) >= 0)
		{
			MessageBox("��Чʱ��!", "��ʾ");
			return;
		}

		ClosePlayBack(nChannelID);
		
		for (int i = 0; i < 10; i++)
		{
			LLONG lHandle = CLIENT_PlayBackByTimeEx(m_LoginID, nChannelID, &netTimeFrom, &netTimeTo, m_Wnd[nChannelID]->m_hWnd, DownLoadPosCallBackFunc, (LDWORD)this, DataCallBackFunc, (LDWORD)this);
			if (0 != lHandle)
			{
				m_nChannelID = nChannelID;
				m_hPlayBack[nChannelID] = lHandle;
				m_bNewStart = true;
				bPlaySuccess = true;
							
				break;
			}
			else
				Sleep(1000);
		}

		if (!bPlaySuccess)
		{
			MessageBox("����ʧ��!", "��ʾ");
		}
	}
}

NET_TIME CPlayVideoDlg::ConvertToDateTime(const COleDateTime &date, const COleDateTime &time)
{
	NET_TIME netTime = { 0 };
	int year = date.GetYear();
	if (year < 2000)
	{
		netTime.dwYear = 2000;
		netTime.dwMonth = 1;
		netTime.dwDay = 1;
		netTime.dwHour = 0;
		netTime.dwMinute = 0;
		netTime.dwSecond = 0;
	}
	else
	{
		netTime.dwYear = date.GetYear();
		netTime.dwMonth = date.GetMonth();
		netTime.dwDay = date.GetDay();
		netTime.dwHour = time.GetHour();
		netTime.dwMinute = time.GetMinute();
		netTime.dwSecond = time.GetSecond();
	}

	return netTime;
}

int CPlayVideoDlg::Compare(const NET_TIME *pSrcTime, const NET_TIME *pDestTime)
{
	SYSTEMTIME srcTime = { 0 }, destTime = { 0 };
	srcTime.wYear = (WORD)pSrcTime->dwYear;
	srcTime.wMonth = (WORD)pSrcTime->dwMonth;
	srcTime.wDay = (WORD)pSrcTime->dwDay;
	srcTime.wHour = (WORD)pSrcTime->dwHour;
	srcTime.wMinute = (WORD)pSrcTime->dwMinute;
	srcTime.wSecond = (WORD)pSrcTime->dwSecond;
	/// dest
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
void CPlayVideoDlg::ClosePlayBack(int nChannel)
{
	//Close video directly
	if (0 != m_hPlayBack[nChannel])
	{
		CLIENT_StopPlayBack(m_hPlayBack[nChannel]);
		m_hPlayBack[nChannel] = 0;
		m_Wnd[nChannel]->Invalidate();
	}
}

void CPlayVideoDlg::OnButtonCapturePicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	static int nPictureCount = 0;

	if ((0 != m_hPlayBack[m_nChannelID]) && (0 != m_LoginID))
	{
		BOOL bSuccess = TRUE;
		int nError = 0;
		int nDirectoryLength = 64;
		char* pDirectory = NULL;
		while (1)
		{
			if (NULL == pDirectory)
			{
				pDirectory = new char[nDirectoryLength];
			}

			if (NULL == pDirectory)
			{
				MessageBox("ϵͳ����!", "��ʾ");
				return;
			}
			memset(pDirectory, 0, nDirectoryLength);

			int Ret = GetModuleFileName(NULL, pDirectory, nDirectoryLength);
			char* pLastPos = NULL;
			for (int i = 0; pDirectory[i]; ++i)
			{
				if ('\\' == pDirectory[i])
				{
					pLastPos = pDirectory + i;
				}
			}

			if (NULL == pLastPos)
			{
				MessageBox("ϵͳ����!", "��ʾ");
				return;
			}
			else
			{
				*(pLastPos + 1) = 0;
			}

			if (Ret >= nDirectoryLength)   // ����������
			{
				delete[] pDirectory;
				pDirectory = NULL;
				nDirectoryLength = nDirectoryLength * 2;
			}
			else
			{
				break;
			}
		}

		int nPictureNameLength = nDirectoryLength + 50;
		char* pPictureName = new char[nPictureNameLength];
		if (NULL == pPictureName)
		{
			MessageBox("ϵͳ����!", "��ʾ");
			return;
		}

		memset(pPictureName, 0, nPictureNameLength);

		if (m_bNewStart)
		{
			nPictureCount = 0;
			m_bNewStart = false;
		}

		sprintf_s(pPictureName, nPictureNameLength - 1, "%sPicture_%02d_%4d%02d%02d_%02d%02d%02d_%03d.jpg",
			pDirectory, m_nChannelID + 1, m_dateFrom.GetYear(), m_dateFrom.GetMonth(), m_dateFrom.GetDay(), 
			m_timeFrom.GetHour(), m_timeFrom.GetMinute(), m_timeFrom.GetSecond(), nPictureCount++);
		
		if (NULL != pDirectory)
		{
			delete[] pDirectory;
			pDirectory = NULL;
		}

		bSuccess = CLIENT_CapturePictureEx(m_hPlayBack[m_nChannelID], pPictureName, NET_CAPTURE_JPEG);

		if (NULL != pPictureName)
		{
			delete[] pPictureName;
			pPictureName = NULL;
		}

		if (!bSuccess)
		{
			nError = CLIENT_GetLastError();
			MessageBox("ץȡͼ��ʧ��!", "��ʾ");
		}
	}
	else
	{
		MessageBox("���ȿ�ʼ����!", "��ʾ");
	}
}


void CPlayVideoDlg::OnButtonStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ClosePlayBack(m_nChannelID);
}
