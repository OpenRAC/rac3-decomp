#include "common.h"

/* NTSC-U counterpart of func_L02_0034F710 (src/levels/02_florana/L02_0034C9F0.c): 100 -> 120 */
/* localdecomp:start func_L02_0034E6B0 */
typedef struct { u8 p0[0x24]; s32 f24; u8 p1[0x44]; s32 f6C; u8 p2[0x24]; s32 f94; } S_34F710;
extern s32 func_L02_0034E8F8(void *);
extern void func_L01_0044CB08(void *, s32, s32, s32);
extern void func_L02_0034EBE0(void *);
extern s32 *func_L01_00444358(void *, s32, s32);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_L02_0034ECF8(void *);
extern s32 func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L02_003F84F0(s32, s32, f32);
extern S_34F710 D_001CCFD0;
__asm__(".extern D_001CCFD0, 16");

s32 func_L02_0034E6B0(u8 *a0)
{
    u8 *p;
    s32 *q;
    s32 v;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L02_0034E8F8(a0) != 0) return 1;
    }
    if (*(s32 *)(p + 0x938) != 0) func_L01_0044CB08(a0, *(s32 *)(p + 0x938), 2, 0);
    if (p[0x3E] == 2) {
        func_L02_0034EBE0(a0);
        return 1;
    }
    if (*(s32 *)(p + 0x2EC) != 0 && a0[0xBC] == 0) func_L01_0044CB08(a0, *(s32 *)(p + 0x2EC), 0, 0);
    q = func_L01_00444358(a0, 0x10000, 0);
    if (q != 0 && *(u8 **)((u8 *)q + 0x20) != 0) {
        s32 h = *(s16 *)(*(u8 **)((u8 *)q + 0x20) + 0xAA);
        if (h == 0x18BE || h == 0x184F) {
            *(f32 *)((u8 *)q + 0x2C) *= 0.75f;
        }
    }
    if (*(f32 *)(p + 0x2CC) > 0.0f) {
        if (func_L01_0044FCD0(a0, p + 0x160, 0, 0, 0) != 0) {
            if (*(s32 *)(p + 0x21C) == 0) *(s32 *)(p + 0x21C) = 120;
            if (*(s32 *)(p + 0xA3C) == 0 && D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1
                && D_001CCFD0.f94 == 0 && *(f32 *)(p + 0x30) > 0.0f) {
                func_00382468(4);
                *(s32 *)(p + 0xA3C) = 1;
            }
            func_L02_0034ECF8(a0);
        }
    }
    func_L01_004539A8(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
    if ((u8)(a0[0x95] - 2) < 2) {
        v = (s32)*(f32 *)(p + 0x30);
        if (v < 0) v = 0;
        func_L02_003F84F0(10, 0, (f32)v / (f32)*(s16 *)(p + 0x34));
    }
    return 0;
}
/* localdecomp:end func_L02_0034E6B0 */
