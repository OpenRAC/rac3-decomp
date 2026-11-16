/* NTSC-U draft (Claude wave C4): C of func_L23_00332138, the NTSC-U twin of func_L23_00332920, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L23_00332138", whose code is not the PAL one).
 * Worker's note: flags: needs -mvu0-use-vf0-vf2 (vu0.h vec_sub_ab/vec_sub_ba/vec_add_ba; the PAL line has no vu0 flag). With it 12 aligned words differ (not byte-exact): retail's cross-jump merges state 0's set_state(a,1,-1) into state 1's set_state(a,2,-1) copy (both tails ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L23_00332138 */
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} W_00332138;
typedef struct {
    u8 pad0[0x30];
    u8 b30[0x40];
    vu0_q v70;
    union {
        vu0_q q;
        f32 f[4];
    } v80;
    s32 w90;
    s32 w94;
    s32 w98;
    s32 w9C;
    s32 wA0;
} S_00332138;
typedef struct {
    u8 pad0[0x10];
    vu0_q v10;
    u8 b20;
    u8 b21;
    u8 pad22[2];
    W_00332138 *w24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    S_00332138 *p68;
    u8 pad6C[0x84];
    u8 bF0[1];
} O_00332138;

__asm__(".extern D_L23_001DCCB4, 4");
__asm__(".extern D_L23_001DCCB8, 4");
extern f32 D_L23_001DCCB4;
extern f32 D_L23_001DCCB8;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001A30B0[];
extern s32 func_L01_00452F60(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_00388398(void *);
extern void func_003BF838(void *, void *, void *, void *);

void func_L23_00332138(O_00332138 *a) {
    S_00332138 *s;
    vu0_q old[1];
    vu0_q delta[1];
    vu0_q *pos;
    f32 r;
    f32 k;

    pos = &a->v10;
    s = a->p68;
    old[0] = *pos;
    if (a->b21 != 0xFF) {
        s->w98 = func_L01_00452F60(a);
    }
    switch (a->b20) {
    case 0:
        s->w9C = -1;
        s->v70 = a->v10;
        s->v80.q = a->v10;
        r = func_003BE7F0(pos, 0, 0, 0.5f);
        s->v80.f[2] = r + D_L23_001DCCB4 * a->f2C / a->w24->f24;
        if (D_001D545C == 0x17) {
            s->v80.f[2] = s->v80.f[2] + D_L23_001DCCB8;
        }
        s->w98 = s->w90;
        s->w94 = (s32)((f32)s->w94 * 60.0f);
        if (s->w98 != 0) {
            a->v10 = s->v70;
            s->wA0 = s->w94;
        } else {
            a->v10 = s->v80.q;
            s->wA0 = 0;
        }
        func_L01_00441FB8(a, 1, -1);
        break;
    case 1:
        if (s->w98 != 0) {
            if (s->wA0 < s->w94) {
                func_L01_00441FB8(a, 2, -1);
            }
        } else if (s->wA0 > 0) {
            func_L01_00441FB8(a, 3, -1);
        }
        break;
    case 2: {
        s32 id = s->w9C;
        u8 *e;
        if (id == -1 || *(s32 *)((e = (u8 *)((id << 7) + (s32)D_001A30B0)) + 0xDC) != (s32)a || *(u8 *)(e + 0xD0) == 0) {
            s->w9C = func_0039FE80(0, 4, a);
        }
        s->wA0 = s->wA0 + 1;
        k = (f32)s->wA0 / (f32)s->w94;
        vec_sub_ab(delta, &s->v70, &s->v80);
        func_003886E8(delta, delta, k);
        vec_add_ba(&a->v10, delta, &s->v80);
        if (s->w98 == 0) {
            func_L01_00441FB8(a, 3, -1);
        } else if (s->wA0 >= s->w94) {
            s32 id2;
            u8 *e2;
            s->wA0 = s->w94;
            id2 = s->w9C;
            if (id2 != -1) {
                e2 = (u8 *)((id2 << 7) + (s32)D_001A30B0);
                if (*(s32 *)(e2 + 0xDC) == (s32)a && *(u8 *)(e2 + 0xD0) != 0) {
                    func_0039FB08(id2);
                }
            }
            s->w9C = -1;
            func_0039FE80(1, 0, a);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    }
    case 3: {
        s32 id = s->w9C;
        u8 *e;
        if (id == -1 || *(s32 *)((e = (u8 *)((id << 7) + (s32)D_001A30B0)) + 0xDC) != (s32)a || *(u8 *)(e + 0xD0) == 0) {
            s->w9C = func_0039FE80(0, 4, a);
        }
        func_00388398(&s->wA0);
        k = (f32)s->wA0 / (f32)s->w94;
        vec_sub_ab(delta, &s->v70, &s->v80);
        func_003886E8(delta, delta, k);
        vec_add_ba(&a->v10, delta, &s->v80);
        if (s->w98 != 0) {
            func_L01_00441FB8(a, 2, -1);
        } else if (s->wA0 <= 0) {
            s32 id2;
            u8 *e2;
            s->wA0 = 0;
            id2 = s->w9C;
            if (id2 != -1) {
                e2 = (u8 *)((id2 << 7) + (s32)D_001A30B0);
                if (*(s32 *)(e2 + 0xDC) == (s32)a && *(u8 *)(e2 + 0xD0) != 0) {
                    func_0039FB08(id2);
                }
            }
            s->w9C = -1;
            func_0039FE80(1, 0, a);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    }
    }
    vec_sub_ba(delta, &a->v10, old);
    func_003BF838(s->b30, delta, a->bF0, a->bF0);
}
/* localdecomp:end func_L23_00332138 */
