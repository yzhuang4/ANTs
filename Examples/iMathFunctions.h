/*=========================================================================

  Program:   Advanced Normalization Tools

  Copyright (c) ConsortiumOfANTS. All rights reserved.
  See accompanying COPYING.txt or
 https://github.com/stnava/ANTs/blob/master/ANTSCopyright.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __iMathFunctions_h
#define __iMathFunctions_h

#include "antsUtilities.h"
#include "itkFlatStructuringElement.h"

namespace ants
{
// Templated functions that perform the work for
// iMath.cxx and iMath.cpp (in ANTSR)
// after each function, suggested default parameters are defined

unsigned int morph_shape_flag( const char * shape );

template<class ImageType>
typename ImageType::Pointer
iMathBlobDetector( typename ImageType::Pointer image, unsigned int nBlobs);                    /*???*/

// Canny Edge Filter
template <class ImageType>
typename ImageType::Pointer
iMathCanny(typename ImageType::Pointer image,                                                    /*0*/
           double sigma,
           double lowerThreshold,
           double upperThreshold );

// Distance Map
template <class ImageType>
typename ImageType::Pointer
iMathDistanceMap(typename ImageType::Pointer image, bool useSpacing );                               /*0*/
#define iMathDistanceMapUseSpacing true;

// Fill Holes in objects
template <class ImageType>
typename ImageType::Pointer
iMathFillHoles(typename ImageType::Pointer image, double holeParam );                                  /*0*/
#define iMathFillHolesHoleParam 2;


#define iMathGetLargestComponentMinSize 50;

template <unsigned int ImageDimension>
typename itk::FlatStructuringElement<ImageDimension>
iMathGetFlatStructuringElement( unsigned int shape,
                                unsigned long radius,
                                bool radiusIsParametric,
                                unsigned int lines,
                                unsigned int thickness,
                                bool includeCenter );
#define iMathGetFlatStructuringElementShape 1;
#define iMathGetFlatStructuringElementRadius 1;
#define iMathGetFlatStructuringElementLines 3;
#define iMathGetFlatStructuringElementThickness 1;
#define iMathGetFlatStructuringElementIncludeCenter false;
#define iMathGetFlatStructuringElementRadiusIsParametric false;


// Grayscale morphological closing
template <class ImageType>
typename ImageType::Pointer
iMathGC(typename ImageType::Pointer image, unsigned long radius);                               /*0*/
#define iMathGCRadius 1;
#define iMathGCValue 1;

// Grayscale morphological dilation
template <class ImageType>
typename ImageType::Pointer
iMathGD(typename ImageType::Pointer image, unsigned long radius);                            /*0*/   /*3*/
#define iMathGDRadius 1;
#define iMathGDValue 1;



}
#include "iMathFunctions.hxx"

#endif
