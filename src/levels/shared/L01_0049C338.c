#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7058 - 0x4958];
    u8 fX[1];
} S_func_00498868;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_498978;
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_0049C950;
extern S_0049C950 *D_001D52FC[] __attribute__((section(".sdata")));

/* declared by functions of L01_0049BE80.c, which this file was cut from */
extern E_498978 D_L01_002EBED8[];
extern s32 *func_003B9BD0(s32);
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L01_0049C338 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_0049C338;
extern s32 D_L01_001D9400;
__asm__(".extern D_L01_001D9400, 4");
extern char D_L01_001D9460[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern void func_003B9C68(void *, S_0049C338 *);
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_L01_00498948(void *, s32, s32);
extern s32 func_003B9E30(void *, s32, s32);
extern void func_0011B2E8(s32, char *, s32);
extern void func_L01_004986A8(s32 *, s32);

void func_L01_0049C338(void) {
    S_0049C338 s;
    s32 n;
    s32 i;
    f32 width;

    for (n = 0; D_L01_002EBED8[n].x0 > 0; n++) {
    }
    width = 0.699119985f;
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = n < 6 ? n : 5;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = width;
    s.f20 = 0.0635600016f;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.79520601f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.816536009f, 0.0450000018f, 0.0425000004f, 0.349999994f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.764262974f, 0.816536009f, 0.185586005f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0329999998f, 0.00665999996f, 0.0299999993f);
    D_L01_001D9400 = 0;
    for (i = 0; i < n; i++) {
        if (D_L01_002EBED8[i].x14) {
            func_L01_00498948(func_003B9BD0(0), i, 0);
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D9460, func_00381FF0(D_L01_002EBED8[i].x0));
        } else {
            D_L01_001D9400 = 1;
            func_L01_00498948(func_003B9BD0(0), i, 1);
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D9460, func_00381FF0(0x1C8));
        }
    }
    if (D_L01_001D9400) {
        func_L01_004986A8(func_003B9BD0(0), 1);
    }
}
/* localdecomp:end func_L01_0049C338 */
