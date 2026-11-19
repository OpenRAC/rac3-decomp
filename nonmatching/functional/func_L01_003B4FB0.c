/* functional: medium. Same reads, writes, calls and branch structure; register allocation differs. The jump-table (jtbl_002BF010, not in the level 01 asm) was read as cases 1..7 in code order; case 3 vtable f18 is called with a0 left over from the call setup (0x19E1). */
typedef struct {
    s32 (*f0)(void);
    s32 (*f4)(void);
    s32 (*f8)(void);
    s32 (*fC)(void);
    s32 (*f10)(void);
    s32 (*f14)(void);
    s32 (*f18)(s32);
} V_003B4FB0;

extern u8 *D_L01_001E001C;
extern f32 D_L01_001DF950;
extern s32 D_L01_001DE748[];
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern s32 D_001D545C[];
extern s16 D_001A4DBC[];
extern f32 D_001A7404[];
extern void func_L01_003B5498(u8 *, u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_003291D0(void);
extern void func_003E54E0(s32);
extern s32 func_L01_00328FE8(s32);
extern s32 func_L01_00329038(s32);
extern void func_L01_00419188(s32);
extern void func_L01_00326E50(s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_004EDE10(void);
extern void func_L01_00456230(void *, s32);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_003B42C8(s32, s32, s32, s32);
extern V_003B4FB0 *func_L01_0043B548(s32, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_003B5500(u8 *, u8 *, s32);
extern void func_L01_003B28D0(s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L01_003B4FB0(u8 *m) {
    u8 *s = *(u8 **)(m + 104);
    u8 *o;
    u8 *ent;
    s32 v;
    s32 x;
    s32 hold;
    s32 r4;

    if (m[32] == 0) {
        func_L01_003B5498(m, s);
    }
    switch (m[32]) {
    case 1:
        *(u16 *)(m + 52) |= 2;
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(s + 20) = (*(s32 *)(s + 16) != 0) ? 2 : 200;
            if (*(s32 *)(s + 12) != 0) {
                r4 = *(s32 *)(s + 24);
                if (r4 != -1) {
                    ent = D_L01_001E001C + (r4 << 8);
                    ent[48] = 255;
                    *(u16 *)(ent + 52) &= 0xFFFD;
                }
                o = *(u8 **)(*(u8 **)s + 104);
                if (*(s32 *)(o + 84) == 0) {
                    *(s32 *)(s + 28) = 0;
                } else {
                    v = func_L01_003291D0();
                    *(s32 *)(s + 28) = v;
                    D_00142660[0] += v;
                    func_003E54E0(150);
                }
                if (o[82] == 0) {
                    *(s32 *)(s + 32) = 0;
                } else if (func_L01_00328FE8(*(s32 *)s) == 0 || func_L01_00329038(*(s32 *)s) == 0) {
                    v = D_L01_001DE748[o[82]];
                    *(s32 *)(s + 32) = v;
                    func_L01_00419188(v);
                } else {
                    *(s32 *)(s + 32) = 0;
                }
                if (*(s32 *)(s + 24) != -1) {
                    x = (*(s32 *)o & 0x7FF) + ((D_001D545C[0] & 0x1F) << 11);
                    D_001426E0[230] = x;
                    D_001426E0[229] = x >> 8;
                }
                hold = D_001426E0[189];
                func_L01_00326E50(*(s32 *)s);
                if (hold != 0) {
                    *(s32 *)(s + 36) = 0;
                } else if (D_001426E0[189] == 0) {
                    *(s32 *)(s + 36) = 0;
                } else {
                    *(s32 *)(s + 36) = 1;
                    func_003A5348(1, 0, 0);
                }
                D_001A4DBC[0] = 250;
            }
        }
        if (*(s32 *)(s + 12) != 0 && *(s32 *)(s + 16) == 0) {
            D_001A7404[0] = 300.0f;
        }
        if (func_0038CAD0(s + 20) != 0) {
            if (*(s32 *)(s + 12) == 0) {
                func_L01_004EDE10();
            }
            r4 = *(s32 *)(s + 24);
            if (r4 != -1 && *(s32 *)(s + 12) != 0) {
                func_L01_00456230(D_L01_001E001C + (r4 << 8), 1);
                if (D_001D545C[0] == 26) {
                    func_L01_005003D0(0x74, 1);
                }
                func_L01_004450F0((s32)m, 3, -1);
                return;
            }
            if (*(s32 *)(s + 16) == 0) {
                func_L01_004450F0((s32)m, 4, -1);
            } else if (*(s32 *)(s + 12) == 0) {
                func_L01_004450F0((s32)m, 7, -1);
            } else if (*(s32 *)(s + 4) == 0) {
                func_L01_004450F0((s32)m, 7, -1);
            } else {
                func_L01_004450F0((s32)m, 5, -1);
            }
        } else {
            if (*(s32 *)(s + 16) != 0) {
                return;
            }
            if (*(s32 *)(s + 12) != 0) {
                func_L01_003B42C8(0xA82, *(s32 *)(s + 28), *(s32 *)(s + 32), *(s32 *)(s + 36));
            } else {
                func_L01_003B42C8(0xA83, 0, 0, 0);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0043B548(0x19E1, 0x6C)->f18(0x19E1);
        }
        if (func_L01_004BA800() != 0) {
            return;
        }
        D_001426E0[230] = 0;
        D_001426E0[229] = 0;
        if (*(s32 *)(s + 12) == 0) {
            func_L01_004450F0((s32)m, 7, -1);
        } else if (*(s32 *)(s + 4) == 0) {
            func_L01_004450F0((s32)m, 7, -1);
        } else {
            func_L01_004450F0((s32)m, 5, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(s + 20) = 0x21;
        }
        if (*(s32 *)(s + 12) != 0) {
            func_L01_003B42C8(0xA82, *(s32 *)(s + 28), *(s32 *)(s + 32), *(s32 *)(s + 36));
        } else {
            func_L01_003B42C8(0xA83, 0, 0, 0);
        }
        if (func_0038CAD0(s + 20) != 0) {
            D_L01_001DF950 = 2.0f;
            if (*(s32 *)(s + 12) == 0) {
                func_L01_004450F0((s32)m, 7, -1);
            } else if (*(s32 *)(s + 4) == 0) {
                func_L01_004450F0((s32)m, 7, -1);
            } else {
                func_L01_004450F0((s32)m, 5, -1);
            }
        } else {
            D_L01_001DF950 = (1.0f - (f32)*(s32 *)(s + 20) / 33.0f) * 1.1f;
        }
        break;
    case 5:
        func_L01_003B5500(m, s, *(s32 *)(s + 8));
        func_L01_004450F0((s32)m, 6, -1);
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(s + 20) = 0x11;
        }
        if (func_0038CAD0(s + 20) != 0) {
            D_L01_001DF950 = 0.0f;
            func_L01_004450F0((s32)m, 7, -1);
        } else {
            D_L01_001DF950 = (f32)*(s32 *)(s + 20) / 17.0f * 1.1f;
        }
        break;
    case 7:
        func_L01_003B28D0(*(s32 *)s);
        func_L01_004450F0((s32)m, 1, -1);
        break;
    }
}
