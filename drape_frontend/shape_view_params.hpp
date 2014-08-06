#pragma once

#include "../drape/drape_global.hpp"
#include "../drape/color.hpp"

#include "../indexer/feature_decl.hpp"
#include "../geometry/point2d.hpp"

#include "../std/string.hpp"

namespace df
{

struct CommonViewParams
{
  float m_depth;
};

struct PoiSymbolViewParams : CommonViewParams
{
  PoiSymbolViewParams(FeatureID const & id) : m_id(id) {}

  FeatureID m_id;
  string m_symbolName;
};

struct CircleViewParams : CommonViewParams
{
  CircleViewParams(FeatureID const & id) : m_id(id) {}

  FeatureID m_id;
  dp::Color m_color;
  float m_radius;
};

struct AreaViewParams : CommonViewParams
{
  dp::Color m_color;
};

struct LineViewParams : CommonViewParams
{
  dp::Color m_color;
  float m_width;
  dp::LineCap m_cap;
  dp::LineJoin m_join;
};

struct FontDecl
{
  dp::Color m_color;
  dp::Color m_outlineColor;
  float m_size;
  bool m_needOutline;
};

struct TextViewParams : CommonViewParams
{
  FeatureID m_featureID;
  FontDecl m_primaryTextFont;
  string m_primaryText;
  m2::PointF m_primaryOffset;
  FontDecl m_secondaryTextFont;
  string m_secondaryText;
  dp::Anchor m_anchor;
};

struct PathTextViewParams : CommonViewParams
{
  FeatureID m_featureID;
  FontDecl m_textFont;
  string m_text;
  float m_offsetStart;
  float m_offsetEnd;
};

struct PathSymbolViewParams : CommonViewParams
{
  FeatureID m_featureID;
  string m_symbolName;
  float m_offset;
  float m_step;
};

} // namespace df
