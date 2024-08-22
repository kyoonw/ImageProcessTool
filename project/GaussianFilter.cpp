#include"stdafx.h"
#include"GaussianFilter.h"

const float PI_F = 3.14159265358979323846f;

void Gaussianfiter(IppByteImage& imgSrc, IppByteImage& imgDst, double sigma)
{

	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst.CreateImage(w, h);

	int i, j, k, x;
	int masksize = (int)(2 * 3 * sigma + 1);
	int hsize = masksize / 2;
	IppByteImage imgmir;

	Fullmirror(imgSrc, imgmir, hsize);


	BYTE** pSrc = imgmir.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	IppFloatImage imgMask(masksize, 1);
	float* pMask = imgMask.GetPixels();

	for (i = 0; i < masksize; i++)
	{
		x = i - hsize;
		pMask[i] = (float)(exp(-(x * x) / (2. * sigma * sigma)) / (sqrt(2. * PI_F) * sigma));
	}

	IppFloatImage imgBuf(w, h);
	float** pBuf = imgBuf.GetPixels2D();

	float sum1, sum2;
	for (i = 0; i < w; i++)
		for (j = hsize; j < h+ hsize; j++)
		{
			sum1 = sum2 = 0.f;

			for (k = 0; k < masksize; k++)
			{
				x = k - hsize + j;

				if (x >= 0 && x < h)
				{
					sum1 += pMask[k];
					sum2 += (pMask[k] * (float)pSrc[x][i]);
				}
			}

			pBuf[j-hsize][i] = sum2 / sum1;
		}

	for (j = 0; j < h; j++)
		for (i = hsize; i < w+hsize; i++)
		{
			sum1 = sum2 = 0.f;

			for (k = 0; k < masksize; k++)
			{
				x = k - hsize + i;

				if (x >= 0 && x < w)
				{
					sum1 += pMask[k];
					sum2 += (pMask[k] * (float)pBuf[j][x]);
				}
			}

			pDst[j][i-hsize] = static_cast<BYTE>(sum2 / sum1 + 0.4999999);
		}

}