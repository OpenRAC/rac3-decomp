/* US draft of func_00398BB8 (rac3-uya-decomp func_00393DC8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00398BB8 */
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8;
extern S_16C580_00393DC8 D_16C580;
extern S_160C40_00393DC8 D_160C40;
extern s32 D_002275F0[];
extern unsigned long D_0022CAD0[3];
__asm__(".extern D_001D5F30, 4");
extern s32 D_001D5F30;
extern void func_003A92F0(s32);
extern s32 func_003A26F0(s32, s32, s32);
extern void func_00399A48(s32, s32, void *, s32);
void func_00398BB8(s32 n) {
    S_160C40_00393DC8 *b;
    s32 h;
    D_16C580.f18 = n;
    func_003A92F0(1);
    b = &D_160C40;
    h = D_002275F0[0];
    func_003A26F0(h, b->e[n].a + b->f1284, b->e[n].b);
    D_0022CAD0[0] = D_16C580.f38;
    D_0022CAD0[1] = 0xFFA0000000E0;
    D_0022CAD0[2] = 0x40000400004000;
    func_00399A48(h, 0, &D_001D5F30, -1);
}
/* localdecomp:end func_00398BB8 */
