#include "common.h"

/* localdecomp:start func_L39_005247C0 */
#include "vu0.h"

extern void func_L01_00307058(s32 unused, f32 *pos, f32 *dir, s32 color, f32 scale);
extern unsigned long func_L39_00589890(s32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_005247C0(u8 *self)
{
    s32 i, j, alpha;
    u8 *rec, *src, *qb;
    u8 *obj = *(u8 **)(self + 0x68);
    u8 *cam = *(u8 **)(obj + 0x2C);
    f32 *v, *pos, *t;
    s32 *rnd;
    s32 a;
    f32 m[4][4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 up[4] __attribute__((aligned(16)));

    for (i = 0; i < 10; i++) {
        rec = (u8 *)(i * 0x530 + *(s32 *)(obj + 0x60));
        if (*(s32 *)(rec + 0x514) != 1)
            continue;
        if (*(s32 *)(rec + 0x518) == 1)
            alpha = (s32)(*(f32 *)(rec + 0x510) * 64.0f * 2.0f);
        else
            alpha = 0x40;
        a = alpha << 24;
        func_L01_00307058((s32)self, (f32 *)(rec + 0x20), (f32 *)rec, a | 0x103080, 0.35f);
        func_L01_00307058((s32)self, (f32 *)(rec + 0x20), (f32 *)rec, a | 0xFFFFFF, 0.075f);
        rnd = (s32 *)(rec + 0x4E0);
        pos = (f32 *)(rec + 0x500);
        qb = rec + 0x2A0;
        for (j = 0; j < 2; j++) {
            t = &pos[j];
            v = (f32 *)(rec + 0x20 + j * 0x10);
            *(unsigned long *)(qb + j * 0x90 + 0x78) = func_L39_00589890(0x17);
            *(unsigned long *)(qb + j * 0x90 + 0x80) = 0xFF9000000260UL;
            *(unsigned long *)(qb + j * 0x90 + 0x70) = 0;
            *(s32 *)(qb + j * 0x90 + 0x48) = (alpha << 24) + 0x103080;
            *(s32 *)(qb + j * 0x90 + 0x40) = (alpha << 24) + 0x103080;
            *(s32 *)(qb + j * 0x90 + 0x4C) = 0x103080;
            *(s32 *)(qb + j * 0x90 + 0x44) = 0x103080;
            *(unsigned long *)(qb + j * 0x90 + 0x88) = ((long)(j % 2 + 1) << 2) | 0x8000000040UL;
            src = rec + j * 0x90 + 0x60;
            if (rnd[j]) {
                *(f32 *)(qb + j * 0x90 + 0x50) = *t + 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x54) = 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x58) = *t + 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x5C) = 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x60) = *t + 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x64) = 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x68) = *t + 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x6C) = 1.0f;
            } else {
                *(f32 *)(qb + j * 0x90 + 0x50) = *t + 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x54) = 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x58) = *t + 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x5C) = 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x60) = *t + 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x64) = 0.0f;
                *(f32 *)(qb + j * 0x90 + 0x68) = *t + 1.0f;
                *(f32 *)(qb + j * 0x90 + 0x6C) = 0.0f;
            }
            {
                vu0_q qv, qc;
                __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(*(vu0_v4 *)(cam + 0x23A0)));
                __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(*(vu0_v4 *)v));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(qc) : "j"(qc), "j"(qv));
                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qc));
            }
            func_L39_005BC330(v, up, 1);
            func_0038CF68(m[0], d, 1.0f);
            func_0038CE90(m[1], m[0], up);
            func_0038CF68(m[1], m[1], 1.0f);
            func_0038CE90(m[2], m[1], m[0]);
            m[3][0] = v[0];
            m[3][1] = v[1];
            m[3][2] = v[2];
            m[3][3] = 1.0f;
            if (*(s32 *)(rec + 0x518) == 1) {
                func_0038CE20(qb + j * 0x90, src, 0.5f);
                func_0038CE20(rec + j * 0x90 + 0x2B0, rec + j * 0x90 + 0x70, 0.5f);
                func_0038CE20(rec + j * 0x90 + 0x2C0, rec + j * 0x90 + 0x80, 0.5f);
                func_0038CE20(rec + j * 0x90 + 0x2D0, rec + j * 0x90 + 0x90, 0.5f);
            } else {
                func_0038CE20(qb + j * 0x90, src, *(f32 *)(rec + 0x510));
                func_0038CE20(rec + j * 0x90 + 0x2B0, rec + j * 0x90 + 0x70, *(f32 *)(rec + 0x510));
                func_0038CE20(rec + j * 0x90 + 0x2C0, rec + j * 0x90 + 0x80, *(f32 *)(rec + 0x510));
                func_0038CE20(rec + j * 0x90 + 0x2D0, rec + j * 0x90 + 0x90, *(f32 *)(rec + 0x510));
            }
            func_003D2DA0(qb + j * 0x90, m, 0);
        }
    }
}
/* localdecomp:end func_L39_005247C0 */
