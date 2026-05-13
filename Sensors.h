#pragma once

struct Dist {

  int sl;
  int fl;
  int fc;
  int fr;
  int sr;
};



struct Line {

  bool left;
  bool right;

  int leftRaw;
  int rightRaw;
};



namespace Sensors {

  void begin();

  Dist readDist();

  Line readLine();
}
