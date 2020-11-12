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

bool PointInsideTriangle(Point p, Point A, Point B, Point C)
{
    Point v0 = C - A;
    Point v1 = B - A;
    Point v2 = p - A;

    float dot00 = v0.DotProduct(v0);
    float dot01 = v0.DotProduct(v1);
    float dot02 = v0.DotProduct(v2);
    float dot11 = v1.DotProduct(v1);
    float dot12 = v1.DotProduct(v2);

    // compute barycentric coordinates
    float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    return (u >= 0) && (v >= 0) && (u + v < 1);
}


float CalculateAreaTriangle(Point v1, Point v2, Point v3)
{
    float det = 0.0f;
    det = ((v1.X() - v3.X()) * (v2.Y() - v3.Y())) - ((v2.X() - v3.X()) * (v1.Y() - v3.Y()));
    return 0.5f * det;
}
