// CDivdConstDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CDivdConstDlg.h"


// CDivdConstDlg 대화 상자

IMPLEMENT_DYNAMIC(CDivdConstDlg, CDialogEx)

CDivdConstDlg::CDivdConstDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIVD_CONST, pParent)
	, m_dDivdConst(0)
{

}

CDivdConstDlg::~CDivdConstDlg()
{
}

void CDivdConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIVDCONST_EDIT, m_dDivdConst);
	DDV_MinMaxDouble(pDX, m_dDivdConst, 1.0, 32.0);
}


BEGIN_MESSAGE_MAP(CDivdConstDlg, CDialogEx)
END_MESSAGE_MAP()


// CDivdConstDlg 메시지 처리기


BOOL CDivdConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
