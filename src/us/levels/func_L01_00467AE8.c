#include "common.h"

/* NTSC-U counterpart of func_L01_0046B198 (src/levels/shared/L01_0046A938.c): 0.002 -> 0.00138889 */
#include "vu0.h"
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);

/* localdecomp:start func_L01_00467AE8 */
extern void func_00388700(void *, void *, f32);

void func_L01_00467AE8(u8 *p)
{
    vu0_v4 v;
    vu0_q qa;
    vu0_q qb;
    vu0_q qr;
    u32 x;
    f32 *q = (f32 *)(p + 0x20);

    func_00388700(&v, q, 0.95f);
    q[2] += 0.00138888892f;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(p + 0x20)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(p + 0x10)) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
    x = *(u32 *)(p + 4) + 0xFE000000;
    *(u32 *)(p + 4) = x;
    if ((x & 0xFF000000) - 1 > 0x5EFFFFFF || func_003883C8((s16 *)(p + 0xA)) != 0) {
        func_003C7CE0((Obj *)p);
    } else {
        f32 f = *(f32 *)(p + 0xC);
        p[8]++;
        *(f32 *)(p + 0xC) = f + (210000.0f - f) * 0.07f;
    }
}
/* localdecomp:end func_L01_00467AE8 */
