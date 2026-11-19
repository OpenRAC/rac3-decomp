/* functional: medium. Written from asm + jump table; 428 words differ; one callee (func_L01_005147A8) gets s[0x28] because retail leaves it in $a0. */
typedef struct { u8 b[0xF0]; } T_003C81D0;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern u8 D_002428C0[];
extern u8 *D_001D52FC;
extern s32 D_L03_002E52F0[];
__asm__(".extern D_L03_002E52F0, 16");
extern T_003C81D0 D_002C49C0[];
extern s32 D_001427F0[];
extern u8 D_001425D6[];
extern s16 D_001426A0[];
extern u8 D_001DEEA0_sda[];
__asm__(".extern D_001DEEA0_sda, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_005003D0(s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_L01_004C93D8(void);
extern void func_L01_004C94B0(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L03_003C8900(void *);
extern void func_L03_003C8918(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00511A40(void *, s32, f32);
extern s32 func_L01_00511A98(void);
extern void func_L01_00504E38(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00381CB0(void);
extern void func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L02_003C5DC0(s32);
extern void func_L01_003EC9E0(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L03_003C81D0(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    u8 *h;
    u8 *dd;
    u8 *e;
    u8 *ptr;
    T_003C81D0 tmp;
    vu0_v4 *vec = (vu0_v4 *)&tmp;
    s32 w;
    s32 r5;
    s32 b;
    u32 v;

    switch (m[0x20]) {
    case 0:
        *(f32 *)(m + 0x48) = 0.5f;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.6500001f;
        *(s32 *)(s + 0x10) = 0;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        h = D_001A4BE0;
        if (*(s32 *)(s + 0x14) != 0 && *(s32 *)(h + 0x25C4) != 0x74) {
            *(s32 *)(s + 0x14) = 0;
            func_L01_005003D0(0, 0);
            *(s32 *)(h + 0x25F8) = *(s32 *)(s + 0x1C);
            *(s32 *)(h + 0x2604) = *(s32 *)(s + 0x20);
        }
        if (h[0x25E4] != 0 || *(s16 *)(h + 0x288C) != 0) {
            break;
        }
        if (func_0038CAD0(s + 0x10) == 0) {
            break;
        }
        if (D_L03_002E52F0[0] != 0 || D_L03_002E52F0[9] != -1) {
            break;
        }
        if (!(func_L01_0040E570(m + 0x10, h + 0x80) < 1.5f)) {
            break;
        }
        if (*(s32 *)(h + 0x360) == 0) {
            break;
        }
        if (!(*(f32 *)(h + 0x98) > -1.57079637f) || !(*(f32 *)(h + 0x98) < 1.57079637f)) {
            break;
        }
        func_L01_00452560(0, 1, 0x8BB, 1, 0, 0, 0);
        if (!(*(s32 *)(D_001D52FC + 0x1A4) & 0x10)) {
            break;
        }
        if (func_L01_004C93D8() != 0.0f) {
            func_L01_004C94B0(m);
            tmp = D_002C49C0[D_001425D6[0]];
            D_001427F0[0x58 / 4] = D_001427F0[0x58 / 4] + 1;
            if (*(u16 *)(tmp.b + 0x8A) < D_001427F0[0x58 / 4]) {
                D_001427F0[0x58 / 4] = *(u16 *)(tmp.b + 0x8A);
            }
        }
        func_L01_004450F0(m, 3, -1);
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            *(vu0_q *)D_001A4C60 = *(vu0_q *)(m + 0x10);
            h = D_001A4C60 - 0x80;
            *(f32 *)(h + 0x88) = *(f32 *)(h + 0x88) + 0.200000003f;
            func_L01_005003D0(0x74, 1);
            *(s32 *)(s + 0x10) = 0x2A;
        }
        func_L03_003C8900(m);
        if (func_0038CAD0(s + 0x10) != 0) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        h = D_001A4BE0;
        *(s32 *)(h + 0x238) = 0x25;
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(s + 0x1C) = *(s32 *)(h + 0x1228);
            *(s32 *)(s + 0x20) = *(s32 *)(h + 0x1318);
            func_0038D000(vec, &D_001DEEA0_sda[0], m + 0xC0);
            vec_add_ab(vec, vec, m + 0x10);
            func_L01_00511A40(vec, 0, *(f32 *)(m + 0xF8));
        }
        r5 = func_L01_00511A98();
        if (r5 == 2) {
            ptr = *(u8 **)(h + 0x25C0);
            if (ptr[0x42] == ptr[0x43]) {
                *(s32 *)(h + 0x2604) = r5;
                *(s32 *)(h + 0x25F8) = 1;
                func_L01_004450F0(m, 4, -1);
                break;
            }
        }
        v = *(u16 *)(m + 0x96);
        *(u16 *)(m + 0x96) = v + 1;
        if (v >= 0xFB) {
            func_L01_00504E38(0);
        } else if (r5 != 0) {
            break;
        }
        *(s32 *)(h + 0x25F8) = *(s32 *)(s + 0x1C);
        *(s32 *)(h + 0x2604) = *(s32 *)(s + 0x20);
        func_L01_004450F0(m, 1, -1);
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            func_L01_005003D0(0x74, 1);
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 0);
            }
            m[0xBC] = 0;
        }
        func_L03_003C8900(m);
        if (m[0x60] & 2) {
            if (m[0x43] != 2) {
                func_003C3A10(m, 2, 0, 0);
            }
            *(s32 *)(s + 0x28) = func_00381CB0();
            func_L01_005147A8(0);
            if (func_00381CB0() != *(s32 *)(s + 0x28)) {
                func_L01_00425978(D_001426A0[0]);
            }
            func_003A0EC0(5, 1, 3, 0, 0);
            m[0xBC] = 1;
            break;
        }
        b = m[0xBC];
        if (b != 1) {
            break;
        }
        func_L01_005003D0(0x74, 1);
        dd = D_002428C0;
        if (*(s32 *)(dd + 0x768) != 0) {
            func_L02_003C5DC0(*(s32 *)(s + (*(s32 *)(dd + 0x768) - 1) * 4));
            func_L01_003EC9E0(*(s32 *)(s + (*(s32 *)(dd + 0x768) - 1) * 4));
            *(s32 *)(dd + 0x768) = 0;
            *(s32 *)(s + 0x14) = b;
            w = *(s32 *)(s + 0x24);
            if (w == -1 || *(void **)(D_001A30B0 + w * 128 + 0xDC) != (void *)m || D_001A30B0[w * 128 + 0xD0] == 0) {
                *(s32 *)(s + 0x24) = func_003A52A0(4, 4, m);
            }
            func_003A52A0(5, 0, m);
            func_L01_004450F0(m, 5, -1);
            break;
        }
        if (m[0x43] != 3) {
            func_003C3A10(m, 3, 0, 0);
        }
        *(s32 *)(s + 0x14) = 0;
        w = func_00381CB0();
        if (w != *(s32 *)(s + 0x28)) {
            func_L01_005147A8(*(s32 *)(s + 0x28));
            func_L01_00425978(D_001426A0[0]);
        }
        func_L01_004450F0(m, 6, -1);
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            func_L01_00425978(D_001426A0[0]);
            *(s32 *)(s + 0x10) = 0xB7;
        }
        func_L03_003C8900(m);
        func_L03_003C8918(m);
        if (func_0038CAD0(s + 0x10) == 0) {
            break;
        }
        w = *(s32 *)(s + 0x24);
        if (w != -1 && *(void **)(D_001A30B0 + w * 128 + 0xDC) == (void *)m && D_001A30B0[w * 128 + 0xD0] != 0) {
            func_003A4F28(w);
        }
        *(s32 *)(s + 0x24) = -1;
        if (m[0x43] != 3) {
            func_003C3A10(m, 3, 0, 0);
        }
        func_L01_004450F0(m, 6, -1);
        break;
    case 6:
        func_L03_003C8900(m);
        if (!(m[0x60] & 2)) {
            break;
        }
        if (m[0x43] != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        w = *(s32 *)(s + 0x14);
        *(s32 *)(s + 0x10) = (w != 0) ? 200 : 100;
        if (w == 0) {
            func_L01_005003D0(0, 0);
            *(s32 *)(D_001A4BE0 + 0x25F8) = *(s32 *)(s + 0x1C);
            *(s32 *)(D_001A4BE0 + 0x2604) = *(s32 *)(s + 0x20);
        }
        func_L01_004450F0(m, 1, -1);
        break;
    default:
        break;
    }
    if (m[0x31] != 0) {
        func_L01_00451DB8(m, s + 0x18, 0x7FA0A0A0, 0x7F505050, 0.167551622f);
    }
}
