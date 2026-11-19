/* functional: high. P08 reconstruction (510-557 diff: register allocation/scheduling only) re-verified block by block against the PAL asm: hit/damage branch, the three clamped HP bands (D_001E1AF0/AF8/B00), react state list, hero push-out logic, spawn of the 0x188 helper and the final flag byte at D_00142660+0x77. SDA aliases renamed to D_L32_ catalogue names; .extern hints dropped. */
extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern s32 D_L32_001DE984, D_L32_001DE988;
extern u8 D_L32_001DEB31;

extern s32 D_L32_001DE980, D_L32_001DE9C8;
extern s32 D_L32_001DE908, D_L32_001DE958, D_L32_001DE954;
extern u8 D_L32_001DEB30;
extern f32 D_L32_001E1AF0, D_L32_001E1AF8, D_L32_001E1B00;
extern f32 D_L32_001DE8E8, D_L32_001DE8E4, D_L32_001DE8F8, D_L32_001DE8FC;
extern f32 D_L32_001DE900, D_L32_001DE904, D_L32_001DE968, D_L32_001DEA90, D_L32_001DE9A8;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L32_003A40B0(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C4A40(void *, void *);
extern void func_L32_003A52A8(void *, s32);
extern f32 func_L30_0034CE78(void *);
extern void func_L31_003478E8(void *, void *, void *, s32, f32, f32, f32, f32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern u8 *func_L31_0034E0F0(void *, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L32_003A44A8(void);
void func_L32_003A45D8(u8 *a0) {
    vu0_v4 temp;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *hero = D_001A4BE0;
    u8 *hit;
    u8 *other;
    s32 knocked = 0;
    s32 react;
    s32 state;
    s32 kind;
    f32 factor;
    f32 amount;
    f32 x;
    f32 y;
    hit = (u8 *)func_L01_00447490(a0, 0x10000, 0);
    func_L32_003A40B0(a0);
    func_0038CAD0(s + 0xA4);
    func_0038CAD0(s + 0x128);
    if (*(s32 *)(s + 0x124) == -1) {
        a0[0x23] = 0x80;
        *(u16 *)(a0 + 0x34) &= 0xFFF7;
    }
    func_L01_0044ABD0(a0, s + 0x70);
    if (hit && *(f32 *)(hit + 0x2C) > 0.0f && a0[0x20] != 3 &&
        a0[0x20] != 0x42 && *(s32 *)(s + 0xA4) == 0 &&
        *(s32 *)(hit + 0x20) != 0) {
        kind = *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA);
        if (kind == *(s16 *)(*(u8 **)(hero + 0x25C0) + 0xAA) ||
            kind == 0x1678 || kind == 0x1E9B) {
            if (kind == 0x1678) func_003A52A0(13, 0, a0);
            if (*(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1E9B)
                *(f32 *)(hit + 0x2C) /= 3.0f;
            if (*(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1678)
                *(f32 *)(hit + 0x2C) = 2.0f;
            *(f32 *)(s + 0x30) -= *(f32 *)(hit + 0x2C);
            amount = *(f32 *)(s + 0x30) - (f32)D_L32_001DE984 - (f32)D_L32_001DE988;
            D_L32_001E1AF0 = amount;
            if (amount > (f32)D_L32_001DE980) D_L32_001E1AF0 = (f32)D_L32_001DE980;
            else if (amount < 0.0f) D_L32_001E1AF0 = 0.0f;
            amount = *(f32 *)(s + 0x30) - (f32)D_L32_001DE988;
            D_L32_001E1AF8 = amount;
            if (amount > (f32)D_L32_001DE984) D_L32_001E1AF8 = (f32)D_L32_001DE984;
            else if (amount < 0.0f) D_L32_001E1AF8 = 0.0f;
            amount = *(f32 *)(s + 0x30);
            D_L32_001E1B00 = amount;
            if ((f32)D_L32_001DE988 < amount) D_L32_001E1B00 = (f32)D_L32_001DE988;
            else if (amount < 0.0f) D_L32_001E1B00 = 0.0f;
            if (D_L32_001E1AF0 > 0.0f) *(s32 *)(s + 0xF8) = 0;
            else if (D_L32_001E1AF8 > 0.0f) *(s32 *)(s + 0xF8) = 1;
            else *(s32 *)(s + 0xF8) = 2;
            *(s32 *)(s + 0xA4) = 12;
            s[0x77] = 0xFF;
            func_003C4A40(a0, s + 0x70);
            if (((*(s32 *)(s + 0xF8) == 1 && !D_L32_001DEB30) ||
                 (*(s32 *)(s + 0xF8) == 2 && !D_L32_001DEB31)) &&
                *(s32 *)(s + 0xF4) != -1) {
                if (*(f32 *)(s + 0x98) > 0.0f) *(f32 *)(s + 0x98) = 0.0f;
                knocked = 1;
                *(s32 *)(s + 0xF4) = -1;
            }
            state = a0[0x20];
            react = 0;
            if (state != 1 && state != 0x42 && state != 3 && state != 4 &&
                (state != 7 || (*(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1678 && *(f32 *)(s + 0x98) <= 0.0f)) &&
                state != 8 && state != 9 && state != 10 && state != 11 && state != 12 &&
                state != 20 && state != 21 && state != 22 &&
                *(s32 *)(s + 0xF4) != -1 && *(s32 *)(s + 0xF4) != 0 && *(s32 *)(s + 0xF4) != 2) react = 1;
            if (*(f32 *)(s + 0x30) <= 0.0f) {
                *(f32 *)(a0 + 0xF8) = *(f32 *)(hit + 0x10) < 0.0f ? D_L32_001DE8E8 : D_L32_001DE8E4;
                func_L32_003A52A8(a0, 3);
            } else if (knocked) {
                *(f32 *)(a0 + 0xF8) = *(f32 *)(hit + 0x10) < 0.0f ? D_L32_001DE8E8 : D_L32_001DE8E4;
                func_L32_003A52A8(a0, 4);
            } else if ((react && *(s32 *)(s + 0x128) == 0) ||
                       *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1E9B) {
                *(f32 *)(a0 + 0xF8) = *(f32 *)(hit + 0x10) < 0.0f ? D_L32_001DE8E8 : D_L32_001DE8E4;
                func_L32_003A52A8(a0, 5);
            } else {
                *(s32 *)(s + 0x128) = D_L32_001DE9C8;
            }
        }
    }
    other = *(u8 **)(s + 0x168);
    if (other && other[0x20] >= 0xFD) *(s32 *)(s + 0x168) = 0;
    factor = 1.0f;
    if (*(f32 *)(hero + 0x88) > *(f32 *)(a0 + 0x18)) {
        amount = (*(f32 *)(hero + 0x88) - *(f32 *)(a0 + 0x18)) / D_L32_001DE8F8;
        if (!(amount < 0.0f)) factor -= amount;
    }
    amount = func_L30_0034CE78(*(void **)(hero + 0x25C0));
    if (*(f32 *)(a0 + 0x18) - D_L32_001DE8FC < *(f32 *)(hero + 0x88) + amount &&
        *(f32 *)(hero + 0x88) < *(f32 *)(a0 + 0x18) + D_L32_001DE8F8 + D_L32_001DE8FC &&
        fabs_asm(*(f32 *)(hero + 0x80) - *(f32 *)(a0 + 0x10)) < D_L32_001DE904 + factor * D_L32_001DE900 &&
        a0[0x20] != 8 && a0[0x20] != 9 && a0[0x23]) {
        if (*(f32 *)(hero + 0x80) < *(f32 *)(a0 + 0x10)) {
            if (*(f32 *)(hero + 0xF0) > 0.0f) *(f32 *)(hero + 0x100) -= *(f32 *)(hero + 0xF0);
            if (*(f32 *)(hero + 0x80) <= *(f32 *)(s + 0x178) + D_L32_001DE968) {
                amount = *(f32 *)(s + 0x178) + D_L32_001DE904;
                if (*(f32 *)(hero + 0x80) < amount) *(f32 *)(hero + 0x80) = amount;
                amount = *(f32 *)(hero + 0x80) + D_L32_001DE904 + factor * D_L32_001DE900;
                if (*(f32 *)(a0 + 0x10) < amount) *(f32 *)(a0 + 0x10) = amount;
            } else {
                amount = *(f32 *)(a0 + 0x10) - factor * D_L32_001DE900 - D_L32_001DE904;
                if (amount < *(f32 *)(hero + 0x80)) *(f32 *)(hero + 0x80) = amount;
            }
        } else {
            if (*(f32 *)(hero + 0xF0) < 0.0f) *(f32 *)(hero + 0x100) -= *(f32 *)(hero + 0xF0);
            if (*(f32 *)(s + 0x180) - D_L32_001DE968 <= *(f32 *)(hero + 0x80)) {
                amount = *(f32 *)(s + 0x180) - D_L32_001DE904;
                if (amount < *(f32 *)(hero + 0x80)) *(f32 *)(hero + 0x80) = amount;
                amount = *(f32 *)(hero + 0x80) - factor * D_L32_001DE900 - D_L32_001DE904;
                if (amount < *(f32 *)(a0 + 0x10)) *(f32 *)(a0 + 0x10) = amount;
            } else {
                amount = *(f32 *)(a0 + 0x10) + factor * D_L32_001DE900 + D_L32_001DE904;
                if (*(f32 *)(hero + 0x80) < amount) *(f32 *)(hero + 0x80) = amount;
            }
        }
    }
    if (hit) a0[0xA8] = 0xFF;
    other = *(u8 **)(s + 0x188);
    if (other) {
        if ((u8)(other[0x20] + 3) < 2) *(s32 *)(s + 0x188) = 0;
        else func_L31_003478E8(other, other + 0x10, s + 0x150, 0,
            -0.0095f, 0.5f, 0.07f, 0.05f, 0.05f, 0.08f, 0.0f);
    }
    if (*(s32 *)(s + 0x188) == 0 && *(s32 *)(hero + 0x1B08) <= 0 &&
        a0[0x20] != 19 && func_0038CAD0(s + 0x10C)) {
        temp = *(vu0_v4 *)(hero + 0x80);
        if (*(f32 *)(a0 + 0x10) < *(f32 *)(s + 0x17C)) {
            x = *(f32 *)(s + 0x17C);
            y = *(f32 *)(s + 0x180) - D_L32_001DEA90;
            amount = 0.33f;
        } else {
            x = *(f32 *)(s + 0x178) + D_L32_001DEA90;
            y = *(f32 *)(s + 0x17C);
            amount = 0.66f;
        }
        temp.x = func_003C4088(x, y, amount);
        temp.z = *(f32 *)(s + 0x174) + (D_L32_001DE9A8 + D_L32_001DE9A8);
        *(u8 **)(s + 0x188) = func_L31_0034E0F0(&temp, 3, D_L32_001DE908, 0, -1);
        *(s32 *)(s + 0x10C) = func_00382498(D_L32_001DE958, D_L32_001DE954);
        qzero(s + 0x150);
    }
    func_L01_00404A10(func_L32_003A44A8, a0);
    if (*(s32 *)(hero + 0x25C4) == 0x9F &&
        D_00142660[0x77] == *(s32 *)(hero + 0x1B38) &&
        a0[0x20] != 0x42 && a0[0x20] != 3 && a0[0x20] != 19) {
        if (!(D_00142660[0x77] & 8)) D_00142660[0x77] |= 8;
        else if (!(D_00142660[0x77] & 16)) D_00142660[0x77] |= 16;
        else D_00142660[0x77] |= 32;
    }
}
