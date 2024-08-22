#include "stdafx.h"
#include "End-InSearch.h"

void EndInSearch(IppByteImage& img, int max, int low) {
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		if (p[i] < low) {
			p[i] = 0;
		}
		else if (p[i] > max) {
			p[i] = 255;
		}
		else {
			p[i] = (int)((float)(p[i] - low) / (max - low) * 255. + 0.4999999);
		}
	}
}