/* US draft of func_0039B680 (rac3-uya-decomp func_00396890, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039B680 */
typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_142430_0039B680;
extern s32 D_001D4CEC_0039B680;
extern s32 D_001D4CE8_0039B680;
void func_0039B680(void) {
    S_396890 *s = &D_142430_0039B680;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CE8_0039B680 = 0x14;
            D_001D4CEC_0039B680 |= 0x40;
        } else {
            s->f148 = 0;
            s->f18 = 0;
            D_001D4CE8_0039B680 = 0x1F;
        }
    }
}
/* localdecomp:end func_0039B680 */
