#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

/* localdecomp:start func_L31_00349380 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_00349380;
typedef struct {
    u8 pad0[0xB0];
    f32 fB0;
    f32 fB4;
} S_00349380;
typedef struct {
    u8 pad0[0x10];
    V_00349380 pos;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_00349380 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_00349380;

extern f32 D_L31_001DD090;
extern f32 D_L31_001DD094;
extern M_00349380 *D_L31_001E9198 __attribute__((section(".data")));
extern u8 D_001A4C60[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

f32 func_L31_00349380(M_00349380 *a) {
    V_00349380 p;
    V_00349380 q;
    S_00349380 *s;
    M_00349380 *m;
    f32 d;
    f32 e;
    f32 r;

    p = a->pos;
    s = a->p68;
    p.z += s->fB4;
    q = p;
    if (a->b20 == 6) {
        q.x = s->fB0;
    } else if (a->b20 == 8) {
        q.x = *(f32 *)D_001A4C60;
    }
    if (!(func_0038CF00(&p, &q) < D_L31_001DD090)) {
        if (p.x < q.x) {
            p.x += D_L31_001DD090;
        } else {
            d = -D_L31_001DD090;
            p.x += d;
        }
        if (func_003D3CB0(&p, &q, 1, a, 0) != 0 && (m = D_L31_001E9198) != 0 && m->hAA == 0x1644) {
            d = D_L31_001DD090 + D_L31_001DD094;
            if (a->pos.x < m->pos.x) {
                e = -d;
                r = m->pos.x + e;
            } else {
                r = m->pos.x + d;
            }
            return r;
        }
    }
    return q.x;
}
/* localdecomp:end func_L31_00349380 */
