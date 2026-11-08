/* Near miss, ported from rac4-decomp's func_0011A1C8 (cross-game near pair). NEAR: only epilogue scheduling differs (retail: move v0,0 before ld ra; ours after), size hint used; 5 variants tried */
__asm__(".extern D_L39_00464670, 16");
extern s32 D_L39_00464670;
extern void func_00126280(s32);

s32 func_L39_004D5900(void) {
    func_00126280(D_L39_00464670);
    return 0;
}
