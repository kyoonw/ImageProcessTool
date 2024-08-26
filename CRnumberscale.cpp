// CRnumberscale.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CRnumberscale.h"


// CRnumberscale 대화 상자

IMPLEMENT_DYNAMIC(CRnumberscale, CDialogEx)

CRnumberscale::CRnumberscale(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RNUMRESIZE, pParent)
	, m_nscale(0)
{

}

CRnumberscale::~CRnumberscale()
{
}

void CRnumberscale::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nscale);
}


BEGIN_MESSAGE_MAP(CRnumberscale, CDialogEx)
END_MESSAGE_MAP()


// CRnumberscale 메시지 처리기
