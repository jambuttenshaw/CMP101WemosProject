#include "Track.h"

#include "core/MathsUtility.h"

Track::Track()
    : m_TrackTranslation(Point()), m_TrackRotation(Rotation())
{
    CreateTrack();
}

Track::Track(Point initialOffset)
    : m_TrackTranslation(initialOffset), m_TrackRotation(Rotation())
{
    CreateTrack();
}

Track::~Track()
{

}

void Track::CreateTrack()
{
    // create the track
    m_TrackVertices[0] = Point({-24, -40, 0});
    m_TrackVertices[1] = Point({24, -40, 0});
    m_TrackVertices[2] = Point({-24, 104, 0});
    m_TrackVertices[3] = Point({24, 104, 0});

    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 2;
    m_TrackEdgeIndices[2] = 1;
    m_TrackEdgeIndices[3] = 3;

    // ----
    m_TrackAreaIndices[0] = 0;
    m_TrackAreaIndices[1] = 2;
    m_TrackAreaIndices[2] = 1;

    m_TrackAreaIndices[3] = 0;
    m_TrackAreaIndices[4] = 2;
    m_TrackAreaIndices[5] = 3;
}

void Track::Update(Timestep ts)
{

}

void Track::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    // the number of lines is half the number of indices
    int numIndices = sizeof(m_TrackEdgeIndices) / sizeof(unsigned int);

    for (int i = 0; i < numIndices; i += 2)
    {
        Point p1 = TransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i]]), camera.GetPosition(), Rotation());
        Point p2 = TransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i + 1]]), camera.GetPosition(), Rotation());

        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
    }
}
