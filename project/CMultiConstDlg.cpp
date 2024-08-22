// CMultiConstDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CMultiConstDlg.h"


// CMultiConstDlg 대화 상자

IMPLEMENT_DYNAMIC(CMultiConstDlg, CDialogEx)

CMultiConstDlg::CMultiConstDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MULTI_CONST, pParent)
	, m_dMultiConst(0)
{

}

CMultiConstDlg::~CMultiConstDlg()
{
}

void CMultiConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MULTICONST_EDIT, m_dMultiConst);
	DDV_MinMaxDouble(pDX, m_dMultiConst, 1.0, 32.0);
}


BEGIN_MESSAGE_MAP(CMultiConstDlg, CDialogEx)
END_MESSAGE_MAP()


// CMultiConstDlg 메시지 처리기


BOOL CMultiConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
