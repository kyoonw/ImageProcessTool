#pragma once
#include "afxdialogex.h"


// CGeometricTranslateDlg 대화 상자

class CGeometricTranslateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGeometricTranslateDlg)

public:
	CGeometricTranslateDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CGeometricTranslateDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GEOTRANS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_ninputX;
	int m_ninputY;
};
