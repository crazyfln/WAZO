// PlayVideoActiveXCtrl.cpp : CPlayVideoActiveXCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "PlayVideoActiveX.h"
#include "PlayVideoActiveXCtrl.h"
#include "PlayVideoActiveXPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPlayVideoActiveXCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CPlayVideoActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CPlayVideoActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Login", dispidLogin, Login, VT_EMPTY, VTS_BSTR VTS_UI2 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Logout", dispidLogout, Logout, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Play", dispidPlay, Play, VT_EMPTY, VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Stop", dispidStop, Stop, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CPlayVideoActiveXCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CPlayVideoActiveXCtrl, 1)
	PROPPAGEID(CPlayVideoActiveXPropPage::guid)
END_PROPPAGEIDS(CPlayVideoActiveXCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CPlayVideoActiveXCtrl, "PLAYVIDEOACTIVEX.PlayVideoActiveXCtrl.1",
	0x336811da, 0x2169, 0x42d4, 0x82, 0x9b, 0xa6, 0xb1, 0x87, 0x35, 0xbc, 0xa0)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CPlayVideoActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DPlayVideoActiveX = { 0x1CE85FEF, 0x73FE, 0x45F5, { 0xAC, 0xC2, 0xA, 0xF3, 0x97, 0x95, 0xD5, 0xED } };
const IID IID_DPlayVideoActiveXEvents = { 0x311BE723, 0x2B9B, 0x432D, { 0xB2, 0x49, 0xE6, 0x1D, 0x93, 0xB8, 0x4D, 0xD6 } };

// 控件类型信息

static const DWORD _dwPlayVideoActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CPlayVideoActiveXCtrl, IDS_PLAYVIDEOACTIVEX, _dwPlayVideoActiveXOleMisc)

// CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrlFactory::UpdateRegistry -
// 添加或移除 CPlayVideoActiveXCtrl 的系统注册表项

BOOL CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_PLAYVIDEOACTIVEX,
			IDB_PLAYVIDEOACTIVEX,
			afxRegApartmentThreading,
			_dwPlayVideoActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrl - 构造函数

CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrl()
{
	InitializeIIDs(&IID_DPlayVideoActiveX, &IID_DPlayVideoActiveXEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CPlayVideoActiveXCtrl::~CPlayVideoActiveXCtrl - 析构函数

CPlayVideoActiveXCtrl::~CPlayVideoActiveXCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CPlayVideoActiveXCtrl::OnDraw - 绘图函数

void CPlayVideoActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CPlayVideoActiveXCtrl::DoPropExchange - 持久性支持

void CPlayVideoActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CPlayVideoActiveXCtrl::OnResetState - 将控件重置为默认状态

void CPlayVideoActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CPlayVideoActiveXCtrl::AboutBox - 向用户显示“关于”框

void CPlayVideoActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_PLAYVIDEOACTIVEX);
	dlgAbout.DoModal();
}


// CPlayVideoActiveXCtrl 消息处理程序


int CPlayVideoActiveXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_MainDlg.Create(IDD_MAIN_DIALOG, this);
	return 0;
}


void CPlayVideoActiveXCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	RECT activeXRect;
	GetClientRect(&activeXRect);
	m_MainDlg.MoveWindow(&activeXRect);
}


void CPlayVideoActiveXCtrl::Login(LPCTSTR strIPAddress, USHORT nPort, LPCTSTR strUsername, LPCTSTR strPassword)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MainDlg.OnBtnLogin(strIPAddress, nPort, strUsername, strPassword);
}


void CPlayVideoActiveXCtrl::Logout()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MainDlg.OnBtnLogout();
}


void CPlayVideoActiveXCtrl::Play(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MainDlg.OnButtonPlay(nChannel, nStartYear, nStartMonth, nStartDay, nStartHour, nStartMinute, nStartSecond,
		nEndYear, nEndMonth, nEndDay, nEndHour, nEndMinute, nEndSecond);
}


void CPlayVideoActiveXCtrl::Stop()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_MainDlg.OnButtonStop();
}
