/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00665BC8, the NTSC-U twin of func_L39_006684A0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L39_006683F8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_665BC8;
typedef struct {
    u8 p0[0x1F0];
    V4_665BC8 v1F0;
    V4_665BC8 v200;
    u8 p210[0x10];
    V4_665BC8 v220;
    u8 p230[0x2B0 - 0x230];
    V4_665BC8 v2B0;
    V4_665BC8 v2C0;
    u8 *p2D0;
    u8 p2D4[0x2E0 - 0x2D4];
    s32 w2E0;
    s32 w2E4;
    u8 p2E8[0x2F8 - 0x2E8];
    s32 w2F8;
    u8 p2FC[5];
    u8 b301;
    u8 p302[0x318 - 0x302];
    s32 w318;
} T_665BC8;

extern T_665BC8 *func_L39_00665D00(s32);

static __inline__ void v3_665BC8(V4_665BC8 *d, f32 *s) {
    d->x = s[0];
    d->y = s[1];
    d->z = s[2];
    *(s32 *)&d->w = 0;
}

/* localdecomp:start func_L39_00665BC8 */
void func_L39_00665BC8(u8 *a0) {
    T_665BC8 *t;
    s32 fl;
    s32 w;
    u8 *q;

    t = func_L39_00665D00(*(s32 *)(a0 + 0x1C));
    if (t != 0) {
        if (a0[0x20] & 4) {
            v3_665BC8(&t->v220, (f32 *)(a0 + 0xC));
            t->w2E4 = *(s32 *)(a0 + 0x18);
        } else {
            if (a0[0x20] & 8) {
                t->b301 = 1;
            } else {
                t->b301 = 0;
            }
            v3_665BC8(&t->v1F0, (f32 *)a0);
            v3_665BC8(&t->v200, (f32 *)(a0 + 0xC));
            w = t->w2F8;
            t->w2E0 = *(s32 *)(a0 + 0x18);
            t->w2F8 = w | 1;
            if (a0[0x20] & 1) {
                t->w2F8 = w | 0x11;
            } else if (a0[0x20] & 2) {
                q = t->p2D0;
                t->w318 = 0x1E;
                *(u128_t *)&t->v2B0 = *(u128_t *)(q + 0x10);
                vec_sub_ba(&t->v2C0, &t->v1F0, q + 0x10);
                t->w2F8 = t->w2F8 | 2;
            } else {
                t->w2F8 = w | 1;
            }
        }
    }
}
/* localdecomp:end func_L39_00665BC8 */
