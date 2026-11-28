/* func_L01_003B7CB8 (Claude wave 14 r74, 2026-11-28). First draft kept here. */
/* r74 wave 14 (2026-11-28), first draft (fresh entry). NEEDS ANOTHER LINE: retail loads its float constants as
 * lui/ori/mtc1 through $at (Ps2EeAs li.s: @ps2as) and does the vector adds/subtracts with lqc2/vadd.xyz/vsub.xyz/sqc2
 * (vu0.h helpers: -mvu0-use-vf0-vf2); the file's line '-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses'
 * has neither. This file is the plain-float form that compiles under the file's line (271 diff there). The real draft is
 * out/func_L01_003B7CB8.vu0.c: under the existing line '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
 * -mvu0-use-vf0-vf2' (L01_003B84E8.c's) it is 16 aligned rows at level 01 (309 vs 308 instructions). Cut 0x003B7CB8-0x003B8190
 * (the function is the last of L01_003B7BF8.c; both ends 8-aligned). Levers found: m->F0 stored as a struct field (lets
 * the D_001DFB4C load move above it, giving retail's f1/f2 and vf1/vf2), vars read before the state test (delay slot),
 * the success copy *pos = newpos written last (shared with the D_001EAA18 == other case), D_001EAA18 as an array (not ),
 * the hit struct's .w/type stores before the flags |= 1. Left (vu0 form): the effect block computes &hit.a (s0) and its
 * copy s5 earlier than retail, and reorg fills the three tail branches' delay slots differently (retail: lui of
 * D_001EAA18 in all three, beql with the copy's lq). */
#include "common.h"

/* localdecomp:start func_L01_003B7CB8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B7CB8;
typedef int u128_003B7CB8 __attribute__((mode(TI)));
typedef struct { V4_003B7CB8 a; V4_003B7CB8 b; V4_003B7CB8 c; } Hit_003B7CB8;
typedef struct { u8 pad00[0xF0]; f32 fF0; } Moby_003B7CB8;
extern f32 D_L01_001DFB4C;
extern f32 D_L01_001DFB50;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 4");
extern u8 *D_L01_001EAA18[];
extern u8 D_L01_001D66B0[];
void func_L01_003B7CB8(u8 *m) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_0013D3E0(void);
    extern void func_003C2880(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_003D4D00(void *, s32, void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_0044AF78(u8 *owner, void *direction, f32 *position, f32 radius, f32 damage, s32 sparks,
                           s32 flashes, s32 smoke, f32 glow, f32 white, f32 cutoff, f32 scale, s32 sound,
                           f32 blast, s32 shake, s32 debris, s32 quality, u8 channels, s32 flags);
    V4_003B7CB8 newpos;
    Hit_003B7CB8 hit;
    u8 *vars;
    f32 len;
    s32 flag;

    vars = *(u8 **)(m + 0x68);
    if (m[0x20] != 1) {
        return;
    }
    ((Moby_003B7CB8 *)m)->fF0 = func_0038DAB8(((Moby_003B7CB8 *)m)->fF0, 0.12566371f);
    flag = 0;
    newpos = *(V4_003B7CB8 *)(m + 0x10);
    newpos.x += ((V4_003B7CB8 *)vars)->x;
    newpos.y += ((V4_003B7CB8 *)vars)->y;
    newpos.z += ((V4_003B7CB8 *)vars)->z;
    if (0.9f < D_L01_001DFB4C) {
        flag = 1;
    } else if (0.9f < D_L01_001DFB50) {
        flag = 1;
    }
    if (flag == 0 || (D_L01_001DFB40 & 1) == 0) {
        len = func_0038CEA8(vars);
        *(u128_003B7CB8 *)&hit.c = 0;
        hit.c.x = func_003824E0(-1.0f, 1.0f);
        hit.c.y = func_003824E0(-1.0f, 1.0f);
        hit.c.z = func_003824E0(-1.0f, 1.0f);
        *(u128_003B7CB8 *)&hit.b = *(u128_003B7CB8 *)&hit.c;
        func_0038CF68(&hit.b, &hit.b, func_003824E0(0.04f, 0.08f) * 0.020000001f);
        func_0038CE20(&hit.a, vars, func_003824E0(0.2f, 0.99f));
        hit.b.x += hit.a.x;
        hit.b.y += hit.a.y;
        hit.b.z += hit.a.z;
        func_0038CF68(&hit.a, vars, func_003824E0(0.0f, 1.0f) * len);
        hit.a.x += ((V4_003B7CB8 *)(m + 0x10))->x;
        hit.a.y += ((V4_003B7CB8 *)(m + 0x10))->y;
        hit.a.z += ((V4_003B7CB8 *)(m + 0x10))->z;
        func_L01_0046A610(m + 0x10, &hit.b, 6, 0x7F, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
        *(u128_003B7CB8 *)&hit.c = 0;
        hit.c.z = 0.01f;
        func_0038D000(&hit.c, &hit.c, m + 0xC0);
        func_0038D890(&hit.c, &hit.c, m + 0xC0, func_00382538());
        if (func_0013D3E0() & 1) {
            func_L01_00466588(&hit.a, &hit.c, 0x4F007FFF, 0x1FFFFFFF, 0xB, 1, 25000.0f);
        }
    }
    func_L01_00446760(&hit.a, *(void **)(m + 0xB8), 0x10001, vars, *(f32 *)(vars + 0x14));
    *(u16 *)((u8 *)&hit.b + 0xA) = *(u16 *)(m + 0xAA);
    hit.a = *(V4_003B7CB8 *)(m + 0x10);
    hit.a.x -= ((V4_003B7CB8 *)(*(u8 **)(m + 0xB8) + 0x10))->x;
    hit.a.y -= ((V4_003B7CB8 *)(*(u8 **)(m + 0xB8) + 0x10))->y;
    hit.a.z -= ((V4_003B7CB8 *)(*(u8 **)(m + 0xB8) + 0x10))->z;
    hit.a.z = 0.0f;
    func_0038CF68(&hit.a, &hit.a, 2.0000002f);
    hit.a.w = 5627.925f;
    *((u8 *)&hit.b + 8) = 4;
    *(s32 *)&hit.c |= 1;
    if (func_003D3CB0(m + 0x10, &newpos, 0, *(void **)(m + 0xB8), &hit.a) != 0
        || func_L01_003FB640(m + 0x10, 1, *(void **)(m + 0xB8), 0.3f) != 0
        || func_0038CAD0(vars + 0x10) != 0) {
        if (D_L01_001EAA18[0] != 0) {
            if (D_L01_001EAA18[0] != *(u8 **)(m + 0xB8)) {
                if (*(s16 *)(D_L01_001EAA18[0] + 0xAA) != 0x4E) {
                    func_003D4D00(m + 0x10, 0, *(void **)(m + 0xB8), &hit.a, 0.5f);
                }
                func_L01_0044AF78(m, D_L01_001D66B0, 0, 0.0f, 0.0f, 0, 2, 10, 0.0f, 0.0f, 9.0f, 0.666f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
                func_003C2880(m);
                return;
            }
        } else {
            func_L01_0044AF78(m, D_L01_001D66B0, 0, 0.0f, 0.0f, 0, 2, 8, 0.0f, 0.0f, 9.0f, 0.5f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
            func_003C2880(m);
            return;
        }
    }
    *(u128_003B7CB8 *)(m + 0x10) = *(u128_003B7CB8 *)&newpos;
}
/* localdecomp:end func_L01_003B7CB8 */

/* The other form the notes name (Claude wave 14 r74, func_L01_003B7CB8.vu0.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
/* r74: the VU0/@ps2as form of func_L01_003B7CB8 (see out/func_L01_003B7CB8.near.c): 16 aligned rows under '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2' (tools/check.py --flags="@ps2as -mvu0-use-vf0-vf2"). */
#include "common.h"

/* localdecomp:start func_L01_003B7CB8 */
#include "vu0.h"
typedef int u128_003B7CB8 __attribute__((mode(TI)));
typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } Hit_003B7CB8;
typedef struct { u8 pad00[0xF0]; f32 fF0; } Moby_003B7CB8;
extern f32 D_L01_001DFB4C;
extern f32 D_L01_001DFB50;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 4");
extern u8 *D_L01_001EAA18[];
extern u8 D_L01_001D66B0[];
void func_L01_003B7CB8(u8 *m) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_0013D3E0(void);
    extern void func_003C2880(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_003D4D00(void *, s32, void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_0044AF78(u8 *owner, void *direction, f32 *position, f32 radius, f32 damage, s32 sparks,
                           s32 flashes, s32 smoke, f32 glow, f32 white, f32 cutoff, f32 scale, s32 sound,
                           f32 blast, s32 shake, s32 debris, s32 quality, u8 channels, s32 flags);
    vu0_v4 newpos;
    Hit_003B7CB8 hit;
    u8 *vars;
    f32 len;
    s32 flag;

    vars = *(u8 **)(m + 0x68);
    if (m[0x20] != 1) {
        return;
    }
    ((Moby_003B7CB8 *)m)->fF0 = func_0038DAB8(((Moby_003B7CB8 *)m)->fF0, 0.12566371f);
    flag = 0;
    vec_add_ba(&newpos, m + 0x10, vars);
    if (0.9f < D_L01_001DFB4C) {
        flag = 1;
    } else if (0.9f < D_L01_001DFB50) {
        flag = 1;
    }
    if (flag == 0 || (D_L01_001DFB40 & 1) == 0) {
        len = func_0038CEA8(vars);
        *(u128_003B7CB8 *)&hit.c = 0;
        hit.c.x = func_003824E0(-1.0f, 1.0f);
        hit.c.y = func_003824E0(-1.0f, 1.0f);
        hit.c.z = func_003824E0(-1.0f, 1.0f);
        *(u128_003B7CB8 *)&hit.b = *(u128_003B7CB8 *)&hit.c;
        func_0038CF68(&hit.b, &hit.b, func_003824E0(0.04f, 0.08f) * 0.020000001f);
        func_0038CE20(&hit.a, vars, func_003824E0(0.2f, 0.99f));
        vec_add_ba(&hit.b, &hit.b, &hit.a);
        func_0038CF68(&hit.a, vars, func_003824E0(0.0f, 1.0f) * len);
        vec_add_ab(&hit.a, &hit.a, m + 0x10);
        func_L01_0046A610(m + 0x10, &hit.b, 6, 0x7F, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
        *(u128_003B7CB8 *)&hit.c = 0;
        hit.c.z = 0.01f;
        func_0038D000(&hit.c, &hit.c, m + 0xC0);
        func_0038D890(&hit.c, &hit.c, m + 0xC0, func_00382538());
        if (func_0013D3E0() & 1) {
            func_L01_00466588(&hit.a, &hit.c, 0x4F007FFF, 0x1FFFFFFF, 0xB, 1, 25000.0f);
        }
    }
    func_L01_00446760(&hit.a, *(void **)(m + 0xB8), 0x10001, vars, *(f32 *)(vars + 0x14));
    *(u16 *)((u8 *)&hit.b + 0xA) = *(u16 *)(m + 0xAA);
    vec_sub_ab(&hit.a, m + 0x10, *(u8 **)(m + 0xB8) + 0x10);
    hit.a.z = 0.0f;
    func_0038CF68(&hit.a, &hit.a, 2.0000002f);
    hit.a.w = 5627.925f;
    *((u8 *)&hit.b + 8) = 4;
    *(s32 *)&hit.c |= 1;
    if (func_003D3CB0(m + 0x10, &newpos, 0, *(void **)(m + 0xB8), &hit.a) != 0
        || func_L01_003FB640(m + 0x10, 1, *(void **)(m + 0xB8), 0.3f) != 0
        || func_0038CAD0(vars + 0x10) != 0) {
        if (D_L01_001EAA18[0] != 0) {
            if (D_L01_001EAA18[0] != *(u8 **)(m + 0xB8)) {
                if (*(s16 *)(D_L01_001EAA18[0] + 0xAA) != 0x4E) {
                    func_003D4D00(m + 0x10, 0, *(void **)(m + 0xB8), &hit.a, 0.5f);
                }
                func_L01_0044AF78(m, D_L01_001D66B0, 0, 0.0f, 0.0f, 0, 2, 10, 0.0f, 0.0f, 9.0f, 0.666f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
                func_003C2880(m);
                return;
            }
        } else {
            func_L01_0044AF78(m, D_L01_001D66B0, 0, 0.0f, 0.0f, 0, 2, 8, 0.0f, 0.0f, 9.0f, 0.5f, -1, 0.0f, 0, 1, -1, 0, 0x1010001);
            func_003C2880(m);
            return;
        }
    }
    *(u128_003B7CB8 *)(m + 0x10) = *(u128_003B7CB8 *)&newpos;
}
/* localdecomp:end func_L01_003B7CB8 */
#endif
