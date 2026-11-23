/* Level 4 (Marcadia), file L04_003D0968.c (its line: -O2 -G8 -fopt-stack -mno-check-zero-division
 * -mvu0-use-vf0-vf2 @ps2as). tools/check.py at level 04: 89 differences (2026-11-21, task #2809).
 * - The prototype is the file's own (`M_003D0968 *, V_003D0968 *`, from func_L04_003D0968's block), cast to
 *   byte pointers inside; the earlier `(u8 *, u8 *)` draft no longer compiled in the file's context.
 * - 264 -> 89: the second search compares against `*(s32 *)(v + 0x90) + 1` read in place instead of an
 *   `n` assigned in the else-if test. With `n`, gcc keeps the first load of +0x90 in a register for the
 *   whole if/else chain (264); retail reloads +0x90 in the else branch.
 * - Still open (the blocker): the three inlined moby-group searches (D_L04_0021C9A0 / D_L04_001DFD9C, as in
 *   func_L04_003627C8) compile, but retail has the found-exits (`b ...; sw $a1, 0x94($s2)`) placed after the
 *   early `return 0` and before the first loop. Loops 1 and 3 share one exit block there, which jumps past all
 *   three searches, and loop 2 has its own, which jumps to the `+0x94 == 0` test. Here they land after the
 *   first loop, which shifts every branch. Retail also keeps the else-branch value of +0x90 in $t2 for loop 2
 *   (`addiu $a0, $t2, 1`); this C reloads it in the loop. Also the loop-setup register choice and the order of
 *   the child-vars stores (+0x60/+0x6C, +0x40).
 * - Tried (task #2809): `goto` exits to a common label (264); `n` assigned inside a nested
 *   else (264); `n` assigned after the else-if test (264); `vv->w90`/`vv->p94` struct fields (264);
 *   `*(s32 *)(v + 0x90) + 1 == 0` for the first test (75, but it
 *   compiles to addiu/bnez where retail compares with $s0 = -1, so it is not retail's form).
 * Stopped per AGENTS.md.
 * Task #2882 (2026-11-22): re-measured 89 differences (tools/check.py) at level 04 with the file's line. One more
 * wording: the three searches as one `static __inline__` helper returning the found moby (or 0), with the
 * `+0x94` store in the caller under `if (e != 0)`: 276 differences. */
#include "common.h"

/* localdecomp:start func_L04_003D0C40 */
#include "vu0.h"

extern u16 *D_L04_0021C9A0[];
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFDD8, 4");
extern s32 D_L04_001DFDD8;
__asm__(".extern D_L04_001DEB10, 4");
extern f32 D_L04_001DEB10;
__asm__(".extern D_L04_001DEB20, 4");
extern f32 D_L04_001DEB20;
typedef void (*Fn_L04_003D0C40)(u8 *);
extern void func_L01_00456230(void *, s32);
extern Fn_L04_003D0C40 *func_L01_0043B548(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C7C38(void *);
extern f32 func_0038DAB8(f32, f32);
extern u8 *func_L04_003E2390(void *, vu0_v4 *, vu0_v4 *, s32, s32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L04_003D0C40(M_003D0968 *mm, V_003D0968 *vv) {
    u8 *m = (u8 *)mm;
    u8 *v = (u8 *)vv;
    u16 *p;
    u8 *e;
    u8 *c;
    u8 *cv;
    vu0_v4 pos;
    vu0_v4 rot;

    func_L01_00456230(m, 0);
    v[0x38] = 1;
    *(s32 *)(v + 0xA4) = -1;
    if (*(s32 *)(v + 0x70) > 0) {
        Fn_L04_003D0C40 *t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(v + 0x70) = -1;
        v[0x7E] = 4;
        t[0](m);
        return 0;
    }
    *(u8 **)(v + 0x94) = 0;
    if (*(s32 *)(v + 0x90) == -1) {
        p = D_L04_0021C9A0[m[0x21]];
        while (m[0x21] != 0xFF && m[0x21] <= D_L04_001DFDD8 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[m[0x21]])) {
            e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                break;
            }
            if (*(s32 *)(*(u8 **)(e + 0x68) + 0x90) == 1) {
                *(u8 **)(v + 0x94) = e;
                break;
            }
            p++;
        }
    } else if (*(s32 *)(v + 0x90) >= -1) {
        p = D_L04_0021C9A0[m[0x21]];
        while (m[0x21] != 0xFF && m[0x21] <= D_L04_001DFDD8 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[m[0x21]])) {
            e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
            if (e == 0) {
                break;
            }
            if (*(s32 *)(*(u8 **)(e + 0x68) + 0x90) == *(s32 *)(v + 0x90) + 1) {
                *(u8 **)(v + 0x94) = e;
                break;
            }
            p++;
        }
        if (*(u8 **)(v + 0x94) == 0) {
            p = D_L04_0021C9A0[m[0x21]];
            while (m[0x21] != 0xFF && m[0x21] <= D_L04_001DFDD8 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L04_0021C9A0[m[0x21]])) {
                e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                if (*(s32 *)(*(u8 **)(e + 0x68) + 0x90) == -2) {
                    *(u8 **)(v + 0x94) = e;
                    break;
                }
                p++;
            }
        }
    }
    if (*(s32 *)(v + 0x90) == -2 || *(s32 *)(v + 0x90) == -1) {
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        *(s32 *)(m + 0x98) = 0;
        func_L01_004AA7E8(m, 1);
        *(u8 **)(v + 0x9C) = 0;
        *(u8 **)(v + 0xA0) = 0;
    } else {
        c = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) &= ~0x41;
        *(u16 *)(m + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(c + 0x10);
        *(u8 **)(v + 0x9C) = func_003C24B0(0xB57, 0xA0);
        (*(u8 **)(v + 0x9C))[0x30] = m[0x30];
        *(u16 *)(*(u8 **)(v + 0x9C) + 0x32) = *(u16 *)(m + 0x32);
        cv = *(u8 **)(*(u8 **)(v + 0x9C) + 0x68);
        *(f32 *)(cv + 0x68) = 1.0f;
        *(s32 *)(cv + 0x90) = -1;
        *(s32 *)(cv + 0x74) = -1;
        *(f32 *)(cv + 0x70) = 3.5f;
        *(s32 *)(cv + 0x60) = *(s32 *)(v + 0x98);
        *(s32 *)(cv + 0x6C) = 0;
        func_0038D000(*(u8 **)(v + 0x9C) + 0x10, &D_L04_001DEB10, m + 0xC0);
        vec_add_ba(*(u8 **)(v + 0x9C) + 0x10, *(u8 **)(v + 0x9C) + 0x10, m + 0x10);
        *(vu0_q *)(*(u8 **)(v + 0x9C) + 0xF0) = *(vu0_q *)(m + 0xF0);
        func_0038D308(*(u8 **)(v + 0x9C) + 0xC0, *(u8 **)(v + 0x9C) + 0xF0);
        *(s32 *)(cv + 0x40) = 0;
        *(f32 *)(cv + 0x7C) = *(f32 *)(*(u8 **)(v + 0x9C) + 0x18);
        func_L01_00456230(*(u8 **)(v + 0x9C), 0);
        (*(u8 **)(v + 0x9C))[0x20] = 6;
        func_003C7C38(*(u8 **)(v + 0x9C));
        func_0038D000(&pos, &D_L04_001DEB20, m + 0xC0);
        vec_add_ab(&pos, &pos, m + 0x10);
        *(vu0_q *)&rot = *(vu0_q *)(m + 0xF0);
        rot.z = func_0038DAB8(rot.z, 3.14159274f);
        *(u8 **)(v + 0xA0) = func_L04_003E2390(m, &pos, &rot, *(s32 *)(v + 0x80), *(s32 *)(v + 0x88),
                                               *(f32 *)(v + 0x84), *(f32 *)(v + 0x8C), v[0x44]);
        (*(u8 **)(v + 0xA0))[0x30] = m[0x30];
        *(u16 *)(*(u8 **)(v + 0xA0) + 0x32) = *(u16 *)(m + 0x32);
        func_003C7C38(*(u8 **)(v + 0xA0));
    }
    if (*(s32 *)(v + 0x90) == -3) {
        func_L01_004450F0(m, 2, -1);
    } else {
        func_L01_004450F0(m, 1, -1);
    }
    return 1;
}
/* localdecomp:end func_L04_003D0C40 */
