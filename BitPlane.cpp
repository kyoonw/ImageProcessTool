#include"stdafx.h"
#include"BitPlane.h"

void BitPlane(IppByteImage& img1, IppByteImage& img2, int bit)
{
	int w = img1.GetWidth();
	int h = img1.GetHeight();

	img2.CreateImage(w, h);

	int size = img1.GetSize();
	BYTE* p1 = img1.GetPixels();
	BYTE* p2 = img2.GetPixels();

	for (int i = 0; i < size; i++) {
		p2[i] = (p1[i] & (1 << bit)) ? 255 : 0;
	}

}