#pragma once

// PlayVideoActiveXPropPage.h : CPlayVideoActiveXPropPage ����ҳ���������


// CPlayVideoActiveXPropPage : �й�ʵ�ֵ���Ϣ������� PlayVideoActiveXPropPage.cpp��

class CPlayVideoActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPlayVideoActiveXPropPage)
	DECLARE_OLECREATE_EX(CPlayVideoActiveXPropPage)

// ���캯��
public:
	CPlayVideoActiveXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_PLAYVIDEOACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

