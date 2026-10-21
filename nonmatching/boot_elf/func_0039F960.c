/* Near miss of func_0039F960 with its file's own flags: tools/check.py reports 3 diff
   (the US draft it started from: 7).
   What differs: 3 diffs, all one thing: the `$ra` save is scheduled before the flag load
   instead of after it (mine: `addiu $sp,-0x10` / `sd $ra,($sp)` / `lui $v0,0x1d` / `lbu
   $v0,0x5550($v0)`; retail: `addiu $sp,-0x10` / `lui $v0,0x1d` / `lbu $v0,0x5550($v0)` / `sd
   $ra,($sp)`); everything else already matches - the one-register load `lui $v0,0x1d`+`lbu
   $v0,0x5550($v0)`, r in $v1, the delay slot `move $v1,$zero`, `jal func_0039F940`, `sltu
   $v1,$zero,$v0`, the epilogue and the 52-byte size. Root cause of the address form: retail
   reads the byte through a bare symbol reference (one register), which GCC only...
*/

/* US draft of func_0039F960 (rac3-uya-decomp func_0039F848, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override).

   The retail loads the flag byte with a bare symbol reference (`lui $v0,%hi(D_001D5550)` +
   `lbu $v0,%lo(D_001D5550)($v0)`, one register). With the file's flags GCC only emits that
   one-register form when the address is a constant; `D_001D5550[0]` compiles to plus(sym,0),
   which GCC splits over two registers, and a scalar redeclaration of D_001D5550 conflicts
   with the file's own `extern u8 D_001D5550[];` (the checker rejects it), so the byte is
   read through its PAL address. The only difference left is where the $ra save is scheduled. */


/* localdecomp:start func_0039F960 */
extern u8 D_001D5550[];
extern s32 func_0039F940();
s32 func_0039F960(void) {
    s32 r = 0;
    if (*(u8 *)0x001D5550 != 0) r = func_0039F940() != 0;
    return r;
}
/* localdecomp:end func_0039F960 */
