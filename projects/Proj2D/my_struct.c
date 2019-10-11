/* Luke Donnelly
 * CIS 330
 * Project 2C
 */


/* File contains the 9 functions defined in prototypes.h */
#include "prototypes.h"
#define PI 3.14159


void InitializeCircle(struct Shape *circ, double radius, double origin, double originY){
    Circle c;
    c.radius = radius;
    c.origin = origin;
    c.originY = originY;

    circ->u.c = c;
    circ->t = Circ;
    circ->ft.GetArea = GetCircleArea;
    circ->ft.GetBoundingBox = GetCircleBoundingBox;
}

void InitializeRectangle(struct Shape *rect, double minX, double maxX, double minY, double maxY){
    Rectangle r;
    r.minX=minX;
    r.maxX=maxX;
    r.minY=minY;
    r.maxY=maxY;

    rect->u.r = r;
    rect->t = Rect;
    rect->ft.GetArea = GetRectangleArea;
    rect->ft.GetBoundingBox = GetRectangleBoundingBox;
}

void InitializeTriangle(struct Shape *tri, double pt1X, double pt2X, double minY, double maxY){
    Triangle t;
    t.pt1X = pt1X;
    t.pt2X = pt2X;
    t.minY = minY;
    t.maxY = maxY;

    tri->u.t = t;
    tri->t = Tri;
    tri->ft.GetArea = GetTriangleArea;
    tri->ft.GetBoundingBox = GetTriangleBoundingBox;
}


double GetCircleArea(struct Shape *circ){
    double radius = circ->u.c.radius;

    return radius * radius * PI;
}

double GetRectangleArea(struct Shape *rect){
    double width = rect->u.r.maxX - rect->u.r.minX;
    double height = rect->u.r.maxY - rect->u.r.minY;

    return width * height;
}

double GetTriangleArea(struct Shape *tri){
    double base = tri->u.t.pt2X - tri->u.t.pt1X;
    double height = tri->u.t.maxY - tri->u.t.minY;

    return base * height * 0.5;
}

void GetCircleBoundingBox(struct Shape *circ, double *bbox){
    double origin = circ->u.c.origin;
    double originY = circ->u.c.originY;
    double radius = circ->u.c.radius;

    bbox[0] = origin - radius;
    bbox[1] = origin + radius;
    bbox[2] = originY - radius;
    bbox[3] = originY + radius;
}

void GetRectangleBoundingBox(struct Shape *rect, double *bbox){
    bbox[0] = rect->u.r.minX;
    bbox[1] = rect->u.r.maxX;
    bbox[2] = rect->u.r.minY;
    bbox[3] = rect->u.r.maxY;
}

void GetTriangleBoundingBox(struct Shape *tri, double *bbox){
    bbox[0] = tri->u.t.pt1X;
    bbox[1] = tri->u.t.pt2X;
    bbox[2] = tri->u.t.minY;
    bbox[3] = tri->u.t.maxY;
}
