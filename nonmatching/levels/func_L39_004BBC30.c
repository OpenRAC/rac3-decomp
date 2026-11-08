/* Near miss, ported from rac4-decomp's func_L00_004F7A30 (cross-game near pair). NEAR: size hint + s32 return + function-pointer global fixes everything except retail scheduling lui $v0 before addiu $sp (2 instrs); 5 wordings tried */
__asm__(".extern D_L39_004433D0, 16");
extern s32 (*D_L39_004433D0)(void);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BBC30(void) {
    if (D_L39_004433D0 != 0) {
        return D_L39_004433D0();
    }
    func_L39_004BC6C8(26, 106, 14, 0, 0);
    return 0;
}
