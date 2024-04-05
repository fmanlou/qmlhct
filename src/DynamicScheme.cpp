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

QString DynamicScheme::backgroundColor() const {
  return impl->d.backgroundColor;
}
QString DynamicScheme::onBackgroundColor() const {
  return impl->d.onBackgroundColor;
}
QString DynamicScheme::primaryColor() const { return impl->d.primaryColor; }
QString DynamicScheme::onPrimaryColor() const { return impl->d.onPrimaryColor; }
QString DynamicScheme::secondaryColor() const { return impl->d.secondaryColor; }
QString DynamicScheme::onSecondaryColor() const {
  return impl->d.onSecondaryColor;
}
QString DynamicScheme::tertiaryColor() const { return impl->d.tertiaryColor; }
QString DynamicScheme::onTeritaryColor() const {
  return impl->d.onTeritaryColor;
}
QString DynamicScheme::errorColor() const { return impl->d.errorColor; }
QString DynamicScheme::onErrorColor() const { return impl->d.onErrorColor; }
QString DynamicScheme::primaryContainerColor() const {
  return impl->d.primaryContainerColor;
}
QString DynamicScheme::onPrimaryContainerColor() const {
  return impl->d.onPrimaryContainerColor;
}
QString DynamicScheme::secondaryContainerColor() const {
  return impl->d.secondaryContainerColor;
}
QString DynamicScheme::onSecondaryContainerColor() const {
  return impl->d.onSecondaryContainerColor;
}
QString DynamicScheme::tertiaryContainerColor() const {
  return impl->d.tertiaryContainerColor;
}
QString DynamicScheme::onTertiaryContainerColor() const {
  return impl->d.onTertiaryContainerColor;
}
QString DynamicScheme::errorContainerColor() const {
  return impl->d.errorContainerColor;
}
QString DynamicScheme::onErrorContainerColor() const {
  return impl->d.onErrorContainerColor;
}

QString DynamicScheme::primaryFixedColor() const {
  return impl->d.primaryFixedColor;
}
QString DynamicScheme::primaryFixedDimColor() const {
  return impl->d.primaryFixedDimColor;
}
QString DynamicScheme::onPrimaryFixedColor() const {
  return impl->d.onPrimaryFixedColor;
}
QString DynamicScheme::onPrimaryFixedVariantColor() const {
  return impl->d.onPrimaryFixedVariantColor;
}

QString DynamicScheme::secondaryFixedColor() const {
  return impl->d.secondaryFixedColor;
}
QString DynamicScheme::secondaryFixedDimColor() const {
  return impl->d.secondaryFixedDimColor;
}
QString DynamicScheme::onSecondaryFixedColor() const {
  return impl->d.onSecondaryFixedColor;
}
QString DynamicScheme::onSecondaryFixedVariantColor() const {
  return impl->d.onSecondaryFixedVariantColor;
}

QString DynamicScheme::tertiaryFixedColor() const {
  return impl->d.tertiaryFixedColor;
}
QString DynamicScheme::tertiaryFixedDimColor() const {
  return impl->d.tertiaryFixedDimColor;
}
QString DynamicScheme::onTertiaryFixedColor() const {
  return impl->d.onTertiaryFixedColor;
}
QString DynamicScheme::onTertiaryFixedVariantColor() const {
  return impl->d.onTertiaryFixedVariantColor;
}

QString DynamicScheme::surfaceDimColor() const {
  return impl->d.surfaceDimColor;
}
QString DynamicScheme::surfaceColor() const { return impl->d.surfaceColor; }
QString DynamicScheme::surfaceBrightColor() const {
  return impl->d.surfaceBrightColor;
}

QString DynamicScheme::surfaceContainerLowestColor() const {
  return impl->d.surfaceContainerLowestColor;
}
QString DynamicScheme::surfaceContainerLowColor() const {
  return impl->d.surfaceContainerLowColor;
}
QString DynamicScheme::surfaceContainerColor() const {
  return impl->d.surfaceContainerColor;
}
QString DynamicScheme::surfaceContainerHighColor() const {
  return impl->d.surfaceContainerHighColor;
}
QString DynamicScheme::surfaceContainerHighestColor() const {
  return impl->d.surfaceContainerHighestColor;
}

QString DynamicScheme::onSurfaceColor() const { return impl->d.onSurfaceColor; }
QString DynamicScheme::onSurfaceVariantColor() const {
  return impl->d.onSurfaceVariantColor;
}
QString DynamicScheme::outlineColor() const { return impl->d.outlineColor; }
QString DynamicScheme::outlineVariantColor() const {
  return impl->d.outlineVariantColor;
}

QString DynamicScheme::inverseSurfaceColor() const {
  return impl->d.inverseSurfaceColor;
}
QString DynamicScheme::inverseOnSurfaceColor() const {
  return impl->d.inverseOnSurfaceColor;
}
QString DynamicScheme::inversePrimaryColor() const {
  return impl->d.inversePrimaryColor;
}

QString DynamicScheme::scrimColor() const { return impl->d.scrimColor; }
QString DynamicScheme::shadowColor() const { return impl->d.shadowColor; }
