#include "stdafx.h"
#include "Mirroring.h"

void Verticalmirroring(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w, h +(2*size));

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int j = 0; j < size; j++)
        for (int i = 0; i < w; i++)
        {
            pDst[j][i] = pSrc[size - j - 1][i];
        }

    for (int j = size; j < h+size; j++)
        for (int i = 0; i < w; i++)
        {
            pDst[j][i] = pSrc[j - size][i];
        }

    for (int j = h+size; j < h+(2*size); j++)
        for (int i = 0; i < w; i++)
        {
            pDst[j][i] = pSrc[h-(j-h-size) - 1][i];
        }



}

void Horizonmirroring(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w+(2*size), h);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int i = 0; i < size; i++)
        for (int j = 0; j < h; j++)
        {
            pDst[j][i] = pSrc[j][size-i-1];
        }

    for (int i = size; i < w + size; i++)
        for (int j = 0; j < h; j++)
        {
            pDst[j][i] = pSrc[j][i-size];
        }

    for (int i = w+size; i < w+(2*size); i++)
        for (int j = 0; j < h ; j++)
        {
            pDst[j][i] = pSrc[j][w-(i-w-size) - 1];
        }




}

void Fullmirror(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w + (2*size), h + (2 * size));

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
            {
                pDst[j][i] = pSrc[size - j - 1][size - i - 1];
            }

        for (int i = size; i < w + size; i++)
            {
                pDst[j][i] = pSrc[size - j - 1][i - size];
            }

        for (int i = w + size; i < w + (2 * size); i++)
            {
                pDst[j][i] = pSrc[size - j - 1][w - (i - w - size) - 1];
            }
    }

    for (int j = size; j < h + size; j++)
    {
        for (int i = 0; i < size; i++)
            {
                pDst[j][i] = pSrc[j - size][size - i - 1];
            }

        for (int i = size; i < w + size; i++)
            {
                pDst[j][i] = pSrc[j - size][i - size];
            }

        for (int i = w + size; i < w + (2 * size); i++)
            {
                pDst[j][i] = pSrc[j - size][w - (i - w - size) - 1];
            }

    }

    for (int j = h + size; j < h + (2 * size); j++)
    {
        for (int i = 0; i < size; i++)
            {
                pDst[j][i] = pSrc[h - (j - h - size) - 1][size - i - 1];
            }

        for (int i = size; i < w + size; i++)
            {
                pDst[j][i] = pSrc[h - (j - h - size) - 1][i - size];
            }

        for (int i = w + size; i < w + (2 * size); i++)
            {
                pDst[j][i] = pSrc[h - (j - h - size) - 1][w - (i - w - size) - 1];
            }

    }

}