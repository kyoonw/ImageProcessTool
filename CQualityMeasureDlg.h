#pragma once
#include "afxdialogex.h"


// CQualityMeasureDlg 대화 상자

class CQualityMeasureDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQualityMeasureDlg)

public:
	CQualityMeasureDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CQualityMeasureDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUALITYMESURE };
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
	void* m_pDoc1;
	void* m_pDoc2;
};
