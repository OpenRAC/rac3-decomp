/* Near miss of func_0039A530 with its file's own flags: tools/check.py reports 10 diff
   (the version it replaces: 16).
   What differs: the global at 0x1D4B50 now gets retail's lui/lo addressing (write via a
   literal address -> `lui $at; sw 0x4b50($at)`, reload via an unsized alias), but gcc keeps
   the reload's high half in $a1 (`lui $a1,0x1d; lw $v0,0x4b50($a1)`) where retail has it in
   the destination (`lui $v0,0x1d; lw $v0,0x4b50($v0)`); that also shifts the two constants
   (retail $a1/$a2, ours $a2/$t0). 10 words differ.
*/

/* PAL candidate for func_0039A530 (US draft rac3-uya-decomp func_0039A418).
   Retail reaches the global at 0x1D4B50 with lui/lo (every one of its users
   does), never through $gp: it is not small data, so a sized declaration
   (which lets gcc address it through $gp) cannot reproduce retail. The write
   uses the literal address, which gcc splits as lui $at + sw lo($at), and
   the reload uses the unsized alias, whose high half gcc keeps in the
   destination register (docs/us/permuter_todo.md,
   docs/wiki/Matching-Patterns.md, "Globals: gp vs lui"). */


/* localdecomp:start func_0039A530 */
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_0039A530_u[];
extern u8 D_01FF7FF0[];
extern s32 func_003A2A80();
s32 func_0039A530(void) {
    S_395360 *s = &D_00160C40;
    u32 x;
    s32 *p;
    s32 *q;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_01FF7FF0 - x) & -16);
    *(s32 *)0x001D4B50 = (s32)p;
    *p = 0x60;
    q = D_001D4B50_0039A530_u[0];
    func_003A2A80((s32)q + q[0], s->f668 + s->f64C, s->f66C);
    return 1;
}
/* localdecomp:end func_0039A530 */
TEXT_PADDING(2);
