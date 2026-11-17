#include "common.h"

/* declared by functions of L39_006DC228.c, which this file was cut from */
extern f32 D_001A6950[];
extern void func_L39_006DF4E8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);

/* localdecomp:start func_L39_006DF760 */
typedef struct {
    s16 b;
    s16 a;
} P_006DF760;
typedef struct {
    char _p0[0x120];
    s32 team[8];
    s16 hit[8][2];
    u8 b160[16];
    u8 b170[8];
    u8 b178[8];
    f32 f180[8];
    f32 f1A0[2];
    s32 winner;
    char _p1AC[0x1B8 - 0x1AC];
    s16 h1B8[8];
    P_006DF760 tbl[8][9];
    char _p2E8[0x808 - 0x2E8];
    s32 f808;
    s32 mode;
    char _p810[0x81C - 0x810];
    s32 f81C;
    s32 f820;
    s32 f824;
} S_006DF760;
/* D_001FD7E8 is declared later in this file as S_006E0150; this alias needs
   `D_001FD7E8_006DF760 = 0x1FD7E8;` in symbol_addrs_resolved.txt. */
extern S_006DF760 D_001FD7E8_006DF760;
extern f32 D_001A6950[];
s32 func_L39_00672118(s32);
void func_L39_006DF640(s32);
void func_L39_006DF450(s32 *, s32, s32, s32);
void func_L39_006DF4E8(s32 *, s32, s32, s32);
f32 func_003C4088(f32, f32, f32);

void func_L39_006DF760(s32 *s, s32 p, f32 f) {
    s32 win;
    s32 lose;
    s32 cur;
    s32 w;
    s32 r;
    s32 k, i1, i3, i4, j1, j2, j3;
    s32 a, b, c, n, i2;
    f32 d;
    f32 x;
    s32 i;

    win = 0;
    lose = 0;
    cur = D_001FD7E8_006DF760.team[p];
    w = D_001FD7E8_006DF760.winner;
    if (w != -1) {
        if (w == cur) {
            win = 1;
        } else {
            lose = 1;
        }
    }
    s[2] += win;
    s[3] += lose;
    func_L39_006DF4E8(s, 4, 2, 3);
    s[5] += D_001FD7E8_006DF760.hit[p][0];
    s[6] += D_001FD7E8_006DF760.hit[p][1];
    func_L39_006DF4E8(s, 8, 5, 6);
    if (D_001FD7E8_006DF760.mode != 2) {
        d = D_001FD7E8_006DF760.f1A0[cur];
        if (0.0f < d) {
            s[9] += (s32)(D_001FD7E8_006DF760.f180[p] * 100.0f / d);
        }
        s[10] += D_001FD7E8_006DF760.b160[p];
    }
    s[7] += D_001FD7E8_006DF760.h1B8[p];
    s[11] += 1;
    s[0x59] += D_001FD7E8_006DF760.f81C;
    s[0x5C] += D_001FD7E8_006DF760.f820;
    s[0x5F] += D_001FD7E8_006DF760.f824;
    func_L39_006DF450(s, 0x5A, 0x59, 0xB);
    func_L39_006DF450(s, 0x5D, 0x5C, 0xB);
    func_L39_006DF450(s, 0x60, 0x5F, 0xB);
    func_L39_006DF4E8(s, 0x5B, 0x59, 5);
    func_L39_006DF4E8(s, 0x5E, 0x5C, 6);
    func_L39_006DF450(s, 0x45, 5, 0xB);
    func_L39_006DF450(s, 0x46, 6, 0xB);
    func_L39_006DF450(s, 0x47, 7, 0xB);
    func_L39_006DF450(s, 0x48, 0xA, 0xB);
    func_L39_006DF450(s, 0x49, 9, 0xB);
    if (D_001FD7E8_006DF760.f808 == 2) {
        func_L39_006DF640(p);
        s[0xD] += win;
        s[0xE] += lose;
    }
    r = func_L39_00672118(1);
    s[20] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[21] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(2);
    s[32] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[33] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(7);
    s[22] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[23] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(5);
    s[24] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[25] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(3);
    s[26] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[27] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(6);
    s[28] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[29] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(9);
    s[30] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[31] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(4);
    s[34] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[35] += D_001FD7E8_006DF760.tbl[p][r].b;
    r = func_L39_00672118(10);
    s[36] += D_001FD7E8_006DF760.tbl[p][r].a;
    s[37] += D_001FD7E8_006DF760.tbl[p][r].b;

    k = 0;
    i1 = 0;
    i3 = 0;
    n = 0;
    i2 = 0;
    i4 = 0;
    j1 = 0;
    j2 = 0;
    j3 = 0;
    a = 0;
    b = 0;
    c = 0;
    switch (D_001FD7E8_006DF760.mode) {
    case 0:
        d = D_001FD7E8_006DF760.f1A0[cur];
        if (0.0f < d) {
            s[44] += (s32)(D_001FD7E8_006DF760.f180[p] * 100.0f / d);
        }
        s[45] += D_001FD7E8_006DF760.b160[p];
        n = 0x2E;
        func_L39_006DF450(s, 0x4D, 0x2C, n);
        i1 = 0x29;
        i2 = 0x2A;
        func_L39_006DF450(s, 0x4C, 0x2D, n);
        a = 0x26;
        b = 0x27;
        c = 0x28;
        i3 = 0x2B;
        i4 = 0x42;
        j1 = 0x4A;
        j2 = 0x4B;
        j3 = 0x4E;
        k = 0x11;
        break;
    case 2:
        n = 0x35;
        a = 0x2F;
        b = 0x30;
        c = 0x31;
        i2 = 0x33;
        i1 = 0x32;
        i3 = 0x34;
        i4 = 0x44;
        j1 = 0x56;
        j2 = 0x57;
        j3 = 0x58;
        k = 0x12;
        break;
    case 1:
        d = D_001FD7E8_006DF760.f1A0[cur];
        if (0.0f < d) {
            s[60] += (s32)(D_001FD7E8_006DF760.f180[p] * 100.0f / d);
        }
        s[61] += D_001FD7E8_006DF760.b160[p];
        s[62] += D_001FD7E8_006DF760.b170[p];
        s[63] += D_001FD7E8_006DF760.b178[p];
        i1 = 0x39;
        n = 0x40;
        i2 = 0x3A;
        i3 = 0x3B;
        i4 = 0x43;
        j1 = 0x4F;
        j2 = 0x50;
        j3 = 0x55;
        k = 0x13;
        func_L39_006DF450(s, 0x52, 0x3C, 0x40);
        func_L39_006DF450(s, 0x51, 0x3D, 0x40);
        func_L39_006DF450(s, 0x53, 0x3E, 0x40);
        func_L39_006DF450(s, 0x54, 0x3F, 0x40);
        a = 0x36;
        b = 0x37;
        c = 0x38;
        break;
    }
    s[a] += win;
    s[b] += lose;
    func_L39_006DF4E8(s, c, a, b);
    s[i1] += D_001FD7E8_006DF760.hit[p][0];
    s[i2] += D_001FD7E8_006DF760.hit[p][1];
    func_L39_006DF4E8(s, i3, i1, i2);
    s[i4] += D_001FD7E8_006DF760.h1B8[p];
    func_L39_006DF450(s, j1, i1, n);
    func_L39_006DF450(s, j2, i2, n);
    func_L39_006DF450(s, j3, i4, n);
    s[n]++;
    x = (f32)s[n];
    if (x < D_001A6950[0xEC / 4]) {
        if (D_001A6950[0xF0 / 4] < x) {
            s[k] = (s32)func_003C4088(0.0f, f * 100.0f,
                                      (x - D_001A6950[0xF0 / 4]) / (D_001A6950[0xEC / 4] - D_001A6950[0xF0 / 4]));
        } else {
            s[k] = 0;
        }
    } else {
        s[k] = (s32)(f * 100.0f);
    }
    s[1] = (s32)((f32)(s[17] + s[19] + s[18]) / 3.0f);
    for (i = 0; i < 100; i++) {
        if (i != 0 && i != 12 && i != 65 && s[i] < 0) {
            s[i] = 0;
        }
    }
}
/* localdecomp:end func_L39_006DF760 */
