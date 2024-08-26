#pragma once
#include "afxdialogex.h"


// CLogicImage 대화 상자

class CLogicImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogicImageDlg)

public:
	CLogicImageDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLogicImageDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGICIMG };
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
	int m_nFunction;
	void* m_pDoc1;
	void* m_pDoc2;
};
