// CGeometricTranslateDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CGeometricTranslateDlg.h"


// CGeometricTranslateDlg 대화 상자

IMPLEMENT_DYNAMIC(CGeometricTranslateDlg, CDialogEx)

CGeometricTranslateDlg::CGeometricTranslateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GEOTRANS, pParent)
	, m_ninputX(0)
	, m_ninputY(0)
{

}

CGeometricTranslateDlg::~CGeometricTranslateDlg()
{
}

void CGeometricTranslateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUT_X, m_ninputX);
	DDX_Text(pDX, IDC_INPUT_Y, m_ninputY);
}


BEGIN_MESSAGE_MAP(CGeometricTranslateDlg, CDialogEx)
END_MESSAGE_MAP()


// CGeometricTranslateDlg 메시지 처리기
