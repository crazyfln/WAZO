// PlayVideoActiveXPropPage.cpp : CPlayVideoActiveXPropPage 属性页类的实现。

#include "stdafx.h"
#include "PlayVideoActiveX.h"
#include "PlayVideoActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPlayVideoActiveXPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CPlayVideoActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CPlayVideoActiveXPropPage, "PLAYVIDEOACTIV.PlayVideoActivPropPage.1",
	0x7ac02bb1, 0x419, 0x40f1, 0xbf, 0x2b, 0xd4, 0xa0, 0x83, 0x63, 0xec, 0x23)

// CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPageFactory::UpdateRegistry -
// 添加或移除 CPlayVideoActiveXPropPage 的系统注册表项

BOOL CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_PLAYVIDEOACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPage - 构造函数

CPlayVideoActiveXPropPage::CPlayVideoActiveXPropPage() :
	COlePropertyPage(IDD, IDS_PLAYVIDEOACTIVEX_PPG_CAPTION)
{
}

// CPlayVideoActiveXPropPage::DoDataExchange - 在页和属性间移动数据

void CPlayVideoActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CPlayVideoActiveXPropPage 消息处理程序
