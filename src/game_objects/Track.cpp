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

    m_TrackVertices[0] = Point({-29, -2, 0});
    m_TrackVertices[1] = Point({27, -1, 0});
    m_TrackVertices[2] = Point({-30, -32, 0});
    m_TrackVertices[3] = Point({-27, -76, 0});
    m_TrackVertices[4] = Point({-24, -117, 0});
    m_TrackVertices[5] = Point({-14, -147, 0});
    m_TrackVertices[6] = Point({0, -174, 0});
    m_TrackVertices[7] = Point({27, -198, 0});
    m_TrackVertices[8] = Point({69, -226, 0});
    m_TrackVertices[9] = Point({93, -245, 0});
    m_TrackVertices[10] = Point({99, -257, 0});
    m_TrackVertices[11] = Point({92, -275, 0});
    m_TrackVertices[12] = Point({80, -281, 0});
    m_TrackVertices[13] = Point({62, -280, 0});
    m_TrackVertices[14] = Point({43, -270, 0});
    m_TrackVertices[15] = Point({18, -256, 0});
    m_TrackVertices[16] = Point({-12, -234, 0});
    m_TrackVertices[17] = Point({-45, -206, 0});
    m_TrackVertices[18] = Point({-61, -182, 0});
    m_TrackVertices[19] = Point({-70, -156, 0});
    m_TrackVertices[20] = Point({-77, -129, 0});
    m_TrackVertices[21] = Point({-82, -114, 0});
    m_TrackVertices[22] = Point({-92, -99, 0});
    m_TrackVertices[23] = Point({-110, -95, 0});
    m_TrackVertices[24] = Point({-140, -91, 0});
    m_TrackVertices[25] = Point({-181, -90, 0});
    m_TrackVertices[26] = Point({-214, -91, 0});
    m_TrackVertices[27] = Point({-240, -91, 0});
    m_TrackVertices[28] = Point({-260, -95, 0});
    m_TrackVertices[29] = Point({-273, -109, 0});
    m_TrackVertices[30] = Point({-280, -132, 0});
    m_TrackVertices[31] = Point({-280, -158, 0});
    m_TrackVertices[32] = Point({-277, -182, 0});
    m_TrackVertices[33] = Point({-279, -200, 0});
    m_TrackVertices[34] = Point({-290, -210, 0});
    m_TrackVertices[35] = Point({-310, -216, 0});
    m_TrackVertices[36] = Point({-337, -218, 0});
    m_TrackVertices[37] = Point({-368, -219, 0});
    m_TrackVertices[38] = Point({-396, -219, 0});
    m_TrackVertices[39] = Point({-424, -219, 0});
    m_TrackVertices[40] = Point({-443, -219, 0});
    m_TrackVertices[41] = Point({-451, -209, 0});
    m_TrackVertices[42] = Point({-456, -192, 0});
    m_TrackVertices[43] = Point({-464, -159, 0});
    m_TrackVertices[44] = Point({-463, -126, 0});
    m_TrackVertices[45] = Point({-464, -81, 0});
    m_TrackVertices[46] = Point({-465, -48, 0});
    m_TrackVertices[47] = Point({-463, -18, 0});
    m_TrackVertices[48] = Point({-453, 7, 0});
    m_TrackVertices[49] = Point({-425, 26, 0});
    m_TrackVertices[50] = Point({-398, 33, 0});
    m_TrackVertices[51] = Point({-371, 36, 0});
    m_TrackVertices[52] = Point({-351, 46, 0});
    m_TrackVertices[53] = Point({-342, 66, 0});
    m_TrackVertices[54] = Point({-339, 98, 0});
    m_TrackVertices[55] = Point({-339, 128, 0});
    m_TrackVertices[56] = Point({-327, 140, 0});
    m_TrackVertices[57] = Point({-308, 147, 0});
    m_TrackVertices[58] = Point({-291, 151, 0});
    m_TrackVertices[59] = Point({-259, 153, 0});
    m_TrackVertices[60] = Point({-212, 153, 0});
    m_TrackVertices[61] = Point({-186, 153, 0});
    m_TrackVertices[62] = Point({-163, 151, 0});
    m_TrackVertices[63] = Point({-153, 143, 0});
    m_TrackVertices[64] = Point({-138, 126, 0});
    m_TrackVertices[65] = Point({-138, 109, 0});
    m_TrackVertices[66] = Point({-137, 98, 0});
    m_TrackVertices[67] = Point({-126, 87, 0});
    m_TrackVertices[68] = Point({-104, 83, 0});
    m_TrackVertices[69] = Point({-68, 84, 0});
    m_TrackVertices[70] = Point({-49, 79, 0});
    m_TrackVertices[71] = Point({-37, 63, 0});
    m_TrackVertices[72] = Point({-31, 45, 0});
    m_TrackVertices[73] = Point({-30, 22, 0});
    m_TrackVertices[74] = Point({27, -34, 0});
    m_TrackVertices[75] = Point({27, -72, 0});
    m_TrackVertices[76] = Point({31, -98, 0});
    m_TrackVertices[77] = Point({41, -125, 0});
    m_TrackVertices[78] = Point({51, -152, 0});
    m_TrackVertices[79] = Point({66, -169, 0});
    m_TrackVertices[80] = Point({87, -188, 0});
    m_TrackVertices[81] = Point({117, -211, 0});
    m_TrackVertices[82] = Point({135, -231, 0});
    m_TrackVertices[83] = Point({145, -256, 0});
    m_TrackVertices[84] = Point({142, -280, 0});
    m_TrackVertices[85] = Point({134, -303, 0});
    m_TrackVertices[86] = Point({110, -318, 0});
    m_TrackVertices[87] = Point({77, -329, 0});
    m_TrackVertices[88] = Point({32, -325, 0});
    m_TrackVertices[89] = Point({-7, -309, 0});
    m_TrackVertices[90] = Point({-51, -276, 0});
    m_TrackVertices[91] = Point({-97, -240, 0});
    m_TrackVertices[92] = Point({-116, -211, 0});
    m_TrackVertices[93] = Point({-129, -179, 0});
    m_TrackVertices[94] = Point({-137, -148, 0});
    m_TrackVertices[95] = Point({-143, -135, 0});
    m_TrackVertices[96] = Point({-150, -131, 0});
    m_TrackVertices[97] = Point({-161, -132, 0});
    m_TrackVertices[98] = Point({-193, -131, 0});
    m_TrackVertices[99] = Point({-218, -137, 0});
    m_TrackVertices[100] = Point({-227, -157, 0});
    m_TrackVertices[101] = Point({-226, -180, 0});
    m_TrackVertices[102] = Point({-224, -200, 0});
    m_TrackVertices[103] = Point({-233, -223, 0});
    m_TrackVertices[104] = Point({-251, -242, 0});
    m_TrackVertices[105] = Point({-288, -262, 0});
    m_TrackVertices[106] = Point({-329, -275, 0});
    m_TrackVertices[107] = Point({-368, -272, 0});
    m_TrackVertices[108] = Point({-415, -276, 0});
    m_TrackVertices[109] = Point({-442, -273, 0});
    m_TrackVertices[110] = Point({-477, -264, 0});
    m_TrackVertices[111] = Point({-497, -247, 0});
    m_TrackVertices[112] = Point({-512, -219, 0});
    m_TrackVertices[113] = Point({-522, -184, 0});
    m_TrackVertices[114] = Point({-526, -149, 0});
    m_TrackVertices[115] = Point({-525, -96, 0});
    m_TrackVertices[116] = Point({-529, -34, 0});
    m_TrackVertices[117] = Point({-527, 11, 0});
    m_TrackVertices[118] = Point({-514, 36, 0});
    m_TrackVertices[119] = Point({-494, 59, 0});
    m_TrackVertices[120] = Point({-465, 73, 0});
    m_TrackVertices[121] = Point({-441, 76, 0});
    m_TrackVertices[122] = Point({-417, 81, 0});
    m_TrackVertices[123] = Point({-404, 90, 0});
    m_TrackVertices[124] = Point({-399, 110, 0});
    m_TrackVertices[125] = Point({-395, 132, 0});
    m_TrackVertices[126] = Point({-393, 158, 0});
    m_TrackVertices[127] = Point({-377, 173, 0});
    m_TrackVertices[128] = Point({-360, 187, 0});
    m_TrackVertices[129] = Point({-337, 200, 0});
    m_TrackVertices[130] = Point({-313, 206, 0});
    m_TrackVertices[131] = Point({-282, 211, 0});
    m_TrackVertices[132] = Point({-252, 215, 0});
    m_TrackVertices[133] = Point({-219, 213, 0});
    m_TrackVertices[134] = Point({-189, 212, 0});
    m_TrackVertices[135] = Point({-155, 209, 0});
    m_TrackVertices[136] = Point({-129, 203, 0});
    m_TrackVertices[137] = Point({-110, 187, 0});
    m_TrackVertices[138] = Point({-92, 170, 0});
    m_TrackVertices[139] = Point({-85, 152, 0});
    m_TrackVertices[140] = Point({-82, 138, 0});
    m_TrackVertices[141] = Point({-78, 129, 0});
    m_TrackVertices[142] = Point({-70, 123, 0});
    m_TrackVertices[143] = Point({-46, 123, 0});
    m_TrackVertices[144] = Point({-24, 121, 0});
    m_TrackVertices[145] = Point({-6, 114, 0});
    m_TrackVertices[146] = Point({6, 104, 0});
    m_TrackVertices[147] = Point({19, 88, 0});
    m_TrackVertices[148] = Point({26, 63, 0});
    m_TrackVertices[149] = Point({26, 37, 0});


    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 73;
    m_TrackEdgeIndices[2] = 1;
    m_TrackEdgeIndices[3] = 149;
    m_TrackEdgeIndices[4] = 0;
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
    m_TrackEdgeIndices[148] = 1;
    m_TrackEdgeIndices[149] = 74;
    m_TrackEdgeIndices[150] = 74;
    m_TrackEdgeIndices[151] = 75;
    m_TrackEdgeIndices[152] = 75;
    m_TrackEdgeIndices[153] = 76;
    m_TrackEdgeIndices[154] = 76;
    m_TrackEdgeIndices[155] = 77;
    m_TrackEdgeIndices[156] = 77;
    m_TrackEdgeIndices[157] = 78;
    m_TrackEdgeIndices[158] = 78;
    m_TrackEdgeIndices[159] = 79;
    m_TrackEdgeIndices[160] = 79;
    m_TrackEdgeIndices[161] = 80;
    m_TrackEdgeIndices[162] = 80;
    m_TrackEdgeIndices[163] = 81;
    m_TrackEdgeIndices[164] = 81;
    m_TrackEdgeIndices[165] = 82;
    m_TrackEdgeIndices[166] = 82;
    m_TrackEdgeIndices[167] = 83;
    m_TrackEdgeIndices[168] = 83;
    m_TrackEdgeIndices[169] = 84;
    m_TrackEdgeIndices[170] = 84;
    m_TrackEdgeIndices[171] = 85;
    m_TrackEdgeIndices[172] = 85;
    m_TrackEdgeIndices[173] = 86;
    m_TrackEdgeIndices[174] = 86;
    m_TrackEdgeIndices[175] = 87;
    m_TrackEdgeIndices[176] = 87;
    m_TrackEdgeIndices[177] = 88;
    m_TrackEdgeIndices[178] = 88;
    m_TrackEdgeIndices[179] = 89;
    m_TrackEdgeIndices[180] = 89;
    m_TrackEdgeIndices[181] = 90;
    m_TrackEdgeIndices[182] = 90;
    m_TrackEdgeIndices[183] = 91;
    m_TrackEdgeIndices[184] = 91;
    m_TrackEdgeIndices[185] = 92;
    m_TrackEdgeIndices[186] = 92;
    m_TrackEdgeIndices[187] = 93;
    m_TrackEdgeIndices[188] = 93;
    m_TrackEdgeIndices[189] = 94;
    m_TrackEdgeIndices[190] = 94;
    m_TrackEdgeIndices[191] = 95;
    m_TrackEdgeIndices[192] = 95;
    m_TrackEdgeIndices[193] = 96;
    m_TrackEdgeIndices[194] = 96;
    m_TrackEdgeIndices[195] = 97;
    m_TrackEdgeIndices[196] = 97;
    m_TrackEdgeIndices[197] = 98;
    m_TrackEdgeIndices[198] = 98;
    m_TrackEdgeIndices[199] = 99;
    m_TrackEdgeIndices[200] = 99;
    m_TrackEdgeIndices[201] = 100;
    m_TrackEdgeIndices[202] = 100;
    m_TrackEdgeIndices[203] = 101;
    m_TrackEdgeIndices[204] = 101;
    m_TrackEdgeIndices[205] = 102;
    m_TrackEdgeIndices[206] = 102;
    m_TrackEdgeIndices[207] = 103;
    m_TrackEdgeIndices[208] = 103;
    m_TrackEdgeIndices[209] = 104;
    m_TrackEdgeIndices[210] = 104;
    m_TrackEdgeIndices[211] = 105;
    m_TrackEdgeIndices[212] = 105;
    m_TrackEdgeIndices[213] = 106;
    m_TrackEdgeIndices[214] = 106;
    m_TrackEdgeIndices[215] = 107;
    m_TrackEdgeIndices[216] = 107;
    m_TrackEdgeIndices[217] = 108;
    m_TrackEdgeIndices[218] = 108;
    m_TrackEdgeIndices[219] = 109;
    m_TrackEdgeIndices[220] = 109;
    m_TrackEdgeIndices[221] = 110;
    m_TrackEdgeIndices[222] = 110;
    m_TrackEdgeIndices[223] = 111;
    m_TrackEdgeIndices[224] = 111;
    m_TrackEdgeIndices[225] = 112;
    m_TrackEdgeIndices[226] = 112;
    m_TrackEdgeIndices[227] = 113;
    m_TrackEdgeIndices[228] = 113;
    m_TrackEdgeIndices[229] = 114;
    m_TrackEdgeIndices[230] = 114;
    m_TrackEdgeIndices[231] = 115;
    m_TrackEdgeIndices[232] = 115;
    m_TrackEdgeIndices[233] = 116;
    m_TrackEdgeIndices[234] = 116;
    m_TrackEdgeIndices[235] = 117;
    m_TrackEdgeIndices[236] = 117;
    m_TrackEdgeIndices[237] = 118;
    m_TrackEdgeIndices[238] = 118;
    m_TrackEdgeIndices[239] = 119;
    m_TrackEdgeIndices[240] = 119;
    m_TrackEdgeIndices[241] = 120;
    m_TrackEdgeIndices[242] = 120;
    m_TrackEdgeIndices[243] = 121;
    m_TrackEdgeIndices[244] = 121;
    m_TrackEdgeIndices[245] = 122;
    m_TrackEdgeIndices[246] = 122;
    m_TrackEdgeIndices[247] = 123;
    m_TrackEdgeIndices[248] = 123;
    m_TrackEdgeIndices[249] = 124;
    m_TrackEdgeIndices[250] = 124;
    m_TrackEdgeIndices[251] = 125;
    m_TrackEdgeIndices[252] = 125;
    m_TrackEdgeIndices[253] = 126;
    m_TrackEdgeIndices[254] = 126;
    m_TrackEdgeIndices[255] = 127;
    m_TrackEdgeIndices[256] = 127;
    m_TrackEdgeIndices[257] = 128;
    m_TrackEdgeIndices[258] = 128;
    m_TrackEdgeIndices[259] = 129;
    m_TrackEdgeIndices[260] = 129;
    m_TrackEdgeIndices[261] = 130;
    m_TrackEdgeIndices[262] = 130;
    m_TrackEdgeIndices[263] = 131;
    m_TrackEdgeIndices[264] = 131;
    m_TrackEdgeIndices[265] = 132;
    m_TrackEdgeIndices[266] = 132;
    m_TrackEdgeIndices[267] = 133;
    m_TrackEdgeIndices[268] = 133;
    m_TrackEdgeIndices[269] = 134;
    m_TrackEdgeIndices[270] = 134;
    m_TrackEdgeIndices[271] = 135;
    m_TrackEdgeIndices[272] = 135;
    m_TrackEdgeIndices[273] = 136;
    m_TrackEdgeIndices[274] = 136;
    m_TrackEdgeIndices[275] = 137;
    m_TrackEdgeIndices[276] = 137;
    m_TrackEdgeIndices[277] = 138;
    m_TrackEdgeIndices[278] = 138;
    m_TrackEdgeIndices[279] = 139;
    m_TrackEdgeIndices[280] = 139;
    m_TrackEdgeIndices[281] = 140;
    m_TrackEdgeIndices[282] = 140;
    m_TrackEdgeIndices[283] = 141;
    m_TrackEdgeIndices[284] = 141;
    m_TrackEdgeIndices[285] = 142;
    m_TrackEdgeIndices[286] = 142;
    m_TrackEdgeIndices[287] = 143;
    m_TrackEdgeIndices[288] = 143;
    m_TrackEdgeIndices[289] = 144;
    m_TrackEdgeIndices[290] = 144;
    m_TrackEdgeIndices[291] = 145;
    m_TrackEdgeIndices[292] = 145;
    m_TrackEdgeIndices[293] = 146;
    m_TrackEdgeIndices[294] = 146;
    m_TrackEdgeIndices[295] = 147;
    m_TrackEdgeIndices[296] = 147;
    m_TrackEdgeIndices[297] = 148;
    m_TrackEdgeIndices[298] = 148;
    m_TrackEdgeIndices[299] = 149;

    m_TrackAreaIndices[0] = 0;
    m_TrackAreaIndices[1] = 73;
    m_TrackAreaIndices[2] = 1;
    m_TrackAreaIndices[3] = 73;
    m_TrackAreaIndices[4] = 149;
    m_TrackAreaIndices[5] = 1;
    m_TrackAreaIndices[6] = 73;
    m_TrackAreaIndices[7] = 72;
    m_TrackAreaIndices[8] = 149;
    m_TrackAreaIndices[9] = 72;
    m_TrackAreaIndices[10] = 148;
    m_TrackAreaIndices[11] = 149;
    m_TrackAreaIndices[12] = 72;
    m_TrackAreaIndices[13] = 71;
    m_TrackAreaIndices[14] = 148;
    m_TrackAreaIndices[15] = 71;
    m_TrackAreaIndices[16] = 147;
    m_TrackAreaIndices[17] = 148;
    m_TrackAreaIndices[18] = 71;
    m_TrackAreaIndices[19] = 70;
    m_TrackAreaIndices[20] = 147;
    m_TrackAreaIndices[21] = 70;
    m_TrackAreaIndices[22] = 146;
    m_TrackAreaIndices[23] = 147;
    m_TrackAreaIndices[24] = 70;
    m_TrackAreaIndices[25] = 69;
    m_TrackAreaIndices[26] = 146;
    m_TrackAreaIndices[27] = 69;
    m_TrackAreaIndices[28] = 145;
    m_TrackAreaIndices[29] = 146;
    m_TrackAreaIndices[30] = 69;
    m_TrackAreaIndices[31] = 144;
    m_TrackAreaIndices[32] = 145;
    m_TrackAreaIndices[33] = 69;
    m_TrackAreaIndices[34] = 68;
    m_TrackAreaIndices[35] = 144;
    m_TrackAreaIndices[36] = 68;
    m_TrackAreaIndices[37] = 143;
    m_TrackAreaIndices[38] = 144;
    m_TrackAreaIndices[39] = 68;
    m_TrackAreaIndices[40] = 142;
    m_TrackAreaIndices[41] = 143;
    m_TrackAreaIndices[42] = 68;
    m_TrackAreaIndices[43] = 67;
    m_TrackAreaIndices[44] = 142;
    m_TrackAreaIndices[45] = 67;
    m_TrackAreaIndices[46] = 141;
    m_TrackAreaIndices[47] = 142;
    m_TrackAreaIndices[48] = 67;
    m_TrackAreaIndices[49] = 66;
    m_TrackAreaIndices[50] = 141;
    m_TrackAreaIndices[51] = 66;
    m_TrackAreaIndices[52] = 140;
    m_TrackAreaIndices[53] = 141;
    m_TrackAreaIndices[54] = 66;
    m_TrackAreaIndices[55] = 65;
    m_TrackAreaIndices[56] = 140;
    m_TrackAreaIndices[57] = 65;
    m_TrackAreaIndices[58] = 139;
    m_TrackAreaIndices[59] = 140;
    m_TrackAreaIndices[60] = 65;
    m_TrackAreaIndices[61] = 64;
    m_TrackAreaIndices[62] = 139;
    m_TrackAreaIndices[63] = 64;
    m_TrackAreaIndices[64] = 138;
    m_TrackAreaIndices[65] = 139;
    m_TrackAreaIndices[66] = 64;
    m_TrackAreaIndices[67] = 63;
    m_TrackAreaIndices[68] = 138;
    m_TrackAreaIndices[69] = 63;
    m_TrackAreaIndices[70] = 137;
    m_TrackAreaIndices[71] = 138;
    m_TrackAreaIndices[72] = 63;
    m_TrackAreaIndices[73] = 62;
    m_TrackAreaIndices[74] = 137;
    m_TrackAreaIndices[75] = 62;
    m_TrackAreaIndices[76] = 136;
    m_TrackAreaIndices[77] = 137;
    m_TrackAreaIndices[78] = 62;
    m_TrackAreaIndices[79] = 61;
    m_TrackAreaIndices[80] = 136;
    m_TrackAreaIndices[81] = 61;
    m_TrackAreaIndices[82] = 135;
    m_TrackAreaIndices[83] = 136;
    m_TrackAreaIndices[84] = 61;
    m_TrackAreaIndices[85] = 60;
    m_TrackAreaIndices[86] = 135;
    m_TrackAreaIndices[87] = 60;
    m_TrackAreaIndices[88] = 134;
    m_TrackAreaIndices[89] = 135;
    m_TrackAreaIndices[90] = 60;
    m_TrackAreaIndices[91] = 133;
    m_TrackAreaIndices[92] = 134;
    m_TrackAreaIndices[93] = 60;
    m_TrackAreaIndices[94] = 59;
    m_TrackAreaIndices[95] = 133;
    m_TrackAreaIndices[96] = 59;
    m_TrackAreaIndices[97] = 132;
    m_TrackAreaIndices[98] = 133;
    m_TrackAreaIndices[99] = 59;
    m_TrackAreaIndices[100] = 58;
    m_TrackAreaIndices[101] = 132;
    m_TrackAreaIndices[102] = 58;
    m_TrackAreaIndices[103] = 131;
    m_TrackAreaIndices[104] = 132;
    m_TrackAreaIndices[105] = 58;
    m_TrackAreaIndices[106] = 57;
    m_TrackAreaIndices[107] = 131;
    m_TrackAreaIndices[108] = 57;
    m_TrackAreaIndices[109] = 56;
    m_TrackAreaIndices[110] = 131;
    m_TrackAreaIndices[111] = 56;
    m_TrackAreaIndices[112] = 130;
    m_TrackAreaIndices[113] = 131;
    m_TrackAreaIndices[114] = 56;
    m_TrackAreaIndices[115] = 55;
    m_TrackAreaIndices[116] = 130;
    m_TrackAreaIndices[117] = 55;
    m_TrackAreaIndices[118] = 129;
    m_TrackAreaIndices[119] = 130;
    m_TrackAreaIndices[120] = 55;
    m_TrackAreaIndices[121] = 128;
    m_TrackAreaIndices[122] = 129;
    m_TrackAreaIndices[123] = 55;
    m_TrackAreaIndices[124] = 54;
    m_TrackAreaIndices[125] = 128;
    m_TrackAreaIndices[126] = 54;
    m_TrackAreaIndices[127] = 127;
    m_TrackAreaIndices[128] = 128;
    m_TrackAreaIndices[129] = 54;
    m_TrackAreaIndices[130] = 53;
    m_TrackAreaIndices[131] = 127;
    m_TrackAreaIndices[132] = 53;
    m_TrackAreaIndices[133] = 126;
    m_TrackAreaIndices[134] = 127;
    m_TrackAreaIndices[135] = 53;
    m_TrackAreaIndices[136] = 52;
    m_TrackAreaIndices[137] = 126;
    m_TrackAreaIndices[138] = 52;
    m_TrackAreaIndices[139] = 125;
    m_TrackAreaIndices[140] = 126;
    m_TrackAreaIndices[141] = 52;
    m_TrackAreaIndices[142] = 124;
    m_TrackAreaIndices[143] = 125;
    m_TrackAreaIndices[144] = 52;
    m_TrackAreaIndices[145] = 51;
    m_TrackAreaIndices[146] = 124;
    m_TrackAreaIndices[147] = 51;
    m_TrackAreaIndices[148] = 123;
    m_TrackAreaIndices[149] = 124;
    m_TrackAreaIndices[150] = 51;
    m_TrackAreaIndices[151] = 50;
    m_TrackAreaIndices[152] = 123;
    m_TrackAreaIndices[153] = 50;
    m_TrackAreaIndices[154] = 122;
    m_TrackAreaIndices[155] = 123;
    m_TrackAreaIndices[156] = 50;
    m_TrackAreaIndices[157] = 121;
    m_TrackAreaIndices[158] = 122;
    m_TrackAreaIndices[159] = 50;
    m_TrackAreaIndices[160] = 49;
    m_TrackAreaIndices[161] = 121;
    m_TrackAreaIndices[162] = 49;
    m_TrackAreaIndices[163] = 120;
    m_TrackAreaIndices[164] = 121;
    m_TrackAreaIndices[165] = 49;
    m_TrackAreaIndices[166] = 48;
    m_TrackAreaIndices[167] = 120;
    m_TrackAreaIndices[168] = 48;
    m_TrackAreaIndices[169] = 119;
    m_TrackAreaIndices[170] = 120;
    m_TrackAreaIndices[171] = 48;
    m_TrackAreaIndices[172] = 47;
    m_TrackAreaIndices[173] = 119;
    m_TrackAreaIndices[174] = 47;
    m_TrackAreaIndices[175] = 118;
    m_TrackAreaIndices[176] = 119;
    m_TrackAreaIndices[177] = 47;
    m_TrackAreaIndices[178] = 46;
    m_TrackAreaIndices[179] = 118;
    m_TrackAreaIndices[180] = 46;
    m_TrackAreaIndices[181] = 117;
    m_TrackAreaIndices[182] = 118;
    m_TrackAreaIndices[183] = 46;
    m_TrackAreaIndices[184] = 45;
    m_TrackAreaIndices[185] = 117;
    m_TrackAreaIndices[186] = 45;
    m_TrackAreaIndices[187] = 116;
    m_TrackAreaIndices[188] = 117;
    m_TrackAreaIndices[189] = 45;
    m_TrackAreaIndices[190] = 44;
    m_TrackAreaIndices[191] = 116;
    m_TrackAreaIndices[192] = 44;
    m_TrackAreaIndices[193] = 115;
    m_TrackAreaIndices[194] = 116;
    m_TrackAreaIndices[195] = 44;
    m_TrackAreaIndices[196] = 43;
    m_TrackAreaIndices[197] = 115;
    m_TrackAreaIndices[198] = 43;
    m_TrackAreaIndices[199] = 114;
    m_TrackAreaIndices[200] = 115;
    m_TrackAreaIndices[201] = 43;
    m_TrackAreaIndices[202] = 42;
    m_TrackAreaIndices[203] = 114;
    m_TrackAreaIndices[204] = 42;
    m_TrackAreaIndices[205] = 41;
    m_TrackAreaIndices[206] = 114;
    m_TrackAreaIndices[207] = 41;
    m_TrackAreaIndices[208] = 113;
    m_TrackAreaIndices[209] = 114;
    m_TrackAreaIndices[210] = 41;
    m_TrackAreaIndices[211] = 40;
    m_TrackAreaIndices[212] = 113;
    m_TrackAreaIndices[213] = 40;
    m_TrackAreaIndices[214] = 39;
    m_TrackAreaIndices[215] = 113;
    m_TrackAreaIndices[216] = 39;
    m_TrackAreaIndices[217] = 112;
    m_TrackAreaIndices[218] = 113;
    m_TrackAreaIndices[219] = 39;
    m_TrackAreaIndices[220] = 38;
    m_TrackAreaIndices[221] = 112;
    m_TrackAreaIndices[222] = 38;
    m_TrackAreaIndices[223] = 111;
    m_TrackAreaIndices[224] = 112;
    m_TrackAreaIndices[225] = 38;
    m_TrackAreaIndices[226] = 110;
    m_TrackAreaIndices[227] = 111;
    m_TrackAreaIndices[228] = 38;
    m_TrackAreaIndices[229] = 37;
    m_TrackAreaIndices[230] = 110;
    m_TrackAreaIndices[231] = 37;
    m_TrackAreaIndices[232] = 109;
    m_TrackAreaIndices[233] = 110;
    m_TrackAreaIndices[234] = 37;
    m_TrackAreaIndices[235] = 36;
    m_TrackAreaIndices[236] = 109;
    m_TrackAreaIndices[237] = 36;
    m_TrackAreaIndices[238] = 108;
    m_TrackAreaIndices[239] = 109;
    m_TrackAreaIndices[240] = 36;
    m_TrackAreaIndices[241] = 35;
    m_TrackAreaIndices[242] = 108;
    m_TrackAreaIndices[243] = 35;
    m_TrackAreaIndices[244] = 34;
    m_TrackAreaIndices[245] = 108;
    m_TrackAreaIndices[246] = 34;
    m_TrackAreaIndices[247] = 33;
    m_TrackAreaIndices[248] = 108;
    m_TrackAreaIndices[249] = 33;
    m_TrackAreaIndices[250] = 107;
    m_TrackAreaIndices[251] = 108;
    m_TrackAreaIndices[252] = 33;
    m_TrackAreaIndices[253] = 32;
    m_TrackAreaIndices[254] = 107;
    m_TrackAreaIndices[255] = 32;
    m_TrackAreaIndices[256] = 106;
    m_TrackAreaIndices[257] = 107;
    m_TrackAreaIndices[258] = 32;
    m_TrackAreaIndices[259] = 31;
    m_TrackAreaIndices[260] = 106;
    m_TrackAreaIndices[261] = 31;
    m_TrackAreaIndices[262] = 30;
    m_TrackAreaIndices[263] = 106;
    m_TrackAreaIndices[264] = 30;
    m_TrackAreaIndices[265] = 105;
    m_TrackAreaIndices[266] = 106;
    m_TrackAreaIndices[267] = 30;
    m_TrackAreaIndices[268] = 29;
    m_TrackAreaIndices[269] = 105;
    m_TrackAreaIndices[270] = 29;
    m_TrackAreaIndices[271] = 104;
    m_TrackAreaIndices[272] = 105;
    m_TrackAreaIndices[273] = 29;
    m_TrackAreaIndices[274] = 28;
    m_TrackAreaIndices[275] = 104;
    m_TrackAreaIndices[276] = 28;
    m_TrackAreaIndices[277] = 103;
    m_TrackAreaIndices[278] = 104;
    m_TrackAreaIndices[279] = 28;
    m_TrackAreaIndices[280] = 27;
    m_TrackAreaIndices[281] = 103;
    m_TrackAreaIndices[282] = 27;
    m_TrackAreaIndices[283] = 102;
    m_TrackAreaIndices[284] = 103;
    m_TrackAreaIndices[285] = 27;
    m_TrackAreaIndices[286] = 26;
    m_TrackAreaIndices[287] = 102;
    m_TrackAreaIndices[288] = 26;
    m_TrackAreaIndices[289] = 101;
    m_TrackAreaIndices[290] = 102;
    m_TrackAreaIndices[291] = 26;
    m_TrackAreaIndices[292] = 100;
    m_TrackAreaIndices[293] = 101;
    m_TrackAreaIndices[294] = 26;
    m_TrackAreaIndices[295] = 25;
    m_TrackAreaIndices[296] = 100;
    m_TrackAreaIndices[297] = 25;
    m_TrackAreaIndices[298] = 99;
    m_TrackAreaIndices[299] = 100;
    m_TrackAreaIndices[300] = 25;
    m_TrackAreaIndices[301] = 98;
    m_TrackAreaIndices[302] = 99;
    m_TrackAreaIndices[303] = 25;
    m_TrackAreaIndices[304] = 24;
    m_TrackAreaIndices[305] = 98;
    m_TrackAreaIndices[306] = 24;
    m_TrackAreaIndices[307] = 97;
    m_TrackAreaIndices[308] = 98;
    m_TrackAreaIndices[309] = 24;
    m_TrackAreaIndices[310] = 23;
    m_TrackAreaIndices[311] = 97;
    m_TrackAreaIndices[312] = 23;
    m_TrackAreaIndices[313] = 96;
    m_TrackAreaIndices[314] = 97;
    m_TrackAreaIndices[315] = 23;
    m_TrackAreaIndices[316] = 95;
    m_TrackAreaIndices[317] = 96;
    m_TrackAreaIndices[318] = 23;
    m_TrackAreaIndices[319] = 22;
    m_TrackAreaIndices[320] = 95;
    m_TrackAreaIndices[321] = 22;
    m_TrackAreaIndices[322] = 94;
    m_TrackAreaIndices[323] = 95;
    m_TrackAreaIndices[324] = 22;
    m_TrackAreaIndices[325] = 21;
    m_TrackAreaIndices[326] = 94;
    m_TrackAreaIndices[327] = 21;
    m_TrackAreaIndices[328] = 93;
    m_TrackAreaIndices[329] = 94;
    m_TrackAreaIndices[330] = 21;
    m_TrackAreaIndices[331] = 20;
    m_TrackAreaIndices[332] = 93;
    m_TrackAreaIndices[333] = 20;
    m_TrackAreaIndices[334] = 92;
    m_TrackAreaIndices[335] = 93;
    m_TrackAreaIndices[336] = 20;
    m_TrackAreaIndices[337] = 19;
    m_TrackAreaIndices[338] = 92;
    m_TrackAreaIndices[339] = 19;
    m_TrackAreaIndices[340] = 91;
    m_TrackAreaIndices[341] = 92;
    m_TrackAreaIndices[342] = 19;
    m_TrackAreaIndices[343] = 18;
    m_TrackAreaIndices[344] = 91;
    m_TrackAreaIndices[345] = 18;
    m_TrackAreaIndices[346] = 17;
    m_TrackAreaIndices[347] = 91;
    m_TrackAreaIndices[348] = 17;
    m_TrackAreaIndices[349] = 90;
    m_TrackAreaIndices[350] = 91;
    m_TrackAreaIndices[351] = 17;
    m_TrackAreaIndices[352] = 16;
    m_TrackAreaIndices[353] = 90;
    m_TrackAreaIndices[354] = 16;
    m_TrackAreaIndices[355] = 89;
    m_TrackAreaIndices[356] = 90;
    m_TrackAreaIndices[357] = 16;
    m_TrackAreaIndices[358] = 15;
    m_TrackAreaIndices[359] = 89;
    m_TrackAreaIndices[360] = 15;
    m_TrackAreaIndices[361] = 88;
    m_TrackAreaIndices[362] = 89;
    m_TrackAreaIndices[363] = 15;
    m_TrackAreaIndices[364] = 14;
    m_TrackAreaIndices[365] = 88;
    m_TrackAreaIndices[366] = 14;
    m_TrackAreaIndices[367] = 13;
    m_TrackAreaIndices[368] = 88;
    m_TrackAreaIndices[369] = 13;
    m_TrackAreaIndices[370] = 87;
    m_TrackAreaIndices[371] = 88;
    m_TrackAreaIndices[372] = 13;
    m_TrackAreaIndices[373] = 12;
    m_TrackAreaIndices[374] = 87;
    m_TrackAreaIndices[375] = 12;
    m_TrackAreaIndices[376] = 11;
    m_TrackAreaIndices[377] = 87;
    m_TrackAreaIndices[378] = 11;
    m_TrackAreaIndices[379] = 86;
    m_TrackAreaIndices[380] = 87;
    m_TrackAreaIndices[381] = 11;
    m_TrackAreaIndices[382] = 10;
    m_TrackAreaIndices[383] = 86;
    m_TrackAreaIndices[384] = 10;
    m_TrackAreaIndices[385] = 85;
    m_TrackAreaIndices[386] = 86;
    m_TrackAreaIndices[387] = 10;
    m_TrackAreaIndices[388] = 9;
    m_TrackAreaIndices[389] = 85;
    m_TrackAreaIndices[390] = 9;
    m_TrackAreaIndices[391] = 84;
    m_TrackAreaIndices[392] = 85;
    m_TrackAreaIndices[393] = 9;
    m_TrackAreaIndices[394] = 8;
    m_TrackAreaIndices[395] = 84;
    m_TrackAreaIndices[396] = 8;
    m_TrackAreaIndices[397] = 83;
    m_TrackAreaIndices[398] = 84;
    m_TrackAreaIndices[399] = 8;
    m_TrackAreaIndices[400] = 82;
    m_TrackAreaIndices[401] = 83;
    m_TrackAreaIndices[402] = 8;
    m_TrackAreaIndices[403] = 7;
    m_TrackAreaIndices[404] = 82;
    m_TrackAreaIndices[405] = 7;
    m_TrackAreaIndices[406] = 81;
    m_TrackAreaIndices[407] = 82;
    m_TrackAreaIndices[408] = 7;
    m_TrackAreaIndices[409] = 6;
    m_TrackAreaIndices[410] = 81;
    m_TrackAreaIndices[411] = 6;
    m_TrackAreaIndices[412] = 80;
    m_TrackAreaIndices[413] = 81;
    m_TrackAreaIndices[414] = 6;
    m_TrackAreaIndices[415] = 79;
    m_TrackAreaIndices[416] = 80;
    m_TrackAreaIndices[417] = 6;
    m_TrackAreaIndices[418] = 5;
    m_TrackAreaIndices[419] = 79;
    m_TrackAreaIndices[420] = 5;
    m_TrackAreaIndices[421] = 78;
    m_TrackAreaIndices[422] = 79;
    m_TrackAreaIndices[423] = 5;
    m_TrackAreaIndices[424] = 4;
    m_TrackAreaIndices[425] = 78;
    m_TrackAreaIndices[426] = 4;
    m_TrackAreaIndices[427] = 77;
    m_TrackAreaIndices[428] = 78;
    m_TrackAreaIndices[429] = 4;
    m_TrackAreaIndices[430] = 76;
    m_TrackAreaIndices[431] = 77;
    m_TrackAreaIndices[432] = 4;
    m_TrackAreaIndices[433] = 3;
    m_TrackAreaIndices[434] = 76;
    m_TrackAreaIndices[435] = 3;
    m_TrackAreaIndices[436] = 75;
    m_TrackAreaIndices[437] = 76;
    m_TrackAreaIndices[438] = 3;
    m_TrackAreaIndices[439] = 2;
    m_TrackAreaIndices[440] = 75;
    m_TrackAreaIndices[441] = 2;
    m_TrackAreaIndices[442] = 74;
    m_TrackAreaIndices[443] = 75;
    m_TrackAreaIndices[444] = 2;
    m_TrackAreaIndices[445] = 0;
    m_TrackAreaIndices[446] = 74;
    m_TrackAreaIndices[447] = 0;
    m_TrackAreaIndices[448] = 1;
    m_TrackAreaIndices[449] = 74;

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
