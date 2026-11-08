/* Near miss, ported from rac4-decomp's func_L00_00541528 (cross-game near pair). NEAR: SQ_RA: same 16-byte save spacing (frame 0x50); save-order/arg-move scheduling follows from it; start_c unchanged */
s32 func_L39_0050C498();
s32 func_L39_0050C338(s32, s32, s32, s32, s32, s32);

s32 func_L39_0050C430(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_L39_0050C338(0, func_L39_0050C498(), arg0, arg1, arg2, arg3);
}