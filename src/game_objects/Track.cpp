#include "Track.h"

Track::Track()
{
    // create the track
    m_TrackVertices[0] = Point({40, -40, 0});
    m_TrackVertices[1] = Point({88, -40, 0});
    m_TrackVertices[2] = Point({40, 104, 0});
    m_TrackVertices[3] = Point({88, 104, 0});

    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 2;
    m_TrackEdgeIndices[2] = 1;
    m_TrackEdgeIndices[3] = 3;
}

Track::~Track()
{

}

void Track::Update()
{

}

void Track::Draw(Adafruit_SSD1306& display)
{
    // the number of lines is half the number of indices
    int numIndices = sizeof(m_TrackEdgeIndices) / sizeof(unsigned int);

    for (int i = 0; i < numIndices; i += 2)
    {
        Point p1 = m_TrackVertices[m_TrackEdgeIndices[i]];
        Point p2 = m_TrackVertices[m_TrackEdgeIndices[i + 1]];
        
        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
    }
}
