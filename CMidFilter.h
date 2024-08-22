#pragma once
#include "afxdialogex.h"


// CMidFilter 대화 상자

class CMidFilter : public CDialogEx
{
	DECLARE_DYNAMIC(CMidFilter)

public:
	CMidFilter(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMidFilter();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MIDFILTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nsize;
	afx_msg void OnEnChangeEdit1();
};
