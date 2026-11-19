/* functional: high. same calls/stores/order; only register allocation and scheduling differ */
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_00284320[];
extern u8 *D_001E1A20_sda;
extern u8 *D_L01_001E1A20[];
extern f32 D_001DD654_sda;
extern u8 *func_003C24B0(s32, s32);
extern s32 func_L01_00456160(void *, u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_L01_0044FD88(u8 *, u8 *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_00357E70(u8 *a0) {
    u8 tmp[0x50] __attribute__((aligned(16)));
    u8 *obj = *(u8 **)(a0 + 0x68);
    u8 **p = &D_L01_001E1A20[1];
    s32 i;
    u8 *row;
    D_001E1A20_sda = a0;
    func_L01_0043B9E8(a0, 0x40, 0x10, 0x80);
    for (i = 1; i < 10; i++) {
        *p = func_003C24B0(i < 9 ? 0x183A : 0x183C, 0x80);
        func_L01_00456160(*p, a0);
        row = D_L01_002C5600 + D_001425C0[0x7F] * 0xF0;
        if (row[1] < 4) *(u16 *)(*p + 0x34) |= 0x200;
        (*p)[0x23] = 0x3C;
        row = D_L01_002C5600 + D_001425C0[0x7F] * 0xF0;
        if (row[1] == 0) func_L01_0043B9E8(*p, 0xBF, 0x40, 0x20);
        else if (row[1] == 1) func_L01_0043B9E8(*p, 0x20, 0x40, 0xBF);
        func_L01_0043B9E8(*p, 0xBF, 0x40, 0x20);
        p++;
        *(f32 *)(p[-1] + 0x2C) = *(f32 *)(*(u8 **)(p[-1] + 0x24) + 0x24) * 0.2f;
        func_L01_0044FD88(p[-2], p[-1], 0, 0);
        func_003C2EC0(p[-2], 0, tmp + 0x10);
        func_0038CF68(tmp, tmp + 0x10, 0.1f);
        vec_add_ab(D_L01_00284320 + i * 16, tmp, tmp + 0x40);
    }
    func_003C2F58(D_L01_001E1A20[0], 0, tmp);
    *(vu0_q *)obj = *(vu0_q *)tmp;
    *(f32 *)(obj + 0x14) = D_001DD654_sda;
}
