/* functional: high. Same reads, writes and calls; only register allocation differs. a2 of func_003B78F8 is the leftover $6 = s->w10 in retail and is passed explicitly. */
extern u8 D_001BBC40[];
extern s32 D_001D545C[];
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_003B78F8(u8 *, u8 *, s32, f32);

void func_L01_003B5FD8(u8 *m, u8 *unused) {
    u8 *s = *(u8 **)(m + 104);
    s32 a2;
    s32 idx;

    *(s32 *)(s + 104) = 255;
    *(s32 *)(s + 36) = 0;
    *(s32 *)(s + 96) = 0;
    *(s32 *)(s + 100) = 0;
    *(s32 *)(s + 76) = 0;
    *(s32 *)(s + 192) = 0;
    *(s32 *)(s + 196) = 0;
    *(s32 *)(s + 120) = 0;
    *(s32 *)(s + 124) = 0;
    *(s32 *)(s + 140) = 0;
    *(s32 *)(s + 284) = 0;
    if (m[32] == 4) {
        m[188] = 2;
    } else {
        func_L01_004450F0((s32)m, 2, -1);
    }
    *(u16 *)(m + 52) &= 0xFFFD;
    a2 = *(s32 *)(s + 16);
    if (a2 <= 0) {
        return;
    }
    idx = *(s32 *)(s + 272);
    if (idx != -1) {
        if ((D_001BBC40[idx + (D_001D545C[0] << 4)] & 0x80) == 0) {
            return;
        }
    }
    idx = *(s32 *)(s + 276);
    if (idx != -1) {
        if ((D_001BBC40[idx + (D_001D545C[0] << 4)] & 0x80) != 0) {
            return;
        }
    }
    func_L01_003B78F8(m, s, a2, *(f32 *)(s + 20));
    if (*(f32 *)(s + 12) != *(f32 *)(s + 20)) {
        *(s32 *)(s + 100) = 0;
        *(s32 *)(s + 96) = 0;
    }
}
