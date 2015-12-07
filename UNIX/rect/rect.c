#include <stdio.h>
#include <stdlib.h>
#include "rect.h"


Rect* createRect (float x1, float y1, float x2, float y2)
{
  Rect* r = malloc(sizeof(Rect));
  r->pt1.x = x1;
  r->pt1.y = y1;
  r->pt2.x = x2;
  r->pt2.y = y2;

  return r;
}

Rect* copyRect (Rect* r){
  Rect* r2 = malloc(sizeof(Rect));
  r2->pt1.x = r->pt1.x;
  r2->pt1.y = r->pt1.y;
  r2->pt2.x = r->pt2.x;
  r2->pt2.y = r->pt2.y;

  return r2;  
}

void move (Rect *r, float dx, float dy)
{
  r->pt1.x += dx;
  r->pt1.y += dy;
  r->pt2.x += dx;
  r->pt2.y += dy;
}

void dilate (Rect *r, float factor)
{
  r->pt1.x *= factor;
  r->pt1.y *= factor;
  r->pt2.x *= factor;
  r->pt2.y *= factor; 
}

float getWidth (Rect *r){
  float a = (r->pt1.x) - (r->pt2.x);
  if(a<0) a*=-1;
  return a;
}

float getHeight (Rect *r){
  float a = (r->pt1.y) - (r->pt2.y);
  if(a<0) a*=-1;
  return a;
}

float getArea (Rect *r){
  return (getWidth(r)*getHeight(r));
}

float getPerimeter (Rect *r){
  float width = getWidth(r);
  float height = getHeight(r);
  return (width*2 + height*2);
}

char* toString (Rect *r, char out[])
{
  sprintf(out, "Rectangle: (%.1f, %.1f); (%.1f, %.1f)", r->pt1.x, r->pt1.y, r->pt2.x, r->pt2.y);
  return out;
}
