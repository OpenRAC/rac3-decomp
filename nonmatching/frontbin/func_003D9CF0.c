/* Near miss of func_003D9CF0 with its file's own flags: tools/check.py reports 6 diff
   (the version it replaces: 37).
   What differs: Retail rebuilds the D_001DA050_003D9CF0 address at every use: `lui $v0, 0x1e`
   + `lw $v0, -0x5fb0($v0)` for the reload and `lui $at, 0x1e` + `sw $v0, -0x5fb0($at)` for the
   store (address materialised in the destination / in $at). The candidate still emits `lui
   $v1, 0x1e` + `lw $v0, -0x5fb0($v1)` and `lui $a0, 0x1e` + `sw $v0, -0x5fb0($a0)`: with an
   unsized-alias declaration gcc uses its own %hi pseudo, which lands in a different register
   than the load destination, and with a constant address gcc CSEs the three uses of 0x001DA050
   into one shared address register (lui+ori, $s0) instead of...
*/

/* Candidate for func_003D9CF0 (PAL retail, file flags -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division).

   Changes against the US draft:
   - the US callee func_003D48D8 is PAL func_003D9E28.
   - PAL retail reaches D_001D4BB4 and D_001DA050_003D9CF0 with lui/lw and
     lui/sw, never through $gp. A constant address gets gcc to fold the low
     half into the load offset and to materialise the address in the
     destination register (lui $v0; lw $v0, %lo($v0)), which is exactly what
     retail does for those two reads.
   - the reload and the store of D_001DA050_003D9CF0 use two unsized aliases
     (never small data, so always lui) at the same address, so gcc rebuilds
     the address for each of them instead of sharing one across the call.
   - D_001D4BB0_003D9CF0 stays a sized scalar: retail stores it through $gp. */

extern s32 D_001DA050_003D9CF0_h[];
extern s32 D_001DA050_003D9CF0_i[];
void func_0038CD28(s32, s32 *, s32);
void func_003A8F90(s32 *);
extern void func_003A9440(s32, unsigned long);
void func_003D9C00();
void func_003D9E28();
void func_003DAD90();
void func_003DC160();
void func_003DCEA0();
void func_11F0A0(s32);
extern s32 D_001D4BB0_003D9CF0;
extern u8 D_001D7960[];
extern u8 D_100AE0[];
extern u8 D_1159B0[];

void func_003D9CF0(void) {
    func_003A9440(0x47, 0x5340B);
    D_001D4BB0_003D9CF0 = *(s32 *)0x001D4BB4;
    func_11F0A0(0);
    func_003D9E28();
    func_003D9C00();
    func_11F0A0(0);
    func_003DCEA0();
    func_003A8F90(D_1159B0);
    func_003DAD90();
    func_003DC160();
    func_003A8F90(D_100AE0);
    func_0038CD28(*(s32 *)0x001DA050, D_001D7960, 0x20);
    D_001DA050_003D9CF0_i[0] = D_001DA050_003D9CF0_h[0] + 0x20;
}
