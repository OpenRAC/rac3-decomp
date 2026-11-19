/* PAL near miss (Sonnet b12-w1): func_L03_003ADF58, the level 3 stage menu text set-up (straight-line calls into
 * the frontbin UI: func_003E8EF0 / func_003E9358 / func_003E8630, three of the strings built with sprintf).
 * With `-mno-split-addresses` added for this function (a flag the level build already uses for other files,
 * e.g. L03_003AE810.c; check.py --flags=-mno-split-addresses) everything matches except where the format
 * string's address is loaded: gcc hoists `la $s0, D_L03_001DE7A8` into the prologue, retail keeps `lui $s0` in front
 * of the first sprintf's `addiu $a0,0x10ac` and the `addiu $s0` in the delay slot of func_00381FF0's call
 * (about 3 instructions). With the file's own flags (split addresses) it is 49 instructions off: gcc then
 * CSEs the buffers' `lui`s into $s registers where retail rebuilds each `lui/addiu` pair (the second use of
 * every buffer is given its own alias name `...b`, which fixed most of the CSE in the no-split build).
 * Tried: fmt as a local assigned just before the first use, a temp for the nested func_00381FF0 call (split mode
 * moves the fmt load after the call then), one base symbol plus offsets for the buffers.
 * Needs: a file cut with -mno-split-addresses (all other blocks of L03_003AD8C8.c must keep matching).
 */
#include "common.h"
typedef struct { u8 p0[0x68]; void *w68; } M_3AC2C8;
extern void func_L03_003AE810(u8 *);
extern void func_L03_003AE880(M_3AC2C8 *);
extern void func_L03_003AE558(s32);
/* localdecomp:start func_L03_003ADF58 */
extern void func_L03_00503EB8(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_L03_003AE4C0(s32);
extern f32 D_L03_001DE738_003ADF58;
__asm__(".extern D_L03_001DE738_003ADF58, 4");
extern f32 D_L03_001DE73C_003ADF58;
extern f32 D_L03_001DE740_003ADF58;
__asm__(".extern D_L03_001DE740_003ADF58, 4");
extern f32 D_L03_001DE744_003ADF58;
extern f32 D_L03_001DE748_003ADF58;
__asm__(".extern D_L03_001DE748_003ADF58, 4");
extern f32 D_L03_001DE74C_003ADF58;
extern f32 D_L03_001DE750_003ADF58;
__asm__(".extern D_L03_001DE750_003ADF58, 4");
extern f32 D_L03_001DE754_003ADF58;
extern f32 D_L03_001DE758_003ADF58;
__asm__(".extern D_L03_001DE758_003ADF58, 4");
extern f32 D_L03_001DE75C_003ADF58;
extern f32 D_L03_001DE760_003ADF58;
__asm__(".extern D_L03_001DE760_003ADF58, 4");
extern f32 D_L03_001DE764_003ADF58;
extern f32 D_L03_001DE768_003ADF58;
__asm__(".extern D_L03_001DE768_003ADF58, 4");
extern f32 D_L03_001DE76C_003ADF58;
extern f32 D_L03_001DE778_003ADF58;
__asm__(".extern D_L03_001DE778_003ADF58, 4");
extern f32 D_L03_001DE77C_003ADF58;
extern f32 D_L03_001DE780_003ADF58;
__asm__(".extern D_L03_001DE780_003ADF58, 4");
extern f32 D_L03_001DE784_003ADF58;
extern f32 D_L03_001DE788_003ADF58;
__asm__(".extern D_L03_001DE788_003ADF58, 4");
extern f32 D_L03_001DE78C_003ADF58;
extern f32 D_L03_001DE790_003ADF58;
__asm__(".extern D_L03_001DE790_003ADF58, 4");
extern f32 D_L03_001DE794_003ADF58;
extern f32 D_L03_001DE798_003ADF58;
__asm__(".extern D_L03_001DE798_003ADF58, 4");
extern f32 D_L03_001DE79C_003ADF58;
extern f32 D_L03_001DE7A4_003ADF58;
__asm__(".extern D_L03_001DE7A4_003ADF58, 4");
extern char D_L03_001DE7A8_003ADF58[];
extern char D_L03_001E1BD0_003ADF58[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001E1BD0_003ADF58, 8");
extern char D_L03_001E1C10_003ADF58[];
extern char D_L03_001E1C10_003ADF58b[];
extern char D_L03_001E1C50_003ADF58[];
extern char D_L03_001E1C50_003ADF58b[];
extern char D_L03_001E1C90_003ADF58[];
extern char D_L03_001E1C90_003ADF58b[];
extern char D_L03_001E1CD0_003ADF58[];
extern char D_L03_001E1CD0_003ADF58b[];
extern char D_L03_001E1D10_003ADF58[];
extern char D_L03_001E1D10_003ADF58b[];
extern char D_L03_001E1D50_003ADF58[];
extern char D_L03_001E1D50_003ADF58b[];
extern char D_L03_001E1BD0_003ADF58b[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001E1BD0_003ADF58b, 8");

void func_L03_003ADF58(u8 *o) {
    func_L03_00503EB8(1);
    func_003B5060(0x4A0000);
    func_003E8EF0(0x4A0002, 127, 0x331465B7, D_L03_001DE738_003ADF58, D_L03_001DE73C_003ADF58, -1.0f, 1.0f, 0.32f);
    func_003E8630(0x4A0000, 0x4A0002);
    func_003E8EF0(0x4A0001, 126, 0x332299DE, D_L03_001DE738_003ADF58, D_L03_001DE73C_003ADF58, -1.0f, 1.0f, 0.32f);
    func_003E8630(0x4A0000, 0x4A0001);
    func_003E8EF0(0x4A0004, 127, 0x331465B7, D_L03_001DE740_003ADF58, D_L03_001DE744_003ADF58, 1.0f, 1.0f, 0.32f);
    func_003E8630(0x4A0000, 0x4A0004);
    func_003E8EF0(0x4A0003, 126, 0x332299DE, D_L03_001DE740_003ADF58, D_L03_001DE744_003ADF58, 1.0f, 1.0f, 0.32f);
    func_003E8630(0x4A0000, 0x4A0003);
    func_0011B2E8(D_L03_001E1BD0_003ADF58, D_L03_001DE7A8_003ADF58, func_00381FF0(0x10AC));
    func_003E9358(0x4A0005, (s32)D_L03_001E1BD0_003ADF58b, 0x8066CCFF, D_L03_001DE748_003ADF58, D_L03_001DE74C_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A0005);
    func_0011B2E8(D_L03_001E1C10_003ADF58, D_L03_001DE7A8_003ADF58, func_00381FF0(0x10AB));
    func_003E9358(0x4A0006, (s32)D_L03_001E1C10_003ADF58b, 0x8066CCFF, D_L03_001DE750_003ADF58, D_L03_001DE754_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A0006);
    func_L03_003AE810(o);
    func_003E9358(0x4A0007, (s32)D_L03_001E1C50_003ADF58b, 0x8066CCFF, D_L03_001DE758_003ADF58, D_L03_001DE75C_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A0007);
    func_L03_003AE880((M_3AC2C8 *)o);
    func_003E9358(0x4A0008, (s32)D_L03_001E1C90_003ADF58b, 0x8066CCFF, D_L03_001DE760_003ADF58, D_L03_001DE764_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A0008);
    func_0011B2E8(D_L03_001E1CD0_003ADF58, D_L03_001DE7A8_003ADF58, func_00381FF0(0x10AA));
    func_003E9358(0x4A0009, (s32)D_L03_001E1CD0_003ADF58b, 0x8066CCFF, D_L03_001DE768_003ADF58, D_L03_001DE76C_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A0009);
    func_003E8EF0(0x4A000A, 14, 0x331465B7, D_L03_001DE778_003ADF58, D_L03_001DE77C_003ADF58, -1.0f, 1.0f, 0.1f);
    func_003E8630(0x4A0000, 0x4A000A);
    func_003E8EF0(0x4A000B, 15, 0x332299DE, D_L03_001DE780_003ADF58, D_L03_001DE784_003ADF58, -1.0f, 1.0f, 0.1f);
    func_003E8630(0x4A0000, 0x4A000B);
    func_0011B2E8(D_L03_001E1D10_003ADF58, D_L03_001DE7A8_003ADF58, func_00381FF0(0x8DE));
    func_003E9358(0x4A000C, (s32)D_L03_001E1D10_003ADF58b, 0x8066CCFF, D_L03_001DE788_003ADF58, D_L03_001DE78C_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A000C);
    func_L03_003AE4C0(0);
    func_003E8EF0(0x4A000F, 14, 0x331465B7, D_L03_001DE790_003ADF58, D_L03_001DE794_003ADF58, -1.0f, 1.0f, 0.1f);
    func_003E8630(0x4A0000, 0x4A000F);
    func_003E8EF0(0x4A0010, 15, 0x332299DE, D_L03_001DE790_003ADF58, D_L03_001DE794_003ADF58, -1.0f, 1.0f, 0.1f);
    func_003E8630(0x4A0000, 0x4A0010);
    func_0011B2E8(D_L03_001E1D50_003ADF58, D_L03_001DE7A8_003ADF58, func_00381FF0(0x15E8));
    func_003E9358(0x4A000E, (s32)D_L03_001E1D50_003ADF58b, 0x8066CCFF, D_L03_001DE798_003ADF58, D_L03_001DE79C_003ADF58, 0.5f, 1.0f, D_L03_001DE7A4_003ADF58);
    func_003E8630(0x4A0000, 0x4A000E);
    func_L03_003AE558(0);
    func_003E8348(0, 0x4A0000);
}
/* localdecomp:end func_L03_003ADF58 */
