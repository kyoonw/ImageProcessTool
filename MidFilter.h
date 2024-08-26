#pragma once
#include"IppImage/IppImage.h"
#include<math.h>
#include"Mirroring.h"

void Midfilter(IppByteImage& imgSrc, IppByteImage& imgDst, int size);
void WeightMidfilter(IppByteImage& imgSrc, IppByteImage& imgDst);