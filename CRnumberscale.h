#pragma once
#include "afxdialogex.h"


// CRnumberscale 대화 상자

class CRnumberscale : public CDialogEx
{
	DECLARE_DYNAMIC(CRnumberscale)

public:
	CRnumberscale(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CRnumberscale();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RNUMRESIZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_nscale;
};
