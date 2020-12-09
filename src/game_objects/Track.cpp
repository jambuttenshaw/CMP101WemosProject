#include "Track.h"

#include "core/MathsUtility.h"

#include <Streaming.h>

// default constructor
// initialises pos and rot as 0
Track::Track()
    : m_TrackTranslation(Point()), m_TrackRotation(Rotation())
{
    CreateTrack();
}

// you can initialise the track with a position too
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

    /*

    These values were not inputted by hand (thankfully).

    I built a track geometry generation tool in Unity that exports the C++ code below
    You can view this track builder tool at https://github.com/jambuttenshaw/WemosTrackBuilder

    It allows me to click and drag the vertices of the track, and once I am happy with the layout
    it works out how the vertices should be joined together in order to draw the edges
    and fill the area of the track.

    */

   // C# Script generated code below:

    m_TrackVertices[0] = Point({-34, 0, 0});
    m_TrackVertices[1] = Point({-34, 50, 0});
    m_TrackVertices[2] = Point({-34, 100, 0});
    m_TrackVertices[3] = Point({-35, 120, 0});
    m_TrackVertices[4] = Point({-43, 147, 0});
    m_TrackVertices[5] = Point({-66, 165, 0});
    m_TrackVertices[6] = Point({-103, 169, 0});
    m_TrackVertices[7] = Point({-150, 162, 0});
    m_TrackVertices[8] = Point({-177, 147, 0});
    m_TrackVertices[9] = Point({-189, 129, 0});
    m_TrackVertices[10] = Point({-192, 104, 0});
    m_TrackVertices[11] = Point({-193, 73, 0});
    m_TrackVertices[12] = Point({-194, 36, 0});
    m_TrackVertices[13] = Point({-194, 17, 0});
    m_TrackVertices[14] = Point({-200, 5, 0});
    m_TrackVertices[15] = Point({-214, 0, 0});
    m_TrackVertices[16] = Point({-233, 0, 0});
    m_TrackVertices[17] = Point({-258, -1, 0});
    m_TrackVertices[18] = Point({-277, -1, 0});
    m_TrackVertices[19] = Point({-288, -1, 0});
    m_TrackVertices[20] = Point({-304, -6, 0});
    m_TrackVertices[21] = Point({-308, -15, 0});
    m_TrackVertices[22] = Point({-309, -26, 0});
    m_TrackVertices[23] = Point({-310, -46, 0});
    m_TrackVertices[24] = Point({-311, -68, 0});
    m_TrackVertices[25] = Point({-304, -78, 0});
    m_TrackVertices[26] = Point({-289, -85, 0});
    m_TrackVertices[27] = Point({-264, -85, 0});
    m_TrackVertices[28] = Point({-221, -86, 0});
    m_TrackVertices[29] = Point({-180, -87, 0});
    m_TrackVertices[30] = Point({-140, -86, 0});
    m_TrackVertices[31] = Point({-96, -87, 0});
    m_TrackVertices[32] = Point({-69, -88, 0});
    m_TrackVertices[33] = Point({-52, -82, 0});
    m_TrackVertices[34] = Point({-38, -72, 0});
    m_TrackVertices[35] = Point({-34, -57, 0});
    m_TrackVertices[36] = Point({-34, -32, 0});
    m_TrackVertices[37] = Point({29, 0, 0});
    m_TrackVertices[38] = Point({28, 49, 0});
    m_TrackVertices[39] = Point({28, 101, 0});
    m_TrackVertices[40] = Point({25, 124, 0});
    m_TrackVertices[41] = Point({14, 151, 0});
    m_TrackVertices[42] = Point({-6, 172, 0});
    m_TrackVertices[43] = Point({-37, 191, 0});
    m_TrackVertices[44] = Point({-77, 206, 0});
    m_TrackVertices[45] = Point({-121, 207, 0});
    m_TrackVertices[46] = Point({-166, 200, 0});
    m_TrackVertices[47] = Point({-200, 180, 0});
    m_TrackVertices[48] = Point({-225, 150, 0});
    m_TrackVertices[49] = Point({-237, 117, 0});
    m_TrackVertices[50] = Point({-239, 76, 0});
    m_TrackVertices[51] = Point({-239, 47, 0});
    m_TrackVertices[52] = Point({-240, 38, 0});
    m_TrackVertices[53] = Point({-245, 33, 0});
    m_TrackVertices[54] = Point({-256, 32, 0});
    m_TrackVertices[55] = Point({-282, 32, 0});
    m_TrackVertices[56] = Point({-308, 32, 0});
    m_TrackVertices[57] = Point({-326, 29, 0});
    m_TrackVertices[58] = Point({-342, 17, 0});
    m_TrackVertices[59] = Point({-347, -6, 0});
    m_TrackVertices[60] = Point({-350, -33, 0});
    m_TrackVertices[61] = Point({-351, -60, 0});
    m_TrackVertices[62] = Point({-349, -87, 0});
    m_TrackVertices[63] = Point({-340, -100, 0});
    m_TrackVertices[64] = Point({-329, -111, 0});
    m_TrackVertices[65] = Point({-311, -118, 0});
    m_TrackVertices[66] = Point({-282, -126, 0});
    m_TrackVertices[67] = Point({-242, -124, 0});
    m_TrackVertices[68] = Point({-202, -124, 0});
    m_TrackVertices[69] = Point({-120, -124, 0});
    m_TrackVertices[70] = Point({-70, -125, 0});
    m_TrackVertices[71] = Point({-31, -120, 0});
    m_TrackVertices[72] = Point({7, -107, 0});
    m_TrackVertices[73] = Point({27, -85, 0});
    m_TrackVertices[74] = Point({30, -32, 0});


    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 36;
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
    m_TrackEdgeIndices[52] = 25;
    m_TrackEdgeIndices[53] = 26;
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
    m_TrackEdgeIndices[74] = 37;
    m_TrackEdgeIndices[75] = 74;
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
    m_TrackEdgeIndices[136] = 67;
    m_TrackEdgeIndices[137] = 68;
    m_TrackEdgeIndices[138] = 68;
    m_TrackEdgeIndices[139] = 69;
    m_TrackEdgeIndices[140] = 69;
    m_TrackEdgeIndices[141] = 70;
    m_TrackEdgeIndices[142] = 70;
    m_TrackEdgeIndices[143] = 71;
    m_TrackEdgeIndices[144] = 71;
    m_TrackEdgeIndices[145] = 72;
    m_TrackEdgeIndices[146] = 72;
    m_TrackEdgeIndices[147] = 73;
    m_TrackEdgeIndices[148] = 73;
    m_TrackEdgeIndices[149] = 74;

    m_TrackAreaIndices[0] = 0;
    m_TrackAreaIndices[1] = 74;
    m_TrackAreaIndices[2] = 37;
    m_TrackAreaIndices[3] = 0;
    m_TrackAreaIndices[4] = 36;
    m_TrackAreaIndices[5] = 74;
    m_TrackAreaIndices[6] = 36;
    m_TrackAreaIndices[7] = 35;
    m_TrackAreaIndices[8] = 74;
    m_TrackAreaIndices[9] = 35;
    m_TrackAreaIndices[10] = 73;
    m_TrackAreaIndices[11] = 74;
    m_TrackAreaIndices[12] = 35;
    m_TrackAreaIndices[13] = 34;
    m_TrackAreaIndices[14] = 73;
    m_TrackAreaIndices[15] = 34;
    m_TrackAreaIndices[16] = 33;
    m_TrackAreaIndices[17] = 73;
    m_TrackAreaIndices[18] = 33;
    m_TrackAreaIndices[19] = 72;
    m_TrackAreaIndices[20] = 73;
    m_TrackAreaIndices[21] = 33;
    m_TrackAreaIndices[22] = 32;
    m_TrackAreaIndices[23] = 72;
    m_TrackAreaIndices[24] = 32;
    m_TrackAreaIndices[25] = 71;
    m_TrackAreaIndices[26] = 72;
    m_TrackAreaIndices[27] = 32;
    m_TrackAreaIndices[28] = 31;
    m_TrackAreaIndices[29] = 71;
    m_TrackAreaIndices[30] = 31;
    m_TrackAreaIndices[31] = 70;
    m_TrackAreaIndices[32] = 71;
    m_TrackAreaIndices[33] = 31;
    m_TrackAreaIndices[34] = 30;
    m_TrackAreaIndices[35] = 70;
    m_TrackAreaIndices[36] = 30;
    m_TrackAreaIndices[37] = 69;
    m_TrackAreaIndices[38] = 70;
    m_TrackAreaIndices[39] = 30;
    m_TrackAreaIndices[40] = 29;
    m_TrackAreaIndices[41] = 69;
    m_TrackAreaIndices[42] = 29;
    m_TrackAreaIndices[43] = 68;
    m_TrackAreaIndices[44] = 69;
    m_TrackAreaIndices[45] = 29;
    m_TrackAreaIndices[46] = 28;
    m_TrackAreaIndices[47] = 68;
    m_TrackAreaIndices[48] = 28;
    m_TrackAreaIndices[49] = 67;
    m_TrackAreaIndices[50] = 68;
    m_TrackAreaIndices[51] = 28;
    m_TrackAreaIndices[52] = 27;
    m_TrackAreaIndices[53] = 67;
    m_TrackAreaIndices[54] = 27;
    m_TrackAreaIndices[55] = 66;
    m_TrackAreaIndices[56] = 67;
    m_TrackAreaIndices[57] = 27;
    m_TrackAreaIndices[58] = 26;
    m_TrackAreaIndices[59] = 66;
    m_TrackAreaIndices[60] = 26;
    m_TrackAreaIndices[61] = 65;
    m_TrackAreaIndices[62] = 66;
    m_TrackAreaIndices[63] = 26;
    m_TrackAreaIndices[64] = 25;
    m_TrackAreaIndices[65] = 65;
    m_TrackAreaIndices[66] = 25;
    m_TrackAreaIndices[67] = 64;
    m_TrackAreaIndices[68] = 65;
    m_TrackAreaIndices[69] = 25;
    m_TrackAreaIndices[70] = 24;
    m_TrackAreaIndices[71] = 64;
    m_TrackAreaIndices[72] = 24;
    m_TrackAreaIndices[73] = 63;
    m_TrackAreaIndices[74] = 64;
    m_TrackAreaIndices[75] = 24;
    m_TrackAreaIndices[76] = 23;
    m_TrackAreaIndices[77] = 63;
    m_TrackAreaIndices[78] = 23;
    m_TrackAreaIndices[79] = 62;
    m_TrackAreaIndices[80] = 63;
    m_TrackAreaIndices[81] = 23;
    m_TrackAreaIndices[82] = 22;
    m_TrackAreaIndices[83] = 62;
    m_TrackAreaIndices[84] = 22;
    m_TrackAreaIndices[85] = 61;
    m_TrackAreaIndices[86] = 62;
    m_TrackAreaIndices[87] = 22;
    m_TrackAreaIndices[88] = 21;
    m_TrackAreaIndices[89] = 61;
    m_TrackAreaIndices[90] = 21;
    m_TrackAreaIndices[91] = 20;
    m_TrackAreaIndices[92] = 61;
    m_TrackAreaIndices[93] = 20;
    m_TrackAreaIndices[94] = 60;
    m_TrackAreaIndices[95] = 61;
    m_TrackAreaIndices[96] = 20;
    m_TrackAreaIndices[97] = 19;
    m_TrackAreaIndices[98] = 60;
    m_TrackAreaIndices[99] = 19;
    m_TrackAreaIndices[100] = 59;
    m_TrackAreaIndices[101] = 60;
    m_TrackAreaIndices[102] = 19;
    m_TrackAreaIndices[103] = 18;
    m_TrackAreaIndices[104] = 59;
    m_TrackAreaIndices[105] = 18;
    m_TrackAreaIndices[106] = 58;
    m_TrackAreaIndices[107] = 59;
    m_TrackAreaIndices[108] = 18;
    m_TrackAreaIndices[109] = 17;
    m_TrackAreaIndices[110] = 58;
    m_TrackAreaIndices[111] = 17;
    m_TrackAreaIndices[112] = 57;
    m_TrackAreaIndices[113] = 58;
    m_TrackAreaIndices[114] = 17;
    m_TrackAreaIndices[115] = 56;
    m_TrackAreaIndices[116] = 57;
    m_TrackAreaIndices[117] = 17;
    m_TrackAreaIndices[118] = 16;
    m_TrackAreaIndices[119] = 56;
    m_TrackAreaIndices[120] = 16;
    m_TrackAreaIndices[121] = 55;
    m_TrackAreaIndices[122] = 56;
    m_TrackAreaIndices[123] = 16;
    m_TrackAreaIndices[124] = 15;
    m_TrackAreaIndices[125] = 55;
    m_TrackAreaIndices[126] = 15;
    m_TrackAreaIndices[127] = 14;
    m_TrackAreaIndices[128] = 55;
    m_TrackAreaIndices[129] = 14;
    m_TrackAreaIndices[130] = 54;
    m_TrackAreaIndices[131] = 55;
    m_TrackAreaIndices[132] = 14;
    m_TrackAreaIndices[133] = 13;
    m_TrackAreaIndices[134] = 54;
    m_TrackAreaIndices[135] = 13;
    m_TrackAreaIndices[136] = 53;
    m_TrackAreaIndices[137] = 54;
    m_TrackAreaIndices[138] = 13;
    m_TrackAreaIndices[139] = 52;
    m_TrackAreaIndices[140] = 53;
    m_TrackAreaIndices[141] = 13;
    m_TrackAreaIndices[142] = 51;
    m_TrackAreaIndices[143] = 52;
    m_TrackAreaIndices[144] = 13;
    m_TrackAreaIndices[145] = 12;
    m_TrackAreaIndices[146] = 51;
    m_TrackAreaIndices[147] = 12;
    m_TrackAreaIndices[148] = 50;
    m_TrackAreaIndices[149] = 51;
    m_TrackAreaIndices[150] = 12;
    m_TrackAreaIndices[151] = 11;
    m_TrackAreaIndices[152] = 50;
    m_TrackAreaIndices[153] = 11;
    m_TrackAreaIndices[154] = 49;
    m_TrackAreaIndices[155] = 50;
    m_TrackAreaIndices[156] = 11;
    m_TrackAreaIndices[157] = 10;
    m_TrackAreaIndices[158] = 49;
    m_TrackAreaIndices[159] = 10;
    m_TrackAreaIndices[160] = 48;
    m_TrackAreaIndices[161] = 49;
    m_TrackAreaIndices[162] = 10;
    m_TrackAreaIndices[163] = 9;
    m_TrackAreaIndices[164] = 48;
    m_TrackAreaIndices[165] = 9;
    m_TrackAreaIndices[166] = 47;
    m_TrackAreaIndices[167] = 48;
    m_TrackAreaIndices[168] = 9;
    m_TrackAreaIndices[169] = 8;
    m_TrackAreaIndices[170] = 47;
    m_TrackAreaIndices[171] = 8;
    m_TrackAreaIndices[172] = 46;
    m_TrackAreaIndices[173] = 47;
    m_TrackAreaIndices[174] = 8;
    m_TrackAreaIndices[175] = 7;
    m_TrackAreaIndices[176] = 46;
    m_TrackAreaIndices[177] = 7;
    m_TrackAreaIndices[178] = 45;
    m_TrackAreaIndices[179] = 46;
    m_TrackAreaIndices[180] = 7;
    m_TrackAreaIndices[181] = 6;
    m_TrackAreaIndices[182] = 45;
    m_TrackAreaIndices[183] = 6;
    m_TrackAreaIndices[184] = 44;
    m_TrackAreaIndices[185] = 45;
    m_TrackAreaIndices[186] = 6;
    m_TrackAreaIndices[187] = 5;
    m_TrackAreaIndices[188] = 44;
    m_TrackAreaIndices[189] = 5;
    m_TrackAreaIndices[190] = 43;
    m_TrackAreaIndices[191] = 44;
    m_TrackAreaIndices[192] = 5;
    m_TrackAreaIndices[193] = 4;
    m_TrackAreaIndices[194] = 43;
    m_TrackAreaIndices[195] = 4;
    m_TrackAreaIndices[196] = 42;
    m_TrackAreaIndices[197] = 43;
    m_TrackAreaIndices[198] = 4;
    m_TrackAreaIndices[199] = 3;
    m_TrackAreaIndices[200] = 42;
    m_TrackAreaIndices[201] = 3;
    m_TrackAreaIndices[202] = 41;
    m_TrackAreaIndices[203] = 42;
    m_TrackAreaIndices[204] = 3;
    m_TrackAreaIndices[205] = 2;
    m_TrackAreaIndices[206] = 41;
    m_TrackAreaIndices[207] = 2;
    m_TrackAreaIndices[208] = 40;
    m_TrackAreaIndices[209] = 41;
    m_TrackAreaIndices[210] = 2;
    m_TrackAreaIndices[211] = 39;
    m_TrackAreaIndices[212] = 40;
    m_TrackAreaIndices[213] = 2;
    m_TrackAreaIndices[214] = 1;
    m_TrackAreaIndices[215] = 39;
    m_TrackAreaIndices[216] = 1;
    m_TrackAreaIndices[217] = 38;
    m_TrackAreaIndices[218] = 39;
    m_TrackAreaIndices[219] = 1;
    m_TrackAreaIndices[220] = 0;
    m_TrackAreaIndices[221] = 38;
    m_TrackAreaIndices[222] = 0;
    m_TrackAreaIndices[223] = 37;
    m_TrackAreaIndices[224] = 38;

    // End of C# script generated code



    // calculate the centroid of the track
    // the centroid is the average of all the vertices that make up the track
    m_TrackCentroid = Point();
    // calculate the number of vertices in the track
    unsigned int numVertices = sizeof(m_TrackVertices) / sizeof(m_TrackVertices[0]);
    for (unsigned int i = 0; i < numVertices; i++)
    {
        // add this vertices position to the centroid
        m_TrackCentroid += m_TrackVertices[i];
    }
    // to get the centroid we divide the sum of the vertices by the quantity
    m_TrackCentroid /= numVertices;    

    // find the finish line vector
    m_FinishLine = m_TrackVertices[m_StartLineVertices[1]] - m_TrackVertices[m_StartLineVertices[0]];
    // and its magnitude
    m_FinishLineLength = m_FinishLine.Magnitude();

    // get direction vector from centroid to the start line
    m_CentroidToStartLine = Normalize(m_TrackVertices[m_StartLineVertices[0]] - m_TrackCentroid);
}


bool Track::PointOnTrack(Point p)
{
    // checks if the point P is on or off of the track

    // since the track is constructed out of triangles,
    // we can iterate through those triangles and check to see if the 
    // point is inside the triangle
    // if the point is inside any triangle then the car is on the track
    // otherwise the car cannot be on the track

    // get the number of triangle vertices that make up the track
    int triangleVertexCount = sizeof(m_TrackAreaIndices) / (sizeof(unsigned int));
    for (int i = 0; i < triangleVertexCount; i += 3)
    {
        // get the vertices of the triangle
        Point v1 = m_TrackVertices[m_TrackAreaIndices[i]];
        Point v2 = m_TrackVertices[m_TrackAreaIndices[i + 1]];
        Point v3 = m_TrackVertices[m_TrackAreaIndices[i + 2]];

        // check to see if the point is inside this triangle
        if (PointInsideTriangle(p, v1, v2, v3))
        {
            // if it is, the point is on the track; return true
            return true;
        }
    }
    // the point is not inside any of the triangles so we should return false
    return false;
}

bool Track::CrossingFinishLine(Point p)
{
    // check to see if the point is close enough to the finish line to be considered crossing it

    // take the component of the finish line vector in the direction of the finish line to the point
    // and if the difference between that length and the length of the finish line is less than our
    // threshold, the point can be considered crossing the finish line
    Point toPoint = Normalize(p - m_TrackVertices[m_StartLineVertices[0]]);
    float dot = toPoint.DotProduct(m_FinishLine);
    return fabs(dot - m_FinishLineLength) < m_CrossingLineThreshold;
}

bool Track::AtAngularHalfway(Point p)
{
    // checks if the angle between the start line and the point with respect to the centroid of the track is approximately pi.

    // get the direction from the centroid to p
    Point centroidToP = Normalize(p - m_TrackCentroid);
    // get the component of the centroid-to-start vector in the direction of the centroid-to-p vector
    float dot = centroidToP.DotProduct(m_CentroidToStartLine);
    // if it is exactly halfway, dot would be -1, but we allow a small margin for error here
    return fabs(dot + 1) < m_HalfwayThreshold;
}

void Track::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    // an overload of draw that uses the tracks stored default draw mode
    Draw(m_DrawMode, display, camera);
}

void Track::Draw(DrawMode mode, Adafruit_SSD1306& display, Camera& camera)
{

    /*
    Normally, this sort of stuff would get done in parallel on a GPU
    Unfortunately the Wemos can't do that.

    Where on a regular computer, all of the vertices would be processed in parallel and it would
    be super fast, we need to do them in series here.
    */

    // switch on the draw mode
    switch(mode)
    {
    // draw the edges of the track
    case(DrawMode::Lines):          DrawLines(display, camera); break;
    // draw the track as filled triangles
    case(DrawMode::Fill):           DrawTriangles(display, camera); break;
    // draw the track as non-filled triangles
    case(DrawMode::Wireframe):      DrawWireframe(display, camera); break;
    // just in case something goes wrong
    default:                        Serial << "Error: Unkown draw mode!" << endl;
    }

    // Draw the start line
    DrawFinishLine(display, camera);
    
}

void Track::DrawLines(Adafruit_SSD1306& display, Camera& camera)
{
    // the number of lines is half the number of indices
    // we need the number of indices first
    int numIndices = sizeof(m_TrackEdgeIndices) / sizeof(unsigned int);

    // repeat for the number of edges
    // where i is the current index
    // there are 2 indices per edge, therefore we go up in increments of 2
    for (int i = 0; i < numIndices; i += 2)
    {
        // get the 2 ends of the line

        // the points are stored in model space at the moment
        // they need to be transformed to screen space ultimately

        // we want to apply the transform (rotation and translation) of the track
        // followed inverse transform of the camera to get the point in world space
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());

        // and from world space we can use the dimensions of the screen to convert to screen space
        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});

        // then draw this line onto the screen using the screen space coordinates
        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
    }
}

void Track::DrawTriangles(Adafruit_SSD1306& display, Camera& camera)
{
    // get the number of indices in the triangles array
    int numIndices = sizeof(m_TrackAreaIndices) / sizeof(unsigned int);

    // repeat for the number of triangles
    // where i is the current vertex index
    // there are 3 indices per triangle, therefore we go up in increments of 3
    for (int i = 0; i < numIndices; i += 3)
    {
        // get the 3 vertices of the triangle

        // the points are stored in model space at the moment
        // they need to be transformed to screen space ultimately

        // we want to apply the transform (rotation and translation) of the track
        // followed inverse transform of the camera to get the point in world space
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());
        Point p3 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 2]]), camera.GetPosition(), camera.GetRotation());

        // and from world space we can use the dimensions of the screen to convert to screen space
        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});
        p3 = Point({64 + p3.X(), 32 - p3.Y(), 0});

        // then draw this triangle onto the screen using the screen space coordinates
        display.fillTriangle(p1.X(), p1.Y(), p2.X(), p2.Y(), p3.X(), p3.Y(), WHITE);
    }
}

void Track::DrawWireframe(Adafruit_SSD1306& display, Camera& camera)
{
    // the number of lines is half the number of indices
    int numIndices = sizeof(m_TrackAreaIndices) / sizeof(unsigned int);

    for (int i = 0; i < numIndices; i += 3)
    {
        // get the vertices of the triangle and transform them to world space using the tracks transform and the camera
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());
        Point p3 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackAreaIndices[i + 2]]), camera.GetPosition(), camera.GetRotation());

        // transform the points to screen space
        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});
        p3 = Point({64 + p3.X(), 32 - p3.Y(), 0});


        // draw the edges of the triangle
        // as each triangle will share edges with at most 1 neighbour,
        // most edges will get drawn multiple times
        // however since wireframe mode is only for debug purposes
        // im not too bothered about optimizing it
        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
        display.drawLine(p1.X(), p1.Y(), p3.X(), p3.Y(), WHITE);
        display.drawLine(p2.X(), p2.Y(), p3.X(), p3.Y(), WHITE);
    }
}

void Track::DrawFinishLine(Adafruit_SSD1306& display, Camera& camera)
{
    // get the edges of the finish line and transform them into world space using the tracks transform and the camera
    Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_StartLineVertices[0]]), camera.GetPosition(), camera.GetRotation());
    Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_StartLineVertices[1]]), camera.GetPosition(), camera.GetRotation());

    // transform the vertices to screen space
    p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
    p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});

    // draw the finish line onto the screen
    // use the inverse color as we want the finish line to stand out from the track
    display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), INVERSE);
}
