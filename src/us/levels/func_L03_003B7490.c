#include "common.h"

/* NTSC-U counterpart of func_L03_003B9130 (src/levels/shared/L03_003B8F10.c) */
#include "vu0.h"

/* localdecomp:start func_L03_003B7490 */
extern void func_L01_00440A88(f32 *, f32, f32);
extern void func_003886E8(void *, void *, f32);
__asm__(".extern D_L03_001DEACC, 4");
__asm__(".extern D_L03_001DEAD0, 4");
__asm__(".extern D_L03_001DEAD4, 4");
__asm__(".extern D_L03_001DEAD8, 4");
extern f32 D_L03_001DEACC;
extern f32 D_L03_001DEAD0;
extern u8 D_L03_001DEAD4;
extern f32 D_L03_001DEAD8;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    s32 pad0C;
    f32 v10[3];
} Ctl_3B9130;

void func_L03_003B7490(u8 *e, Ctl_3B9130 *s) {
    u8 *m;
    vu0_v4 d;
    s32 i;
    f32 f;
    f32 c;
    s32 w;
    if (s == 0) {
        return;
    }
    m = s->m;
    w = s->w4;
    if (m == 0 || w == 0) {
        return;
    }
    if ((u8)(m[0x20] + 2) < 2) {
        *(s16 *)(e + 0xA) = 0;
        return;
    }
    if (s->hA & 1) {
        e[2] = D_L03_001DEAD4;
        *(vu0_q *)(e + 0x10) = *(vu0_q *)(m + 0x10);
        func_L01_00440A88(&d.x, D_L03_001DEACC * 0.016666668f, D_L03_001DEAD0 * 0.016666668f);
        c = D_L03_001DEAD8 * 210000.0f;
        s->v10[0] = d.x;
        s->v10[1] = d.y;
        s->v10[2] = d.z;
        *(u32 *)(e + 4) = 0x88202080;
        *(f32 *)(e + 0xC) = c;
    }
    *(u32 *)(e + 4) = (*(u32 *)(e + 4) & 0xFFFFFF) | ((s32)((f32)*(s16 *)(e + 0xA) * 128.0f / (f32)s->h8) << 24);
    for (i = 0; i < 3; i++) {
        (&d.x)[i] = s->v10[i];
    }
    f = (f32)(s->h8 - *(s16 *)(e + 0xA));
    if (f < 1.0f) {
        f = 1.0f;
    }
    func_003886E8(&d, &d, f);
    vec_add_ab(e + 0x10, m + 0x10, &d);
}
/* localdecomp:end func_L03_003B7490 */
