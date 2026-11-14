#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BD360 */
extern u8 *D_L09_0021E640[];
__asm__(".extern D_L09_0021E640, 16");

s32 func_L09_003BD360(s32 a0, s32 a1, s8 *a2, s32 *a3) {
    u8 *p1;
    u8 *p2;
    f32 d;
    p1 = D_L09_0021E640[a3[a0]] + (a1 << 4);
    p2 = D_L09_0021E640[a3[a2[2]]] + (a2[3] << 4);
    d = fabs_asm(*(f32 *)(p1 + 0x10) - *(f32 *)(p2 + 0x10));
    d = d + fabs_asm(*(f32 *)(p1 + 0x14) - *(f32 *)(p2 + 0x14));
    return (s32)d;
}
/* localdecomp:end func_L09_003BD360 */

INCLUDE_ASM("asm/levels", func_L09_003BD3E8);

INCLUDE_ASM("asm/levels", func_L09_003BD560);

/* localdecomp:start func_L09_003BD860 */
s32 func_L09_003BD860(void *arg0) {
    s32 var_a0;
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    var_a0 = 1;
    if (!(((*(f32 *)((u8 *)temp_v0 + 0x30)) + 1.0f) <= ((f32) (*(s16 *)((u8 *)temp_v0 + 0x34)) * (*(f32 *)((u8 *)temp_v0 + 0xD4C))))) {
        var_a0 = 0;
    }
    return var_a0;
}
/* localdecomp:end func_L09_003BD860 */

INCLUDE_ASM("asm/levels", func_L09_003BD8A8);

INCLUDE_ASM("asm/levels", func_L09_003BDB90);

INCLUDE_ASM("asm/levels", func_L09_003BDED0);

/* localdecomp:start func_L09_003BE168 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);

void func_L09_003BE168(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 loc[3];
    u8 *s;

    pos = *(vu0_v4 *)(a0 + 0x10);
    s = *(u8 **)(a0 + 0x68);
    off.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 2.0f;
    off.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 2.0f;
    off.z = 1.5f;
    vec_add_ab(&pos, &pos, &off);
    func_L01_00446748(loc, a0, 0x10001, (f32)s[0x44]);
    func_003D4D00(&pos, 0, a0, loc, 3.0f);
}
/* localdecomp:end func_L09_003BE168 */

INCLUDE_ASM("asm/levels", func_L09_003BE228);
