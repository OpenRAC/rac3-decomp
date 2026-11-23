#include "common.h"

/* NTSC-U counterpart of func_L31_003473F0 (src/levels/shared/L31_003473F0.c) */
/* localdecomp:start func_L31_003468E0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003473F0;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    u8 pad84[4];
    f32 z;
    u8 pad8C[0xF0 - 0x8C];
    f32 vx;
    u8 padF4[0xC];
    f32 f100;
    u8 pad104[0x25C0 - 0x104];
    u8 *coll;
} Hero_003473F0;

extern Hero_003473F0 D_001A4BE0;
extern f32 D_L31_001E9220_003468E0 __attribute__((section(".data")));
extern s32 D_L31_001DF3C0_003468E0;
extern f32 D_L31_001DD01C_003468E0;
__asm__(".extern D_L31_001DD01C_003468E0, 4");
extern f32 D_L31_001DD020_003468E0;
__asm__(".extern D_L31_001DD020_003468E0, 4");
extern f32 D_L31_001DD024_003468E0;
__asm__(".extern D_L31_001DD024_003468E0, 4");
extern s32 D_L31_001DD028_003468E0;
__asm__(".extern D_L31_001DD028_003468E0, 4");
extern f32 D_L31_001DD030_003468E0;
__asm__(".extern D_L31_001DD030_003468E0, 4");
extern f32 func_L30_0034BF98_003468E0(u8 *);
extern f32 func_003BEB48(f32, f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);

void func_L31_003468E0(V4_003473F0 *pos, f32 a, f32 b) {
    V4_003473F0 v;
    V4_003473F0 w;
    f32 top;
    f32 m;
    f32 f;
    f32 d;

    f = func_L30_0034BF98_003468E0(D_001A4BE0.coll);
    top = D_001A4BE0.z;
    if (top + f < pos->z) {
        return;
    }
    if (pos->z + a < top) {
        return;
    }
    m = (top < pos->z) ? pos->z : top;
    f = func_003BEB48(b, 0.0f, (m - pos->z) / a);
    if (f + D_L31_001DD01C_003468E0 < fabs_asm(pos->x - D_001A4BE0.x)) {
        return;
    }
    if ((0.0f < D_001A4BE0.vx && D_001A4BE0.x < pos->x) ||
        (D_001A4BE0.vx < 0.0f && pos->x < D_001A4BE0.x)) {
        D_001A4BE0.f100 -= D_001A4BE0.vx;
    }
    v = *pos;
    v.z += D_L31_001DD020_003468E0;
    w = v;
    if (D_001A4BE0.x < pos->x) {
        d = (0.0f < (pos->x - f - D_L31_001DD01C_003468E0 - D_001A4BE0.x)) ? 0.0f : (pos->x - f - D_L31_001DD01C_003468E0 - D_001A4BE0.x);
        w.x -= f + (D_L31_001DD01C_003468E0 + D_L31_001DD01C_003468E0);
        if (func_003CE740(&v, &w, 2, D_001A4BE0.coll, 0)) {
            d = ((D_L31_001E9220_003468E0 - D_001A4BE0.x + D_L31_001DD01C_003468E0) < d) ? d : (D_L31_001E9220_003468E0 - D_001A4BE0.x + D_L31_001DD01C_003468E0);
        }
        v.z += D_L31_001DD024_003468E0 - D_L31_001DD020_003468E0;
        w.z = v.z;
        if (func_003CE740(&v, &w, 2, D_001A4BE0.coll, 0)) {
            d = ((D_L31_001E9220_003468E0 - D_001A4BE0.x + D_L31_001DD01C_003468E0) < d) ? d : (D_L31_001E9220_003468E0 - D_001A4BE0.x + D_L31_001DD01C_003468E0);
        }
        d = (d < 0.0f) ? d : 0.0f;
    } else {
        d = ((pos->x + f + D_L31_001DD01C_003468E0 - D_001A4BE0.x) < 0.0f) ? 0.0f : (pos->x + f + D_L31_001DD01C_003468E0 - D_001A4BE0.x);
        w.x += f + (D_L31_001DD01C_003468E0 + D_L31_001DD01C_003468E0);
        if (func_003CE740(&v, &w, 2, D_001A4BE0.coll, 0)) {
            d = (d < (D_L31_001E9220_003468E0 - D_001A4BE0.x - D_L31_001DD01C_003468E0)) ? d : (D_L31_001E9220_003468E0 - D_001A4BE0.x - D_L31_001DD01C_003468E0);
        }
        v.z += D_L31_001DD024_003468E0 - D_L31_001DD020_003468E0;
        w.z = v.z;
        if (func_003CE740(&v, &w, 2, D_001A4BE0.coll, 0)) {
            d = (d < (D_L31_001E9220_003468E0 - D_001A4BE0.x - D_L31_001DD01C_003468E0)) ? d : (D_L31_001E9220_003468E0 - D_001A4BE0.x - D_L31_001DD01C_003468E0);
        }
        d = (0.0f < d) ? d : 0.0f;
    }
    if (D_L31_001DF3C0_003468E0 != D_L31_001DD028_003468E0) {
        D_L31_001DD028_003468E0 = D_L31_001DF3C0_003468E0;
        D_001A4BE0.x += d / (D_L31_001DD030_003468E0 * 60.0f);
    }
}
/* localdecomp:end func_L31_003468E0 */
