#ifndef __BALL_H__
#define __BALL_H__

#include <iostream>
#include "common.h"
#include "geometry.h"

using namespace std;

class Ball {
 public:
  Ball(GLfloat _x, GLfloat _y, GLint _r, Color _c, bool _solid);

  operator GLfloat*() { return x; }
  GLint operator[](int i) const { return x[i]; }
  Color c;
  GLfloat x[2];  // Position
  Vector v;      // Velocity
  GLfloat a[2];  // Acceleration
  GLfloat mass;
  GLint radius;
  bool solid;

  void draw();
  bool isStopped();
  void checkBounds();
  bool collide(Ball *other);
  bool collideToHole(Ball *hole);
  void elasticCollision(Ball *other);
  void update(float elapsed_time);
  void setVelocity(GLfloat vx, GLfloat vy);
};

#endif
