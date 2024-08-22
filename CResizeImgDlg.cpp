// CResizeImgDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CResizeImgDlg.h"


// CResizeImgDlg 대화 상자

IMPLEMENT_DYNAMIC(CResizeImgDlg, CDialogEx)

CResizeImgDlg::CResizeImgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RESIZE, pParent)
	, m_nsize(0)
	, m_nfunction(0)
{

}

CResizeImgDlg::~CResizeImgDlg()
{
}

void CResizeImgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nsize);
	DDX_Radio(pDX, IDC_Nearist, m_nfunction);
}


BEGIN_MESSAGE_MAP(CResizeImgDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Nearist, &CResizeImgDlg::OnBnClickedNearist)
	ON_BN_CLICKED(IDC_Binnaryline, &CResizeImgDlg::OnBnClickedBinnaryline)
END_MESSAGE_MAP()


// CResizeImgDlg 메시지 처리기


void CResizeImgDlg::OnBnClickedNearist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CResizeImgDlg::OnBnClickedBinnaryline()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
