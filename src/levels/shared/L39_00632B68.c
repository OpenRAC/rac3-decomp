#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

typedef struct { u8 pad0[0xFB0]; f32 f0FB0; u8 pad1[0x2468 - 0xFB4]; f32 f2468; } S_00633160;

typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;

/* localdecomp:start func_L39_00632B68 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x230];
    Vec4 v230;
    Vec4 v240;
    Vec4 v250;
    u8 pad260[0x1A06 - 0x260];
    u8 mode;
} S_00632B68;

extern void func_0038CF68(void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_00632B68(S_00632B68 *o, Vec4 *out, Vec4 *in)
{
    Vec4 v;
    Vec4 *p;

    switch (o->mode) {
    case 0:
        *out = *in;
        out->f[2] = 0;
        break;
    case 1:
        ((void (*)(void *, void *, f32))func_0038CF68)(&v, &o->v230, 1.0f);
        func_0038CE20(&v, &v, func_0038CE68(&v, in));
        vec_sub_ab(out, in, &v);
        break;
    case 2:
        p = &o->v250;
        func_0038CE20(&v, p, func_0038CE68(p, in));
        vec_sub_ab(out, in, &v);
        break;
    }
}
/* localdecomp:end func_L39_00632B68 */
