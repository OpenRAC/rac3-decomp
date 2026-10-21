/* Near miss of func_003B3158 with its file's own flags: tools/check.py reports 7 diff
   (the version it replaces: 45).
*/

/* PAL candidate for func_003B3158.
 *
 * Retail reaches the two flag globals with `lui $v0, %hi(sym)` +
 * `lw $v0, %lo(sym)($v0)`: the load goes into the same register as the `lui`.
 * The globals are unsized arrays (never small data), so they are read through
 * per-function aliases; the store keeps retail's `lui $at` + `sw` form.
 */

/* localdecomp:start func_003B3158 */
__asm__(".extern D_001D8881, 1");
extern void func_003A9CA8();
extern void func_003E6E10_003B3158();
extern void func_003E6BB8();
extern void *func_003E6C08();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3158;
extern s32 D_001D9EC0_003B3158[];
extern s32 D_001D9BDC_003B3158[];
void func_003B3158(s32 a) {
    S_003ADBB0 *q;
    void *base;
    if (D_001D9EC0_003B3158[0] || D_001D9BDC_003B3158[0]) {
        *(s32 *)0x1D9EC0 = 0;
        return;
    }
    func_003A9CA8(1);
    if (D_001D8881) return;
    q = &D_001DA938_003B3158;
    if (q->f4 != 0) base = q; else base = func_003E6C08(q);
    func_003E6E10_003B3158(base, a);
    q = &D_001DA938_003B3158;
    if (q->f4 != 0) base = q; else base = func_003E6C08(q);
    func_003E6BB8(base);
}
/* localdecomp:end func_003B3158 */
