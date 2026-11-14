#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BF2F8.c, which this file was cut from */
extern void func_0038CE20(void *, void *, f32);

/* localdecomp:start func_L09_003BFC90 */
typedef struct { u8 pad0[2]; u8 b2; u8 b3; } S_003BFC90;
typedef struct { u8 pad[0x5C]; u8 *p5C; } G_003BFC90;
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 i28; s32 i2C; } T_003BFC90;
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 D_L09_001DE6F0;
__asm__(".extern D_L09_001DE6F0, 4");
extern s32 D_L09_001DE6F4;
__asm__(".extern D_L09_001DE6F4, 4");
extern s32 D_L09_001DE6F8;
__asm__(".extern D_L09_001DE6F8, 4");
extern s32 D_L09_001DE6FC;
__asm__(".extern D_L09_001DE6FC, 4");
extern f32 D_L09_001DE700;
__asm__(".extern D_L09_001DE700, 4");
extern f32 D_L09_001DE704;
__asm__(".extern D_L09_001DE704, 4");
extern f32 D_L09_001DE708;
__asm__(".extern D_L09_001DE708, 4");
extern f32 D_L09_001DE70C;
__asm__(".extern D_L09_001DE70C, 4");
extern f32 D_L09_001DE710;
__asm__(".extern D_L09_001DE710, 4");
extern f32 D_L09_001DE718;
__asm__(".extern D_L09_001DE718, 4");
extern s32 D_L09_001DE720;
__asm__(".extern D_L09_001DE720, 4");
extern G_003BFC90 D_L09_00220018;
extern T_003BFC90 D_L09_001E2B80;

void func_L09_003BFC90(u8 *a0, s32 flag, f32 x, f32 y) {
    f32 vel[4];
    f32 pos[4];
    s32 which = 0;
    s32 ok;
    s32 count, i, n;
    f32 lo, hi, sx, sy, a, b, size;
    S_003BFC90 *s;

    if (func_L01_0044E1B8(a0, (x * 5.0f + 2.0f) / 6.0f)) {
        ok = 1;
        which = 1;
    } else {
        ok = func_L01_0044E1B8(a0, (y * 5.0f + 2.0f) / 6.0f) != 0;
    }
    if (ok) {
        count = flag ? D_L09_001DE6FC : D_L09_001DE6F8;
        lo = flag ? D_L09_001DE704 : D_L09_001DE700;
        hi = flag ? D_L09_001DE70C : D_L09_001DE708;
        sx = flag ? D_L09_001DE704 : D_L09_001DE710;
        sy = flag ? D_L09_001DE70C : D_L09_001DE718;
        for (i = 0; i < count; i++) {
            size = func_003824E0(lo, hi) * 210000.0f;
            a = sx * 0.020000001f;
            b = sy * 0.020000001f;
            vel[0] = func_L01_00443A18(a, b);
            vel[1] = func_L01_00443A18(a, b);
            vel[2] = func_003824E0(0.25f, 0.8f) * 0.020000001f;
            func_003C2F58(a0, which ? 0x34 : 0x35, pos);
            pos[0] += func_L01_00443A18(0.0f, 0.6f);
            pos[1] += func_L01_00443A18(0.0f, 0.6f);
            pos[2] += func_L01_00443A18(0.0f, 0.2f);
            n = (func_00382498(0x23, 0x78) * 5 + 2) / 6;
            s = (S_003BFC90 *)func_L01_0046FB40(pos, vel, n, D_L09_001DE720, func_00382468(2) ? 1 : -1, 50, 0, size, size, 0.0f, 0);
            if (s) {
                s->b2 = *D_L09_00220018.p5C;
                s->b3 = 0x44;
            }
        }
        if (flag) {
            D_L09_001E2B80.f20 = D_L09_001DE6F0;
            D_L09_001E2B80.i2C = 0;
            D_L09_001E2B80.i28 = (D_L09_001DE6F4 * 5 + 2) / 6;
        }
    }
}
/* localdecomp:end func_L09_003BFC90 */
