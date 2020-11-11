#include "MathsUtility.h"

float Lerp(float a, float b, float t)
{
    // linear interpolation between a and b
    return (1 - t) * a + b * t;
}

Point Lerp(Point a, Point b, float t)
{
    // linear interpolation for vectors
    return a * (1 - t) + b * t; 
}

Point Normalize(Point p)
{
    return p / p.Magnitude();
}

Point TransformPoint(Point toTransform, Point translation, Rotation rotation)
{
    return (rotation * toTransform) + translation;
}

Point InverseTransformPoint(Point toTransform, Point translation, Rotation rotation)
{
    return rotation * (toTransform + translation);
}

float CalculateAreaTriangle(Point v1, Point v2, Point v3)
{
    float det = 0.0f;
    det = ((v1.X() - v3.X()) * (v2.Y() - v3.Y())) - ((v2.X() - v3.X()) * (v1.Y() - v3.Y()));
    return 0.5f * det;
}
