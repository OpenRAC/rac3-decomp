/* func_003EF7F8 (frontbin), FE-C 2026-11-22: near miss. From FE-A1's draft of the boot_elf twin
   (itself from Flavius's functional draft), with the switch's cases in the jump table's address order
   (0, 4, 2, 3, 1), the background colours built by an inline that returns a compound literal and the
   colour argument passed through an inline's by-value parameter (both as func_003EE840 in frontbin 3EE160.c).
   218 differences (tools/check.py) with its file's line (src/frontbin/3EE160.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as),
   the same with --no-context. Its boot_elf twin func_003EFBB0 (3EF658.c) is the same code with the callees moved, also 218.
   Left:
   - the jump table's dispatch: retail builds the table's address (lui/addiu) and loads at offset 0; ours,
     with -mno-split-addresses, folds %lo into the load. check.py --mode S (split addresses, not the file's
     flags) gives retail's dispatch and 106 differences;
   - ours keeps the call's colour slot address (sp+0x10) in $s1 for both calls; retail recomputes it in each
     delay slot and keeps the "invisible" flag in $s1 (computed in $t2, then moved);
   - the registers of the four colours and alphas.
   The INCLUDE_RODATA line of jtbl_0031CC30 goes with the marker when it matches. */
#include "common.h"
/* localdecomp:start func_003EF7F8 */
typedef struct { u32 c0, c1, c2, c3; } Color_003EF7F8;
typedef struct VT_003EF7F8 {
    u8 pad[0x20];
    void (*fill)(void *o, s32 a1, f32 *rect, s32 one);
} VT_003EF7F8;
typedef struct CVT_003EF7F8 {
    u8 pad[8];
    void (*fade)(void *c, s32 v);
} CVT_003EF7F8;
typedef struct { s32 f0; CVT_003EF7F8 *vt4; } Child_003EF7F8;
typedef struct {
    u8 pad0[8];
    VT_003EF7F8 *vt;
    u8 padC[0x14];
    f32 offx, offy;
    u32 background;
    u8 pad2C[0xC];
    u32 col0, col1, col2, col3;
    u16 count;
    u8 pad4A[2];
    u8 max, t, state;
    u8 pad4F;
    Child_003EF7F8 *child;
} Obj_003EF7F8;
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
extern s32 func_003EDAF8(void *, s32);
extern void func_003EDCF0(void *, f32 *);
extern s32 func_003EF5E0();
extern void func_003EF2E0();
extern void func_0038C310(s32, s32, s32, s32, s32, Color_003EF7F8);

static __inline__ Color_003EF7F8 colors_003EF7F8(u32 c) {
    return (Color_003EF7F8){ c, c, c, c };
}

static __inline__ void fill_003EF7F8(Color_003EF7F8 c, f32 x0, f32 y0, f32 x1, f32 y1) {
    func_0038C310((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                  (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, c);
}

void func_003EF7F8(Obj_003EF7F8 *o, s32 a1)
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
        invisible = al0 == 0 && al1 == 0 && al2 == 0 && al3 == 0;
        o->col0 = (al0 << 24) | (c0 & 0xFFFFFF);
        o->col1 = (al1 << 24) | (c1 & 0xFFFFFF);
        o->col2 = (al2 << 24) | (c2 & 0xFFFFFF);
        o->col3 = (al3 << 24) | (c3 & 0xFFFFFF);
    }

    o->vt->fill(o, a1, rect, 1);
    func_003EDCF0(o, rect);
    if (!invisible) {
        s32 more = 1;

        if (o->count != 0) {
            if (o->child != 0) {
                more = func_003EF5E0(o, rect);
            } else {
                func_003EF2E0(o, rect);
                more = 0;
            }
        }
        if (more != 0) {
            if (func_003EDAF8(o, 0x40)) {
                f32 x0 = rect[0] + o->offx, x1 = rect[2] + o->offx;
                f32 y0 = rect[1] + o->offy, y1 = rect[3] + o->offy;

                func_0038C310((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                              (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0,
                              colors_003EF7F8(o->background));
            }
            fill_003EF7F8((Color_003EF7F8){ o->col0, o->col1, o->col2, o->col3 },
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
/* localdecomp:end func_003EF7F8 */
