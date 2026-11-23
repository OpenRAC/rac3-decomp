/* functional: high. 148 instruction positions differ at L01 (frame 0x70 vs 0x80, loop layout and register allocation); same calls with the same arguments, same switch constants (0x20 / 0xB20 / 0xD20 | 0x42) and same -1 / index returns. Needs vu0.h (already in this file's prelude). */
extern s32 D_L01_001E1060[];
extern s32 D_L01_001E1068;
extern s32 D_L01_001E1070;
extern s32 D_L01_001E1074;
extern s32 D_L01_001DFC08;
extern s32 D_001DFC08_sda;
__asm__(".extern D_001DFC08_sda, 4");
extern s32 D_001D545C;
extern u8 D_L01_001EAA20[];
extern void func_003A92F0(s32);
extern s32 func_L01_003FB640(void *, s32, s32, f32);
extern s32 func_L01_003FE1E8(void *, void *, s32, s32);

s32 func_L01_003F8820(u8 *self) {
    vu0_v4 L[4];
    u8 *m = *(u8 **)(self + 0x68);
    s32 r;
    s32 i;
    s32 j;
    s32 a1;
    s32 n;
    s32 found;
    f32 d;

    func_0038D000(&L[0], m + 0x20, self + 0xC0);
    vec_add_ba(&L[0], &L[0], self + 0x10);
    D_001DFC08_sda = D_L01_001E1060[D_L01_001E1074] + D_L01_001E1070 - 0x8000;
    if (D_001DFC08_sda < D_L01_001E1068) {
        func_003A92F0(1);
        D_L01_001DFC08 = D_L01_001E1060[1 - D_L01_001E1074] + D_L01_001E1070 - 0x8000;
    }
    switch (D_001D545C) {
    case 0x2A:
    case 0x2D:
        a1 = 0xB20;
        break;
    case 0x29:
        a1 = 0xD20;
        break;
    default:
        a1 = 0x20;
        break;
    }
    r = func_L01_003FB640(&L[0], a1 | 0x42, *(s32 *)(m + 0x54), *(f32 *)(m + 0x2C));
    if (r == 0) {
        m[0x5C] = 0;
        return -1;
    }
    for (i = 0; i < m[0x58]; i++) {
        found = 0;
        for (j = 0; j < m[0x5C]; j++) {
            if (m[0x59 + j] == i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            func_0038D000(&L[1], *(u8 **)(m + 0x30) + (i << 4), self + 0xC0);
            vec_add_ab(&L[1], &L[1], self + 0x10);
            if (func_L01_003FE1E8(&L[0], &L[1], r, 0) != 0) {
                vec_sub_ab(&L[2], &L[1], D_L01_001EAA20);
                func_0038CF68(D_L01_001EAA20 + 0x20, D_L01_001EAA20 + 0x20, 1.0f);
                d = func_0038CE68(&L[2], D_L01_001EAA20 + 0x20);
                func_0038CF68(&L[3], D_L01_001EAA20 + 0x20, -d);
                vec_add_ab(self + 0x10, self + 0x10, &L[3]);
                return i;
            }
        }
    }
    return -1;
}
