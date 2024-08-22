#include "stdafx.h"
#include "QualityMeasure.h"

double CalculateMSE(IppByteImage& img1, IppByteImage& img2)
{
	int w = img1.GetWidth();
	int h = img1.GetHeight();
	if (w != img2.GetWidth() || h != img2.GetHeight())
		return -1.0;

	int size = img1.GetSize();
	BYTE* p1 = img1.GetPixels();
	BYTE* p2 = img2.GetPixels();



	double diff = 0.;
	double diffsum = 0.;
	double mse = 0.;

	for (int i = 0; i < size; i++) {
		diff = (double)(p1[i] - p2[i]);
		diffsum += (diff*diff);
	}

	mse = diffsum / (double)size;

	return round(mse * 10) / 10;
}

double CalculateRMSE(IppByteImage& img1, IppByteImage& img2)
{
	double Rmse = sqrt(CalculateMSE(img1, img2));
	Rmse = (double)(round(Rmse * 10.) / 10.);
	return Rmse;
}

double CalculatePSNR(IppByteImage& img1, IppByteImage& img2)
{
	double Psnr = 0.;
	Psnr = 10 * log10((double)(255*255)/CalculateMSE(img1, img2));
	Psnr = round(Psnr * 10.) / 10.;
	return Psnr;
}

double CalculateMAE(IppByteImage& img1, IppByteImage& img2)
{
	int w = img1.GetWidth();
	int h = img1.GetHeight();
	if (w != img2.GetWidth() || h != img2.GetHeight())
		return -1.0;

	int size = img1.GetSize();
	BYTE* p1 = img1.GetPixels();
	BYTE* p2 = img2.GetPixels();

	double diff = 0.;
	double diffsum = 0.;
	double mae = 0.;

	for (int i = 0; i < size; i++) {
		diff = (double)(abs(p1[i] - p2[i]));
		diffsum += diff;
	}

	mae = diffsum / (double)size;

	return round(mae * 10) / 10;
}
