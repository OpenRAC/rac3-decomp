/* Near miss, ported from rac4-decomp's func_L00_004F8268 (cross-game near pair). NEAR: 1 diff: retail has stray extra word addiu sp,sp,0x50 after the epilogue (past jr delay slot); all else equal; not producible */
__asm__(".extern D_L39_00443410, 16");
extern s32 (*D_L39_00443410[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BBEB8(void) {
    if (D_L39_00443410[0] != 0) {
        return D_L39_00443410[0]();
    }
    func_L39_004BC6C8(26, 125, 14, 0, 0);
    return 0;
}
