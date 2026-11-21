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

/* declared by functions of L39_00632888.c, which this file was cut from */
extern void func_0038D328(Vec4 *, Vec4 *);
extern void func_0038D028(Vec4 *out, void *a, void *b);

/* declared by functions of L39_00632C48.c, which this file was cut from */
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D160(f32 x, f32 y);

/* localdecomp:start func_L39_00633748 */
#include "vu0.h"
typedef struct V_00633748 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00633748;

extern void func_0013D528(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_00633748(u8 *o) {
    V_00633748 v;
    f32 f;

    if (*(s16 *)(o + 0x2DE) == 0) {
        return;
    }
    if (!(*(f32 *)(o + 0x2AC) < 0.15f)) {
        return;
    }
    if (!(0.0f < *(f32 *)(o + 0x148))) {
        return;
    }
    if (o[0x216] == 0) {
        return;
    }
    if (!(0.0f < *(f32 *)(o + 0x1C8))) {
        return;
    }
    f = func_0038D160(*(f32 *)(o + 0x1C8), func_0038CED8(o + 0x1C0));
    if (0.87266463f <= f) {
        *(u128_t *)&v = *(u128_t *)(o + 0x1C0);
        v.z = 0.0f;
        func_0013D528(&v, &v);
        f = -*(f32 *)(o + 0x120) * v.x - *(f32 *)(o + 0x124) * v.y;
        if (0.0f < f) {
            func_0038CE20(&v, &v, f);
            vec_add_ab(o + 0x120, o + 0x120, &v);
            *(f32 *)(o + 0x128) = *(f32 *)(o + 0x128) - 0.0432f;
        }
    }
}
/* localdecomp:end func_L39_00633748 */
