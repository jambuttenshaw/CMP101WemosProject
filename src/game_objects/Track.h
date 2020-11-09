#pragma once

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

#include "core/Timestep.h"
#include "Camera.h"

#include <vector>


class Track
{
public:
    Track();
    Track(Point initialOffset);
    ~Track();

    inline void Translate(Point translation) { m_TrackTranslation += translation; }
    inline void SetPosition(Point pos) { m_TrackTranslation = pos; }

    inline void SetRotation(Rotation rot) { m_TrackRotation = rot; }
    inline void Rotate(Rotation rot) { m_TrackRotation *= rot; }

    void Update(Timestep ts);
    void Draw(Adafruit_SSD1306& display, Camera& camera);

private:
    void CreateTrack();

private:
    // GEOMETRY OF THE TRACK
    Point m_TrackVertices[4]; // an array of points that define the shape of the track
    unsigned int m_TrackEdgeIndices[4]; // an array of indices that define how the points that make up the track should be joined together
    unsigned int m_TrackAreaIndices[6]; // an array of indices that define the area that the track covers, for checking when the car is on or off the track

    Point m_TrackTranslation;
    Rotation m_TrackRotation;
};
