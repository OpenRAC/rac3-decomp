#include "common.h"

/* NTSC-U counterpart of func_L19_003B1E08 (src/levels/19_thran_asteroid_belt/L19_003B1A80.c) */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern void func_003BDA38(u8 *a0, s32 a1, u8 *a2);

/* localdecomp:start func_L19_003B0198 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B1E08;
extern u8 D_L19_001E2100_003B0198[];
extern s32 D_L19_001DF758_003B0198;
extern s32 D_L19_0021C260_003B0198[];
extern s32 func_L19_003AFAE0(u8 *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, u8 *);
extern void func_L19_003ADEF0(u8 *obj, s32 mode);
extern void func_L01_00452F40(void *, s32);
extern void func_L03_0042FC00(s32, s32);
extern s32 func_L19_003B0FB8(u8 *self, f32 a, f32 b, f32 c);
extern s32 func_0037E1D8(s32);
extern s32 func_L19_003B1070(u8 *obj);
extern void func_003BD360(void *);
extern void func_L01_004412D0(u8 *, s32, s32);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_003BDA38(u8 *a0, s32 a1, u8 *a2);
extern void func_L01_004539A8(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L19_003B0198(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    V4_3B1E08 p;
    f32 hp;
    s32 n;
    s32 a;
    s32 k;

    if (obj[0x20] == 0 && func_L19_003AFAE0(obj) != 0)
        return 1;
    if (obj[0x95] == 5)
        *(f32 *)(v + 0x40) = 0.5f;
    else if (obj[0x42] == 6)
        *(f32 *)(v + 0x40) = 0.75f;
    else
        *(f32 *)(v + 0x40) = 2.0f;
    hp = *(f32 *)(v + 0x30);
    if (obj[0x31] != 0 && func_L01_0040C018(D_L19_001E2100_003B0198, obj + 0x10) < 576.0f) {
        func_L01_00444188(obj);
        obj[0x6F] = 0x16;
    }
    n = func_L01_0044FCD0(obj, v + 0x160, 0, 0, 0);
    if (hp != *(f32 *)(v + 0x30)) {
        if (0.0f < *(f32 *)(v + 0x30)) {
            if (*(s16 *)(v + 0x3B2) == 0) {
                func_0039FE80(5, 0, obj);
                *(s16 *)(v + 0x3B2) = *(u16 *)(v + 0x3B0);
            }
            if ((u32)n >= 2)
                func_L19_003ADEF0(obj, 0);
        }
        func_L01_00452F40(obj, 1);
        k = obj[0x21];
        if (k < D_L19_001DF758_003B0198 && D_L19_0021C260_003B0198[k] != 0)
            func_L03_0042FC00(k, 1);
        func_L19_003B0FB8(obj, hp, *(f32 *)(v + 0x30), *(s16 *)(v + 0x34));
        if (*(f32 *)(v + 0x30) <= 0.0f && obj[0x95] != 5 && func_0037E1D8(100) <= *(s16 *)(v + 0x3A4))
            func_L19_003B1070(obj);
    }
    if (v[0x60] != 0 || v[0x5E] != 0 || v[0x3E] == 2) {
        func_003BD360(*(void **)(v + 0x39C));
        func_L01_004412D0(obj, 0, 3);
        func_003BD360(obj);
        return 1;
    }
    func_L01_0044F5E8(obj, v + 0x30, 0);
    if (v[0x5F] != 0) {
        a = 5;
        n = 3;
    } else {
        a = 3;
        n = 1;
    }
    if (((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0)
        && 0.0f < *(f32 *)(v + 0x30))
        func_L01_004538E0(obj, a);
    func_003BDA38(obj, 4, (u8 *)&p);
    if (obj[0x95] == 0)
        func_L01_004539A8(obj, *(s32 *)(v + 0x350), &p, 0, 0, 0, n, 0, 0, 0, *(f32 *)(v + 0x354), 10.0f, 1.0f);
    else
        func_L01_004539A8(obj, *(s32 *)(v + 0x358), &p, 0, 0, 0, n, 0, 0, 0, *(f32 *)(v + 0x35C), 10.0f, 1.0f);
    return 0;
}
/* localdecomp:end func_L19_003B0198 */
