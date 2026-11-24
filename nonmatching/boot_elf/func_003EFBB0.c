/* func_003EFBB0 (boot_elf), near miss. FE-C 2026-11-22 (218), retried by NM-FE7 2026-11-22 (166).
   From FE-A1's draft of the boot_elf twin (itself from Flavius's functional draft), with the switch's cases
   in the jump table's address order (0, 4, 2, 3, 1), the background colours built by an inline that returns
   a compound literal and the colour argument passed through an inline's by-value parameter (both as
   func_003EE840 in frontbin 3EE160.c). NM-FE7: the "invisible" flag is computed into a scoped local and
   assigned after the four colour stores, which gives retail's $t2 -> $s1 move.
   166 differences (tools/check.py) with its file's line (src/boot_elf/text/3EF658.c: -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as), the same with --no-context (FE-C's
   draft: 218; FE-A1's: 220; Flavius's functional draft: 244). Its frontbin twin func_003EF7F8 (3EE160.c)
   is the same code; the same change gives 166 there.
   Left:
   - the jump table's dispatch: retail builds the table's address (lui, sll, addiu: split HIGH/LO_SUM)
     and loads at offset 0; ours, with -mno-split-addresses, folds %lo into the load (a plain 5-case
     switch compiled with this line does the same). check.py --mode S gives retail's dispatch (106 with
     FE-C's wording, 119 with this one), but split addresses are not the file's line: under --mode S the
     file's matched func_003F0270 (2) and func_003F02D0 (5) stop matching, so no flag change; a cut
     would need this function at 0 under S first;
   - ours keeps the call's colour slot address (sp+0x10) in a saved register for both calls; retail
     recomputes it in each jal delay slot;
   - the registers of the four colours (retail c0..c3 in $s5, $s3, $s4, $s2) and alphas.
   Tried without gain (NM-FE7): alphas as u8 (166), alphas declared in reverse order (166), colours
   assigned after the declarations (218 with FE-C's wording).
   The INCLUDE_RODATA line of jtbl_0031CC60 goes with the marker when it matches. */
#include "common.h"
/* localdecomp:start func_003EFBB0 */
typedef struct { u32 c0, c1, c2, c3; } Color_003EFBB0;
typedef struct VT_003EFBB0 {
    u8 pad[0x20];
    void (*fill)(void *o, s32 a1, f32 *rect, s32 one);
} VT_003EFBB0;
typedef struct CVT_003EFBB0 {
    u8 pad[8];
    void (*fade)(void *c, s32 v);
} CVT_003EFBB0;
typedef struct { s32 f0; CVT_003EFBB0 *vt4; } Child_003EFBB0;
typedef struct {
    u8 pad0[8];
    VT_003EFBB0 *vt;
    u8 padC[0x14];
    f32 offx, offy;
    u32 background;
    u8 pad2C[0xC];
    u32 col0, col1, col2, col3;
    u16 count;
    u8 pad4A[2];
    u8 max, t, state;
    u8 pad4F;
    Child_003EFBB0 *child;
} Obj_003EFBB0;
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
extern s32 func_003EDEB0(void *, s32);
extern void func_003EE0A8(void *, f32 *);
extern s32 func_003EF998();
extern void func_003EF698();
extern void func_0038C6F0(s32, s32, s32, s32, s32, Color_003EFBB0);

static __inline__ Color_003EFBB0 colors_003EFBB0(u32 c) {
    return (Color_003EFBB0){ c, c, c, c };
}

static __inline__ void fill_003EFBB0(Color_003EFBB0 c, f32 x0, f32 y0, f32 x1, f32 y1) {
    func_0038C6F0((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                  (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, c);
}

void func_003EFBB0(Obj_003EFBB0 *o, s32 a1)
{
    f32 rect[4];
    s32 invisible = 0;
    u32 c0 = o->col0, c1 = o->col1, c2 = o->col2, c3 = o->col3;
    u32 al0, al1, al2, al3;
    s32 diff;

    if (o->child != 0) {
        al0 = c0 >> 24;
        al1 = c1 >> 24;
        al2 = c2 >> 24;
        al3 = c3 >> 24;
        switch (o->state) {
        case 0:
            o->t = 0;
            break;
        case 4:
            o->t = o->t + 1;
            if (o->max < o->t) {
                o->t = o->max;
                o->state = 2;
            }
            goto fade;
        case 2:
            o->child->vt4->fade(o->child, o->count - 1);
            o->state = 3;
        case 3:
            o->t = o->max;
            if ((o->child->f0 ^ 2) == 0) {
                o->state = 1;
            }
            al3 = 0;
            al2 = 0;
            al1 = 0;
            al0 = 0;
            break;
        case 1:
            o->t = o->t - 1;
            if (o->t == 0) {
                o->state = 0;
                o->t = 0;
            }
        fade:
            diff = o->max - o->t;
            al3 = (u8)((s32)(al3 * diff) / o->max);
            al0 = (u8)((s32)(al0 * diff) / o->max);
            al1 = (u8)((s32)(al1 * diff) / o->max);
            al2 = (u8)((s32)(al2 * diff) / o->max);
            break;
        }
        {
        s32 inv = al0 == 0 && al1 == 0 && al2 == 0 && al3 == 0;
        o->col0 = (al0 << 24) | (c0 & 0xFFFFFF);
        o->col1 = (al1 << 24) | (c1 & 0xFFFFFF);
        o->col2 = (al2 << 24) | (c2 & 0xFFFFFF);
        o->col3 = (al3 << 24) | (c3 & 0xFFFFFF);
        invisible = inv;
        }
    }

    o->vt->fill(o, a1, rect, 1);
    func_003EE0A8(o, rect);
    if (!invisible) {
        s32 more = 1;

        if (o->count != 0) {
            if (o->child != 0) {
                more = func_003EF998(o, rect);
            } else {
                func_003EF698(o, rect);
                more = 0;
            }
        }
        if (more != 0) {
            if (func_003EDEB0(o, 0x40)) {
                f32 x0 = rect[0] + o->offx, x1 = rect[2] + o->offx;
                f32 y0 = rect[1] + o->offy, y1 = rect[3] + o->offy;

                func_0038C6F0((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                              (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0,
                              colors_003EFBB0(o->background));
            }
            fill_003EFBB0((Color_003EFBB0){ o->col0, o->col1, o->col2, o->col3 },
                          rect[0], rect[1], rect[2], rect[3]);
        }
    }
    if (o->child != 0) {
        o->col3 = c3;
        o->col0 = c0;
        o->col1 = c1;
        o->col2 = c2;
    }
}
/* localdecomp:end func_003EFBB0 */
