/* Near miss of func_0039F580 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 7).
   What differs: 3 diffs left, all one issue: gcc schedules the `$ra` save (`sd $31, 0($sp)`)
   second (right after the frame setup) while retail has it after the flag load (`addiu
   $sp,-0x10; lui $v0,0x1d; lbu $v0,0x5550($v0); sd $31,0($sp); beqz ...`). Reading the flag
   through the constant address 0x1D5550 is required to get retail's one-register address form
   (`lui $v0; lbu $v0,0x5550($v0)`) - a symbol reference (`D_001D5550[0]`, `*(u8 *)D_001D5550`,
   or a typed struct alias) splits across $v1/$v0 in this file's split-address mode (7 diffs),
   which is what the US build avoided with `-mno-split-addresses`....
*/

/* func_0039F580 — PAL retail 0x39F580 (52 bytes).
   Retail forms the address of the flag byte in one register (lui $v0 / lbu $v0),
   so the flag is read through the constant address 0x1D5550: with this file's
   flags (split addresses) a symbol reference splits across $v1/$v0 instead.
   Everything else (registers $v0/$v1, the sltu compare, the delay slots) matches. */

extern s32 func_0039F560();

s32 func_0039F580(void) {
    s32 r = 0;
    if (*(u8 *)0x1D5550 != 0) r = func_0039F560() != 0;
    return r;
}
