/* Level 30 near miss: 5 of 98 words differ with the owning file's flags plus
   -mvu0-use-vf0-vf2. The file already uses @ps2as. Retail stores the final
   quadword at sp+0x40 before sp+0x20; this C reverses them and schedules the
   s2/ra restores earlier. Tail/store/load permutations did not move the tie.
   The five-member aggregate preserves retail's stack slots. No div.s/sqrt.s.
   This draft is not linked; the owning file's flags are unchanged. */
#include "common.h"
#include "vu0.h"

typedef int Q_003427F8 __attribute__((mode(TI)));
typedef struct {
    Q_003427F8 v, pos, d, tmp, q;
} S_3427F8;

extern s32 func_L30_00342980(u8 *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 D_001DCE28_sda;
extern f32 D_001DCE3C_sda;
extern f32 D_001DCE40_sda;
extern vu0_v4 D_L30_001E9020;
__asm__(".extern D_001DCE28_sda, 4");
__asm__(".extern D_001DCE3C_sda, 4");
__asm__(".extern D_001DCE40_sda, 4");
__asm__(".extern D_L30_001E9020, 16");

void func_L30_003427F8(u8 *a0) {
    u8 *t = *(u8 **)(a0 + 0x68);
    S_3427F8 s;
    Q_003427F8 r1, r2;
    s32 ret;

    ret = func_L30_00342980(a0);
    if (ret != 0 && *(f32 *)(t + 0x68) < 0.0f) {
        *(f32 *)(t + 0x68) = 0.0f;
    } else {
        *(f32 *)(t + 0x68) += D_001DCE28_sda;
    }

    if (*(f32 *)(t + 0x60) > D_001DCE3C_sda) {
        *(f32 *)(t + 0x60) = D_001DCE3C_sda;
    } else if (*(f32 *)(t + 0x60) < -D_001DCE3C_sda) {
        *(f32 *)(t + 0x60) = -D_001DCE3C_sda;
    }

    if (*(f32 *)(t + 0x68) > D_001DCE40_sda) {
        *(f32 *)(t + 0x68) = D_001DCE40_sda;
    } else if (*(f32 *)(t + 0x68) < -D_001DCE40_sda) {
        *(f32 *)(t + 0x68) = -D_001DCE40_sda;
    }

    s.pos = *(Q_003427F8 *)(a0 + 0x10);
    *(f32 *)((u8 *)&s.pos + 8) += *(f32 *)(t + 0x70);

    vec_add_ab(&s.v, &s.pos, (void *)(t + 0x60));
    if (func_L01_003FB640(&s.v, 2, a0, *(f32 *)(t + 0x70)) != 0) {
        __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(s.v));
        __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(D_L30_001E9020));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
        __asm__("sqc2 %1, %0" : "=m"(s.tmp) : "j"(r1));
        func_0038CF68(&s.tmp, &s.tmp, 1.0f);
        func_0038CF68(&s.tmp, &s.tmp, *(f32 *)(t + 0x70));
        vec_add_ab(&s.v, &s.tmp, &D_L30_001E9020);
    }
    __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(s.pos));
    __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(s.v));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r2) : "j"(r2), "j"(r1));
    __asm__("sqc2 %1, %0" : "=m"(s.d) : "j"(r2));
    vec_copy(&s.q, (void *)(a0 + 0x10));
    __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(s.d));
    __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(s.q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "j"(r1));
}
