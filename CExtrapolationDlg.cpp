// CExtrapolationDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CExtrapolationDlg.h"


// CExtrapolationDlg 대화 상자

IMPLEMENT_DYNAMIC(CExtrapolationDlg, CDialogEx)

CExtrapolationDlg::CExtrapolationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXTRAPOL, pParent)
	, m_nextrafunction(0)
	, m_nsize(0)
{

}

CExtrapolationDlg::~CExtrapolationDlg()
{
}

void CExtrapolationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Zeropadding, m_nextrafunction);
	DDX_Text(pDX, IDC_EDIT1, m_nsize);
}


BEGIN_MESSAGE_MAP(CExtrapolationDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Zeropadding, &CExtrapolationDlg::OnBnClickedZeropadding)
	ON_BN_CLICKED(IDC_PeriodicPadding, &CExtrapolationDlg::OnBnClickedPeriodicpadding)
	ON_BN_CLICKED(IDC_Symmetric, &CExtrapolationDlg::OnBnClickedSymmetric)
	ON_BN_CLICKED(IDOK, &CExtrapolationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CExtrapolationDlg 메시지 처리기


void CExtrapolationDlg::OnBnClickedZeropadding()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExtrapolationDlg::OnBnClickedPeriodicpadding()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExtrapolationDlg::OnBnClickedSymmetric()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExtrapolationDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
