/* Near miss of func_00382B20 with its file's own flags: tools/check.py reports 16 diff
   (the version it replaces: 40).
   What differs: Addressing of both globals is now right (lui/addiu as in retail, the $gp form
   is gone: 38 -> 16 diffs). What still differs: gcc materialises the base address of
   D_001D9A80 in its split-address form (`lui $v0` then `addiu $s4, $v0, -0x6580`, the lo half
   written into the callee-saved register) whereas retail materialises the whole address into
   $v0 (`lui $v0, 0x1e` + `addiu $v0, $v0, -0x6580`) and copies it to $s4 (`move $s4, $v0`);
   that single difference shifts the whole prologue (save order $s1/$s4, placement of `move
   $s3, $a0`, the lui/addiu of D_001D9A40) and adds one nop of loop...
*/

/* Candidate for func_00382B20 (PAL retail, frontbin).
   Retail forms the addresses of D_001D9A80 and D_001D9A40 with lui/addiu, while a
   declaration of 8 bytes or less (-G8) makes the compiler reach them through $gp.
   An unsized array is never small data, so it always gets lui; the plain names are
   declared sized (8 bytes) in the source file and the checker puts those
   declarations in front of this candidate, hence the per-function aliases below:
   same addresses, declared unsized, so they are never small data.
   D_001D9A80 is named once, so the compiler keeps the whole address in one register
   instead of splitting it into a hi part plus two lo parts, as retail does. */

/* localdecomp:start func_00382B20 */
extern s32 D_001D9A80_00382B20[];
extern void (*D_001D9A40_00382B20[])(s32);
void func_00382B20(s32 a) {
    s32 i;
    s32 *c = D_001D9A80_00382B20;
    for (i = 0; i < c[a]; i++) D_001D9A40_00382B20[a * 16 + i](a);
    c[a] = 0;
}
/* localdecomp:end func_00382B20 */
