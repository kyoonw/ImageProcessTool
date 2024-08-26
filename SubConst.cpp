#include"stdafx.h"
#include "SubConst.h"

void SubConst(IppByteImage& img, int addc)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = limit(p[i] - addc);
	}
}