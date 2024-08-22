#include "stdafx.h"
#include "Filter.h"

void MeanFilter(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	int hsize = (int)(size / 2);

	imgDst.CreateImage(w, h);

	IppByteImage imgmir;

	Fullmirror(imgSrc, imgmir, hsize);

	BYTE** pSrc = imgmir.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();
	
	for(int i=0; i<h;i++)
		for (int j = 0; j < w; j++)
		{
			int sum = 0;
			for(int y= 0; y<size; y++)
				for (int x = 0; x < size; x++)
				{
					sum += pSrc[i+y][j +x];
				}

			pDst[i][j] = (int)((float)sum / (size * size) + 0.4999999);
		}

}

void Weight3Filter(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	int hsize = (int)(3 / 2);

	imgDst.CreateImage(w, h);

	IppByteImage imgmir;

	Fullmirror(imgSrc, imgmir, hsize);

	BYTE** pSrc = imgmir.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[3][3] = {
		{ 1, 2, 1 },
		{ 2, 4, 2 },
		{ 1, 2, 1 },
	};

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			int sum = 0;
			for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
				{
					sum += (pSrc[i + y][j + x]*mask[y][x]);
				}

			pDst[i][j] = limit((int)((sum / 16.)  + 0.4999999));
		}
}

void Weight5Filter(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	int hsize = (int)(5 / 2);

	imgDst.CreateImage(w, h);

	IppByteImage imgmir;

	Fullmirror(imgSrc, imgmir, hsize);

	BYTE** pSrc = imgmir.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int mask[5][5] = {
		{ 1,4,6,4,1 },
		{ 4,16,24,15,4},
		{ 6,24,36,24,6},
		{ 4,16,24,16,4},
		{ 1,4,6,4,1},
	};

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			double sum = 0.;
			for (int y = 0; y < 5; y++)
				for (int x = 0; x < 5; x++)
				{
					sum += (pSrc[i + y][j + x] * mask[y][x]);
				}

			pDst[i][j] = (int)limit(((sum / 256) + 1));
		}
}