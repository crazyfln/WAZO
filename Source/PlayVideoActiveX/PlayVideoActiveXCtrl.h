#pragma once

#include "MainDialog.h"
// PlayVideoActiveXCtrl.h : CPlayVideoActiveXCtrl ActiveX 控件类的声明。


// CPlayVideoActiveXCtrl : 有关实现的信息，请参阅 PlayVideoActiveXCtrl.cpp。

class CPlayVideoActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CPlayVideoActiveXCtrl)

// 构造函数
public:
	CPlayVideoActiveXCtrl();
	CMainDialog m_MainDlg;

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CPlayVideoActiveXCtrl();

	DECLARE_OLECREATE_EX(CPlayVideoActiveXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CPlayVideoActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CPlayVideoActiveXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CPlayVideoActiveXCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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
	void Login(LPCTSTR strIPAddress, USHORT nPort, LPCTSTR strUsername, LPCTSTR strPassword);
	void Logout();
	void Play(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond);
	void Stop(USHORT nChannel);
};

