#pragma once
#include "afxdialogex.h"


// CWeightFilter 대화 상자

class CWeightFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWeightFilterDlg)

public:
	CWeightFilterDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CWeightFilterDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WEIGHTFILTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nfunction;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
