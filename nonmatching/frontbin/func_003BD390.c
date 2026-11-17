/* func_003BD390 (PAL frontbin, src/frontbin/3BC858.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Started from the US draft (rac3-uya-decomp func_003B7EB0).
   Near miss: 7 diff in its file's context (tools/try_in_context.py), 2026-11-16.
   - The store to D_001D4B4C: retail has `lui $at, 0x1D; sw $zero, 0x4B4C($at)` before the bnez,
     an assembler macro the compiler counted as two words. A sized `extern s32 D_001D4B4C;` makes gcc
     emit `sw $0,D_001D4B4C` as one small-data word and schedule it into the bnez delay slot, where
     Ps2EeAs always uses $gp; an unsized array gives `lui $v0` + `sw %lo` from the compiler. Only the
     US draft's literal address `*(s32 *)0x1D4B4C` reproduces retail, and that is not allowed.
   - The c->f7 store builds the address in $v0 where retail uses $v1.
   The file's other declarations (the two typedefs, the externs) are already above the marker. */
/* localdecomp:start func_003BD390 */
__asm__(".extern D_001D8CD1, 1");
__asm__(".extern D_001DA1F0, 4");
__asm__(".extern D_001D8CC4, 4");
extern s32 D_001D4B4C;
void func_003BD390(void) {
    s32 r;
    D_001D4B4C = 0;
    if (D_001D8CD1 == 0) {
        do {
            func_11F0A0(0);
            func_12C908(0);
            func_0039C410();
            func_0039ADE0();
            r = D_001D8CD1 = func_0039A1E0() != 0;
        } while (r == 0);
    }
    while (D_142430_003BD390.f15C != 2 || D_142430_003BD390.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_0039C410();
        func_0039ADE0();
    }
    if (D_001DA1F0 != 0) func_13BF00(D_001DA1F0);
    do {} while (func_13B620());
    func_13BED0();
    func_13CF40(0);
    func_13CDF0(0);
    func_13CDF0(0);
    { S_1CCFD0_3B7EB0 *c = &D_1CCFD0_003BD390; c->f7 = 0; }
    func_003A9AD0();
    if (D_001D8CC4 != 0) D_001D8CC4();
    func_00387EF0();
}
/* localdecomp:end func_003BD390 */
