/* functional: high. No draft; written from asm. 68 diff words regalloc/scheduling. D_001D52F0/D_001D67C8 are read via both gp and lui in retail; one name used */
extern f32 D_L01_001E7580[];
extern s32 D_001D545C[];
extern s32 D_001D52F0[];
extern s32 D_L01_002D15F0[];
extern u8 *D_L01_001D67C8[];
extern s32 D_001DB784_sda;
extern s32 D_001DB788_sda;
extern void func_003873C0(void);
extern void func_L01_004D2110(u8 *);
extern void func_L01_004D1700(u8 *);
extern u32 func_L01_004D0CB0(u8 *);
extern void func_L01_004D21E0(u8 *, s32, s32, s32, s32);
extern void func_003AD278(u8 *);
extern void func_L01_004365D0(void);

void func_L01_004D24C0(u8 *obj) {
    f32 saved = D_L01_001E7580[0x2C];
    u8 *v;
    u32 r;

    D_L01_001E7580[0x2C] = 0.62f;
    func_003873C0();
    func_L01_004D2110(obj);
    if (D_001D545C[0] != -2) {
        func_L01_004D1700(obj + D_001D52F0[0] * 0xB50 + 0x18A0);
    }
    if (D_L01_002D15F0[0] == 0) {
        if (D_001D545C[0] != -2) {
            r = func_L01_004D0CB0(obj + D_001D52F0[0] * 0xB50 + 0x18A0);
            func_L01_004D21E0(obj, D_001D52F0[0], D_001DB784_sda, D_001DB788_sda, r >> 24);
        }
    }
    v = D_L01_001D67C8[0];
    *(s32 *)(v + 0x24DD8) = 0;
    *(s32 *)(v + 0x24DD4) = 0;
    func_003AD278(obj + 0x4ED0);
    func_L01_004365D0();
    D_L01_001E7580[0x2C] = saved;
    func_003873C0();
}
