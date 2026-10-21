/* Near miss of func_003D8500 with its file's own flags: tools/check.py reports 19 diff
   (the version it replaces: 47).
   What differs: nothing differs
*/

/* PAL candidate for func_003D8500.

   Retail (built with SN's Ps2EeAs) reaches D_001D5608, D_001D5620, D_001D561C and
   D_001D55F4 through lui/lo, while D_001D9360 and the D_001D5620 read that sits in the
   delay slot of the call to func_003D7850 go through $gp.  With the default assembler
   the size hint decides the address form, so the four lui/lo symbols get a 16-byte
   .extern hint (like func_003D9100 in this file) and the two $gp ones stay sized. */

__asm__(".extern D_001D5608_003D8500, 16");
__asm__(".extern D_001D5620_003D8500, 16");
__asm__(".extern D_001D561C_003D8500, 16");
__asm__(".extern D_001D55F4, 16");

extern s32 D_001D5608_003D8500, D_001D5620_003D8500, D_001D561C_003D8500, D_001D9360, D_001D55F4;
extern s32 D_001D5620;
extern u8 D_001D2A50[];
extern void func_003D72B0(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7850();
extern void func_003D6BC0(u8 **, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_003D8500 */
void func_003D8500(void) {
    u8 *p = D_001D2A50;
    func_003D72B0(&p, D_001D5608_003D8500, 0x40, 0x40, D_001D5620_003D8500, 0x80, 0x80);
    func_003D72B0(&p, D_001D5620_003D8500, 0x80, 0x80, D_001D561C_003D8500, 0x100, 0x100);
    func_003D7850(&p, D_001D561C_003D8500, D_001D5620);
    func_003D6BC0(&p, D_001D561C_003D8500, 0x100, 0x100, 1, 0, D_001D9360);
    D_001D55F4 = p - D_001D2A50;
}
/* localdecomp:end func_003D8500 */
