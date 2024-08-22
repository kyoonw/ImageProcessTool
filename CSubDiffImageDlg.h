#pragma once
#include "afxdialogex.h"


// CSubDiffImage 대화 상자

class CSubDiffImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDiffImageDlg)

public:
	CSubDiffImageDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSubDiffImageDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUBDIF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboImage2();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CComboBox m_comboImage1;
	CComboBox m_comboImage2;
	int m_nfunction;
	void* m_pDoc1;
	void* m_pDoc2;
};
