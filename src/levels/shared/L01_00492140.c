#include "common.h"

typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6EC0 - 0x4958];
    u8 fX[1];
} S_func_0048E5D8;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} E_002EB338;
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;

/* declared by functions of L01_00491A30.c, which this file was cut from */
extern s32 func_003B9BD0(s32);

/* localdecomp:start func_L01_00492140 */
typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14;
    f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4];
} S_00492140;
extern S_48F880e D_L01_002EB2E8_00492140[];
extern s32 D_L01_001D8E08;
extern s32 D_L01_001D8E0C;
extern s32 D_L01_001D8E10;
extern s32 D_L01_001D8E14;
__asm__(".extern D_L01_001D8E08, 4");
__asm__(".extern D_L01_001D8E0C, 4");
__asm__(".extern D_L01_001D8E10, 4");
__asm__(".extern D_L01_001D8E14, 4");
extern f32 D_L01_001D8E3C;
extern f32 D_L01_001D8E40;
__asm__(".extern D_L01_001D8E3C, 4");
__asm__(".extern D_L01_001D8E40, 4");
extern s32 D_001D545C;
extern char D_L01_001D8E48[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern void func_003B9C68(s32, S_00492140 *);
extern void func_003BABB0(s32, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern char *func_003B9E30(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_00498948(s32, s32, s32);

/* layout as frontbin's func_003B5D70 (same menu setup) */
void func_L01_00492140(void) {
    S_00492140 s;
    s32 n = 0;
    s32 i = 0;
    s32 j;
    s32 hidden;
    f32 c1;
    f32 c2;

    D_L01_001D8E10 = -1;
    D_L01_001D8E14 = -1;
    D_L01_001D8E08 = -1;
    D_L01_001D8E0C = -1;
    while (D_L01_002EB2E8_00492140[n].w0 > 0) {
        switch (D_L01_002EB2E8_00492140[n].w0) {
        case 0x507: D_L01_001D8E10 = n; break;
        case 0x18D: D_L01_001D8E14 = n; break;
        case 0x18E: D_L01_001D8E08 = n; break;
        case 0x148: D_L01_001D8E0C = n; break;
        }
        n++;
    }
    if (D_001D545C == 0x18) {
        D_L01_002EB2E8_00492140[0].b4 = 0;
    } else {
        D_L01_002EB2E8_00492140[0].b4 = 1;
    }
    c1 = 0.500369f;
    c2 = 0.816536f;
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = n < 7 ? n : 6;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = D_L01_001D8E3C;
    s.f20 = D_L01_001D8E40;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.795206f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0, c1, c2, 0.045f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), c1, 0.698703f, c2, 0.314706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.033f, 0.00666f, 0.03f);
    for (j = 0; j < n; j++) {
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i++), D_L01_001D8E48, func_00381FF0(D_L01_002EB2E8_00492140[j].w0));
        hidden = !D_L01_002EB2E8_00492140[j].b4;
        func_L01_00498948(func_003B9BD0(0), j, hidden);
    }
}
/* localdecomp:end func_L01_00492140 */
