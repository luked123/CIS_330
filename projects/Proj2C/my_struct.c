/* Luke Donnelly
 * CIS 330
 * Project 2C
 */


/* File contains the 9 functions defined in prototypes.h */
#include "prototypes.h"
#define PI 3.14159


void InitializeCircle(Circle *circ, double radius, double origin, double originY){
    circ->radius = radius;
    circ->origin = origin;
    circ->originY = originY;
}

void InitializeRectangle(Rectangle *rect, double minX, double maxX, double minY, double maxY){
    rect->minX=minX;
    rect->maxX=maxX;
    rect->minY=minY;
    rect->maxY=maxY;
}

void InitializeTriangle(Triangle *tri, double pt1X, double pt2X, double minY, double maxY){
    tri->pt1X = pt1X;
    tri->pt2X = pt2X;
    tri->minY = minY;
    tri->maxY = maxY;
}


double GetCircleArea(Circle *circ){
  double radius = circ->radius;

  return radius * radius * PI;
}

double GetRectangleArea(Rectangle *rect){
    double width = rect->maxX - rect->minX;
    double height = rect->maxY - rect->minY;

    return width * height;
}

double GetTriangleArea(Triangle *tri){
    double base = tri->pt2X - tri->pt1X;
    double height = tri->maxY - tri->minY;

    return base * height * 0.5;
}

void GetCircleBoundingBox(Circle *circ, double *bbox){
    double origin = circ->origin;
    double originY = circ->originY;
    double radius = circ->radius;

    bbox[0] = origin - radius;
    bbox[1] = origin + radius;
    bbox[2] = originY - radius;
    bbox[3] = originY + radius;
}

void GetRectangleBoundingBox(Rectangle *rec, double *bbox){
    bbox[0] = rec->minX;
    bbox[1] = rec->maxX;
    bbox[2] = rec->minY;
    bbox[3] = rec->maxY;
}

void GetTriangleBoundingBox(Triangle *tri, double *bbox){
    bbox[0] = tri->pt1X;
    bbox[1] = tri->pt2X;
    bbox[2] = tri->minY;
    bbox[3] = tri->maxY;
}
