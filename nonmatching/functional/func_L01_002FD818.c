/* functional: high. Near-miss draft, 1 word differs (sltiu vs slti on the u32 loop counter, same loop). Draft was derived from our own rac2 sister function. For each of 3 slots (stride 0xA0) whose owner matches, runs the slot update and, if its flag at +0x64 is clear, spawns 3 particle effects. */
/* localdecomp:start func_L01_002FD818 */
extern s8 D_L01_0026EAB0_002FD818[];
void func_L01_002FD818(s32 owner) {
    extern void func_L01_002FDA10(s32, s32);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    u32 i;
    s32 state;
    s8 *slot;
    s8 *pool;

    pool = D_L01_0026EAB0_002FD818;
    slot = pool + 0x30;
    state = (s32) pool;
    i = 0;
    for (;;) {
        ++i;
        if ((*(s32 *)((s8 *)(slot) + (0x5C))) == owner) {
            func_L01_002FDA10(owner, state);
            if ((*(s32 *)((s8 *)(slot) + (0x64))) == 0) {
                func_003D9508(slot, 0x31, 0x3F007F00, 1, func_003824E0(0.125f, 0.25f) * 5.0f, 1.25f, 0.0f);
                func_003D9508(slot, 0x31, 0x5F7F7F7F, 1, func_003824E0(0.0625f, 0.125f) * 5.0f, 1.24f, 0.0f);
                func_003D9508(slot, 0xB, 0x10003F00, 1, func_003824E0(0.15f, 0.35f) * 5.0f, 1.23f, 0.0f);
            }
        }
        slot += 0xA0;
        state += 0xA0;
        if (i >= 3) break;
    }
}
/* localdecomp:end func_L01_002FD818 */
