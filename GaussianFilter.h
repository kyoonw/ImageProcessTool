#pragma once
#include"IppImage/IppImage.h"
#include<math.h>
#include"Mirroring.h"

void Gaussianfiter(IppByteImage& imgSrc, IppByteImage& imgDst, double sigma);