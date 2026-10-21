/* US draft of func_003AFC48 (rac3-uya-decomp func_003AFAA8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003AFC48 */
extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA09C_003AFC48;
extern s32 D_001DA0B0_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern s32 D_001DA0C0[];
extern s32 D_001D4D40;
extern void func_00391880();
extern s32 func_003AFE10();
extern void func_003B0360();
extern void func_003B0188();
s32 func_003AFC48(s32 a, s32 b, s32 (*alloc)(s32, s32), s32 c, s32 flag) {
    s32 i;
    s32 *p;
    s32 r;
    D_001DA08C = alloc(0x1A0000, 0x40);
    p = D_001DA0C0;
    D_001DA090 = alloc(0x4FC80, 0x40);
    D_001DA094 = alloc(0x1010, 0x40);
    D_001DA088_003AFC48 = alloc(0x14, 0x40);
    D_001DA098 = alloc(0xEC800, 0x40);
    D_001DA09C_003AFC48 = alloc(0x5000C, 0x40);
    D_001DA0A0 = alloc(0xC000, 0x40);
    D_001DA0A4 = alloc(0x80000, 0x40);
    D_001DA0A8 = alloc(0x4000, 0x40);
    D_001DA0AC = alloc(0x3000, 0x40);
    D_001DA0B0_003AFC48 = alloc(0xC, 0x40);
    D_001DA0B4_003AFC48 = alloc(0xB8, 0x40);
    D_001DA0B8_003AFC48 = alloc(0x68, 0x40);
    for (i = 1; i >= 0; i--) {
        *p++ = alloc(0x4000, 0x80);
    }
    func_00391880(flag != 0, flag != 0);
    func_003B0188(a, b, c);
    r = func_003AFE10(D_001DA0B4_003AFC48, D_001DA09C_003AFC48, D_001DA0B0_003AFC48);
    func_003B0360();
    D_001D4D40 = D_001D4D40 & ~0x80;
    return r;
}
/* localdecomp:end func_003AFC48 */
