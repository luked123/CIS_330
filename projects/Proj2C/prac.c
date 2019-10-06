#include "prototypes.h"
#include <stdio.h>

int main(){

    Rectangle r; 
    Circle c; 
    Triangle t; 

    InitializeRectangle(&r, 0.0, 0.5, 0.5, 1.0);
    InitializeCircle(&c, 1.5, 2, 3);
    InitializeTriangle(&t, 4.1, 5.1, 6.1, 7.1);

    printf("R has following values\n"
           "MinX = %f\n"
           "MaxX = %f\n"
           "MinY = %f\n" 
           "MaxY = %f\n", 
           r.minX, r.maxX, r.minY, r.maxY); 

    printf("C has following values\n"
           "Radius = %f\n"
           "Origin = %f\n" 
           "OriginY = %f\n", 
           c.radius, c.origin, c.originY); 
    
    printf("R has following values\n"
           "Pt1x = %f\n"
           "Pt2x = %f\n"
           "minY = %f\n" 
           "maxY = %f\n", 
           t.pt1X, t.pt2X, t.minY, t.maxY); 

}
