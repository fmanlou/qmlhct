#include "qmlmaterialcolorutilities/Hct.h"

#include "HctImpl.h"
#include "cpp/cam/hct.h"

QString hctToRgbString(double h, double c, double t) {
  material_color_utilities::Hct d{h, c, t};
  return argbToRgbString(d.ToInt());
}

QString argbToRgbString(material_color_utilities::Argb argb) {
  return "#" +
         QString::fromStdString(material_color_utilities::HexFromArgb(argb))
             .remove(0, 2);
}

Hct::Hct(QObject* parent) : QObject(parent) {
  impl = new HctImpl;

  connect(this, &Hct::hChanged, this, &Hct::rgbChanged);
  connect(this, &Hct::cChanged, this, &Hct::rgbChanged);
  connect(this, &Hct::tChanged, this, &Hct::rgbChanged);
}

Hct::~Hct() { delete impl; }

int Hct::h() const { return impl->d.hue; }

void Hct::setH(int h) {
  if (h != impl->d.hue) {
    impl->d.hue = h;
    emit hChanged();
  }
}

int Hct::c() const { return impl->d.chroma; }

void Hct::setC(int c) {
  if (c != impl->d.chroma) {
    impl->d.chroma = c;
    emit cChanged();
  }
}

int Hct::t() const { return impl->d.tone; }

void Hct::setT(int t) {
  if (t != impl->d.tone) {
    impl->d.tone = t;
    emit tChanged();
  }
}

QString Hct::rgb() const {
  return hctToRgbString(impl->d.hue, impl->d.chroma, impl->d.tone);
}
