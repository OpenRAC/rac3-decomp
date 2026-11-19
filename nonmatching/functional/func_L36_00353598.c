/* functional: medium. Rewritten from the asm as a switch on the state byte (jump table jtbl_002BF020: states 0..11 and 0x42 have code, the rest only run the common tail); not byte-matched (600 diff). gp-relative constants are D_L36_001DDxxx via .extern, as the file does. The VU0 vsub/vadd in state 5 are vec_sub_ab/vec_add_ab. Unsure: signedness of D_L36_001DD8D0/D8D8/F44 (taken as s32 from lw). */
__asm__(".extern D_L36_001DD7F0, 4");
__asm__(".extern D_L36_001DD7F4, 4");
__asm__(".extern D_L36_001DD810, 4");
__asm__(".extern D_L36_001DD814, 4");
__asm__(".extern D_L36_001DD818, 4");
__asm__(".extern D_L36_001DD81C, 4");
__asm__(".extern D_L36_001DD820, 4");
__asm__(".extern D_L36_001DD880, 4");
__asm__(".extern D_L36_001DD884, 4");
__asm__(".extern D_L36_001DD888, 4");
__asm__(".extern D_L36_001DD88C, 4");
__asm__(".extern D_L36_001DD890, 4");
__asm__(".extern D_L36_001DD894, 4");
__asm__(".extern D_L36_001DD8A0, 4");
__asm__(".extern D_L36_001DD8A4, 4");
__asm__(".extern D_L36_001DD8A8, 4");
__asm__(".extern D_L36_001DD8AC, 4");
__asm__(".extern D_L36_001DD8B0, 4");
__asm__(".extern D_L36_001DD8B4, 4");
__asm__(".extern D_L36_001DD8C4, 4");
__asm__(".extern D_L36_001DD8C8, 4");
__asm__(".extern D_L36_001DD8CC, 4");
__asm__(".extern D_L36_001DD8D0, 4");
__asm__(".extern D_L36_001DD8D4, 4");
__asm__(".extern D_L36_001DD8D8, 4");
__asm__(".extern D_L36_001DD8F8, 4");
__asm__(".extern D_L36_001DD8FC, 4");
__asm__(".extern D_L36_001DD900, 4");
__asm__(".extern D_L36_001DD904, 4");
extern f32 D_L36_001DD7F0;
extern s32 D_L36_001DD7F4;
extern f32 D_L36_001DD810;
extern f32 D_L36_001DD814;
extern f32 D_L36_001DD818;
extern f32 D_L36_001DD81C;
extern f32 D_L36_001DD820;
extern f32 D_L36_001DD880;
extern f32 D_L36_001DD884;
extern f32 D_L36_001DD888;
extern f32 D_L36_001DD88C;
extern f32 D_L36_001DD890;
extern f32 D_L36_001DD894;
extern s32 D_L36_001DD8A0;
extern s32 D_L36_001DD8A4;
extern f32 D_L36_001DD8A8;
extern f32 D_L36_001DD8AC;
extern f32 D_L36_001DD8B0;
extern s32 D_L36_001DD8B4;
extern f32 D_L36_001DD8C4;
extern f32 D_L36_001DD8C8;
extern f32 D_L36_001DD8CC;
extern s32 D_L36_001DD8D0;
extern f32 D_L36_001DD8D4;
extern s32 D_L36_001DD8D8;
extern f32 D_L36_001DD8F8;
extern f32 D_L36_001DD8FC;
extern f32 D_L36_001DD900;
extern f32 D_L36_001DD904;
extern u8 D_001A4BE0[];
extern u8 *D_001DFC00;
extern s32 func_L01_004561B8(u8 *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_L01_004395E0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003B1DB8(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 func_0038CAD0(u8 *);
extern s32 func_L01_00456250(u8 *);
extern void func_L01_00456230(u8 *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L36_00355210(u8 *);
extern f32 func_0038CEA8(void *);
extern s32 func_L36_00355290(s32);
extern void func_003C2F58(u8 *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2880(u8 *);
extern s32 func_L31_003494B0(void *, s32);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern void func_L36_00354D88(u8 *);
void func_L36_00353598(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 ns;
    f32 f;
    s32 i;
    u8 *p;
    s32 t;
    vu0_v4 tmp;
    vu0_v4 d;

    switch (a0[0x20]) {
    case 0:
        func_L36_00355210(a0);
        ns = 0xB;
        goto set_state;
    case 1:
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 8) {
                func_003C3A10(a0, 8, (s32)(a0[0x20] == 1 ? D_L36_001DD814 : D_L36_001DD81C), D_L36_001DD7F4);
            }
        }
        *(f32 *)(a0 + 0x48) = D_L36_001DD810;
        f = func_L01_004395E0(a0);
        if (a0[0x20] == 1) {
            if (!(D_L36_001DD818 <= f)) {
                break;
            }
        } else {
            if (!(D_L36_001DD820 <= f)) {
                break;
            }
        }
        {
            f32 x = *(f32 *)(a0 + 0x10);
            f32 g = *(f32 *)(D_001A4BE0 + 0x80);
            f32 diff = x - g;
            if (diff < 0.0f) {
                diff = -diff;
            }
            if (D_L36_001DD8C8 < diff) {
                ns = 3;
                goto set_state;
            }
            if (*(s32 *)(s + 0x70) != 0) {
                if (x < g) {
                    ns = 3;
                    goto set_state;
                }
            } else {
                if (g < x) {
                    ns = 3;
                    goto set_state;
                }
            }
            func_003C3A10(a0, 8, (s32)D_L36_001DD814, D_L36_001DD7F4);
        }
        break;
    case 0x42:
        if (func_L01_004561B8(a0) != 0) {
            *(u128_t *)(s + 0x50) = *(u128_t *)(a0 + 0x10);
            func_L01_003B1DB8(a0);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            *(s32 *)(s + 0x78) = D_L36_001DD8A4;
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        func_0038CAD0(s + 0x78);
        if (func_L01_00456250(a0) != 0) {
            func_L01_00456230(a0, 0);
            ns = 5;
            goto set_state;
        }
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x94] != 10) {
                *(s32 *)(s + 0x78) = D_L36_001DD8B4;
            }
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, D_L36_001DD7F4);
            }
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        if (*(s32 *)(s + 0x70) != 0) {
            if (*(f32 *)(a0 + 0x10) < *(f32 *)(D_001A4BE0 + 0x80)) {
                func_L01_004450F0(a0, 10, -1);
            }
        } else {
            if (*(f32 *)(D_001A4BE0 + 0x80) < *(f32 *)(a0 + 0x10)) {
                func_L01_004450F0(a0, 10, -1);
            }
        }
        if (func_0038CAD0(s + 0x78) != 0) {
            f = func_003824E0(0.0f, 1.0f);
            if (f < D_L36_001DD8D4) {
                ns = 7;
            } else {
                ns = 4;
            }
            goto set_state;
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 6) {
                func_003C3A10(a0, 6, 0, D_L36_001DD7F4);
            }
        }
        *(f32 *)(a0 + 0x48) = D_L36_001DD904 * func_0038CEA8(s + 0x60);
        if (*(s32 *)(s + 0x70) != 0) {
            if (*(f32 *)(a0 + 0x10) < *(f32 *)(D_001A4BE0 + 0x80)) {
                func_L01_004450F0(a0, 10, -1);
            }
        } else {
            if (*(f32 *)(D_001A4BE0 + 0x80) < *(f32 *)(a0 + 0x10)) {
                func_L01_004450F0(a0, 10, -1);
            }
        }
        {
            f32 g = *(f32 *)(D_001A4BE0 + 0x80);
            f32 x = *(f32 *)(a0 + 0x10);
            f32 tol = D_L36_001DD8C8;
            if (g + tol < x) {
                *(f32 *)(s + 0x60) = *(f32 *)(s + 0x60) - D_L36_001DD7F0;
            } else if (x < g - tol) {
                *(f32 *)(s + 0x60) = *(f32 *)(s + 0x60) + D_L36_001DD7F0;
            } else {
                ns = 1;
                goto set_state;
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(s + 0x78) = D_L36_001DD8A0;
        }
        for (i = 0; i < 12; i++) {
            p = *(u8 **)(s + 0x8C + i * 4);
            if (p != 0) {
                func_003C2F58(a0, func_L36_00355290(i), &tmp);
                vec_sub_ab(&d, &tmp, p + 0x10);
                func_0038CE20(&d, &d, 1.0f / (f32)*(s32 *)(s + 0x78));
                p = *(u8 **)(s + 0x8C + i * 4);
                vec_add_ab(p + 0x10, p + 0x10, &d);
                p = *(u8 **)(s + 0x8C + i * 4);
                *(f32 *)(p + 0xF4) = func_0038DB00(*(f32 *)(p + 0xF4), *(f32 *)(*(u8 **)(p + 0x68) + 0x58));
            }
        }
        if (func_0038CAD0(s + 0x78) != 0) {
            u16 h = *(u16 *)(a0 + 0x34) & 0xFFBE;
            u8 *q = *(u8 **)(a0 + 0x24);
            *(u16 *)(a0 + 0x34) = h;
            h |= *(u16 *)(q + 0x44) & 0x1000;
            *(u16 *)(a0 + 0x34) = h;
            *(s32 *)(a0 + 0x98) = *(s32 *)(q + 0x10);
            for (i = 0; i < 12; i++) {
                p = *(u8 **)(s + 0x8C + i * 4);
                if (p != 0) {
                    func_003C2880(p);
                    *(u8 **)(s + 0x8C + i * 4) = 0;
                }
            }
            func_L36_00355210(a0);
            ns = 6;
            goto set_state;
        }
        break;
    case 6:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, D_L36_001DD7F4);
            }
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        if (!(a0[0x60] & 2)) {
            break;
        }
        if (a0[0x43] == 2) {
            func_003C3A10(a0, 4, 0, D_L36_001DD7F4);
            break;
        }
        ns = 4;
        goto set_state;
    case 7:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 9) {
                func_003C3A10(a0, 9, 0, D_L36_001DD7F4);
            }
            *(s32 *)(s + 0x74) = 0;
            *(s32 *)(s + 0x78) = D_L36_001DD8D8;
        }
        if (a0[0x43] != 10) {
            f = D_L36_001DD8CC;
        } else {
            f = 1.0f;
        }
        *(f32 *)(a0 + 0x48) = f;
        if (func_0038CAD0(s + 0x78) != 0) {
            t = *(s32 *)(s + 0x74);
            if (t < D_L36_001DD8D0) {
                func_L31_003494B0(D_001DFC00 + (*(s32 *)(s + 0x84 + (t % 2) * 4) << 7) + 0x30, -1);
                *(s32 *)(s + 0x78) = D_L36_001DD8D8;
                *(s32 *)(s + 0x74) = *(s32 *)(s + 0x74) + 1;
            }
        }
        if (!(a0[0x60] & 2)) {
            break;
        }
        if (a0[0x43] == 11) {
            func_003C3A10(a0, 3, 0, 0);
            ns = 3;
            goto set_state;
        }
        if (*(s32 *)(s + 0x74) < D_L36_001DD8D0) {
            if (a0[0x43] != 10) {
                func_003C3A10(a0, 10, 0, 0);
            }
        } else {
            func_003C3A10(a0, 11, 0, 0);
        }
        break;
    case 8:
    case 9:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x20] == 9) {
                if (a0[0x43] != 13) {
                    func_003C3A10(a0, 13, (s32)D_L36_001DD890, 0);
                }
            } else {
                if (a0[0x43] != 13) {
                    func_003C3A10(a0, 13, (s32)D_L36_001DD888, 0);
                }
            }
        }
        if (a0[0x20] == 9) {
            f = D_L36_001DD880;
        } else {
            f = D_L36_001DD884;
        }
        *(f32 *)(a0 + 0x48) = f;
        f = func_L01_004395E0(a0);
        if (a0[0x20] == 9) {
            if (!(D_L36_001DD894 <= f)) {
                break;
            }
        } else {
            if (!(D_L36_001DD88C <= f)) {
                break;
            }
        }
        if (a0[0x20] != 9) {
            ns = 3;
            goto set_state;
        }
        {
            f32 x = *(f32 *)(a0 + 0x10);
            f32 g = *(f32 *)(D_001A4BE0 + 0x80);
            if (*(s32 *)(s + 0x70) != 0) {
                ns = (g < x) ? 2 : 3;
            } else {
                ns = (x < g) ? 2 : 3;
            }
            goto set_state;
        }
    case 10:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 7) {
                func_003C3A10(a0, 7, 0, D_L36_001DD7F4);
            }
        }
        if (func_L01_0044E1B8(a0, D_L36_001DD900) != 0) {
            s32 n = (*(s32 *)(s + 0x70) == 0);
            *(s32 *)(s + 0x70) = n;
            if (n != 0) {
                f = D_L36_001DD8A8;
            } else {
                f = D_L36_001DD8AC;
            }
            *(f32 *)(a0 + 0xF8) = f;
            func_L01_004450F0(a0, a0[0x94], -1);
            if (a0[0x20] == 4) {
                if (a0[0x43] != 6) {
                    func_003C3A10(a0, 6, 0, 0);
                }
            } else if (a0[0x20] == 3) {
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 0);
                }
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, D_L36_001DD7F4);
            }
        }
        if (func_L01_00456250(a0) != 0) {
            func_L01_00456230(a0, 0);
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    default:
        break;
    }
    goto tail;
set_state:
    func_L01_004450F0(a0, ns, -1);
tail:
    if (a0[0x20] == 4) {
        func_L31_003478E8(a0, a0 + 0x10, s + 0x60, D_L36_001DD8B0, D_L36_001DD8C4, D_L36_001DD8FC, D_L36_001DD8FC, D_L36_001DD8FC, D_L36_001DD8F8, 0.0f, 0);
    } else {
        func_L31_003478E8(a0, a0 + 0x10, s + 0x60, D_L36_001DD8B0, D_L36_001DD8C4, 0.0f, 0.0f, 0.0f, D_L36_001DD8F8, 0.0f, 0);
    }
    func_L36_00354D88(a0);
}
