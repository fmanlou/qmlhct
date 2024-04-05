#include "qmlmaterialcolorutilities/DynamicScheme.h"

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

DynamicScheme::DynamicScheme(QObject* parent) : QObject(parent) {}

bool DynamicScheme::isDark() const { return m_isDark; }

void DynamicScheme::setIsDark(bool b) {
  if (m_isDark != b) {
    m_isDark = b;
    update();
    emit changed();
  }
}

DynamicScheme::Style DynamicScheme::style() const { return m_style; }

void DynamicScheme::setStyle(Style s) {
  if (m_style != s) {
    m_style = s;
    update();
    emit changed();
  }
}

QString DynamicScheme::baseColor() const { return m_baseColor; }

void DynamicScheme::setBaseColor(const QString& color) {
  if (m_baseColor != color) {
    m_baseColor = color;
    update();
    emit changed();
  }
}

QString DynamicScheme::backgroundColor() const { return m_backgroundColor; }
QString DynamicScheme::onBackgroundColor() const { return m_onBackgroundColor; }
QString DynamicScheme::primaryColor() const { return m_primaryColor; }
QString DynamicScheme::onPrimaryColor() const { return m_onPrimaryColor; }
QString DynamicScheme::secondaryColor() const { return m_secondaryColor; }
QString DynamicScheme::onSecondaryColor() const { return m_onSecondaryColor; }
QString DynamicScheme::tertiaryColor() const { return m_tertiaryColor; }
QString DynamicScheme::onTeritaryColor() const { return m_onTeritaryColor; }
QString DynamicScheme::errorColor() const { return m_errorColor; }
QString DynamicScheme::onErrorColor() const { return m_onErrorColor; }
QString DynamicScheme::primaryContainerColor() const {
  return m_primaryContainerColor;
}
QString DynamicScheme::onPrimaryContainerColor() const {
  return m_onPrimaryContainerColor;
}
QString DynamicScheme::secondaryContainerColor() const {
  return m_secondaryContainerColor;
}
QString DynamicScheme::onSecondaryContainerColor() const {
  return m_onSecondaryContainerColor;
}
QString DynamicScheme::tertiaryContainerColor() const {
  return m_tertiaryContainerColor;
}
QString DynamicScheme::onTertiaryContainerColor() const {
  return m_onTertiaryContainerColor;
}
QString DynamicScheme::errorContainerColor() const {
  return m_errorContainerColor;
}
QString DynamicScheme::onErrorContainerColor() const {
  return m_onErrorContainerColor;
}

QString DynamicScheme::primaryFixedColor() const { return m_primaryFixedColor; }
QString DynamicScheme::primaryFixedDimColor() const {
  return m_primaryFixedDimColor;
}
QString DynamicScheme::onPrimaryFixedColor() const {
  return m_onPrimaryFixedColor;
}
QString DynamicScheme::onPrimaryFixedVariantColor() const {
  return m_onPrimaryFixedVariantColor;
}

QString DynamicScheme::secondaryFixedColor() const {
  return m_secondaryFixedColor;
}
QString DynamicScheme::secondaryFixedDimColor() const {
  return m_secondaryFixedDimColor;
}
QString DynamicScheme::onSecondaryFixedColor() const {
  return m_onSecondaryFixedColor;
}
QString DynamicScheme::onSecondaryFixedVariantColor() const {
  return m_onSecondaryFixedVariantColor;
}

QString DynamicScheme::tertiaryFixedColor() const {
  return m_tertiaryFixedColor;
}
QString DynamicScheme::tertiaryFixedDimColor() const {
  return m_tertiaryFixedDimColor;
}
QString DynamicScheme::onTertiaryFixedColor() const {
  return m_onTertiaryFixedColor;
}
QString DynamicScheme::onTertiaryFixedVariantColor() const {
  return m_onTertiaryFixedVariantColor;
}

QString DynamicScheme::surfaceDimColor() const { return m_surfaceDimColor; }
QString DynamicScheme::surfaceColor() const { return m_surfaceColor; }
QString DynamicScheme::surfaceBrightColor() const {
  return m_surfaceBrightColor;
}

QString DynamicScheme::surfaceContainerLowestColor() const {
  return m_surfaceContainerLowestColor;
}
QString DynamicScheme::surfaceContainerLowColor() const {
  return m_surfaceContainerLowColor;
}
QString DynamicScheme::surfaceContainerColor() const {
  return m_surfaceContainerColor;
}
QString DynamicScheme::surfaceContainerHighColor() const {
  return m_surfaceContainerHighColor;
}
QString DynamicScheme::surfaceContainerHighestColor() const {
  return m_surfaceContainerHighestColor;
}

QString DynamicScheme::onSurfaceColor() const { return m_onSurfaceColor; }
QString DynamicScheme::onSurfaceVariantColor() const {
  return m_onSurfaceVariantColor;
}
QString DynamicScheme::outlineColor() const { return m_outlineColor; }
QString DynamicScheme::outlineVariantColor() const {
  return m_outlineVariantColor;
}

QString DynamicScheme::inverseSurfaceColor() const {
  return m_inverseSurfaceColor;
}
QString DynamicScheme::inverseOnSurfaceColor() const {
  return m_inverseOnSurfaceColor;
}
QString DynamicScheme::inversePrimaryColor() const {
  return m_inversePrimaryColor;
}

QString DynamicScheme::scrimColor() const { return m_scrimColor; }
QString DynamicScheme::shadowColor() const { return m_shadowColor; }

void DynamicScheme::update() { update(m_baseColor, m_isDark, m_style); }

void DynamicScheme::update(const QString& color, bool isDark, Style style) {
  QColor col(color);
  const auto& hct =
      material_color_utilities::Hct(material_color_utilities::ArgbFromRgb(
          col.red(), col.green(), col.blue()));
  const auto& generator = dynamicSchemeStyleFunction(style);
  const auto& dynamic_scheme = generator(hct, isDark);
  update(*dynamic_scheme);
}

void DynamicScheme::update(
    const material_color_utilities::DynamicScheme& dynamic_scheme) {
  m_backgroundColor = argbToRgbString(dynamic_scheme.GetBackground());
  m_onBackgroundColor = argbToRgbString(dynamic_scheme.GetOnBackground());

  m_primaryColor = argbToRgbString(dynamic_scheme.GetPrimary());
  m_onPrimaryColor = argbToRgbString(dynamic_scheme.GetOnPrimary());

  m_secondaryColor = argbToRgbString(dynamic_scheme.GetSecondary());
  m_onSecondaryColor = argbToRgbString(dynamic_scheme.GetOnSecondary());

  m_tertiaryColor = argbToRgbString(dynamic_scheme.GetTertiary());
  m_onTeritaryColor = argbToRgbString(dynamic_scheme.GetOnTertiary());

  m_errorColor = argbToRgbString(dynamic_scheme.GetError());
  m_onErrorColor = argbToRgbString(dynamic_scheme.GetOnError());

  m_primaryContainerColor =
      argbToRgbString(dynamic_scheme.GetPrimaryContainer());
  m_onPrimaryContainerColor =
      argbToRgbString(dynamic_scheme.GetOnPrimaryContainer());

  m_secondaryContainerColor =
      argbToRgbString(dynamic_scheme.GetSecondaryContainer());
  m_onSecondaryContainerColor =
      argbToRgbString(dynamic_scheme.GetOnSecondaryContainer());

  m_tertiaryContainerColor =
      argbToRgbString(dynamic_scheme.GetTertiaryContainer());
  m_onTertiaryContainerColor =
      argbToRgbString(dynamic_scheme.GetOnTertiaryContainer());

  m_errorContainerColor = argbToRgbString(dynamic_scheme.GetErrorContainer());
  m_onErrorContainerColor =
      argbToRgbString(dynamic_scheme.GetOnErrorContainer());

  m_primaryFixedColor = argbToRgbString(dynamic_scheme.GetPrimaryFixed());
  m_primaryFixedDimColor = argbToRgbString(dynamic_scheme.GetPrimaryFixedDim());

  m_onPrimaryFixedColor = argbToRgbString(dynamic_scheme.GetOnPrimaryFixed());
  m_onPrimaryFixedVariantColor =
      argbToRgbString(dynamic_scheme.GetOnPrimaryFixedVariant());

  m_secondaryFixedColor = argbToRgbString(dynamic_scheme.GetSecondaryFixed());
  m_secondaryFixedDimColor =
      argbToRgbString(dynamic_scheme.GetSecondaryFixedDim());

  m_onSecondaryFixedColor =
      argbToRgbString(dynamic_scheme.GetOnSecondaryFixed());
  m_onSecondaryFixedVariantColor =
      argbToRgbString(dynamic_scheme.GetOnSecondaryFixedVariant());

  m_tertiaryFixedColor = argbToRgbString(dynamic_scheme.GetTertiaryFixed());
  m_tertiaryFixedDimColor =
      argbToRgbString(dynamic_scheme.GetTertiaryFixedDim());

  m_onTertiaryFixedColor = argbToRgbString(dynamic_scheme.GetOnTertiaryFixed());
  m_onTertiaryFixedVariantColor =
      argbToRgbString(dynamic_scheme.GetOnTertiaryFixedVariant());

  m_surfaceDimColor = argbToRgbString(dynamic_scheme.GetSurfaceDim());
  m_surfaceColor = argbToRgbString(dynamic_scheme.GetSurface());
  m_surfaceBrightColor = argbToRgbString(dynamic_scheme.GetSurfaceBright());

  m_surfaceContainerLowestColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerLowest());
  m_surfaceContainerLowColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerLow());
  m_surfaceContainerColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainer());
  m_surfaceContainerHighColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerHigh());
  m_surfaceContainerHighestColor =
      argbToRgbString(dynamic_scheme.GetSurfaceContainerHighest());

  m_onSurfaceColor = argbToRgbString(dynamic_scheme.GetOnSurface());
  m_onSurfaceVariantColor =
      argbToRgbString(dynamic_scheme.GetOnSurfaceVariant());
  m_outlineColor = argbToRgbString(dynamic_scheme.GetOutline());
  m_outlineVariantColor = argbToRgbString(dynamic_scheme.GetOutlineVariant());

  m_inverseSurfaceColor = argbToRgbString(dynamic_scheme.GetInverseSurface());
  m_inverseOnSurfaceColor =
      argbToRgbString(dynamic_scheme.GetInverseOnSurface());
  m_inversePrimaryColor = argbToRgbString(dynamic_scheme.GetInversePrimary());

  m_scrimColor = argbToRgbString(dynamic_scheme.GetScrim());
  m_shadowColor = argbToRgbString(dynamic_scheme.GetShadow());
}