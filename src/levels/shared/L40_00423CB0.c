#include "common.h"

/* localdecomp:start func_L40_00423CB0 */
#include "vu0.h"

typedef struct V4_00423CB0 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00423CB0;

typedef struct Info_00423CB0 {
    u8 pad0[0xC];
    u8 fC;
    u8 padD[0x10 - 0xD];
    s32 f10;
    u8 pad14[0x44 - 0x14];
    u16 f44;
} Info_00423CB0;

typedef struct Moby_00423CB0 {
    u8 pad0[0x10];
    V4_00423CB0 pos;
    u8 pad20[0x24 - 0x20];
    Info_00423CB0 *f24;
    u8 pad28[0x30 - 0x28];
    u8 f30;
    u8 pad31;
    u16 f32;
    u16 f34;
    u8 pad36[0x64 - 0x36];
    s32 f64;
    struct S2_00423CB0 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    u8 pad9C[0xE0 - 0x9C];
    V4_00423CB0 fE0;
    f32 fF0;
    f32 fF4;
    f32 fF8;
} Moby_00423CB0;

typedef struct S2_00423CB0 {
    u8 pad0[0x78];
    Moby_00423CB0 *f78;
} S2_00423CB0;

extern s32 func_L40_00422C30(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L40_00422550(void *);
extern u8 *func_L40_003D9CA0(u8 *, s32);
extern s32 func_L40_004224E0(void *);
extern s32 func_L40_00422560(void *);
extern s32 func_L40_00422540(void *);
extern u8 *func_003C24B0(s32, s32);
extern s32 func_L40_00422530(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38(void *);

void func_L40_00423CB0(void *arg) {
    Moby_00423CB0 *obj = arg;
    S2_00423CB0 *s2 = obj->f68;
    s32 snd;
    Moby_00423CB0 *m;
    V4_00423CB0 tmp;

    if (s2->f78 != 0) {
        return;
    }
    snd = func_L40_00422C30(obj);
    tmp = obj->fE0;
    func_0038CF68(&tmp, &tmp, 0.75f);
    if (func_L40_00422550(obj) != 0) {
        Moby_00423CB0 *n = (Moby_00423CB0 *)func_L40_003D9CA0((u8 *)obj, 0);
        vec_add_ba(&n->pos, &n->pos, &tmp);
        s2->f78 = n;
        return;
    }
    if (func_L40_004224E0(obj) == 0 && func_L40_00422560(obj) == 0 && func_L40_00422540(obj) == 0) {
        return;
    }
    m = (Moby_00423CB0 *)func_003C24B0(snd, 0);
    m->f64 = 0;
    m->f34 &= 0xFFFD;
    m->f30 = obj->f30;
    m->f32 = obj->f32;
    m->pos = obj->pos;
    vec_add_ab(&m->pos, &m->pos, &tmp);
    m->fF0 = 0.0f;
    m->fF8 = 0.0f;
    if (func_L40_00422530(obj) != 0 || func_L40_00422540(obj) != 0) {
        m->fF4 = -1.57f;
    }
    if (obj->fF0 != 0.0f) {
        m->fF4 += obj->fF0;
    } else if (obj->fF4 != 0.0f) {
        m->fF4 += obj->fF4;
    }
    m->f34 &= 0xFFBE;
    m->f34 |= m->f24->f44 & 0x1000;
    m->f98 = m->f24->f10;
    if (m->f24->fC >= 2) {
        func_003C3A10(m, 1, 0, 0);
    }
    func_003C7C38(m);
    s2->f78 = m;
}
/* localdecomp:end func_L40_00423CB0 */
