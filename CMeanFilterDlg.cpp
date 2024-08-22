// CMeanFilterDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CMeanFilterDlg.h"


// CMeanFilterDlg 대화 상자

IMPLEMENT_DYNAMIC(CMeanFilterDlg, CDialogEx)

CMeanFilterDlg::CMeanFilterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FILTER, pParent)
	, m_nsize(0)
{

}

CMeanFilterDlg::~CMeanFilterDlg()
{
}

void CMeanFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nsize);
}


BEGIN_MESSAGE_MAP(CMeanFilterDlg, CDialogEx)
END_MESSAGE_MAP()


// CMeanFilterDlg 메시지 처리기
