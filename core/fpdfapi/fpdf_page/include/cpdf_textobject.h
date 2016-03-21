// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FPDFAPI_FPDF_PAGE_INCLUDE_CPDF_TEXTOBJECT_H_
#define CORE_FPDFAPI_FPDF_PAGE_INCLUDE_CPDF_TEXTOBJECT_H_

#include "core/fpdfapi/fpdf_page/include/cpdf_pageobject.h"
#include "core/include/fxcrt/fx_string.h"
#include "core/include/fxcrt/fx_system.h"

struct CPDF_TextObjectItem {
  FX_DWORD m_CharCode;
  FX_FLOAT m_OriginX;
  FX_FLOAT m_OriginY;
};

class CPDF_TextObject : public CPDF_PageObject {
 public:
  CPDF_TextObject();
  ~CPDF_TextObject() override;

  // CPDF_PageObject:
  CPDF_TextObject* Clone() const override;
  Type GetType() const override { return TEXT; };
  void Transform(const CFX_Matrix& matrix) override;
  bool IsText() const override { return true; };
  CPDF_TextObject* AsText() override { return this; };
  const CPDF_TextObject* AsText() const override { return this; };

  int CountItems() const { return m_nChars; }
  void GetItemInfo(int index, CPDF_TextObjectItem* pInfo) const;
  int CountChars() const;
  void GetCharInfo(int index, FX_DWORD& charcode, FX_FLOAT& kerning) const;
  void GetCharInfo(int index, CPDF_TextObjectItem* pInfo) const;
  FX_FLOAT GetCharWidth(FX_DWORD charcode) const;
  FX_FLOAT GetPosX() const { return m_PosX; }
  FX_FLOAT GetPosY() const { return m_PosY; }
  void GetTextMatrix(CFX_Matrix* pMatrix) const;
  CPDF_Font* GetFont() const { return m_TextState.GetFont(); }
  FX_FLOAT GetFontSize() const { return m_TextState.GetFontSize(); }

  void SetText(const CFX_ByteString& text);
  void SetPosition(FX_FLOAT x, FX_FLOAT y);

  void RecalcPositionData() { CalcPositionData(nullptr, nullptr, 1); }

 protected:
  friend class CPDF_RenderStatus;
  friend class CPDF_StreamContentParser;
  friend class CPDF_TextRenderer;

  void SetSegments(const CFX_ByteString* pStrs, FX_FLOAT* pKerning, int nSegs);

  void CalcPositionData(FX_FLOAT* pTextAdvanceX,
                        FX_FLOAT* pTextAdvanceY,
                        FX_FLOAT horz_scale,
                        int level = 0);

  FX_FLOAT m_PosX;
  FX_FLOAT m_PosY;
  int m_nChars;
  FX_DWORD* m_pCharCodes;
  FX_FLOAT* m_pCharPos;
};

#endif  // CORE_FPDFAPI_FPDF_PAGE_INCLUDE_CPDF_TEXTOBJECT_H_
