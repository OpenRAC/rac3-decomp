/* US draft of func_003C24B0 (rac3-uya-decomp func_003BCFB0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003BD0D8. */


/* localdecomp:start func_003C24B0 */
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0x47]; s32 f68; u8 p6c[0x34]; u32 fA0; u8 pa4[0x5C]; } O_3BCFB0;
__asm__(".extern D_001DA4A0, 16");
__asm__(".extern D_001DA4A4, 16");
__asm__(".extern D_001D9D00, 16");
__asm__(".extern D_001DA3C0, 16");
extern u32 D_001DA4A0;
extern u32 D_001DA4A4;
extern s32 D_001D9D00;
extern s32 D_001DA3C0;
extern volatile u8 D_001D90C8;
extern s32 func_003C7310();
extern void func_003BD0D8();
extern void func_0038CB78();
extern int func_003C38E0();
O_3BCFB0 *func_003C24B0(s32 a, s32 b) {
    O_3BCFB0 *p;
    O_3BCFB0 *end;
    s32 r;
    end = (O_3BCFB0 *)D_001DA4A4;
    p = (O_3BCFB0 *)D_001DA4A0;
    if (p < (O_3BCFB0 *)D_001DA4A4) do {
        if (p->f20 < 0xFE) continue;
        if ((u32)D_001D9D00 < p->fA0) continue;
        r = 0;
        if (b) r = func_003C7310(b);
        if (r == 0 && b) break;
        if (p->f20 == 0xFF) *((u8 *)p + 0x120) = p->f20;
        func_003BD0D8(p, a);
        p->f68 = r;
        if (b) func_0038CB78(r, 0, b);
        if (D_001DA3C0) D_001DA3C0 = D_001DA3C0 - 1;
        return p;
    } while (++p < (O_3BCFB0 *)D_001DA4A4);
    if (D_001D90C8) func_003C38E0();
    return 0;
}
/* localdecomp:end func_003C24B0 */
