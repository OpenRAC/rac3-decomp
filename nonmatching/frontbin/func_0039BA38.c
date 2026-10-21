/* Near miss of func_0039BA38 with its file's own flags: tools/check.py reports 8 diff
   (the version it replaces: 39).
   What differs: All five address forms now match retail exactly (flag read `lui $a1,0x1d` +
   `lw $a1,0x4cec($a1)`, flag store `lui $at,0x1d` + `sw $v0,0x4cec($at)`, state store `lui
   $at,0x1d` + `sw $v0,0x4ce8($at)`, and both delay-slot stores `$gp` relative); what is left
   is the order of the first basic block: retail loads the flag word first (words 2-3) and then
   the struct base, ours builds the struct base first and loads the flag word at words 7-8, so
   the `and` also lands after `lw $a0,0x15c($a2)` instead of before it (8 of 40 words differ).
*/

/* PAL candidate for func_0039BA38 (frontbin), from the US draft of
   rac3-uya-decomp func_00396C48 (commit 13cf5c5).

   Retail reaches the flag word at 0x001D4CEC and the state word at 0x001D4CE8
   in two different address forms inside this one function: the read of the
   flag and the two stores that are not in a branch delay slot use the
   compiler's lui/%lo pair (the read with the high half in the destination
   register, the stores through $at), while the two stores that sit in a
   branch delay slot stay $gp relative.

   With this file's flags (split addresses) gcc only reaches a global through
   $gp, and it splits a global's address over two registers; retail's form
   (the high half in the register that holds the loaded word, $at for the
   stores) is what gcc builds for a plain constant address, the same trick
   func_0039AA38 in this file uses for *(s32 *)0x1D4C40 and the neighbouring
   functions of this file use for their flag words.  The two stores that sit
   in a branch delay slot keep the sized global, so the assembler leaves them
   $gp relative. */


/* localdecomp:start func_0039BA38 */
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_0039BA38[];
extern void (*D_001D62F8)();
extern s32 D_001D4CEC_g;
extern s32 D_001D4CE8_g;

void func_0039BA38(void) {
    s32 v;
    S_00396C48 *p;
    v = *(s32 *)0x001D4CEC & ~2;
    D_001D4CEC_g = v;
    p = D_00142430_0039BA38;
    if (p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                *(s32 *)0x001D4CEC = v | 0x440;
                D_001D4CE8_g = 0x18;
            } else {
                p->f17C = 1;
                *(s32 *)0x001D4CE8 = 1;
            }
            if (D_001D62F8 != 0) {
                D_001D62F8();
                D_001D62F8 = 0;
            }
        }
    }
}
/* localdecomp:end func_0039BA38 */
