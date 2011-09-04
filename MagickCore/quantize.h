/*
  Copyright 1999-2011 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickCore image quantization methods.
*/
#ifndef _MAGICKCORE_QUANTIZE_H
#define _MAGICKCORE_QUANTIZE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "MagickCore/colorspace.h"

typedef enum
{
  UndefinedDitherMethod,
  NoDitherMethod,
  RiemersmaDitherMethod,
  FloydSteinbergDitherMethod
} DitherMethod;

typedef struct _QuantizeInfo
{
  size_t
    number_colors;

  size_t
    tree_depth;

  MagickBooleanType
    dither;

  ColorspaceType
    colorspace;

  MagickBooleanType
    measure_error;

  size_t
    signature;

  DitherMethod
    dither_method;
} QuantizeInfo;

extern MagickExport MagickBooleanType
  CompressImageColormap(Image *,ExceptionInfo *),
  GetImageQuantizeError(Image *),
  PosterizeImage(Image *,const size_t,const MagickBooleanType,ExceptionInfo *),
  QuantizeImage(const QuantizeInfo *,Image *,ExceptionInfo *),
  QuantizeImages(const QuantizeInfo *,Image *,ExceptionInfo *),
  RemapImage(const QuantizeInfo *,Image *,const Image *,ExceptionInfo *),
  RemapImages(const QuantizeInfo *,Image *,const Image *,ExceptionInfo *);

extern MagickExport QuantizeInfo
  *AcquireQuantizeInfo(const ImageInfo *),
  *CloneQuantizeInfo(const QuantizeInfo *),
  *DestroyQuantizeInfo(QuantizeInfo *);

extern MagickExport void
  GetQuantizeInfo(QuantizeInfo *);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
