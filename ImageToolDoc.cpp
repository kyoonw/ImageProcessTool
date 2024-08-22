
// ImageToolDoc.cpp : CImageToolDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageTool.h"
#endif

#include "ImageToolDoc.h"
#include "FileNewDlg.h"
#include "ImageToolSecChk.h"
#include "ImageToolSecChkDlg.h"

#include "IppImage/IppImage.h"
#include"IppImage/IppConvert.h"
#include"InverseImage.h"

#include "CAddConstDlg.h"
#include"AddConst.h"

#include"CSubConstDlg.h"
#include"SubConst.h"

#include"CMultiConstDlg.h"
#include"MultiConst.h"

#include"CDivdConstDlg.h"
#include"DivdConst.h"

#include "CGreyTransformDlg.h"
#include "GreyTransform.h"

#include "CGammaCorrectionDlg.h"
#include "GammaCorrection.h"

#include"GetHistogram.h"
#include"CHistogramDlg.h"

#include "StretchHistogram.h"

#include "CEndInSearch.h"
#include "End-InSearch.h"

#include"EqualizationHistogram.h"

#include"AddAvgImage.h"
#include"CAddAvgImageDlg.h"

#include"SubDiffImage.h"
#include"CSubDiffImageDlg.h"

#include"QualityMeasure.h"
#include"CQualityMeasureDlg.h"

#include"LogicImage.h"
#include"CLogicImageDlg.h"

#include"BitPlane.h"

#include"GeometricTranslate.h"
#include"CGeometricTranslateDlg.h"

#include"GeoReflection.h"

#include"Mirroring.h"
#include"CMirroringDlg.h"

#include"Extrapolatrion.h"
#include"CExtrapolationDlg.h"

#include"ResizeImg.h"
#include"CResizeImgDlg.h"

#include"ScaleImg.h"
#include"CScaleImgDlg.h"

#include"Rnumberscale.h"
#include"CRnumberscale.h"

#include"Filter.h"
#include"CMeanFilterDlg.h"

#include"CWeightFilterDlg.h"

#include"GaussianFilter.h"
#include"CGaussianFilterDlg.h"

#include"MidFilter.h"
#include"CMidFilter.h"

#include<string.h>

#include <propkey.h>

#define CONVERT_DIB_TO_BYTEIMAGE(m_Dib,img) \
IppByteImage img; \
IppDibToImage(m_Dib,img);

#define CONVERT_BYTEIMAGE_TO_DIB(img,dib) \
IppDib dib; \
IppImageToDib(img,dib);



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImageToolDoc

IMPLEMENT_DYNCREATE(CImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_SEC_CHK, &CImageToolDoc::OnSecChk)
	ON_COMMAND(ID_INVERSE_IMAGE, &CImageToolDoc::OnInverseImage)
	ON_UPDATE_COMMAND_UI(ID_INVERSE_IMAGE, &CImageToolDoc::OnUpdateInverseImage)
	ON_COMMAND(ID_ADD_CONST, &CImageToolDoc::OnAddConst)
	ON_UPDATE_COMMAND_UI(ID_ADD_CONST, &CImageToolDoc::OnUpdateAddConst)
	ON_COMMAND(ID_SUB_CONST, &CImageToolDoc::OnSubConst)
	ON_UPDATE_COMMAND_UI(ID_SUB_CONST, &CImageToolDoc::OnUpdateSubConst)
	ON_COMMAND(ID_MULTI_CONST, &CImageToolDoc::OnMultiConst)
	ON_UPDATE_COMMAND_UI(ID_MULTI_CONST, &CImageToolDoc::OnUpdateMultiConst)
	ON_COMMAND(ID_DIVD_CONST, &CImageToolDoc::OnDivdConst)
	ON_UPDATE_COMMAND_UI(ID_DIVD_CONST, &CImageToolDoc::OnUpdateDivdConst)
	ON_COMMAND(ID_GREY_TRANSFORM, &CImageToolDoc::OnGreyTransform)
	ON_UPDATE_COMMAND_UI(ID_GREY_TRANSFORM, &CImageToolDoc::OnUpdateGreyTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageToolDoc::OnGammaCorrection)
	ON_UPDATE_COMMAND_UI(ID_GAMMA_CORRECTION, &CImageToolDoc::OnUpdateGammaCorrection)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnViewHistogram)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnUpdateViewHistogram)
	ON_COMMAND(ID_STRETCH_HISTOGRAM, &CImageToolDoc::OnStretchHistogram)
	ON_UPDATE_COMMAND_UI(ID_STRETCH_HISTOGRAM, &CImageToolDoc::OnUpdateStretchHistogram)
	ON_COMMAND(ID_ENDINSEARCH, &CImageToolDoc::OnEndinsearch)
	ON_UPDATE_COMMAND_UI(ID_ENDINSEARCH, &CImageToolDoc::OnUpdateEndinsearch)
	ON_COMMAND(ID_EQUALIZATION_HISTOGRAM, &CImageToolDoc::OnEqualizationHistogram)
	ON_UPDATE_COMMAND_UI(ID_EQUALIZATION_HISTOGRAM, &CImageToolDoc::OnUpdateEqualizationHistogram)
	ON_COMMAND(ID_ADDAVG, &CImageToolDoc::OnAddavg)
	ON_COMMAND(ID_SUBDIF, &CImageToolDoc::OnSubdif)
	ON_COMMAND(ID_QULMSE, &CImageToolDoc::OnQulmse)
	ON_COMMAND(ID_LOGICIMG, &CImageToolDoc::OnLogicimg)
	ON_COMMAND(ID_BITPLANE, &CImageToolDoc::OnBitplane)
	ON_COMMAND(ID_GEOTRANSLATE, &CImageToolDoc::OnGeotranslate)
	ON_COMMAND(ID_VERREF, &CImageToolDoc::OnVerref)
	ON_COMMAND(ID_HORREF, &CImageToolDoc::OnHorref)
	ON_COMMAND(ID_MIRROR, &CImageToolDoc::OnMirror)
	ON_COMMAND(ID_EXTPOL, &CImageToolDoc::OnExtpol)
	ON_COMMAND(ID_Rsize, &CImageToolDoc::OnRsize)
	ON_COMMAND(ID_SCALEIMG, &CImageToolDoc::OnScaleimg)
	ON_COMMAND(ID_RNUMRESIZE, &CImageToolDoc::OnRnumresize)
	ON_COMMAND(ID_MEANFILTER, &CImageToolDoc::OnMeanfilter)
	ON_COMMAND(ID_WEGFILT, &CImageToolDoc::OnWegfilt)
	ON_COMMAND(ID_GAUSSIAN, &CImageToolDoc::OnGaussian)
	ON_COMMAND(ID_MIDFILTER, &CImageToolDoc::OnMidfilter)
	ON_COMMAND(ID_WEIGTMIDFILTER, &CImageToolDoc::OnWeigtmidfilter)
END_MESSAGE_MAP()


// CImageToolDoc 생성/소멸

CImageToolDoc::CImageToolDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageToolDoc::~CImageToolDoc()
{
}

BOOL CImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL ret = TRUE;

	if (theApp.m_pNewDib == NULL)
	{
		CFileNewDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			if (dlg.m_nType == 0) // 그레이스케일 비트맵
				ret = m_Dib.CreateGrayBitmap(dlg.m_nWidth, dlg.m_nHeight);
			else // 트루컬러 비트맵
				ret = m_Dib.CreateRgbBitmap(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		m_Dib = *(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	return ret;
}




// CImageToolDoc serialization

void CImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageToolDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageToolDoc 진단

#ifdef _DEBUG
void CImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageToolDoc 명령


BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	BOOL res = m_Dib.Load(CT2A(lpszPathName));
	if (res)
		AfxPrintInfo(_T("[파일 열기] 파일 경로: %s, 가로 크기: %d픽셀, 세로 크기: %d픽셀, 색상수: %d"),
			lpszPathName, m_Dib.GetWidth(), m_Dib.GetHeight(), 0x01 << m_Dib.GetBitCount());

	return res;
}


BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return m_Dib.Save(CT2A(lpszPathName));
}


void CImageToolDoc::OnWindowDuplicate()
{
	AfxNewBitmap(m_Dib);
}


void CImageToolDoc::OnEditCopy()
{
	if (m_Dib.IsValid())
		m_Dib.CopyToClipboard();
}


void CImageToolDoc::OnSecChk()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageToolSecChkDlg dlg;
	int result;
	if (dlg.DoModal() == IDOK)
	{
		result = ImageToolSecChk(dlg.m_nSecChk);
	}

	if (result == 0)
		AfxMessageBox(_T("실패(x): 보안코드 불일치"), MB_ICONERROR);
	else
		AfxMessageBox(_T("성공(o): 보안코드 일치"), MB_ICONINFORMATION);
}


void CImageToolDoc::OnInverseImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		InverseImage(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[반전] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);

}


void CImageToolDoc::OnUpdateInverseImage(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnAddConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CAddConstDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			AddConst(img, dlg.m_nAddConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[밝기 증가] 입력 영상: %s, 밝기값: %d"), GetTitle(), dlg.m_nAddConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateAddConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnSubConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSubConstDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			SubConst(img, dlg.m_nSubConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[밝기 감소] 입력 영상: %s, 감소값: %d"), GetTitle(), dlg.m_nSubConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateSubConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnMultiConst()
{
	CMultiConstDlg dlg;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			MultiConst(img, dlg.m_dMultiConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[밝기 대비 증가] 입력 영상: %s, 감소값: %d"), GetTitle(), dlg.m_dMultiConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateMultiConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnDivdConst()
{
	CDivdConstDlg dlg;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			DivdConst(img, dlg.m_dDivdConst);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[밝기 대비 감소] 입력 영상: %s, 감소값: %d"), GetTitle(), dlg.m_dDivdConst);
		AfxNewBitmap(dib);
	}	
}


void CImageToolDoc::OnUpdateDivdConst(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGreyTransform()
{
	CGreyTransformDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			GreyTransform(img, dlg.m_dCoefA, dlg.m_dCoefB);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[선형 영상 변환] 입력 영상: %s, 곱셈값: %lf, 덧셈값: %+lf"), GetTitle(), dlg.m_dCoefA, dlg.m_dCoefB);
		AfxNewBitmap(dib);
	}

}


void CImageToolDoc::OnUpdateGreyTransform(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnGammaCorrection()
{
	CGammaCorrectionDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			GammaCorrection(img, dlg.m_dGammaCorr);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[영상 감마 보정] 입력 영상: %s, 감마값: %lf"), GetTitle(), dlg.m_dGammaCorr);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateGammaCorrection(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnViewHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHistogramDlg dlg;

	dlg.SetImage(m_Dib);
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	dlg.m_nMin = GetMinGrayValue(img);
	dlg.m_nMax = GetMaxGrayValue(img);
	dlg.m_fAvgValue = GetAvgValue(img);
	dlg.m_fStdValue = GetStdValue(img, dlg.m_fAvgValue);

	AfxPrintInfo(_T("[히스토그램] 입력 영상: %s, 최소값: %d, 최대값: %d, 평균값: %.1f, 표준편차: %.1f"), GetTitle(), dlg.m_nMin,dlg.m_nMax,dlg.m_fAvgValue,dlg.m_fStdValue);

	dlg.DoModal();

}


void CImageToolDoc::OnUpdateViewHistogram(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnStretchHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		StretchHistogram(img, GetMaxGrayValue(img),GetMinGrayValue(img));
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[스트레칭] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);

}


void CImageToolDoc::OnUpdateStretchHistogram(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}



void CImageToolDoc::OnEndinsearch()
{
	CEndInSearch dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
			EndInSearch(img, dlg.m_nmax,dlg.m_nlow);
		CONVERT_BYTEIMAGE_TO_DIB(img, dib)

			AfxPrintInfo(_T("[영상 앤드-인 검색] 입력 영상: %s, 최대값: %d, 최소값: %d"), GetTitle(), dlg.m_nmax,dlg.m_nlow);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateEndinsearch(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnEqualizationHistogram()
{

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		EqualizationHistogram(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[평활화] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnUpdateEqualizationHistogram(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8);
}


void CImageToolDoc::OnAddavg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CAddAvgImageDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3;

		bool ret = false;

		switch (dlg.m_nFunction)
		{
		case 0: ret = AddImage(img1, img2, img3); break;
		case 1: ret = AvgImage(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR* op[] = { _T("덧셈"),_T("평균") };
			AfxPrintInfo(_T("[산술연산(영상): %s] 입력영상#1: %s, 입력영상#2: %s"), op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnSubdif()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CSubDiffImageDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3;

		bool ret = false;

		switch (dlg.m_nfunction)
		{
		case 0: ret = SubImage(img1, img2, img3); break;
		case 1: ret = DiffImage(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR* op[] = { _T("뺄셈"),_T("차이") };
			AfxPrintInfo(_T("[산술연산(영상): %s] 입력영상#1: %s, 입력영상#2: %s"), op[dlg.m_nfunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnQulmse()
{
	CQualityMeasureDlg dlg;
	CString otr;

	if (dlg.DoModal() == IDOK)
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);

		bool ret = false;
		ret = (img1.GetSize() == img2.GetSize());
		double dmse = CalculateMSE(img1, img2);
		double drmse = CalculateRMSE(img1, img2);
		double dpsnr = CalculatePSNR(img1, img2);
		double dmae = CalculateMAE(img1, img2);

		if (ret)
		{
			AfxPrintInfo(_T("입력영상#1: %s, 입력영상#2: %s"), pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxPrintInfo(_T("MSE:%lf, RMSE:%.1lf, PNSR:%lf, MAE:%lf"), dmse, drmse, dpsnr, dmae);
			otr.Format(_T("입력영상#1: %s\n 입력영상#2: %s \n\nMSE:%.1f\n RMSE:%.1f\n PNSR:%.1f\n MAE:%.1f"), pDoc1->GetTitle(), pDoc2->GetTitle(), dmse, drmse, dpsnr,dmae);
			AfxMessageBox(otr);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnLogicimg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CLogicImageDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3;

		bool ret = false;

		switch (dlg.m_nFunction)
		{
		case 0: ret = LogicAND(img1, img2, img3); break;
		case 1: ret = LogicOR(img1, img2, img3); break;
		case 2: ret = LogicXOR(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR* op[] = { _T("(AND)연산"),_T("(OR)연산"),_T("(XOR)연산")};
			AfxPrintInfo(_T("[논리연산(영상): %s] 입력영상#1: %s, 입력영상#2: %s"), op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}

}


void CImageToolDoc::OnBitplane()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
	AfxPrintInfo(_T("[비트 플랜] 입력 영상: %s"), GetTitle());
	IppByteImage img2;
	for (int i = 0; i < 8; i++) {
			BitPlane(img,img2,i);
		CONVERT_BYTEIMAGE_TO_DIB(img2, dib)
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnGeotranslate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGeometricTranslateDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppByteImage img2;
		if (GeoTranslate(img, img2, dlg.m_ninputX, dlg.m_ninputY)) {

			CONVERT_BYTEIMAGE_TO_DIB(img2, dib)
			AfxPrintInfo(_T("[이동 변환] 입력 영상: %s , X축: %d, Y축: %d"), GetTitle(),dlg.m_ninputX,dlg.m_ninputY);
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 입력값이 큽니다."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnVerref()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppByteImage img2;
		Verticalreflection(img,img2);
	CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

		AfxPrintInfo(_T("[상하대칭] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnHorref()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppByteImage img2;
	Horizonreflection(img, img2);
	CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

		AfxPrintInfo(_T("[좌우대칭] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnMirror()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMirroringDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
		IppByteImage img2;


		switch (dlg.m_nmirrorfunction)
		{
		case 0: Verticalmirroring(img1, img2,dlg.m_nsize); break;
		case 1: Horizonmirroring(img1, img2, dlg.m_nsize); break;
		case 2: Fullmirror(img1, img2, dlg.m_nsize); break;
		}

		CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

			TCHAR* op[] = { _T("상하대칭변환"),_T("좌우대칭변환"),_T("상하/좌우 대칭변환") };
			AfxPrintInfo(_T("[가변대칭변환(영상): %s] 입력영상: %s"), op[dlg.m_nmirrorfunction], GetTitle());
			AfxNewBitmap(dib);
	
	}

}


void CImageToolDoc::OnExtpol()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CExtrapolationDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
		IppByteImage img2;


		switch (dlg.m_nextrafunction)
		{
		case 0: ZeroPadding(img1, img2, dlg.m_nsize); break;
		case 1: PeriodicPading(img1, img2, dlg.m_nsize); break;
		case 2: SymmetricExtension(img1, img2, dlg.m_nsize); break;
		}

		CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

			TCHAR* op[] = { _T("Zero Pading"),_T("Periodic Pading"),_T("Symmetric Extension") };
		AfxPrintInfo(_T("[외곽처리(영상): %s] 입력영상: %s"), op[dlg.m_nextrafunction], GetTitle());
		AfxNewBitmap(dib);

	}
}


void CImageToolDoc::OnRsize()
{

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CResizeImgDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
		IppByteImage img2;


		switch (dlg.m_nfunction)
		{
		case 0: NearestResize(img1, img2, dlg.m_nsize); break;
		case 1: BilinearResize(img1, img2, dlg.m_nsize); break;
		}

		CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

			TCHAR* op[] = { _T("최근방 이웃 보간법"),_T("양선형 보간법")};
		AfxPrintInfo(_T("[보간법(영상): %s] 입력영상: %s"), op[dlg.m_nfunction], GetTitle());
		AfxNewBitmap(dib);

	}
}


void CImageToolDoc::OnScaleimg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CScaleImgDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.m_nratio > 0)
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
			IppByteImage img2;


			switch (dlg.m_nfunction)
			{
			case 0: Sampling(img1, img2, dlg.m_nratio); break;
			case 1: AvgSampling(img1, img2, dlg.m_nratio); break;
			case 2: MidSampling(img1, img2, dlg.m_nratio); break;
			}

			CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

				TCHAR* op[] = { _T("서브 샘플링"),_T("평균값 샘플링"),_T("중간값 샘플링") };
			AfxPrintInfo(_T("[%s] 입력영상: %s =>축소비율: %d"), op[dlg.m_nfunction], GetTitle(), dlg.m_nratio);
			AfxNewBitmap(dib);
		}
		else
		AfxMessageBox(_T("ERROR: 비율은 0보다 커야됩니다."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnRnumresize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CRnumberscale dlg;
	if (dlg.DoModal() == IDOK)
	{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
			IppByteImage img2;
			Rnumberresize(img1, img2, dlg.m_nscale);
			CONVERT_BYTEIMAGE_TO_DIB(img2, dib)

				int count = 0;
			if (dlg.m_nscale > 1) {
				count = 1;
			}

			TCHAR* op[] = { _T("축소"),_T("확대")};
			AfxPrintInfo(_T("[축소/확대(실수배) 변환] 입력영상: %s, 입력영상 크기: %d X %d, 확대/축소비율: %lf배, 결과영상크기: %d X %d "), GetTitle(), img1.GetWidth(),img1.GetHeight(), dlg.m_nscale, img2.GetWidth(), img2.GetHeight());
			AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnMeanfilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMeanFilterDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.m_nsize >= 3 && dlg.m_nsize <= 31 && (dlg.m_nsize % 2 == 1))
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
			IppByteImage img2;
			MeanFilter(img1, img2, dlg.m_nsize);
			CONVERT_BYTEIMAGE_TO_DIB(img2, dib);

			AfxPrintInfo(_T("[블러링: 평균값 필터] 입력영상: %s, 마스크 크기: %d X %d "), GetTitle(), dlg.m_nsize, dlg.m_nsize);
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 3 <= 마스크 크기 <= 31을 만족하는 홀수값 사용"), MB_ICONERROR);
	}
}


void CImageToolDoc::OnWegfilt()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CWeightFilterDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
		IppByteImage img2;


		switch (dlg.m_nfunction)
		{
		case 0: Weight3Filter(img1, img2); break;
		case 1: Weight5Filter(img1, img2); break;
		}

		CONVERT_BYTEIMAGE_TO_DIB(img2, dib)
		TCHAR* op[] = { _T("3 X 3"),_T("5 X 5") };
		AfxPrintInfo(_T("[블러링: 가중 평균값 필터] 입력영상: %s, 마스크 크기: %s"),  GetTitle() , op[dlg.m_nfunction]);
		AfxNewBitmap(dib);
	}
	
}



void CImageToolDoc::OnGaussian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGaussianFilterDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.m_nsigma >= 0.5 && dlg.m_nsigma <= 10)
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
			IppByteImage img2;
			Gaussianfiter(img1, img2, dlg.m_nsigma);
			CONVERT_BYTEIMAGE_TO_DIB(img2, dib);

			AfxPrintInfo(_T("[블러링: 평균값 필터] 입력영상: %s, Sigma값: %lf  "), GetTitle(),dlg.m_nsigma);
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 0.5에서 10사이의 숫자를 입력하시오"), MB_ICONERROR);
	}
}


void CImageToolDoc::OnMidfilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CMidFilter dlg;

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.m_nsize >= 3 && dlg.m_nsize <= 9)
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
			IppByteImage img2;
			Midfilter(img1, img2, dlg.m_nsize);
			CONVERT_BYTEIMAGE_TO_DIB(img2, dib);

			AfxPrintInfo(_T("[블러링: 중간값 필터] 입력영상: %s, 마스크 사이즈: %d  "), GetTitle(), dlg.m_nsize);
			AfxNewBitmap(dib);

		}
		else
			AfxMessageBox(_T("ERROR: 3에서 9사이의 숫자를 입력하시오"), MB_ICONERROR);
	}
}


void CImageToolDoc::OnWeigtmidfilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img1);
	IppByteImage img2;
	WeightMidfilter(img1, img2);
	CONVERT_BYTEIMAGE_TO_DIB(img2, dib);

	AfxPrintInfo(_T("[블러링: 가중 중간값 필터] 입력영상: %s "), GetTitle());
	AfxNewBitmap(dib);
}
