#include "stdafx.h"
#include "LogicImage.h"



bool LogicAND(IppByteImage& img1, IppByteImage& img2, IppByteImage& img3)
{
    int w = img1.GetWidth();
    int h = img1.GetHeight();

    if (w != img2.GetWidth() || h != img2.GetHeight())
        return false;

    img3.CreateImage(w, h);

    int size = img3.GetSize();
    BYTE* p1 = img1.GetPixels();
    BYTE* p2 = img2.GetPixels();
    BYTE* p3 = img3.GetPixels();

    for (int i = 0; i < size; i++)
    {
        p3[i] = static_cast<BYTE>(p1[i] & p2[i]);
    }

    return true;
}

bool LogicOR(IppByteImage& img1, IppByteImage& img2, IppByteImage& img3)
{
    int w = img1.GetWidth();
    int h = img1.GetHeight();

    if (w != img2.GetWidth() || h != img2.GetHeight())
        return false;

    img3.CreateImage(w, h);

    int size = img3.GetSize();
    BYTE* p1 = img1.GetPixels();
    BYTE* p2 = img2.GetPixels();
    BYTE* p3 = img3.GetPixels();

    for (int i = 0; i < size; i++)
    {
        p3[i] = static_cast<BYTE>(p1[i] | p2[i]);
    }

    return true;
}

bool LogicXOR(IppByteImage& img1, IppByteImage& img2, IppByteImage& img3)
{
    int w = img1.GetWidth();
    int h = img1.GetHeight();

    if (w != img2.GetWidth() || h != img2.GetHeight())
        return false;

    img3.CreateImage(w, h);

    int size = img3.GetSize();
    BYTE* p1 = img1.GetPixels();
    BYTE* p2 = img2.GetPixels();
    BYTE* p3 = img3.GetPixels();

    for (int i = 0; i < size; i++)
    {
        p3[i] = static_cast<BYTE>(p1[i] ^ p2[i]);
    }

    return true;
}


