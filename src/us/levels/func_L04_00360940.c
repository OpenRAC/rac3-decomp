/* NEAR (5 diff words of 162, same length): needs flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' and divs row 'func_L04_00360940 2'. Everything is byte-exact except the order inside the v70/v80 copy block after func_0039FE80: retail = lq v1,0x60 / addiu a1 / lq v0,0x30 / addiu a2 / li.s f12 / move s7,a1 / move s6,a2 / sq v1,0x70 / sq v0,0x80; mine = lq v0,0x60 / addiu a1 / lq v1,0x30 / addiu a2 / li.s / move s7 / sq v0,0x70 / move s6 / sq v1,0x80 (row3 and row0 temporaries swapped, one sq between the two moves) */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_360940;
typedef struct { V4_360940 r[4]; } M4_360940;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xF8 - 0x18]; f32 fF8; } O_360940;
typedef struct {
    u8 p0[0x44];
    u8 b44;
    u8 p45[0x5F - 0x45];
    u8 b5F;
    u8 p60[0x220 - 0x60];
    V4_360940 v220;
    u8 p230[0x2FC - 0x230];
    void *p2FC;
    u8 p300[0x4E4 - 0x300];
    s32 w4E4;
} C_360940;

extern s32 func_003BD9A0(void *, s32, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_003A7568(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern s32 func_003BDA38(void *, s32, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_003AD288(void *, void *, void *, s32, f32);

static __inline__ void qcopy_360940(void *dst, void *src) {
    *(u128_t *)dst = *(u128_t *)src;
}

/* localdecomp:start func_L04_00360940 */
extern f32 D_001DD724_sda;
__asm__(".extern D_001DD724_sda, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

void func_L04_00360940(O_360940 *o, C_360940 *c, s32 n, s32 d) {
    V4_360940 a;
    V4_360940 b;
    V4_360940 c2;
    M4_360940 m;
    V4_360940 v70;
    V4_360940 v80;
    f32 diff;

    func_003BD9A0(c->p2FC, 0, &m);
    func_0039FE80(0, 0, o);
    qcopy_360940(&v70, &m.r[3]);
    qcopy_360940(&v80, &m.r[0]);
    func_L01_003A7568(o, &v70, &v80, 0.65f);
    vec_sub_ba(&a, &c->v220, &m.r[3]);
    func_00388830(&a, &a, D_001DD724_sda * 0.016666668f);
    if (c->w4E4 == 0) {
        diff = func_00389468(o->fF8, func_00388A28(c->v220.x - o->f10, c->v220.y - o->f14));
        if (1.0471976f < diff) {
            func_00388830(&a, &m, D_001DD724_sda * 0.016666668f);
        }
    }
    func_00388830(&b, &m, D_001DD724_sda * 0.016666668f);
    func_003886C0(&c2, &a, &b, (f32)n / (f32)d);
    if (D_001D545C == 13) {
        if (c2.z < -0.17453292f) {
            c2.z = -0.17453292f;
        }
    }
    func_003BDA38(c->p2FC, 0, &v80);
    func_003BDA38(o, 0, &v70);
    if (func_003CE740(&v70, &v80, 0x10, o, 0) == 0) {
        if (c->b5F != 0) {
            func_L01_003AD288(o, &c2, &m.r[3], 0x10001, (f32)c->b44);
        } else {
            func_L01_003AD288(o, &c2, &m.r[3], 1, (f32)c->b44);
        }
    }
}
/* localdecomp:end func_L04_00360940 */
