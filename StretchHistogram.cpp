#include "stdafx.h"
#include "StretchHistogram.h"

void StretchHistogram(IppByteImage& img, int max_histo, int min_histo) {
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = (int)((float)(p[i] - min_histo) / (max_histo - min_histo) * 255. + 0.499999);
	}
}