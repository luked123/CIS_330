/* Luke Donnelly
 * CIS 330
 * Proj2C
 * 
 * File contains struct definitions for Circle, Triangle, and Rectangle
 */

#ifndef MY_STRUCT
#define MY_STRUCT

typedef struct Rectangle{
    double minX;
    double maxX;
    double minY;
    double maxY;
} Rectangle; 

typedef struct Circle{
    double radius; 
    double origin;
    double originY; 
} Circle; 

typedef struct Triangle{
    double pt1X;
    double pt2X;
    double minY;
    double maxY; 
} Triangle; 

#endif
