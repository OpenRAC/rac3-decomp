/* Near miss, ported from rac4-decomp's func_L00_00541528 (cross-game near pair). NEAR: 16 diff: library-style 16-byte sd save slots (frame 0x50) vs our 8-byte slots; body equal */
s32 func_L39_00505BB8();
s32 func_L39_0050C338(s32, s32, s32, s32, s32, s32);

s32 func_L39_00505718(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_L39_0050C338(0, func_L39_00505BB8(), arg0, arg1, arg2, arg3);
}
