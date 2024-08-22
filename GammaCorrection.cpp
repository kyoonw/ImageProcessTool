#include"stdafx.h"
#include "GammaCorrection.h"
#include<math.h>

void GammaCorrection(IppByteImage& img, double gamma)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = limit((int)(pow(p[i]/255.0, 1/gamma)*255.0 + 0.4999999));
	}
}