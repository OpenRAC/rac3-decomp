#include "common.h"

typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
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
typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

/* declared by functions of L01_00492C80.c, which this file was cut from */
extern S_48F880e D_L01_002EB498[];
extern s32 func_003B9BD0(s32);

/* localdecomp:start func_L01_004931E0 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_004931E0;
typedef struct { u8 pad0[0x25E4]; u8 f25E4; } H_004931E0;
extern f32 D_L01_001D8E80;
extern f32 D_L01_001D8E84;
__asm__(".extern D_L01_001D8E80, 4");
__asm__(".extern D_L01_001D8E84, 4");
extern char D_L01_001D8E88[];
extern H_004931E0 D_001A4BE0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D5570[] __attribute__((section(".sdata")));
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern void func_003B9C68(s32, S_004931E0 *);
extern void func_L01_00499760(s32, f32, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00498948(s32, s32, s32);
extern char *func_00381FF0(s32);
extern char *func_003B9E30(s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);

void func_L01_004931E0(void) {
    S_004931E0 s;
    s32 n;
    s32 i;
    s32 j;

    i = 0;
    for (n = 0; D_L01_002EB498[n].w0 > 0; n++)
        ;
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = 4;
    s.f10 = 4;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = D_L01_001D8E80;
    s.f20 = D_L01_001D8E84;
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
    func_L01_00499760(func_003B9BD0(0), 0.500369012f, 0.816536009f, 0.0649999976f, 0.00824999996f, 0.0425000004f, 0.349999994f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.698702991f, 0.816536009f, 0.304706007f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0329999998f, 0.00665999996f, 0.0299999993f);
    for (j = 0; j < n; j++) {
        if (D_L01_002EB498[j].w0 == 0x526 && !func_L01_0041A4F0()) {
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8E88, func_00381FF0(0x16F));
            func_L01_00498948(func_003B9BD0(0), i, 1);
        } else {
            D_L01_002EB498[j].b4 = 1;
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8E88, func_00381FF0(D_L01_002EB498[j].w0));
            if (D_L01_002EB498[j].w0 == 0x526) {
                if ((D_001D545C == 0x17 && D_001D5570[13] == 0) || (D_001D545C == 0x1B && D_001D5570[28] == 0)) {
                    D_L01_002EB498[j].b4 = 0;
                    func_L01_00498948(func_003B9BD0(0), i, 1);
                }
            }
        }
        if (D_L01_002EB498[j].w0 == 0x139E && D_001A4BE0.f25E4 != 0) {
            D_L01_002EB498[j].b4 = 0;
            func_L01_00498948(func_003B9BD0(0), i, 1);
        }
        i++;
    }
}
/* localdecomp:end func_L01_004931E0 */
