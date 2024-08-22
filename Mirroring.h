#pragma once

#include"IppImage/IppImage.h"
#include<math.h>

void Verticalmirroring(IppByteImage& imgSrc, IppByteImage& imgDst, int size);
void Horizonmirroring(IppByteImage& imgSrc, IppByteImage& imgDst, int size);
void Fullmirror(IppByteImage& imgSrc, IppByteImage& imgDst, int size);