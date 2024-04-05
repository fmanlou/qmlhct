#pragma once

#include <QString>

#include "cpp/dynamiccolor/dynamic_scheme.h"
#include "qmlmaterialcolorutilities/DynamicScheme.h"

struct DynamicSchemeData {
  QString baseColor;
  bool isDark{false};
  DynamicScheme::Style style;

  QString backgroundColor;
  QString onBackgroundColor;

  QString primaryColor;
  QString onPrimaryColor;

  QString secondaryColor;
  QString onSecondaryColor;

  QString tertiaryColor;
  QString onTeritaryColor;

  QString errorColor;
  QString onErrorColor;

  QString primaryContainerColor;
  QString onPrimaryContainerColor;

  QString secondaryContainerColor;
  QString onSecondaryContainerColor;

  QString tertiaryContainerColor;
  QString onTertiaryContainerColor;

  QString errorContainerColor;
  QString onErrorContainerColor;

  QString primaryFixedColor;
  QString primaryFixedDimColor;

  QString onPrimaryFixedColor;
  QString onPrimaryFixedVariantColor;

  QString secondaryFixedColor;
  QString secondaryFixedDimColor;

  QString onSecondaryFixedColor;
  QString onSecondaryFixedVariantColor;

  QString tertiaryFixedColor;
  QString tertiaryFixedDimColor;

  QString onTertiaryFixedColor;
  QString onTertiaryFixedVariantColor;

  QString surfaceDimColor;
  QString surfaceColor;
  QString surfaceBrightColor;

  QString surfaceContainerLowestColor;
  QString surfaceContainerLowColor;
  QString surfaceContainerColor;
  QString surfaceContainerHighColor;
  QString surfaceContainerHighestColor;

  QString onSurfaceColor;
  QString onSurfaceVariantColor;
  QString outlineColor;
  QString outlineVariantColor;

  QString inverseSurfaceColor;
  QString inverseOnSurfaceColor;
  QString inversePrimaryColor;

  QString scrimColor;
  QString shadowColor;
};

struct DynamicSchemeImpl {
  void update();

  void update(const QString& color, bool isDark, DynamicScheme::Style style);

  void update(const material_color_utilities::DynamicScheme& dynamic_scheme);

  DynamicSchemeData d;
};