#pragma once

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

#include "core/Timestep.h"
#include "Camera.h"

#include <vector>


class Track
{
public:

    enum DrawMode
    {
        Lines,
        Fill,
        Wireframe
    };

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
    void Draw(DrawMode mode, Adafruit_SSD1306& display, Camera& camera);

    inline void SetDrawMode(DrawMode mode) { m_DrawMode = mode; }

    bool PointOnTrack(Point p);

    bool CrossingFinishLine(Point p);
    bool AtAngularHalfway(Point p);

private:
    void DrawLines(Adafruit_SSD1306& display, Camera& camera);
    void DrawTriangles(Adafruit_SSD1306& display, Camera& camera);
    void DrawWireframe(Adafruit_SSD1306& display, Camera& camera);

    void CreateTrack();

private:
    DrawMode m_DrawMode = DrawMode::Lines;

    // GEOMETRY OF THE TRACK
    Point m_TrackVertices[75]; // an array of points that define the shape of the track
    unsigned int m_TrackEdgeIndices[150]; // an array of indices that define how the points that make up the track should be joined together
    unsigned int m_TrackAreaIndices[225]; // an array of indices that define the area that the track covers, for checking when the car is on or off the track

    Point m_TrackCentroid;

    unsigned int m_StartLineVertices[2] = {0, 37};

    Point m_FinishLine;
    float m_FinishLineLength;
    float m_CrossingLineThreshold = 0.3f;

    Point m_TrackTranslation;
    Rotation m_TrackRotation;

    Point m_CentroidToStartLine;
    float m_HalfwayThreshold = 0.05f;
};
