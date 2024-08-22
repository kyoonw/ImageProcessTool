#pragma once
#include"IppImage/IppImage.h"
#include<math.h>

void NearestResize(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio);
void BilinearResize(IppByteImage& imgSrc, IppByteImage& imgDst, int ratio);