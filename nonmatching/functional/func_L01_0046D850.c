/* functional: high. Written from PAL asm; third argument of func_0038CF68 is the f12 computed just before; vadd.xyz keeps the old w. */
extern void func_003C2EC0(void *, s32, void *);
void func_L01_0046D850(u8 *p) {
    u8 *parent = *(u8 **)(p + 0x30);
    f32 f20, f22, r;
    vu0_v4 anchor;
    vu0_v4 off;
    if (parent == 0 || *(s16 *)(parent + 0xAA) != *(s16 *)(p + 0x36) || parent[0x20] == 0xFE || parent[0x20] == 0xFD) {
        func_003CD250((Obj *)p);
        return;
    }
    f20 = *(f32 *)(p + 0x38) * func_003824E0(0.05f, 1.0f);
    f22 = *(f32 *)(p + 0x2C);
    func_003C2F58(*(u8 **)(p + 0x30), p[0x34], p + 0x10);
    func_003C2EC0(*(u8 **)(p + 0x30), p[0x34], &anchor);
    r = func_003824E0(-(f32)p[0x35], (f32)p[0x35]);
    func_0038CF68(&off, &anchor, (r / 100.0f - 1.0f) * *(f32 *)(p + 0x3C));
    *(vu0_v4 *)(p + 0x20) = *(vu0_v4 *)(p + 0x10);
    ((f32 *)(p + 0x20))[0] = ((f32 *)(p + 0x10))[0] + off.x;
    ((f32 *)(p + 0x20))[1] = ((f32 *)(p + 0x10))[1] + off.y;
    ((f32 *)(p + 0x20))[2] = ((f32 *)(p + 0x10))[2] + off.z;
    *(f32 *)(p + 0x2C) = f22;
    *(f32 *)(p + 0x1C) = f20;
}
