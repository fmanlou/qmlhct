#pragma once

#include <QObject>

class DynamicSchemeImpl;

class DynamicScheme : public QObject {
  Q_OBJECT

  Q_PROPERTY(bool isDark READ isDark WRITE setIsDark NOTIFY isDarkChanged)
  Q_PROPERTY(Style style READ style WRITE setStyle NOTIFY styleChanged)
  Q_PROPERTY(QString baseColor READ baseColor WRITE setBaseColor NOTIFY
                 baseColorChanged)

  Q_PROPERTY(QString background READ background NOTIFY changed)
  Q_PROPERTY(QString onBackground READ onBackground NOTIFY changed)
  Q_PROPERTY(QString primary READ primary NOTIFY changed)
  Q_PROPERTY(QString onPrimary READ onPrimary NOTIFY changed)
  Q_PROPERTY(QString secondary READ secondary NOTIFY changed)
  Q_PROPERTY(QString onSecondary READ onSecondary NOTIFY changed)
  Q_PROPERTY(QString tertiary READ tertiary NOTIFY changed)
  Q_PROPERTY(QString onTeritary READ onTeritary NOTIFY changed)
  Q_PROPERTY(QString error READ error NOTIFY changed)
  Q_PROPERTY(QString onError READ onError NOTIFY changed)
  Q_PROPERTY(QString primaryContainer READ primaryContainer NOTIFY changed)
  Q_PROPERTY(QString onPrimaryContainer READ onPrimaryContainer NOTIFY changed)
  Q_PROPERTY(QString secondaryContainer READ secondaryContainer NOTIFY changed)
  Q_PROPERTY(
      QString onSecondaryContainer READ onSecondaryContainer NOTIFY changed)
  Q_PROPERTY(QString tertiaryContainer READ tertiaryContainer NOTIFY changed)
  Q_PROPERTY(
      QString onTertiaryContainer READ onTertiaryContainer NOTIFY changed)
  Q_PROPERTY(QString errorContainer READ errorContainer NOTIFY changed)
  Q_PROPERTY(QString onErrorContainer READ onErrorContainer NOTIFY changed)

  Q_PROPERTY(QString primaryFixed READ primaryFixed NOTIFY changed)
  Q_PROPERTY(QString primaryFixedDim READ primaryFixedDim NOTIFY changed)
  Q_PROPERTY(QString onPrimaryFixed READ onPrimaryFixed NOTIFY changed)
  Q_PROPERTY(
      QString onPrimaryFixedVariant READ onPrimaryFixedVariant NOTIFY changed)

  Q_PROPERTY(QString secondaryFixed READ secondaryFixed NOTIFY changed)
  Q_PROPERTY(QString secondaryFixedDim READ secondaryFixedDim NOTIFY changed)
  Q_PROPERTY(QString onSecondaryFixed READ onSecondaryFixed NOTIFY changed)
  Q_PROPERTY(QString onSecondaryFixedVariant READ onSecondaryFixedVariant NOTIFY
                 changed)

  Q_PROPERTY(QString tertiaryFixed READ tertiaryFixed NOTIFY changed)
  Q_PROPERTY(QString tertiaryFixedDim READ tertiaryFixedDim NOTIFY changed)
  Q_PROPERTY(QString onTertiaryFixed READ onTertiaryFixed NOTIFY changed)
  Q_PROPERTY(
      QString onTertiaryFixedVariant READ onTertiaryFixedVariant NOTIFY changed)

  Q_PROPERTY(QString surfaceDim READ surfaceDim NOTIFY changed)
  Q_PROPERTY(QString surface READ surface NOTIFY changed)
  Q_PROPERTY(QString surfaceBright READ surfaceBright NOTIFY changed)

  Q_PROPERTY(
      QString surfaceContainerLowest READ surfaceContainerLowest NOTIFY changed)
  Q_PROPERTY(
      QString surfaceContainerLow READ surfaceContainerLow NOTIFY changed)
  Q_PROPERTY(QString surfaceContainer READ surfaceContainer NOTIFY changed)
  Q_PROPERTY(
      QString surfaceContainerHigh READ surfaceContainerHigh NOTIFY changed)
  Q_PROPERTY(QString surfaceContainerHighest READ surfaceContainerHighest NOTIFY
                 changed)

  Q_PROPERTY(QString onSurface READ onSurface NOTIFY changed)
  Q_PROPERTY(QString onSurfaceVariant READ onSurfaceVariant NOTIFY changed)
  Q_PROPERTY(QString outline READ outline NOTIFY changed)
  Q_PROPERTY(QString outlineVariant READ outlineVariant NOTIFY changed)

  Q_PROPERTY(QString inverseSurface READ inverseSurface NOTIFY changed)
  Q_PROPERTY(QString inverseOnSurface READ inverseOnSurface NOTIFY changed)
  Q_PROPERTY(QString inversePrimary READ inversePrimary NOTIFY changed)

  Q_PROPERTY(QString scrim READ scrim NOTIFY changed)
  Q_PROPERTY(QString shadow READ shadow NOTIFY changed)

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

  explicit DynamicScheme(QObject* parent = nullptr);

  ~DynamicScheme();

  bool isDark() const;

  void setIsDark(bool b);

  Style style() const;

  void setStyle(Style s);

  QString baseColor() const;

  void setBaseColor(const QString& color);

  QString background() const;
  QString onBackground() const;
  QString primary() const;
  QString onPrimary() const;
  QString secondary() const;
  QString onSecondary() const;
  QString tertiary() const;
  QString onTeritary() const;
  QString error() const;
  QString onError() const;
  QString primaryContainer() const;
  QString onPrimaryContainer() const;
  QString secondaryContainer() const;
  QString onSecondaryContainer() const;
  QString tertiaryContainer() const;
  QString onTertiaryContainer() const;
  QString errorContainer() const;
  QString onErrorContainer() const;

  QString primaryFixed() const;
  QString primaryFixedDim() const;
  QString onPrimaryFixed() const;
  QString onPrimaryFixedVariant() const;

  QString secondaryFixed() const;
  QString secondaryFixedDim() const;
  QString onSecondaryFixed() const;
  QString onSecondaryFixedVariant() const;

  QString tertiaryFixed() const;
  QString tertiaryFixedDim() const;
  QString onTertiaryFixed() const;
  QString onTertiaryFixedVariant() const;

  QString surfaceDim() const;
  QString surface() const;
  QString surfaceBright() const;

  QString surfaceContainerLowest() const;
  QString surfaceContainerLow() const;
  QString surfaceContainer() const;
  QString surfaceContainerHigh() const;
  QString surfaceContainerHighest() const;

  QString onSurface() const;
  QString onSurfaceVariant() const;
  QString outline() const;
  QString outlineVariant() const;

  QString inverseSurface() const;
  QString inverseOnSurface() const;
  QString inversePrimary() const;

  QString scrim() const;
  QString shadow() const;

 signals:
  void isDarkChanged();
  void styleChanged();
  void baseColorChanged();
  void changed();

 private:
  DynamicSchemeImpl* impl;
};