#include "common.h"

/* NTSC-U counterpart of func_L04_00367150 (src/levels/04_marcadia/L04_00366800.c) */
extern void func_L04_00365FD8(void *);

/* localdecomp:start func_L04_00365FD8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_367150;
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L04_00365FD8(void *a0) {
    u8 *p = (u8 *)a0;
    V4_367150 a;
    V4_367150 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_367150){0.0f, 0.0f, 0.0f, 0.0f};
    a = (V4_367150){0.0f, 0.0f, 5.0f, 0.0f};
    b.x = 0.0333333351f;
    b.z = 0.0333333351f;
    func_003888C8(&b, &b, p + 0xC0);
    r = func_0037E208(3, 6);
    func_L02_003E0520(p, &a, 0.0f, &b, r, 0, 0, 0.0333333351f, 0.5f, 15.0f, 1.0f);
    b.x = -0.0333333351f;
    b.z = 0.040000003f;
    func_003888C8(&b, &b, p + 0xC0);
    r = func_0037E208(3, 6);
    func_L02_003E0520(p, &a, 0.0f, &b, r, 1, 0, 0.0333333351f, 0.5f, 15.0f, 1.0f);
    r = func_0037E208(0x5A, 0xB4);
    *q = r;
}
/* localdecomp:end func_L04_00365FD8 */
