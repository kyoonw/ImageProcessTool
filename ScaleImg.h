#pragma once
#include"IppImage/IppImage.h"
#include<math.h>

void Sampling(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio);
void AvgSampling(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio);
void MidSampling(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio);