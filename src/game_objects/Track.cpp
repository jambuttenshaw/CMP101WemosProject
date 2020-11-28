#include "Track.h"

#include "core/MathsUtility.h"

#include <Streaming.h>

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
    m_TrackVertices[0] = Point({-24, -39, 0});
    m_TrackVertices[1] = Point({-24, 30, 0});
    m_TrackVertices[2] = Point({-26, 62, 0});
    m_TrackVertices[3] = Point({-54, 99, 0});
    m_TrackVertices[4] = Point({-110, 107, 0});
    m_TrackVertices[5] = Point({-161, 103, 0});
    m_TrackVertices[6] = Point({-195, 69, 0});
    m_TrackVertices[7] = Point({-218, 41, 0});
    m_TrackVertices[8] = Point({-241, 28, 0});
    m_TrackVertices[9] = Point({-280, 41, 0});
    m_TrackVertices[10] = Point({-307, 76, 0});
    m_TrackVertices[11] = Point({-324, 97, 0});
    m_TrackVertices[12] = Point({-345, 120, 0});
    m_TrackVertices[13] = Point({-376, 107, 0});
    m_TrackVertices[14] = Point({-410, 79, 0});
    m_TrackVertices[15] = Point({-406, 36, 0});
    m_TrackVertices[16] = Point({-385, -25, 0});
    m_TrackVertices[17] = Point({-351, -49, 0});
    m_TrackVertices[18] = Point({-280, -73, 0});
    m_TrackVertices[19] = Point({-243, -120, 0});
    m_TrackVertices[20] = Point({-191, -142, 0});
    m_TrackVertices[21] = Point({-140, -138, 0});
    m_TrackVertices[22] = Point({-94, -130, 0});
    m_TrackVertices[23] = Point({-61, -119, 0});
    m_TrackVertices[24] = Point({-37, -92, 0});
    m_TrackVertices[25] = Point({-26, -64, 0});
    m_TrackVertices[26] = Point({15, -40, 0});
    m_TrackVertices[27] = Point({17, 26, 0});
    m_TrackVertices[28] = Point({16, 61, 0});
    m_TrackVertices[29] = Point({1, 83, 0});
    m_TrackVertices[30] = Point({-13, 104, 0});
    m_TrackVertices[31] = Point({-45, 117, 0});
    m_TrackVertices[32] = Point({-80, 130, 0});
    m_TrackVertices[33] = Point({-123, 131, 0});
    m_TrackVertices[34] = Point({-174, 126, 0});
    m_TrackVertices[35] = Point({-203, 104, 0});
    m_TrackVertices[36] = Point({-230, 72, 0});
    m_TrackVertices[37] = Point({-244, 62, 0});
    m_TrackVertices[38] = Point({-253, 61, 0});
    m_TrackVertices[39] = Point({-264, 65, 0});
    m_TrackVertices[40] = Point({-274, 83, 0});
    m_TrackVertices[41] = Point({-295, 105, 0});
    m_TrackVertices[42] = Point({-313, 126, 0});
    m_TrackVertices[43] = Point({-329, 142, 0});
    m_TrackVertices[44] = Point({-346, 146, 0});
    m_TrackVertices[45] = Point({-365, 139, 0});
    m_TrackVertices[46] = Point({-380, 134, 0});
    m_TrackVertices[47] = Point({-416, 118, 0});
    m_TrackVertices[48] = Point({-441, 97, 0});
    m_TrackVertices[49] = Point({-446, 83, 0});
    m_TrackVertices[50] = Point({-441, 45, 0});
    m_TrackVertices[51] = Point({-434, -8, 0});
    m_TrackVertices[52] = Point({-427, -45, 0});
    m_TrackVertices[53] = Point({-390, -64, 0});
    m_TrackVertices[54] = Point({-344, -87, 0});
    m_TrackVertices[55] = Point({-295, -103, 0});
    m_TrackVertices[56] = Point({-287, -138, 0});
    m_TrackVertices[57] = Point({-249, -158, 0});
    m_TrackVertices[58] = Point({-214, -173, 0});
    m_TrackVertices[59] = Point({-179, -180, 0});
    m_TrackVertices[60] = Point({-147, -179, 0});
    m_TrackVertices[61] = Point({-125, -174, 0});
    m_TrackVertices[62] = Point({-79, -162, 0});
    m_TrackVertices[63] = Point({-34, -143, 0});
    m_TrackVertices[64] = Point({-10, -118, 0});
    m_TrackVertices[65] = Point({7, -87, 0});
    m_TrackVertices[66] = Point({12, -69, 0});
    m_TrackVertices[67] = Point({15, -51, 0});


    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 25;
    m_TrackEdgeIndices[2] = 0;
    m_TrackEdgeIndices[3] = 1;
    m_TrackEdgeIndices[4] = 1;
    m_TrackEdgeIndices[5] = 2;
    m_TrackEdgeIndices[6] = 2;
    m_TrackEdgeIndices[7] = 3;
    m_TrackEdgeIndices[8] = 3;
    m_TrackEdgeIndices[9] = 4;
    m_TrackEdgeIndices[10] = 4;
    m_TrackEdgeIndices[11] = 5;
    m_TrackEdgeIndices[12] = 5;
    m_TrackEdgeIndices[13] = 6;
    m_TrackEdgeIndices[14] = 6;
    m_TrackEdgeIndices[15] = 7;
    m_TrackEdgeIndices[16] = 7;
    m_TrackEdgeIndices[17] = 8;
    m_TrackEdgeIndices[18] = 8;
    m_TrackEdgeIndices[19] = 9;
    m_TrackEdgeIndices[20] = 9;
    m_TrackEdgeIndices[21] = 10;
    m_TrackEdgeIndices[22] = 10;
    m_TrackEdgeIndices[23] = 11;
    m_TrackEdgeIndices[24] = 11;
    m_TrackEdgeIndices[25] = 12;
    m_TrackEdgeIndices[26] = 12;
    m_TrackEdgeIndices[27] = 13;
    m_TrackEdgeIndices[28] = 13;
    m_TrackEdgeIndices[29] = 14;
    m_TrackEdgeIndices[30] = 14;
    m_TrackEdgeIndices[31] = 15;
    m_TrackEdgeIndices[32] = 15;
    m_TrackEdgeIndices[33] = 16;
    m_TrackEdgeIndices[34] = 16;
    m_TrackEdgeIndices[35] = 17;
    m_TrackEdgeIndices[36] = 17;
    m_TrackEdgeIndices[37] = 18;
    m_TrackEdgeIndices[38] = 18;
    m_TrackEdgeIndices[39] = 19;
    m_TrackEdgeIndices[40] = 19;
    m_TrackEdgeIndices[41] = 20;
    m_TrackEdgeIndices[42] = 20;
    m_TrackEdgeIndices[43] = 21;
    m_TrackEdgeIndices[44] = 21;
    m_TrackEdgeIndices[45] = 22;
    m_TrackEdgeIndices[46] = 22;
    m_TrackEdgeIndices[47] = 23;
    m_TrackEdgeIndices[48] = 23;
    m_TrackEdgeIndices[49] = 24;
    m_TrackEdgeIndices[50] = 24;
    m_TrackEdgeIndices[51] = 25;
    m_TrackEdgeIndices[52] = 26;
    m_TrackEdgeIndices[53] = 67;
    m_TrackEdgeIndices[54] = 26;
    m_TrackEdgeIndices[55] = 27;
    m_TrackEdgeIndices[56] = 27;
    m_TrackEdgeIndices[57] = 28;
    m_TrackEdgeIndices[58] = 28;
    m_TrackEdgeIndices[59] = 29;
    m_TrackEdgeIndices[60] = 29;
    m_TrackEdgeIndices[61] = 30;
    m_TrackEdgeIndices[62] = 30;
    m_TrackEdgeIndices[63] = 31;
    m_TrackEdgeIndices[64] = 31;
    m_TrackEdgeIndices[65] = 32;
    m_TrackEdgeIndices[66] = 32;
    m_TrackEdgeIndices[67] = 33;
    m_TrackEdgeIndices[68] = 33;
    m_TrackEdgeIndices[69] = 34;
    m_TrackEdgeIndices[70] = 34;
    m_TrackEdgeIndices[71] = 35;
    m_TrackEdgeIndices[72] = 35;
    m_TrackEdgeIndices[73] = 36;
    m_TrackEdgeIndices[74] = 36;
    m_TrackEdgeIndices[75] = 37;
    m_TrackEdgeIndices[76] = 37;
    m_TrackEdgeIndices[77] = 38;
    m_TrackEdgeIndices[78] = 38;
    m_TrackEdgeIndices[79] = 39;
    m_TrackEdgeIndices[80] = 39;
    m_TrackEdgeIndices[81] = 40;
    m_TrackEdgeIndices[82] = 40;
    m_TrackEdgeIndices[83] = 41;
    m_TrackEdgeIndices[84] = 41;
    m_TrackEdgeIndices[85] = 42;
    m_TrackEdgeIndices[86] = 42;
    m_TrackEdgeIndices[87] = 43;
    m_TrackEdgeIndices[88] = 43;
    m_TrackEdgeIndices[89] = 44;
    m_TrackEdgeIndices[90] = 44;
    m_TrackEdgeIndices[91] = 45;
    m_TrackEdgeIndices[92] = 45;
    m_TrackEdgeIndices[93] = 46;
    m_TrackEdgeIndices[94] = 46;
    m_TrackEdgeIndices[95] = 47;
    m_TrackEdgeIndices[96] = 47;
    m_TrackEdgeIndices[97] = 48;
    m_TrackEdgeIndices[98] = 48;
    m_TrackEdgeIndices[99] = 49;
    m_TrackEdgeIndices[100] = 49;
    m_TrackEdgeIndices[101] = 50;
    m_TrackEdgeIndices[102] = 50;
    m_TrackEdgeIndices[103] = 51;
    m_TrackEdgeIndices[104] = 51;
    m_TrackEdgeIndices[105] = 52;
    m_TrackEdgeIndices[106] = 52;
    m_TrackEdgeIndices[107] = 53;
    m_TrackEdgeIndices[108] = 53;
    m_TrackEdgeIndices[109] = 54;
    m_TrackEdgeIndices[110] = 54;
    m_TrackEdgeIndices[111] = 55;
    m_TrackEdgeIndices[112] = 55;
    m_TrackEdgeIndices[113] = 56;
    m_TrackEdgeIndices[114] = 56;
    m_TrackEdgeIndices[115] = 57;
    m_TrackEdgeIndices[116] = 57;
    m_TrackEdgeIndices[117] = 58;
    m_TrackEdgeIndices[118] = 58;
    m_TrackEdgeIndices[119] = 59;
    m_TrackEdgeIndices[120] = 59;
    m_TrackEdgeIndices[121] = 60;
    m_TrackEdgeIndices[122] = 60;
    m_TrackEdgeIndices[123] = 61;
    m_TrackEdgeIndices[124] = 61;
    m_TrackEdgeIndices[125] = 62;
    m_TrackEdgeIndices[126] = 62;
    m_TrackEdgeIndices[127] = 63;
    m_TrackEdgeIndices[128] = 63;
    m_TrackEdgeIndices[129] = 64;
    m_TrackEdgeIndices[130] = 64;
    m_TrackEdgeIndices[131] = 65;
    m_TrackEdgeIndices[132] = 65;
    m_TrackEdgeIndices[133] = 66;
    m_TrackEdgeIndices[134] = 66;
    m_TrackEdgeIndices[135] = 67;
    
    m_TrackAreaIndices[0] = 0;
    m_TrackAreaIndices[1] = 67;
    m_TrackAreaIndices[2] = 26;
    m_TrackAreaIndices[3] = 0;
    m_TrackAreaIndices[4] = 66;
    m_TrackAreaIndices[5] = 67;
    m_TrackAreaIndices[6] = 0;
    m_TrackAreaIndices[7] = 25;
    m_TrackAreaIndices[8] = 66;
    m_TrackAreaIndices[9] = 25;
    m_TrackAreaIndices[10] = 65;
    m_TrackAreaIndices[11] = 66;
    m_TrackAreaIndices[12] = 25;
    m_TrackAreaIndices[13] = 24;
    m_TrackAreaIndices[14] = 65;
    m_TrackAreaIndices[15] = 24;
    m_TrackAreaIndices[16] = 64;
    m_TrackAreaIndices[17] = 65;
    m_TrackAreaIndices[18] = 24;
    m_TrackAreaIndices[19] = 23;
    m_TrackAreaIndices[20] = 64;
    m_TrackAreaIndices[21] = 23;
    m_TrackAreaIndices[22] = 63;
    m_TrackAreaIndices[23] = 64;
    m_TrackAreaIndices[24] = 23;
    m_TrackAreaIndices[25] = 22;
    m_TrackAreaIndices[26] = 63;
    m_TrackAreaIndices[27] = 22;
    m_TrackAreaIndices[28] = 62;
    m_TrackAreaIndices[29] = 63;
    m_TrackAreaIndices[30] = 22;
    m_TrackAreaIndices[31] = 21;
    m_TrackAreaIndices[32] = 62;
    m_TrackAreaIndices[33] = 21;
    m_TrackAreaIndices[34] = 61;
    m_TrackAreaIndices[35] = 62;
    m_TrackAreaIndices[36] = 21;
    m_TrackAreaIndices[37] = 60;
    m_TrackAreaIndices[38] = 61;
    m_TrackAreaIndices[39] = 21;
    m_TrackAreaIndices[40] = 20;
    m_TrackAreaIndices[41] = 60;
    m_TrackAreaIndices[42] = 20;
    m_TrackAreaIndices[43] = 59;
    m_TrackAreaIndices[44] = 60;
    m_TrackAreaIndices[45] = 20;
    m_TrackAreaIndices[46] = 58;
    m_TrackAreaIndices[47] = 59;
    m_TrackAreaIndices[48] = 20;
    m_TrackAreaIndices[49] = 19;
    m_TrackAreaIndices[50] = 58;
    m_TrackAreaIndices[51] = 19;
    m_TrackAreaIndices[52] = 57;
    m_TrackAreaIndices[53] = 58;
    m_TrackAreaIndices[54] = 19;
    m_TrackAreaIndices[55] = 56;
    m_TrackAreaIndices[56] = 57;
    m_TrackAreaIndices[57] = 19;
    m_TrackAreaIndices[58] = 18;
    m_TrackAreaIndices[59] = 56;
    m_TrackAreaIndices[60] = 18;
    m_TrackAreaIndices[61] = 55;
    m_TrackAreaIndices[62] = 56;
    m_TrackAreaIndices[63] = 18;
    m_TrackAreaIndices[64] = 54;
    m_TrackAreaIndices[65] = 55;
    m_TrackAreaIndices[66] = 18;
    m_TrackAreaIndices[67] = 17;
    m_TrackAreaIndices[68] = 54;
    m_TrackAreaIndices[69] = 17;
    m_TrackAreaIndices[70] = 53;
    m_TrackAreaIndices[71] = 54;
    m_TrackAreaIndices[72] = 17;
    m_TrackAreaIndices[73] = 16;
    m_TrackAreaIndices[74] = 53;
    m_TrackAreaIndices[75] = 16;
    m_TrackAreaIndices[76] = 52;
    m_TrackAreaIndices[77] = 53;
    m_TrackAreaIndices[78] = 16;
    m_TrackAreaIndices[79] = 51;
    m_TrackAreaIndices[80] = 52;
    m_TrackAreaIndices[81] = 16;
    m_TrackAreaIndices[82] = 15;
    m_TrackAreaIndices[83] = 51;
    m_TrackAreaIndices[84] = 15;
    m_TrackAreaIndices[85] = 50;
    m_TrackAreaIndices[86] = 51;
    m_TrackAreaIndices[87] = 15;
    m_TrackAreaIndices[88] = 14;
    m_TrackAreaIndices[89] = 50;
    m_TrackAreaIndices[90] = 14;
    m_TrackAreaIndices[91] = 49;
    m_TrackAreaIndices[92] = 50;
    m_TrackAreaIndices[93] = 14;
    m_TrackAreaIndices[94] = 48;
    m_TrackAreaIndices[95] = 49;
    m_TrackAreaIndices[96] = 14;
    m_TrackAreaIndices[97] = 13;
    m_TrackAreaIndices[98] = 48;
    m_TrackAreaIndices[99] = 13;
    m_TrackAreaIndices[100] = 47;
    m_TrackAreaIndices[101] = 48;
    m_TrackAreaIndices[102] = 13;
    m_TrackAreaIndices[103] = 12;
    m_TrackAreaIndices[104] = 47;
    m_TrackAreaIndices[105] = 12;
    m_TrackAreaIndices[106] = 46;
    m_TrackAreaIndices[107] = 47;
    m_TrackAreaIndices[108] = 12;
    m_TrackAreaIndices[109] = 45;
    m_TrackAreaIndices[110] = 46;
    m_TrackAreaIndices[111] = 12;
    m_TrackAreaIndices[112] = 11;
    m_TrackAreaIndices[113] = 45;
    m_TrackAreaIndices[114] = 11;
    m_TrackAreaIndices[115] = 44;
    m_TrackAreaIndices[116] = 45;
    m_TrackAreaIndices[117] = 11;
    m_TrackAreaIndices[118] = 10;
    m_TrackAreaIndices[119] = 44;
    m_TrackAreaIndices[120] = 10;
    m_TrackAreaIndices[121] = 43;
    m_TrackAreaIndices[122] = 44;
    m_TrackAreaIndices[123] = 10;
    m_TrackAreaIndices[124] = 42;
    m_TrackAreaIndices[125] = 43;
    m_TrackAreaIndices[126] = 10;
    m_TrackAreaIndices[127] = 41;
    m_TrackAreaIndices[128] = 42;
    m_TrackAreaIndices[129] = 10;
    m_TrackAreaIndices[130] = 9;
    m_TrackAreaIndices[131] = 41;
    m_TrackAreaIndices[132] = 9;
    m_TrackAreaIndices[133] = 40;
    m_TrackAreaIndices[134] = 41;
    m_TrackAreaIndices[135] = 9;
    m_TrackAreaIndices[136] = 39;
    m_TrackAreaIndices[137] = 40;
    m_TrackAreaIndices[138] = 9;
    m_TrackAreaIndices[139] = 8;
    m_TrackAreaIndices[140] = 39;
    m_TrackAreaIndices[141] = 8;
    m_TrackAreaIndices[142] = 38;
    m_TrackAreaIndices[143] = 39;
    m_TrackAreaIndices[144] = 8;
    m_TrackAreaIndices[145] = 37;
    m_TrackAreaIndices[146] = 38;
    m_TrackAreaIndices[147] = 8;
    m_TrackAreaIndices[148] = 7;
    m_TrackAreaIndices[149] = 37;
    m_TrackAreaIndices[150] = 7;
    m_TrackAreaIndices[151] = 36;
    m_TrackAreaIndices[152] = 37;
    m_TrackAreaIndices[153] = 7;
    m_TrackAreaIndices[154] = 6;
    m_TrackAreaIndices[155] = 36;
    m_TrackAreaIndices[156] = 6;
    m_TrackAreaIndices[157] = 35;
    m_TrackAreaIndices[158] = 36;
    m_TrackAreaIndices[159] = 6;
    m_TrackAreaIndices[160] = 34;
    m_TrackAreaIndices[161] = 35;
    m_TrackAreaIndices[162] = 6;
    m_TrackAreaIndices[163] = 5;
    m_TrackAreaIndices[164] = 34;
    m_TrackAreaIndices[165] = 5;
    m_TrackAreaIndices[166] = 33;
    m_TrackAreaIndices[167] = 34;
    m_TrackAreaIndices[168] = 5;
    m_TrackAreaIndices[169] = 4;
    m_TrackAreaIndices[170] = 33;
    m_TrackAreaIndices[171] = 4;
    m_TrackAreaIndices[172] = 32;
    m_TrackAreaIndices[173] = 33;
    m_TrackAreaIndices[174] = 4;
    m_TrackAreaIndices[175] = 31;
    m_TrackAreaIndices[176] = 32;
    m_TrackAreaIndices[177] = 4;
    m_TrackAreaIndices[178] = 3;
    m_TrackAreaIndices[179] = 31;
    m_TrackAreaIndices[180] = 3;
    m_TrackAreaIndices[181] = 30;
    m_TrackAreaIndices[182] = 31;
    m_TrackAreaIndices[183] = 3;
    m_TrackAreaIndices[184] = 29;
    m_TrackAreaIndices[185] = 30;
    m_TrackAreaIndices[186] = 3;
    m_TrackAreaIndices[187] = 2;
    m_TrackAreaIndices[188] = 29;
    m_TrackAreaIndices[189] = 2;
    m_TrackAreaIndices[190] = 28;
    m_TrackAreaIndices[191] = 29;
    m_TrackAreaIndices[192] = 2;
    m_TrackAreaIndices[193] = 1;
    m_TrackAreaIndices[194] = 28;
    m_TrackAreaIndices[195] = 1;
    m_TrackAreaIndices[196] = 27;
    m_TrackAreaIndices[197] = 28;
    m_TrackAreaIndices[198] = 1;
    m_TrackAreaIndices[199] = 0;
    m_TrackAreaIndices[200] = 27;
    m_TrackAreaIndices[201] = 0;
    m_TrackAreaIndices[202] = 26;
    m_TrackAreaIndices[203] = 27;

}

void Track::Update(Timestep ts)
{

}

bool Track::PointOnTrack(Point p)
{
    int triangleVertexCount = sizeof(m_TrackAreaIndices) / (sizeof(unsigned int));
    for (int i = 0; i < triangleVertexCount; i += 3)
    {
        Point v1 = m_TrackVertices[m_TrackAreaIndices[i]];
        Point v2 = m_TrackVertices[m_TrackAreaIndices[i + 1]];
        Point v3 = m_TrackVertices[m_TrackAreaIndices[i + 2]];

        if (PointInsideTriangle(p, v1, v2, v3))
        {
            return true;
        }
    }
    return false;
}

void Track::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    Draw(m_DrawMode, display, camera);
}

void Track::Draw(DrawMode mode, Adafruit_SSD1306& display, Camera& camera)
{
    switch(mode)
    {
    case(DrawMode::Lines):          DrawLines(display, camera); return;
    case(DrawMode::Fill):      DrawTriangles(display, camera); return;
    case(DrawMode::Wireframe):      DrawWireframe(display, camera); return;
    }

    Serial << "Error: Unkown draw mode!" << endl;
}

void Track::DrawLines(Adafruit_SSD1306& display, Camera& camera)
{
    // the number of lines is half the number of indices
    int numIndices = sizeof(m_TrackEdgeIndices) / sizeof(unsigned int);

    for (int i = 0; i < numIndices; i += 2)
    {
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());

        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});

        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
    }
}

void Track::DrawTriangles(Adafruit_SSD1306& display, Camera& camera)
{
    // the number of lines is half the number of indices
    int numIndices = sizeof(m_TrackAreaIndices) / sizeof(unsigned int);

    for (int i = 0; i < numIndices; i += 3)
    {
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());
        Point p3 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 2]]), camera.GetPosition(), camera.GetRotation());

        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});
        p3 = Point({64 + p3.X(), 32 - p3.Y(), 0});

        display.fillTriangle(p1.X(), p1.Y(), p2.X(), p2.Y(), p3.X(), p3.Y(), WHITE);
    }
}

void Track::DrawWireframe(Adafruit_SSD1306& display, Camera& camera)
{
    // the number of lines is half the number of indices
    int numIndices = sizeof(m_TrackAreaIndices) / sizeof(unsigned int);

    for (int i = 0; i < numIndices; i += 3)
    {
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());
        Point p3 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 2]]), camera.GetPosition(), camera.GetRotation());

        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});
        p3 = Point({64 + p3.X(), 32 - p3.Y(), 0});

        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
        display.drawLine(p1.X(), p1.Y(), p3.X(), p3.Y(), WHITE);
        display.drawLine(p2.X(), p2.Y(), p3.X(), p3.Y(), WHITE);

    }
}
