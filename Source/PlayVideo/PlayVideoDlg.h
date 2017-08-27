
// PlayVideoDlg.h : ͷ�ļ�
//

#pragma once

#include "dhnetsdk.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "ATLComTime.h"

#define MAX_CHANNELS 9

// CPlayVideoDlg �Ի���
class CPlayVideoDlg : public CDialogEx
{
// ����
public:
	CPlayVideoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAYVIDEO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnBtnLogin();
	DECLARE_MESSAGE_MAP()

private:
	CIPAddressCtrl m_ctlDvrIP;
	UINT m_nPort;
	CString m_strUserName;
	CString m_strPwd;
	CComboBox m_ctlChannel;
	LLONG m_hPlayBack[MAX_CHANNELS];
	LLONG m_LoginID;
	int m_nChannelCount;
	bool m_bNewStart;
	CWnd *m_Wnd[MAX_CHANNELS];

public:
	int m_nChannelID;
	COleDateTime m_dateFrom;
	COleDateTime m_timeFrom;
	COleDateTime m_dateTo;
	COleDateTime m_timeTo;
	BOOL m_bSaveVideo;

private:
	void DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort);
	void InitNetSDK();
	CString GetDvrIP();
	void ShowLoginErrorReason(int nError);
	void InitComboBox(int nChannel);
	NET_TIME ConvertToDateTime(const COleDateTime &date, const COleDateTime &time);
	int Compare(const NET_TIME *pSrcTime, const NET_TIME *pDestTime);
	void ClosePlayBack(int nChannel);

public:
	friend void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
	friend void CALLBACK DownLoadPosCallBackFunc(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser);
	friend int CALLBACK DataCallBackFunc(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);
	afx_msg void OnBtnLogout();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonCapturePicture();
	afx_msg void OnButtonStop();
};
