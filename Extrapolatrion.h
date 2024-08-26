#pragma once
#include"IppImage/IppImage.h"
#include<math.h>

void ZeroPadding(IppByteImage& imgSrc, IppByteImage& imgDst, int size);
void PeriodicPading(IppByteImage& imgSrc, IppByteImage& imgDst, int size);
void SymmetricExtension(IppByteImage& imgSrc, IppByteImage& imgDst, int size);