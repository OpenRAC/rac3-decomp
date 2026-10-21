/* US draft of func_003BDCF0 (rac3-uya-decomp func_003BDC00, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003BDA80. */


/* localdecomp:start func_003BDCF0 */
/* MATCH */
typedef int u128_3B8440 __attribute__((mode(TI)));
__asm__(".extern D_001DA2BC, 4");
__asm__(".extern D_001DA2B0_003BDCF0, 4");
extern s32 D_001DA2A0_003BDCF0[2];
extern f32 D_001DA2BC;
extern s32 D_001DA2B0_003BDCF0;
extern f32 D_001DA2B4_003BDCF0;
extern f32 D_001DA2B8_003BDCF0;
extern void func_003BDA80(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C3310_003BDCF0(void *, s32, void *);
extern void func_0038DE98(f32, f32);
extern f32 func_0038D490(f32);
extern void func_0038A140(void (*)(), s32);
extern void func_003BDB18(void);
void func_003BDCF0(u8 *p) {
    u128_3B8440 v;
    s32 k;
    s32 m;
    f32 f;
    *(u16 *)(p + 0x34) |= 0x10;
    func_003BDA80(p, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
    k = *(s16 *)(p + 0xAA);
    if (k == 10) m = 1; else { s32 e = k ^ 0x259; m = e ? 0 : 8; }
    func_003C3310_003BDCF0(p, m, &v);
    f = ((f32 (*)(f32, f32))func_0038DE98)(D_001DA2BC, 0.06690429151058197f);
    D_001DA2BC = f;
    f = (func_0038D490(f) * 0.5f + 0.5f) * 13.0f;
    *(u128_3B8440 *)D_001DA2A0_003BDCF0 = v;
    D_001DA2B4_003BDCF0 = 0.04f;
    D_001DA2B8_003BDCF0 = 0.07f;
    D_001DA2B0_003BDCF0 = (((s32)f + 0x17) << 24) | 0xC0;
    func_0038A140(func_003BDB18, (s32)p);
}
/* localdecomp:end func_003BDCF0 */
