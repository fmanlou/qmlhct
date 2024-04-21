#include "DynamicSchemeImpl.h"

#include <QColor>

#include "cpp/scheme/scheme_content.h"
#include "cpp/scheme/scheme_expressive.h"
#include "cpp/scheme/scheme_fidelity.h"
#include "cpp/scheme/scheme_fruit_salad.h"
#include "cpp/scheme/scheme_monochrome.h"
#include "cpp/scheme/scheme_neutral.h"
#include "cpp/scheme/scheme_rainbow.h"
#include "cpp/scheme/scheme_tonal_spot.h"
#include "cpp/scheme/scheme_vibrant.h"
#include "qmlmaterialcolorutilities/Hct.h"

typedef std::function<std::unique_ptr<material_color_utilities::DynamicScheme>(
    const material_color_utilities::Hct& hct, bool light)>
    DynamicSchemeGenerator;

const DynamicSchemeGenerator VibrantSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeVibrant(hct, light));
    };

const DynamicSchemeGenerator TonalSpotSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeTonalSpot(hct, light));
    };

const DynamicSchemeGenerator MonochromeSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeMonochrome(hct, light));
    };

const DynamicSchemeGenerator ContentSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeContent(hct, light));
    };

const DynamicSchemeGenerator ExpressiveSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeExpressive(hct, light));
    };

const DynamicSchemeGenerator FidelitySchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeFidelity(hct, light));
    };

const DynamicSchemeGenerator FruitSaladSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeFruitSalad(hct, light));
    };

const DynamicSchemeGenerator NeutralSaladSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeNeutral(hct, light));
    };

const DynamicSchemeGenerator RainbowSaladSchemeGenerator =
    [](const material_color_utilities::Hct& hct, bool light) {
      return std::unique_ptr<material_color_utilities::DynamicScheme>(
          new material_color_utilities::SchemeRainbow(hct, light));
    };

DynamicSchemeGenerator dynamicSchemeStyleFunction(DynamicScheme::Style style) {
  switch (style) {
    case DynamicScheme::Vibrant:
      return VibrantSchemeGenerator;
    case DynamicScheme::TonalSpot:
      return TonalSpotSchemeGenerator;
    case DynamicScheme::Monochrome:
      return MonochromeSchemeGenerator;
    case DynamicScheme::Content:
      return ContentSchemeGenerator;
    case DynamicScheme::Expressive:
      return ExpressiveSchemeGenerator;
    case DynamicScheme::Fidelity:
      return FidelitySchemeGenerator;
    case DynamicScheme::FruitSalad:
      return FruitSaladSchemeGenerator;
    case DynamicScheme::Neutral:
      return NeutralSaladSchemeGenerator;
    case DynamicScheme::Rainbow:
      return RainbowSaladSchemeGenerator;
  }

  return VibrantSchemeGenerator;
}

void DynamicSchemeImpl::update() { update(d.baseColor, d.isDark, d.style); }

void DynamicSchemeImpl::update(const QString& color, bool isDark,
                               DynamicScheme::Style style) {
  QColor col(color);
  const auto& hct =
      material_color_utilities::Hct(material_color_utilities::ArgbFromRgb(
          col.red(), col.green(), col.blue()));
  const auto& generator = dynamicSchemeStyleFunction(style);
  const auto& dynamic_scheme = generator(hct, isDark);
  update(*dynamic_scheme);
}

void DynamicSchemeImpl::update(
    const material_color_utilities::DynamicScheme& dynamic_scheme) {
  d.background = argbToRgbString(dynamic_scheme.GetBackground());
  d.onBackground = argbToRgbString(dynamic_scheme.GetOnBackground());

  d.primary = argbToRgbString(dynamic_scheme.GetPrimary());
  d.onPrimary = argbToRgbString(dynamic_scheme.GetOnPrimary());

  d.secondary = argbToRgbString(dynamic_scheme.GetSecondary());
  d.onSecondary = argbToRgbString(dynamic_scheme.GetOnSecondary());

  d.tertiary = argbToRgbString(dynamic_scheme.GetTertiary());
  d.onTeritary = argbToRgbString(dynamic_scheme.GetOnTertiary());

  d.error = argbToRgbString(dynamic_scheme.GetError());
  d.onError = argbToRgbString(dynamic_scheme.GetOnError());

  d.primaryContainer = argbToRgbString(dynamic_scheme.GetPrimaryContainer());
  d.onPrimaryContainer =
      argbToRgbString(dynamic_scheme.GetOnPrimaryContainer());

  d.secondaryContainer =
      argbToRgbString(dynamic_scheme.GetSecondaryContainer());
  d.onSecondaryContainer =
      argbToRgbString(dynamic_scheme.GetOnSecondaryContainer());

  d.tertiaryContainer = argbToRgbString(dynamic_scheme.GetTertiaryContainer());
  d.onTertiaryContainer =
      argbToRgbString(dynamic_scheme.GetOnTertiaryContainer());

  d.errorContainer = argbToRgbString(dynamic_scheme.GetErrorContainer());
  d.onErrorContainer = argbToRgbString(dynamic_scheme.GetOnErrorContainer());

  d.primaryFixed = argbToRgbString(dynamic_scheme.GetPrimaryFixed());
  d.primaryFixedDim = argbToRgbString(dynamic_scheme.GetPrimaryFixedDim());

  d.onPrimaryFixed = argbToRgbString(dynamic_scheme.GetOnPrimaryFixed());
  d.onPrimaryFixedVariant =
      argbToRgbString(dynamic_scheme.GetOnPrimaryFixedVariant());

  d.secondaryFixed = argbToRgbString(dynamic_scheme.GetSecondaryFixed());
  d.secondaryFixedDim = argbToRgbString(dynamic_scheme.GetSecondaryFixedDim());

  d.onSecondaryFixed = argbToRgbString(dynamic_scheme.GetOnSecondaryFixed());
  d.onSecondaryFixedVariant =
      argbToRgbString(dynamic_scheme.GetOnSecondaryFixedVariant());

  d.tertiaryFixed = argbToRgbString(dynamic_scheme.GetTertiaryFixed());
  d.tertiaryFixedDim = argbToRgbString(dynamic_scheme.GetTertiaryFixedDim());

  d.onTertiaryFixed = argbToRgbString(dynamic_scheme.GetOnTertiaryFixed());
  d.onTertiaryFixedVariant =
      argbToRgbString(dynamic_scheme.GetOnTertiaryFixedVariant());

  d.surfaceDim = argbToRgbString(dynamic_scheme.GetSurfaceDim());
  d.surface = argbToRgbString(dynamic_scheme.GetSurface());
  d.surfaceBright = argbToRgbString(dynamic_scheme.GetSurfaceBright());

  d.surfaceContainerLowest =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerLowest());
  d.surfaceContainerLow =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerLow());
  d.surfaceContainer = argbToRgbString(dynamic_scheme.GetSurfaceContainer());
  d.surfaceContainerHigh =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerHigh());
  d.surfaceContainerHighest =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerHighest());

  d.onSurface = argbToRgbString(dynamic_scheme.GetOnSurface());
  d.onSurfaceVariant = argbToRgbString(dynamic_scheme.GetOnSurfaceVariant());
  d.outline = argbToRgbString(dynamic_scheme.GetOutline());
  d.outlineVariant = argbToRgbString(dynamic_scheme.GetOutlineVariant());

  d.inverseSurface = argbToRgbString(dynamic_scheme.GetInverseSurface());
  d.inverseOnSurface = argbToRgbString(dynamic_scheme.GetInverseOnSurface());
  d.inversePrimary = argbToRgbString(dynamic_scheme.GetInversePrimary());

  d.scrim = argbToRgbString(dynamic_scheme.GetScrim());
  d.shadow = argbToRgbString(dynamic_scheme.GetShadow());
}