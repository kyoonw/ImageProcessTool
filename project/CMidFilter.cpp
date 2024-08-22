// CMidFilter.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CMidFilter.h"


// CMidFilter 대화 상자

IMPLEMENT_DYNAMIC(CMidFilter, CDialogEx)

CMidFilter::CMidFilter(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MIDFILTER, pParent)
	, m_nsize(0)
{

}

CMidFilter::~CMidFilter()
{
}

void CMidFilter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nsize);
}


BEGIN_MESSAGE_MAP(CMidFilter, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CMidFilter::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CMidFilter 메시지 처리기


void CMidFilter::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
