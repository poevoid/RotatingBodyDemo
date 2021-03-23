#include <Arduboy2.h>

Arduboy2 arduboy;
struct center {
  float x, y;
};
struct point {
  float x, y;
};

center c = {WIDTH/2, HEIGHT/2};
point p = {WIDTH/2, HEIGHT/2 -15};

float angleA = 0.01;
float angleC = -0.01;


void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  if (!arduboy.nextFrame()) return;
  //arduboy.clear();
  ///run code here
  arduboy.drawPixel(c.x, c.y);
  arduboy.drawPixel(p.x, p.y);
  if (arduboy.pressed(LEFT_BUTTON)) {
    float s = sin(angleA);
    float C = cos(angleA);
    p.x -= c.x;
    p.y -= c.y;

    float newx = (p.x*C)-(p.y*s);
    float newy = (p.x*s)+(p.y*C);

    p.x = newx + c.x;
    p.y = newy + c.y;
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    float s = sin(angleC);
    float C = cos(angleC);
    p.x -= c.x;
    p.y -= c.y;

    float newx = (p.x*C)-(p.y*s);
    float newy = (p.x*s)+(p.y*C);

    p.x = newx + c.x;
    p.y = newy + c.y;
  }
  arduboy.display();
}
