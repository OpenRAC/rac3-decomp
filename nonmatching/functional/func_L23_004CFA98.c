/* functional: medium. Same reads/writes/calls order as retail; flow restructured; field and sound IDs unnamed. */
extern u8 D_001A4BE0[];
extern u8 D_001ECA00[];
extern s32 D_001D6694;
extern u8 D_00142660[];
extern s16 D_001426A0;
extern f32 D_001A4C60[4];
extern f32 D_001A4CD0[12];

extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004C93D8(void);
extern f32 func_L01_004C9360(f32);
extern f32 func_L01_004DFE88(s32);
extern void func_L01_004E1560(void);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern void func_L23_004E3428(s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004DFEA0(s32);
extern void func_L01_003F1F20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004ED838(void *, s32, f32, f32);
extern void func_L01_00511618(void *, void *, f32);
extern void func_L23_003098F8(s32);
extern void func_0038CE20(void *, void *, f32);

s32 func_L23_004CFA98(s32 a0) {
    u8 *h;
    u8 *t;
    u8 *e;
    u8 *p;
    s32 idx;
    s32 m;
    s32 n;
    s32 st;
    f32 v[4];
    f32 w[4];
    f32 x;

    h = D_001A4BE0;
    if (*(s32 *)(h + 0x25CC) == 0x14 || *(s32 *)(h + 0x25CC) == 7) {
        return 0;
    }
    if (*(s32 *)(h + 0x25C4) == 0x74 || *(s32 *)(h + 0x25C4) == 0x31) {
        return 0;
    }
    if (*(s16 *)(h + 0x1DC) != 0) {
        return 0;
    }
    if (D_001D6694 != 0) {
        return 0;
    }
    *(s32 *)(h + 0x2808) = 0;
    t = *(u8 **)(h + 0x25C0);
    idx = t[0xA8];
    if (idx == 0xFF) {
        return 0;
    }
    e = D_001ECA00 + idx * 0x40;
    if (*(u8 **)(e + 0x38) != t) {
        return 0;
    }
    if (h[0x25E4] == 2) {
        m = *(s32 *)(e + 0x24) & 2;
    } else {
        m = *(s32 *)(e + 0x24) & 9;
    }
    if (m == 0) {
        return 0;
    }
    if (*(s32 *)(h + 0x234) != 0) {
        return 0;
    }
    if (*(f32 *)(e + 0x2C) != 0.0f) {
        if (func_L01_0041A4F0() != 0 && h[0x25E4] != 5) {
            D_00142660[0x5B] = 0;
            D_00142660[0x5A] = 0;
        }
    }
    if (func_L01_004C93D8() == 0.0f || h[0x25E4] != 0 || (*(s32 *)(e + 0x24) & 0x20000000) != 0) {
        /* falls to the 0x20000000 test below */
    } else {
        x = func_L01_004C9360(*(f32 *)(e + 0x2C));
        *(f32 *)(e + 0x2C) = x;
        if (x == 0.0f) {
            return 0;
        }
    }
    if ((*(s32 *)(e + 0x24) & 0x20000000) != 0) {
        if (h[0x25E4] == 0) {
            n = D_001426A0;
            if (n >= 5) {
                n = 4;
            }
            if (n < 0) {
                n = 0;
            }
            *(f32 *)(e + 0x2C) = *(f32 *)(e + 0x2C) / func_L01_004DFE88(n);
        }
    }
    *(s32 *)(h + 0x2808) = *(s32 *)(e + 0x20);
    if (*(s32 *)(h + 0x25CC) == 0xF) {
        *(u8 **)(h + 0x664) = e;
        *(s16 *)(h + 0x62E) = 1;
        return 0;
    }
    if (h[0x25E4] == 2) {
        n = *(s32 *)(h + 0x1A84) - (s32)*(f32 *)(e + 0x2C);
        *(s32 *)(h + 0x1A84) = n;
        if (n < 0) {
            *(s32 *)(h + 0x1A84) = 0;
        }
    }
    if (a0 == 0) {
        if (*(s16 *)(h + 0x1DC) != 0) {
            return 1;
        }
        p = func_L01_00447490(*(void **)(h + 0x25C0), 1, 0);
        if (p != 0) {
            func_L01_004DFEA0((s32)*(f32 *)(p + 0x2C));
        } else {
            func_L01_004DFEA0(1);
        }
        *(s16 *)(h + 0x1DC) = 0x40;
        return 1;
    }
    a0 = 0;
    func_L01_004E1560();
    if ((*(s32 *)(e + 0x30) & 1) != 0) {
        v[0] = *(f32 *)(e + 0x10);
        v[1] = *(f32 *)(e + 0x14);
        v[2] = *(f32 *)(e + 0x18);
        v[3] = *(f32 *)(e + 0x1C);
        if (*(f32 *)(e + 0x1C) == 5627.9248f) {
            a0 = 1;
        }
    } else if (*(s32 *)(e + 0x20) != 0) {
        u8 *o = *(u8 **)(e + 0x20);
        v[0] = D_001A4C60[0] - *(f32 *)(o + 0x10);
        v[1] = D_001A4C60[1] - *(f32 *)(o + 0x14);
        v[2] = D_001A4C60[2] - *(f32 *)(o + 0x18);
        v[3] = D_001A4C60[3];
    } else {
        func_L01_005110E8(v, 0, -1.0f, 0.0f, 0.0f);
    }
    st = h[0x25E4];
    if (st == 1) {
        func_L23_004E3428(0x42, 1);
        func_L01_004ED838(v, a0, 0.0600000024f, 0.0600000024f);
    } else if (st == 0) {
        if (*(s32 *)(h + 0x2808) != 0) {
            s32 ty = *(s16 *)(*(u8 **)(h + 0x2808) + 0xAA);
            if (ty == 0x4EB || ty == 0x558 || ty == 0x1C5F) {
                func_L23_004E3428(0x82, 1);
                return 1;
            }
        }
        if (*(s32 *)(h + 0x25C4) == 1 || *(s32 *)(h + 0x25C4) == 0x1D || *(s32 *)(h + 0x16B0) == 2) {
            if ((*(s32 *)(e + 0x24) & 8) == 0) {
                p = func_L01_00447490(*(void **)(h + 0x25C0), 1, 0);
                if (p != 0) {
                    func_L01_004DFEA0((s32)*(f32 *)(p + 0x2C));
                }
                if (*(s32 *)(h + 0x2850) == 0) {
                    func_L23_004E3428(0x16, 1);
                } else {
                    func_L01_003F1F20(0x12, 0);
                }
                *(s16 *)(h + 0x1DC) = 0x40;
                if (*(s16 *)(h + 0x21C) == 0) {
                    *(s16 *)(h + 0x21C) = 0xF;
                }
                func_L01_004F4E70(0x14, 0);
                return 0;
            }
        }
        if (*(s32 *)(h + 0x25CC) == 0x12) {
            func_L23_004E3428(0x77, 1);
        } else if (*(s32 *)(h + 0x25CC) == 0x11) {
            func_L23_004E3428(0x78, 1);
        } else if ((*(s32 *)(e + 0x24) & 8) != 0) {
            func_L23_004E3428(0x91, 1);
        } else {
            func_L23_004E3428(0x16, 1);
        }
        if (*(s32 *)(h + 0x25C4) == 0x91) {
            v[0] = 0.0f;
            v[1] = 0.0f;
            v[2] = 0.0f;
            v[3] = 0.0f;
        } else {
            x = 0.0660000071f;
            if (h[0x1479] != 0) {
                x = 0.0f;
            }
            func_L01_004ED838(v, a0, x, 0.0340000018f);
            if (a0 != 0 && e[0x28] == 4) {
                func_L01_00511618(v, v, 2.0f);
            }
        }
    } else if (st == 2) {
        if ((*(s32 *)(e + 0x24) & 4) == 0 && *(s32 *)(h + 0x1A84) > 0) {
            v[0] = 0.0f;
            v[1] = 0.0f;
            v[2] = 0.0f;
            v[3] = 0.0f;
        } else {
            func_L23_004E3428(0x5D, 1);
            func_L23_003098F8(*(s32 *)(h + 0x25C0));
            func_0038CE20(v, v, 0.114000008f);
        }
    } else if (st == 3) {
        func_L23_004E3428(0x55, 1);
        func_L01_004ED838(v, a0, 0.100000009f, 0.0480000041f);
    }
    w[0] = v[0];
    w[1] = v[1];
    w[2] = v[2];
    w[3] = v[3];
    D_001A4CD0[0] = D_001A4CD0[0] + w[0];
    D_001A4CD0[1] = D_001A4CD0[1] + w[1];
    D_001A4CD0[2] = D_001A4CD0[2] + w[2];
    D_001A4CD0[8] = D_001A4CD0[8] + w[0];
    D_001A4CD0[9] = D_001A4CD0[9] + w[1];
    D_001A4CD0[10] = D_001A4CD0[10] + w[2];
    return 1;
}
