/* US draft of func_0039AF10 (rac3-uya-decomp func_00396120, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039AF10 */
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x168]; s32 f17C; } S_142430_00396120;
__asm__(".extern D_001D4CE8_00396122, 4");
__asm__(".extern D_001D4CEC_00396122, 4");
extern S_142430_00396120 D_142430_0039AF10;
extern s32 D_001D4CE8_00396122;
extern s32 D_001D4CEC_00396122;
extern s32 D_001D4CE8_0039AF10;
extern s32 D_001D4CEC_0039AF10;
void func_0039AF10(void) {
    if (D_142430_0039AF10.f17C == 0 && D_142430_0039AF10.f8 != 2) {
        D_001D4CE8_00396122 = 4;
        return;
    }
    if (D_142430_0039AF10.f17C != 0 && D_142430_0039AF10.f8 != 2) {
        D_142430_0039AF10.f17C = 0;
        D_001D4CE8_0039AF10 = 3;
        D_001D4CEC_00396122 = D_001D4CEC_00396122 | 1;
        return;
    }
    if (D_001D4CEC_0039AF10 & 4) {
        D_001D4CE8_00396122 = 0x1E;
        return;
    }
    if (D_001D4CEC_0039AF10 & 2) {
        D_001D4CE8_00396122 = 0x1D;
        return;
    }
    if (D_142430_0039AF10.f17C == 0 || (D_142430_0039AF10.f8 == 2 && D_142430_0039AF10.f10 != 0)) {
        D_001D4CE8_00396122 = 5;
        return;
    }
    if (D_001D4CEC_0039AF10 & 0x80) {
        D_001D4CE8_0039AF10 = 0x18;
        D_001D4CEC_00396122 = (D_001D4CEC_0039AF10 ^ 0x80) | 0x40;
        return;
    }
    if (D_001D4CEC_0039AF10 & 0x100) {
        D_001D4CE8_0039AF10 = 0x16;
        D_001D4CEC_00396122 = (D_001D4CEC_0039AF10 ^ 0x100) | 0x40;
        return;
    }
    if (D_001D4CEC_0039AF10 & 0x200) {
        D_001D4CEC_0039AF10 = D_001D4CEC_0039AF10 ^ 0x200;
        D_001D4CE8_0039AF10 = 0x1C;
    }
}
/* localdecomp:end func_0039AF10 */
