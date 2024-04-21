#include "qmlmaterialcolorutilities/DynamicScheme.h"

#include "DynamicSchemeImpl.h"

DynamicScheme::DynamicScheme(QObject* parent) : QObject(parent) {
  impl = new DynamicSchemeImpl();
}

DynamicScheme::~DynamicScheme() { delete impl; }

bool DynamicScheme::isDark() const { return impl->d.isDark; }

void DynamicScheme::setIsDark(bool b) {
  if (impl->d.isDark != b) {
    impl->d.isDark = b;
    impl->update();
    emit isDarkChanged();
    emit changed();
  }
}

DynamicScheme::Style DynamicScheme::style() const { return impl->d.style; }

void DynamicScheme::setStyle(Style s) {
  if (impl->d.style != s) {
    impl->d.style = s;
    impl->update();
    emit styleChanged();
    emit changed();
  }
}

QString DynamicScheme::baseColor() const { return impl->d.baseColor; }

void DynamicScheme::setBaseColor(const QString& color) {
  if (impl->d.baseColor != color) {
    impl->d.baseColor = color;
    impl->update();
    emit baseColorChanged();
    emit changed();
  }
}

QString DynamicScheme::background() const { return impl->d.background; }
QString DynamicScheme::onBackground() const { return impl->d.onBackground; }
QString DynamicScheme::primary() const { return impl->d.primary; }
QString DynamicScheme::onPrimary() const { return impl->d.onPrimary; }
QString DynamicScheme::secondary() const { return impl->d.secondary; }
QString DynamicScheme::onSecondary() const { return impl->d.onSecondary; }
QString DynamicScheme::tertiary() const { return impl->d.tertiary; }
QString DynamicScheme::onTeritary() const { return impl->d.onTeritary; }
QString DynamicScheme::error() const { return impl->d.error; }
QString DynamicScheme::onError() const { return impl->d.onError; }
QString DynamicScheme::primaryContainer() const {
  return impl->d.primaryContainer;
}
QString DynamicScheme::onPrimaryContainer() const {
  return impl->d.onPrimaryContainer;
}
QString DynamicScheme::secondaryContainer() const {
  return impl->d.secondaryContainer;
}
QString DynamicScheme::onSecondaryContainer() const {
  return impl->d.onSecondaryContainer;
}
QString DynamicScheme::tertiaryContainer() const {
  return impl->d.tertiaryContainer;
}
QString DynamicScheme::onTertiaryContainer() const {
  return impl->d.onTertiaryContainer;
}
QString DynamicScheme::errorContainer() const { return impl->d.errorContainer; }
QString DynamicScheme::onErrorContainer() const {
  return impl->d.onErrorContainer;
}

QString DynamicScheme::primaryFixed() const { return impl->d.primaryFixed; }
QString DynamicScheme::primaryFixedDim() const {
  return impl->d.primaryFixedDim;
}
QString DynamicScheme::onPrimaryFixed() const { return impl->d.onPrimaryFixed; }
QString DynamicScheme::onPrimaryFixedVariant() const {
  return impl->d.onPrimaryFixedVariant;
}

QString DynamicScheme::secondaryFixed() const { return impl->d.secondaryFixed; }
QString DynamicScheme::secondaryFixedDim() const {
  return impl->d.secondaryFixedDim;
}
QString DynamicScheme::onSecondaryFixed() const {
  return impl->d.onSecondaryFixed;
}
QString DynamicScheme::onSecondaryFixedVariant() const {
  return impl->d.onSecondaryFixedVariant;
}

QString DynamicScheme::tertiaryFixed() const { return impl->d.tertiaryFixed; }
QString DynamicScheme::tertiaryFixedDim() const {
  return impl->d.tertiaryFixedDim;
}
QString DynamicScheme::onTertiaryFixed() const {
  return impl->d.onTertiaryFixed;
}
QString DynamicScheme::onTertiaryFixedVariant() const {
  return impl->d.onTertiaryFixedVariant;
}

QString DynamicScheme::surfaceDim() const { return impl->d.surfaceDim; }
QString DynamicScheme::surface() const { return impl->d.surface; }
QString DynamicScheme::surfaceBright() const { return impl->d.surfaceBright; }

QString DynamicScheme::surfaceContainerLowest() const {
  return impl->d.surfaceContainerLowest;
}
QString DynamicScheme::surfaceContainerLow() const {
  return impl->d.surfaceContainerLow;
}
QString DynamicScheme::surfaceContainer() const {
  return impl->d.surfaceContainer;
}
QString DynamicScheme::surfaceContainerHigh() const {
  return impl->d.surfaceContainerHigh;
}
QString DynamicScheme::surfaceContainerHighest() const {
  return impl->d.surfaceContainerHighest;
}

QString DynamicScheme::onSurface() const { return impl->d.onSurface; }
QString DynamicScheme::onSurfaceVariant() const {
  return impl->d.onSurfaceVariant;
}
QString DynamicScheme::outline() const { return impl->d.outline; }
QString DynamicScheme::outlineVariant() const { return impl->d.outlineVariant; }

QString DynamicScheme::inverseSurface() const { return impl->d.inverseSurface; }
QString DynamicScheme::inverseOnSurface() const {
  return impl->d.inverseOnSurface;
}
QString DynamicScheme::inversePrimary() const { return impl->d.inversePrimary; }

QString DynamicScheme::scrim() const { return impl->d.scrim; }
QString DynamicScheme::shadow() const { return impl->d.shadow; }
