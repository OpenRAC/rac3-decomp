#include "common.h"

/* localdecomp:start func_L32_00347FE8 */
#include "vu0.h"

typedef int u128_t_00347FE8 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00347FE8;
typedef struct {
    V_00347FE8 v;
    u8 *o;
    s32 flags;
    u8 pad[0x14];
} S_00347FE8;

typedef struct {
    u8 pad0[0x84];
    f32 f84;
    u8 pad88[0x25C0 - 0x88];
    u8 *p25C0;
} G_00347FE8;
extern G_00347FE8 D_001A4BE0;
extern u8 D_001A4C60[];
extern f32 func_L30_0034CE78(u8 *obj);
extern void func_L30_0034CC28(S_00347FE8 *s, u8 *o, f32 f, void *pos, s32 a3, s32 a4);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_L30_004E5370(void);
extern void func_L01_00446978(void *, void *);

void func_L32_00347FE8(u8 *a0, void *a1, f32 f12, f32 f13, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2) {
    S_00347FE8 s;
    V_00347FE8 a;
    V_00347FE8 b;
    V_00347FE8 d;
    V_00347FE8 p;
    V_00347FE8 q;
    V_00347FE8 e;
    V_00347FE8 cam;
    V_00347FE8 r;
    f32 h;
    f32 range;

    cam = *(V_00347FE8 *)D_001A4C60;
    h = func_L30_0034CE78(*(u8 **)(D_001A4C60 + 0x2540));
    cam.z += h;
    func_L30_0034CC28(&s, a0, f12, a1, 1, 0);
    if (t2 != 0) {
        s.flags |= 0x30000;
    }
    if (t0 != 0) {
        a = *(V_00347FE8 *)t0;
    } else {
        func_003C2F58(a0, a2, &a);
    }
    if (t1 != 0) {
        b = *(V_00347FE8 *)t1;
    } else {
        func_003C2F58(a0, a3, &b);
    }
    range = f13 + h;
    b.y = a.y = D_001A4BE0.f84;
    vec_sub_ab(&d, &b, &a);
    vec_sub_ab(&e, &cam, &a);
    func_0038CE20(&p.x, &d, func_0038CE68(&d, &e) / func_0038CE68(&d, &d));
    vec_sub_ab(&q, &e, &p);
    if (func_0038CF00(&a, &cam) < range || func_0038CF00(&b, &cam) < range
        || (func_0038CEA8(&q) < range && 0.0f < func_0038CE68(&p, &d)
            && func_0038CEA8(&p) < func_0038CEA8(&d) + h)) {
        vec_sub_ab(&r, a0 + 0x10, D_001A4BE0.p25C0 + 0x10);
        if (func_L30_004E5370() == 0 || t2 != 0) {
            func_L01_00446978(D_001A4BE0.p25C0, &s);
        }
    }
}
/* localdecomp:end func_L32_00347FE8 */
