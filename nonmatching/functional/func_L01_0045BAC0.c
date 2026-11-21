/* functional: high. VU0 vsub.xyz as scalar math; compiles under file flags, not byte exact. a0 of func_L01_00476F10 is b+0x3C (retail passes it by register left from the earlier load). */
extern s32 func_L01_00476F10(s32, f32, u8 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
s32 func_L01_0045BAC0(u8 *self, u8 *b) {
    f32 q[4] __attribute__((aligned(16)));
    f32 *sp = (f32 *)(self + 16);
    f32 *d;
    if (*(s32 *)(b + 60) == -1) {
        return 0;
    }
    if (*(s32 *)(b + 156) & 1) {
        return 0;
    }
    q[0] = sp[0];
    q[1] = sp[1];
    q[2] = sp[2];
    q[3] = sp[3];
    if (func_L01_00476F10(*(s32 *)(b + 60), *(f32 *)b, (u8 *)q, sp) == 0) {
        return 0;
    }
    d = (f32 *)(b + 96);
    d[0] = q[0] - sp[0];
    d[1] = q[1] - sp[1];
    d[2] = q[2] - sp[2];
    d[3] = q[3];
    func_0038CF68(d, d, *(f32 *)b);
    *(s32 *)(b + 148) |= 16;
    return 1;
}
