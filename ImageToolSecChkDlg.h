#pragma once


// CImageToolSecChkDlg ��ȭ �����Դϴ�.

class CImageToolSecChkDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageToolSecChkDlg)

public:
	CImageToolSecChkDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CImageToolSecChkDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SEC_CHK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nSecChk;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeSecChkEdit();
};
