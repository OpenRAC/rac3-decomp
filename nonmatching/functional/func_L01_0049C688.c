/* functional: high. Ported from NTSC draft with PAL names; read against asm: last call uses mode 8 here (draft had 10); selection logic with gp slots 9478/9474/9470/9468; float constants and reg allocation differ in bytes only */
extern char D_L01_002EC5D8[];
extern E_498978 D_L01_002EC368[];
extern s32 D_001D9478_sda;
__asm__(".extern D_001D9478_sda, 4");
extern s32 D_001D9474_sda;
__asm__(".extern D_001D9474_sda, 4");
extern s32 D_001D9470_sda;
__asm__(".extern D_001D9470_sda, 4");
extern s32 D_001D9468_sda;
__asm__(".extern D_001D9468_sda, 4");
extern f32 D_L01_001DC0E8;
extern void func_L01_0049D0F8(void);
extern s32 func_00381FF0(s32);
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_0049CA28(void *);
extern void func_003E8348(s32, s32);
extern void *func_003B42F8(s32);
extern void func_003E8710(s32, void *);
extern void func_L01_0049CD08(void);
extern void func_L01_0049D2E8(void);
extern s32 *func_003B9BD0(s32);
extern void func_L01_004986A8(s32 *, s32);
extern void func_003E87B8(s32, s32, s32);

void func_L01_0049C688(void) {
    s32 i = 0, flag = 0, index;
    f32 scale = 0.0f, start = 0.0f, ratio, value;

    func_L01_0049D0F8();
    ratio = (f32)func_0038E548(func_00381FF0(0x1C3), -1, 1.2f) / D_L01_001DC0E8;
    if (ratio > 0.49f) {
        flag = 1;
        scale = 0.58800006f / ratio;
        ratio = 0.49f;
    }
    value = func_003C4088(6.0f, 11.0f, (ratio - start) / 0.49f);
    if (value > 11.0f) value = 11.0f;
    else if (value < 6.0f) value = 6.0f;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x1C3), 0xD0006, 0x124, 0xD0007, 0xCD5, value);
    if (flag) func_L01_00517538(0xD0005, scale, scale);
    func_L01_0049CA28(D_L01_002EC5D8);
    func_003E8348(0x11, 0x4E0000);
    func_003E8710(0x4E0003, func_003B42F8(1));
    func_L01_00517190(0x4E0003, 0);
    func_L01_0049CD08();
    func_L01_0049D2E8();
    D_001D9478_sda = -1;
    index = -1;
    if (D_L01_002EC368[i].x0) {
        do {
            if (D_L01_002EC368[i].x14) index = i;
            i++;
        } while (D_L01_002EC368[i].x0 && index < 0);
        D_001D9478_sda = index;
    }
    if (D_001D9478_sda < 0 && D_001D9470_sda) D_001D9478_sda = 0;
    if (D_001D9474_sda >= 0) func_L01_004986A8(func_003B9BD0(0), D_001D9474_sda);
    D_001D9468_sda = -1;
    D_001D9474_sda = -1;
    func_L01_00516D60(0x4E0003, 0);
    func_003E87B8(0x4E0003, 1, 8);
}
