
// ImageToolDoc.h : CImageToolDoc Ŭ������ �������̽�
//


#pragma once
#include ".\IppImage\IppDib.h"


class CImageToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CImageToolDoc();
	DECLARE_DYNCREATE(CImageToolDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// ��Ʈ�� ��ü
	IppDib m_Dib;

	// ���� �ҷ����� & �����ϱ�
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	
	afx_msg void OnWindowDuplicate();
	afx_msg void OnEditCopy();
	afx_msg void OnSecChk();
	afx_msg void OnInverseImage();
	afx_msg void OnUpdateInverseImage(CCmdUI* pCmdUI);
	afx_msg void OnAddConst();
	afx_msg void OnUpdateAddConst(CCmdUI* pCmdUI);
	afx_msg void OnSubConst();
	afx_msg void OnUpdateSubConst(CCmdUI* pCmdUI);
	afx_msg void OnMultiConst();
	afx_msg void OnUpdateMultiConst(CCmdUI* pCmdUI);
	afx_msg void OnDivdConst();
	afx_msg void OnUpdateDivdConst(CCmdUI* pCmdUI);
	afx_msg void OnGreyTransform();
	afx_msg void OnUpdateGreyTransform(CCmdUI* pCmdUI);
	afx_msg void OnGammaCorrection();
	afx_msg void OnUpdateGammaCorrection(CCmdUI* pCmdUI);
	afx_msg void OnViewHistogram();
	afx_msg void OnUpdateViewHistogram(CCmdUI* pCmdUI);
	afx_msg void OnStretchHistogram();
	afx_msg void OnUpdateStretchHistogram(CCmdUI* pCmdUI);
	afx_msg void OnBnClickedOk();
	afx_msg void OnEndinsearch();
	afx_msg void OnUpdateEndinsearch(CCmdUI* pCmdUI);
	afx_msg void OnEqualizationHistogram();
	afx_msg void OnUpdateEqualizationHistogram(CCmdUI* pCmdUI);
	afx_msg void OnAddavg();
	afx_msg void OnSubdif();
	afx_msg void OnQulmse();
	afx_msg void OnLogicimg();
	afx_msg void OnBitplane();
	afx_msg void OnGeotranslate();
	afx_msg void OnVerref();
	afx_msg void OnHorref();
	afx_msg void OnMirror();
	afx_msg void OnExtpol();
	afx_msg void OnRsize();
	afx_msg void OnScaleimg();
	afx_msg void OnRnumresize();
	afx_msg void OnMeanfilter();
	afx_msg void OnWegfilt();
	afx_msg void OnGaussian();
	afx_msg void OnMidfilter();
	afx_msg void OnWeigtmidfilter();
};
