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
    m_TrackVertices[0] = Point({-20, -33, 0});
    m_TrackVertices[1] = Point({-23, 35, 0});
    m_TrackVertices[2] = Point({-26, 59, 0});
    m_TrackVertices[3] = Point({-29, 76, 0});
    m_TrackVertices[4] = Point({-38, 86, 0});
    m_TrackVertices[5] = Point({-58, 91, 0});
    m_TrackVertices[6] = Point({-82, 85, 0});
    m_TrackVertices[7] = Point({-101, 68, 0});
    m_TrackVertices[8] = Point({-104, 37, 0});
    m_TrackVertices[9] = Point({-103, 15, 0});
    m_TrackVertices[10] = Point({-107, -13, 0});
    m_TrackVertices[11] = Point({-126, -29, 0});
    m_TrackVertices[12] = Point({-148, -28, 0});
    m_TrackVertices[13] = Point({-171, -27, 0});
    m_TrackVertices[14] = Point({-192, -30, 0});
    m_TrackVertices[15] = Point({-212, -50, 0});
    m_TrackVertices[16] = Point({-218, -88, 0});
    m_TrackVertices[17] = Point({-220, -113, 0});
    m_TrackVertices[18] = Point({-207, -139, 0});
    m_TrackVertices[19] = Point({-180, -170, 0});
    m_TrackVertices[20] = Point({-138, -186, 0});
    m_TrackVertices[21] = Point({-113, -183, 0});
    m_TrackVertices[22] = Point({-89, -160, 0});
    m_TrackVertices[23] = Point({-82, -136, 0});
    m_TrackVertices[24] = Point({-71, -106, 0});
    m_TrackVertices[25] = Point({-42, -97, 0});
    m_TrackVertices[26] = Point({-20, -100, 0});
    m_TrackVertices[27] = Point({11, -118, 0});
    m_TrackVertices[28] = Point({27, -136, 0});
    m_TrackVertices[29] = Point({60, -143, 0});
    m_TrackVertices[30] = Point({72, -136, 0});
    m_TrackVertices[31] = Point({87, -119, 0});
    m_TrackVertices[32] = Point({94, -100, 0});
    m_TrackVertices[33] = Point({91, -83, 0});
    m_TrackVertices[34] = Point({83, -73, 0});
    m_TrackVertices[35] = Point({61, -69, 0});
    m_TrackVertices[36] = Point({38, -70, 0});
    m_TrackVertices[37] = Point({14, -77, 0});
    m_TrackVertices[38] = Point({-10, -74, 0});
    m_TrackVertices[39] = Point({-19, -56, 0});
    m_TrackVertices[40] = Point({10, -33, 0});
    m_TrackVertices[41] = Point({9, 36, 0});
    m_TrackVertices[42] = Point({11, 65, 0});
    m_TrackVertices[43] = Point({8, 86, 0});
    m_TrackVertices[44] = Point({-1, 105, 0});
    m_TrackVertices[45] = Point({-23, 116, 0});
    m_TrackVertices[46] = Point({-51, 117, 0});
    m_TrackVertices[47] = Point({-82, 112, 0});
    m_TrackVertices[48] = Point({-116, 102, 0});
    m_TrackVertices[49] = Point({-136, 77, 0});
    m_TrackVertices[50] = Point({-146, 48, 0});
    m_TrackVertices[51] = Point({-147, 17, 0});
    m_TrackVertices[52] = Point({-151, 9, 0});
    m_TrackVertices[53] = Point({-164, 8, 0});
    m_TrackVertices[54] = Point({-180, 3, 0});
    m_TrackVertices[55] = Point({-214, -6, 0});
    m_TrackVertices[56] = Point({-238, -27, 0});
    m_TrackVertices[57] = Point({-251, -56, 0});
    m_TrackVertices[58] = Point({-260, -91, 0});
    m_TrackVertices[59] = Point({-262, -131, 0});
    m_TrackVertices[60] = Point({-229, -175, 0});
    m_TrackVertices[61] = Point({-195, -208, 0});
    m_TrackVertices[62] = Point({-165, -220, 0});
    m_TrackVertices[63] = Point({-114, -224, 0});
    m_TrackVertices[64] = Point({-83, -209, 0});
    m_TrackVertices[65] = Point({-68, -192, 0});
    m_TrackVertices[66] = Point({-56, -168, 0});
    m_TrackVertices[67] = Point({-48, -151, 0});
    m_TrackVertices[68] = Point({-41, -133, 0});
    m_TrackVertices[69] = Point({-36, -131, 0});
    m_TrackVertices[70] = Point({-21, -133, 0});
    m_TrackVertices[71] = Point({0, -144, 0});
    m_TrackVertices[72] = Point({19, -159, 0});
    m_TrackVertices[73] = Point({33, -172, 0});
    m_TrackVertices[74] = Point({60, -179, 0});
    m_TrackVertices[75] = Point({88, -175, 0});
    m_TrackVertices[76] = Point({106, -157, 0});
    m_TrackVertices[77] = Point({114, -145, 0});
    m_TrackVertices[78] = Point({119, -130, 0});
    m_TrackVertices[79] = Point({123, -112, 0});
    m_TrackVertices[80] = Point({125, -97, 0});
    m_TrackVertices[81] = Point({118, -82, 0});
    m_TrackVertices[82] = Point({110, -64, 0});
    m_TrackVertices[83] = Point({99, -56, 0});
    m_TrackVertices[84] = Point({75, -43, 0});
    m_TrackVertices[85] = Point({52, -42, 0});
    m_TrackVertices[86] = Point({36, -45, 0});
    m_TrackVertices[87] = Point({17, -47, 0});
    m_TrackVertices[88] = Point({12, -43, 0});


    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 39;
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
    m_TrackEdgeIndices[74] = 36;
    m_TrackEdgeIndices[75] = 37;
    m_TrackEdgeIndices[76] = 37;
    m_TrackEdgeIndices[77] = 38;
    m_TrackEdgeIndices[78] = 38;
    m_TrackEdgeIndices[79] = 39;
    m_TrackEdgeIndices[80] = 40;
    m_TrackEdgeIndices[81] = 88;
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


    // ----
    m_TrackAreaIndices[0] = 0;
    m_TrackAreaIndices[1] = 88;
    m_TrackAreaIndices[2] = 40;
    m_TrackAreaIndices[3] = 0;
    m_TrackAreaIndices[4] = 87;
    m_TrackAreaIndices[5] = 88;
    m_TrackAreaIndices[6] = 0;
    m_TrackAreaIndices[7] = 39;
    m_TrackAreaIndices[8] = 87;
    m_TrackAreaIndices[9] = 39;
    m_TrackAreaIndices[10] = 86;
    m_TrackAreaIndices[11] = 87;
    m_TrackAreaIndices[12] = 39;
    m_TrackAreaIndices[13] = 38;
    m_TrackAreaIndices[14] = 86;
    m_TrackAreaIndices[15] = 38;
    m_TrackAreaIndices[16] = 85;
    m_TrackAreaIndices[17] = 86;
    m_TrackAreaIndices[18] = 38;
    m_TrackAreaIndices[19] = 84;
    m_TrackAreaIndices[20] = 85;
    m_TrackAreaIndices[21] = 38;
    m_TrackAreaIndices[22] = 37;
    m_TrackAreaIndices[23] = 84;
    m_TrackAreaIndices[24] = 37;
    m_TrackAreaIndices[25] = 83;
    m_TrackAreaIndices[26] = 84;
    m_TrackAreaIndices[27] = 37;
    m_TrackAreaIndices[28] = 36;
    m_TrackAreaIndices[29] = 83;
    m_TrackAreaIndices[30] = 36;
    m_TrackAreaIndices[31] = 82;
    m_TrackAreaIndices[32] = 83;
    m_TrackAreaIndices[33] = 36;
    m_TrackAreaIndices[34] = 81;
    m_TrackAreaIndices[35] = 82;
    m_TrackAreaIndices[36] = 36;
    m_TrackAreaIndices[37] = 35;
    m_TrackAreaIndices[38] = 81;
    m_TrackAreaIndices[39] = 35;
    m_TrackAreaIndices[40] = 80;
    m_TrackAreaIndices[41] = 81;
    m_TrackAreaIndices[42] = 35;
    m_TrackAreaIndices[43] = 34;
    m_TrackAreaIndices[44] = 80;
    m_TrackAreaIndices[45] = 34;
    m_TrackAreaIndices[46] = 79;
    m_TrackAreaIndices[47] = 80;
    m_TrackAreaIndices[48] = 34;
    m_TrackAreaIndices[49] = 33;
    m_TrackAreaIndices[50] = 79;
    m_TrackAreaIndices[51] = 33;
    m_TrackAreaIndices[52] = 78;
    m_TrackAreaIndices[53] = 79;
    m_TrackAreaIndices[54] = 33;
    m_TrackAreaIndices[55] = 32;
    m_TrackAreaIndices[56] = 78;
    m_TrackAreaIndices[57] = 32;
    m_TrackAreaIndices[58] = 77;
    m_TrackAreaIndices[59] = 78;
    m_TrackAreaIndices[60] = 32;
    m_TrackAreaIndices[61] = 76;
    m_TrackAreaIndices[62] = 77;
    m_TrackAreaIndices[63] = 32;
    m_TrackAreaIndices[64] = 31;
    m_TrackAreaIndices[65] = 76;
    m_TrackAreaIndices[66] = 31;
    m_TrackAreaIndices[67] = 75;
    m_TrackAreaIndices[68] = 76;
    m_TrackAreaIndices[69] = 31;
    m_TrackAreaIndices[70] = 30;
    m_TrackAreaIndices[71] = 75;
    m_TrackAreaIndices[72] = 30;
    m_TrackAreaIndices[73] = 29;
    m_TrackAreaIndices[74] = 75;
    m_TrackAreaIndices[75] = 29;
    m_TrackAreaIndices[76] = 74;
    m_TrackAreaIndices[77] = 75;
    m_TrackAreaIndices[78] = 29;
    m_TrackAreaIndices[79] = 73;
    m_TrackAreaIndices[80] = 74;
    m_TrackAreaIndices[81] = 29;
    m_TrackAreaIndices[82] = 28;
    m_TrackAreaIndices[83] = 73;
    m_TrackAreaIndices[84] = 28;
    m_TrackAreaIndices[85] = 72;
    m_TrackAreaIndices[86] = 73;
    m_TrackAreaIndices[87] = 28;
    m_TrackAreaIndices[88] = 27;
    m_TrackAreaIndices[89] = 72;
    m_TrackAreaIndices[90] = 27;
    m_TrackAreaIndices[91] = 71;
    m_TrackAreaIndices[92] = 72;
    m_TrackAreaIndices[93] = 27;
    m_TrackAreaIndices[94] = 70;
    m_TrackAreaIndices[95] = 71;
    m_TrackAreaIndices[96] = 27;
    m_TrackAreaIndices[97] = 26;
    m_TrackAreaIndices[98] = 70;
    m_TrackAreaIndices[99] = 26;
    m_TrackAreaIndices[100] = 69;
    m_TrackAreaIndices[101] = 70;
    m_TrackAreaIndices[102] = 26;
    m_TrackAreaIndices[103] = 68;
    m_TrackAreaIndices[104] = 69;
    m_TrackAreaIndices[105] = 26;
    m_TrackAreaIndices[106] = 67;
    m_TrackAreaIndices[107] = 68;
    m_TrackAreaIndices[108] = 26;
    m_TrackAreaIndices[109] = 25;
    m_TrackAreaIndices[110] = 67;
    m_TrackAreaIndices[111] = 25;
    m_TrackAreaIndices[112] = 66;
    m_TrackAreaIndices[113] = 67;
    m_TrackAreaIndices[114] = 25;
    m_TrackAreaIndices[115] = 24;
    m_TrackAreaIndices[116] = 66;
    m_TrackAreaIndices[117] = 24;
    m_TrackAreaIndices[118] = 65;
    m_TrackAreaIndices[119] = 66;
    m_TrackAreaIndices[120] = 24;
    m_TrackAreaIndices[121] = 64;
    m_TrackAreaIndices[122] = 65;
    m_TrackAreaIndices[123] = 24;
    m_TrackAreaIndices[124] = 23;
    m_TrackAreaIndices[125] = 64;
    m_TrackAreaIndices[126] = 23;
    m_TrackAreaIndices[127] = 63;
    m_TrackAreaIndices[128] = 64;
    m_TrackAreaIndices[129] = 23;
    m_TrackAreaIndices[130] = 22;
    m_TrackAreaIndices[131] = 63;
    m_TrackAreaIndices[132] = 22;
    m_TrackAreaIndices[133] = 21;
    m_TrackAreaIndices[134] = 63;
    m_TrackAreaIndices[135] = 21;
    m_TrackAreaIndices[136] = 62;
    m_TrackAreaIndices[137] = 63;
    m_TrackAreaIndices[138] = 21;
    m_TrackAreaIndices[139] = 20;
    m_TrackAreaIndices[140] = 62;
    m_TrackAreaIndices[141] = 20;
    m_TrackAreaIndices[142] = 61;
    m_TrackAreaIndices[143] = 62;
    m_TrackAreaIndices[144] = 20;
    m_TrackAreaIndices[145] = 19;
    m_TrackAreaIndices[146] = 61;
    m_TrackAreaIndices[147] = 19;
    m_TrackAreaIndices[148] = 60;
    m_TrackAreaIndices[149] = 61;
    m_TrackAreaIndices[150] = 19;
    m_TrackAreaIndices[151] = 18;
    m_TrackAreaIndices[152] = 60;
    m_TrackAreaIndices[153] = 18;
    m_TrackAreaIndices[154] = 59;
    m_TrackAreaIndices[155] = 60;
    m_TrackAreaIndices[156] = 18;
    m_TrackAreaIndices[157] = 17;
    m_TrackAreaIndices[158] = 59;
    m_TrackAreaIndices[159] = 17;
    m_TrackAreaIndices[160] = 58;
    m_TrackAreaIndices[161] = 59;
    m_TrackAreaIndices[162] = 17;
    m_TrackAreaIndices[163] = 16;
    m_TrackAreaIndices[164] = 58;
    m_TrackAreaIndices[165] = 16;
    m_TrackAreaIndices[166] = 57;
    m_TrackAreaIndices[167] = 58;
    m_TrackAreaIndices[168] = 16;
    m_TrackAreaIndices[169] = 15;
    m_TrackAreaIndices[170] = 57;
    m_TrackAreaIndices[171] = 15;
    m_TrackAreaIndices[172] = 56;
    m_TrackAreaIndices[173] = 57;
    m_TrackAreaIndices[174] = 15;
    m_TrackAreaIndices[175] = 14;
    m_TrackAreaIndices[176] = 56;
    m_TrackAreaIndices[177] = 14;
    m_TrackAreaIndices[178] = 55;
    m_TrackAreaIndices[179] = 56;
    m_TrackAreaIndices[180] = 14;
    m_TrackAreaIndices[181] = 13;
    m_TrackAreaIndices[182] = 55;
    m_TrackAreaIndices[183] = 13;
    m_TrackAreaIndices[184] = 54;
    m_TrackAreaIndices[185] = 55;
    m_TrackAreaIndices[186] = 13;
    m_TrackAreaIndices[187] = 12;
    m_TrackAreaIndices[188] = 54;
    m_TrackAreaIndices[189] = 12;
    m_TrackAreaIndices[190] = 53;
    m_TrackAreaIndices[191] = 54;
    m_TrackAreaIndices[192] = 12;
    m_TrackAreaIndices[193] = 52;
    m_TrackAreaIndices[194] = 53;
    m_TrackAreaIndices[195] = 12;
    m_TrackAreaIndices[196] = 11;
    m_TrackAreaIndices[197] = 52;
    m_TrackAreaIndices[198] = 11;
    m_TrackAreaIndices[199] = 51;
    m_TrackAreaIndices[200] = 52;
    m_TrackAreaIndices[201] = 11;
    m_TrackAreaIndices[202] = 10;
    m_TrackAreaIndices[203] = 51;
    m_TrackAreaIndices[204] = 10;
    m_TrackAreaIndices[205] = 50;
    m_TrackAreaIndices[206] = 51;
    m_TrackAreaIndices[207] = 10;
    m_TrackAreaIndices[208] = 9;
    m_TrackAreaIndices[209] = 50;
    m_TrackAreaIndices[210] = 9;
    m_TrackAreaIndices[211] = 49;
    m_TrackAreaIndices[212] = 50;
    m_TrackAreaIndices[213] = 9;
    m_TrackAreaIndices[214] = 8;
    m_TrackAreaIndices[215] = 49;
    m_TrackAreaIndices[216] = 8;
    m_TrackAreaIndices[217] = 48;
    m_TrackAreaIndices[218] = 49;
    m_TrackAreaIndices[219] = 8;
    m_TrackAreaIndices[220] = 7;
    m_TrackAreaIndices[221] = 48;
    m_TrackAreaIndices[222] = 7;
    m_TrackAreaIndices[223] = 47;
    m_TrackAreaIndices[224] = 48;
    m_TrackAreaIndices[225] = 7;
    m_TrackAreaIndices[226] = 6;
    m_TrackAreaIndices[227] = 47;
    m_TrackAreaIndices[228] = 6;
    m_TrackAreaIndices[229] = 46;
    m_TrackAreaIndices[230] = 47;
    m_TrackAreaIndices[231] = 6;
    m_TrackAreaIndices[232] = 5;
    m_TrackAreaIndices[233] = 46;
    m_TrackAreaIndices[234] = 5;
    m_TrackAreaIndices[235] = 45;
    m_TrackAreaIndices[236] = 46;
    m_TrackAreaIndices[237] = 5;
    m_TrackAreaIndices[238] = 4;
    m_TrackAreaIndices[239] = 45;
    m_TrackAreaIndices[240] = 4;
    m_TrackAreaIndices[241] = 44;
    m_TrackAreaIndices[242] = 45;
    m_TrackAreaIndices[243] = 4;
    m_TrackAreaIndices[244] = 3;
    m_TrackAreaIndices[245] = 44;
    m_TrackAreaIndices[246] = 3;
    m_TrackAreaIndices[247] = 43;
    m_TrackAreaIndices[248] = 44;
    m_TrackAreaIndices[249] = 3;
    m_TrackAreaIndices[250] = 2;
    m_TrackAreaIndices[251] = 43;
    m_TrackAreaIndices[252] = 2;
    m_TrackAreaIndices[253] = 42;
    m_TrackAreaIndices[254] = 43;
    m_TrackAreaIndices[255] = 2;
    m_TrackAreaIndices[256] = 1;
    m_TrackAreaIndices[257] = 42;
    m_TrackAreaIndices[258] = 1;
    m_TrackAreaIndices[259] = 41;
    m_TrackAreaIndices[260] = 42;
    m_TrackAreaIndices[261] = 1;
    m_TrackAreaIndices[262] = 0;
    m_TrackAreaIndices[263] = 41;
    m_TrackAreaIndices[264] = 0;
    m_TrackAreaIndices[265] = 40;
    m_TrackAreaIndices[266] = 41;
}

void Track::Update(Timestep ts)
{

}

void Track::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    Draw(m_DrawMode, display, camera);
}

void Track::Draw(DrawMode mode, Adafruit_SSD1306& display, Camera& camera)
{
    switch(mode)
    {
    case(DrawMode::Lines):          DrawLines(display, camera); break;
    case(DrawMode::Triangles):      DrawTriangles(display, camera); break;
    }
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
