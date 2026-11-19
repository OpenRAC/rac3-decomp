/* functional: medium. written from asm; jump table read from level ELF; unrun blocks untested; same call sequence counts as retail */
typedef struct { u8 b[16]; } Blob_003B7548;
typedef int Quad_003B7548 __attribute__((mode(TI)));
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001E1EC0[];
extern u8 D_L07_001D66B0[];

void func_L07_003B7548(u8 *obj) {
    extern s32 func_L01_0045A9F0(void *);
    extern s32 func_0038CB00(void *);
    extern s32 func_L01_004561B8(u8 *);
    extern s32 func_L01_0044E1B8(void *, f32);
    extern f32 func_L01_004395E0(void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern s32 func_L01_0045A748(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32,
                                  f32, f32, f32, f32, f32, f32);
    extern void func_L07_003315B0(void *);
    extern void func_L07_0030FFE8(void *, void *, s32, f32);
    extern void func_L07_003A7488(s32, s32, s32);
    extern void func_L07_003A7540(s32);
    extern void func_L07_003A2380(s32, void *, s32, s32);
    extern void func_L07_003B8690(void *, s32);
    extern void func_L07_003B7E40(u8 *);
    extern void func_L07_003B7F80(u8 *);
    extern void func_L07_003B8D80(u8 *);
    extern void func_L07_003B89E0(u8 *);
    extern void func_L07_003B8F88(u8 *);
    extern void func_L07_003B88F0(u8 *);
    extern void func_L07_003B8CE0(u8 *);
    extern void func_L07_003B8BA0(u8 *);
    extern void func_L07_003B8C50(u8 *);
    extern void func_L07_003B89C0(s32, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_00382468(s32);
    u8 *s;
    s32 r;
    f32 f;

    if (obj[0x20] == 0) {
        func_L07_003B7E40(obj);
    }
    func_L07_003B7F80(obj);
    s = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 2:
        func_L01_0045A9F0(obj);
        if (func_0038CB00(s + 0x19E) != 0) {
            func_L07_003B8690(obj, 3);
        }
        return;
    case 3:
        s[0x1AE] = 1;
        func_L07_003B8C50(obj);
        return;
    case 5:
        if (func_L01_004561B8(obj) != 0) {
            *(u16 *)(obj + 0x34) |= 0x5000;
            if (*(s16 *)(s + 0x29C) == 0) {
                func_L07_003A2380(0x10, obj, 0, 100);
                *(s16 *)(s + 0x29C) = 0x14D;
            }
        }
        if (obj[0x60] & 2) {
            func_L07_003B8690(obj, 6);
        }
        return;
    case 6:
        if (func_L01_004561B8(obj) != 0) {
            s[0x29A] = 0;
        }
        func_L01_0045A9F0(obj);
        f = func_0038D160(*(f32 *)(s + 0x70) - *(f32 *)(obj + 0x10),
                          *(f32 *)(s + 0x74) - *(f32 *)(obj + 0x14));
        *(f32 *)(s + 0x218) = func_0038DB00(f, *(f32 *)(obj + 0xF8));
        if (obj[0x42] == 6) {
            if (func_L01_0044E1B8(obj, 20.5f) != 0) {
                Quad_003B7548 pos;
                s[0x29A]++;
                *(s32 *)(D_L07_001E1EC0 + 0x48) = 0x19;
                *(s32 *)(D_L07_001E1EC0 + 0x28) = 0x19;
                *(f32 *)(D_L07_001E1EC0 + 0x40) = 0.1f;
                *(f32 *)(D_L07_001E1EC0 + 0x20) = 0.1f;
                *(s32 *)(D_L07_001E1EC0 + 0x2C) = 0;
                func_L07_003B8D80(obj);
                pos = *(Quad_003B7548 *)(obj + 0x10);
                f = func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x1F8));
                func_L07_0030FFE8(obj, &pos, s[0x44], f);
            }
        }
        if (obj[0x60] & 2) {
            if (s[0x296] == 0) {
                if (s[0x29A] < 4) return;
                func_L07_003B8690(obj, 7);
                return;
            }
            if (s[0x296] < 5) return;
            func_L07_003B89E0(obj);
        }
        return;
    case 7:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B89E0(obj);
        }
        return;
    case 8:
        if (obj[0x42] == 4) {
            f = func_L01_004395E0(obj);
            if (f >= 30.0f && f <= 50.0f) {
                func_L07_003A7540(*(s32 *)(s + 0x288));
            }
            if (func_L01_0044E1B8(obj, 20.0f) != 0) {
                func_L07_003A7488(*(s32 *)(s + 0x288), 1, 8);
            }
            if (func_L01_0044E1B8(obj, 45.0f) != 0) {
                goto L7900;
            }
        }
        goto L7920;
    case 9:
        if (obj[0x42] == 5) {
            f = func_L01_004395E0(obj);
            if (f >= 30.0f && f <= 90.0f) {
                func_L07_003A7540(*(s32 *)(s + 0x288));
            }
            if (func_L01_0044E1B8(obj, 15.0f) != 0 || func_L01_0044E1B8(obj, 55.0f) != 0) {
                func_L07_003A7488(*(s32 *)(s + 0x288), 1, 8);
            }
            if (func_L01_0044E1B8(obj, 45.0f) != 0) {
                goto L7900;
            }
            if (func_L01_0044E1B8(obj, 80.0f) != 0) {
                goto L7900;
            }
        }
        goto L7920;
    L7900:
        func_L01_004AAC98(10, 0, obj, 0x1A1F);
        func_L07_003A7488(*(s32 *)(s + 0x288), 2, 8);
    L7920:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003A7488(*(s32 *)(s + 0x288), 0, 8);
            func_L07_003B8BA0(obj);
        }
        return;
    case 10:
        if (func_L01_004561B8(obj) != 0) {
            *(f32 *)(s + 0x90 + 0x24) = 0.07200000435113907f;
            *(f32 *)(s + 0x90 + 0x28) = 0.40000003576278687f;
            *(f32 *)(s + 0x90 + 0x20) = 0.07200000435113907f;
            *(u32 *)(s + 0x90 + 0x38) |= 0x415;
        }
        if (obj[0x42] == 1 && func_L01_004395E0(obj) > 5.0f) {
            func_L07_003B8F88(obj);
            func_L07_003B88F0(obj);
            func_L01_0045A748(obj, s + 0x270);
        } else {
            func_L01_0045A9F0(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B8690(obj, 0xB);
        }
        return;
    case 11: {
        u8 *p = obj + 0x10;
        Quad_003B7548 v;
        f32 d;
        if (func_L01_004561B8(obj) != 0) {
            *(f32 *)(s + 0x28C) = func_0038CF38(p, s + 0x270);
        }
        func_L07_003B8F88(obj);
        func_L07_003B89C0((s32)obj, *(void **)(s + 0x290));
        func_L07_003B88F0(obj);
        v = *(Quad_003B7548 *)(s + 0x270);
        d = func_0038CF38(p, &v);
        *((f32 *)&v + 2) += d * 20.0f / *(f32 *)(s + 0x28C) + 2.0f;
        r = func_L01_0045A748(obj, &v);
        if (r & 0x80) {
            func_L07_003B8690(obj, 0xC);
        }
        return;
    }
    case 12:
        func_L07_003B89C0((s32)obj, *(void **)(s + 0x290));
        if (obj[0x42] != 3 || func_L01_004395E0(obj) <= 3.0f) {
            func_L07_003B8F88(obj);
            func_L07_003B88F0(obj);
            func_L01_0045A748(obj, s + 0x270);
        } else {
            if (func_L01_004561B8(obj) != 0) {
                if (s[0x297] != 0xE) {
                    *(f32 *)(D_L07_001E1EC0 + 0x40) = 0.05f;
                    *(s32 *)(D_L07_001E1EC0 + 0x48) = 0xC;
                    *(s32 *)(D_L07_001E1EC0 + 0x2C) = 0;
                    *(f32 *)(D_L07_001E1EC0 + 0x20) = 0.05f;
                    *(s32 *)(D_L07_001E1EC0 + 0x28) = 0xC;
                }
                func_L07_003B8D80(obj);
            }
            *(u32 *)(s + 0xC8) &= ~0x415;
            func_L01_0045A9F0(obj);
        }
        if (obj[0x60] & 2) {
            if (s[0x296] == 0) {
                if (s[0x29B] & 1) {
                    func_L07_003A2380(9, obj, 0, 100);
                    s[0x29B] |= 1;
                }
            }
            func_L07_003B8690(obj, s[0x297]);
        }
        return;
    case 13:
        if (func_L01_004561B8(obj) != 0) {
            *(u32 *)(s + 0xC8) &= ~0x415;
            *(u16 *)(obj + 0x34) &= 0xAFFF;
            if (*(f32 *)(s + 0x138) > 0.0f) {
                *(f32 *)(s + 0x138) = 0.0f;
            }
            if (s[0x296] == 1) {
                func_L07_003A2380(3, D_L07_001DF41C + (*(s32 *)(s + 0x280) << 8), 0, 100);
            }
        }
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B8C50(obj);
        }
        return;
    case 14:
        if (func_L01_004561B8(obj) != 0) {
            *(s16 *)(s + 0x294) = func_00382468(100) + 200;
        }
        func_L01_0045A9F0(obj);
        func_0038CB00(s + 0x294);
        r = obj[0xBC];
        if (r == 3) {
            func_L07_003B8CE0(obj);
            return;
        }
        if (*(s16 *)(s + 0x294) != 0) return;
        if (r == 2) {
            r = 0xF;
        } else if (r == 1) {
            r = 0x10;
        } else {
            return;
        }
        obj[0xBC] = 0;
        func_L07_003B8690(obj, r);
        return;
    case 15:
    case 16:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B8690(obj, 0xE);
        }
        return;
    case 17:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            Blob_003B7548 b = *(Blob_003B7548 *)(s + 0x180);
            func_L01_0043B9E8(obj, b.b[4], b.b[5], b.b[6]);
            func_L07_003A2380(7, D_L07_001DF41C + (*(s32 *)(s + 0x280) << 8), 0, 100);
            func_L01_00451FE0(obj, 0x3FFF, D_L07_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              3.0f, 6.0f, 10.0f, 16.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_L07_003315B0(obj);
        }
        return;
    default:
        return;
    }
}
