/* Near miss of func_003931D0 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 41).
   What differs: 7 instructions still differ, all in the `D_00142430` (S_38E5B8) pointer block,
   and only in register choice: retail computes the address as `lui $v0, 0x14` / `addiu $a0,
   $v0, 0x2430` and uses $a0 as the base (`lw $v1, 0x17c($a0)`, `sw $zero, 0x17c($a0)`, `lh
   $v0, 0x18($a0)`, `sh $a1, 0x18($a0)`), while this C gives `lui $v1, 0x14` / `addiu $v1, $v1,
   0x2430` and uses $v1 as the base (`lw $v0, 0x17c($v1)`, ...). Everything else matches byte
   for byte: the `lui/lo` accesses to D_001D545C, D_001D4CF0 and D_001D4CEC (declared as
   unsized arrays so they are never small data) and the `$gp` accesses...
*/

/* func_003931D0: retail reaches D_001D545C, D_001D4CF0 and D_001D4CEC through
   lui/lo, so they are declared as unsized arrays (never small data, so never
   $gp-relative), while D_001D5B74 and D_001D9D04 stay sized scalars and are
   reached through $gp.  Every access gets its own alias at the same address:
   two accesses to one array element make the compiler build the address once
   and keep it in a register (in $s1 here), which retail does not do. */

/* localdecomp:start func_003931D0 */
extern s32 D_001D545C_003931D0[];
extern s32 D_001D4CF0_003931D0[];
extern s32 D_001D4CF0_r_003931D0[];
extern s32 D_001D4CEC_r_003931D0[];
extern s32 D_001D4CEC_w_003931D0[];
void func_003931D0(s32 a, s32 b) {
    s32 x = a;
    s32 y;
    S_38E5B8 *p;
    func_00393120(&x);
    y = x;
    D_001D5B74 = 1;
    D_001D4CF0_003931D0[0] = D_001D545C_003931D0[0];
    D_001D9D04 = y;
    if (y == -1) {
        p = D_00142430_003931D0;
        if (p->x17C != 0) p->x17C = 0;
        if (p->h18 >= 0) p->h18 = y;
        D_001D4CEC_w_003931D0[0] = D_001D4CEC_r_003931D0[0] & ~0x200;
    }
    if (b != 0) {
        func_003932D0();
        if (x != 0x18) func_0039F008(0, D_001D9D04);
        else func_0039F008(0, D_001D4CF0_r_003931D0[0]);
    }
}
/* localdecomp:end func_003931D0 */
