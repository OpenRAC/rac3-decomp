#include "common.h"

/* NTSC-U counterpart of func_L09_003EE908. */

/* localdecomp:start func_L09_003ECB60 */
#include "vu0.h"

typedef int u128_003ECB60 __attribute__((mode(TI)));
typedef struct {
    s32 i0;
    s32 i4;
    f32 f8;
    f32 fC;
    s32 i10;
} S_003ECB60;

extern s32 D_001D545C;
extern u8 D_001426E0[];
extern void func_00388BD0(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_00388398(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_003894E8(void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L03_00454FD8(u128_003ECB60 *, u128_003ECB60 *, f32, s32, s32, s32);

void func_L09_003ECB60(u8 *self) {
    S_003ECB60 *v = *(S_003ECB60 **)(self + 0x68);

    if (D_001D545C == 10 && (D_001426E0[2] == 0 || D_001426E0[0x7A] != 0)) {
        return;
    }
    switch (self[0x20]) {
    case 0:
        func_00388BD0(self + 0xC0, self + 0xF0);
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1: {
        vu0_v4 pos;
        vu0_v4 a;
        vu0_v4 b;
        u128_003ECB60 *p;
        if (func_L01_00452EC8(self)) {
            func_0039FE80(0, 0, self);
        }
        if (func_00388398(&v->i10)) {
            v->i10 = func_0037E208(v->i4 >> 1, v->i4 << 1);
            if (v->i10 < 60) {
                v->i10 = 60;
            }
            func_L01_00441FB8(self, 2, -1);
        }
        p = (u128_003ECB60 *)(self + 0x10);
        *(u128_003ECB60 *)&pos = *p;
        pos.w = 0.3f;
        if (func_003894E8(&pos, 5.0f)) {
            f32 size;
            s32 life;
            func_00388830(&a, self + 0xC0, -(v->f8 * 0.016666668f));
            func_L01_00440A88(&b, 0.0f, v->f8 * 0.2f * 0.016666668f);
            vec_add_ab(&a, &b, &a);
            size = v->fC * func_0037E250(0.6f, 1.3f);
            life = func_0037E208(40, 80);
            func_L03_00454FD8(p, (u128_003ECB60 *)&a, size, life, func_0037E208(-4, 4), 0x30FFFFFF);
        }
        break;
    }
    case 2:
        if (func_00388398(&v->i10)) {
            v->i10 = func_0037E208(v->i0 >> 1, v->i0 << 1);
            if (v->i10 < 60) {
                v->i10 = 60;
            }
            func_L01_00441FB8(self, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L09_003ECB60 */
