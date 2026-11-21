#include "common.h"

/* NTSC-U counterpart of func_003BDCF0 (src/boot_elf/text/3BDCF0.c): phase step 0.0802851543f -> 0.0669042915f (60 Hz) */
/* localdecomp:start func_U_003BDC00 */
typedef int u128_3BDC00 __attribute__((mode(TI)));
extern s32 D_U_001DA320[2];
extern f32 D_U_001DA33C;
extern s32 D_U_001DA330;
extern f32 D_U_001DA334;
extern f32 D_U_001DA338;
extern void func_U_003C31F8(void *, s32, void *);
extern void func_U_0038DDE0(f32, f32);
extern f32 func_U_0038D3D8(f32);
extern void func_U_0038A0E8(void (*)(), s32);
extern void func_U_003BDA40(void);
__asm__(".extern D_U_001DA33C, 4");
__asm__(".extern D_U_001DA330, 4");
extern void func_U_003BDA80(void *, s32, s32, s32, s32, s32, s32, s32, s32);
void func_U_003BDC00(u8 *p) {
    u128_3BDC00 v;
    s32 k;
    s32 m;
    f32 f;
    *(u16 *)(p + 0x34) |= 0x10;
    func_U_003BDA80(p, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
    k = *(s16 *)(p + 0xAA);
    if (k == 10) m = 1; else { s32 e = k ^ 0x259; m = e ? 0 : 8; }
    func_U_003C31F8(p, m, &v);
    f = ((f32 (*)(f32, f32))func_U_0038DDE0)(D_U_001DA33C, 0.0669042915f);
    D_U_001DA33C = f;
    f = (func_U_0038D3D8(f) * 0.5f + 0.5f) * 13.0f;
    *(u128_3BDC00 *)D_U_001DA320 = v;
    D_U_001DA334 = 0.04f;
    D_U_001DA338 = 0.07f;
    D_U_001DA330 = (((s32)f + 0x17) << 24) | 0xC0;
    func_U_0038A0E8(func_U_003BDA40, (s32)p);
}
/* localdecomp:end func_U_003BDC00 */
