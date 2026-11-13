#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L39_0055AF88.c, which this file was cut from */
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(f32 *, f32, f32, f32);

/* localdecomp:start func_L39_0055B178 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0055B178;
typedef struct { u8 p0[0x20]; f32 x, y, z; } S_0055B178;
extern S_0055B178 D_L39_0025F740;
extern V4_0055B178 D_L39_0025F760;
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004660F8(void *, void *);
extern s32 func_L39_005B43C8(s32, s32);
extern void *func_L39_005C8990(void *a0, void *a1, int a2, int a3, int a4, int a5, float f);
void func_L39_0055B178(u8 *a0, u8 *a1) {
    V4_0055B178 d;
    V4_0055B178 v;
    u128_t pos;
    f32 len;
    f32 pitch;
    f32 a;
    s32 i;

    if (a1 == 0)
        return;
    if (a1[0x1A14] != 0)
        pos = **(u128_t **)(a1 + 0x2530);
    else
        pos = *(u128_t *)(a1 + 0x23A0);
    {
    vu0_q q2, q1;
    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(pos));
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(D_L39_0025F760));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(q2) : "j"(q2), "j"(q1));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(q2));
    }
    len = func_0038CED8(&d);
    pitch = -func_0038D160(len, d.z);
    func_0038D160(d.x, d.y);
    for (i = 0; i < 20; i++) {
        a = func_0038DAB8(func_L39_005B4468(0.0f, 3.1415927f), pitch);
        func_00382760((f32 *)&d, 0.2f, func_0038DAB8(func_L39_005B4468(0.0f, 3.1415927f), pitch), a);
        func_0038CE20(&v, &d, func_L39_005B4410(1.0f, 3.0f));
        {
        vu0_q q2, q1;
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(D_L39_0025F760));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q2) : "j"(q2), "j"(q1));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(q2));
        }
        func_L01_004660F8(&v, &d);
    }
    for (i = 0; i < 10; i++) {
        v.x = D_L39_0025F740.x + func_L39_005B4468(0.0f, 0.1f);
        v.y = D_L39_0025F740.y + func_L39_005B4468(0.0f, 0.1f);
        v.z = D_L39_0025F740.z + func_L39_005B4468(0.0f, 0.1f);
        a = func_0038DAB8(func_L39_005B4468(0.0f, 3.1415927f), pitch);
        func_00382760((f32 *)&d, 0.05f, func_0038DAB8(func_L39_005B4468(0.0f, 3.1415927f), pitch), a);
        func_L39_005C8990(&v, &d, 0x4F007FFF, 0x1FFFFFFF, func_L39_005B43C8(8, 17), 1, 20000.0f);
    }
    if (*(s16 *)(*(u8 **)(a0 + 0x68) + 0x78) == 0x27)
        func_L39_0055AF88((f32 *)&D_L39_0025F760, 10);
}
/* localdecomp:end func_L39_0055B178 */
