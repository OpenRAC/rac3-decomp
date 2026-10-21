/* Near miss of func_003CE2C0 with its file's own flags: tools/check.py reports 48 diff
   (the version it replaces: 68).
   What differs: The tail (second half) and the whole first block's instruction order now match
   retail (the local pointer `p` makes the compiler emit `addiu $v0, $v0, 0x10` in place and
   schedule the D_001DA604 store before the increment, and the D_001DA600 stores land in
   retail's order/registers: v1 for [0], a0 for [1], v0 for the value, v1 for [2], v0 for [3]).
   Still different: the call argument `func_003A02E8(D_001DA600)` is re-loaded after the
   D_001DA600[2]/[3] stores (gcc kills the load across the stores through that pointer), so an
   extra `lui $a0 / lw $a0` pair appears, the `jal` lands after `sw...
*/

/* Candidate for func_003CE2C0 (PAL retail). US draft as base, with the first
   block's pointer arithmetic going through a local so that the compiler
   updates it in place (retail: addiu $v0, $v0, 0x10, with the D_001DA604
   store scheduled before the increment, and no second register needed for
   D_001DA050). */


/* localdecomp:start func_003CE2C0 */
extern u32 *D_001DA050_003CE2C0;
extern u32 *D_001DA600_003CE2C0;
extern u32 *D_001DA604_003CE2C0;
extern s32 D_001D4BB0_003CE2C0;
extern s32 D_001D4BB4_003CE2C0;
__asm__(".extern D_001DA600_003CE2C0, 16");
__asm__(".extern D_001DA050_003CE2C0, 16");
__asm__(".extern D_001DA604_003CE2C0, 16");
__asm__(".extern D_001D4BB0_003CE2C0, 16");
__asm__(".extern D_001D4BB4_003CE2C0, 16");
extern void func_003A02E8();
extern s32 func_003A9618();
void func_003CE2C0(void) {
    u32 *p = D_001DA050_003CE2C0;
    D_001DA604_003CE2C0 = (u32)p;
    p += 4;
    D_001DA050_003CE2C0 = p;
    D_001DA600_003CE2C0[0] = 0x20000000;
    D_001DA600_003CE2C0[1] = (u32)D_001DA050_003CE2C0;
    D_001DA600_003CE2C0[2] = 0;
    D_001DA600_003CE2C0[3] = 0;
    func_003A02E8(D_001DA600_003CE2C0);
    func_003A9618();
    D_001DA050_003CE2C0[0] = 0x20000000;
    D_001DA050_003CE2C0[1] = (u32)(D_001DA600_003CE2C0 + 4);
    D_001DA050_003CE2C0[2] = 0;
    D_001DA050_003CE2C0[3] = 0;
    D_001DA050_003CE2C0 += 4;
    D_001DA604_003CE2C0[0] = 0x20000000;
    D_001DA604_003CE2C0[1] = (u32)D_001DA050_003CE2C0;
    D_001DA604_003CE2C0[2] = 0;
    D_001DA604_003CE2C0[3] = 0;
    D_001D4BB0_003CE2C0 = D_001D4BB4_003CE2C0;
}
/* localdecomp:end func_003CE2C0 */
