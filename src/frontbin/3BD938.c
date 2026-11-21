#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern f32 func_0038D0B0(f32);
typedef int u128_3B8440 __attribute__((mode(TI)));
extern s32 D_001DA2A0_003BD938[2];
extern f32 D_001DA2BC;
extern s32 D_001DA2B0_003BD938;
extern f32 D_001DA2B4_003BD938;
extern f32 D_001DA2B8_003BD938;
extern void func_003C2F58_003BD938(void *, s32, void *);
extern void func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_00389D60(void (*)(), s32);
extern void func_003BD760(void);
/* localdecomp:start func_003BD938 */
/* func_003BD938 log: US draft (rac3-uya-decomp func_003B8440); declarations the file already has removed;
   func_003B82C0 is PAL func_003BD7A0; the angle step is 0x3DA46C8B on PAL (US step x 1.2). */
__asm__(".extern D_001DA2BC, 4");
__asm__(".extern D_001DA2B0_003BD938, 4");
extern void func_003BD7A0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003BD938(u8 *p) {
    u128_3B8440 v;
    s32 k;
    s32 m;
    f32 f;
    *(u16 *)(p + 0x34) |= 0x10;
    func_003BD7A0(p, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
    k = *(s16 *)(p + 0xAA);
    if (k == 10) m = 1; else { s32 e = k ^ 0x259; m = e ? 0 : 8; }
    func_003C2F58_003BD938(p, m, &v);
    f = ((f32 (*)(f32, f32))func_0038DAB8)(D_001DA2BC, 0.0802851543f);
    D_001DA2BC = f;
    f = (func_0038D0B0(f) * 0.5f + 0.5f) * 13.0f;
    *(u128_3B8440 *)D_001DA2A0_003BD938 = v;
    D_001DA2B4_003BD938 = 0.04f;
    D_001DA2B8_003BD938 = 0.07f;
    D_001DA2B0_003BD938 = (((s32)f + 0x17) << 24) | 0xC0;
    func_00389D60(func_003BD760, (s32)p);
}
/* localdecomp:end func_003BD938 */
