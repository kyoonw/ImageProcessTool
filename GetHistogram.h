#pragma once

#include "IppImage/IppImage.h"

//히스토그램 함수 선언 
void GetHistogram(IppByteImage& img, double histo[256]);
int GetMinGrayValue(IppByteImage& img);
int GetMaxGrayValue(IppByteImage& img);
float GetAvgValue(IppByteImage& img);
float GetStdValue(IppByteImage& img, float avg); 