// CMirroringDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CMirroringDlg.h"


// CMirroringDlg 대화 상자

IMPLEMENT_DYNAMIC(CMirroringDlg, CDialogEx)

CMirroringDlg::CMirroringDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MIRRORING, pParent)
	, m_nmirrorfunction(0)
	, m_nsize(0)
{

}

CMirroringDlg::~CMirroringDlg()
{
}

void CMirroringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_VERMIRROR, m_nmirrorfunction);
	DDX_Text(pDX, IDC_EDIT1, m_nsize);
}


BEGIN_MESSAGE_MAP(CMirroringDlg, CDialogEx)
	ON_BN_CLICKED(IDC_HORMIRROR, &CMirroringDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_FULLMIRROR, &CMirroringDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_VERMIRROR, &CMirroringDlg::OnBnClickedVermirror)
	ON_BN_CLICKED(IDOK, &CMirroringDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMirroringDlg 메시지 처리기


void CMirroringDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMirroringDlg::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMirroringDlg::OnBnClickedVermirror()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMirroringDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
