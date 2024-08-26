#include"stdafx.h"
#include"GeometricTranslate.h"

bool GeoTranslate(IppByteImage& imgSrc, IppByteImage& imgDst, int sx, int sy)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    if (abs(sx) >= w || abs(sy) >= h)
        return false;

    imgDst.CreateImage(w, h);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    int x = 0;
    int y = 0;
    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
        {
            x = i - sx;
            y = j - sy;
            if (x >= 0 && x < w && y >= 0 && y < h)
                pDst[j][i] = pSrc[y][x];
        }

    return true;
}