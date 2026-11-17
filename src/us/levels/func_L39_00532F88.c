#include "common.h"

/* NTSC-U counterpart of func_L39_00533600 (src/levels/shared/L39_00533600.c) */
/* localdecomp:start func_L39_00532F88 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00533600;
typedef struct { u8 p0[0x10]; s32 x10; } X_00533600;
typedef struct {
    u8 p0[0x24]; X_00533600 *x24;
    u8 p28[0x98 - 0x28]; s32 x98;
    u8 p9C[0xAA - 0x9C]; s16 hAA;
} O_00533600;
typedef struct { u8 p0[0x2548]; s32 x2548; } P_00533600;
typedef struct {
    u8 p0[0x28]; P_00533600 *p28;
    u8 b2C; u8 b2D; u8 p2E[2];
    V4_00533600 q30;
} V_00533600;
typedef struct { u8 p0[0x10]; V4_00533600 pos; u8 p20[0x68 - 0x20]; V_00533600 *vars; } M_00533600;

extern O_00533600 *D_L39_0025F858 __attribute__((section(".data")));
extern V4_00533600 D_L39_0025F860;
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L39_005FD6D8(void);

void func_L39_00532F88(M_00533600 *m) {
    V_00533600 *v = m->vars;
    O_00533600 *list[4];
    V4_00533600 t;
    O_00533600 *o;
    f32 len;
    s32 n = 0;
    s32 i;

    if (v->b2D == 0) {
        len = func_00388770(v);
        func_00388830(&t, v, len * 180.0f * 0.125f);
        vec_add_ab(&t, &t, &m->pos);
        func_L39_005FD658(v->p28->x2548);
    again:
        if (func_003CE740(&m->pos, &t, 2, 0, 0)) {
            if (n < 4 && (o = D_L39_0025F858) != 0 && (o->hAA == 0x107C || o->hAA == 0x107E)) {
                list[n++] = o;
                o->x98 = 0;
                goto again;
            }
            {
                f32 d = func_003887C8(&m->pos, &D_L39_0025F860);
                v->q30 = D_L39_0025F860;
                v->b2C = d / len;
            }
        }
        func_L39_005FD6D8();
        v->b2D = 8;
    } else {
        v->b2D--;
    }
    for (i = 0; i < n; i++) {
        list[i]->x98 = list[i]->x24->x10;
    }
}
/* localdecomp:end func_L39_00532F88 */
