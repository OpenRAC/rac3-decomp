/* functional: high. Jump table jtbl_002BE450 read from data.data.s (0->25B0 then falls into case 3 body, 1/2/>=7 default). D_001D6694 read via $gp (D_001D6694_sda). */
/* localdecomp:start func_L03_003B2570 */
extern u8 D_00142CBE;
extern u8 D_00142CC2;
__asm__(".extern D_001D6694_sda, 4");
extern s32 D_001D6694_sda;
extern s32 func_L01_004BA800(void);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C2880(u8 *);
extern s32 func_0038CAD0(s32 *);
extern s32 func_00382498(s32, s32);
extern void func_L03_003B27D0(u8 *);
void func_L03_003B2570(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 r;
    s32 do_move = 0;
    switch (m[0x20]) {
    case 0:
        if (D_00142CBE != 0) {
            if (m[0x43] != 0) func_003C3A10(m, 0, 0, 8);
            func_L01_004450F0(m, 3, -1);
            do_move = 1;
        } else {
            func_003C2880(m);
            return;
        }
        break;
    case 3:
        do_move = 1;
        break;
    case 4:
        if (func_L01_004561B8(m) != 0 && m[0x43] != 2) func_003C3A10(m, 2, 0, 8);
        break;
    case 5:
        if (func_L01_004561B8(m) != 0 && m[0x43] != 3) func_003C3A10(m, 3, 0, 8);
        break;
    case 6:
        if (func_L01_004561B8(m) != 0 && m[0x43] != 4) func_003C3A10(m, 4, 0, 8);
        break;
    default:
        break;
    }
    if (do_move) {
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 0) func_003C3A10(m, 0, 0, 8);
            r = func_00382498(0x226, 0x352);
            *(s32 *)(v + 0x128) = (r * 5 + 2) / 6;
        }
        if (func_0038CAD0((s32 *)(v + 0x128)) != 0) {
            r = func_00382498(0x226, 0x352);
            *(s32 *)(v + 0x128) = (r * 5 + 2) / 6;
            if (m[0x43] != 1) func_003C3A10(m, 1, 0, 0x11);
        } else if (m[0x60] & 2) {
            if (m[0x43] != 0) func_003C3A10(m, 0, 0, 0x11);
        }
    }
    if (D_001D6694_sda == 2) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0 && D_00142CC2 == 0) {
        m[0x31] = 1;
        *(u16 *)(m + 0x34) &= 0xFFFE;
    }
    func_L03_003B27D0(m);
}
/* localdecomp:end func_L03_003B2570 */
