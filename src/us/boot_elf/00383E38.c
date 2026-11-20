#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_00383E48 (src/boot_elf/text/383E48.c): the two blends advance by f14 / f4, not f14 * 1.2f / f4 * 1.2f */
/* localdecomp:start func_U_00383E38 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00383E38;
typedef union { u128_t q; struct { f32 x, y, z, w; } v; } U_00383E38;
typedef struct {
    f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8];
    V_00383E38 v20; V_00383E38 v30; U_00383E38 u40; u8 m50[0x40];
} B_00383E38;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_00383E38;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_00383E38 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_00383E38;
extern E_00383E38 D_U_00222500[];
extern f32 func_U_003C3E68(f32, f32, f32);
extern void func_U_003C4A60(void *, void *);
extern void func_U_0038D8B8(void *, void *);
extern void func_U_0038D9F0(void *, void *, void *, f32);
extern void func_U_0038DB58(void *, void *);

/* the engine's quadword copy (rac2-decomp's qcopy) */
static __inline__ void qcopy_00383E38(void *d, void *s) {
    *(u128_t *)d = *(u128_t *)s;
}

s32 func_U_00383E38(void *arg, void *state) {
    O_00383E38 *o = arg;
    B_00383E38 *s = state;
    V_00383E38 v;
    u128_t matrix[4];
    f32 t;

    if (s->f10 == 1.0f && s->f0 == 1.0f) {
        return 1;
    }
    t = func_U_003C3E68(0.0f, 1.0f, s->f10);
    vec_add_ba(&s->v30, &D_U_00222500[o->f94].v1C0, &s->v30);
    s->u40.v.x = s->v30.x + (o->f30 - s->v30.x) * t;
    s->u40.v.y = s->v30.y + (o->f34 - s->v30.y) * t;
    s->u40.v.z = s->v30.z + (o->f38 - s->v30.z) * t;
    qcopy_00383E38(&D_U_00222500[o->f94].q0, &s->u40);
    func_U_003C4A60(&v, o);
    t = func_U_003C3E68(0.0f, 1.0f, s->f0);
    func_U_0038D9F0(s->m50, &s->v20, &v, t);
    func_U_0038DB58(s->m50, matrix);
    func_U_0038D8B8(D_U_00222500[o->f94].m380, matrix);
    s->f10 += s->f14;
    if (s->f10 > 1.0f) {
        s->f10 = 1.0f;
    }
    s->f0 += s->f4;
    if (s->f0 > 1.0f) {
        s->f0 = 1.0f;
    }
    return 0;
}
/* localdecomp:end func_U_00383E38 */
