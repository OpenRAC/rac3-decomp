/* Near miss of func_0039B9B0 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 12).
*/

/* PAL candidate for func_0039B9B0.
   Retail reaches 0x1D4CEC three times with two different forms: the load and
   the last store use an absolute address (lui $a0 / lw $a0, lui $at / sw),
   while the store in the bne delay slot goes through $gp.  Under this file's
   flags gcc only emits that absolute shape for a constant address (a named
   global splits over two registers), so the two absolute accesses are written
   as casts of the literal address, and the delay-slot store keeps the sized
   global, which gcc puts in small data ($gp).  Same trick as func_0039B570
   and func_0039BA10 in this file. */

/* localdecomp:start func_0039B9B0 */
typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_0039B9B0;
extern s32 D_001D4CEC_0039B9B0;
extern s32 D_001D4CE8_0039B9B0;
void func_0039B9B0(void) {
    S_396BC0 *s;
    s32 f;
    f = *(s32 *)0x001D4CEC;
    f &= ~4;
    D_001D4CEC_0039B9B0 = f;
    s = &D_142430_0039B9B0;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            *(s32 *)0x001D4CEC = f | 0x40;
            D_001D4CE8_0039B9B0 = 0x16;
        } else {
            D_001D4CE8_0039B9B0 = s->f15C;
        }
    }
}
/* localdecomp:end func_0039B9B0 */
