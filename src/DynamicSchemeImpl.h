#pragma once

#include <QString>

#include "cpp/dynamiccolor/dynamic_scheme.h"
#include "qmlmaterialcolorutilities/DynamicScheme.h"

struct DynamicSchemeData {
  QString baseColor;
  bool isDark{false};
  DynamicScheme::Style style;

  QString background;
  QString onBackground;

  QString primary;
  QString onPrimary;

  QString secondary;
  QString onSecondary;

  QString tertiary;
  QString onTeritary;

  QString error;
  QString onError;

  QString primaryContainer;
  QString onPrimaryContainer;

  QString secondaryContainer;
  QString onSecondaryContainer;

  QString tertiaryContainer;
  QString onTertiaryContainer;

  QString errorContainer;
  QString onErrorContainer;

  QString primaryFixed;
  QString primaryFixedDim;

  QString onPrimaryFixed;
  QString onPrimaryFixedVariant;

  QString secondaryFixed;
  QString secondaryFixedDim;

  QString onSecondaryFixed;
  QString onSecondaryFixedVariant;

  QString tertiaryFixed;
  QString tertiaryFixedDim;

  QString onTertiaryFixed;
  QString onTertiaryFixedVariant;

  QString surfaceDim;
  QString surface;
  QString surfaceBright;

  QString surfaceContainerLowest;
  QString surfaceContainerLow;
  QString surfaceContainer;
  QString surfaceContainerHigh;
  QString surfaceContainerHighest;

  QString onSurface;
  QString onSurfaceVariant;
  QString outline;
  QString outlineVariant;

  QString inverseSurface;
  QString inverseOnSurface;
  QString inversePrimary;

  QString scrim;
  QString shadow;
};

struct DynamicSchemeImpl {
  void update();

  void update(const QString& color, bool isDark, DynamicScheme::Style style);

  void update(const material_color_utilities::DynamicScheme& dynamic_scheme);

  DynamicSchemeData d;
};