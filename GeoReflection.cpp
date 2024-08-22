#include "stdafx.h"
#include "GeoReflection.h"

void Horizonreflection(IppByteImage& imgSrc, IppByteImage& imgDst)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w, h);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
        {
            pDst[j][i] = pSrc[j][w-i-1];
        }

}

void Verticalreflection(IppByteImage& imgSrc, IppByteImage& imgDst)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w, h);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
        {
            pDst[j][i] = pSrc[h-j-1][i];
        }

}