/* PAL near miss (sonnet-b30-j2b, round 19): 9 words differ (raw 9, only the FP register numbers of the four operands of case 1's
 * `(1.0f - (f32)D758 / (f32)D852C) * 128.0f`: ours $f2 (divisor), $f0 (1.0), $f1 (dividend), $f3 (128.0), retail $f1, $f3, $f0, $f2: a
 * rotation of the same four registers; case 4 (three operands) matches). A menu state machine on D_L01_001E0754 (5 states, jump
 * table, 9 x func_L01_005170B8 per fade state), 1104 bytes, 34 places, NTSC-U twin `asm`. The C contains a `switch` (a match needs
 * the manager's level build for the jump table).
 * Needs (a) a CUT: S mode with `@ps2as` (`lui $at; mtc1` constants): a file of its own at 0x4845E8 with the flags `-O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as` (8-aligned at both ends: func_L01_00484080 ends at 0x4845E8 and is C in the old file, the rest
 * of L01_00483FC0.c from func_L01_00484A38 on moves to a third file with the old line), and (b) a config/levels/divs_nops.txt row
 * `func_L01_004845E8 2 2`. Check it with `python tools/check.py nonmatching/levels/func_L01_004845E8.c func_L01_004845E8 --as ps2as
 * --mode S` (the row has to be in the working tree).
 * What got it from 66 to 9 (aligned): (1) the state words D_L01_001E0754/0758 are `lui`-form reads (`.extern X, 16` hint on an `s32`;
 * the `$gp` forms in the delay slots are made by the assembler), the three gp floats/ints `D_L01_001D852C/8530/8534/8508` keep `.extern X, 4`;
 * (2) the buffer D_L01_001E0760 is an 8-byte object (`char[8]` + 16-byte hint: retail rebuilds `lui/addiu` at each use) while the format strings
 * stay unsized (split `lui`, `addiu` in the jal slot); (3) `alpha` declared INSIDE each fade case (a function-level variable set in two
 * cases is a global pseudo: mask and alpha swapped $s0/$s1; block-local: 66 -> 22 in one compile); (4) case 2 reloads D_8534, case 3 D_8530.
 * Tried for the last 9 words (all identical): operand order and a 128 integer constant, locals for the four operands in all 24 orders
 * (cse merges them), the quotient as its own local. */
#include "common.h"
/* localdecomp:start func_L01_004845E8 */
extern s32 D_L01_001E0754_004845E8;
extern s32 D_L01_001E0758_004845E8;
extern char D_L01_001E0760_004845E8[8];
__asm__(".extern D_L01_001E0760_004845E8, 16");
extern char D_L01_001D8528_004845E8[];
extern char D_L01_001D8538_004845E8[];
extern char D_L01_001D8540_004845E8[];
extern char D_L01_001D8548_004845E8[];
extern s32 D_L01_001D852C_004845E8;
extern s32 D_L01_001D8530_004845E8;
extern s32 D_L01_001D8534_004845E8;
__asm__(".extern D_L01_001D8534_004845E8, 4");
extern u32 D_L01_001D8508_004845E8;
extern u8 *D_001D52FC;
__asm__(".extern D_L01_001E0754_004845E8, 16");
__asm__(".extern D_L01_001E0758_004845E8, 16");
__asm__(".extern D_L01_001D852C_004845E8, 4");
__asm__(".extern D_L01_001D8530_004845E8, 4");
__asm__(".extern D_L01_001D8508_004845E8, 4");
extern void func_L01_0047EC88_004845E8(void);
extern s32 func_L01_0047EBE0_004845E8(void);
extern int func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00516FD8(s32, void *);
extern s32 func_L01_005170B8_004845E8(s32, u32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00517748_004845E8(s32);
extern void func_L01_00516090_004845E8(void *);

void func_L01_004845E8(void *self) {

    func_L01_0047EC88_004845E8();
    switch (D_L01_001E0754_004845E8) {
    case 0:
        func_0011B2E8(D_L01_001E0760_004845E8, D_L01_001D8538_004845E8, 0);
        func_L01_00516FD8(0x100006, D_L01_001E0760_004845E8);
        func_L01_00516FD8(0x10000A, D_L01_001D8528_004845E8);
        func_0011B2E8(D_L01_001E0760_004845E8, D_L01_001D8540_004845E8, 0, 0);
        func_L01_00516FD8(0x10000C, D_L01_001E0760_004845E8);
        D_L01_001E0754_004845E8 = 1;
        D_L01_001E0758_004845E8 = D_L01_001D852C_004845E8 - 1;
        break;
    case 1: {
        s32 alpha = (s32)((1.0f - (f32)D_L01_001E0758_004845E8 / (f32)D_L01_001D852C_004845E8) * 128.0f) << 24;
        func_L01_005170B8_004845E8(0x100005, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100008, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100009, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100006, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100007, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000A, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000B, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000C, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000D, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        if (func_0038CAD0(&D_L01_001E0758_004845E8) != 0) {
            D_L01_001E0758_004845E8 = 0;
            D_L01_001E0754_004845E8 = 2;
        }
        break;
    }
    case 2:
        func_0011B2E8(D_L01_001E0760_004845E8, D_L01_001D8538_004845E8, 0);
        func_L01_00516FD8(0x100006, D_L01_001E0760_004845E8);
        func_0011B2E8(D_L01_001E0760_004845E8, D_L01_001D8548_004845E8, 0);
        func_L01_00516FD8(0x10000A, D_L01_001E0760_004845E8);
        if (func_0038CAD0(&D_L01_001E0758_004845E8) != 0) {
            D_L01_001E0754_004845E8 = 3;
            D_L01_001E0758_004845E8 = D_L01_001D8534_004845E8 - 1;
        }
        break;
    case 3:
        func_L01_005170B8_004845E8(0x100006, D_L01_001D8508_004845E8);
        if (func_0038CAD0(&D_L01_001E0758_004845E8) != 0 || (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) != 0) {
            D_L01_001E0754_004845E8 = 4;
            D_L01_001E0758_004845E8 = D_L01_001D8530_004845E8 - 1;
        }
        break;
    case 4: {
        s32 alpha = (s32)((f32)D_L01_001E0758_004845E8 / (f32)D_L01_001D8530_004845E8 * 128.0f) << 24;
        func_L01_005170B8_004845E8(0x100005, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100008, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100009, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100006, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x100007, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000A, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000B, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000C, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        func_L01_005170B8_004845E8(0x10000D, (D_L01_001D8508_004845E8 & 0xFFFFFF) | alpha);
        if (func_0038CAD0(&D_L01_001E0758_004845E8) != 0) {
            func_L01_00517748_004845E8(func_L01_0047EBE0_004845E8());
            func_L01_00516090_004845E8(self);
        }
        break;
    }
    }
}
/* localdecomp:end func_L01_004845E8 */
