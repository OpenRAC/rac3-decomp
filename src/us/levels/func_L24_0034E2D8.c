#include "common.h"

/* NTSC-U counterpart of func_L24_0034F1B8 (src/levels/24_insomniac_museum/L24_0034F040.c) */
#include "vu0.h"
#include "vu0.h"
extern vu0_q D_L24_001E21A0_0034E2D8;

/* localdecomp:start func_L24_0034E2D8 */
#include "vu0.h"
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_004424B0(void *, void *, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0040C1F8(void *, void *, f32);
extern s32 func_L24_0034DE58(u8 *);
extern void func_L24_0034D870(void *, s32);
extern u8 *D_001D52FC;
extern vu0_q D_L24_001E21A0_0034E2D8;
__asm__(".extern D_L24_001DD430, 4");
__asm__(".extern D_L24_001DD434, 4");
__asm__(".extern D_L24_001DD438_0034E2D8, 4");
__asm__(".extern D_L24_001DD43C_0034E2D8, 4");
__asm__(".extern D_L24_001DD440_0034E2D8, 4");
__asm__(".extern D_L24_001DD444_0034E2D8, 4");
__asm__(".extern D_L24_001DD448_0034E2D8, 4");
__asm__(".extern D_L24_001DD44C, 4");
__asm__(".extern D_L24_001DD450_0034E2D8, 4");
__asm__(".extern D_L24_001DD454_0034E2D8, 4");
__asm__(".extern D_L24_001DD458_0034E2D8, 4");
__asm__(".extern D_L24_001DD45C_0034E2D8, 4");
__asm__(".extern D_L24_001DD4FC_0034E2D8, 4");
__asm__(".extern D_L24_001DD500_0034E2D8, 4");
extern f32 D_L24_001DD430;
extern f32 D_L24_001DD434;
extern f32 D_L24_001DD438_0034E2D8;
extern f32 D_L24_001DD43C_0034E2D8;
extern f32 D_L24_001DD440_0034E2D8;
extern f32 D_L24_001DD444_0034E2D8;
extern f32 D_L24_001DD448_0034E2D8;
extern f32 D_L24_001DD44C;
extern f32 D_L24_001DD450_0034E2D8;
extern f32 D_L24_001DD454_0034E2D8;
extern f32 D_L24_001DD458_0034E2D8;
extern f32 D_L24_001DD45C_0034E2D8;
extern f32 D_L24_001DD4FC_0034E2D8;
extern f32 D_L24_001DD500_0034E2D8;

typedef struct {
    u8 p0[0x100];
    f32 x100;
    f32 x104;
    f32 x108;
    f32 x10C;
    u8 p110[0x118 - 0x110];
    f32 x118;
    u8 p11C[0x140 - 0x11C];
    f32 x140;
    f32 x144;
    f32 x148;
    f32 x14C;
    u8 p150[0x1A0 - 0x150];
    u8 *x1A0;
} S_0034F1B8;

typedef struct {
    u8 p0[0x100];
    f32 x100;
    f32 x104;
    f32 x108;
    f32 x10C;
} H_0034F1B8;

static __inline__ void vadd2_34F1B8(void *d1, void *d2, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d1) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d2) : "j"(qr));
}

s32 func_L24_0034E2D8(void *o) {
    u8 *obj = (u8 *)o;
    S_0034F1B8 *s = *(S_0034F1B8 **)(obj + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 t[4] __attribute__((aligned(16)));
    f32 z;
    f32 yaw;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 turn;
    u8 *m;
    H_0034F1B8 *h;
    s32 r;

    s->x118 = s->x118 * D_L24_001DD450_0034E2D8;
    s->x144 = s->x144 * D_L24_001DD454_0034E2D8;
    z = s->x108 * D_L24_001DD45C_0034E2D8;
    c = 0.0f;
    func_003886E8(&s->x100, &s->x100, D_L24_001DD458_0034E2D8);
    s->x108 = z;
    a = 0.0f;
    b = 0.0f;
    d = 0.0f;
    m = s->x1A0;
    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
        s->x1A0 = 0;
        h = (H_0034F1B8 *)D_001D52FC;
        d = -h->x10C;
        c = -h->x108;
        b = -(h->x104 - 0.25f);
        a = h->x100;
        c *= D_L24_001DD434 * 0.00027777778f;
        d *= D_L24_001DD438_0034E2D8 * 0.00027777778f;
        a *= D_L24_001DD448_0034E2D8 * 0.017453292f * 0.00027777778f;
    }
    yaw = func_00388A28(s->x100, s->x104);
    s->x144 = func_00389380(s->x144, a);
    turn = 0.0f;
    if (b < 0.0f) {
        turn = D_L24_001DD4FC_0034E2D8 * 0.017453292f * b;
    } else if (0.0f < b) {
        turn = D_L24_001DD500_0034E2D8 * 0.017453292f * b;
    }
    func_L01_00445758(&s->x148, &s->x14C, 0, turn, D_L24_001DD43C_0034E2D8 * 0.017453292f * 0.00027777778f, D_L24_001DD43C_0034E2D8 * 0.017453292f * 0.00027777778f, D_L24_001DD444_0034E2D8 * 0.017453292f * 0.016666668f);
    {
        f32 lim = D_L24_001DD44C * 0.017453292f * 0.016666668f;
        if (lim < s->x144) {
            s->x144 = lim;
        } else if (s->x144 < -lim) {
            s->x144 = -lim;
        }
    }
    func_L01_004424B0(obj, &s->x118, yaw, D_L24_001DD43C_0034E2D8 * 0.017453292f * 0.00027777778f, D_L24_001DD440_0034E2D8, D_L24_001DD444_0034E2D8 * 0.017453292f * 0.016666668f);
    s->x140 = func_00389380(s->x140, s->x144);
    s->x140 = func_003893C8(s->x140, s->x118);
    v[0] = d;
    v[1] = c;
    v[2] = 0.0f;
    func_003888C8(v, v, &D_L24_001E21A0_0034E2D8);
    v[2] = 0.0f;
    vadd2_34F1B8(&s->x100, t, &s->x100, v);
    func_L01_0040C1F8(&s->x100, &s->x100, D_L24_001DD430 * 0.016666668f);
    vadd2_34F1B8(obj + 0x10, t, obj + 0x10, &s->x100);
    r = func_L24_0034DE58(obj);
    func_L24_0034D870(obj, 0);
    return r;
}
/* localdecomp:end func_L24_0034E2D8 */
