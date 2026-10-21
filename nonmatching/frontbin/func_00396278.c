/* US draft of func_00396278 (rac3-uya-decomp func_00391A18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00396278 */
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern s32 func_00396968();
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];
s32 func_00396278(O_91A18 *o) {
    s32 x, y, h;
    x = o->w50;
    y = o->w54;
    o->w58 = 0x100;
    o->w5C = 0x40;
    func_00393620(o, &x, &y);
    func_00393690(o, &x, &y, o->w6C, 0);
    h = o->w74 * 0xDD / o->w8 + 0x1B;
    func_003970D8(func_00396968(0x7558, 1), x, y, h, 0x40, 0x80);
    func_00396C60(func_00396968(0x7558, 0), x, y, 0x100, 0x40, 0x80);
    func_00396C60(func_00396968(0x7558, 2), x, y, 0x20, 0x20, D_001A666A[0] == 0 ? 0 : 0x80);
    return o->w58;
}
/* localdecomp:end func_00396278 */
