#include "common.h"

/* NTSC-U counterpart of func_L21_003B1328 (src/levels/21_obani_draco/L21_003B0F18.c) */
#include "vu0.h"
#include "vu0.h"
extern void func_003BD360(void *);
extern void func_003886E8(void *,void *,float);
extern void func_L01_00443610(void *,void *,int,float);
extern int func_003CE740(void *,void *,int,void *,void *);

/* localdecomp:start func_L21_003AF770 */
extern s32 func_L01_00452EC8(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_003BD360(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003886E8(void *,void *,float);
extern void func_L01_00443610(void *,void *,int,float);
extern int func_003CE740(void *,void *,int,void *,void *);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_L01_004026A0(void *, void *);
void func_L21_003AFAD8(u8 *arg0);
extern f32 D_L21_001DE2A0; __asm__(".extern D_L21_001DE2A0, 4");

typedef struct {
    u8 pad0[0x10];
    vu0_v4 vel;
    u8 *target;
    u8 pad24[4];
    f32 f28;
    f32 f2C;
    s32 timer;
} S_003B1328;

void func_L21_003AF770(u8 *self) {
    S_003B1328 *p;
    vu0_v4 start;
    vu0_v4 low;
    vu0_v4 d;
    u8 buf[0x30];
    f32 f;

    p = *(S_003B1328 **)(self + 0x68);
    if (func_L01_00452EC8(self)) {
        func_0039FE80(0, 4, self);
    }
    p->timer++;
    if (p->timer > 0x12C) {
        func_L01_004A6D70(0, self);
        func_003BD360(self);
        return;
    }
    start = *(vu0_v4 *)(self + 0x10);
    vec_sub_ba(&d, p->target + 0x10, self + 0x10);
    if (func_00388730(self + 0xC0, &d) > 0.0f) {
        f = func_003893C8(func_00388A28(*(f32 *)(p->target + 0x10) - *(f32 *)(self + 0x10),
                                        *(f32 *)(p->target + 0x14) - *(f32 *)(self + 0x14)),
                          *(f32 *)(self + 0xF8));
        if (f > 0.00436332356f) {
            f = 0.00436332356f;
        } else if (f < -0.00436332356f) {
            f = -0.00436332356f;
        }
        *(f32 *)(self + 0xF8) = func_00389380(*(f32 *)(self + 0xF8), f);
    }
    p->vel = *(vu0_v4 *)(self + 0xC0);
    func_003886E8(&p->vel, &p->vel, p->f2C);
    vec_add_ba(self + 0x10, &p->vel, self + 0x10);
    func_L01_00443610(buf, self, 0x10001, p->f28);
    func_003CE740(&start, self + 0x10, 0x10, *(void **)(self + 0xB8), buf);
    low = *(vu0_v4 *)(self + 0x10);
    low.z -= D_L21_001DE2A0;
    func_003CF790(&low, 0, *(void **)(self + 0xB8), buf, 0.5f);
    func_L01_004026A0(func_L21_003AFAD8, self);
}
/* localdecomp:end func_L21_003AF770 */
