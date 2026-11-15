/* func_L30_00350DB0: 6 diff with the file's flags (@ps2as). Left: the init call func_L03_0034B218 is set up with its function pointer ($t0) and $a1 loaded before $a0 in retail; gcc loads $a0 first. Everything else (the u128 copies, the float stores, the flag order) matches. */
#include "common.h"

typedef int q_00350DB0 __attribute__((mode(TI)));
__asm__(".extern D_L30_001DD744, 4");
__asm__(".extern D_L30_001DD748, 4");
__asm__(".extern D_L30_001DD750, 4");
__asm__(".extern D_L30_001DD820, 4");
__asm__(".extern D_L30_001DD824, 4");
__asm__(".extern D_L30_001DD848, 4");
__asm__(".extern D_L30_001DD84C, 4");
extern s32 D_L30_001DD744;
extern f32 D_L30_001DD748;
extern f32 D_L30_001DD750;
extern s32 D_L30_001DD820;
extern s32 D_L30_001DD824;
extern f32 D_L30_001DD848;
extern s32 D_L30_001DD84C;
extern u8 D_L30_001E1340[];
extern s32 D_L30_001E1350;
extern u8 D_L30_001E9020[];
extern void *func_003C24B0(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003502D0();
extern void func_L03_0034B218(void *, s32, s32, f32, s32, void *);
extern s32 func_L30_0034DB30(void *);
extern void func_L01_004450F0(void *, s32, s32);

void *func_L30_00350DB0(u8 *moby, f32 f) {
    u8 *n;
    u8 *vars;
    f32 t;
    s32 flag;
    n = func_003C24B0(0x1679, 0x80);
    if (n == 0) {
        return 0;
    }
    *(q_00350DB0 *)(n + 0x10) = *(q_00350DB0 *)moby;
    n[0x30] = 0xFF;
    *(u16 *)(n + 0x32) = 0x40;
    *(f32 *)(n + 0x2C) = D_L30_001DD748 * *(f32 *)(*(u8 **)(n + 0x24) + 0x24);
    vars = *(u8 **)(n + 0x68);
    *(f32 *)vars = f;
    *(s32 *)(vars + 0x10) = -1;
    *(f32 *)(vars + 0x30) = func_0038D098(f) * D_L30_001DD750;
    t = func_0038D0B0(*(f32 *)vars) * D_L30_001DD750;
    flag = D_L30_001DD744;
    *(s32 *)(vars + 0x34) = 0;
    *(f32 *)(vars + 0x38) = t;
    if (flag == 0) {
        D_L30_001DD744 = 1;
        func_L03_0034B218(D_L30_001E1340, D_L30_001DD820, D_L30_001DD824, D_L30_001DD848, D_L30_001DD84C, func_003502D0);
        D_L30_001E1350 = 0x44;
    }
    if (func_L30_0034DB30(n)) {
        *(q_00350DB0 *)(n + 0x10) = *(q_00350DB0 *)D_L30_001E9020;
        func_L01_004450F0(n, 1, -1);
    } else {
        func_L01_004450F0(n, 0, -1);
    }
    return n;
}

INCLUDE_ASM("asm/levels", func_L30_00350DB0);
