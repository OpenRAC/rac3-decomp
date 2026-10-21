/* US draft of func_0039B620 (rac3-uya-decomp func_00396830, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039B620 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396830;
extern S_396830 D_00142430_0039B620[];
extern s32 D_001D4CEC_0039B620;
extern s32 D_001D4CE8_0039B620;
void func_0039B620(void) {
    S_396830 *p = D_00142430_0039B620;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 9;
        D_001D4CEC_0039B620 &= ~2;
        D_001D4CEC_0039B620 &= ~0x10;
        p->x168 = 0;
        D_001D4CE8_0039B620 = 0x11;
    }
}
/* localdecomp:end func_0039B620 */
