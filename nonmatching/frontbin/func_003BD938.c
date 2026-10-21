/* US draft of func_003BD938 (rac3-uya-decomp func_003B8440, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BD938 */
/* MATCH */
typedef int u128_3B8440 __attribute__((mode(TI)));
__asm__(".extern D_001DA2BC, 4");
__asm__(".extern D_001DA2B0_003BD938, 4");
extern s32 D_001DA2A0_003BD938[2];
extern f32 D_001DA2BC;
extern s32 D_001DA2B0_003BD938;
extern f32 D_001DA2B4_003BD938;
extern f32 D_001DA2B8_003BD938;
extern void func_003B82C0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2F58_003BD938(void *, s32, void *);
extern void func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_00389D60(void (*)(), s32);
extern void func_003BD760(void);
void func_003BD938(u8 *p) {
    u128_3B8440 v;
    s32 k;
    s32 m;
    f32 f;
    *(u16 *)(p + 0x34) |= 0x10;
    func_003B82C0(p, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
    k = *(s16 *)(p + 0xAA);
    if (k == 10) m = 1; else { s32 e = k ^ 0x259; m = e ? 0 : 8; }
    func_003C2F58_003BD938(p, m, &v);
    f = ((f32 (*)(f32, f32))func_0038DAB8)(D_001DA2BC, 0.06690429151058197f);
    D_001DA2BC = f;
    f = (func_0038D0B0(f) * 0.5f + 0.5f) * 13.0f;
    *(u128_3B8440 *)D_001DA2A0_003BD938 = v;
    D_001DA2B4_003BD938 = 0.04f;
    D_001DA2B8_003BD938 = 0.07f;
    D_001DA2B0_003BD938 = (((s32)f + 0x17) << 24) | 0xC0;
    func_00389D60(func_003BD760, (s32)p);
}
/* localdecomp:end func_003BD938 */
