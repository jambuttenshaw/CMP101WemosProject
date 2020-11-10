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
    m_TrackVertices[0] = Point({-28, -34, 0});
    m_TrackVertices[1] = Point({-29, 33, 0});
    m_TrackVertices[2] = Point({23, -35, 0});
    m_TrackVertices[3] = Point({23, 35, 0});
    m_TrackVertices[4] = Point({-31, 66, 0});
    m_TrackVertices[5] = Point({-31, 94, 0});
    m_TrackVertices[6] = Point({-13, 124, 0});
    m_TrackVertices[7] = Point({7, 149, 0});
    m_TrackVertices[8] = Point({20, 171, 0});
    m_TrackVertices[9] = Point({23, 180, 0});
    m_TrackVertices[10] = Point({14, 192, 0});
    m_TrackVertices[11] = Point({-3, 198, 0});
    m_TrackVertices[12] = Point({-24, 199, 0});
    m_TrackVertices[13] = Point({-61, 197, 0});
    m_TrackVertices[14] = Point({-103, 193, 0});
    m_TrackVertices[15] = Point({-138, 183, 0});
    m_TrackVertices[16] = Point({-157, 165, 0});
    m_TrackVertices[17] = Point({-170, 143, 0});
    m_TrackVertices[18] = Point({-176, 98, 0});
    m_TrackVertices[19] = Point({-168, 68, 0});
    m_TrackVertices[20] = Point({-155, 35, 0});
    m_TrackVertices[21] = Point({-149, -2, 0});
    m_TrackVertices[22] = Point({-155, -15, 0});
    m_TrackVertices[23] = Point({-169, -23, 0});
    m_TrackVertices[24] = Point({-196, -30, 0});
    m_TrackVertices[25] = Point({-246, -35, 0});
    m_TrackVertices[26] = Point({-283, -40, 0});
    m_TrackVertices[27] = Point({-308, -42, 0});
    m_TrackVertices[28] = Point({-344, -37, 0});
    m_TrackVertices[29] = Point({-383, -27, 0});
    m_TrackVertices[30] = Point({-396, -28, 0});
    m_TrackVertices[31] = Point({-401, -36, 0});
    m_TrackVertices[32] = Point({-401, -45, 0});
    m_TrackVertices[33] = Point({-397, -52, 0});
    m_TrackVertices[34] = Point({-384, -55, 0});
    m_TrackVertices[35] = Point({-363, -55, 0});
    m_TrackVertices[36] = Point({-341, -55, 0});
    m_TrackVertices[37] = Point({-299, -56, 0});
    m_TrackVertices[38] = Point({-247, -59, 0});
    m_TrackVertices[39] = Point({-213, -64, 0});
    m_TrackVertices[40] = Point({-171, -72, 0});
    m_TrackVertices[41] = Point({-146, -89, 0});
    m_TrackVertices[42] = Point({-123, -116, 0});
    m_TrackVertices[43] = Point({-113, -161, 0});
    m_TrackVertices[44] = Point({-116, -202, 0});
    m_TrackVertices[45] = Point({-107, -236, 0});
    m_TrackVertices[46] = Point({-74, -246, 0});
    m_TrackVertices[47] = Point({-45, -227, 0});
    m_TrackVertices[48] = Point({-34, -196, 0});
    m_TrackVertices[49] = Point({-36, -156, 0});
    m_TrackVertices[50] = Point({-32, -107, 0});
    m_TrackVertices[51] = Point({-28, -66, 0});
    m_TrackVertices[52] = Point({21, 66, 0});
    m_TrackVertices[53] = Point({24, 101, 0});
    m_TrackVertices[54] = Point({39, 131, 0});
    m_TrackVertices[55] = Point({59, 156, 0});
    m_TrackVertices[56] = Point({67, 181, 0});
    m_TrackVertices[57] = Point({66, 194, 0});
    m_TrackVertices[58] = Point({54, 216, 0});
    m_TrackVertices[59] = Point({37, 224, 0});
    m_TrackVertices[60] = Point({7, 239, 0});
    m_TrackVertices[61] = Point({-31, 241, 0});
    m_TrackVertices[62] = Point({-74, 241, 0});
    m_TrackVertices[63] = Point({-128, 230, 0});
    m_TrackVertices[64] = Point({-179, 219, 0});
    m_TrackVertices[65] = Point({-219, 185, 0});
    m_TrackVertices[66] = Point({-231, 135, 0});
    m_TrackVertices[67] = Point({-237, 93, 0});
    m_TrackVertices[68] = Point({-230, 57, 0});
    m_TrackVertices[69] = Point({-222, 29, 0});
    m_TrackVertices[70] = Point({-221, 22, 0});
    m_TrackVertices[71] = Point({-223, 9, 0});
    m_TrackVertices[72] = Point({-239, -1, 0});
    m_TrackVertices[73] = Point({-258, -6, 0});
    m_TrackVertices[74] = Point({-289, -8, 0});
    m_TrackVertices[75] = Point({-318, -7, 0});
    m_TrackVertices[76] = Point({-352, -6, 0});
    m_TrackVertices[77] = Point({-380, -6, 0});
    m_TrackVertices[78] = Point({-398, -7, 0});
    m_TrackVertices[79] = Point({-422, -12, 0});
    m_TrackVertices[80] = Point({-432, -34, 0});
    m_TrackVertices[81] = Point({-434, -50, 0});
    m_TrackVertices[82] = Point({-423, -60, 0});
    m_TrackVertices[83] = Point({-406, -71, 0});
    m_TrackVertices[84] = Point({-381, -78, 0});
    m_TrackVertices[85] = Point({-348, -80, 0});
    m_TrackVertices[86] = Point({-306, -82, 0});
    m_TrackVertices[87] = Point({-269, -83, 0});
    m_TrackVertices[88] = Point({-231, -91, 0});
    m_TrackVertices[89] = Point({-205, -102, 0});
    m_TrackVertices[90] = Point({-173, -119, 0});
    m_TrackVertices[91] = Point({-159, -154, 0});
    m_TrackVertices[92] = Point({-160, -186, 0});
    m_TrackVertices[93] = Point({-151, -224, 0});
    m_TrackVertices[94] = Point({-132, -259, 0});
    m_TrackVertices[95] = Point({-101, -274, 0});
    m_TrackVertices[96] = Point({-59, -273, 0});
    m_TrackVertices[97] = Point({-11, -258, 0});
    m_TrackVertices[98] = Point({18, -218, 0});
    m_TrackVertices[99] = Point({22, -182, 0});
    m_TrackVertices[100] = Point({24, -155, 0});
    m_TrackVertices[101] = Point({24, -112, 0});
    m_TrackVertices[102] = Point({25, -71, 0});


    m_TrackEdgeIndices[0] = 0;
    m_TrackEdgeIndices[1] = 51;
    m_TrackEdgeIndices[2] = 0;
    m_TrackEdgeIndices[3] = 1;
    m_TrackEdgeIndices[4] = 2;
    m_TrackEdgeIndices[5] = 102;
    m_TrackEdgeIndices[6] = 2;
    m_TrackEdgeIndices[7] = 3;
    m_TrackEdgeIndices[8] = 1;
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
    m_TrackEdgeIndices[104] = 3;
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
        Point p1 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i]]), camera.GetPosition(), camera.GetRotation());
        Point p2 = InverseTransformPoint(m_TrackTranslation + (m_TrackRotation * m_TrackVertices[m_TrackEdgeIndices[i + 1]]), camera.GetPosition(), camera.GetRotation());

        p1 = Point({64 + p1.X(), 32 - p1.Y(), 0});
        p2 = Point({64 + p2.X(), 32 - p2.Y(), 0});

        display.drawLine(p1.X(), p1.Y(), p2.X(), p2.Y(), WHITE);
    }
}
