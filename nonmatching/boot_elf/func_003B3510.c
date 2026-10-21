/* US draft of func_003B3510 (rac3-uya-decomp func_003B3370, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B3510 */
__asm__(".extern D_001D8881, 1");
extern void func_003AA060();
extern void func_003E71C8_003B3510();
extern void func_003E6F70();
extern void *func_003E6FC0();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3510;
void func_003B3510(s32 a) {
    S_003ADBB0 *q;
    void *base;
    if (D_001D9EC0 || D_001D9BDC) {
        *(volatile s32 *)&D_001D9EC0 = 0;
        return;
    }
    func_003AA060(1);
    if (D_001D8881) return;
    q = &D_001DA938_003B3510;
    if (q->f4 != 0) base = q; else base = func_003E6FC0(q);
    func_003E71C8_003B3510(base, a);
    q = &D_001DA938_003B3510;
    if (q->f4 != 0) base = q; else base = func_003E6FC0(q);
    func_003E6F70(base);
}
/* localdecomp:end func_003B3510 */
