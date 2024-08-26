#pragma once
#include"IppImage/IppImage.h"
#include<math.h>
#include"Mirroring.h"

void MeanFilter(IppByteImage& imgSrc, IppByteImage& imgDst, int size);
void Weight3Filter(IppByteImage& imgSrc, IppByteImage& imgDst);
void Weight5Filter(IppByteImage& imgSrc, IppByteImage& imgDst);