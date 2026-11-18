/* PAL port of the NTSC-U draft (Sonnet worker b15-z4, 2026-11-18): 3 words off with -mno-split-addresses @ps2as (see the README row). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0033D940 */
/* NTSC-U counterpart of func_L01_0033D940 (src/levels/shared/L01_0033AC58.c) */
typedef struct {
    vu0_q q0, q10, q20, q30;
    f32 f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84;
    s32 i88, i8C, i90, i94, i98, i9C;
} P_33D248;

extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_00382348(void *);
extern void func_L01_00451290(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);

extern P_33D248 D_L01_00278BC0[];
extern vu0_q D_L01_001E18B0;

void func_L01_0033D940(s32 a0, u8 *a1, s32 a2) {
    P_33D248 *p;
    u8 *r;
    vu0_v4 v;
    s32 i;

    for (i = 0; i < 3; i++) { vu0_q *src = &D_L01_001E18B0;
        p = &D_L01_00278BC0[i];
        if (p->i8C != 0) {
            continue;
        }
        p->i8C = a0;
        p->q20 = *src;
        p->f40 = func_003824E0(-3.1415927f, 3.1415927f);
        p->f44 = func_003824E0(-3.1415927f, 3.1415927f);
        p->f48 = func_003824E0(-3.1415927f, 3.1415927f);
        p->f64 = func_003824E0(-3.1415927f, 3.1415927f);
        p->f68 = func_003824E0(-3.1415927f, 3.1415927f);
        p->f6C = func_003824E0(-3.1415927f, 3.1415927f);
        p->f4C = func_L01_00443A18(0.001f, 0.005f);
        p->f50 = func_L01_00443A18(0.001f, 0.005f);
        p->f54 = func_L01_00443A18(0.001f, 0.005f);
        p->f70 = func_L01_00443A18(0.001f, 0.005f);
        p->f74 = func_L01_00443A18(0.001f, 0.005f);
        p->f78 = func_L01_00443A18(0.001f, 0.005f);
        p->f58 = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->f5C = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->f60 = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->f7C = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->f80 = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->f84 = func_003824E0(3.25f, 4.75f) * 0.5f;
        p->i94 = a2;
        qzero(&p->q0);
        p->i98 = a2;
        qzero(&p->q10);
        p->i88 = 0xC;
        p->i90 = (s32)a1;
        p->i9C = 0;
        r = func_00382348(a1);
        if (r != 0) {
            func_L01_00451290(a1, &v, 1);
            func_0038CE20(&v, &v, *(f32 *)(r + 0x10));
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(p->q30) : "m"(v), "m"(*(vu0_v4 *)(a1 + 0x10)));
        } else {
            p->q30 = *(vu0_q *)(a1 + 0x10);
        }
        return;
    }
}
/* localdecomp:end func_L01_0033D940 */
