/* PAL near miss (b8-s4): 6 differences, all one scheduling pattern: retail sets up the next call's $a1 (lw 0x27F4/0x27F0($gp)) before the sw of the previous result and puts that sw in the next jal's delay slot; this C stores right after each call. Needs the .extern hints for D_L01_001DF0A0/A4 (file is @ps2as). About 8 compiles (locals for the four results, interleaved stores) did not move it.
 */
#include "common.h"
/* localdecomp:start func_L01_003CE2E8 */
__asm__(".extern D_L01_001DF0A8, 4");
__asm__(".extern D_L01_001DF0A0, 4");
__asm__(".extern D_L01_001DF0A4, 4");
extern void func_L01_0043A778(s32, s32, u8 *);
extern s32 func_L01_0040F550(s32, s32, f32);
extern void func_L01_0040C8A0(u8 *, s32);
extern s32 D_L01_001DF0A8;
extern s32 D_L01_001DF0A0;
extern s32 D_L01_001DF0A4;

void func_L01_003CE2E8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s + 0xC4) != 0) {
        f32 f;
        s32 a;
        s32 b;
        s32 c;
        s32 d;
        func_L01_0043A778(*(s32 *)(s + 0xC4), *(s32 *)(s + 0xC8), s);
        *(s128 *)(s + 0x10) = *(s128 *)(a0 + 0x10);
        f = (f32)*(s32 *)(s + 0xD0);
        f = f / (f32)((D_L01_001DF0A8 * 5 + 2) / 6);
        *(s32 *)(s + 0x24) = func_L01_0040F550(0, D_L01_001DF0A0, f);
        *(s32 *)(s + 0x2C) = func_L01_0040F550(0, D_L01_001DF0A4, f);
        *(s32 *)(s + 0x20) = func_L01_0040F550(0, D_L01_001DF0A0, f);
        *(s32 *)(s + 0x28) = func_L01_0040F550(0, D_L01_001DF0A4, f);
        func_L01_0040C8A0(s, *(s32 *)(s + 0xC0));
    }
}
/* localdecomp:end func_L01_003CE2E8 */
