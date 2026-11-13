#include "common.h"

/* NTSC-U counterpart of func_L05_003B1100 (src/levels/05_daxx/L05_003AFC08.c): 0.000288 -> 0.0002; 0.00144 -> 0.001 */
/* localdecomp:start func_L05_003AF1E0 */
extern s32 func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_003A4F28(s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L05_003AFF60(s32, s32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_003E6D50(s32, s32, f32, f32);
extern void func_L02_003F84F0(s32, s32, f32);
extern void func_L05_003B0428(u8 *);
extern void func_L05_003AF530(u8 *);
typedef struct { u8 pad[0x144]; s32 v; } S_003B1100;
extern S_003B1100 D_L05_001E2780;
__asm__(".extern D_L05_001E2780, 16");

void func_L05_003AF1E0(u8 *a0) {
    u8 *p = a0;
    u8 *q = *(u8 **)(p + 0x68);
    u8 *r;
    s32 i;

    if (*(s32 *)(q + 0x2B0) == -1) {
        if (((p[0x34] ^ 1) & 1)) {
            *(s32 *)(q + 0x2B0) = func_L01_004A72A8(0, 4, p, 0x1A13);
        }
    } else {
        if (*(u16 *)(p + 0x34) & 1) {
            func_003A4F28(*(s32 *)(q + 0x2B0));
            *(s32 *)(q + 0x2B0) = -1;
        }
    }
    if (((p[0x34] ^ 1) & 1)) {
        if (p[0x20] < 0x11) {
            func_L05_003AF530(p);
        }
    }
    func_L01_004538E0(p, 3);
    i = 0;
    { f32 c = 100.0f; func_L01_004539A8(p, c, c, 1.0f, -1, 0, 0, 0, 0, 1, 0, 0, 0); }
    r = q + 0x160;
    do {
        s32 v = func_L05_003AFF60(i, 2);
        i++;
        func_L01_0044B5C8(p, r, v, 0.000199999995f, 0.00100000005f);
        r += 0x80;
    } while (i < 2);
    if (D_L05_001E2780.v) {
        func_L01_003E6D50(0, 0, 9.0f, 0.003f);
    }
    if ((u32)(p[0x20] - 6) < 11) {
        func_L02_003F84F0(7, 0, *(f32 *)(q + 0x30) / (f32)*(s16 *)(q + 0x34));
    }
    if (((p[0x34] ^ 1) & 1)) {
        if (p[0x20] < 0x11) {
            func_L05_003B0428(p);
        }
    }
}
/* localdecomp:end func_L05_003AF1E0 */
