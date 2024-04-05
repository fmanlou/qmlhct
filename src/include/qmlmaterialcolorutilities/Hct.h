#pragma once

#include <QObject>

#include "cpp/utils/utils.h"

QString hctToRgbString(double h, double c, double t);

QString argbToRgbString(material_color_utilities::Argb argb);

class Hct : public QObject {
  Q_OBJECT

  Q_PROPERTY(int h READ h WRITE setH NOTIFY hChanged)
  Q_PROPERTY(int c READ c WRITE setC NOTIFY cChanged)
  Q_PROPERTY(int t READ t WRITE setT NOTIFY tChanged)
  Q_PROPERTY(QString rgb READ rgb NOTIFY rgbChanged)

 public:
  Hct(QObject* parent = nullptr);

  int h() const;

  void setH(int h);

  int c() const;

  void setC(int c);

  int t() const;

  void setT(int t);

  QString rgb() const;

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