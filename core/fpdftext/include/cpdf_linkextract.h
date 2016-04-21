// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FPDFTEXT_INCLUDE_CPDF_LINKEXTRACT_H_
#define CORE_FPDFTEXT_INCLUDE_CPDF_LINKEXTRACT_H_

#include <vector>

#include "core/fxcrt/include/fx_basic.h"
#include "core/fxcrt/include/fx_coordinates.h"
#include "core/fxcrt/include/fx_string.h"
#include "core/fxcrt/include/fx_system.h"

class CPDF_TextPage;

class CPDF_LinkExtract {
 public:
  explicit CPDF_LinkExtract(const CPDF_TextPage* pTextPage);
  ~CPDF_LinkExtract();

  void ExtractLinks();
  size_t CountLinks() const { return m_LinkArray.size(); }
  CFX_WideString GetURL(size_t index) const;
  void GetRects(size_t index, CFX_RectArray* pRects) const;

 protected:
  void ParseLink();
  bool CheckWebLink(CFX_WideString& str);
  bool CheckMailLink(CFX_WideString& str);

 private:
  struct Link {
    int m_Start;
    int m_Count;
    CFX_WideString m_strUrl;
  };

  const CPDF_TextPage* const m_pTextPage;
  CFX_WideString m_strPageText;
  std::vector<Link> m_LinkArray;
};

#endif  // CORE_FPDFTEXT_INCLUDE_CPDF_LINKEXTRACT_H_
