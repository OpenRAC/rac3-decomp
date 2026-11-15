#include "common.h"

/* declared by functions of L21_003AA740.c, which this file was cut from */
extern void func_L21_003AABA0(void *);

/* localdecomp:start func_L21_003AABA0 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003AABA0;

typedef struct {
    s32 pad0;
    f32 level;
    f32 speed;
    s32 padC;
    s32 tex;
    f32 v0;
    f32 v1;
} P_003AABA0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    P_003AABA0 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
    u8 padAC[0xF4 - 0xAC];
    f32 fF4;
    f32 fF8;
} M_003AABA0;

extern vu0_v4 D_L21_001DE140[] __attribute__((section(".sdata")));
__asm__(".extern D_L21_001DE140, 4");
extern vu0_v4 D_L21_001D9B80 __attribute__((section(".sdata")));
extern vu0_v4 D_L21_001D9BA0 __attribute__((section(".sdata")));
extern long func_00389598(s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);

void func_L21_003AABA0(void *arg)
{
    M_003AABA0 *m = arg;
    P_003AABA0 *p = m->p68;
    Q_003AABA0 q;
    vu0_v4 t;
    vu0_v4 w;
    s32 flags;
    s32 skip;
    s32 i;
    f32 h;

    flags = 0;
    h = (1.0f - p->level) * 1.4f;
    if (0.0f < h - 0.05f) {
        flags = 4;
    }
    if (0.0f < h + 0.05f && h - 0.05f < 1.4f) {
        flags |= 2;
    }
    if (h + 0.05f < 1.4f) {
        flags |= 1;
    }
    for (i = 0; i < 3; i++) {
        switch (1 << i) {
        case 1: {
            s32 j;

            skip = (flags & 1) == 0;
            if (skip) {
                break;
            }
            q.u78 = func_00389598(p->tex);
            q.u80 = 0xFF9000000260L;
            q.u70 = 0;
            q.gif = (0x8000L << 25) | 0x48;
            q.col[3] = 0x82303030;
            q.col[2] = 0x82303030;
            q.col[1] = 0x82303030;
            q.col[0] = 0x82303030;
            q.uv[0][0] = 0.0f;
            q.uv[1][0] = 1.0f;
            q.uv[2][0] = 0.0f;
            q.uv[3][0] = 1.0f;
            for (j = 0; j < 4; j++) {
                if (j < 2) {
                    q.uv[j][1] = p->v0;
                    func_0038D890(&t, &D_L21_001DE140[j], &D_L21_001D9B80, func_0038DAB8(m->fF4, 0.0f));
                } else {
                    w = D_L21_001DE140[j];
                    w.z = h + 0.05f - 0.7f;
                    q.uv[j][1] = (1.0f - (h + 0.05f) / 1.4f) * p->v1;
                    func_0038D890(&t, &w, &D_L21_001D9B80, func_0038DAB8(m->fF4, 0.0f));
                }
                func_0038D890(&t, &t, &D_L21_001D9BA0, func_0038DAB8(m->fF8, 1.5707964f));
                switch (m->hAA) {
                case 0x1BCC:
                    func_0038CE20(&t, &t, 1.0f);
                    break;
                case 0x1BCD:
                    func_0038CE20(&t, &t, 1.4f);
                    break;
                case 0x1BCE:
                    func_0038CE20(&t, &t, 1.7f);
                    break;
                }
                vec_add_ba(&q.v[j], &m->pos, &t);
            }
            func_003D2DA0(&q, 0, 0);
            break;
        }
        case 2: {
            s32 j;
            f32 y;

            if (!(flags & 2)) {
                break;
            }
            q.u78 = func_00389598(p->tex);
            q.u80 = 0xFF9000000260L;
            q.u70 = 0;
            q.gif = (0x8000L << 25) | 0x48;
            q.col[3] = 0x7F1F1F1F;
            q.col[2] = 0x7F1F1F1F;
            q.col[1] = 0x7F1F1F1F;
            q.col[0] = 0x7F1F1F1F;
            q.uv[0][0] = 0.05f;
            q.uv[1][0] = 0.95f;
            q.uv[2][0] = 0.05f;
            q.uv[3][0] = 0.95f;
            for (j = 0; j < 4; j++) {
                if (j < 2) {
                    y = h + 0.05f;
                    w = D_L21_001DE140[j];
                    if (1.4f < y) {
                        w.z = 0.7f;
                    } else {
                        w.z = y - 0.7f;
                    }
                    q.uv[j][1] = (1.0f - y / 1.4f) * (p->v1 + 0.05f);
                    func_0038D890(&t, &w, &D_L21_001D9B80, func_0038DAB8(m->fF4, 0.0f));
                } else {
                    y = h - 0.05f;
                    w = D_L21_001DE140[j];
                    if (y < 0.0f) {
                        w.z = -0.7f;
                    } else {
                        w.z = y - 0.7f;
                    }
                    q.uv[j][1] = (1.0f - y / 1.4f) * (p->v1 - 0.05f);
                    func_0038D890(&t, &w, &D_L21_001D9B80, func_0038DAB8(m->fF4, 0.0f));
                }
                func_0038D890(&t, &t, &D_L21_001D9BA0, func_0038DAB8(m->fF8, 1.5707964f));
                switch (m->hAA) {
                case 0x1BCC:
                    func_0038CE20(&t, &t, 1.0f);
                    break;
                case 0x1BCD:
                    func_0038CE20(&t, &t, 1.4f);
                    break;
                case 0x1BCE:
                    func_0038CE20(&t, &t, 1.7f);
                    break;
                }
                vec_add_ba(&q.v[j], &m->pos, &t);
            }
            func_003D2DA0(&q, 0, 0);
            break;
        }
        case 4: {
            s32 j;

            if (!(flags & 4)) {
                break;
            }
            q.u78 = func_00389598(p->tex);
            q.u80 = 0xFF9000000260L;
            q.u70 = 0;
            q.gif = (0x8000L << 25) | 0x48;
            q.col[3] = 0x82303030;
            q.col[2] = 0x82303030;
            q.col[1] = 0x82303030;
            q.col[0] = 0x82303030;
            q.uv[0][0] = 0.0f;
            q.uv[1][0] = 1.0f;
            q.uv[2][0] = 0.0f;
            q.uv[3][0] = 1.0f;
            for (j = 0; j < 4; j++) {
                if (j < 2) {
                    w = D_L21_001DE140[j];
                    w.z = h - 0.05f - 0.7f;
                    q.uv[j][1] = (1.0f - (h - 0.05f) / 1.4f) * p->v1;
                    func_0038D890(&t, &w, &D_L21_001D9B80, func_0038DAB8(m->fF4, 0.0f));
                } else {
                    q.uv[j][1] = p->v1;
                    func_0038D890(&t, &D_L21_001DE140[j], &D_L21_001D9B80, func_0038DAB8(m->fF4, 0.0f));
                }
                func_0038D890(&t, &t, &D_L21_001D9BA0, func_0038DAB8(m->fF8, 1.5707964f));
                switch (m->hAA) {
                case 0x1BCC:
                    func_0038CE20(&t, &t, 1.0f);
                    break;
                case 0x1BCD:
                    func_0038CE20(&t, &t, 1.4f);
                    break;
                case 0x1BCE:
                    func_0038CE20(&t, &t, 1.7f);
                    break;
                }
                vec_add_ba(&q.v[j], &m->pos, &t);
            }
            func_003D2DA0(&q, 0, 0);
            break;
        }
        }
    }
    p->level += p->speed;
    if (1.0f < p->level) {
        p->level -= 1.0f;
    }
}
/* localdecomp:end func_L21_003AABA0 */
