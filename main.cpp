#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cpp/cam/hct.h"
#include "cpp/scheme/scheme.h"
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
    return "#" + QString::fromStdString(
                     material_color_utilities::HexFromArgb(d.ToInt()))
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

int main(int argc, char** argv) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  const material_color_utilities::Scheme& scheme =
      material_color_utilities::MaterialLightColorScheme(
          material_color_utilities::ArgbFromRgb(0, 0x86, 0x73));

  qmlRegisterType<Hct>("Hct", 1, 0, "Hct");

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