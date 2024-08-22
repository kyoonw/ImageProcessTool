#pragma once
#include "afxdialogex.h"


// CEndInSearch 대화 상자

class CEndInSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CEndInSearch)

public:
	CEndInSearch(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEndInSearch();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENDINSEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nmax;
	int m_nlow;
};
