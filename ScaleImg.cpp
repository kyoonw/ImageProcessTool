#include "stdafx.h"
#include"ScaleImg.h"

void Sampling(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    int nw = (int)(w / ratio);
    int nh = (int)(h / ratio);

    imgDst.CreateImage(nw, nh);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    for (int j = 0; j < nh; j++)
        for (int i = 0; i < nw; i++)
        {
            pDst[j][i] = pSrc[j*ratio][i*ratio];
        }

}

void AvgSampling(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    int nw = (int)(w / ratio);
    int nh = (int)(h / ratio);

    imgDst.CreateImage(nw, nh);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    int filter = ratio *ratio;

    for (int j = 0; j < nh; j++)
        for (int i = 0; i < nw; i++)
        {
            double sum = 0;
            for (int k = 0; k < ratio; k++)
                for (int m = 0; m < ratio; m++)
                    sum += (double)pSrc[j * ratio + k][i * ratio + m];
            pDst[j][i] = (int)limit((sum/(double)filter +0.4999999));
        }

}

void MidSampling(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    int nw = (int)(w / ratio);
    int nh = (int)(h / ratio);

    imgDst.CreateImage(nw, nh);

    BYTE** pSrc = imgSrc.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();

    int* npixary;
    npixary = (int*)malloc(sizeof(int) *(ratio*ratio));

    for (int j = 0; j < nh; j++)
        for (int i = 0; i < nw; i++)
        {
            int f = 0;
            int mid = 0;
            int* npixary;
            int rate = ratio;
            int filter = ratio *ratio;
            npixary = (int*)malloc(sizeof(int) * (filter));

            for (int k = 0; k < ratio; k++)
                for (int m = 0; m < ratio; m++)
                {
                    npixary[f] = pSrc[j * rate + k][i * rate + m];
                    f++;
                }
            for (int z = f-1; z >0; z--)
                for (int u = 0; u < z; u++)
                {
                    if (npixary[u] < npixary[u + 1])
                    {
                        mid = npixary[u];
                        npixary[u] = npixary[u + 1];
                        npixary[u + 1] = mid;
                    }
                }
            pDst[j][i] = npixary[filter/2 ];
        }

}
