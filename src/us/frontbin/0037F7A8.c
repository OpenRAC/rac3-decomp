#include "common.h"

/* NTSC-U counterpart of func_00383A68 (src/frontbin/382380.c): the rates are added unscaled (no 1.2 for 50 Hz) */
/* localdecomp:start func_U_0037F7A8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0037F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_0037F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_0037F7A8 v20; V_0037F7A8 v30; V_0037F7A8 v40; u8 m50[0x40]; } B_0037F7A8;
typedef struct { V_0037F7A8 v0; u8 p10[0x1C0 - 0x10]; V_0037F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_0037F7A8;
extern E_0037F7A8 D_U_00222500_0037F7A8[];
extern void func_U_003BF2A0(void *, void *);
extern void func_U_00388F90(void *, void *, void *, f32);
extern void func_U_003890F8(void *, void *);
extern void func_U_00388E58(void *, void *);
extern f32 func_U_003BE6A8(f32, f32, f32);
typedef int u128_t_0037F7A8 __attribute__((mode(TI)));

/* a vector assignment (the vector type's copy) */
static __inline__ void vcopy_0037F7A8(V_0037F7A8 *dst, V_0037F7A8 *src) { *dst = *src; }

s32 func_U_0037F7A8(void *arg, void *state)
{
    f32 v[4] __attribute__((aligned(16)));
    u128_t_0037F7A8 matrix[4];
    O_0037F7A8 *m = arg;
    B_0037F7A8 *d = state;
    f32 t;

    if (d->f10 == 1.0f && d->f0 == 1.0f) return 1;
    t = func_U_003BE6A8(0.0f, 1.0f, d->f10);
    vec_add_ba(&d->v30, &D_U_00222500_0037F7A8[m->f94].v1C0, &d->v30);
    d->v40.x = d->v30.x + (m->f30 - d->v30.x) * t;
    d->v40.y = d->v30.y + (m->f34 - d->v30.y) * t;
    d->v40.z = d->v30.z + (m->f38 - d->v30.z) * t;
    vcopy_0037F7A8(&D_U_00222500_0037F7A8[m->f94].v0, &d->v40);
    func_U_003BF2A0(v, m);
    t = func_U_003BE6A8(0.0f, 1.0f, d->f0);
    func_U_00388F90(d->m50, &d->v20, v, t);
    func_U_003890F8(d->m50, matrix);
    func_U_00388E58(D_U_00222500_0037F7A8[m->f94].m380, matrix);
    d->f10 += d->f14;
    if (d->f10 > 1.0f) d->f10 = 1.0f;
    d->f0 += d->f4;
    if (d->f0 > 1.0f) d->f0 = 1.0f;
    return 0;
}
/* localdecomp:end func_U_0037F7A8 */
