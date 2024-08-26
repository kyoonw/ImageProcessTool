#pragma once

#include "IppImage/IppImage.h"
#include<math.h>
#include<stdlib.h>

double CalculateMSE(IppByteImage& img1, IppByteImage& img2);
double CalculateRMSE(IppByteImage& img1, IppByteImage& img2);
double CalculatePSNR(IppByteImage& img1, IppByteImage& img2);
double CalculateMAE(IppByteImage& img1, IppByteImage& img2);