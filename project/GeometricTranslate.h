#pragma once

#include"IppImage/IppImage.h"
#include<math.h>

bool GeoTranslate(IppByteImage& imgSrc, IppByteImage& imgDst, int sx, int sy);
