#include "common.h"

/* NTSC-U version of func_003BF2A0 (frontbin): 0.00392 -> 0.00272222 */
#include "common.h"





extern void func_U_003B9DA8();
typedef int Q_3B9C50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9C50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u8 padA[2];
    s32 wC;
    Q_3B9C50 q10;
    V4_3B9C50 v20;
    Q_3B9C50 q30;
} S_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50_003BF148;
typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
extern void func_U_003C7CE0(s32);
/* localdecomp:start func_U_003B9DA8 */
typedef int Q_003BF2A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BF2A0;
typedef struct {
    u8 pad0[0x10];
    V4_003BF2A0 v10;
    V4_003BF2A0 v20;
    V4_003BF2A0 v30;
} S_003BF2A0;
extern void func_U_003C7CE0(s32);
void func_U_003B9DA8(S_003BF2A0 *p) {
    V4_003BF2A0 *q = &p->v30;
    f32 w = q->w;
    V4_003BF2A0 v;
    Q_003BF2A0 a20, a10, b1, b2, r1, r2;
    if (w < p->v10.z || p->v10.x < 0.0f || p->v10.y < 0.0f || 1024.0f < p->v10.x || 1024.0f < p->v10.y) {
        func_U_003C7CE0((s32)p);
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
    q->z -= 0.00272222236f;
    q->w = w;
}
/* localdecomp:end func_U_003B9DA8 */
