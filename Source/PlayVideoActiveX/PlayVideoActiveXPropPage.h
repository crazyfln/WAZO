#pragma once

// PlayVideoActiveXPropPage.h : CPlayVideoActiveXPropPage 属性页类的声明。


// CPlayVideoActiveXPropPage : 有关实现的信息，请参阅 PlayVideoActiveXPropPage.cpp。

class CPlayVideoActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPlayVideoActiveXPropPage)
	DECLARE_OLECREATE_EX(CPlayVideoActiveXPropPage)

// 构造函数
public:
	CPlayVideoActiveXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_PLAYVIDEOACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

