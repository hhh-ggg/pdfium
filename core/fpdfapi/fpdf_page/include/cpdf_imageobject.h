// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FPDFAPI_FPDF_PAGE_INCLUDE_CPDF_IMAGEOBJECT_H_
#define CORE_FPDFAPI_FPDF_PAGE_INCLUDE_CPDF_IMAGEOBJECT_H_

#include "core/fpdfapi/fpdf_page/include/cpdf_pageobject.h"
#include "core/include/fxcrt/fx_coordinates.h"

class CPDF_Image;

class CPDF_ImageObject : public CPDF_PageObject {
 public:
  CPDF_ImageObject();
  ~CPDF_ImageObject() override;

  // CPDF_PageObject:
  CPDF_ImageObject* Clone() const override;
  Type GetType() const override { return IMAGE; };
  void Transform(const CFX_Matrix& matrix) override;
  bool IsImage() const override { return true; };
  CPDF_ImageObject* AsImage() override { return this; };
  const CPDF_ImageObject* AsImage() const override { return this; };

  void CalcBoundingBox();

  CPDF_Image* m_pImage;
  CFX_Matrix m_Matrix;
};

#endif  // CORE_FPDFAPI_FPDF_PAGE_INCLUDE_CPDF_IMAGEOBJECT_H_
