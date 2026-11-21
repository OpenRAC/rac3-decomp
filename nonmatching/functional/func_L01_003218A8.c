/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 66 words differ, single VU sequence vs retail interleaved EE setup; not byte-identical, behaviour as retail. */
#include "vu0.h"
typedef struct { vu0_v4 pos; u8 pad10[0x38]; f32 phase; } Vars_003218A8;
extern s32 D_L01_001DC940;
extern u8 *D_L01_001E17B8[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E29C0[];
extern s32 D_L01_001DC984, D_L01_001DC97C;
__asm__(".extern D_L01_001DC940, 4");
__asm__(".extern D_L01_001DC984, 4");
__asm__(".extern D_L01_001DC97C, 4");
void func_L01_003218A8(u8 *gun) {
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_004CB128(void *, u8 *, s32);
    extern void func_0038CF68(f32 *, s32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_003F6F20(s32, u8 *, s32, Vars_003218A8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    Vars_003218A8 *vars = *(Vars_003218A8 **)(gun + 0x68);
    s32 i;
    vu0_v4 delta;
    f32 ratio;
    vars->phase = func_0038DAB8(vars->phase, 0.034906585f);
    for (i = 0; i < D_L01_001DC940; i++) {
        u8 *target = D_L01_001E17B8[i];
        if (target == 0 || target[0x20] == 0xFE || target[0x20] == 0xFD || (*(u16 *)(target + 0x34) & 2) || !target[0x31]) continue;
        func_L01_004CB128(vars, target, 0);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(delta) : "m"(*(vu0_v4 *)vars), "m"(D_L01_001E29C0[0]) : "vf1", "vf2");
        func_0038CF68((f32 *)&delta, (s32)&delta, 1.0f);
        if (func_0038CE68(D_L01_001E29C0 + 2, &delta) > 0.5f) {
            ratio = func_0038CF00(D_L01_001E29C0, vars) / 150.0f;
            if (i == D_L01_001DC940 - 1) D_L01_001DC984 = 0x7F2040FF;
            func_L01_003F6F20(0, gun, D_L01_001DC984, vars, D_L01_001DC97C, -1, 4,
                fabs_asm(0.9f - ratio * 0.65f), -vars->phase, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
}
