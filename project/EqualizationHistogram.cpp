#include "stdafx.h"
#include "EqualizationHistogram.h"

void EqualizationHistogram(IppByteImage& img) {
	int size = img.GetSize();
	BYTE* p = img.GetPixels();
	double histo[256] = {0.0,};
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		histo[p[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		sum += (int)histo[i];
		histo[i] = sum;
	}
	for (int i = 0; i < 256; i++)
	{
		histo[i] = (int)(limit((histo[i] / size * 255. + 0.499999)));
	}
	for (int i = 0; i < size; i++)
	{
		p[i] = (int)histo[p[i]];
	}
}