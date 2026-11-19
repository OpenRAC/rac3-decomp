/* functional: high. Adapted from NTSC draft with PAL callee names; with @ps2as 49 words differ (loop scheduling only: retail loop uses a raw bltzl); 1.2f literal bytes need ps2as; semantics read against asm */
typedef struct { s32 f0; s32 p4; s32 f8; s32 pC; s32 p10; u8 flag; u8 pad[3]; } E_0049B5A8;
extern E_0049B5A8 D_L01_002EBED8[];
extern u8 D_L01_002EBF38[];
extern s32 D_001D940C_sda;
__asm__(".extern D_001D940C_sda, 4");
extern s32 D_001D9408_sda;
__asm__(".extern D_001D9408_sda, 4");
extern s32 D_001D9404_sda;
__asm__(".extern D_001D9404_sda, 4");
extern void func_L01_0049C0C8(void);
extern void func_0038E150(s32);
extern void func_L01_00499B20(s32, f32 *, f32 *);
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_0049B8F8(void *);
extern void func_003E8348(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern void func_003E8710(s32, s32 *);
extern void func_003E87B8(s32, s32, s32);
extern void func_L01_0049BBD8(void);
extern void func_L01_0049C338(void);
extern void func_L01_0049C1D8(void);

void func_L01_0049B5A8(void) {
    f32 a;
    f32 b;
    s32 i;
    s32 n;
    E_0049B5A8 *p;

    i = 0;
    b = 0.0f;
    a = 1.2f;
    func_L01_0049C0C8();
    func_0038E150(0);
    func_L01_00499B20(0x1C2, &a, &b);
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x1C2), 0xD0006, 0x124, 0xD0007, 0xCD5, b);
    func_L01_00516818(0xD0005, a);
    func_L01_0049B8F8(D_L01_002EBF38);
    func_003E8348(0x11, 0x4E0000);
    func_003E7F20(0x4E0005, 1);
    func_003E7F20(0x4E0006, 1);
    func_003E8710(0x4E0009, (s32 *)func_003B42F8(0));
    func_L01_00517190(0x4E0009, 0);
    func_L01_00516D60(0x4E0009, 0);
    func_003E87B8(0x4E0009, 1, 8);
    func_L01_0049BBD8();
    func_L01_0049C338();
    D_001D940C_sda = -1;
    if (D_L01_002EBED8[0].f0 != 0) {
        n = -1;
        p = D_L01_002EBED8;
        do {
            if (p->flag) n = i;
            p++;
            i++;
        } while (p->f0 != 0 && n < 0);
        D_001D940C_sda = n;
    }
    if (D_001D940C_sda < 0) {
        if (D_001D9408_sda != 0) D_001D940C_sda = 0;
    }
    if (D_001D940C_sda >= 0) {
        func_L01_00517190(0x4E0009, D_L01_002EBED8[D_001D940C_sda].f8 + 1);
        func_L01_00516D60(0x4E0009, 1);
    }
    func_L01_00516D60(0x4E0009, 0);
    D_001D9404_sda = -1;
    func_L01_0049C1D8();
}
