#pragma once
#include "afxdialogex.h"


// CGreyTransformDlg 대화 상자

class CGreyTransformDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGreyTransformDlg)

public:
	CGreyTransformDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CGreyTransformDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GREY_TRANSFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_dCoefA;
	double m_dCoefB;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeCoefaEdit();
	afx_msg void OnEnChangeCoefbEdit();
};
