/* Near miss, ported from rac4-decomp's func_005407D8 (cross-game near pair). NEAR: donor global address wrong: retail reads D_001A5CD8 (lui 0x1a/0x5cd8), not D_00172170; remaining 14 diff are saved-register numbering (retail s1=a2&ff, s2=a3&ff, s3=a1 copied late; ours s1=a1) and lui/lw placement; ~9 tries */
extern void func_L39_0061E278(void);
extern void func_L39_0066DA90(void *, s32, s32, s32);
extern s32 D_001A5CD8[];

void func_L39_0066DA10(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 a2 = arg2 & 0xFF;
    s32 a3 = arg3 & 0xFF;
    if (*(s32 *)((u8 *)arg0 + 0x34) == D_001A5CD8[0]) {
        func_L39_0061E278();
    }
    func_L39_0066DA90(arg0, arg1, a2, a3);
    *(s32 *)((u8 *)arg0 + 0x34) = -1;
    *(s32 *)((u8 *)arg0 + 0x4) = -1;
}
