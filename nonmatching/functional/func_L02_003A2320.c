/* functional: high. Same stores and call as retail; only register choice and order of 4 independent stores differ (check.py 4 diff). Constants and callee verified against PAL asm. */
extern f32 func_003824E0(f32, f32);
void func_L02_003A2320(void *arg0) {
    u8 *p;
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        p = *(u8 **)((u8 *)arg0 + 0x68);
        *(f32 *)(p + 0x28) = func_003824E0(0.031415928f, 0.12566371f);
        *(s16 *)(p + 0x2E) = 7;
        *(f32 *)(p + 0x24) = 0.65f;
        *(s16 *)(p + 0x2C) = 50;
        *(f32 *)(p + 8) = 0.00392f;
        *(s32 *)(p + 0x20) = 100;
        *(u8 *)((u8 *)arg0 + 0x20) = 1;
        *(u16 *)((u8 *)arg0 + 0x34) |= 0x808;
    }
}
