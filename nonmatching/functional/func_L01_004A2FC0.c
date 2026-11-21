/* functional: high. Same calls, arguments and order as retail (read against the asm); retail loads the float constants with lui/ori+mtc1 where this uses small-data loads, which is bytes only. Twin of the func_L01_0049D5E8 menu setup (same func_003B9298 window call, 0x1CF title string). */
extern f32 D_L01_001DC0E8[];
extern f32 D_L01_001DC0EC[];
extern char D_L01_001D96D8[];
extern char D_L01_001D9728[];
extern s32 D_L01_001D96C0;
extern s32 D_L01_001D96C4;
__asm__(".extern D_L01_001D9728, 8");
__asm__(".extern D_L01_001D96D8, 8");
__asm__(".extern D_L01_001D96C0, 4");
__asm__(".extern D_L01_001D96C4, 4");
extern u16 D_001A8EC8[];
extern u8 D_L01_002EDB38[];
extern void func_0038E150(s32);
extern char *func_00381FF0(s32);
extern s32 func_0038E548(char *, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_004A2560(void *);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_L01_00516818(s32, f32);
extern s32 func_003E7AC8(s32, s32);
extern void func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00516D60(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern void func_L01_004A2BE0(void);

void func_L01_004A2FC0(void) {
    s32 scale = 0;
    f32 width;
    f32 ratio;
    f32 maxWidth = 0.49f;
    f32 low = 6.0f;
    f32 high = 11.0f;
    f32 zoom = 0.0f;
    f32 zero = 0.0f;
    func_L01_004A2840();
    func_0038E150(0);
    ratio = (f32)func_0038E548(func_00381FF0(0x1CF), -1, 1.2f) / D_L01_001DC0E8[0];
    if (ratio > maxWidth) {
        scale = 1;
        zoom = 0.58800006f / ratio;
        ratio = maxWidth;
    }
    width = func_003C4088(low, high, (ratio - zero) / maxWidth);
    if (width > high) width = high;
    else if (width < low) width = low;
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_00381FF0(0x1CF), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    func_L01_00516FD8(0xD0006, D_L01_001D9728);
    if (scale) func_L01_00517538(0xD0005, zoom, zoom);
    func_L01_004A2560(D_L01_002EDB38);
    func_L01_00516FD8(0x580004, func_00381FF0(0x1CF));
    func_L01_00516FD8(0x580005, D_L01_001D96D8);
    func_L01_00516B90(0x580004, 3, 3);
    func_L01_00516B90(0x580005, 3, 3);
    func_L01_00516818(0x580003, 1.0f);
    func_003E7AC8(0x580003, 1);
    func_L01_00516728(0x580003, 2.0f / D_L01_001DC0E8[0], 2.0f / D_L01_001DC0EC[0]);
    func_L01_00517BF8(0x580003, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0x580003, 0xB4, 0, 0.0005f);
    func_L01_00516D60(0x580003, 1);
    func_003E8348(0x11, 0x580000);
    func_003E7F20(0x580003, 1);
    func_L01_004A2BE0();
    D_L01_001D96C4 = D_L01_001D96C0 - 1;
    func_L01_00516FD8(0x580003, func_00381FF0(D_001A8EC8[D_L01_001D96C4]));
}
