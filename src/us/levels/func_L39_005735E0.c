#include "common.h"

/* NTSC-U counterpart of func_L39_00574308 (src/levels/shared/L39_00573DE0.c) */
/* localdecomp:start func_L39_005735E0 */
#include "vu0.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} Sub_00574308;
typedef struct { f32 x, y, z; s32 w; } __attribute__((aligned(16))) V_00574308;

extern u8 D_L39_0024DF00[];
extern u8 D_L39_001FE1A0[];
extern s32 func_L39_005F0ED8(s32, s32, void *, s32);
extern f32 func_003888C8(void *, void *, void *);
extern s32 func_00388398(void *);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);

void func_L39_005735E0(u8 *self) {
    V_00574308 a;
    V_00574308 b;
    V_00574308 ra;
    V_00574308 rb;
    V_00574308 v;
    vu0_q qa, qs, qv, qp;
    Sub_00574308 *sub;
    f32 s;
    u8 *slot;
    s32 n;

    { __asm__("lqc2 %0, %1" : "=j"(qs) : "m"(*(vu0_v4 *)D_L39_0024DF00)); }
    sub = *(Sub_00574308 **)(self + 8);
    s = *(f32 *)(self + 0xC);
    b.x = s;
    b.y = s;
    b.z = s;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qs) : "j"(qs), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qs));
    a.w = 0;
    func_003888C8(&ra, &a, self + 0x50);
    func_003888C8(&rb, &b, self + 0x50);
    if (fabs_asm(rb.x) + 1.0f >= fabs_asm(ra.x)
        && fabs_asm(rb.y) + 1.0f >= fabs_asm(ra.y)
        && fabs_asm(rb.z) + 1.0f >= fabs_asm(ra.z)) {
        slot = D_L39_001FE1A0 + (sub->w10 << 7);
        if (*(u8 **)(slot + 0x100) == self && *(slot + 0xD0) != 0) {
            return;
        }
        if (func_00388398(&sub->wC) != 0) {
            n = func_L39_005F0ED8(sub->w0, 0, self, 0x400);
            sub->w10 = n;
            if (n != -1) {
                v.x = func_L39_005B2510(-1.0f, 1.0f);
                v.y = func_L39_005B2510(-1.0f, 1.0f);
                v.z = func_L39_005B2510(-1.0f, 1.0f);
                func_003888C8(&v, &v, self + 0x10);
                __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(self + 0x40)));
                __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(v));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
                __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qv));
                *(vu0_q *)(D_L39_001FE1A0 + (sub->w10 << 7) + 0xE0) = *(vu0_q *)&v;
            }
            if (sub->w8 > 0) {
                sub->wC = (s32)((f32)(sub->w4 + func_L39_005B2498(sub->w8 - sub->w4)) * 60.0f);
            }
        } else {
            sub->w10 = -1;
        }
    }
}
/* localdecomp:end func_L39_005735E0 */
