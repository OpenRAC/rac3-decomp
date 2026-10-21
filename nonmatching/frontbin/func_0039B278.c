/* US draft of func_0039B278 (rac3-uya-decomp func_00396488, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039B278 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396488;
extern S_396488 D_00142430_0039B278[];
extern s32 D_001D4CEC_0039B278;
extern s32 D_001D4CE8_0039B278;
void func_0039B278(void) {
    S_396488 *p = D_00142430_0039B278;
    if (p->x15C == 2 && p->x164 < 0) {
        if (p->x16C) {
            D_001D4CE8_0039B278 = 0x13;
            D_001D4CEC_0039B278 |= 0x40;
        } else {
            D_001D4CE8_0039B278 = 0x10;
        }
    }
}
/* localdecomp:end func_0039B278 */
