#include "common.h"

/* localdecomp:start func_L30_003A3070 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_003A3070;
typedef struct {
    f32 x0;
    u8 pad4[0xC];
    Q_003A3070 x10;
    u8 x20[0x10];
    Q_003A3070 x30;
    u8 x40[4];
    u8 x44[8];
    u32 x4C;
    u8 pad50[0xC];
    f32 x5C;
    u8 pad60[0xC];
    f32 x6C;
    f32 x70;
    u8 pad74[8];
    s32 x7C;
} V_003A3070;
typedef struct { u8 pad[0x24]; f32 x24; } C_003A3070;
typedef struct {
    u8 pad[0x24];
    C_003A3070 *x24;
    u8 pad28[4];
    f32 x2C;
    u8 pad30[0x10];
    u8 x40;
    u8 x41;
    u8 x42;
    u8 x43;
    u8 pad44[0x24];
    V_003A3070 *x68;
    u8 pad6C[0xF4 - 0x6C];
    u8 xF4[4];
    u8 xF8[4];
} O_003A3070;
__asm__(".extern D_L30_001DE8A0, 4");
__asm__(".extern D_L30_001DE8A4, 4");
__asm__(".extern D_L30_001DE8A8, 4");
__asm__(".extern D_L30_001DE950, 4");
__asm__(".extern D_L30_001DE958, 4");
__asm__(".extern D_L30_001DE95C, 4");
__asm__(".extern D_L30_001DE960, 4");
__asm__(".extern D_L30_001DE964, 4");
extern f32 D_L30_001DE8A0;
extern f32 D_L30_001DE8A4;
extern f32 D_L30_001DE8A8;
extern s32 D_L30_001DE950;
extern f32 D_L30_001DE958;
extern f32 D_L30_001DE95C;
extern f32 D_L30_001DE960;
extern f32 D_L30_001DE964;
extern s32 D_L30_001DF2C0;
extern f32 D_001A4C60 __attribute__((section(".data")));
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_00445F40(void *, s32);
extern void func_003C7DD8(void *);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_L30_0034C9F8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L30_003A2C68(void *, s32);
void func_L30_003A3070(O_003A3070 *a0) {
    V_003A3070 *v = a0->x68;
    f32 s;
    f32 a;

    if (func_L01_004561B8(a0)) {
        func_L01_00445F40(a0, 0x1C1A);
        func_003C7DD8(a0);
        a0->x40 = 0;
        a0->x41 = 0;
        v->x6C = D_L30_001DE8A0 * v->x70;
        a0->x2C = v->x70 * a0->x24->x24;
    }
    v->x7C = D_L30_001DF2C0;
    v->x30 = v->x10;
    if (v->x4C < 2) {
        func_L01_00448890(a0->xF4, 0.0f, v->x40, 0, D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964);
        if (a0->x43 != 3) {
            func_003C3A10(a0, 3, 0, (D_L30_001DE950 * 5 + 2) / 6);
        }
    } else if (v->x4C == 2) {
        s = D_L30_001DE960 * (v->x5C - 0.25f);
        a = func_0038DAB8(-func_L30_0034C9F8(v->x20), -1.5707964f);
        func_L01_00448890(a0->xF4, a, v->x40, 0,
                          s * D_L30_001DE958, s * D_L30_001DE95C, s * D_L30_001DE964);
        func_L01_00448890(a0->xF8, D_L30_001DE8A8, v->x44, 0,
                          s * D_L30_001DE958, s * D_L30_001DE95C, s * D_L30_001DE964);
        if (a0->x43 != 0) {
            func_003C3A10(a0, 0, 0, (D_L30_001DE950 * 5 + 2) / 6);
        }
    }
    if (v->x4C == 0) {
        func_L01_00448890(a0->xF8, v->x0 < 0.0f ? D_L30_001DE8A4 : D_L30_001DE8A8, v->x44, 0,
                          D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964);
    } else if (v->x4C == 1) {
        func_L01_00448890(a0->xF8, D_001A4C60 < v->x30.x ? D_L30_001DE8A4 : D_L30_001DE8A8, v->x44, 0,
                          D_L30_001DE958, D_L30_001DE95C, D_L30_001DE964);
    }
    if (func_L01_00456250(a0)) {
        func_L30_003A2C68(a0, 0x42);
    }
}
/* localdecomp:end func_L30_003A3070 */
