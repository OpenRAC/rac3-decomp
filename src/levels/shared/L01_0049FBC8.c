#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* localdecomp:start func_L01_0049FBC8 */
typedef struct {
    u8 pad0[0x14];
    s32 a[3][4];
    s32 b[3][4];
    s32 c[3][4];
} S_143950_0049FBC8;

extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_004A0300_0049FBC8(void);
extern u8 D_001A71C4[];
extern s32 D_L01_002ED730_0049FBC8[][4][3];
extern s32 D_L01_001E0CD0_0049FBC8[2];
extern s32 D_L01_001D9570_0049FBC8;
__asm__(".extern D_L01_001D9570_0049FBC8, 4");
extern S_143950_0049FBC8 D_00143950;
extern s32 D_00143A10[][8];
extern s32 D_00143A70[][8];
extern s32 D_00143AD0[][8];

void func_L01_0049FBC8(void) {
    s32 i;
    s32 r;
    s32 w;

    i = 0;
    r = func_003B9C58(func_003B9BD0(0));
    func_003A5348(3, 0, 0);
    if ((D_001A71C4[0] != 1 || r != 0) && r != 3) {
        D_L01_002ED730_0049FBC8[r][0][0]++;
        if (D_L01_002ED730_0049FBC8[r][0][2] < D_L01_002ED730_0049FBC8[r][0][0]) {
            D_L01_002ED730_0049FBC8[r][0][0] = D_L01_002ED730_0049FBC8[r][0][1];
        }
    }
    switch (D_L01_002ED730_0049FBC8[0][i][0]) {
    case 0:
        D_L01_001E0CD0_0049FBC8[i] = 0;
        break;
    case 1:
        D_L01_001E0CD0_0049FBC8[i] = 2;
        break;
    case 2:
        D_L01_001E0CD0_0049FBC8[i] = 1;
        break;
    }
    if (r == 0) {
        func_L01_004A0300_0049FBC8();
    }
    w = D_L01_001E0CD0_0049FBC8[i];
    D_00143950.a[w][i] = D_L01_002ED730_0049FBC8[1][i][0];
    D_00143950.b[w][i] = D_L01_002ED730_0049FBC8[2][i][0];
    ((u8 *)&D_00143950)[D_L01_001D9570_0049FBC8 + 0xAE] = D_L01_002ED730_0049FBC8[4][i][0];
    ((u8 *)&D_00143950)[0xB6] = D_L01_002ED730_0049FBC8[5][i][0];
    D_00143A10[w][0] = D_00143950.a[w][i];
    D_00143A70[w][0] = D_00143950.b[w][i];
    D_00143AD0[w][0] = D_00143950.c[w][i];
}
/* localdecomp:end func_L01_0049FBC8 */

/* localdecomp:start func_L01_0049FDF0 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_L01_0049FDF0;
extern f32 D_L01_001D9578;
extern f32 D_L01_001D957C;
extern f32 D_L01_001D9580;
extern f32 D_L01_001D9584;
extern f32 D_L01_001D9588;
__asm__(".extern D_L01_001D9578, 4");
__asm__(".extern D_L01_001D957C, 4");
__asm__(".extern D_L01_001D9580, 4");
__asm__(".extern D_L01_001D9584, 4");
__asm__(".extern D_L01_001D9588, 4");
extern char D_L01_001D9638[];
extern char D_L01_001D9640[];
extern char D_L01_001D9648[];
extern u8 D_001A71C4[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BA358();
extern void func_L01_00498F18(void *, s32, s32);
extern void func_L01_00498948(void *, s32, s32);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_11B2E8();

void func_L01_0049FDF0(void) {
    S_L01_0049FDF0 s;
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(1);
    s.f8 = 0x14;
    s.fC = 6;
    s.f10 = 6;
    s.f14 = 2;
    s.f18 = 1.0f;
    s.f1C = D_L01_001D9578;
    s.f20 = D_L01_001D957C;
    s.a24[0] = D_L01_001D9580;
    s.a24[1] = D_L01_001D9584;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = D_L01_001D9588;
    s.a34[1] = D_L01_001D9584 - D_L01_001D9580 - D_L01_001D9588;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.815505981f, 0.0450000018f, 0.0425000004f, 0.349999994f, 0);
    func_003BA4E0(func_003B9BD0(0), 1, 0.023f, 0.00665999996f, 0.0299999993f);
    func_003BABD0(func_003B9BD0(0), 0.5f, 0.712166011f, 0.815505981f, 0.292499006f);
    func_003BA358(func_003B9BD0(0), 0, 1, 3);
    func_003BA358(func_003B9BD0(0), 1, 2, 3);
    func_L01_00498F18(func_003B9BD0(0), 0, 1);
    func_L01_00498F18(func_003B9BD0(0), 1, 1);
    if (D_001A71C4[0] == 1) {
        func_L01_00498948(func_003B9BD0(0), 0, 1);
    } else {
        func_L01_00498948(func_003B9BD0(0), 0, 0);
    }
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, 0), D_L01_001D9638, func_00381FF0(0x15E3));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, 1), D_L01_001D9640, func_00381FF0(0x191));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, 2), D_L01_001D9640, func_00381FF0(0x190));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, 3), D_L01_001D9640, func_00381FF0(0x23C));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, 4), D_L01_001D9640, func_00381FF0(0x18F));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, 5), D_L01_001D9638, func_00381FF0(0x507));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 0), D_L01_001D9638, func_00381FF0(0x1359));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 1), D_L01_001D9638, func_00381FF0(0x192));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 2), D_L01_001D9638, func_00381FF0(0x192));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 3), D_L01_001D9648);
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 4), D_L01_001D9638, func_00381FF0(0x176));
    func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 5), D_L01_001D9638, func_00381FF0(0x176));
}
/* localdecomp:end func_L01_0049FDF0 */

/* localdecomp:start func_L01_004A02B8 */
extern S_func_0049A930 D_00160C40[];
extern s32 D_L01_001D9590;
__asm__(".extern D_L01_001D9590, 4");
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);

void func_L01_004A02B8(void) {
    D_L01_001D9590 = (s32)func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), D_L01_001D9590, 0, D_00160C40->f4954, (s32)D_00160C40->f4B90);
}
/* localdecomp:end func_L01_004A02B8 */

/* localdecomp:start func_L01_004A0300 */
__asm__(".extern D_L01_001D9570_0049FBC8, 4");
typedef struct {
    u8 pad0[0x14];
    s32 a[3][4];
    s32 b[3][4];
    s32 c[3][4];
    u8 padA4[0xAE - 0xA4];
    u8 fAE[8];
    u8 fB6;
} S_143950_004A0300;
extern S_143950_004A0300 D_00143950_004A0300;

void func_L01_004A0300(void) {
    s32 i = 0;
    s32 w = D_L01_001E0CD0_0049FBC8[i];

    D_L01_002ED730_0049FBC8[1][i][0] = D_00143950_004A0300.a[w][i];
    D_L01_002ED730_0049FBC8[2][i][0] = D_00143950_004A0300.b[w][i];
    D_L01_001D9570_0049FBC8 = 0;
    if (D_00143950_004A0300.c[w][i] < 50) {
        D_L01_002ED730_0049FBC8[3][i][0] = 0;
    } else if (D_00143950_004A0300.c[w][i] < 88) {
        D_L01_002ED730_0049FBC8[3][i][0] = 1;
    } else {
        D_L01_002ED730_0049FBC8[3][i][0] = 2;
    }
    D_L01_002ED730_0049FBC8[4][i][0] = D_00143950_004A0300.fAE[D_L01_001D9570_0049FBC8];
    D_L01_002ED730_0049FBC8[5][i][0] = D_00143950_004A0300.fB6;
}
/* localdecomp:end func_L01_004A0300 */

/* localdecomp:start func_L01_004A03A8 */
extern s32 D_L01_001E0CC0[2];
extern u8 D_001439F4[];
extern void func_L01_00514508(s32);
extern void func_003BB468(s32);

void func_L01_004A03A8(void) {
    s32 m;
    O_49A988 *o;

    if (D_L01_001E0CD0_0049FBC8[0] != D_L01_001E0CC0[0]) {
        m = 0;
        switch (D_L01_001E0CD0_0049FBC8[0]) {
        case 2: m = 2; break;
        case 1: m = 1; break;
        case 0: m = 0; break;
        }
        D_001439F4[0] = m;
        func_L01_00514508(m);
    }
    o = (O_49A988 *)func_003B42F8(0);
    o->vt->fn(o);
    func_003BB468(D_L01_001D9590);
}
/* localdecomp:end func_L01_004A03A8 */

INCLUDE_ASM("asm/levels", func_L01_004A0430);

/* localdecomp:start func_L01_004A04B8 */
extern s32 D_L01_001D9574;
__asm__(".extern D_L01_001D9574, 4");
extern s32 D_L01_00236AB8_004A04B8[6][3];
extern s32 func_0011B2E8(char *, char *, ...);

void func_L01_004A04B8(void) {
    s32 r;
    s32 i = 0;

    for (r = 0; r < D_L01_001D9574; r++) {
        if (r == 2 && D_L01_001E0CD0_0049FBC8 == 0) {
            func_0011B2E8((char *)func_003B9E30(func_003B9BD0(0), 1, r), D_L01_001D9638, D_L01_00236AB8_004A04B8[r][D_L01_002ED730_0049FBC8[r][i][0] ? 0 : 1]);
        } else if (r != 3) {
            func_0011B2E8((char *)func_003B9E30(func_003B9BD0(0), 1, r), D_L01_001D9638, D_L01_00236AB8_004A04B8[r][D_L01_002ED730_0049FBC8[r][i][0]]);
        }
    }
}
/* localdecomp:end func_L01_004A04B8 */

/* localdecomp:start func_L01_004A0608 */

extern s32 D_L01_002ED730[];
extern S_236B80 D_L01_00236B00;

extern s32 func_L01_00516FD8(s32 id, s32 v);

void func_L01_004A0608(void) {
    func_L01_00516FD8(0x54000A, D_L01_00236B00.v[0][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54000E, D_L01_00236B00.v[1][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540012, D_L01_00236B00.v[2][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540016, D_L01_00236B00.v[3][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54001A, D_L01_00236B00.v[4][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54001E, D_L01_00236B00.v[5][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540022, D_L01_00236B00.v[10][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540026, D_L01_00236B00.v[11][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54002A, D_L01_00236B00.v[8][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x54002E, D_L01_00236B00.v[7][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540032, D_L01_00236B00.v[6][D_L01_002ED730[0]]);
    func_L01_00516FD8(0x540036, D_L01_00236B00.v[9][D_L01_002ED730[0]]);
}
/* localdecomp:end func_L01_004A0608 */

/* localdecomp:start func_L01_004A0788 */
typedef struct {
    s32 v[12][3];
} S_236B80_004A0788;

extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 D_L01_00236AB8_004A0788[6][3];
extern S_236B80_004A0788 D_L01_00236B00_004A0788;
extern char D_L01_001D9650_004A0788[];
extern char D_L01_001D95A8_004A0788[8];
extern char D_L01_001D95B0_004A0788[8];
extern char D_L01_001D95D0_004A0788[8];
extern char D_L01_001D95F0_004A0788[8];
__asm__(".extern D_L01_001D95A8_004A0788, 8");
__asm__(".extern D_L01_001D95B0_004A0788, 8");
__asm__(".extern D_L01_001D95D0_004A0788, 8");
__asm__(".extern D_L01_001D95F0_004A0788, 8");

void func_L01_004A0788(void) {
    D_L01_00236AB8_004A0788[0][0] = (s32)func_00381FF0(0x1359);
    D_L01_00236AB8_004A0788[1][0] = (s32)func_00381FF0(0x192);
    D_L01_00236AB8_004A0788[2][0] = (s32)func_00381FF0(0x192);
    D_L01_00236AB8_004A0788[3][0] = (s32)func_00381FF0(0x23B);
    D_L01_00236AB8_004A0788[4][0] = (s32)func_00381FF0(0x176);
    D_L01_00236AB8_004A0788[5][0] = (s32)func_00381FF0(0x176);
    D_L01_00236AB8_004A0788[0][1] = (s32)func_00381FF0(0x1357);
    D_L01_00236AB8_004A0788[1][1] = (s32)func_00381FF0(0x193);
    D_L01_00236AB8_004A0788[2][1] = (s32)func_00381FF0(0x193);
    D_L01_00236AB8_004A0788[3][1] = (s32)func_00381FF0(0x23A);
    D_L01_00236AB8_004A0788[4][1] = (s32)func_00381FF0(0x175);
    D_L01_00236AB8_004A0788[5][1] = (s32)func_00381FF0(0x175);
    D_L01_00236AB8_004A0788[0][2] = (s32)func_00381FF0(0x1358);
    D_L01_00236AB8_004A0788[1][2] = (s32)func_00381FF0(0);
    D_L01_00236AB8_004A0788[2][2] = (s32)func_00381FF0(0);
    D_L01_00236AB8_004A0788[3][2] = (s32)func_00381FF0(0x239);
    D_L01_00236AB8_004A0788[4][2] = (s32)func_00381FF0(0);
    D_L01_00236AB8_004A0788[5][2] = (s32)func_00381FF0(0);
    func_0011B2E8(D_L01_001D95B0_004A0788, D_L01_001D9650_004A0788, 0x16, func_00381FF0(0x1826));
    func_0011B2E8(D_L01_001D95D0_004A0788, D_L01_001D9650_004A0788, 0x17, func_00381FF0(0x181D));
    D_L01_00236B00_004A0788.v[0][0] = (s32)func_00381FF0(0x180D);
    D_L01_00236B00_004A0788.v[1][0] = (s32)func_00381FF0(0x180A);
    D_L01_00236B00_004A0788.v[2][0] = (s32)D_L01_001D95F0_004A0788;
    D_L01_00236B00_004A0788.v[3][0] = (s32)func_00381FF0(0x180B);
    D_L01_00236B00_004A0788.v[4][0] = (s32)func_00381FF0(0x1809);
    D_L01_00236B00_004A0788.v[5][0] = (s32)func_00381FF0(0x181C);
    D_L01_00236B00_004A0788.v[6][0] = (s32)func_00381FF0(0x180E);
    D_L01_00236B00_004A0788.v[7][0] = (s32)func_00381FF0(0x194B);
    D_L01_00236B00_004A0788.v[8][0] = (s32)func_00381FF0(0x1810);
    D_L01_00236B00_004A0788.v[9][0] = (s32)func_00381FF0(0x1811);
    D_L01_00236B00_004A0788.v[10][0] = (s32)func_00381FF0(0x180C);
    D_L01_00236B00_004A0788.v[11][0] = (s32)func_00381FF0(0x8E6);
    D_L01_00236B00_004A0788.v[0][1] = (s32)func_00381FF0(0x1816);
    D_L01_00236B00_004A0788.v[1][1] = (s32)func_00381FF0(0x194B);
    D_L01_00236B00_004A0788.v[2][1] = (s32)D_L01_001D95A8_004A0788;
    D_L01_00236B00_004A0788.v[3][1] = (s32)func_00381FF0(0x1813);
    D_L01_00236B00_004A0788.v[4][1] = (s32)func_00381FF0(0x181E);
    D_L01_00236B00_004A0788.v[5][1] = (s32)func_00381FF0(0x181C);
    D_L01_00236B00_004A0788.v[6][1] = (s32)func_00381FF0(0x1816);
    D_L01_00236B00_004A0788.v[7][1] = (s32)func_00381FF0(0x194B);
    D_L01_00236B00_004A0788.v[8][1] = (s32)func_00381FF0(0x1818);
    D_L01_00236B00_004A0788.v[9][1] = (s32)func_00381FF0(0x1819);
    D_L01_00236B00_004A0788.v[10][1] = (s32)func_00381FF0(0x1815);
    D_L01_00236B00_004A0788.v[11][1] = (s32)func_00381FF0(0x8E6);
    D_L01_00236B00_004A0788.v[0][2] = (s32)func_00381FF0(0x1820);
    D_L01_00236B00_004A0788.v[1][2] = (s32)func_00381FF0(0x194B);
    D_L01_00236B00_004A0788.v[2][2] = (s32)D_L01_001D95B0_004A0788;
    D_L01_00236B00_004A0788.v[3][2] = (s32)D_L01_001D95D0_004A0788;
    D_L01_00236B00_004A0788.v[4][2] = (s32)func_00381FF0(0x181E);
    D_L01_00236B00_004A0788.v[5][2] = (s32)func_00381FF0(0x1825);
    D_L01_00236B00_004A0788.v[6][2] = (s32)func_00381FF0(0x1820);
    D_L01_00236B00_004A0788.v[7][2] = (s32)func_00381FF0(0x194B);
    D_L01_00236B00_004A0788.v[8][2] = (s32)func_00381FF0(0x1822);
    D_L01_00236B00_004A0788.v[9][2] = (s32)func_00381FF0(0x1823);
    D_L01_00236B00_004A0788.v[10][2] = (s32)func_00381FF0(0x181F);
    D_L01_00236B00_004A0788.v[11][2] = (s32)func_00381FF0(0x8E6);
}
/* localdecomp:end func_L01_004A0788 */

/* localdecomp:start func_L01_004A0A78 */
void func_L01_004A0A78(void) {

}
/* localdecomp:end func_L01_004A0A78 */

/* localdecomp:start func_L01_004A0A80 */
extern void func_L01_004A0AF8(s32);

void func_L01_004A0A80(void) {
    func_L01_004A0AF8(0);
    func_L01_004A0AF8(1);
    func_L01_004A0AF8(2);
    func_L01_004A0AF8(3);
    func_L01_004A0AF8(4);
    func_L01_004A0AF8(5);
    func_L01_004A0AF8(6);
    func_L01_004A0AF8(7);
    func_L01_004A0AF8(8);
    func_L01_004A0AF8(9);
    func_L01_004A0AF8(10);
    func_L01_004A0AF8(11);
}
/* localdecomp:end func_L01_004A0A80 */

/* localdecomp:start func_L01_004A0AF8 */
typedef struct {
    s32 v[12][3];
} S_236B80_004A0AF8;

extern s32 D_L01_002ED730_004A0AF8[];
extern S_236B80_004A0AF8 D_L01_00236B00_004A0AF8;
extern f32 D_L01_001DC0E8_004A0AF8;
extern s32 D_L01_001D95F8_004A0AF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D95F8_004A0AF8, 4");
extern s32 func_L01_00516558_004A0AF8(s32, f32 *, f32 *);
extern s32 func_L01_00516C78_004A0AF8(s32, s32 *, s32 *);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_L01_00516470_004A0AF8(s32, f32, f32);
extern void func_L01_00517538_004A0AF8(s32, f32, f32);
extern void func_L01_00516B90_004A0AF8(s32, s32, s32);
extern void func_0038E150(s32);
extern s32 func_0038E548(f32, s32, s32);

void func_L01_004A0AF8(s32 p) {
    f32 w = 0.0f;
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 h = 0.0f;
    s32 al0, al1;
    s32 id = D_L01_001D95F8_004A0AF8[p];
    f32 a, b, c, d, e, m;
    f32 t;
    f32 u;
    f32 bw;
    a = 0.00800000038f;
    b = 0.00240399991f;
    e = 0.00195299997f;
    m = 0.00999999978f;
    c = 0.0156239998f;
    d = 0.0384639986f;
    if ((u32)(p - 2) < 2) {
        f32 r[4];
        r[0] = 0.0f; r[1] = 0.0f; r[2] = 0.0f; r[3] = 0.0f;
        func_L01_00516558_004A0AF8(0x540012, &r[0], &r[1]);
        func_L01_00516558_004A0AF8(0x540016, &r[2], &r[3]);
        al0 = 3;
        al1 = 3;
        func_0038E150(1);
        u = (f32)func_0038E548(1.0f, D_L01_00236B00_004A0AF8.v[2][D_L01_002ED730_004A0AF8[0]], -1) / D_L01_001DC0E8_004A0AF8;
        t = (f32)func_0038E548(1.0f, D_L01_00236B00_004A0AF8.v[3][D_L01_002ED730_004A0AF8[0]], -1) / D_L01_001DC0E8_004A0AF8;
        w = (t < u) ? u : t;
        id = 0x540012;
        d = 0.0865439996f;
        x = (r[0] + r[2]) * 0.5f;
        y = (r[1] + r[3]) * 0.5f - b;
        func_003E7AC8(0x540016, 0);
    } else {
        func_L01_00516558_004A0AF8(id, &x, &y);
        func_L01_00516C78_004A0AF8(id, &al0, &al1);
        func_0038E150(1);
        w = (f32)func_0038E548(1.0f, D_L01_00236B00_004A0AF8.v[p][D_L01_002ED730_004A0AF8[0]], -1) / D_L01_001DC0E8_004A0AF8;
    }
    h = d + m;
    y = y - b;
    bw = (c + a) + w;
    switch (al0) {
    case 1:
        x += (bw - a - c) * 0.5f;
        break;
    case 2:
        x -= (bw - a - c) * 0.5f;
        break;
    }
    switch (al1) {
    case 1:
        y += h * 0.5f;
        break;
    case 2:
        y -= h * 0.5f;
        break;
    }
    func_003E7AC8(id, 0);
    func_L01_00516470_004A0AF8(id + 1, x, y);
    func_L01_00517538_004A0AF8(id + 1, bw, h);
    func_L01_00516470_004A0AF8(id + 2, x, y);
    func_L01_00517538_004A0AF8(id + 2, bw - 0.00800000038f, h - 0.00999999978f);
    func_L01_00516470_004A0AF8(id + 3, x + e * 4.0f, y + b * 4.0f);
    func_L01_00517538_004A0AF8(id + 3, bw, h);
    func_L01_00516B90_004A0AF8(id + 1, 3, 3);
    func_L01_00516B90_004A0AF8(id + 2, 3, 3);
    func_L01_00516B90_004A0AF8(id + 3, 3, 3);
}
/* localdecomp:end func_L01_004A0AF8 */

/* localdecomp:start func_L01_004A0F28 */
void func_L01_004A0F28(s32 pad) {
    s32 i = 0;

    if (func_003B9C58(func_003B9BD0(0)) == 3) {
        if (pad & 0x8000) {
            D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i] = (D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i] - 2 < 0) ? 0 : D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i] - 2;
            func_003A5348(3, 0, 0);
        } else if (pad & 0x2000) {
            D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i] = (D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i] + 2 > 100) ? 100 : D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i] + 2;
            func_003A5348(3, 0, 0);
        }
        D_00143AD0[D_L01_001E0CD0_0049FBC8[i]][i] = D_00143950.c[D_L01_001E0CD0_0049FBC8[i]][i];
    }
}
/* localdecomp:end func_L01_004A0F28 */

/* localdecomp:start func_L01_004A1050 */
typedef struct {
    u8 pad0[0x14];
    s32 a[3][4];
    s32 b[3][4];
    s32 c[3][4];
} S_143950_0049FBC8_004A1050;

extern s32 D_L01_001E0CD0_0049FBC8[2];
extern S_143950_0049FBC8_004A1050 D_00143950_004A1050;
extern f32 D_L01_001D9580_004A1050;
__asm__(".extern D_L01_001D9580_004A1050, 4");
extern f32 D_L01_001D9584_004A1050;
__asm__(".extern D_L01_001D9584_004A1050, 4");
extern f32 D_L01_001D9588_004A1050;
__asm__(".extern D_L01_001D9588_004A1050, 4");
extern void func_L01_00516558_004A1050(s32, f32 *, f32 *);
extern s32 func_L01_00516470_004A1050(s32, f32, f32);

void func_L01_004A1050(void) {
    f32 buf[2];
    f32 t = (f32)D_00143950_004A1050.c[D_L01_001E0CD0_0049FBC8[0]][0] / 100.0f;
    f32 k = 0.012f;
    f32 x;

    buf[1] = buf[0] = 0.0f;
    func_L01_00516558_004A1050(0x54003D, &buf[0], &buf[1]);
    x = D_L01_001D9580_004A1050 + D_L01_001D9588_004A1050;
    buf[0] = x + 0.007f + (D_L01_001D9584_004A1050 - x - k) * t;
    func_L01_00516470_004A1050(0x54003D, buf[0], buf[1]);
}
/* localdecomp:end func_L01_004A1050 */

LINKER_REMNANT("asm/levels", func_L01_004A1120);

/* localdecomp:start func_L01_004A1128 */
extern s32 func_L01_004A1128(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0CF8;
extern s32 D_L01_001E0CE0[2];
__asm__(".extern D_L01_001E0CF8, 4");
__asm__(".extern D_L01_001E0CE0, 8");
extern void func_L01_004A1180();
extern void func_L01_004A15B0();
extern void func_L01_004A1520();
extern void func_L01_004A15F0_004A1128(void);
extern void func_L01_004A1610_004A1128();
s32 func_L01_004A1128(void) {
    if (D_L01_001E0CF8 == 0) {
        func_003E6FA0(D_L01_001E0CE0, (s32)func_L01_004A1180, (s32)func_L01_004A15B0, (s32)func_L01_004A1520, (s32)func_L01_004A15F0_004A1128, (s32)func_L01_004A1610_004A1128);
        D_L01_001E0CF8 = 1;
    }
    return (s32)D_L01_001E0CE0;
}
/* localdecomp:end func_L01_004A1128 */

INCLUDE_ASM("asm/levels", func_L01_004A1180);

/* localdecomp:start func_L01_004A1520 */
extern void func_003BA4F8(void *, s32);
extern u8 *D_001D52FC;
extern void func_L01_004A1E18(void);
extern void func_L01_004A1D40(s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern void func_L01_00516090_004A1520(s32);
extern u8 D_L01_001D672C;
__asm__(".extern D_L01_001D672C, 16");
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

void func_L01_004A1520(s32 a0) {
    func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
    func_L01_004A1E18();
    func_L01_004A1D40(a0);
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_004A1520(a0);
        if (D_L01_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_004A1520 */

/* localdecomp:start func_L01_004A15B0 */
extern void func_L01_00517918(s32);
extern void func_L01_004A1D00(void);
extern void func_003A2750(s32);

void func_L01_004A15B0(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_004A1D00();
    func_003A2750(1);
}
/* localdecomp:end func_L01_004A15B0 */

/* localdecomp:start func_L01_004A15F0 */
extern void func_L01_0047E4B8_004A15F0();

void func_L01_004A15F0(void) {
    func_L01_0047E4B8_004A15F0();
}
/* localdecomp:end func_L01_004A15F0 */

/* localdecomp:start func_L01_004A1610 */
extern void func_L01_0047E520_004A1610();

void func_L01_004A1610(void) {
    func_L01_0047E520_004A1610();
}
/* localdecomp:end func_L01_004A1610 */
