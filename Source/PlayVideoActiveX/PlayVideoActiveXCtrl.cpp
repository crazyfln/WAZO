// PlayVideoActiveXCtrl.cpp : CPlayVideoActiveXCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "PlayVideoActiveX.h"
#include "PlayVideoActiveXCtrl.h"
#include "PlayVideoActiveXPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPlayVideoActiveXCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CPlayVideoActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CPlayVideoActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Login", dispidLogin, Login, VT_EMPTY, VTS_BSTR VTS_UI2 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Logout", dispidLogout, Logout, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Play", dispidPlay, Play, VT_EMPTY, VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2)
	DISP_FUNCTION_ID(CPlayVideoActiveXCtrl, "Stop", dispidStop, Stop, VT_EMPTY, VTS_UI2)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CPlayVideoActiveXCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CPlayVideoActiveXCtrl, 1)
	PROPPAGEID(CPlayVideoActiveXPropPage::guid)
END_PROPPAGEIDS(CPlayVideoActiveXCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CPlayVideoActiveXCtrl, "PLAYVIDEOACTIVEX.PlayVideoActiveXCtrl.1",
	0x336811da, 0x2169, 0x42d4, 0x82, 0x9b, 0xa6, 0xb1, 0x87, 0x35, 0xbc, 0xa0)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CPlayVideoActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DPlayVideoActiveX = { 0x1CE85FEF, 0x73FE, 0x45F5, { 0xAC, 0xC2, 0xA, 0xF3, 0x97, 0x95, 0xD5, 0xED } };
const IID IID_DPlayVideoActiveXEvents = { 0x311BE723, 0x2B9B, 0x432D, { 0xB2, 0x49, 0xE6, 0x1D, 0x93, 0xB8, 0x4D, 0xD6 } };

// �ؼ�������Ϣ

static const DWORD _dwPlayVideoActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CPlayVideoActiveXCtrl, IDS_PLAYVIDEOACTIVEX, _dwPlayVideoActiveXOleMisc)

// CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CPlayVideoActiveXCtrl ��ϵͳע�����

BOOL CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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


// CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrl - ���캯��

CPlayVideoActiveXCtrl::CPlayVideoActiveXCtrl()
{
	InitializeIIDs(&IID_DPlayVideoActiveX, &IID_DPlayVideoActiveXEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CPlayVideoActiveXCtrl::~CPlayVideoActiveXCtrl - ��������

CPlayVideoActiveXCtrl::~CPlayVideoActiveXCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CPlayVideoActiveXCtrl::OnDraw - ��ͼ����

void CPlayVideoActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CPlayVideoActiveXCtrl::DoPropExchange - �־���֧��

void CPlayVideoActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CPlayVideoActiveXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CPlayVideoActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CPlayVideoActiveXCtrl::AboutBox - ���û���ʾ�����ڡ���

void CPlayVideoActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_PLAYVIDEOACTIVEX);
	dlgAbout.DoModal();
}


// CPlayVideoActiveXCtrl ��Ϣ�������


int CPlayVideoActiveXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_MainDlg.Create(IDD_MAIN_DIALOG, this);
	return 0;
}


void CPlayVideoActiveXCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	RECT activeXRect;
	GetClientRect(&activeXRect);
	m_MainDlg.MoveWindow(&activeXRect);
}


void CPlayVideoActiveXCtrl::Login(LPCTSTR strIPAddress, USHORT nPort, LPCTSTR strUsername, LPCTSTR strPassword)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MainDlg.OnBtnLogin(strIPAddress, nPort, strUsername, strPassword);
}


void CPlayVideoActiveXCtrl::Logout()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MainDlg.OnBtnLogout();
}


void CPlayVideoActiveXCtrl::Play(USHORT nChannel, USHORT nStartYear, USHORT nStartMonth, USHORT nStartDay, USHORT nStartHour, USHORT nStartMinute, USHORT nStartSecond, USHORT nEndYear, USHORT nEndMonth, USHORT nEndDay, USHORT nEndHour, USHORT nEndMinute, USHORT nEndSecond)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MainDlg.OnButtonPlay(nChannel, nStartYear, nStartMonth, nStartDay, nStartHour, nStartMinute, nStartSecond,
		nEndYear, nEndMonth, nEndDay, nEndHour, nEndMinute, nEndSecond);
}


void CPlayVideoActiveXCtrl::Stop(USHORT nChannel)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_MainDlg.OnButtonStop(nChannel);
}
