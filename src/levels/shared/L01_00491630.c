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
typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

/* declared by functions of L01_00491290.c, which this file was cut from */
extern void func_L01_00491630(void);

/* localdecomp:start func_L01_00491630 */
extern s32 D_L01_001D8E20;
__asm__(".extern D_L01_001D8E20, 4");
extern s32 D_L01_001D8DF8[4] __attribute__((section(".sdata")));
extern s32 D_L01_001D8DE8[2];
__asm__(".extern D_L01_001D8DE8, 8");
extern f32 D_L01_001DC0E8;
extern u8 D_L01_002EB348[];
extern void func_L01_00491DD0(void);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern void func_L01_00491AF0(void *);
extern s32 func_003E8348(s32, s32);
extern void *func_003B42F8(s32);
extern s32 func_003E8710(s32, s32);
extern void func_L01_00492140(void);
extern void func_L01_00492458(void);
extern void func_L01_00516D60(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern void func_L01_004986A8(void *, s32);

void func_L01_00491630(void) {
    s32 i;
    s32 s;
    f32 x;
    f32 r;
    f32 lo, hi;
    f32 a, b;

    D_L01_001D8E20 = 0;
    lo = 0.0f;
    hi = 0.49f;
    a = 6.0f;
    b = 11.0f;
    for (i = 0; i < 4; i++) {
        D_L01_001D8DF8[i] = -1;
    }
    func_L01_00491DD0();
    func_0038E150(0);
    x = (f32)func_0038E548(func_00381FF0(0x107), -1, 1.2f) / D_L01_001DC0E8;
    if (hi < x) x = hi;
    x = (x - lo) / (hi - lo);
    r = func_003C4088(a, b, x);
    if (b < r) r = b;
    else if (r < a) r = a;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x107), 0xD0006, 0x124, 0xD0007, 0xCD5, r);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8FE8(0xD000A, func_00381FF0(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0xD000B, 0xD0009, 0xD000A);
    func_L01_00491AF0(D_L01_002EB348);
    func_003E8348(0x11, 0x1C0000);
    func_003E8710(0x1C0003, (s32)func_003B42F8(0));
    func_L01_00492140();
    func_L01_00492458();
    func_L01_00516D60(0x1C0003, 0);
    func_003E87B8(0x1C0003, 1, 8);
    s = func_003B9BD0(func_L01_00517688());
    func_L01_004986A8((void *)s, D_L01_001D8DE8[func_L01_00517688()]);
}
/* localdecomp:end func_L01_00491630 */
