#include "stdafx.h"
#include "Rnumberscale.h"

void Rnumberresize(IppByteImage& imgSrc, IppByteImage& imgDst, double ratio)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    int nw = (int)(w * ratio + 0.4999999);
    int nh = (int)(h * ratio + 0.4999999);

    imgDst.CreateImage(nw, nh);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    int i, j, x1, y1, x2, y2;
    double rx, ry, p, q, value;

    for (j = 0; j < nh; j++)
        for (i = 0; i < nw; i++)
        {
            rx = static_cast<double>(w - 1.) * i / (nw - 1.);
            ry = static_cast<double>(h - 1.) * j / (nh - 1.);

            x1 = static_cast<int>(rx);
            y1 = static_cast<int>(ry);

            x2 = x1 + 1; if (x2 == w) x2 = w - 1;
            y2 = y1 + 1; if (y2 == h) y2 = h - 1;

            p = rx - x1;
            q = ry - y1;

            value = (1. - p) * (1. - q) * pSrc[y1][x1]
                + p * (1. - q) * pSrc[y1][x2]
                + (1. - p) * q * pSrc[y2][x1]
                + p * q * pSrc[y2][x2];

            pDst[j][i] = static_cast<BYTE>(limit(value + .4999999));
        }
}