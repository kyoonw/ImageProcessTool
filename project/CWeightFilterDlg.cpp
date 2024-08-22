// CWeightFilter.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CWeightFilterDlg.h"


// CWeightFilter 대화 상자

IMPLEMENT_DYNAMIC(CWeightFilterDlg, CDialogEx)

CWeightFilterDlg::CWeightFilterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WEIGHTFILTER, pParent)
	, m_nfunction(0)
{

}

CWeightFilterDlg::~CWeightFilterDlg()
{
}

void CWeightFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nfunction);
}


BEGIN_MESSAGE_MAP(CWeightFilterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CWeightFilterDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CWeightFilterDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CWeightFilter 메시지 처리기


void CWeightFilterDlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CWeightFilterDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
