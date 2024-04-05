#include <QColor>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <memory>

#include "cpp/cam/hct.h"
#include "cpp/scheme/scheme_content.h"
#include "cpp/scheme/scheme_expressive.h"
#include "cpp/scheme/scheme_fidelity.h"
#include "cpp/scheme/scheme_fruit_salad.h"
#include "cpp/scheme/scheme_monochrome.h"
#include "cpp/scheme/scheme_neutral.h"
#include "cpp/scheme/scheme_rainbow.h"
#include "cpp/scheme/scheme_tonal_spot.h"
#include "cpp/scheme/scheme_vibrant.h"
#include "cpp/utils/utils.h"

class Hct : public QObject {
  Q_OBJECT

  Q_PROPERTY(int h READ h WRITE setH NOTIFY hChanged)
  Q_PROPERTY(int c READ c WRITE setC NOTIFY cChanged)
  Q_PROPERTY(int t READ t WRITE setT NOTIFY tChanged)
  Q_PROPERTY(QString rgb READ rgb NOTIFY rgbChanged)

 public:
  Hct(QObject* parent = nullptr) : QObject(parent) {
    connect(this, &Hct::hChanged, this, &Hct::rgbChanged);
    connect(this, &Hct::cChanged, this, &Hct::rgbChanged);
    connect(this, &Hct::tChanged, this, &Hct::rgbChanged);
  }

  int h() const { return hue; }
  void setH(int h) {
    if (h != hue) {
      hue = h;
      emit hChanged();
    }
  }

  int c() const { return chroma; }
  void setC(int c) {
    if (c != chroma) {
      chroma = c;
      emit cChanged();
    }
  }

  int t() const { return tone; }
  void setT(int t) {
    if (t != tone) {
      tone = t;
      emit tChanged();
    }
  }

  QString rgb() const { return hctToRgbString(hue, chroma, tone); }

  static QString hctToRgbString(double h, double c, double t) {
    material_color_utilities::Hct d{h, c, t};
    return argbToRgbString(d.ToInt());
  }

  static QString argbToRgbString(material_color_utilities::Argb argb) {
    return "#" +
           QString::fromStdString(material_color_utilities::HexFromArgb(argb))
               .remove(0, 2);
  }

 signals:
  void hChanged();
  void cChanged();
  void tChanged();
  void rgbChanged();

 private:
  int hue;
  int chroma;
  int tone;
};

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

  DynamicScheme(QObject* parent = nullptr) : QObject(parent) {}

  bool isDark() const { return m_isDark; }

  void setIsDark(bool b) {
    if (m_isDark != b) {
      m_isDark = b;
      update();
      emit changed();
    }
  }

  Style style() const { return m_style; }

  void setStyle(Style s) {
    if (m_style != s) {
      m_style = s;
      update();
      emit changed();
    }
  }

  QString baseColor() const { return m_baseColor; }

  void setBaseColor(const QString& color) {
    if (m_baseColor != color) {
      m_baseColor = color;
      update();
      emit changed();
    }
  }

  QString backgroundColor() const { return m_backgroundColor; }
  QString onBackgroundColor() const { return m_onBackgroundColor; }
  QString primaryColor() const { return m_primaryColor; }
  QString onPrimaryColor() const { return m_onPrimaryColor; }
  QString secondaryColor() const { return m_secondaryColor; }
  QString onSecondaryColor() const { return m_onSecondaryColor; }
  QString tertiaryColor() const { return m_tertiaryColor; }
  QString onTeritaryColor() const { return m_onTeritaryColor; }
  QString errorColor() const { return m_errorColor; }
  QString onErrorColor() const { return m_onErrorColor; }
  QString primaryContainerColor() const { return m_primaryContainerColor; }
  QString onPrimaryContainerColor() const { return m_onPrimaryContainerColor; }
  QString secondaryContainerColor() const { return m_secondaryContainerColor; }
  QString onSecondaryContainerColor() const {
    return m_onSecondaryContainerColor;
  }
  QString tertiaryContainerColor() const { return m_tertiaryContainerColor; }
  QString onTertiaryContainerColor() const {
    return m_onTertiaryContainerColor;
  }
  QString errorContainerColor() const { return m_errorContainerColor; }
  QString onErrorContainerColor() const { return m_onErrorContainerColor; }

  QString primaryFixedColor() const { return m_primaryFixedColor; }
  QString primaryFixedDimColor() const { return m_primaryFixedDimColor; }
  QString onPrimaryFixedColor() const { return m_onPrimaryFixedColor; }
  QString onPrimaryFixedVariantColor() const {
    return m_onPrimaryFixedVariantColor;
  }

  QString secondaryFixedColor() const { return m_secondaryFixedColor; }
  QString secondaryFixedDimColor() const { return m_secondaryFixedDimColor; }
  QString onSecondaryFixedColor() const { return m_onSecondaryFixedColor; }
  QString onSecondaryFixedVariantColor() const {
    return m_onSecondaryFixedVariantColor;
  }

  QString tertiaryFixedColor() const { return m_tertiaryFixedColor; }
  QString tertiaryFixedDimColor() const { return m_tertiaryFixedDimColor; }
  QString onTertiaryFixedColor() const { return m_onTertiaryFixedColor; }
  QString onTertiaryFixedVariantColor() const {
    return m_onTertiaryFixedVariantColor;
  }

  QString surfaceDimColor() const { return m_surfaceDimColor; }
  QString surfaceColor() const { return m_surfaceColor; }
  QString surfaceBrightColor() const { return m_surfaceBrightColor; }

  QString surfaceContainerLowestColor() const {
    return m_surfaceContainerLowestColor;
  }
  QString surfaceContainerLowColor() const {
    return m_surfaceContainerLowColor;
  }
  QString surfaceContainerColor() const { return m_surfaceContainerColor; }
  QString surfaceContainerHighColor() const {
    return m_surfaceContainerHighColor;
  }
  QString surfaceContainerHighestColor() const {
    return m_surfaceContainerHighestColor;
  }

  QString onSurfaceColor() const { return m_onSurfaceColor; }
  QString onSurfaceVariantColor() const { return m_onSurfaceVariantColor; }
  QString outlineColor() const { return m_outlineColor; }
  QString outlineVariantColor() const { return m_outlineVariantColor; }

  QString inverseSurfaceColor() const { return m_inverseSurfaceColor; }
  QString inverseOnSurfaceColor() const { return m_inverseOnSurfaceColor; }
  QString inversePrimaryColor() const { return m_inversePrimaryColor; }

  QString scrimColor() const { return m_scrimColor; }
  QString shadowColor() const { return m_shadowColor; }

 signals:
  void changed();

 private:
  void update() { update(m_baseColor, m_isDark, m_style); }

  void update(const QString& color, bool isDark, Style style) {
    QColor col(color);
    const auto& hct =
        material_color_utilities::Hct(material_color_utilities::ArgbFromRgb(
            col.red(), col.green(), col.blue()));
    const auto& generator = dynamicSchemeStyleFunction(style);
    const auto& dynamic_scheme = generator(hct, isDark);
    update(*dynamic_scheme);
  }

  DynamicSchemeGenerator dynamicSchemeStyleFunction(Style style) {
    switch (style) {
      case Vibrant:
        return VibrantSchemeGenerator;
      case TonalSpot:
        return TonalSpotSchemeGenerator;
      case Monochrome:
        return MonochromeSchemeGenerator;
      case Content:
        return ContentSchemeGenerator;
      case Expressive:
        return ExpressiveSchemeGenerator;
      case Fidelity:
        return FidelitySchemeGenerator;
      case FruitSalad:
        return FruitSaladSchemeGenerator;
      case Neutral:
        return NeutralSaladSchemeGenerator;
      case Rainbow:
        return RainbowSaladSchemeGenerator;
    }

    return VibrantSchemeGenerator;
  }

  void update(const material_color_utilities::DynamicScheme& dynamic_scheme) {
    m_backgroundColor = Hct::argbToRgbString(dynamic_scheme.GetBackground());
    m_onBackgroundColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnBackground());

    m_primaryColor = Hct::argbToRgbString(dynamic_scheme.GetPrimary());
    m_onPrimaryColor = Hct::argbToRgbString(dynamic_scheme.GetOnPrimary());

    m_secondaryColor = Hct::argbToRgbString(dynamic_scheme.GetSecondary());
    m_onSecondaryColor = Hct::argbToRgbString(dynamic_scheme.GetOnSecondary());

    m_tertiaryColor = Hct::argbToRgbString(dynamic_scheme.GetTertiary());
    m_onTeritaryColor = Hct::argbToRgbString(dynamic_scheme.GetOnTertiary());

    m_errorColor = Hct::argbToRgbString(dynamic_scheme.GetError());
    m_onErrorColor = Hct::argbToRgbString(dynamic_scheme.GetOnError());

    m_primaryContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetPrimaryContainer());
    m_onPrimaryContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnPrimaryContainer());

    m_secondaryContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetSecondaryContainer());
    m_onSecondaryContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnSecondaryContainer());

    m_tertiaryContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetTertiaryContainer());
    m_onTertiaryContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnTertiaryContainer());

    m_errorContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetErrorContainer());
    m_onErrorContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnErrorContainer());

    m_primaryFixedColor =
        Hct::argbToRgbString(dynamic_scheme.GetPrimaryFixed());
    m_primaryFixedDimColor =
        Hct::argbToRgbString(dynamic_scheme.GetPrimaryFixedDim());

    m_onPrimaryFixedColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnPrimaryFixed());
    m_onPrimaryFixedVariantColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnPrimaryFixedVariant());

    m_secondaryFixedColor =
        Hct::argbToRgbString(dynamic_scheme.GetSecondaryFixed());
    m_secondaryFixedDimColor =
        Hct::argbToRgbString(dynamic_scheme.GetSecondaryFixedDim());

    m_onSecondaryFixedColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnSecondaryFixed());
    m_onSecondaryFixedVariantColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnSecondaryFixedVariant());

    m_tertiaryFixedColor =
        Hct::argbToRgbString(dynamic_scheme.GetTertiaryFixed());
    m_tertiaryFixedDimColor =
        Hct::argbToRgbString(dynamic_scheme.GetTertiaryFixedDim());

    m_onTertiaryFixedColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnTertiaryFixed());
    m_onTertiaryFixedVariantColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnTertiaryFixedVariant());

    m_surfaceDimColor = Hct::argbToRgbString(dynamic_scheme.GetSurfaceDim());
    m_surfaceColor = Hct::argbToRgbString(dynamic_scheme.GetSurface());
    m_surfaceBrightColor =
        Hct::argbToRgbString(dynamic_scheme.GetSurfaceBright());

    m_surfaceContainerLowestColor =
        Hct::argbToRgbString(dynamic_scheme.GetSurfaceContainerLowest());
    m_surfaceContainerLowColor =
        Hct::argbToRgbString(dynamic_scheme.GetSurfaceContainerLow());
    m_surfaceContainerColor =
        Hct::argbToRgbString(dynamic_scheme.GetSurfaceContainer());
    m_surfaceContainerHighColor =
        Hct::argbToRgbString(dynamic_scheme.GetSurfaceContainerHigh());
    m_surfaceContainerHighestColor =
        Hct::argbToRgbString(dynamic_scheme.GetSurfaceContainerHighest());

    m_onSurfaceColor = Hct::argbToRgbString(dynamic_scheme.GetOnSurface());
    m_onSurfaceVariantColor =
        Hct::argbToRgbString(dynamic_scheme.GetOnSurfaceVariant());
    m_outlineColor = Hct::argbToRgbString(dynamic_scheme.GetOutline());
    m_outlineVariantColor =
        Hct::argbToRgbString(dynamic_scheme.GetOutlineVariant());

    m_inverseSurfaceColor =
        Hct::argbToRgbString(dynamic_scheme.GetInverseSurface());
    m_inverseOnSurfaceColor =
        Hct::argbToRgbString(dynamic_scheme.GetInverseOnSurface());
    m_inversePrimaryColor =
        Hct::argbToRgbString(dynamic_scheme.GetInversePrimary());

    m_scrimColor = Hct::argbToRgbString(dynamic_scheme.GetScrim());
    m_shadowColor = Hct::argbToRgbString(dynamic_scheme.GetShadow());
  }

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

int main(int argc, char** argv) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  qmlRegisterType<Hct>("Hct", 1, 0, "Hct");
  qmlRegisterType<DynamicScheme>("Hct", 1, 0, "DynamicScheme");

  const QString mainQmlFile = "/Main.qml";

  const QUrl url(QStringLiteral("qrc:") + mainQmlFile);

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject* obj, const QUrl& objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
#include "main.moc"