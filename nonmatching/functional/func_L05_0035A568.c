/* functional: high. Branch-for-branch port; the 30-argument effect call has its 18 stack args decoded slot by slot (0x10000, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF). Diffs are register assignment and the loop tail layout. The slot-list loop reads q[-1] before the first element like retail. */
typedef int u128_35A568 __attribute__((mode(TI)));
extern u8 *D_L05_001DFB9C;
extern s32 func_L05_00356070(f32);
extern void func_L05_00356018(u8 *);
extern s32 D_L05_001D67BC;
extern u8 D_001D66B0;
extern void func_L01_00459C50(s32);
extern void func_L03_0043FC00(void *, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L05_0035A568(u8 *o, s32 a1) {
    u8 *s = *(u8 **)(o + 0x68);
    u128_35A568 pos;
    s32 x;
    s32 sel;
    s32 r6;
    s32 i;
    s16 *q;
    u8 *r;
    u8 *w;

    if (D_001D545C == 0x11) {
        if (s[0x60] != 0 || s[0x47] == 0x87) {
            D_L05_001D67BC = D_L05_001D67BC + 1;
            if (D_L05_001D67BC >= 0x28) {
                func_L01_00459C50(0x13);
            }
        }
    }
    if (a1 == 0) {
        if (s[0x60] == 0 && s[0x5E] == 0 && s[0x3E] != 2) {
            x = 1;
            sel = 7;
            if (*(u8 **)(s + 0x3EC) != 0) {
                pos = *(u128_35A568 *)(*(u8 **)(s + 0x3EC) + 0x10);
                sel = 0x7F;
                x = 2;
            } else {
                pos = *(u128_35A568 *)(o + 0x10);
            }
            if (func_L05_00356070(1.0f) != 0 || *(s16 *)(s + 0x3F4) != 0) {
                x = 0;
            }
            if (func_L05_00356070(1.4f) != 0) {
                func_L03_0043FC00(o, sel, &D_001D66B0, 3, x, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 1.0f);
            }
            r6 = *(s16 *)(s + 0x3F4) != 0 ? 3 : 7;
            func_L01_003303B8((u8 *)&pos, 0, r6, r6, r6, r6, r6 + 5, 0, 0.9f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        func_L01_004443E8(o, 0, 3);
        i = o[0x21];
        if (i != 0xFF) {
            q = (s16 *)D_L05_0021DAE0[i];
            for (;;) {
                i = o[0x21];
                if (i == 0xFF) {
                    break;
                }
                if (D_L05_001DFBD8 < i || q == 0) {
                    break;
                }
                if (!(q[-1] >= 0 || (void *)q == D_L05_0021DAE0[i])) {
                    break;
                }
                r = D_L05_001DFB9C + ((*(u16 *)q & 0x7FFF) << 8);
                if (r == 0) {
                    break;
                }
                q++;
                if (*(s16 *)(r + 0xAA) == 0x1625) {
                    w = *(u8 **)(r + 0x68);
                    if (w != 0) {
                        *(s32 *)(w + 0x39C) = *(s32 *)(w + 0x39C) + 1;
                    }
                }
            }
        }
    }
    if (*(u8 **)(s + 0x3EC) != 0) {
        func_003C2880(*(u8 **)(s + 0x3EC));
        *(s32 *)(s + 0x3EC) = 0;
    }
    func_L05_00356018(o);
}
