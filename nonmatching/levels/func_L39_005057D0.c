/* Near miss, ported from rac4-decomp's func_L00_005415E0 (cross-game near pair). NEAR: retail frame 0x30 with s0@0,s1@0x10,ra@0x20 (8-byte unused slot at 8); start_c (9 diff) differs only in frame layout; unresolved */
s32 func_L39_004E4578(void *, s32, s32, s32, s32, s32);

void func_L39_005057D0(void *arg0, void *arg1, s32 arg2) {
    s32 var_a5;
    if (((*(s32 *)((u8 *)(arg1) + 0x14)) & 2) || (var_a5 = 0, ((arg2 & 2) != 0))) {
        var_a5 = 2;
    }
    func_L39_004E4578(arg0, (*(s32 *)((u8 *)(arg1) + 0)), (*(s32 *)((u8 *)(arg1) + 4)), (*(s32 *)((u8 *)(arg1) + 0xC)), (*(s32 *)((u8 *)(arg1) + 0x10)), var_a5);
    (*(s32 *)((u8 *)(arg0) + 8)) = (s32) (*(s32 *)((u8 *)(arg1) + 8));
}
