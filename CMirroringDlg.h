#pragma once
#include "afxdialogex.h"


// CMirroringDlg 대화 상자

class CMirroringDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMirroringDlg)

public:
	CMirroringDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMirroringDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MIRRORING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedVermirror();
	int m_nmirrorfunction;
	int m_nsize;
	afx_msg void OnBnClickedOk();
};
