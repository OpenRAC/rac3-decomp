#include "common.h"

/* localdecomp:start func_L39_005FF198 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);

void func_L39_005FF198(u8 *a0, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 t0;
    vu0_v4 t1;

    if (a0 != 0 && *(s16 *)(a0 + 0x2D8) != 0) {
        *a2 = *(vu0_v4 *)(*(u8 **)(a0 + 0x2524) + 0xE0);
        func_0038CF68(&t0, a2, 0.1f);
        vec_add_ba(&t0, &t0, a1);
        func_0038CF68(&t1, a2, -6.0f);
        vec_add_ba(&t1, &t1, a1);
        if (func_003D3CB0(&t0, &t1, 2, 0, 0) != 0 && func_003D5630() == 2) {
            return;
        }
    }
    __asm__ __volatile__(
        "vmr32.xyzw $vf1, $vf0\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(a2) : "memory");
}
/* localdecomp:end func_L39_005FF198 */

/* localdecomp:start func_L39_005FF270 */
#include "vu0.h"

typedef int q_005FF270 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
} S_005FF270;

extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern S_005FF270 D_L39_0025F740;
extern q_005FF270 D_L39_0025F760;
extern q_005FF270 D_L39_0025F770;
extern vu0_v4 D_L39_0025F780;
extern void func_L39_005FF198(u8 *, vu0_v4 *, vu0_v4 *);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern s32 func_L01_003FB640(f32, void *, s32, u8 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);

s32 func_L39_005FF270(u8 *a0, s32 a1)
{
    vu0_v4 v;
    vu0_v4 pos;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 *pp;
    vu0_q q1, q2;
    s32 r = 0;
    s32 mode;
    s32 i;
    u8 *p;
    f32 len;

    func_L39_005FF198(D_L39_0024CE20[a1], (vu0_v4 *)(*(u8 **)(a0 + 0x30) + 0x10), &v);
    if (*(s32 *)(a0 + 0x58) != 0) {
        func_0038CF68(&pos, *(u8 **)(a0 + 0x30) + 0xE0, *(f32 *)(a0 + 0x5C));
        pp = &pos;
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(q1));
    } else {
        *(q_005FF270 *)&pos = *(q_005FF270 *)(a0 + 0x10);
        pp = &pos;
    }
    p = D_L39_0024CE20[a1];
    a1 = -1;
    if (p != 0) {
        a1 = *(s32 *)(p + 0x2548);
    }
    func_L39_005FFDF8(a1);
    if (func_L01_003FB640(*(f32 *)(a0 + 0x3C), pp, *(s32 *)(a0 + 0x4C), *(u8 **)(a0 + 0x30))) {
        mode = 1;
    } else if (func_003D3CB0(a0, a0 + 0x10, *(s32 *)(a0 + 0x4C), *(void **)(a0 + 0x30), 0) != 0) {
        mode = 2;
    } else {
        mode = 0;
    }
    func_L39_005FFE78();
    *(u8 **)(a0 + 0x30) = 0;
    if (mode != 0) {
        *(s32 *)(a0 + 0x54) = func_003D5630();
        if (D_L39_0025F740.f18 != 0) {
            for (i = 0; i < *(s32 *)(a0 + 0x38); i++) {
                if (*(s16 *)(D_L39_0025F740.f18 + 0xAA) == (*(s32 **)(a0 + 0x34))[i]) {
                    return 0;
                }
            }
            *(u8 **)(a0 + 0x30) = D_L39_0025F740.f18;
        }
        if (mode == 1) {
            *(q_005FF270 *)(a0 + 0x10) = D_L39_0025F770;
        } else {
            *(q_005FF270 *)(a0 + 0x10) = D_L39_0025F760;
        }
        func_0038CE20(a0, &D_L39_0025F780, 1.0f / 1024.0f);
        func_0038CF68(a0, a0, 1.0f);
        if (func_0038CE68(&v, a0) < *(f32 *)(a0 + 0x44)
            || (*(u8 **)(a0 + 0x30) != 0 && *(*(u8 **)(*(u8 **)(a0 + 0x30) + 0x24) + 0x46) == 5
                && *(s32 *)(a0 + 0x50) != 0)) {
            func_L01_0040E790((f32 *)(a0 + 0x20), (f32 *)(a0 + 0x20), (f32 *)a0);
            r = 1;
            len = func_0038CE68(a0 + 0x20, a0);
            func_0038CE20(&a, a0, len);
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(a));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)(a0 + 0x20)));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(q1));
            func_0038CE20(a0 + 0x20, &a, *(f32 *)(a0 + 0x40));
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)(a0 + 0x20)));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(b));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x20)) : "j"(q1));
        } else {
            r = 2;
            *(q_005FF270 *)(a0 + 0x10) = D_L39_0025F760;
        }
    }
    return r;
}
/* localdecomp:end func_L39_005FF270 */

LINKER_REMNANT("asm/levels", func_L39_005FF528);
