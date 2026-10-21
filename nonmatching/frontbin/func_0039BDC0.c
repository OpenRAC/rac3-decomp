/* Near miss of func_0039BDC0 with its file's own flags: tools/check.py reports 9 diff
   (the version it replaces: 19).
   What differs: 9 diffs left: the write of the flag word at 0x001D4CEC uses a named global (so
   gcc emits `lui $a0, 0x1d` early and `sw $v0, 0x4cec($a0)`), where retail has `lui $at, 0x1d`
   + `sw $v0, 0x4cec($at)` right before the store; and the two mask constants ~0x10 / ~0x4000
   land in $a2/$a3 instead of retail's $a3/$a2. A literal address for the write would give
   retail's form, but then gcc shares one address computation between the read and the write
   (lui+ori in one register) instead of forming two lui/%lo pairs; the bit-field form of the
   flags allocates the masks as retail does but is only reachable...
*/

/* PAL candidate for func_0039BDC0 (frontbin), from the US draft of
   rac3-uya-decomp func_00396FD0 (commit 13cf5c5).

   The US draft matched only with `@ps2as` (a single-function override); here the
   file's own flags are used, so the C changed:

   - Retail reaches the flag word at 0x001D4CEC and the byte at 0x001D9FA0 with
     a lui/%lo pair, not through $gp.  A named global of that size is small data
     and gcc reaches it through $gp, so these are written through their literal
     address: gcc then forms the high half in the register it loads into (read)
     or in $at (write), as retail does.
   - The read and the write of the flag word use different address expressions
     (a literal and a named global), so that gcc does not merge them into one
     address computation.
   - The flag bits are cleared with separate masks so that gcc keeps one `and`
     per bit, as in func_0039C028. */


/* localdecomp:start func_0039BDC0 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396FD0;
extern S_396FD0 D_00142430_0039BDC0[];
extern s32 D_001D62FC_0039BDC0;
extern s32 D_001D6300_0039BDC0;
extern s32 D_001D6308_0039BDC0;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039BDC0;
extern s32 D_001D6304_0039BDC0;
extern s8 D_001D9FA8;
extern s32 D_001D4CEC_0039BDC0[];
extern void func_0039C028(void);
void func_0039BDC0(s32 a, s32 b, s32 c) {
    S_396FD0 *p = D_00142430_0039BDC0;
    s32 v;
    D_001D62FC_0039BDC0 = a;
    D_001D6300_0039BDC0 = c;
    p->f148 = 0;
    p->f10 = 0;
    D_001D6308_0039BDC0 = b;
    D_001D62F4 = 0;
    D_001D62F8_0039BDC0 = 0;
    D_001D6304_0039BDC0 = 0;
    D_001D9FA8 = 0;
    func_0039C028();
    *(s8 *)0x001D9FA0 = 1;
    v = *(s32 *)0x001D4CEC;
    v |= 4;
    v &= ~2;
    v &= ~0x40;
    v &= ~0x10;
    v &= ~0x4000;
    D_001D4CEC_0039BDC0[0] = v;
}
/* localdecomp:end func_0039BDC0 */
