/* US draft of func_003D8FC0 (rac3-uya-decomp func_003D3A50, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003D8FC0 */
__asm__(".extern D_001D5634_003D8FC0, 4");
extern s32 D_001D5600_003D8FC0;
extern s32 D_001D5604_003D8FC0;
extern s32 D_001D5628_003D8FC0;
extern s32 D_001D5630_003D8FC0;
extern s32 D_001D5634_003D8FC0;
extern s32 D_001D55F8_003D8FC0;
extern u8 D_001D3650_003D8FC0[];
extern void func_003D72B0(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7850();
void func_003D8FC0(void) {
    u8 *p;
    unsigned long *q = (unsigned long *)D_001D3650_003D8FC0;
    q[0] = 0x5000000000000001UL;
    q[1] = 0xEEEEEEEEEEEEEEEEUL;
    q[2] = 0;
    q[3] = 0x3F;
    q[4] = 0xA0000000A0UL;
    q[5] = 0x19;
    q[6] = 0x100000000UL;
    q[7] = 0x4F;
    q[8] = 0x60;
    q[9] = 0x15;
    q[10] = 5;
    q[11] = 9;
    p = D_001D3650_003D8FC0 + 0x60;
    func_003D72B0(&p, D_001D5630_003D8FC0, D_001D5600_003D8FC0, D_001D5604_003D8FC0, D_001D5628_003D8FC0, 0x100, 0x100);
    func_003D7850(&p, D_001D5628_003D8FC0, D_001D5634_003D8FC0);
    func_003D7850(&p, D_001D5628_003D8FC0, D_001D5634_003D8FC0);
    D_001D55F8_003D8FC0 = p - D_001D3650_003D8FC0;
}
/* localdecomp:end func_003D8FC0 */
