/* Near miss of func_003DA0A8 with its file's own flags: tools/check.py reports 12 diff
   (the version it replaces: 37).
   What differs: Fixed vs the draft: the call target is func_003DA1E0 (PAL address of the US
   func_003DA098), and the two globals retail reaches with %hi/%lo (0x1D4BB4 and 0x1DA050) are
   declared as unsized arrays (per-function aliases D_001D4BB4_00389620,
   D_001DA050_003A97F8/_00388348/_00389620) so gcc addresses them absolutely instead of via
   $gp; the copy and the pointer bump also use separate aliases so gcc does not cache one
   address in $s0 across the calls. Still 12 instructions differ, all register allocation:
   retail materialises the %hi into the load's destination register (`lui $v0, %hi(D_X); lw
   $v0,...
*/

/* PAL candidate for func_003DA0A8 (boot_elf, src/boot_elf/text/3D9730.c).
   The US draft is the starting point; the PAL bytes need:
   - the call to go to func_003DA1E0 (the PAL address of the US func_003DA098);
   - the globals the retail reaches with %hi/%lo (0x1D4BB4 and 0x1DA050) declared
     as unsized arrays, so the compiler addresses them absolutely instead of
     through $gp (a sized scalar of 8 bytes or less would be gp-relative);
     each access gets its own alias so gcc does not keep one address in a
     register across the calls. */

/* localdecomp:start func_003DA0A8 */
extern s32 D_001D4BB4_00389620[];
void func_0038D108(s32, s32 *, s32);
void func_003A9348(s32 *);
extern void func_003A97F8(s32, unsigned long);
void func_003DA1E0();
void func_003DB148();
void func_003DC518();
void func_003DD258();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003DA0A8;
extern u8 D_001D7960[];
extern u32 D_001DA050_003A97F8[];
extern u32 D_001DA050_00388348[];
extern u32 D_001DA050_00389620[];
extern u8 D_100AE0[];
extern u8 D_1159B0[];

void func_003DA0A8(void) {
    func_003A97F8(0x47, 0x5340B);
    D_001D4BB0_003DA0A8 = D_001D4BB4_00389620[0];
    func_11F0A0(0);
    func_003DA1E0();
    func_003D9FB8();
    func_11F0A0(0);
    func_003DD258();
    func_003A9348(D_1159B0);
    func_003DB148();
    func_003DC518();
    func_003A9348(D_100AE0);
    func_0038D108(D_001DA050_003A97F8[0], D_001D7960, 0x20);
    D_001DA050_00389620[0] = D_001DA050_00388348[0] + 0x20;
}
/* localdecomp:end func_003DA0A8 */
