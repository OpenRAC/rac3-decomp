/* func_003EFBB0 (boot_elf), near miss. FE-C 2026-11-22 (218), NM-FE7/NM-FE8 2026-11-22 (166), PASS-P5 2026-11-23:
   0 differences with split addresses (tools/check.py --mode S: MATCH, PAL and --version us), 216 with its
   file's line (src/boot_elf/text/3EF658.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division
   -mno-split-addresses @ps2as), the same with --no-context (and 0 under --mode S with --no-context). Twin of frontbin func_003EF7F8 (the same C with the names
   moved, the same counts).
   PASS-P5's changes, each measured under --mode S (119 -> 0):
   - both draw calls go through the fill inline (the background call too): the two by-reference colour
     arguments then come from distinct pre-reload slots, and GCSE no longer keeps sp+0x10 in a saved
     register across both calls (119 -> 31; -fno-gcse, a diagnostic only, gave the same);
   - the colours are restored in field order col0..col3: the last store also kills `o`, sched1 picks it
     first, which gives retail's col3, col0, col1, col2 order and the colours' registers $s5, $s3, $s4, $s2
     (31 -> 20);
   - the fade arm divides the alphas in field order al0..al3, which gives the alphas' registers (20 -> 0).
   - the two float constants are declared plainly (`extern f32 D_001D9698;`), as the file's earlier blocks
     do: with `__attribute__((section(".rodata")))` the block measures 0 only inside the file's context and
     91 with --no-context (the colours and a1 take other saved registers); declared plainly it is 0 both ways.
   Left: only the jump table's dispatch. Retail builds the table's address with split HIGH/LO_SUM
   (lui, sll, addiu, addu, lw 0); -mno-split-addresses folds %lo into the load. Every other instruction
   equals retail under split addresses, so this function was compiled without -mno-split-addresses.
   A whole-file S line breaks matched functions (func_003F0270 2, func_003F02D0 5). A cut would let it match:
   3EF658.c cut at func_003F0270 (0x3F0270): 3EF658.c keeps func_003EF658 .. func_003F0250 with the line
   without -mno-split-addresses (all of them still MATCH under --mode S: func_003EF658, 003EF998, 003EFF68,
   003F01C8, 003F0250), and a new file from func_003F0270 keeps the -mno-split-addresses line
   (func_003F0270 2 and func_003F02D0 5 under S; func_003F02C8, 003F0358, 003F0388, 003F03A0 match either way).
   That cut moves other contributors' matched C into a new file (r3-20), so it is not made here.
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
extern f32 D_001D9698;
extern f32 D_001D969C;
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
            al0 = (u8)((s32)(al0 * diff) / o->max);
            al1 = (u8)((s32)(al1 * diff) / o->max);
            al2 = (u8)((s32)(al2 * diff) / o->max);
            al3 = (u8)((s32)(al3 * diff) / o->max);
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
                fill_003EFBB0(colors_003EFBB0(o->background), rect[0] + o->offx, rect[1] + o->offy,
                              rect[2] + o->offx, rect[3] + o->offy);
            }
            fill_003EFBB0((Color_003EFBB0){ o->col0, o->col1, o->col2, o->col3 },
                          rect[0], rect[1], rect[2], rect[3]);
        }
    }
    if (o->child != 0) {
        o->col0 = c0;
        o->col1 = c1;
        o->col2 = c2;
        o->col3 = c3;
    }
}
/* localdecomp:end func_003EFBB0 */
