/* func_L05_0032A4D8: Promises (task 2790, 2026-11-21), written from the PAL asm (upstream also has a
 * nonmatching/functional/ draft of it, not used here).
 * Near miss: 408 differences (tools/check.py), level 05, with -mvu0-use-vf0-vf2 @ps2as (the count is large
 * because the prologue is one word short and every later row shifts). Needs on the file: -mvu0-use-vf0-vf2 (its
 * neighbour func_L05_0032AB50 still matches with it) and the existing @ps2as, plus the divs_nops row
 * `func_L05_0032A4D8 2` (retail has two nops before the div.s). With those, everything after the prologue matches.
 * Left: retail keeps the 20.0f argument of func_L01_00477ED0 in the callee-saved $f20 (lui/mtc1 $f20 at the
 * top, mov.s $f14,$f20 before the call); ours loads it straight into $f14, which also moves the D_L05_0021ED80
 * address into $a2 instead of $a1. Tried: a local holding 20.0 (used for the call only, for the call and the
 * speed formula, reused for the 1.0 later), an inline wrapper for the call: none puts it in $f20.
 * Task 2812 (2026-11-22) also tried: the call first, before `pos = o->pos`; the call's arguments in
 * temporaries; the call right after `path = ...`; 20.0 assigned to sp, lim, dot or h just before the call
 * (all 403-408). A local `k = 20.0f` used by the call and the speed formula gives 390: the prologue then
 * has retail's mtc1/mov.s shape and $a1 address, but k lives to the formula in a third saved register
 * ($f22, frame 0xC0 instead of 0xB0), where retail reloads 20.0 into $f0.
 * Task 2895 (2026-11-22) re-measured 408 (with and without --no-context) and read the RTL dumps (-da). Retail
 * reuses $f20 for 20.0, then for the 1.0 of the normalise call and the clamp, then 0.10471976 and 0.01, so the
 * 20.0 is most likely the same variable as the 1.0 (only that phase crosses calls, which explains $f20). But a
 * variable set to 20.0, passed to the call and then set to 1.0 (`one = 20.0f; ... one = 1.0f;`, also used by the
 * clamp) still gives 408: CSE keeps the pseudo for the argument, then combine folds the 20.0 into the $f14 move,
 * because the variable dies at the call. In retail it survived combine, so in the original it was still live
 * after the call, although retail's code shows no later read of it before the 1.0.
 * Task 2978 (2026-11-23, upstream bbf261a1; same recipe: -mvu0-use-vf0-vf2 @ps2as and the divs_nops row,
 * level 05) also tried: a scoped `{ f32 hi = 20.0f; ... }` for the call, `f32 k = 20.0f` initialised at the top,
 * `k = 20.0f` before `pos = o->pos`, an inline helper whose parameter is reassigned, and one variable set to 20.0
 * for the call and to 1.0 for the normalise, the clamp and the later `1.0f <= u` (all 408: combine folds the
 * constant into the $f14 move whenever the variable dies at the call); `sp = 20.0f` for the call and the formula
 * (397: three saved float registers). `k` for the call and the formula reproduces 390 ($f22, frame 0xC0).
 * Retail reads $f20 nowhere between the call and its 1.0 load, so a 20.0 variable that lives past the call
 * always overlaps the 1.0 and takes a third saved register.
 * CLOSEOUT attempt 1 of 2 (task 3057, 2026-11-24, upstream 5eb0ce11; same recipe): no change. 408 differences
 * (tools/check.py, level 05; 407 at levels 16 and 19), the same with --no-context; compared one row off from row 30,
 * 2 rows differ at level 05 (both in the prologue) and 8 at levels 16 and 19 (the same 2, plus 6 $gp loads that
 * check.py shows at offset 0 there for the D_L05_ names). Tried: `k = 20.0f` for the call plus a test that is
 * always false right after it (`k < 0.0f || s->f164 < 0.0f`, and `s->f164 < 0.0f || k <= 0.0f`), to keep k live
 * across the call so that it takes a saved register while the test folds away later: both compile to exactly
 * the draft's bytes (cse folds the test first, so k still dies at the call). `k` for the call and the formula
 * reproduces 390: the prologue is then retail's except that k is in $f22 (f in $f21, the 1.0 in $f20) and the
 * frame is 0xC0. Retail's 20.0 must cross the call and die before the 1.0 is set, with no read in between that
 * survives to the output; no plain C form for that was found.
 * The $gp floats are level data (gp+0x4..0x18 in level 05, gp+0x24.. in level 16, gp+0x54.. in level 19), so
 * they are D_L05_ names with `.extern X, 4` hints (the build derives them per level).
 * The three path-segment cases are vec_sub_ba() each (gcc cross-jumps their vsub/sqc2 tail as retail has it).
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0032A4D8 */
typedef struct {
    s32 n;
    u8 pad4[0xC];
    vu0_v4 pts[1];
} Path_0032A4D8;
typedef struct {
    u8 pad0[0x90];
    s32 t90[4];
    u8 padA0[0x15C - 0xA0];
    s32 i15C;
    s32 i160;
    f32 f164;
    f32 f168;
    u8 pad16C[4];
    f32 f170;
    f32 f174;
    f32 f178;
    u8 pad17C[4];
    vu0_v4 v180;
    vu0_v4 v190;
} S_0032A4D8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0xC0 - 0x20];
    u8 mC0[0x30];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} O_0032A4D8;
typedef struct {
    u8 pad0[0x70];
    vu0_v4 r70;
} T_0032A4D8;
extern Path_0032A4D8 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
__asm__(".extern D_L05_001DC8B4, 4");
extern f32 D_L05_001DC8B4;
__asm__(".extern D_L05_001DC8B8, 4");
extern f32 D_L05_001DC8B8;
__asm__(".extern D_L05_001DC8C0, 4");
extern f32 D_L05_001DC8C0;
__asm__(".extern D_L05_001DC8C4, 4");
extern f32 D_L05_001DC8C4;
__asm__(".extern D_L05_001DC8C8, 4");
extern f32 D_L05_001DC8C8;
extern f32 func_L01_00477ED0(s32, s32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_L05_0032A238(S_0032A4D8 *, Path_0032A4D8 *, s32 *, f32, f32);
extern void func_L05_0032A360(S_0032A4D8 *, Path_0032A4D8 *, s32, void *, f32);
extern void func_L01_003ABF48(O_0032A4D8 *, S_0032A4D8 *, void *, f32 *, f32 *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038DBA0(f32, f32);

s32 func_L05_0032A4D8(O_0032A4D8 *o, S_0032A4D8 *s) {
    vu0_v4 dir;
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 tgt;
    vu0_v4 d2;
    f32 tmp;
    s32 seg;
    Path_0032A4D8 *path;
    T_0032A4D8 *t;
    f32 f;
    f32 g;
    f32 h;
    f32 dot;
    f32 lim;
    f32 sp;
    f32 u;
    s32 r;
    s32 end;

    pos = o->pos;
    path = D_L05_0021ED80[s->i160];
    t = (T_0032A4D8 *)(D_L05_001DFC80 + (s->t90[s->i15C] << 7));
    f = func_L01_00477ED0(s->i160, 1, s->v180.w, s->f164, 20.0f);
    if (s->f164 < 0.0f) {
        vec_sub_ba(&dir, &path->pts[0], &s->v180);
    } else {
        seg = s->f164;
        if (seg == path->n - 1) {
            vec_sub_ba(&dir, &s->v190, &path->pts[seg]);
        } else {
            vec_sub_ba(&dir, &path->pts[seg + 1], &path->pts[seg]);
        }
    }
    func_0038CF68(&dir, &dir, 1.0f);
    dot = func_0038CE68(&dir, o->mC0);
    if (dot <= 0.0f) {
        sp = D_L05_001DC8B8;
    } else {
        dot = dot * D_L05_001DC8B4;
        if (1.0f < dot) {
            dot = 1.0f;
        }
        sp = D_L05_001DC8B8 + (20.0f - D_L05_001DC8B8) * dot;
    }
    tmp = 0.0f;
    func_003C41A0(&tmp, &s->f168, f, 0.0032000002f, 0.0032000002f, sp * 0.020000001f);
    r = 0;
    g = func_L05_0032A238(s, path, &seg, s->f164, s->f168);
    s->f164 = g;
    end = 0;
    if (seg >= path->n - 1) {
        seg = path->n - 1;
        end = 1;
    }
    u = g - seg;
    if (end && 1.0f <= u) {
        u = 1.0f;
        r = 1;
        s->f164 = g - s->f168 / path->pts[seg].w;
    }
    func_L05_0032A360(s, path, seg, &o->pos, u);
    rot.x = 0.0f;
    if ((rot.x < s->v180.w && seg == -1) || (s->v180.w < rot.x && seg == 0)) {
        func_L01_003ABF48(o, s, &pos, &rot.x, &rot.y);
        rot.x = func_0038DAB8(rot.x, t->r70.x);
        if (0.43633232f < rot.y) {
            rot.y = 0.43633232f;
        } else if (rot.y < -0.43633232f) {
            rot.y = -0.43633232f;
        }
        rot.y = func_0038DAB8(rot.y, t->r70.y);
        rot.z = o->fF8;
    } else if (seg >= path->n - 2) {
        func_L01_003ABF48(o, s, &pos, &rot.x, &rot.y);
        rot.x = -rot.x;
        rot.y = -rot.y;
        rot.x = func_0038DAB8(rot.x, t->r70.x);
        if (0.43633232f < rot.y) {
            rot.y = 0.43633232f;
        } else if (rot.y < -0.43633232f) {
            rot.y = -0.43633232f;
        }
        rot.y = func_0038DAB8(rot.y, t->r70.y);
        rot.z = t->r70.z;
    } else {
        lim = s->f168 * D_L05_001DC8C0;
        if (D_L05_001DC8C4 < lim) {
            lim = D_L05_001DC8C4;
        } else if (lim < D_L05_001DC8C8) {
            lim = D_L05_001DC8C8;
        }
        h = func_L05_0032A238(s, path, &seg, s->f164, lim);
        seg = h;
        func_L05_0032A360(s, path, seg, &tgt, h - seg);
        vec_sub_ab(&d2, &tgt, &o->pos);
        rot.y = -func_0038D160(func_0038CED8(&d2), d2.z);
        if (0.43633232f < rot.y) {
            rot.y = 0.43633232f;
        } else if (rot.y < -0.43633232f) {
            rot.y = -0.43633232f;
        }
        rot.z = func_0038D160(d2.x, d2.y);
    }
    func_L01_00448890(&o->fF4, rot.y, &s->f174, 0.00069813174f, 0.00069813174f, 0.10471976f, 0);
    func_L01_00448890(&o->fF8, rot.z, &s->f178, 0.0010471976f, 0.0010471976f, 0.10471976f, 0);
    rot.x = func_0038DAB8(rot.x, s->f178 * s->f168 * -50.0f);
    if (0.43633232f < rot.x) {
        rot.x = 0.43633232f;
    } else if (rot.x < -0.43633232f) {
        rot.x = -0.43633232f;
    }
    func_L01_00448890(&o->fF0, rot.x, &s->f170, 0.00069813174f, 0.00069813174f, 0.10471976f, 0);
    rot = t->r70;
    if (0.01f < __builtin_fabsf(func_0038DBA0(o->fF0, rot.x))
        || 0.01f < __builtin_fabsf(func_0038DBA0(o->fF4, rot.y))
        || 0.01f < __builtin_fabsf(func_0038DBA0(o->fF8, rot.z))) {
        r = 0;
    }
    return r ^ 1;
}
/* localdecomp:end func_L05_0032A4D8 */
