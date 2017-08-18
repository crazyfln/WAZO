
// PlayVideoDlg.h : 头文件
//

#pragma once

#include "dhnetsdk.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "ATLComTime.h"

// CPlayVideoDlg 对话框
class CPlayVideoDlg : public CDialogEx
{
// 构造
public:
	CPlayVideoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAYVIDEO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	COleDateTime m_dateFrom;
	COleDateTime m_timeFrom;
	COleDateTime m_dateTo;
	COleDateTime m_timeTo;

	LLONG m_hPlayBack;
	LLONG m_LoginID;
	int m_nChannelCount;
	int m_nChannelID;
	bool m_bNewStart;

private:
	void DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort);
	void InitNetSDK();
	CString GetDvrIP();
	void ShowLoginErrorReason(int nError);
	void InitComboBox(int nChannel);
	NET_TIME ConvertToDateTime(const COleDateTime &date, const COleDateTime &time);
	int Compare(const NET_TIME *pSrcTime, const NET_TIME *pDestTime);
	void ClosePlayBack();

public:
	friend void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
	friend void CALLBACK PlayCallBack(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser);
	afx_msg void OnBtnLogout();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonCapturePicture();
	afx_msg void OnButtonStop();
};
