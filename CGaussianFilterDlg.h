#pragma once
#include "afxdialogex.h"


// CGaussianFilterDlg 대화 상자

class CGaussianFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGaussianFilterDlg)

public:
	CGaussianFilterDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CGaussianFilterDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAUSSIANFILTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_nsigma;
	afx_msg void OnEnChangeEdit1();
};
