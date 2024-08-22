#pragma once
#include "afxdialogex.h"


// CScaleImgDlg 대화 상자

class CScaleImgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScaleImgDlg)

public:
	CScaleImgDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CScaleImgDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCALING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nratio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	int m_nfunction;
};
