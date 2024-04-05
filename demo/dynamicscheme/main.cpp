#include <QColor>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "qmlmaterialcolorutilities/DynamicScheme.h"
#include "qmlmaterialcolorutilities/Hct.h"

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
