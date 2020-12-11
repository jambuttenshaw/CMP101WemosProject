#include "MathsUtility.h"

float Lerp(float a, float b, float t)
{
    // linear interpolation between a and b
    // t should be in the range of 0 and 1
    return (1 - t) * a + b * t;
}

Point Lerp(Point a, Point b, float t)
{
    // linear interpolation for vectors
    // t should be in the range of 0 and 1
    return a * (1 - t) + b * t; 
}

Point Normalize(Point p)
{
    // to normalize a vector divide it by its magnitude
    return p / p.Magnitude();
}

Point TransformPoint(Point toTransform, Point translation, Rotation rotation)
{
    // multiply the point by the rotation matrix, then add on the translation
    return (rotation * toTransform) + translation;
}

Point InverseTransformPoint(Point toTransform, Point translation, Rotation rotation)
{
    // translate the point by the translation and then multiply by the rotation matrix
    return rotation * (toTransform + translation);
}

bool PointInsideTriangle(Point p, Point A, Point B, Point C)
{
    /*
    this is a fast method of calculating if a point is inside a triangle
    it makes use of something called barycentric coordinates

    if you consider the two vectors that make up 2 sides of the triangle (v0 and v1), provided they are not parallel (which theyre not; its a triangle),
    then you can write any point in the triangles plane in terms of only those two vectors like so:
    
    P = u * v0 + v * v1

    Then any point in the plane can be described by different choices of u and v.
    We want to find the u and v that will give us the point P.

    since P, v0, and v1 are vectors, we can construct 2 different equations for P in terms of u and v.
    Then by using cramer's rule for using determinants to solve linear equations
    we can get the expressions for u and v used in this function.

    Once we have that, we know that if u and v are both positive, and their sum is less than 1
    the point MUST be inside the triangle.

    This algorithm really shines as its very computationally cheap, which is essential when we have many triangles to check every frame.
    */

   // get the vectors along triangles edges and to the point
    Point v0 = C - A;
    Point v1 = B - A;
    Point v2 = p - A;

    // compute the dot products we need for finding the barycentric coordinates
    float dot00 = v0.DotProduct(v0);
    float dot01 = v0.DotProduct(v1);
    float dot02 = v0.DotProduct(v2);
    float dot11 = v1.DotProduct(v1);
    float dot12 = v1.DotProduct(v2);

    // compute barycentric coordinates
    float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // if u and v are positive and do not sum to 1 or greater then the point is inside the triangle
    return (u >= 0) && (v >= 0) && (u + v < 1);
}


float CalculateAreaTriangle(Point v1, Point v2, Point v3)
{
    float det = 0.0f;
    // we can use the determinant of a 3x3 matrix constructed from the triangles points to find the area quite simply
    det = ((v1.X() - v3.X()) * (v2.Y() - v3.Y())) - ((v2.X() - v3.X()) * (v1.Y() - v3.Y()));
    return 0.5f * det;
}
