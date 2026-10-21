/* Near miss of func_00389B10 with its file's own flags: tools/check.py reports 8 diff
   (the version it replaces: 55).
*/

/* PAL candidate for func_00389B10 (frontbin, src/frontbin/382380.c).
   The retail reaches D_001DA050 and D_001D4BB0 through lui/lo (the address and
   the value in the same register) everywhere except the two branch delay slots,
   which use $gp: an assembler expands a $gp access of a symbol it knows is not
   small data, and it cannot expand a two-instruction access in a delay slot.
   The file's own matched functions (func_00384AC8, func_00384BB8) use the same
   size hint to get the same effect, so the declarations below keep the natural
   sized type and the .extern hint tells the assembler the symbol is not small.
   The _00389B10 names are the same addresses read through a name the assembler
   still believes is small, so that the two delay-slot accesses can stay $gp. */

/* localdecomp:start func_00389B10 */
extern s32 D_001D4BB0; __asm__(".extern D_001D4BB0, 16");
extern s32 D_001D4BB0_00389B10;
extern s32 D_001DA050;
extern s32 D_001DA050_00389B10; __asm__(".extern D_001DA050_00389B10, 16");
extern u8 D_003353C0[];
extern u8 D_00335430[];
extern void func_0038CC88();
extern void func_003A9618();
s32 func_00389B10(s32 a, s32 p, s32 q, s32 type) {
    s32 e = p - 6;
    s32 v;
    s32 h;
    s32 r;
    u8 *d;
    if (e < 0) e = 0;
    v = (1 << (p + q)) >> 4;
    e = 1 << e;
    if (type == 0x14) {
        v = (1 << (p + q)) >> 5;
        func_0038CC88(D_001DA050_00389B10, D_003353C0, 0x70);
        h = D_001D4BB0_00389B10;
    } else {
        func_0038CC88(D_001DA050_00389B10, D_00335430, 0x70);
        h = D_001D4BB0;
    }
    r = h >> 8;
    D_001D4BB0 = h + (v << 4);
    d = (u8 *)D_001DA050_00389B10;
    *(u8 *)(d + 0x26) = e;
    *(s32 *)(d + 0x64) = a;
    *(s16 *)(d + 0x24) = r;
    *(s32 *)(d + 0x30) = 1 << p;
    *(s32 *)(d + 0x34) = 1 << q;
    *(s32 *)(d + 0x50) = v | 0x8000;
    *(s32 *)(d + 0x60) = v | 0x30000000;
    *(s32 *)(d + 0x6C) = v | 0x50000000;
    D_001DA050 = D_001DA050_00389B10 + 0x70;
    func_003A9618();
    return r;
}
/* localdecomp:end func_00389B10 */
