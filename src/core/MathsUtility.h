#pragma once

#include <Geometry.h>

// functions for linear interpolating between a and b, 
// with one overload for floats and another for vectors

// linear interpolation takes '1-t' amount of 'a' and 't' amount of 'b', and adds them together
// and is very useful to smoothly transition between two values
float Lerp(float a, float b, float t);
Point Lerp(Point a, Point b, float t);

// return the unit vector that has the same direction as vector p
Point Normalize(Point p);

// transform a point by the translation and rotation given
// translates by rotation first, then translation
Point TransformPoint(Point toTransform, Point translation, Rotation rotation);
// transforms the point by the rotation first and then the translation
// this works in place of transforming by the inverse of a transformation matrix,
// since the matrix library is a bit awkward and lacking in transformations
Point InverseTransformPoint(Point toTransform, Point translation, Rotation rotation);

// checks to see if the point p is inside the triangle ABC
bool PointInsideTriangle(Point p, Point A, Point B, Point C);
// calculates the area of the triangle with vertices v1, v2, v3
float CalculateAreaTriangle(Point v1, Point v2, Point v3);
