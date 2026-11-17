/* func_L01_00422338: MATCH (0 diff) with -mno-split-addresses (check.py --mode N). The file L01_00421730.c is built in
   split-address mode, where this C is 3 diff (the `lui` of D_L01_001D6694 is scheduled before the `addiu $sp` and uses
   $v0 instead of the macro's $v1). It needs a file cut at 0x422338 with its own `-mno-split-addresses` line in
   config/levels/text_parts.txt. The earlier `extern void func_L01_00422338(void)` in func_L01_00421988's block has to become `u8`. */
extern s32 D_L01_001D6A08;
extern u8 D_L01_001D6808;
extern s32 D_L01_001D6694;
extern s32 func_L01_0040DFC0(void *);
extern void func_L01_004360B8_00422338(s32);

u8 func_L01_00422338(void) {
    s32 v = D_L01_001D6694;
    if (v == 0 || v == 7) {
        if (func_L01_0040DFC0(&D_L01_001D6A08)) {
            func_L01_004360B8_00422338(1);
        }
    }
    return D_L01_001D6808;
}
