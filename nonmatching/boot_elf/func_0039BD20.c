/* Near miss of func_0039BD20 with its file's own flags: tools/check.py reports 4 diff
   (the version it replaces: 7).
   What differs: Only the head's 4 instructions differ (the tail matches byte for byte): retail
   has `lui $v0,%hi(D_00142438)` / `addiu $a0,2` / `lw $v1,%lo(D_00142438)($v0)` / `beq
   $v1,$a0`, we get `lui $v1,0x14` / `lw $v1,0x2438($v1)` / `addiu $v0,2` / `beq $v1,$v0`.
   Cause: the file's `-mno-split-addresses` makes gcc emit one instruction `lw $v1,D_00142438`
   (R_MIPS_32), which the assembler expands reusing the destination register, so the address
   half and the loaded value can never be in two different registers and the constant 2 can
   never be materialised between the lui and the lw; the retail shape is...
*/

/* PAL candidate for func_0039BD20.
   The store target is the file's own unsized-array D_001D4CE8 (unknown size =>
   never small data => lui $at / sw, as in retail); the draft's scalar
   D_001D4CE8_0039BD20 would be $gp-relative under the file's -G8.
   The comparison reads the file's unsized-array D_00142438. */

extern s32 D_00142438[];
extern s32 D_001D4CE8[];

void func_0039BD20(void) {
    if (D_00142438[0] != 2) D_001D4CE8[0] = 4;
}
