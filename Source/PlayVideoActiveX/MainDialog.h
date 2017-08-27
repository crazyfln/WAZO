#pragma once
#include "afxcmn.h"
#include "dhnetsdk.h"
#include "afxwin.h"
#include "ATLComTime.h"

#define MAX_CHANNELS 9

// CMainDialog 对话框
typedef struct  
{
	LDWORD dwUser;
	USHORT nChannel;
}MyDlg;

class CMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	LLONG m_hPlayBack[MAX_CHANNELS];
	LLONG m_LoginID;
	int m_nChannelCount;
	CWnd *m_Wnd[MAX_CHANNELS];

private:
	void DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort);
	void InitNetSDK();
	void ShowLoginErrorReason(int nError);
	int Compare(const NET_TIME *pSrcTime, const NET_TIME *pDestTime);
	void ClosePlayBack(USHORT nChannel);
	virtual BOOL OnInitDialog();

public:
	friend void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
	friend void CALLBACK DownLoadPosCallBackFunc(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser);
	void OnBtnLogin(LPCTSTR strIPAddress, USHORT nPort, LPCTSTR strUsername, LPCTSTR strPassword);
	void OnBtnLogout();
	void OnButtonPlay(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond);
	void OnButtonStop(USHORT nChannel);
};
