/* near miss (round 19 worker J5D): 7 aligned rows of 267 words (12 raw diffs, same length as retail) with `--mode S` (split addresses) and the file's other flags.
 * check.py --all-modes: S + ps2as 55 raw (before the fixes below), N 156: retail is built in S mode, but the file's line (L01_00302118.c) has -mno-split-addresses, so a
 * match needs a CUT: a new file at 0x303228 with `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2` (8-aligned at all 34 places) and the rest
 * (func_L01_00303658 on) in a file with the old line. An effect drawing a ring of 4 x 4 textured quads around the moby (GS packet on the stack, 0xFF90 / 0x260 tags):
 * the basis from the owner's matrix rows (func_0038CE90 / CF68), a random angle accumulated in D_L01_001E16E4, one func_003D9508 spawn, then the quad loop with
 * u / v = x * 0.5 + 0.5 wrapped by func_L01_0040F518(., 8.0).
 * What fixed most (32 -> 7): the owner pointer split into two variables (`owner` / `o2`: one variable set in two blocks is a global pseudo and took $a3), the colour stores
 * as an if / else with a store chain per arm, `extern u8 D_L01_001E16D0[8]` (the 8-byte `la` form gives retail's `lui $at; lqc2 vf1,lo($at)`), `r = &s.b0` early,
 * the gp table as `s16 D[4]` + `.extern D, 8` (`addiu $v1,$gp,-0x350`), no local copy of D_L01_001E29C0 (the vf pseudo is spilled by reload, as in retail).
 * Left (7 rows): (1) the vector block after the first func_003C5278 call: retail schedules `lqc2 vf1,D16D0; swc1 f20,0xcc; sqc2 vf1,0xf0; lqc2 vf2,D29C0($s0); lqc2 vf1,0xc0 ...`
 * with the D29C0 value in vf2 and its spill slot at 0x110, this C has the c.w store first and the D29C0 load in vf1; (2) the pointer spill slot: retail 0x100 (pointer) / 0x110
 * (vf spill), this C the other way round (reload numbers the slots by pseudo number: the vf pseudo comes before loop.c's hoisted `&uv` pointer here). Sweeps over the
 * position of `s.c.w = 1.0f`, of the vec_copy, of `r = &s.b0` and the helper forms (ab / ba) all stay at 7. */
#include "common.h"

/* localdecomp:start func_L01_00303228 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00303228;
typedef struct {
    V_00303228 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
    V_00303228 b0, b1, b2;
    V_00303228 c, d, e, f;
} S_00303228;

extern s32 D_L01_001DC580;
extern s32 D_L01_001DC584;
extern s32 D_L01_001DC588;
extern s32 D_L01_001DC58C;
extern s32 D_L01_001DC590;
extern s32 D_L01_001DC594;
extern s32 D_L01_001DC598;
extern s32 D_L01_001DC59C;
extern s32 D_L01_001DC5AC;
extern f32 D_L01_001DC5B0;
extern s16 D_L01_001DC560[4];
__asm__(".extern D_L01_001DC580, 4");
__asm__(".extern D_L01_001DC584, 4");
__asm__(".extern D_L01_001DC588, 4");
__asm__(".extern D_L01_001DC58C, 4");
__asm__(".extern D_L01_001DC590, 4");
__asm__(".extern D_L01_001DC594, 4");
__asm__(".extern D_L01_001DC598, 4");
__asm__(".extern D_L01_001DC59C, 4");
__asm__(".extern D_L01_001DC5AC, 4");
__asm__(".extern D_L01_001DC5B0, 4");
__asm__(".extern D_L01_001DC560, 8");
extern u8 D_L01_001E16D0[8];
extern f32 D_L01_001E16E4;
extern V_00303228 D_L01_001E29C0;
extern V_00303228 D_L01_002A7CA0[];
extern V_00303228 D_L01_002A7DA0[];
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00301788(u8 *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern f32 func_L01_0040F518(f32, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_00303228(u8 *m)
{
    S_00303228 s;
    u8 *info;
    u8 *owner;
    u8 *o2;
    V_00303228 *tbl;
    V_00303228 *r;
    s32 i;
    s32 j;
    f32 ang;
    f32 u;
    f32 v;

    info = *(u8 **)(m + 0x68);
    if (info != 0) {
        s.x78 = func_00389598(D_L01_001DC594);
        s.x88 = (long)D_L01_001DC580 | ((long)D_L01_001DC584 << 2) | ((long)D_L01_001DC588 << 4) | ((long)D_L01_001DC58C << 6)
                | ((long)D_L01_001DC590 << 32);
        s.x80 = 0xFF9000000260L;
        s.x70 = 0;
        func_003A9440(0x47, 0x53001);
        if (m[0x20] == 1) {
            owner = *(u8 **)(m + 0xB8);
            *(vu0_q *)(m + 0x10) = *(vu0_q *)(owner + 0x10);
            *(vu0_q *)(info + 0x10) = *(vu0_q *)(owner + 0x10);
            func_003C5278(m + 0x10, info + 0x10, info + 0x10, -0.5f);
        }
        r = &s.b0;
        s.c.x = *(f32 *)(m + 0x10);
        s.c.y = *(f32 *)(m + 0x14);
        s.c.z = *(f32 *)(m + 0x18);
        func_003C5278(m + 0x10, &s.c, &s.c, -0.5f - *(f32 *)info);
        s.c.w = 1.0f;
        vec_copy(&s.f, D_L01_001E16D0);
        vec_add_ab(&s.c, &s.c, &s.f);
        vec_sub_ba(&s.e, &D_L01_001E29C0, &s.c);
        func_0038CF68(r, &s.e, 1.0f);
        func_0038CE90(&s.b1, r, *(u8 **)(m + 0xB8) + 0xE0);
        func_0038CF68(&s.b1, &s.b1, 1.0f);
        func_0038CE90(&s.b2, &s.b1, r);
        if (info[0x57] != 0) {
            s.c40 = s.c44 = s.c48 = s.c4C = D_L01_001DC59C;
        } else {
            s.c40 = s.c44 = s.c48 = s.c4C = D_L01_001DC598;
        }
        ang = func_0038DAB8(D_L01_001E16E4, func_003824E0(-0.15f, -0.3f) * 0.017453292f);
        D_L01_001E16E4 = ang;
        func_003D9508(info + 0x10, 0x59, info[0x57] != 0 ? 0x4F7F207F : 0x4FFF2020, 1, 0.4f, 0.0f, ang);
        if (func_L01_00301788(m) != 0) {
            s.x78 = func_00389598(D_L01_001DC5AC);
            s.c40 = s.c44 = s.c48 = s.c4C = 0x107F7F7F;
            s.x88 = 0x8000000044L;
            o2 = *(u8 **)(m + 0xB8);
            *(vu0_q *)&s.b0 = *(vu0_q *)(o2 + 0xC0);
            *(vu0_q *)&s.b1 = *(vu0_q *)(o2 + 0xD0);
            *(vu0_q *)&s.b2 = *(vu0_q *)(o2 + 0xE0);
            s.c.z = *(f32 *)(m + 0x18);
            if (*(s16 *)(o2 + 0xAA) == 0x1F5) {
                tbl = D_L01_002A7DA0;
            } else {
                tbl = D_L01_002A7CA0;
            }
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    func_0038D028(&s.m[j], &tbl[D_L01_001DC560[i * 4 + j]], &s.b0);
                    vec_sub_ab(&s.d, &s.m[j], &D_L01_001E29C0);
                    s.d.y = s.d.z;
                    func_0038CFB8(&s.d, &s.d, D_L01_001DC5B0);
                    u = s.d.x * 0.5f + 0.5f;
                    s.uv[j][0] = u;
                    s.uv[j][0] = func_L01_0040F518(u, 8.0f);
                    v = s.d.y * 0.5f + 0.5f;
                    s.uv[j][1] = v;
                    s.uv[j][1] = func_L01_0040F518(v, 8.0f);
                }
                func_003D2DA0(&s, 0, 0);
            }
        }
        func_003A9440(0x47, 0x5360B);
    }
}
/* localdecomp:end func_L01_00303228 */
