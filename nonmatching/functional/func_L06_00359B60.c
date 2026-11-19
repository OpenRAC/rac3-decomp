/* functional: high. From the existing 10-diff draft; verified against retail asm (sin/cos pair, table D_L06_001DD400/404 stride 8, copy of a0+0x20, rotate-add). Register allocation only. */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 D_L06_001DD400[];
extern f32 D_L06_001DD404[];

void func_L06_00359B60(u8 *a0, u8 *a1, f32 scale, f32 angle) {
    f32 s = func_0038D098(angle);
    f32 c = func_0038D0B0(angle);
    f32 *q = D_L06_001DD404;
    f32 *p = D_L06_001DD400;
    s32 i;

    for (i = 3; i >= 0; i--) {
        f32 x = *p;
        f32 y = *q;
        p += 2;
        q += 2;
        *(vu0_q *)a1 = *(vu0_q *)(a0 + 0x20);
        ((f32 *)a1)[0] += (x * s - y * c) * scale;
        ((f32 *)a1)[1] += (y * s + x * c) * scale;
        a1 += 0x10;
    }
}
