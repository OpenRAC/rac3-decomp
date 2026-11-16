/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: file line L20_003EE688.c lacks @ps2as: retail builds the float 5627.9248f (0x45AFDF66) with lui/ori/mtc1, plain ee-as gives lwc1 off($gp); with @ps2as best is 12 diff (prologue sched order of li/move/sw before func_0038CF68 + li v0,3/v1,2 order); C in ...
 */
#include "common.h"

/* localdecomp:start func_L20_003EFFE0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
    u8 *obj;
    s32 f14;
    u8 b18, b19;
    u16 h1A;
    f32 f1C;
    s32 w20;
} Q_003EFFE0;

extern u128_t D_L20_001D66B0_003EFFE0;
extern void func_0038CF68(void *, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);

void func_L20_003EFFE0(u8 *arg0, f32 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    Q_003EFFE0 q;

    q.obj = arg0;
    q.f14 = *(s32 *)(s + 0x64);
    q.f1C = arg1;
    q.w20 = 1;
    *(u128_t *)&q = D_L20_001D66B0_003EFFE0;
    func_0038CF68(&q, &q, 1.0f);
    q.w = 5627.9248046875f;
    q.b18 = 3;
    q.b19 = 2;
    q.h1A = *(u16 *)(arg0 + 0xAA);
    func_003D4D00(arg0 + 0x10, 0, 0, &q, *(f32 *)(s + 0x68));
}
/* localdecomp:end func_L20_003EFFE0 */
