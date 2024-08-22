#include"stdafx.h"
#include"MidFilter.h"


void Midfilter(IppByteImage& imgSrc, IppByteImage& imgDst, int size)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w, h);

    int hsize = size / 2;

    IppByteImage imgmir;
    Fullmirror(imgSrc, imgmir, hsize);
    BYTE** pSrc = imgmir.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();



    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
        {
            int f = 0;
            int mid = 0;
            int* npixary;
            int rate = size;
            int filter = size * size;
            npixary = (int*)malloc(sizeof(int) * (filter));

            for (int k = 0; k < size; k++)
                for (int m = 0; m < size; m++)
                {
                    npixary[f] = pSrc[j+ k][i + m];
                    f++;
                }
            for (int z = f - 1; z > 0; z--)
                for (int u = 0; u < z; u++)
                {
                    if (npixary[u] < npixary[u + 1])
                    {
                        mid = npixary[u];
                        npixary[u] = npixary[u + 1];
                        npixary[u + 1] = mid;
                    }
                }
            pDst[j][i] = npixary[filter / 2];
        }

}

void WeightMidfilter(IppByteImage& imgSrc, IppByteImage& imgDst)
{

    int w = imgSrc.GetWidth();
    int h = imgSrc.GetHeight();

    imgDst.CreateImage(w, h);

    int size = 3;
    int hsize = size / 2;

    IppByteImage imgmir;
    Fullmirror(imgSrc, imgmir, hsize);
    BYTE** pSrc = imgmir.GetPixels2D();
    BYTE** pDst = imgDst.GetPixels2D();



    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
        {
            int f = 0;
            int mid = 0;
            int* npixary;
            int rate = size;
            int filter = size * size +2;
            npixary = (int*)malloc(sizeof(int) * (filter));

            for (int k = 0; k < size; k++)
                for (int m = 0; m < size; m++)
                {
                    npixary[f] = pSrc[j + k][i + m];
                    f++;
                }
            for (int q = 0; q < 2; q++)
            {
                npixary[f] = pSrc[j + 1][i + 1];
                f++;
            }
            for (int z = f - 1; z > 0; z--)
                for (int u = 0; u < z; u++)
                {
                    if (npixary[u] < npixary[u + 1])
                    {
                        mid = npixary[u];
                        npixary[u] = npixary[u + 1];
                        npixary[u + 1] = mid;
                    }
                }
            pDst[j][i] = npixary[filter / 2];
        }

}