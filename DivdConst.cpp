#include"stdafx.h"
#include "DivdConst.h"

void DivdConst(IppByteImage& img, double addc)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = (int)(limit(p[i] / addc )+0.499999);
	}
}