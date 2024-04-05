#pragma once

#include <QObject>

#include "cpp/dynamiccolor/dynamic_scheme.h"

class DynamicScheme : public QObject {
  Q_OBJECT

  Q_PROPERTY(bool isDark READ isDark WRITE setIsDark NOTIFY changed)
  Q_PROPERTY(Style style READ style WRITE setStyle NOTIFY changed)
  Q_PROPERTY(QString baseColor READ baseColor WRITE setBaseColor NOTIFY changed)

  Q_PROPERTY(QString backgroundColor READ backgroundColor NOTIFY changed)
  Q_PROPERTY(QString onBackgroundColor READ onBackgroundColor NOTIFY changed)
  Q_PROPERTY(QString primaryColor READ primaryColor NOTIFY changed)
  Q_PROPERTY(QString onPrimaryColor READ onPrimaryColor NOTIFY changed)
  Q_PROPERTY(QString secondaryColor READ secondaryColor NOTIFY changed)
  Q_PROPERTY(QString onSecondaryColor READ onSecondaryColor NOTIFY changed)
  Q_PROPERTY(QString tertiaryColor READ tertiaryColor NOTIFY changed)
  Q_PROPERTY(QString onTeritaryColor READ onTeritaryColor NOTIFY changed)
  Q_PROPERTY(QString errorColor READ errorColor NOTIFY changed)
  Q_PROPERTY(QString onErrorColor READ onErrorColor NOTIFY changed)
  Q_PROPERTY(
      QString primaryContainerColor READ primaryContainerColor NOTIFY changed)
  Q_PROPERTY(QString onPrimaryContainerColor READ onPrimaryContainerColor NOTIFY
                 changed)
  Q_PROPERTY(QString secondaryContainerColor READ secondaryContainerColor NOTIFY
                 changed)
  Q_PROPERTY(QString onSecondaryContainerColor READ onSecondaryContainerColor
                 NOTIFY changed)
  Q_PROPERTY(
      QString tertiaryContainerColor READ tertiaryContainerColor NOTIFY changed)
  Q_PROPERTY(QString onTertiaryContainerColor READ onTertiaryContainerColor
                 NOTIFY changed)
  Q_PROPERTY(
      QString errorContainerColor READ errorContainerColor NOTIFY changed)
  Q_PROPERTY(
      QString onErrorContainerColor READ onErrorContainerColor NOTIFY changed)

  Q_PROPERTY(QString primaryFixedColor READ primaryFixedColor NOTIFY changed)
  Q_PROPERTY(
      QString primaryFixedDimColor READ primaryFixedDimColor NOTIFY changed)
  Q_PROPERTY(
      QString onPrimaryFixedColor READ onPrimaryFixedColor NOTIFY changed)
  Q_PROPERTY(QString onPrimaryFixedVariantColor READ onPrimaryFixedVariantColor
                 NOTIFY changed)

  Q_PROPERTY(
      QString secondaryFixedColor READ secondaryFixedColor NOTIFY changed)
  Q_PROPERTY(
      QString secondaryFixedDimColor READ secondaryFixedDimColor NOTIFY changed)
  Q_PROPERTY(
      QString onSecondaryFixedColor READ onSecondaryFixedColor NOTIFY changed)
  Q_PROPERTY(QString onSecondaryFixedVariantColor READ
                 onSecondaryFixedVariantColor NOTIFY changed)

  Q_PROPERTY(QString tertiaryFixedColor READ tertiaryFixedColor NOTIFY changed)
  Q_PROPERTY(
      QString tertiaryFixedDimColor READ tertiaryFixedDimColor NOTIFY changed)
  Q_PROPERTY(
      QString onTertiaryFixedColor READ onTertiaryFixedColor NOTIFY changed)
  Q_PROPERTY(QString onTertiaryFixedVariantColor READ
                 onTertiaryFixedVariantColor NOTIFY changed)

  Q_PROPERTY(QString surfaceDimColor READ surfaceDimColor NOTIFY changed)
  Q_PROPERTY(QString surfaceColor READ surfaceColor NOTIFY changed)
  Q_PROPERTY(QString surfaceBrightColor READ surfaceBrightColor NOTIFY changed)

  Q_PROPERTY(QString surfaceContainerLowestColor READ
                 surfaceContainerLowestColor NOTIFY changed)
  Q_PROPERTY(QString surfaceContainerLowColor READ surfaceContainerLowColor
                 NOTIFY changed)
  Q_PROPERTY(
      QString surfaceContainerColor READ surfaceContainerColor NOTIFY changed)
  Q_PROPERTY(QString surfaceContainerHighColor READ surfaceContainerHighColor
                 NOTIFY changed)
  Q_PROPERTY(QString surfaceContainerHighestColor READ
                 surfaceContainerHighestColor NOTIFY changed)

  Q_PROPERTY(QString onSurfaceColor READ onSurfaceColor NOTIFY changed)
  Q_PROPERTY(
      QString onSurfaceVariantColor READ onSurfaceVariantColor NOTIFY changed)
  Q_PROPERTY(QString outlineColor READ outlineColor NOTIFY changed)
  Q_PROPERTY(
      QString outlineVariantColor READ outlineVariantColor NOTIFY changed)

  Q_PROPERTY(
      QString inverseSurfaceColor READ inverseSurfaceColor NOTIFY changed)
  Q_PROPERTY(
      QString inverseOnSurfaceColor READ inverseOnSurfaceColor NOTIFY changed)
  Q_PROPERTY(
      QString inversePrimaryColor READ inversePrimaryColor NOTIFY changed)

  Q_PROPERTY(QString scrimColor READ scrimColor NOTIFY changed)
  Q_PROPERTY(QString shadowColor READ shadowColor NOTIFY changed)

 public:
  enum Style {
    Vibrant,
    TonalSpot,
    Monochrome,
    Content,
    Expressive,
    Fidelity,
    FruitSalad,
    Neutral,
    Rainbow
  };

  Q_ENUM(Style)

  DynamicScheme(QObject* parent = nullptr);

  bool isDark() const;

  void setIsDark(bool b);

  Style style() const;

  void setStyle(Style s);

  QString baseColor() const;

  void setBaseColor(const QString& color);

  QString backgroundColor() const;
  QString onBackgroundColor() const;
  QString primaryColor() const;
  QString onPrimaryColor() const;
  QString secondaryColor() const;
  QString onSecondaryColor() const;
  QString tertiaryColor() const;
  QString onTeritaryColor() const;
  QString errorColor() const;
  QString onErrorColor() const;
  QString primaryContainerColor() const;
  QString onPrimaryContainerColor() const;
  QString secondaryContainerColor() const;
  QString onSecondaryContainerColor() const;
  QString tertiaryContainerColor() const;
  QString onTertiaryContainerColor() const;
  QString errorContainerColor() const;
  QString onErrorContainerColor() const;

  QString primaryFixedColor() const;
  QString primaryFixedDimColor() const;
  QString onPrimaryFixedColor() const;
  QString onPrimaryFixedVariantColor() const;

  QString secondaryFixedColor() const;
  QString secondaryFixedDimColor() const;
  QString onSecondaryFixedColor() const;
  QString onSecondaryFixedVariantColor() const;

  QString tertiaryFixedColor() const;
  QString tertiaryFixedDimColor() const;
  QString onTertiaryFixedColor() const;
  QString onTertiaryFixedVariantColor() const;

  QString surfaceDimColor() const;
  QString surfaceColor() const;
  QString surfaceBrightColor() const;

  QString surfaceContainerLowestColor() const;
  QString surfaceContainerLowColor() const;
  QString surfaceContainerColor() const;
  QString surfaceContainerHighColor() const;
  QString surfaceContainerHighestColor() const;

  QString onSurfaceColor() const;
  QString onSurfaceVariantColor() const;
  QString outlineColor() const;
  QString outlineVariantColor() const;

  QString inverseSurfaceColor() const;
  QString inverseOnSurfaceColor() const;
  QString inversePrimaryColor() const;

  QString scrimColor() const;
  QString shadowColor() const;

 signals:
  void changed();

 private:
  void update();

  void update(const QString& color, bool isDark, Style style);

  void update(const material_color_utilities::DynamicScheme& dynamic_scheme);

 private:
  QString m_baseColor;
  bool m_isDark{true};
  Style m_style;

  QString m_backgroundColor;
  QString m_onBackgroundColor;

  QString m_primaryColor;
  QString m_onPrimaryColor;

  QString m_secondaryColor;
  QString m_onSecondaryColor;

  QString m_tertiaryColor;
  QString m_onTeritaryColor;

  QString m_errorColor;
  QString m_onErrorColor;

  QString m_primaryContainerColor;
  QString m_onPrimaryContainerColor;

  QString m_secondaryContainerColor;
  QString m_onSecondaryContainerColor;

  QString m_tertiaryContainerColor;
  QString m_onTertiaryContainerColor;

  QString m_errorContainerColor;
  QString m_onErrorContainerColor;

  QString m_primaryFixedColor;
  QString m_primaryFixedDimColor;

  QString m_onPrimaryFixedColor;
  QString m_onPrimaryFixedVariantColor;

  QString m_secondaryFixedColor;
  QString m_secondaryFixedDimColor;

  QString m_onSecondaryFixedColor;
  QString m_onSecondaryFixedVariantColor;

  QString m_tertiaryFixedColor;
  QString m_tertiaryFixedDimColor;

  QString m_onTertiaryFixedColor;
  QString m_onTertiaryFixedVariantColor;

  QString m_surfaceDimColor;
  QString m_surfaceColor;
  QString m_surfaceBrightColor;

  QString m_surfaceContainerLowestColor;
  QString m_surfaceContainerLowColor;
  QString m_surfaceContainerColor;
  QString m_surfaceContainerHighColor;
  QString m_surfaceContainerHighestColor;

  QString m_onSurfaceColor;
  QString m_onSurfaceVariantColor;
  QString m_outlineColor;
  QString m_outlineVariantColor;

  QString m_inverseSurfaceColor;
  QString m_inverseOnSurfaceColor;
  QString m_inversePrimaryColor;

  QString m_scrimColor;
  QString m_shadowColor;
};