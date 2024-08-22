// CEndInSearch.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CEndInSearch.h"


// CEndInSearch 대화 상자

IMPLEMENT_DYNAMIC(CEndInSearch, CDialogEx)

CEndInSearch::CEndInSearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENDINSEARCH, pParent)
	, m_nmax(0)
	, m_nlow(0)
{

}

CEndInSearch::~CEndInSearch()
{
}

void CEndInSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ENDINMAX, m_nmax);
	DDV_MinMaxInt(pDX, m_nmax, 0, 255);
	DDX_Text(pDX, IDC_ENDINLOW, m_nlow);
	DDV_MinMaxInt(pDX, m_nlow, 0, 255);
}


BEGIN_MESSAGE_MAP(CEndInSearch, CDialogEx)
END_MESSAGE_MAP()


// CEndInSearch 메시지 처리기
