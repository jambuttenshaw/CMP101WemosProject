#pragma once

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

void TransformPoint(Point& toTransform, Point translation, Rotation rotation)
{
    toTransform = (rotation * toTransform) + translation;
}
