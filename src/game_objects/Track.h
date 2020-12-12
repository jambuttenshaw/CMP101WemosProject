#pragma once

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

#include "core/Timestep.h"
#include "Camera.h"

#include <vector>


class Track
{
public:

    // a quick enum for specifying how you want the track drawn on screen
    // Lines draws the track edges
    // Fill fills in the area of the track
    // Wireframe draws the outlines of the triangles that make up the track
    enum DrawMode
    {
        Lines,
        Fill,
        Wireframe
    };

public:
    // constructors and destructors
    Track();
    Track(Point initialOffset);
    ~Track();

    // translate the track by a vector
    inline void Translate(Point translation) { m_TrackTranslation += translation; }
    // set the track to a specific vector
    inline void SetPosition(Point pos) { m_TrackTranslation = pos; }

    // set the tracks rotation to a specific matrix
    inline void SetRotation(Rotation rot) { m_TrackRotation = rot; }
    // rotate the track by a given matrix
    inline void Rotate(Rotation rot) { m_TrackRotation *= rot; }

    // the update function
    void Update(Timestep ts);

    // draw to the display
    // an overload for specifying a draw mode
    void Draw(Adafruit_SSD1306& display, Camera& camera);
    void Draw(DrawMode mode, Adafruit_SSD1306& display, Camera& camera);

    // set the default draw mode
    inline void SetDrawMode(DrawMode mode) { m_DrawMode = mode; }

    // checks to see if a point p is on the track
    bool PointOnTrack(Point p);
    // checks if the point p is crossing the finish line
    bool CrossingFinishLine(Point p);
    // checks if the point p is at the halfway point around the track
    bool AtAngularHalfway(Point p);

private:
    // draws the track as lines
    void DrawLines(Adafruit_SSD1306& display, Camera& camera);
    // draws the track as filled triangles
    void DrawTriangles(Adafruit_SSD1306& display, Camera& camera);
    // draws the edges of the triangles used to fill the track
    void DrawWireframe(Adafruit_SSD1306& display, Camera& camera);
    
    // draw the finish line onto the track
    void DrawFinishLine(Adafruit_SSD1306& display, Camera& camera);

    // populates the track data array
    void CreateTrack();

private:
    // set default draw mode to lines
    DrawMode m_DrawMode = DrawMode::Lines;

    // GEOMETRY OF THE TRACK
    Point m_TrackVertices[150]; // an array of points that define the shape of the track
    unsigned int m_TrackEdgeIndices[300]; // an array of indices that define how the points that make up the track should be joined together
    unsigned int m_TrackAreaIndices[450]; // an array of indices that define the area that the track covers, for checking when the car is on or off the track

    // the centroid of the track
    Point m_TrackCentroid;

    // which vertices in the array form the start line
    unsigned int m_StartLineVertices[2] = {0, 1};

    // a vector from one end of the finish line to the other
    Point m_FinishLine;
    // the length of the finish line
    float m_FinishLineLength;
    // how precisely the position of the car needs to be to the finish line
    // lower value is more precise
    float m_CrossingLineThreshold = 0.3f;

    // the position of the track
    Point m_TrackTranslation;
    // the rotation of the track
    Rotation m_TrackRotation;

    // a vector from the centroid of the track to the start line
    Point m_CentroidToStartLine;
    // how precisely the car needs to match halfway round the track to count as having passed halfway
    float m_HalfwayThreshold = 0.05f;
};
