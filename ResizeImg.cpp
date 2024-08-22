#include "stdafx.h"
#include"ResizeImg.h"

void NearestResize(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    int nw = w * ratio;
    int nh = h * ratio;

    imgDst.CreateImage(nw, nh);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    int i, j, x, y;
    double rx, ry;
    for (j = 0; j < nh; j++)
        for (i = 0; i < nw; i++)
        {
            rx = static_cast<double>(w - 1) * i / (nw - 1);
            ry = static_cast<double>(h - 1) * j / (nh - 1);
            x = static_cast<int>(rx + 0.5);
            y = static_cast<int>(ry + 0.5);

            if (x >= w) x = w - 1;
            if (y >= h) y = h - 1;

            pDst[j][i] = pSrc[y][x];
        }
}

void BilinearResize(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio)
{
    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    int nw = w * ratio;
    int nh = h * ratio;

    imgDst.CreateImage(nw, nh);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    int i, j, x1, y1, x2, y2;
    double rx, ry, p, q, value;

    for (j = 0; j < nh; j++)
        for (i = 0; i < nw; i++)
        {
            rx = static_cast<double>(w - 1) * i / (nw - 1);
            ry = static_cast<double>(h - 1) * j / (nh - 1);

            x1 = (int)(rx);
            y1 = (int)(ry);

            x2 = x1 + 1; if (x2 == w) x2 = w - 1;
            y2 = y1 + 1; if (y2 == h) y2 = h - 1;

            p = rx - x1;
            q = ry - y1;

            value = (1. - p) * (1. - q) * (double)pSrc[y1][x1]
                + p * (1. - q) * (double)pSrc[y1][x2]
                + (1. - p) * q * (double)pSrc[y2][x1]
                + p * q * (double)pSrc[y2][x2];

            pDst[j][i] = (int)(limit(value + .4999999));
        }
}