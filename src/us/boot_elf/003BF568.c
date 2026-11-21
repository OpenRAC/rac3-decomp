#include "common.h"

/* NTSC-U counterpart of func_003BF658 (src/boot_elf/text/3BF500.c): the per-frame step 0.00392f -> 0.0027222224f (0x3B326750) */
/* localdecomp:start func_U_003BF568 */
typedef int Q_003BF568 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BF568;
typedef struct {
    u8 pad0[0x10];
    V4_003BF568 v10;
    V4_003BF568 v20;
    V4_003BF568 v30;
} S_003BF568;
extern void func_U_003CD4A0(s32);
void func_U_003BF568(S_003BF568 *p) {
    V4_003BF568 *q = &p->v30;
    f32 w = q->w;
    V4_003BF568 v;
    Q_003BF568 a20, a10, b1, b2, r1, r2;
    if (w < p->v10.z || p->v10.x < 0.0f || p->v10.y < 0.0f || 1024.0f < p->v10.x || 1024.0f < p->v10.y) {
        func_U_003CD4A0((s32)p);
        return;
    }
    v = *q;
    v.w = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(a20) : "m"(p->v20));
    __asm__("lqc2 %0, %1" : "=j"(b1) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(b2) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(a20), "j"(b2));
    __asm__("sqc2 %1, %0" : "=m"(p->v20) : "j"(r1));
    __asm__("lqc2 %0, %1" : "=j"(a10) : "m"(p->v10));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(a10), "j"(b1));
    __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(r2));
    q->z -= 0.0027222224f;
    q->w = w;
}
/* localdecomp:end func_U_003BF568 */
