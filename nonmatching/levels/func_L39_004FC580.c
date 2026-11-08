/* Near miss, ported from rac4-decomp's func_L00_00538390 (cross-game near pair). NEAR: SQ_RA: body matches (bnez/b form via if(v!=0) return call; return 0); only frame 0x20 with ra@0x10 vs 0x10 differs */
s32 func_L39_004FC380();
s32 func_L39_004FC5C0(s32, s32);

s32 func_L39_004FC580(s32 arg0) {
    s32 temp_v0;
    temp_v0 = func_L39_004FC380();
    if (temp_v0 != 0) {
        return func_L39_004FC5C0(temp_v0, arg0);
    }
    return 0;
}
