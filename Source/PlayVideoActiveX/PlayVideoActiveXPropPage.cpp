// PlayVideoActiveXPropPage.cpp : CPlayVideoActiveXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "PlayVideoActiveX.h"
#include "PlayVideoActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPlayVideoActiveXPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CPlayVideoActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CPlayVideoActiveXPropPage, "PLAYVIDEOACTIV.PlayVideoActivPropPage.1",
	0x7ac02bb1, 0x419, 0x40f1, 0xbf, 0x2b, 0xd4, 0xa0, 0x83, 0x63, 0xec, 0x23)

// CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CPlayVideoActiveXPropPage ��ϵͳע�����

BOOL CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_PLAYVIDEOACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPage - ���캯��

CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPage() :
	COlePropertyPage(IDD, IDS_PLAYVIDEOACTIVEX_PPG_CAPTION)
{
}

// CPlayVideoActiveXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CPlayVideoActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CPlayVideoActiveXPropPage ��Ϣ�������
