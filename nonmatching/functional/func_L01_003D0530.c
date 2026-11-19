/* functional: high. functional: high. Same control flow, calls, constants and offsets as retail; differs in register allocation */
extern void *func_L01_0043B548(s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern s32 func_L01_0041A4F0(void);
extern u8 D_001BBC40[];
extern u8 D_0014275B[];
extern s32 D_001D545C[];
extern f32 D_L01_002F16F0[];
extern s32 D_001D545C_sda;
extern f32 D_001DAA38_sda;
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DAA38_sda, 4");

s32 func_L01_003D0530(u8 *self, u8 *obj) {
    u8 *h;
    u8 *p;
    s32 t3;
    s32 i;
    s32 sel;
    f32 f0;

    h = func_L01_0043B548(0x19E1, 0x6C);
    if (h == 0) {
        obj[0xB0] = 0;
    } else {
        if (((s32 (*)(u8 *))*(s32 *)(h + 0x50))(self + 0x10) != 0) {
            obj[0xB0] = 1;
        } else {
            obj[0xB0] = 0;
        }
    }
    obj[0xB1] = 0;
    t3 = *(s32 *)(obj + 0x24);
    if (t3 != -1) {
        if ((D_001BBC40[t3 + D_001D545C[0] * 16] & 0x80) != 0 && obj[0xB0] == 0 && *(s32 *)(obj + 0x40) == -1) {
            func_003C2880((s32)self);
            return 0;
        }
    }
    self[0x30] = (*(s32 *)(obj + 0x6C) == -1) ? 0x40 : 0xFF;
    p = obj + 0x180;
    func_0038CB78(p, 0, 0x1E00);
    for (i = 0; i < 0x9F; i++) {
        *(u8 **)(p + 0x28) = p + 0x30;
        p += 0x30;
    }
    *(u8 **)(obj + 0x138) = obj + 0x180;
    if (*(s32 *)(obj + 0xE4) < 0) {
        *(s32 *)(obj + 0xE4) = 0;
    }
    func_0038D308(self + 0xC0, self + 0xF0);
    *(s32 *)(obj + 0x50) = 0;
    *(s32 *)(obj + 0xB4) = 0;
    *(s32 *)(obj + 0x4C) = -1;
    if (func_L01_0041A4F0() != 0) {
        sel = D_001D545C_sda;
        f0 = D_L01_002F16F0[sel];
        if (sel == 7 && D_0014275B[0] != 0) {
            f0 = D_001DAA38_sda;
        }
        *(s32 *)(obj + 0x48) = (s32)((f32)*(s32 *)(obj + 0x48) * f0);
    }
    func_L01_004450F0((M3C7568 *)self, 1, -1);
    return 1;
}
