#pragma once

#include <Geometry.h>

float Lerp(float a, float b, float t);
Point Lerp(Point a, Point b, float t);

Point Normalize(Point p);

Point TransformPoint(Point toTransform, Point translation, Rotation rotation);
