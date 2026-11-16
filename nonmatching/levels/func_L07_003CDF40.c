/* Level 7 near miss: 4 differences, only the second call's argument block
   order: retail schedules mov.s $f14,$f20 before the integer moves, this C
   after. The first and third blocks match; the third float argument is 2.5f
   (not 2.0f). Registered sched1 tie class. Not linked. No VU0. */
extern s32 func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern int func_L07_003CE2B8(int n);

void func_L07_003CDF40(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);
    s32 mode = h[0x5F] ? 0x10001 : 1;

    if (func_L07_003CE2B8(func_L01_004468C8(arg0, 8, mode, 0, 1, 0, 0.75f, (f32)h[0x44], 2.5f)) != 0 ||
        func_L07_003CE2B8(func_L01_004468C8(arg0, 7, mode, 0, 1, 0, 0.45f, (f32)h[0x44], 2.5f)) != 0 ||
        func_L07_003CE2B8(func_L01_004468C8(arg0, 6, mode, 0, 1, 0, 0.25f, (f32)h[0x44], 2.5f)) != 0) {
        h[0x406]++;
    }
}
