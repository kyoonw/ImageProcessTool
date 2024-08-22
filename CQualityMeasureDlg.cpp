﻿// CQualityMeasureDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "ImageToolDoc.h"
#include "CQualityMeasureDlg.h"


// CQualityMeasureDlg 대화 상자

IMPLEMENT_DYNAMIC(CQualityMeasureDlg, CDialogEx)

CQualityMeasureDlg::CQualityMeasureDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUALITYMESURE, pParent)
	, m_pDoc1(NULL), m_pDoc2(NULL)
{

}

CQualityMeasureDlg::~CQualityMeasureDlg()
{
}

void CQualityMeasureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
}


BEGIN_MESSAGE_MAP(CQualityMeasureDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_IMAGE2, &CQualityMeasureDlg::OnCbnSelchangeComboImage2)
	ON_BN_CLICKED(IDOK, &CQualityMeasureDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CQualityMeasureDlg 메시지 처리기


void CQualityMeasureDlg::OnCbnSelchangeComboImage2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CQualityMeasureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int nIndex = 0;
	CString strTitle;

	CImageToolApp* pApp = (CImageToolApp*)AfxGetApp();
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while (pos != NULL)
	{
		CImageToolDoc* pDoc = (CImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);

		if (pDoc->m_Dib.GetBitCount() != 8)
			continue;

		strTitle = pDoc->GetTitle();
		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	if (nIndex > 1)
		m_comboImage2.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CQualityMeasureDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pDoc1 = (CImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage2.GetCurSel());
	CDialogEx::OnOK();
}

