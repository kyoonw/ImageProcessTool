// ImageToolSecChkDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ImageToolSecChkDlg.h"
#include "afxdialogex.h"


// CImageToolSecChkDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CImageToolSecChkDlg, CDialogEx)

CImageToolSecChkDlg::CImageToolSecChkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageToolSecChkDlg::IDD, pParent)
	, m_nSecChk(0)
{

}

CImageToolSecChkDlg::~CImageToolSecChkDlg()
{
}

void CImageToolSecChkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEC_CHK_EDIT, m_nSecChk);
	DDV_MinMaxInt(pDX, m_nSecChk, 0, 99999999);
}


BEGIN_MESSAGE_MAP(CImageToolSecChkDlg, CDialogEx)
	ON_EN_CHANGE(IDC_SEC_CHK_EDIT, &CImageToolSecChkDlg::OnEnChangeSecChkEdit)
END_MESSAGE_MAP()


// CImageToolSecChkDlg �޽��� ó�����Դϴ�.


BOOL CImageToolSecChkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CImageToolSecChkDlg::OnEnChangeSecChkEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
}
