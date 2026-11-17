/* NTSC-U draft (Claude wave C4): C of func_L07_0034A120, the NTSC-U twin of func_L07_0034AC60, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_0034A120", whose code is not the PAL one).
 * Worker's note: flags: first draft only (108 aligned words differ). Needs -mvu0-use-vf0-vf2 (vec_sub_ba/ab), @ps2as, and NO -fopt-stack: retail saves s0-s7/fp/ra with sq in 16-byte slots, frame 0x110 (the PAL file line has -fopt-stack). The slot order retail has (s0 lowest ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_0034A120 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0034A120;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    u8 pad6[2];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s32 w18;
    s32 w1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
} S_0034A120;
typedef struct {
    u8 pad0[0x10];
    V4_0034A120 v10;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31;
    s16 h32;
    u8 pad34[0x34];
    S_0034A120 *p68;
    u8 pad6C[0x54];
    V4_0034A120 vC0;
    V4_0034A120 vD0;
    V4_0034A120 vE0;
} O_0034A120;

extern s32 D_001D52F0;
extern u8 D_L07_001E1EC0[];
extern O_0034A120 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003BFC18(void *, void *, s32);
extern void func_00388758(void *, void *, void *);
extern s32 func_003894E8(void *, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388990(f32);
extern void func_L07_0034A648(void *, void *);

O_0034A120 *func_L07_0034A120(V4_0034A120 *src, s32 flag, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 size,
                              s32 st0, s32 st1) {
    O_0034A120 *o;
    S_0034A120 *s;
    V4_0034A120 d;
    V4_0034A120 t;
    V4_0034A120 q;
    V4_0034A120 e;
    u8 *tbl;
    f32 f20;
    f32 dist;
    f32 ang;

    o = func_003BCFB0(0xEAE, 0x80);
    if (o != 0) {
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b20 = 0;
        tbl = D_L07_001E1EC0;
        f20 = 1.0f;
        s = o->p68;
        o->v10 = *src;
        o->v10.w = f20;
        vec_sub_ba(&d, (u8 *)(D_001D52F0 * 0x460) + (s32)tbl, &o->v10);
        func_00388830(&d, &d, f20);
        func_003BFC18(&o->v10, &t, 1);
        o->vC0 = d;
        func_00388758(&o->vD0, &o->vC0, &t);
        func_00388830(&o->vD0, &o->vD0, f20);
        func_00388758(&o->vE0, &o->vD0, &o->vC0);
        o->vC0.w = 0.0f;
        o->vE0.w = 0.0f;
        o->vD0.w = 0.0f;
        s->w20 = a2;
        s->w24 = a3;
        s->w28 = a4;
        s->w2C = a5;
        s->w30 = a6;
        s->h2 = 0x3C;
        s->f8 = size + size;
        s->fC = size * 4.0f;
        s->w34 = st0;
        s->w1C = st1;
        s->h0 = 0x3C;
        s->w18 = a7;
        s->f14 = size;
        q = o->v10;
        q.w = size * 3.0f;
        if (func_003894E8(&q, 128.0f) != 1) {
            s->w18 = 0;
            s->h4 = 0;
        } else {
            s->h4 = 10;
            s->f10 = 0.1f;
            if (flag != 0) {
                dist = func_003887C8(src, (u8 *)(D_001D52F0 * 0x460) + (s32)tbl);
                if (dist < 48.0f) {
                    *(s32 *)(tbl + 0x28) = 0x28;
                    *(f32 *)(tbl + 0x20) = 0.075f;
                    *(s32 *)(tbl + 0x2C) = 0;
                }
            }
            if (s->w18 != 0) {
                vec_sub_ab(&e, &o->v10, (u8 *)(D_001D52F0 * 0x460) + (s32)tbl);
                func_00388830(&e, &e, 1.0f);
                ang = func_00388990(func_00388730(&e, (u8 *)(D_001D52F0 * 0x460) + (s32)(tbl + 0x380)));
                if (1.5707964f - ang < 0.4537856f) {
                    s->w18 = 1;
                } else {
                    s->w18 = 0;
                }
            }
        }
        func_L07_0034A648(o, &t);
    }
    return o;
}
/* localdecomp:end func_L07_0034A120 */
