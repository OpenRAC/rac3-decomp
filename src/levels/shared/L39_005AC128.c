#include "common.h"

/* localdecomp:start func_L39_005AC128 */
#include "vu0.h"

typedef struct {
    s32 f0;
    u16 x, y, z;
    s16 fA;
    s16 fC;
    u8 fE, fF;
    u8 c0, c1, c2;
    u8 d0, d1, d2;
    u8 f16;
    u8 e0, e1, e2;
    s16 f1A, f1C;
    u8 pad[2];
} E_005AC128;

typedef struct {
    u8 r, g, b, pad;
    f32 a, b2, c;
} G_005AC128;

extern s32 D_L39_0024BFAC;
extern E_005AC128 *D_L39_0024BFC0;
extern G_005AC128 D_L39_0024BA64 __attribute__((section(".sdata")));
extern f32 D_L39_0024BA74;
extern s32 D_00241128;
typedef struct {
    u8 pad0[0x40];
    u8 c[3];
    u8 flags;
    u8 pad44[0x70];
    s32 fB4;
} S_005AC128;
extern S_005AC128 D_001FE020[];
extern f32 func_L01_0040E4C0(void *);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_L39_005C1AC0(s32 a0, s32 a1, s32 a2);
extern void func_003864C0(s32);

void func_L39_005AC128(u8 *a0)
{
    vu0_v4 p;
    vu0_v4 d;
    vu0_q qa, qb;
    s32 i;
    s32 best = -1;
    f32 bestd = 1000000.0f;
    f32 dist;
    f32 lo, hi;

    for (i = 0; i < D_L39_0024BFAC; i++) {
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        p.x = D_L39_0024BFC0[i].x * 0.25f;
        p.y = D_L39_0024BFC0[i].y * 0.25f;
        p.z = D_L39_0024BFC0[i].z * 0.25f;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(p));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
        dist = func_L01_0040E4C0(&d);
        if (dist < bestd) {
            bestd = dist;
            best = i;
        }
    }
    if (best == -1) {
        return;
    }
    if (bestd > 400.0f) {
        return;
    }
    func_003C6F90(a0, (D_L39_0024BFC0[best].c2 << 16) + (D_L39_0024BFC0[best].c1 << 8) | D_L39_0024BFC0[best].c0, 0, 0, 0);
    *(s32 *)(a0 + 0x38) = D_L39_0024BFC0[best].f0;
    if (D_00241128 != 2) {
        if (D_L39_0024BFC0[best].f16 != 0) {
            D_001FE020[0].fB4 = D_L39_0024BFC0[best].fA;
            D_001FE020[0].c[0] = D_L39_0024BFC0[best].d0;
            D_001FE020[0].c[1] = D_L39_0024BFC0[best].d1;
            D_001FE020[0].c[2] = D_L39_0024BFC0[best].d2;
            D_001FE020[0].flags |= 7;
        }
        if (D_00241128 != 2) {
            func_L39_005C1AC0(D_L39_0024BFC0[best].fC, 1, 0x400);
        }
    }
    if (D_L39_0024BFC0[best].f1A < D_L39_0024BFC0[best].f1C) {
        D_L39_0024BA64.r = D_L39_0024BFC0[best].e0;
        D_L39_0024BA64.g = D_L39_0024BFC0[best].e1;
        D_L39_0024BA64.b = D_L39_0024BFC0[best].e2;
        lo = D_L39_0024BFC0[best].f1A * 1024.0f;
        hi = D_L39_0024BFC0[best].f1C * 1024.0f;
        D_L39_0024BA64.a = lo;
        D_L39_0024BA64.b2 = hi;
        D_L39_0024BA64.c = D_L39_0024BFC0[best].fE;
        D_L39_0024BA74 = D_L39_0024BFC0[best].fF;
        func_003864C0(0);
    }
}
/* localdecomp:end func_L39_005AC128 */
