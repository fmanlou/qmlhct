#include "qmlmaterialcolorutilities/Hct.h"

#include "cpp/cam/hct.h"

Hct::Hct(QObject* parent) : QObject(parent) {
  connect(this, &Hct::hChanged, this, &Hct::rgbChanged);
  connect(this, &Hct::cChanged, this, &Hct::rgbChanged);
  connect(this, &Hct::tChanged, this, &Hct::rgbChanged);
}

int Hct::h() const { return hue; }

void Hct::setH(int h) {
  if (h != hue) {
    hue = h;
    emit hChanged();
  }
}

int Hct::c() const { return chroma; }

void Hct::setC(int c) {
  if (c != chroma) {
    chroma = c;
    emit cChanged();
  }
}

int Hct::t() const { return tone; }

void Hct::setT(int t) {
  if (t != tone) {
    tone = t;
    emit tChanged();
  }
}

QString Hct::rgb() const { return hctToRgbString(hue, chroma, tone); }

QString Hct::hctToRgbString(double h, double c, double t) {
  material_color_utilities::Hct d{h, c, t};
  return argbToRgbString(d.ToInt());
}

QString Hct::argbToRgbString(material_color_utilities::Argb argb) {
  return "#" +
         QString::fromStdString(material_color_utilities::HexFromArgb(argb))
             .remove(0, 2);
}