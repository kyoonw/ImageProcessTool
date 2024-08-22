#pragma once
#include "afxdialogex.h"


// CResizeImgDlg 대화 상자

class CResizeImgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResizeImgDlg)

public:
	CResizeImgDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CResizeImgDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESIZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nsize;
	afx_msg void OnBnClickedNearist();
	afx_msg void OnBnClickedBinnaryline();
	int m_nfunction;
};
