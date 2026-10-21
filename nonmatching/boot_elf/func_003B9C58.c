/* US draft of func_003B9C58 (rac3-uya-decomp func_003B9B80, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B9C58 */
__asm__(".extern D_001D8BBC, 4");
__asm__(".extern D_001D8BB8, 4");
__asm__(".extern D_001D8BC4, 4");
__asm__(".extern D_001D8BC8, 4");
__asm__(".extern D_001D8BCC, 4");
__asm__(".extern D_001D8BD0, 1");
__asm__(".extern D_001D8BDC, 4");
__asm__(".extern D_001D8BE0, 4");
extern void func_0038E530(s32);
extern s32 func_003823D0(s32);
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003AF7C0(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
extern f32 D_001DA074;
extern s32 D_001DA070;
void func_003B9C58(void) {
    s16 buf[16];
    s32 v;
    if (D_001D8BBC == 1) return;
    func_0038E530(1);
    switch (D_001D8BB8) {
    case 0: {
        char *a, *b, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        func_003914A0(buf, 0xF0, 0x1E0, D_001D8BDC, D_001D8BE0, 0x100, v, 0x10, 3);
        if ((a = (char *)D_001D8BC4) == 0) a = (char *)func_003823D0(0x8E2);
        if ((b = (char *)D_001D8BC8) == 0) b = (char *)func_003823D0(0x8DF);
        if ((c = (char *)D_001D8BCC) == 0) c = (char *)func_003823D0(0x17C);
        func_003AF7C0(buf, 0x8066CCFF, c, 1, 1, -1, 0, a, b, *(u8 *)&D_001D8BD0);
        break;
    }
    case 1: {
        char *a, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        func_003914A0(buf, 0xF0, 0x1E0, D_001D8BDC, D_001D8BE0, 0x100, v, 0x10, 3);
        if ((a = (char *)D_001D8BC4) == 0) a = (char *)func_003823D0(0x8E2);
        if ((c = (char *)D_001D8BCC) == 0) c = (char *)func_003823D0(0x17C);
        func_003AF7C0(buf, 0x8066CCFF, c, 1, 1, -1, 0, a, 0, *(u8 *)&D_001D8BD0);
        break;
    }
    }
}
/* localdecomp:end func_003B9C58 */
