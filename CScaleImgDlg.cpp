// CScaleImgDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CScaleImgDlg.h"


// CScaleImgDlg 대화 상자

IMPLEMENT_DYNAMIC(CScaleImgDlg, CDialogEx)

CScaleImgDlg::CScaleImgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCALING, pParent)
	, m_nratio(0)
	, m_nfunction(0)
{

}

CScaleImgDlg::~CScaleImgDlg()
{
}

void CScaleImgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nratio);
	DDX_Radio(pDX, IDC_RADIO1, m_nfunction);
}


BEGIN_MESSAGE_MAP(CScaleImgDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CScaleImgDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CScaleImgDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CScaleImgDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CScaleImgDlg 메시지 처리기


void CScaleImgDlg::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CScaleImgDlg::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CScaleImgDlg::OnBnClickedRadio3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
