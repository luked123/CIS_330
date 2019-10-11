/* Luke Donnelly
 * CIS 330
 * Proj2C
 *
 * File contains struct definitions for Circle, Triangle, and Rectangle
 */

#ifndef MY_STRUCT
#define MY_STRUCT

// Subtype
typedef struct Rectangle{
    double minX;
    double maxX;
    double minY;
    double maxY;
} Rectangle;

// Subtype
typedef struct Circle{
    double radius;
    double origin;
    double originY;
} Circle;

// Subtype
typedef struct Triangle{
    double pt1X;
    double pt2X;
    double minY;
    double maxY;
} Triangle;

// Enum is a way to define specific key words for code clarity.
typedef enum ShapeType{
    Rect,
    Circ,
    Tri
} ShapeType;

// Union saves space and increases efficiency, can represent multiple data types at once
typedef union ShapeUnion{
    Rectangle r;
    Circle c;
    Triangle t;
} ShapeUnion;

struct Shape; // Tells compiler that struct will be defined later because Function Table is dependent on shape

// Demonstrates function pointers, allowing functions to change according to different data types
typedef struct FunctionTable{
    double (*GetArea) (struct Shape *s);
    void (*GetBoundingBox)(struct Shape *s, double *bbox);
} FunctionTable;

// Supertype shape. A demonstration of polymorphism.
struct Shape{
    ShapeUnion u;
    ShapeType t;
    FunctionTable ft;
};

#endif
