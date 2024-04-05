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
  d.backgroundColor = argbToRgbString(dynamic_scheme.GetBackground());
  d.onBackgroundColor = argbToRgbString(dynamic_scheme.GetOnBackground());

  d.primaryColor = argbToRgbString(dynamic_scheme.GetPrimary());
  d.onPrimaryColor = argbToRgbString(dynamic_scheme.GetOnPrimary());

  d.secondaryColor = argbToRgbString(dynamic_scheme.GetSecondary());
  d.onSecondaryColor = argbToRgbString(dynamic_scheme.GetOnSecondary());

  d.tertiaryColor = argbToRgbString(dynamic_scheme.GetTertiary());
  d.onTeritaryColor = argbToRgbString(dynamic_scheme.GetOnTertiary());

  d.errorColor = argbToRgbString(dynamic_scheme.GetError());
  d.onErrorColor = argbToRgbString(dynamic_scheme.GetOnError());

  d.primaryContainerColor =
      argbToRgbString(dynamic_scheme.GetPrimaryContainer());
  d.onPrimaryContainerColor =
      argbToRgbString(dynamic_scheme.GetOnPrimaryContainer());

  d.secondaryContainerColor =
      argbToRgbString(dynamic_scheme.GetSecondaryContainer());
  d.onSecondaryContainerColor =
      argbToRgbString(dynamic_scheme.GetOnSecondaryContainer());

  d.tertiaryContainerColor =
      argbToRgbString(dynamic_scheme.GetTertiaryContainer());
  d.onTertiaryContainerColor =
      argbToRgbString(dynamic_scheme.GetOnTertiaryContainer());

  d.errorContainerColor = argbToRgbString(dynamic_scheme.GetErrorContainer());
  d.onErrorContainerColor =
      argbToRgbString(dynamic_scheme.GetOnErrorContainer());

  d.primaryFixedColor = argbToRgbString(dynamic_scheme.GetPrimaryFixed());
  d.primaryFixedDimColor = argbToRgbString(dynamic_scheme.GetPrimaryFixedDim());

  d.onPrimaryFixedColor = argbToRgbString(dynamic_scheme.GetOnPrimaryFixed());
  d.onPrimaryFixedVariantColor =
      argbToRgbString(dynamic_scheme.GetOnPrimaryFixedVariant());

  d.secondaryFixedColor = argbToRgbString(dynamic_scheme.GetSecondaryFixed());
  d.secondaryFixedDimColor =
      argbToRgbString(dynamic_scheme.GetSecondaryFixedDim());

  d.onSecondaryFixedColor =
      argbToRgbString(dynamic_scheme.GetOnSecondaryFixed());
  d.onSecondaryFixedVariantColor =
      argbToRgbString(dynamic_scheme.GetOnSecondaryFixedVariant());

  d.tertiaryFixedColor = argbToRgbString(dynamic_scheme.GetTertiaryFixed());
  d.tertiaryFixedDimColor =
      argbToRgbString(dynamic_scheme.GetTertiaryFixedDim());

  d.onTertiaryFixedColor = argbToRgbString(dynamic_scheme.GetOnTertiaryFixed());
  d.onTertiaryFixedVariantColor =
      argbToRgbString(dynamic_scheme.GetOnTertiaryFixedVariant());

  d.surfaceDimColor = argbToRgbString(dynamic_scheme.GetSurfaceDim());
  d.surfaceColor = argbToRgbString(dynamic_scheme.GetSurface());
  d.surfaceBrightColor = argbToRgbString(dynamic_scheme.GetSurfaceBright());

  d.surfaceContainerLowestColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerLowest());
  d.surfaceContainerLowColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerLow());
  d.surfaceContainerColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainer());
  d.surfaceContainerHighColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerHigh());
  d.surfaceContainerHighestColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerHighest());

  d.onSurfaceColor = argbToRgbString(dynamic_scheme.GetOnSurface());
  d.onSurfaceVariantColor =
      argbToRgbString(dynamic_scheme.GetOnSurfaceVariant());
  d.outlineColor = argbToRgbString(dynamic_scheme.GetOutline());
  d.outlineVariantColor = argbToRgbString(dynamic_scheme.GetOutlineVariant());

  d.inverseSurfaceColor = argbToRgbString(dynamic_scheme.GetInverseSurface());
  d.inverseOnSurfaceColor =
      argbToRgbString(dynamic_scheme.GetInverseOnSurface());
  d.inversePrimaryColor = argbToRgbString(dynamic_scheme.GetInversePrimary());

  d.scrimColor = argbToRgbString(dynamic_scheme.GetScrim());
  d.shadowColor = argbToRgbString(dynamic_scheme.GetShadow());
}