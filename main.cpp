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

  Q_PROPERTY(bool light READ light WRITE setLight NOTIFY changed)
  Q_PROPERTY(Style style READ style WRITE setStyle NOTIFY changed)
  Q_PROPERTY(QString baseColor READ baseColor WRITE setBaseColor NOTIFY changed)

  Q_PROPERTY(QString backgroundColor READ backgroundColor NOTIFY changed)
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

  bool light() const { return m_light; }

  void setLight(bool b) {
    if (m_light != b) {
      m_light = b;
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

 signals:
  void changed();

 private:
  void update() { update(m_baseColor, m_light, m_style); }

  void update(const QString& color, bool light, Style style) {
    QColor col(color);
    const auto& hct =
        material_color_utilities::Hct(material_color_utilities::ArgbFromRgb(
            col.red(), col.green(), col.blue()));
    const auto& generator = dynamicSchemeStyleFunction(style);
    const auto& dynamic_scheme = generator(hct, light);
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
  }

 private:
  QString m_baseColor;
  bool m_light;
  Style m_style;

  QString m_backgroundColor;
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