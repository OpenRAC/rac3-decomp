/* functional: high. Jump table jtbl_002BE430 read from data.data.s (0->1EC8, 2->1F9C, 3,4,5->same-shape cases, 1 and >=6 -> default). Globals D_001426E0/D_00142CA0 boot data bytes. Semantics of D_00142CA0[0x1E] flag unknown. */
/* localdecomp:start func_L03_003B1E38 */
extern s32 D_L03_001D6694;
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern u8 *D_L03_001DFA80;
typedef int Q_3B1E38 __attribute__((mode(TI)));
extern s32 func_L01_004BA800(void);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C2880(u8 *);
extern s32 func_0038CAD0(s32 *);
extern s32 func_00382498(s32, s32);
extern void func_L03_003B2158(u8 *);
extern void func_L03_003B2518(u8 *);
void func_L03_003B1E38(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 r;
    if (D_L03_001D6694 == 2) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        m[0x31] = 1;
        *(u16 *)(m + 0x34) &= 0xFFFE;
    }
    switch (m[0x20]) {
    case 0:
        if (D_001426E0[0x3D] != 0 && D_001426E0[0x85] == 0) {
            u8 *p = D_L03_001DFA80 + (*(s32 *)(v + 0x120) << 7);
            u8 had = m[0x43];
            *(Q_3B1E38 *)(m + 0x10) = *(Q_3B1E38 *)(p + 0x30);
            *(Q_3B1E38 *)(m + 0xF0) = *(Q_3B1E38 *)(p + 0x70);
            if (had != 0) func_003C3A10(m, 0, 0, 8);
            func_L01_004450F0(m, 1, -1);
        } else if (D_00142CA0[0x1E] != 0) {
            if (m[0x43] != 1) func_003C3A10(m, 1, 0, 8);
            func_L01_004450F0(m, 2, -1);
        } else {
            func_003C2880(m);
            return;
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 1) func_003C3A10(m, 1, 0, 8);
            r = func_00382498(0x258, 0x320);
            *(s32 *)(v + 0x12C) = (r * 5 + 2) / 6;
        }
        if (*(s32 *)(v + 0x114) == 0) {
            if (func_0038CAD0((s32 *)(v + 0x12C)) != 0) {
                r = func_00382498(0x258, 0x320);
                *(s32 *)(v + 0x12C) = (r * 5 + 2) / 6;
                if (m[0x43] != 2) func_003C3A10(m, 2, 0, 0x11);
            }
        }
        if (m[0x60] & 2) {
            if (m[0x43] != 1) func_003C3A10(m, 1, 0, 0x11);
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0 && m[0x43] != 3) func_003C3A10(m, 3, 0, 8);
        break;
    case 4:
        if (func_L01_004561B8(m) != 0 && m[0x43] != 4) func_003C3A10(m, 4, 0, 8);
        break;
    case 5:
        if (func_L01_004561B8(m) != 0 && m[0x43] != 5) func_003C3A10(m, 5, 0, 8);
        break;
    default:
        break;
    }
    func_L03_003B2158(m);
    if (D_00142CA0[0x1E] != 0) {
        if (m[0x20] != 1) func_L03_003B2518(m);
    }
}
/* localdecomp:end func_L03_003B1E38 */
