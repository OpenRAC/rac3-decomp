/* PAL port (round 8) of the NTSC-U draft of func_L23_00332138: with -mvu0-use-vf0-vf2 and a divs_nops.txt row (func_L23_00332920 1 1 1) it is 15 words off: retail cross-jumps state 0's set_state(a,1,-1) into the call of state 1's set_state(a,2,-1) block (b into the jal), ours keeps two calls. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L23_00332920 */
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

__asm__(".extern D_L23_001DCC74, 4");
__asm__(".extern D_L23_001DCC78, 4");
extern f32 D_L23_001DCC74;
extern f32 D_L23_001DCC78;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001A30B0[];
extern s32 func_L01_00456250(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L23_00332920(O_00332138 *a) {
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
        s->w98 = func_L01_00456250(a);
    }
    switch (a->b20) {
    case 0:
        s->w9C = -1;
        s->v70 = a->v10;
        s->v80.q = a->v10;
        r = func_003C3D30(pos, 0, 0, 0.5f);
        s->v80.f[2] = r + D_L23_001DCC74 * a->f2C / a->w24->f24;
        if (D_001D545C == 0x17) {
            s->v80.f[2] = s->v80.f[2] + D_L23_001DCC78;
        }
        s->w98 = s->w90;
        s->w94 = (s32)((f32)s->w94 * 50.0f);
        if (s->w98 != 0) {
            a->v10 = s->v70;
            s->wA0 = s->w94;
        } else {
            a->v10 = s->v80.q;
            s->wA0 = 0;
        }
        func_L01_004450F0(a, 1, -1);
        break;
    case 1:
        if (s->w98 != 0) {
            if (s->wA0 < s->w94) {
                func_L01_004450F0(a, 2, -1);
            }
        } else if (s->wA0 > 0) {
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 2: {
        s32 id = s->w9C;
        u8 *e;
        if (id == -1 || *(s32 *)((e = (u8 *)((id << 7) + (s32)D_001A30B0)) + 0xDC) != (s32)a || *(u8 *)(e + 0xD0) == 0) {
            s->w9C = func_003A52A0(0, 4, a);
        }
        s->wA0 = s->wA0 + 1;
        k = (f32)s->wA0 / (f32)s->w94;
        vec_sub_ab(delta, &s->v70, &s->v80);
        func_0038CE20(delta, delta, k);
        vec_add_ba(&a->v10, delta, &s->v80);
        if (s->w98 == 0) {
            func_L01_004450F0(a, 3, -1);
        } else if (s->wA0 >= s->w94) {
            s32 id2;
            u8 *e2;
            s->wA0 = s->w94;
            id2 = s->w9C;
            if (id2 != -1) {
                e2 = (u8 *)((id2 << 7) + (s32)D_001A30B0);
                if (*(s32 *)(e2 + 0xDC) == (s32)a && *(u8 *)(e2 + 0xD0) != 0) {
                    func_003A4F28(id2);
                }
            }
            s->w9C = -1;
            func_003A52A0(1, 0, a);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    }
    case 3: {
        s32 id = s->w9C;
        u8 *e;
        if (id == -1 || *(s32 *)((e = (u8 *)((id << 7) + (s32)D_001A30B0)) + 0xDC) != (s32)a || *(u8 *)(e + 0xD0) == 0) {
            s->w9C = func_003A52A0(0, 4, a);
        }
        func_0038CAD0(&s->wA0);
        k = (f32)s->wA0 / (f32)s->w94;
        vec_sub_ab(delta, &s->v70, &s->v80);
        func_0038CE20(delta, delta, k);
        vec_add_ba(&a->v10, delta, &s->v80);
        if (s->w98 != 0) {
            func_L01_004450F0(a, 2, -1);
        } else if (s->wA0 <= 0) {
            s32 id2;
            u8 *e2;
            s->wA0 = 0;
            id2 = s->w9C;
            if (id2 != -1) {
                e2 = (u8 *)((id2 << 7) + (s32)D_001A30B0);
                if (*(s32 *)(e2 + 0xDC) == (s32)a && *(u8 *)(e2 + 0xD0) != 0) {
                    func_003A4F28(id2);
                }
            }
            s->w9C = -1;
            func_003A52A0(1, 0, a);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    }
    }
    vec_sub_ba(delta, &a->v10, old);
    func_003C4DA8(s->b30, delta, a->bF0, a->bF0);
}
/* localdecomp:end func_L23_00332920 */
