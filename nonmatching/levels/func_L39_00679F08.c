/* func_L39_00679F08 (1496 B, 15 places): k4 Sonnet first pass, NEAR MISS: 24 diff of 374 instructions (93.6% equal) with the
 * file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as), checked at level 39 only.
 * Menu layout drawer: 11 unrolled blocks, each `if (D_L39_00352CE0.flag[N] == 0) { y = (s32)((1914 + 1908*N) * h); text(...) ; N<4 also C00 }`.
 * Needs a context edit: G_00677FD8 (L39_00677F28.c) has `u8 pad0[0xC]`; this C wants `u8 flag[11]; u8 pad0B;` in its place (same offsets).
 * Key findings: gp slots are D_001DAF9C_sda (-0x1914), D_001DAFA0_sda (-0x1910), D_001DAFA8_sda (-0x1908), D_001DAFAC_sda (-0x1904),
 * D_001DAFD0_sda (-0x18E0), each with `__asm__(".extern X, 4")`; func_L39_00594D70 = func_L01_00412BC0(unsigned long col, char *s, s32, f32 x, f32 y, f32 z)
 * (col must be unsigned long: retail builds 0x8066CCFF with ori/dsll/ori); func_L39_00594C00(s32, s32, unsigned long, s32 ptr, s32) is already matched.
 * `i = N;` before each `if` for N = 0 and 3..10 and `(f32)i` in the expression reproduces retail's `mtc1 $a0` (const-prop does not cross the branch);
 * blocks 1 and 2 are literal (`1914 + 1908`, `1914 + 1908*2.0`, folded). Prototypes: confident.
 * Remaining 24 diff = two register-allocation hunks: (1) block 0: retail loads $f4=1914 into the bnez delay slot, then i ($f1), then 1908 ($f0), mul $f0=$f0*$f1,
 * add $f0=$f4+$f0; mine allocates i=$f2, 1908=$f1, 1914=$f0 (expression order variants i*1908, 1908*i, 1914+.., ..+1914 all give the same 24);
 * (2) block 1: retail 1908=$f0, 1914=$f1, add $f1=$f1+$f0, cvt $f0; mine has them swapped. A float local `h = (f32)D_L39_00240304` made it much worse ($f20).
 * Next: permuter on block 0/1 expression shapes, or find the pseudo-numbering difference (maybe y computed in a shared local before the ifs).
 */
#include "common.h"
/* localdecomp:start func_L39_00679F08 */
extern void func_L01_00412BC0(unsigned long, char *, s32, f32, f32, f32);
extern void func_L39_00594C00(s32, s32, unsigned long, s32, s32);
extern f32 D_001DAF9C_sda;
__asm__(".extern D_001DAF9C_sda, 4");
extern f32 D_001DAFA0_sda;
__asm__(".extern D_001DAFA0_sda, 4");
extern f32 D_001DAFA8_sda;
__asm__(".extern D_001DAFA8_sda, 4");
extern f32 D_001DAFAC_sda;
__asm__(".extern D_001DAFAC_sda, 4");
extern f32 D_001DAFD0_sda;
__asm__(".extern D_001DAFD0_sda, 4");
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
void func_L39_00679F08(void) {
    s32 x = (s32)(D_001DAFAC_sda * (f32)D_L39_00240300);
    s32 w = (s32)((D_001DAFAC_sda + D_001DAFA0_sda) * (f32)D_L39_00240300);
    s32 y;
    s32 i;
    i = 0;
    if (D_L39_00352CE0.flag[0] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s2E1, -1, (f32)x, (f32)y, D_001DAFD0_sda);
        func_L39_00594C00(w, y, 0x8066CCFFUL, (s32)(D_L39_00352CE0.s40 + (D_L39_00352CE0.f0C << 5)), -1);
    }
    if (D_L39_00352CE0.flag[1] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)1) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s301, -1, (f32)x, (f32)y, D_001DAFD0_sda);
        func_L39_00594C00(w, y, 0x8066CCFFUL, (s32)D_L39_00352CE0.s180, -1);
    }
    if (D_L39_00352CE0.flag[2] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)2) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s321, -1, (f32)x, (f32)y, D_001DAFD0_sda);
        func_L39_00594C00(w, y, 0x8066CCFFUL, (s32)D_L39_00352CE0.s1C0, -1);
    }
    i = 3;
    if (D_L39_00352CE0.flag[3] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s341, -1, (f32)x, (f32)y, D_001DAFD0_sda);
        func_L39_00594C00(w, y, 0x8066CCFFUL, (s32)D_L39_00352CE0.s1A0, -1);
    }
    i = 4;
    if (D_L39_00352CE0.flag[4] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s1E0, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
    i = 5;
    if (D_L39_00352CE0.flag[5] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s200, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
    i = 6;
    if (D_L39_00352CE0.flag[6] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s220, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
    i = 7;
    if (D_L39_00352CE0.flag[7] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s240, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
    i = 8;
    if (D_L39_00352CE0.flag[8] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s261, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
    i = 9;
    if (D_L39_00352CE0.flag[9] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s281, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
    i = 10;
    if (D_L39_00352CE0.flag[10] == 0) {
        y = (s32)((D_001DAF9C_sda + D_001DAFA8_sda * (f32)i) * (f32)D_L39_00240304);
        func_L01_00412BC0(0x8066CCFFUL, D_L39_00352CE0.s2A1, -1, (f32)x, (f32)y, D_001DAFD0_sda);
    }
}
/* localdecomp:end func_L39_00679F08 */
