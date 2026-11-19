/* functional: high. Diffs at default flags are scheduling and the retail's repeated pure re-evaluation of the item type (five times); we compute it once. Digit buffer D_L01_001D96D8 is separate symbols D_001D96D9/DA/DB in retail, same bytes. */
extern s32 D_L01_001D96C0;
extern s32 D_L01_001D96C4;
extern s32 D_L01_001D96C8;
extern char D_L01_001D96D8[];
extern char D_L01_001D9710[];
extern s32 D_L01_001E0D28;
extern f32 D_L01_001E0D24;
extern f32 D_L01_001DC0E8;
extern s32 D_L01_001DFCC0[];
extern u16 D_001A8EC8[];
__asm__(".extern D_L01_001D96C0, 4");
__asm__(".extern D_L01_001D96C4, 4");
__asm__(".extern D_L01_001D96C8, 4");
__asm__(".extern D_L01_001D96D8, 8");
__asm__(".extern D_L01_001D9710, 8");
__asm__(".extern D_L01_001E0D28, 4");
__asm__(".extern D_L01_001E0D24, 4");
extern void func_0038E150(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(void *);
extern s32 func_00381F80(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516FD8(s32, void *);
void func_L01_004A28C8(void) {
    s32 v;
    s32 sel;
    s32 ones;
    s32 tens;
    s32 hundreds;
    s32 type;
    func_0038E150(1);
    if (D_L01_001D96C0 == 0) {
        D_L01_001D96D8[0] = 0;
        func_L01_00516FD8(0x580003, D_L01_001D9710);
        return;
    }
    v = D_L01_001D96C0 - func_003B9C58(func_003B9BD0(0));
    ones = v % 10;
    tens = (v / 10) % 10;
    hundreds = (v / 100) % 10;
    D_L01_001D96C4 = v - 1;
    if (hundreds != 0) {
        D_L01_001D96D8[0] = hundreds + '0';
        D_L01_001D96D8[1] = tens + '0';
        D_L01_001D96D8[2] = ones + '0';
        D_L01_001D96D8[3] = 0;
    } else if (tens != 0) {
        D_L01_001D96D8[0] = tens + '0';
        D_L01_001D96D8[1] = ones + '0';
        D_L01_001D96D8[2] = 0;
    } else {
        D_L01_001D96D8[0] = ones + '0';
        D_L01_001D96D8[1] = 0;
    }
    sel = D_L01_001D96C4;
    if (sel < 0) {
        return;
    }
    if (D_L01_001D96C8 != sel) {
        if (D_L01_001E0D28 == 0) {
            D_L01_001E0D28 = 1;
            D_L01_001E0D24 = 65.0f / D_L01_001DC0E8;
        }
        type = *(s16 *)((u8 *)D_L01_001DFCC0[0] + (func_00381F80(D_001A8EC8[D_L01_001D96C4]) << 4) + 0xE);
        if (type == 0x1DC || type == 0xB0E || type == 0x150E || type == 0x166A || type == 0x1736) {
            func_L01_00516470(0x580003, D_L01_001E0D24 * 0.5f + 0.500369012f, 0.337772012f);
            func_L01_00517538(0x580003, 0.775758028f - D_L01_001E0D24, 0.356963992f);
        } else {
            func_L01_00516470(0x580003, 0.500369012f, 0.337772012f);
            func_L01_00517538(0x580003, 0.775758028f, 0.356963992f);
        }
        func_L01_00516FD8(0x580003, (void *)func_00381FF0(D_001A8EC8[D_L01_001D96C4]));
    }
    D_L01_001D96C8 = D_L01_001D96C4;
}
