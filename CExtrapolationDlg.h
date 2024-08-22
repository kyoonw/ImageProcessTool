#pragma once
#include "afxdialogex.h"


// CExtrapolationDlg 대화 상자

class CExtrapolationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExtrapolationDlg)

public:
	CExtrapolationDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CExtrapolationDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXTRAPOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedZeropadding();
	int m_nextrafunction;
	int m_nsize;
	afx_msg void OnBnClickedPeriodicpadding();
	afx_msg void OnBnClickedSymmetric();
	afx_msg void OnBnClickedOk();
};
