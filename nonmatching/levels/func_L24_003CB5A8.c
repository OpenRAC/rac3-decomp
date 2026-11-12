/* func_L24_003CB5A8: level 24 near miss. 16 differences (needs .extern size hints for the $gp-relative buffers D_L24_001E1B30/70 and K&R declarations of the later-defined func_L24_003CB900/003CB990 and func_11B2E8): left is the block layout of case 2's tail (retail puts the p[1]>1 arm after the shared func_L24_0042BAC0 call and uses bne where this C gets bnel), and the argument-move order of the second func_11B2E8 call; if/else orders, a variable for the func_L24_003591B0 argument, return instead of break were tried */
extern u8 D_L24_001A4C60[];
extern s16 D_L24_001A4DC0[];
extern u8 *D_L24_001D52FC;
extern u8 D_L24_001DEAD0[];
__asm__(".extern D_L24_001E1B30, 8");
__asm__(".extern D_L24_001E1B70, 8");
extern u8 D_L24_001E1B30[8];
extern u8 D_L24_001E1B70[8];
extern f32 func_L24_003F6780(void *, void *);
extern void func_L24_00437D98(s32, s32, s32, s32, s32, s32, s32);
extern void func_L24_0042BAC0(void *, s32, s32);
extern s32 func_L24_0043B9C0(void *);
extern u8 *func_L24_003CB900();
extern void func_L24_003CB990();
extern u8 *func_L24_00402BC8(s32);
extern void func_11B2E8();
extern void func_L24_003591B0(s32);

void func_L24_003CB5A8(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    s32 v;
    switch (a0[0x20]) {
    case 0:
        p[1] = -1;
        func_L24_0042BAC0(a0, 1, -1);
        break;
    case 1:
        if (func_L24_003F6780(a0 + 0x10, D_L24_001A4C60) <= 2.5f) {
            func_L24_00437D98(0, 0xD, 0x169F, 1, 0, 0, 0);
            if (*(u32 *)(D_L24_001D52FC + 0x1A4) & 0x10) {
                func_L24_0042BAC0(a0, 2, -1);
            }
        }
        break;
    case 2:
        D_L24_001A4DC0[0] = 5;
        if (func_L24_0043B9C0(a0) != 0) {
            p[1] = -1;
            p[0] = (s32)func_L24_003CB900(a0);
            func_11B2E8(D_L24_001E1B30, D_L24_001DEAD0, func_L24_00402BC8(0x16A1));
            func_11B2E8(D_L24_001E1B70, D_L24_001DEAD0, func_L24_00402BC8(0x16A3));
            func_L24_003CB990(p[0], &p[1], D_L24_001E1B30, 4);
            func_L24_003CB990(p[0], &p[1], D_L24_001E1B70, 4);
        }
        func_L24_00437D98(0, 1, 0, 1, 0, 0, 0);
        if (p[0] != 0 && *(s16 *)(p[0] + 0xAA) == 0x1F13 && *(u8 *)(p[0] + 0x20) != 0xFE && *(u8 *)(p[0] + 0x20) != 0xFD) {
            break;
        }
        if (p[1] == 0) {
            v = 0x1E;
        } else if (p[1] == 1) {
            v = 0x24;
        } else {
            func_L24_0042BAC0(a0, 1, -1);
            break;
        }
        func_L24_003591B0(v);
        func_L24_0042BAC0(a0, 1, -1);
        break;
    }
}
