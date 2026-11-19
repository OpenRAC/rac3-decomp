/* functional: high. Branch-for-branch port of the asm; diffs are s0/s1 register swap and code layout. The retail reads the slot type (+0xCA) of entry -1 before checking k==-1 (harmless read); the C checks k first. */
extern u8 D_001A30B0[];
extern u8 D_L05_001FEEB6[];
extern s32 func_L01_004AA710(u8 *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);

void func_L05_00329120(u8 *o, u8 *s) {
    s32 k;
    u8 *e;
    s32 r;

    if (*(s16 *)(o + 0xAA) == 0x1C82) {
        if (o[0x20] == 3 && 0.0f < *(f32 *)(s + 0x168)) {
            if (func_L01_004AA710(o, *(s32 *)(s + 0x16C)) != 0) {
                k = *(s32 *)(s + 0x16C);
                if (k != -1 && *(s16 *)(D_001A30B0 + k * 128 + 0xCA) == 0) {
                    e = D_001A30B0 + k * 128;
                    if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                        func_003A4F28(k);
                    }
                    *(s32 *)(s + 0x16C) = -1;
                } else if (k == -1) {
                    *(s32 *)(s + 0x16C) = -1;
                }
            }
            if (func_L01_004AA710(o, *(s32 *)(s + 0x16C)) != 0) {
                return;
            }
            k = *(s32 *)(s + 0x16C);
            if (k != -1) {
                e = D_001A30B0 + k * 128;
                if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                    return;
                }
            }
            *(s32 *)(s + 0x16C) = func_003A52A0(1, 4, o);
        } else {
            if (func_L01_004AA710(o, *(s32 *)(s + 0x16C)) != 0) {
                k = *(s32 *)(s + 0x16C);
                if (k != -1 && *(s16 *)(D_001A30B0 + k * 128 + 0xCA) == 1) {
                    e = D_001A30B0 + k * 128;
                    if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                        func_003A4F28(k);
                    }
                    *(s32 *)(s + 0x16C) = -1;
                } else if (k == -1) {
                    *(s32 *)(s + 0x16C) = -1;
                }
            }
            if (func_L01_004AA710(o, *(s32 *)(s + 0x16C)) != 0) {
                return;
            }
            k = *(s32 *)(s + 0x16C);
            if (k != -1) {
                e = D_001A30B0 + k * 128;
                if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                    return;
                }
            }
            *(s32 *)(s + 0x16C) = func_003A52A0(0, 4, o);
        }
    } else {
        k = *(s32 *)(s + 0x16C);
        if (o[0x20] == 3 && 0.0f < *(f32 *)(s + 0x168)) {
            if (func_L01_004AA710(o, k) != 0) {
                return;
            }
            if (D_L05_001FEEB6[0] == 0xFF) {
                return;
            }
            *(s32 *)(s + 0x16C) = func_L01_004AAC98(0, 4, o, 0x1626);
            return;
        }
        if (k != -1) {
            e = D_001A30B0 + k * 128;
            if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                func_003A4F28(k);
            }
        }
        *(s32 *)(s + 0x16C) = -1;
    }
}
