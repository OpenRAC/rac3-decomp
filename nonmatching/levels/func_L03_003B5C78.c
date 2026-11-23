/* PAL draft (2026-11-21, Promises): written from level 3's assembly. Its file,
 * src/levels/shared/L03_003B5C78.c, is cut at 0x3B6180 (2026-11-22) and has
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (split addresses and the
 * VU0 flag: the jump table's and func_L03_003B6180's %hi in delay slots, VU0 code).
 * 9 differences (tools/check.py, levels 03 and 05, the file's flags).
 * Left: the 0.034906585f constant (in $f20) and &m->pos (in $s0) come before the first call
 * (func_L01_004561B8) where retail has them after it, just before the first func_003C2F58.
 * Retail's order looks like a scheduling-block boundary after that func_003C2F58 call (the two
 * are its last, lowest-priority insns) or a dependence on the first call; ours has neither.
 * Without scheduling both stay next to their first use; either scheduling pass alone lifts them
 * above every call of the block (-fno-schedule-insns: 9; -fno-schedule-insns2: 22).
 * Tried: an if around the call, a local for the constant (also one set after the first call), a
 * void return, a void callee, a pointer local for &m->pos (set after the call, or in a scope
 * around the rest of case 0) (9); the state pointer read after the call (17); static inline
 * helpers for the three rotations or the rest of case 0 (151-153, the constant leaves $f20), for
 * the first call alone, for the first call with the first func_003C2F58, for one or both
 * func_003C2F58 calls (9); an unused label after the call (9); -fno-gcse, -fno-sched-interblock,
 * -fno-rerun-loop-opt, -fno-cse-follow-jumps, -fno-strict-aliasing, -fno-schedule-insns (9). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B5C78 */
typedef struct {
    vu0_v4 x0;
    vu0_v4 x10;
    f32 x20;
    s32 x24;
    f32 x28;
    void *x2C;
    s32 x30;
} State_003B5C78;

typedef struct {
    u8 pad0[0xAA];
    s16 xAA;
} Target_003B5C78;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x47];
    State_003B5C78 *p68;
    u8 pad6C[0x2C];
    s32 x98;
    u8 pad9C[0xC];
    u8 xA8;
    u8 padA9[0xF];
    Target_003B5C78 *xB8;
    u8 padBC[0x4];
    vu0_v4 xC0;
    u8 padD0[0x20];
    f32 xF0;
    f32 xF4;
    f32 xF8;
} Moby_003B5C78;

extern s32 func_L01_004561B8(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L03_003AD510(void *);
extern void func_003C2880(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_003ADB38(void *);
extern void func_L03_003B6180(void *);
extern void func_L03_003B6740(void *, s32, s32, s32);

void func_L03_003B5C78(Moby_003B5C78 *m) {
    State_003B5C78 *s = m->p68;
    vu0_v4 d;
    vu0_v4 p;

    switch (m->state) {
    case 0:
        func_L01_004561B8(m);
        func_003C2F58(s->x2C, s->x30, &s->x10);
        func_003C2F58(s->x2C, s->x30 + 0x20, &s->x0);
        s->x28 += s->x20;
        vec_sub_ba(&d, &s->x0, &s->x10);
        func_0038CF68(&d, &d, s->x28);
        vec_add_ba(&m->pos, &s->x10, &d);
        m->xF0 = func_0038DAB8(m->xF0, 0.034906585f);
        m->xF4 = func_0038DAB8(m->xF4, 0.034906585f);
        m->xF8 = func_0038DAB8(m->xF8, 0.034906585f);
        func_0038D308(&m->xC0, &m->xF0);
        if (func_0038CF38(&m->pos, s) <= s->x20 * 0.88f) {
            if (s->x24 == 0 && m->xB8 != 0 && m->xB8->xAA == 0x1AE0) {
                func_L03_003AD510(m->xB8);
                s->x24 += 3;
                return;
            }
            p = m->pos;
            func_L03_003B6740(&p, 100, 0x88202020, 0x88208020);
            func_003C2880(m);
        } else if (func_L01_00447490(m, 0x10000, 0) != 0) {
            func_003C2880(m);
        } else {
            m->xA8 = 0xFF;
            func_L01_00404808(func_L03_003B6180, m);
        }
        break;
    case 1:
        m->x98 = 0;
        m->xF0 = func_0038DAB8(m->xF0, 0.034906585f);
        m->xF4 = func_0038DAB8(m->xF4, 0.034906585f);
        m->xF8 = func_0038DAB8(m->xF8, 0.034906585f);
        func_L01_00404808(func_L03_003B6180, m);
        break;
    case 4:
        func_L01_004450F0(m, 0, -1);
        break;
    case 2:
        if (m->xB8 != 0 && m->xB8->xAA == 0x1AE0) {
            func_L03_003ADB38(m->xB8);
        }
        func_003C2880(m);
        break;
    case 3:
        break;
    }
}
/* localdecomp:end func_L03_003B5C78 */
