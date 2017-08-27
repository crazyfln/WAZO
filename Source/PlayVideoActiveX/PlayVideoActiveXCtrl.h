#pragma once

#include "MainDialog.h"
// PlayVideoActiveXCtrl.h : CPlayVideoActiveXCtrl ActiveX �ؼ����������


// CPlayVideoActiveXCtrl : �й�ʵ�ֵ���Ϣ������� PlayVideoActiveXCtrl.cpp��

class CPlayVideoActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CPlayVideoActiveXCtrl)

// ���캯��
public:
	CPlayVideoActiveXCtrl();
	CMainDialog m_MainDlg;

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CPlayVideoActiveXCtrl();

	DECLARE_OLECREATE_EX(CPlayVideoActiveXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CPlayVideoActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CPlayVideoActiveXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CPlayVideoActiveXCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidStop = 4L,
		dispidPlay = 3L,
		dispidLogout = 2L,
		dispidLogin = 1L,
		dispidIPAddress = 1
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	CString m_IPAddress;
	void Login(LPCTSTR strIPAddress, USHORT nPort, LPCTSTR strUsername, LPCTSTR strPassword);
	void Logout();
	void Play(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond);
	void Stop(USHORT nChannel);
};

