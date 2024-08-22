#include "stdafx.h"
#include "Extrapolatrion.h"

void ZeroPadding(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w + (2 * size), h + (2 * size));

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();
    for (int j = size; j < size + h; j++)
    {
        for (int i = size; i < size + w; i++)
        {
            pDst[j][i] = pSrc[j-size][i-size];
        }
    }
}

void PeriodicPading(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w + (2 * size), h + (2 * size));

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            pDst[j][i] = pSrc[(h-size) + j - 1][(w-size) +i - 1];
        }

        for (int i = size; i < w + size; i++)
        {
            pDst[j][i] = pSrc[(h - size) + j - 1][i - size];
        }

        for (int i = w + size; i < w + (2 * size); i++)
        {
            pDst[j][i] = pSrc[(h - size) + j - 1][i-(w+size)];
        }
    }

    for (int j = size; j < h + size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            pDst[j][i] = pSrc[j - size][(w - size) + i - 1];
        }

        for (int i = size; i < w + size; i++)
        {
            pDst[j][i] = pSrc[j - size][i - size];
        }

        for (int i = w + size; i < w + (2 * size); i++)
        {
            pDst[j][i] = pSrc[j - size][i - (w + size)];
        }

    }

    for (int j = h + size; j < h + (2 * size); j++)
    {
        for (int i = 0; i < size; i++)
        {
            pDst[j][i] = pSrc[j-(h+size)][(w - size) + i - 1];
        }

        for (int i = size; i < w + size; i++)
        {
            pDst[j][i] = pSrc[j - (h + size)][i - size];
        }

        for (int i = w + size; i < w + (2 * size); i++)
        {
            pDst[j][i] = pSrc[j - (h + size)][i - (w + size)];
        }

    }

}

void SymmetricExtension(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w + (2 * size), h + (2 * size));

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