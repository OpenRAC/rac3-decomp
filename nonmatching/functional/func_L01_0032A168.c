/* functional: medium. Compiles; all 49 jal targets match retail as a multiset (6 jalr too), control flow traced block by block against the asm. Medium because of unknown semantics and two passthrough points: func_0039EF28 and func_L01_0044CCC8 are called with a0 left over from a lb 9(s) in retail (passed b9 to 0044CCC8, none to 0039EF28), and func_00392B20's second arg is the flag index h left in $a1. File's flags lack -mvu0-use-vf0-vf2 so vec_add_ab cannot be used here (scalar adds instead); func_L01_004A3610 is declared (u8 *, u8 *) in the file context. */
extern s32 D_001D545C;
extern s32 D_001DFB40_sda;
__asm__(".extern D_001DFB40_sda, 4");
extern s32 D_001DFB94_sda;
__asm__(".extern D_001DFB94_sda, 4");
extern f32 D_001DF950_sda;
__asm__(".extern D_001DF950_sda, 4");
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern s32 D_001D6690_sda;
__asm__(".extern D_001D6690_sda, 4");
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");
extern u8 *D_001E0100_sda;
__asm__(".extern D_001E0100_sda, 4");
extern u8 D_001BBC40[];
extern u8 D_001D5530[];
extern s32 D_001E1880;
extern u8 ***D_002AF350[];
extern s32 D_00142BA0[];
extern u8 D_001EA7C0[];
extern u8 D_00142CAD;
extern u8 D_0014275D;
extern u8 D_0014275C;
extern u8 D_00142D62;
extern u8 D_00142CA0[];
extern u8 D_00142CBE;
extern u8 D_001426E0[];
extern u8 D_001BBDA2;
extern u8 D_001DFE82;
extern u8 *D_001D52FC;
extern s32 D_002D15F0;
extern s32 D_001E6DB0;
extern u8 D_0016C580[];
extern s32 D_001DFC28;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001F3F40[];

extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_L01_004BA7B8(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);
extern void func_L01_0044FC48(s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern void func_00392DF0(s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00419188(s32);
extern u8 *func_L01_0043B548(s32, s32);
extern void func_L01_0042B068(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00511A40(void *, s32, f32);

void func_L01_0032A168(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    s32 gs, i, h, found, did, did2;
    u8 **row;
    s16 *ent;
    u8 *obj;
    u8 *fn;
    f32 r;

    gs = D_001D545C;
    if (gs == 0x11 && m[0x20] == 0 && *(s32 *)(s + 0x10) != 0 && (D_001BBC40[0x110 + m[0xB0]] & 0x80) != 0) {
        for (i = 0; i < 4; i++) {
            s32 x = *(s32 *)(s + 0x20 + i * 4);
            if (x >= 0) {
                func_L01_00456230(D_001E001C_sda + (x << 8), 1);
            }
        }
        func_003C2880(m);
        return;
    }
    if (D_001DFB40_sda <= 0) {
        return;
    }
    if (m[0x20] >= 5) {
        return;
    }
    switch (m[0x20]) {
    case 0:
        if ((s8)s[9] != -1 && D_001D5530[(s8)s[9]] != 0) {
            func_003C2880(m);
            return;
        }
        if (m[0xB0] != 0xFF && (D_001BBC40[D_001D545C * 16 + m[0xB0]] & 0x80) != 0) {
            func_003C2880(m);
            return;
        }
        func_L01_004450F0(m, 1, -1);
    case 1:
        if (s[0xA] == 0 && func_L01_00456250(m) == 0 && m[0xBC] == 0) {
            return;
        }
        s[0xA] = 1;
        func_L01_004450F0(m, 2, -1);
    case 2:
        if (*(s32 *)(s + 0x14) != 0) {
            if (D_00142CAD == 0) {
                return;
            }
            if (D_0014275D == 0) {
                return;
            }
            if (D_001D545C == 0xD) {
                if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) == 0) {
                    return;
                }
                if (D_002D15F0 == 0xC) {
                    return;
                }
            }
        }
        if (D_001D545C == 4 && D_001D6694_sda == 6) {
            return;
        }
        if (s[0xA] == 0) {
            func_L01_004450F0(m, 1, -1);
            return;
        }
        if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x1C) {
            return;
        }
        if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x31) {
            return;
        }
        if (*(s32 *)(D_001A4BE0 + 0x2850) <= 0) {
            return;
        }
        if (D_001D6694_sda != 0) {
            return;
        }
        if (*(s32 *)s != -1 && func_00382380(D_001A4BE0 + 0x80, *(s32 *)s, 0) == 0) {
            return;
        }
        D_001E1880 = D_001DFB94_sda;
        found = 1;
        row = (u8 **)D_002AF350[D_001D545C];
        if (row != 0 && row[s[8]] != 0 && *(s16 *)row[s[8]] != -1) {
            ent = (s16 *)row[s[8]];
            for (i = 0; ; i++) {
                h = ent[i];
                if (s[0xD] != 0 ||
                    (*(s32 *)(s + 0x34) != -1 && (D_001BBC40[*(s32 *)(s + 0x34) + D_001D545C * 16] & 0x80) == 0) ||
                    (D_00142BA0[h >> 2] & (1 << (h & 0x1F))) == 0) {
                    if (func_00392B20(D_001EA7C0, h) == 0 && i == 0) {
                        return;
                    }
                    found = 0;
                }
                row = (u8 **)D_002AF350[D_001D545C];
                ent = (s16 *)row[s[8]];
                if (ent[i + 1] == -1) {
                    break;
                }
            }
        }
        if (found != 0) {
            s[0xF] = 0;
            func_L01_004450F0(m, 4, -1);
            return;
        }
        s[0xF] = 1;
        func_00392C78(D_001EA7C0);
        if (D_001DFB40_sda < 5 || 0.83f <= D_001DF950_sda) {
            D_001DF950_sda = 1.5f;
            func_L01_004BA7B8();
        }
        func_L01_004450F0(m, 3, -1);
        return;
    case 3:
        if (D_001D545C == 3 && s[8] == 0) {
            D_001DFB94_sda = 0;
        }
        if (D_001D545C == 0xA && (u32)(D_001E6DB0 - 5) < 2) {
            D_001DFB94_sda = 0;
        }
        if (D_001D6694_sda != 2) {
            if (D_001DFB40_sda < 300 && 0.7f < D_001DF950_sda) {
                D_001DF950_sda = 1.5f;
            }
            if (*(s32 *)(s + 0x14) != 0 && D_001D545C == 0xD && D_001D6690_sda != 6 && D_001D6694_sda != 6) {
                v[0] = 260.53f;
                v[1] = 268.38f;
                v[2] = 100.0f;
                *(s16 *)(D_0016C580 + 0x26) = 1;
                D_001DFC28 = 1;
                *(vu0_q *)(D_0016C580 + 0x70) = *(vu0_q *)v;
            }
        }
        if (func_L01_004BA800() == 0) {
            if (*(s32 *)(s + 4) != -1) {
                obj = D_001E0100_sda + (*(s32 *)(s + 4) << 7);
                func_L01_004F50C8(obj + 0x30, obj + 0x70, 0, 1);
            }
            func_L01_004450F0(m, 4, -1);
        }
        did = 0;
        if (D_001D545C == 0 && (s8)s[9] != -1 && func_L01_004BA800() == 0) {
            func_L01_0044CCC8((s8)s[9]);
            func_0039EF28();
            did = 1;
            if ((s8)s[9] != 0x18) {
                func_L01_0044FC48((s8)s[9], 0);
            }
            if (m[0xB0] != 0xFF && (D_001BBC40[D_001D545C * 16 + m[0xB0]] & 0x80) == 0) {
                func_L01_0043B510(m[0xB0]);
                did = 1;
            }
            if ((s8)s[0xB] != 0 && (*(s32 *)(s + 0xC) & 0xFFFF0000) != 0) {
                if (*(s32 *)(s + 4) != -1) {
                    obj = D_001E0100_sda + (*(s32 *)(s + 4) << 7);
                    func_L01_004A3610(obj + 0x30, obj + 0x70);
                } else {
                    func_L01_004A3610(m + 0x10, m + 0xF0);
                }
            }
            if ((s8)s[0xC] != -1) {
                if (s[0x39] == 0) {
                    func_00392DF0((s8)s[0xC], 1);
                } else {
                    D_001D6694_sda = 3;
                    D_001D6690_sda = -2;
                    func_003A0EC0(6, 2, 1, (s8)s[0xC], 0);
                }
            } else if (did != 0 || s[0xF] != 0) {
                func_0039EC28(0, -1);
            }
        }
        if (m[0x20] != 4) {
            return;
        }
    case 4:
        D_001DFB94_sda = D_001E1880;
        did2 = 0;
        if ((s8)s[9] != -1) {
            func_L01_0044CCC8((s8)s[9]);
            func_0039EF28();
            func_L01_0044FC48((s8)s[9], 0);
            did2 = 1;
            if ((s8)s[0x38] != -1) {
                func_L01_0044CCC8((s8)s[0x38]);
                func_0039EF28();
                func_L01_0044FC48((s8)s[0x38], 1);
            }
        }
        if (m[0xB0] != 0xFF && (D_001BBC40[D_001D545C * 16 + m[0xB0]] & 0x80) == 0) {
            func_L01_0043B510(m[0xB0]);
            did2 = 1;
        }
        if (*(s32 *)(s + 0x10) != 0) {
            if (D_001D545C == 0x13) {
                D_001426E0[0x82] = D_001426E0[0x82] | 1;
                func_0039EF28();
                did2 = 1;
            } else if (D_001D545C == 0x11) {
                if (D_00142CA0[0x22] == 0) {
                    D_00142D62 = 1;
                    D_00142CA0[0x22] = 1;
                    func_0039EF28();
                    func_L01_00452560(0, 0xF, 0x14EB, 0x96, 0, 0, 0);
                }
                did2 = 1;
            } else if (D_001D545C == 7) {
                if (D_00142CBE == 0) {
                    func_L01_00419188(0x1E);
                    func_L01_00452560(0, 0xF, 0xAF0, 0x96, 0, 0, 0);
                }
                did2 = 1;
            } else {
                D_0014275C = 1;
                did2 = 1;
            }
        }
        if ((s8)s[0xB] > 0 && (*(s32 *)(s + 0xC) & 0xFFFF0000) != 0) {
            if (*(s32 *)(s + 4) != -1) {
                obj = D_001E0100_sda + (*(s32 *)(s + 4) << 7);
                func_L01_004A3610(obj + 0x30, obj + 0x70);
            } else {
                func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
            }
        }
        for (i = 0; i < 4; i++) {
            s32 x = *(s32 *)(s + 0x20 + i * 4);
            if (x >= 0) {
                func_L01_00456230(D_001E001C_sda + (x << 8), 1);
            }
        }
        if (D_001D545C == 0x16 && *(s32 *)(s + 0x20) >= 0) {
            obj = func_L01_0043B548(0x19E1, 0x6C);
            (*(void (**)(s32, s32))(obj + 0x24))(0, 0);
            (*(void (**)(s32))(obj + 0x44))(1);
            D_001BBDA2 = 0x80;
            D_001DFE82 = 0x80;
            h = ((D_001D545C & 0x1F) << 11) | 0x64;
            D_001426E0[0x72] = h;
            D_001426E0[0x71] = h >> 8;
        }
        if ((s8)s[0xC] != -1) {
            if (D_001D545C == 0xA && s[8] == 0) {
                func_L01_0042B068(1, 0);
            } else if ((s8)s[0xC] == D_001D545C && *(s32 *)(D_001F3F40 + 0xC) > 0) {
                func_L01_0042B068(1 - *(s32 *)D_001F3F40, 0);
            } else if (s[0x39] == 0) {
                func_00392DF0((s8)s[0xC], 1);
            } else {
                D_001D6694_sda = 3;
                D_001D6690_sda = -2;
                func_003A0EC0(6, 2, 1, (s8)s[0xC], 0);
            }
        } else if ((did2 != 0 || s[0xF] != 0) && (s8)s[0xB] != -1) {
            func_0039EC28(0, -1);
        }
        if (*(s32 *)(s + 0x30) != -1) {
            obj = D_001E001C_sda + (*(s32 *)(s + 0x30) << 8);
            func_L01_00456230(obj, 1);
            *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) & 0xFFFD;
            obj[0x30] = 0xFF;
            (*(void (**)(void *))(obj + 0x64))(obj);
        }
        if (s[0x3A] != 0) {
            func_0038CE20(v, D_001A4BE0, 3.0f);
            v[0] = v[0] + *(f32 *)(D_001A4BE0 + 0x80);
            v[1] = v[1] + *(f32 *)(D_001A4BE0 + 0x84);
            v[2] = v[2] + *(f32 *)(D_001A4BE0 + 0x88);
            v[2] = v[2] + 0.5f;
            r = func_003C3D30(v, 0, 0, 0.5f);
            v[2] = r;
            if (0.3f < fabs_asm(*(f32 *)(D_001A4BE0 + 0x88) - r)) {
                return;
            }
            func_L01_00511A40(v, 1, *(f32 *)(D_001A4BE0 + 0x98));
        }
        if (s[0x3B] != 0 && m[0x94] == 3) {
            func_003A0EC0(5, 1, 6, 0, 0);
        }
        func_003C2880(m);
        return;
    }
}
