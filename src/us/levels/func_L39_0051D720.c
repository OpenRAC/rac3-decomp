#include "common.h"

/* NTSC-U counterpart of func_L39_0051DB38 (src/levels/shared/L39_0051CEF8.c) */
/* localdecomp:start func_L39_0051D720 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051DB38;
typedef struct {
    u8 pad0[0x74];
    s16 s74;
    s16 s76;
    u8 pad78[4];
    s32 f7C;
    s32 f80;
    u8 pad84[4];
    f32 f88;
    u8 pad8C[4];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
} P_0051DB38;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
} Q_0051DB38;
typedef struct {
    u8 pad0[0x10];
    V4_0051DB38 v10;
    u8 b20;
    u8 pad21[3];
    Q_0051DB38 *p24;
    u8 pad28[8];
    u8 b30;
    u8 b31;
    s16 s32;
    u8 pad34[0x34];
    P_0051DB38 *p68;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x54];
    V4_0051DB38 vF0;
} O_0051DB38;
typedef struct {
    u8 pad0[0x40];
    V4_0051DB38 v40;
    u8 pad50[0x50];
    V4_0051DB38 vA0;
    u8 padB0[0x228];
    s16 s2D8;
    u8 pad2DA[0x226A];
    s32 f2544;
} A_0051DB38;
extern O_0051DB38 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(V4_0051DB38 *, V4_0051DB38 *, s32, s32, s32);
extern s16 func_L39_005B24C8(s32, s32);
extern void func_L39_0051DE88(O_0051DB38 *);
extern void func_003C26C8(O_0051DB38 *);
extern V4_0051DB38 D_L39_0025F860[];
extern s32 D_001A5F78[];

O_0051DB38 *func_L39_0051D720(O_0051DB38 *a0, A_0051DB38 *a1, s32 a2) {
    O_0051DB38 *o = func_003BCFB0(0x1080, 0xA0);
    P_0051DB38 *p;
    V4_0051DB38 tmp;
    f32 t;

    if (o != 0) {
        o->b30 = 0x7F;
        o->s32 = 0x7F;
        o->b31 = 1;
        p = o->p68;
        o->v10 = a0->v10;
        o->vF0 = a0->vF0;
        o->vF0.x = 0.0f;
        o->vF0.y = 0.0f;
        if (a1->s2D8 != 0) {
            func_00388830(&o->v10, &a1->v40, 1.5f);
            vec_add_ab(&o->v10, &o->v10, &a1->vA0);
        }
        tmp = o->v10;
        tmp.z += 1.0f;
        if (func_003CE740(&tmp, &o->v10, 2, 0, 0)) {
            func_00388830(&tmp, &D_L39_0025F860[2], 0.005f);
            vec_add_ab(&o->v10, &D_L39_0025F860[0], &tmp);
        }
        o->b20 = 0;
        p->s76 = 0;
        p->s74 = func_L39_005B24C8(120, 300);
        p->f90 = 600;
        p->f94 = 30;
        p->f7C = 0;
        p->f98 = 0;
        p->f9C = a1->f2544;
        o->b20 = 3;
        func_L39_0051DE88(o);
        o->f98 = o->p24->f10;
        p->f88 = 1.0f;
        t = (f32)(a2 - D_001A5F78[0]) / 1000.0f;
        if (t < 0.0f) {
            t = 0.017f;
        }
        p->f80 = t * 60.0f;
        func_003C26C8(o);
    }
    return o;
}
/* localdecomp:end func_L39_0051D720 */
