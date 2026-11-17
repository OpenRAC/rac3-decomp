/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_0039D488, the NTSC-U twin of func_L08_0039EFB0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 @ps2as" (src/levels/08_aquatos/L08_0039ED70.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L08_0039D488 (src/levels/08_aquatos/L08_0039ED70.c) */
#include "vu0.h"

/* localdecomp:start func_L08_0039D488 */
extern s32 D_001DE13C_sda;
__asm__(".extern D_001DE13C_sda, 4");
extern f32 D_001DE14C_sda;
__asm__(".extern D_001DE14C_sda, 4");
extern f32 D_001DE150_sda;
__asm__(".extern D_001DE150_sda, 4");
extern f32 D_001DE160_sda;
__asm__(".extern D_001DE160_sda, 4");
extern f32 D_001DE140_sda;
__asm__(".extern D_001DE140_sda, 4");
extern f32 D_001DE15C_sda;
__asm__(".extern D_001DE15C_sda, 4");
extern f32 D_001DE154_sda;
__asm__(".extern D_001DE154_sda, 4");
extern f32 D_001DE158_sda;
__asm__(".extern D_001DE158_sda, 4");
extern s32 D_001DE144_sda;
__asm__(".extern D_001DE144_sda, 4");
extern s32 D_001DE148_sda;
__asm__(".extern D_001DE148_sda, 4");
extern s32 D_001DE0F0_sda;
__asm__(".extern D_001DE0F0_sda, 4");
extern f32 D_001DE10C_sda;
__asm__(".extern D_001DE10C_sda, 4");
extern f32 D_001DE11C_sda;
__asm__(".extern D_001DE11C_sda, 4");
extern f32 D_001DE100_sda;
__asm__(".extern D_001DE100_sda, 4");
extern f32 D_001DE104_sda;
__asm__(".extern D_001DE104_sda, 4");
extern f32 D_001DE108_sda;
__asm__(".extern D_001DE108_sda, 4");
extern f32 D_001DE0FC_sda;
__asm__(".extern D_001DE0FC_sda, 4");
extern s32 D_001DE0F4_sda;
__asm__(".extern D_001DE0F4_sda, 4");
extern s32 D_001DE110_sda;
__asm__(".extern D_001DE110_sda, 4");
extern f32 D_001DE120_sda;
__asm__(".extern D_001DE120_sda, 4");
extern f32 D_001DE124_sda;
__asm__(".extern D_001DE124_sda, 4");
extern f32 D_001DE114_sda;
__asm__(".extern D_001DE114_sda, 4");
extern f32 D_001DE118_sda;
__asm__(".extern D_001DE118_sda, 4");
extern s32 D_001DE128_sda;
__asm__(".extern D_001DE128_sda, 4");
extern s32 D_001DE130_sda;
__asm__(".extern D_001DE130_sda, 4");
extern s32 D_001DE12C_sda;
__asm__(".extern D_001DE12C_sda, 4");
extern s32 D_001DE134_sda;
__asm__(".extern D_001DE134_sda, 4");
extern s32 D_001DE0F8_sda;
__asm__(".extern D_001DE0F8_sda, 4");
extern s32 D_001DE138_sda;
__asm__(".extern D_001DE138_sda, 4");

typedef int u128_0039D488 __attribute__((mode(TI)));

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(f32, s32, s32);
extern void func_L01_00470258(void *, void *, s32, s32, s32, s32, f32);
extern void func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039D488(u8 *o) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    s32 b;
    f32 t1;
    f32 ang;
    f32 r1;
    f32 r2;

    *(u128_0039D488 *)&v10 = *(u128_0039D488 *)(o + 0xE0);
    for (i = 0; i < D_001DE13C_sda; i++) {
        func_00388830(&v20, &v10, func_0037E250(D_001DE14C_sda, D_001DE150_sda) * 0.016666668f);
        func_003BF6A8(&v20, D_001DE160_sda * 0.016666668f);
        func_00388830(&v30, &v10, D_001DE140_sda);
        vec_add_ab(&v30, &v30, o + 0x10);
        func_003BF6A8(&v30, D_001DE15C_sda);
        t1 = func_0037E250(D_001DE154_sda, D_001DE158_sda) * 210000.0f;
        func_L01_00470258(&v30, &v20, D_001DE144_sda, D_001DE148_sda, (s16)func_0037E208(0x78, 0xF0), 0, t1);
    }
    for (j = 0; j < D_001DE0F0_sda; j++) {
        *(u128_0039D488 *)&v20 = *(u128_0039D488 *)(o + 0x10);
        func_003BF6A8(&v20, D_001DE10C_sda);
        v20.z = v20.z + 0.7f;
        ang = func_0037E2A8();
        r1 = func_0037E250(D_001DE11C_sda, D_001DE100_sda) * 0.016666668f;
        r2 = func_0037E250(D_001DE104_sda, D_001DE108_sda);
        *(u128_0039D488 *)&v30 = 0;
        v30.x = v30.x + func_00388960(ang) * r1;
        v30.y = v30.y + func_00388978(ang) * r1;
        v30.z = v30.z + r2 * 0.016666668f;
        *(u128_0039D488 *)&v40 = *(u128_0039D488 *)&v30;
        v40.z = v40.z - func_0037E250(D_001DE0FC_sda * 0.7f, D_001DE0FC_sda * 1.3f) * 0.00027777778f * (f32)D_001DE0F4_sda;
        for (k = 0; k < D_001DE110_sda; k++) {
            f32 t = func_0037E250(0.5f, 1.5f);
            ((f32 *)&v30)[3] = t * D_001DE120_sda;
            ((f32 *)&v40)[3] = t * D_001DE124_sda;
            func_003BF6A8(&v20, D_001DE114_sda);
            func_003BF6A8(&v40, D_001DE118_sda * 0.016666668f);
            a = func_003894A0(func_0037E250(0.0f, 1.0f), D_001DE128_sda, D_001DE130_sda);
            b = func_003894A0(func_0037E250(0.0f, 1.0f), D_001DE12C_sda, D_001DE134_sda);
            func_L01_0045FEC8(&v20, &v30, &v40, a, b, D_001DE138_sda, D_001DE0F4_sda,
                              (s32)func_0037E250((f32)D_001DE0F8_sda * 0.5f, (f32)D_001DE0F8_sda * 2.5f), -1);
        }
    }
}
/* localdecomp:end func_L08_0039D488 */
