#pragma once

float Lerp(float a, float b, float t)
{
    // linear interpolation between a and b
    return (1 - t) * a + b * t;
}
