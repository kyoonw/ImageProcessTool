#include"stdafx.h"
#include "GreyTransform.h"

void GreyTransform(IppByteImage& img,double multic , double addc)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = (int)(limit(multic * p[i] + addc)+0.499999999);
	}
}