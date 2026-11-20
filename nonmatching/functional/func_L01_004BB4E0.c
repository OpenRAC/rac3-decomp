/* functional: medium. Opens the Veldin vendor/shop menu: a0 < 7 starts it from a fresh state (a0 == 4 is the "first visit" variant), a0 >= 7 is the vendor object pointer (type 0xB or 0x1D99) whose state at +0x68->+0x94 picks the page; clears the 0x790-byte menu state at D_L01_002446C0, builds the page's slot list (4BAA20 / 4BAFB8 / 4BB330 / 4BB140), places the menu camera/object and resets the display globals. vadd.xyz is written as plain C; lq/sq quad copies as 4-word copies. The jump table (read from retail) maps case 0->page0, 2->page2, 3->page3, 5->page5, 6->page0b, cases 1 and 4 and out-of-range fall to the default. Data names follow docs/build/globals.md (core D_XXXXXXXX, level D_L01_, $gp slots D_XXXXXXXX_sda). Struct field names are mine; offsets come from the asm. */
extern u8 D_00143950[];
extern s16 D_001426A0[];
extern u8 D_001D5477[];
extern s32 D_001D4BC0[];
extern s32 D_001D4BC4[];
extern s32 D_001D54D0[];
extern u8 D_0016C690[];
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern s32 D_001427F0[];
extern f32 D_L01_001E0FD0[];
extern s32 D_L01_001E0FE0[];
extern s32 D_L01_001E0FE4[];
extern s32 D_L01_001E0FE8[];
extern s32 D_L01_001E0F84[];
extern s32 D_L01_001E0F90[];
extern s32 D_L01_001E0F94[];
extern s32 D_L01_001E0FD4[];
extern s32 D_L01_001E0FD8[];
extern s32 D_L01_001E0FDC;
extern s32 D_L01_001DAC50;
extern f32 D_L01_001DAC54;
extern f32 D_L01_001DAC58;
extern s32 D_L01_001DABA4;
extern s32 D_L01_001DABA8;
extern s32 D_L01_001DABD4;
extern s32 D_L01_001DABE0;
extern s32 D_L01_001D7BE0[];
extern s32 D_L01_001D673C[];
extern f32 D_L01_001DF950[];
extern s32 D_L01_001DF958;
extern f32 D_L01_001E29C0[4];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001EA940[];
extern u8 D_L01_001F1AD0[];
extern u8 D_L01_001DAC00;
extern u8 D_L01_001DAC10;
extern u8 D_L01_001DAC30;
extern u8 D_L01_001DAC40;
extern u8 D_001A4BE0[];

extern void func_0038CB78(void *, s32, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern void func_L01_004C2548(void);
extern void func_L01_004C4380(void);
extern void func_L01_004C3910(void);
extern void func_L01_004C4FE8(void);
extern void func_0013C1A0(s32);
extern void func_L01_0045F328(s32);
extern void func_0013B620(void);
extern void func_L01_004BAA20(s32);
extern void func_L01_004BAFB8(void);
extern void func_L01_004BB330(void);
extern s32 func_L01_004BB140(void);
extern void func_L01_0041FE30(void);
extern void func_003E54E0(s32);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L01_0041A6E0(void);
extern void func_L01_005108C0(s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_00384D88(void);

static void copy16_004BB4E0(void *d, void *s) {
    ((u64 *)d)[0] = ((u64 *)s)[0];
    ((u64 *)d)[1] = ((u64 *)s)[1];
}

static void zero16_004BB4E0(void *d) {
    ((u64 *)d)[0] = 0;
    ((u64 *)d)[1] = 0;
}

void func_L01_004BB4E0(s32 a0) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *obj;
    u8 *rec;
    u8 sv758;
    s32 sv760;
    s32 sel;
    s32 mode;
    s32 cnt;
    s32 i;
    s32 id;
    s32 v;
    f32 q[4];
    f32 sp0[4];
    f32 sp10[4];
    f32 sp20[4];
    f32 sp30[4];
    u8 *src;
    f32 *dv;
    f32 *vv;
    f32 *G;

    sv758 = T[0x758];
    sv760 = *(s32 *)(T + 0x760);
    func_0038CB78(T, 0, 0x790);
    D_L01_001E0FD0[0] = (*(s32 *)D_00143950 != 0) ? 1.0769231f : 1.0f;
    D_L01_001DABA4 = D_001D5477[0];
    D_L01_001DABD4 = D_001426A0[0];
    *(s32 *)(T + 0x60) = 0;
    D_001D5477[0] = 0;
    sel = a0;
    if ((u32)a0 < 7) {
        *(s32 *)(T + 0x60) = 1;
        if (a0 == 4) {
            *(s32 *)(T + 0x5C) = 1;
            sel = 0;
        }
        obj = func_003C24B0(0xB, 0x80);
        *(s16 *)(obj + 0x32) = 0x40;
        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x80;
        if (D_00143950[0xAD] != 0) {
            vv = (f32 *)&D_L01_001DAC10;
        } else {
            vv = (f32 *)&D_L01_001DAC00;
        }
        sp0[0] = vv[0];
        sp0[1] = vv[1];
        sp0[2] = vv[2];
        sp0[3] = vv[3];
        sp0[2] = -sp0[2];
        dv = (f32 *)(obj + 0x10);
        dv[0] = D_L01_001E29C0[0] + sp0[0];
        dv[1] = D_L01_001E29C0[1] + sp0[1];
        dv[2] = D_L01_001E29C0[2] + sp0[2];
        dv[3] = D_L01_001E29C0[3];
        *(u64 *)(obj + 0xF0) = 0;
        *(u64 *)(obj + 0xF8) = 0;
        *(f32 *)(obj + 0xF8) = 3.1415927f;
        func_003C7C38(obj);
        *(s32 *)(T + 0x60) = 1;
        *(s32 *)(T + 0x744) = 0;
        obj[0x20] = 3;
        switch (sel) {
        case 0:
            *(s32 *)(T + 0x50) = 0;
            *(s32 *)(T + 0x744) = 0;
            func_L01_004C2548();
            break;
        case 2:
            *(s32 *)(T + 0xA0) = 0;
            *(s32 *)(T + 0x50) = 2;
            *(f32 *)(T + 0xB8) = -1.5707964f;
            *(s32 *)(T + 0xB0) = 0;
            *(s32 *)(T + 0xB4) = 0;
            func_L01_004C4380();
            break;
        case 3:
            *(s32 *)(T + 0x50) = 3;
            func_L01_004C3910();
            break;
        case 5:
            *(s32 *)(T + 0x50) = 5;
            D_L01_001DABA8 = D_L01_001D7BE0[0];
            func_L01_004C4FE8();
            break;
        case 6:
            *(s32 *)(T + 0x744) = 1;
            *(s32 *)(T + 0x50) = 0;
            func_L01_004C2548();
            break;
        default:
            break;
        }
    } else {
        obj = (u8 *)a0;
        if (*(s16 *)(obj + 0xAA) == 0xB) {
            v = *(s32 *)(*(u8 **)(obj + 0x68) + 0x94);
            if (v == 0) {
                *(s32 *)(T + 0x50) = 0;
                func_L01_004C2548();
            } else if (v == 4) {
                *(s32 *)(T + 0x50) = 2;
                func_L01_004C4380();
            } else if (v == 2) {
                *(s32 *)(T + 0x50) = 3;
                func_L01_004C3910();
            } else if (v == 5) {
                *(s32 *)(T + 0x50) = 5;
                func_L01_004C4FE8();
            } else if (v == 3) {
                *(s32 *)(T + 0x50) = 0;
                *(s32 *)(T + 0x744) = 1;
                func_L01_004C2548();
            }
        } else if (*(s16 *)(obj + 0xAA) == 0x1D99) {
            *(s32 *)(T + 0x28) = (s32)obj;
            *(s32 *)(T + 0x50) = 2;
            func_L01_004C4380();
        }
    }
    if (D_L01_001DABE0 != -1) {
        *(s32 *)(T + 0x50) = D_L01_001DABE0;
    }

    v = D_00143950[0xB7] - 1;
    T[0x88] = 0;
    T[0x89] = 0;
    *(s32 *)(T + 0x38) = (*(s32 *)(T + 0x50) == 0) ? 2 : 6;
    *(s32 *)(T + 0x44) = v;
    if (v < 0) {
        *(s32 *)(T + 0x44) = 0;
    }
    *(s32 *)(T + 0x68) = -1;
    D_L01_001E0FE8[0] = 0x46;
    D_L01_001DAC54 = 0.8f;
    D_L01_001DAC58 = 1.0f;
    D_L01_001E0FE0[0] = 0x41;
    D_L01_001E0FE4[0] = 0x60;
    *(s32 *)(T + 0x78) = -1;
    *(s32 *)(T + 0x7C) = -1;
    *(s32 *)(T + 0x64) = 0;
    *(s32 *)(T + 0x80) = 0;
    D_L01_001E0F90[0] = 0;
    *(s32 *)(T + 0x84) = 0;
    D_L01_001E0F94[0] = 0;
    D_L01_001E0F84[0] = 0;
    D_L01_001DAC50 = 0;
    D_L01_001E0FD4[0] = 0;
    D_L01_001E0FD8[0] = 0;
    D_L01_001E0FDC = 0;
    func_0013C1A0(0x4D);
    func_L01_0045F328(0);
    func_0013B620();

    mode = *(s32 *)(T + 0x50);
    if (mode == 0) {
        func_L01_004BAA20(0);
    } else if (mode == 3) {
        func_L01_004BAFB8();
        D_001426E0[0x75] = D_001426E0[0x75] | D_001426E0[0x3E];
    } else if (mode == 2) {
        func_L01_004BB330();
    } else if (mode == 5) {
        func_L01_004BB140();
    }

    cnt = *(s32 *)(T + 0x740);
    if (sv758 != 0) {
        *(s32 *)(T + 0x80) = 0;
        if (cnt > 0) {
            if (*(s32 *)(T + 0x140) != sv760) {
                for (i = 1; i < *(s32 *)(T + 0x740); i++) {
                    if (*(s32 *)(T + 0x140 + i * 0x14) == sv760) {
                        *(s32 *)(T + 0x80) = i;
                        break;
                    }
                }
            }
        }
    } else {
        mode = *(s32 *)(T + 0x50);
        if (mode == 3 || mode == 5) {
            *(s32 *)(T + 0x80) = 0;
        } else if (*(s32 *)(T + 0x744) != 0) {
            *(s32 *)(T + 0x80) = cnt / 2;
        } else if (cnt > 0 && T[0x144] == 0) {
            *(s32 *)(T + 0x80) = 0;
            for (i = 1; i < cnt; i++) {
                if (T[0x144 + i * 0x14] != 0) {
                    break;
                }
                *(s32 *)(T + 0x80) = i;
            }
        }
    }

    func_L01_0041FE30();
    func_003E54E0(0);
    if (*(s32 *)(T + 0x50) == 0) {
        i = *(s32 *)(T + 0x80);
        if (T[0x144 + i * 0x14] == 1) {
            id = *(s32 *)(T + 0x140 + i * 0x14);
            rec = (u8 *)D_L01_002C5600 + D_001425C0[id] * 0xF0;
            if (rec[0] != 0 && D_00142CA0[id] != 0) {
                func_L01_0047B798(*(u16 *)(rec + 0x38), 0);
                func_L01_0047B820(D_001427F0[id], *(u16 *)(rec + 0x8A));
                func_L01_0047B9B8(id);
            }
        }
    }

    *(s32 *)(T + 0x764) = D_L01_001E2A40[0x27D];
    *(s32 *)(T + 0x14) = *(s32 *)(D_L01_001EA940 + 0xC) + 0x60000;
    *(s32 *)(T + 0x1C) = *(s32 *)(D_L01_001EA940 + 0x10) + 0x60000 + (D_001D4BC0[0] * D_001D4BC4[0]) * 4;
    *(s32 *)(T + 0x00) = 0;
    *(s32 *)(T + 0x10) = *(s32 *)(D_L01_001EA940 + 0x10) + 0x60000;
    *(s32 *)(T + 0x08) = 0;
    *(s32 *)(T + 0x0C) = 1;
    *(s32 *)(T + 0x28) = (s32)obj;
    func_003A52A0(3, 0x11, obj);
    *(s32 *)(T + 0x4C) = D_001D54D0[0];
    *(s32 *)(T + 0x9C) = *(s16 *)(D_0016C690 + 0x14);
    func_L01_0041A6E0();
    D_L01_001D6694 = 5;
    D_L01_001DF950[0] = 0;
    D_L01_001DF958 = 0;
    if (*(s32 *)(T + 0x5C) == 0) {
        if (*(s32 *)(T + 0x60) == 0) {
            D_001A4BE0[0x25E5] = 1;
            D_001A4BE0[0x25ED] = 1;
            func_L01_005108C0(0);
        }
    }
    if (*(s32 *)(T + 0x60) == 0) {
        if (D_00143950[0xAD] != 0) {
            src = &D_L01_001DAC10;
        } else {
            src = &D_L01_001DAC00;
        }
        func_0038D000(T + 0xD0, src, (u8 *)*(s32 *)(T + 0x28) + 0xC0);
        obj = (u8 *)*(s32 *)(T + 0x28);
        {
            f32 *a = (f32 *)(T + 0xD0);
            f32 *b = (f32 *)(obj + 0x10);
            a[0] = a[0] + b[0];
            a[1] = a[1] + b[1];
            a[2] = a[2] + b[2];
        }
        *(f32 *)(T + 0xE8) = func_0038DAB8(*(f32 *)(obj + 0xF8), 3.1415927f);
        if (D_L01_001D673C[0] != 0) {
            u8 *o2 = (u8 *)*(s32 *)(T + 0x28);
            copy16_004BB4E0(sp10, o2 + 0xC0);
            copy16_004BB4E0(sp20, o2 + 0xD0);
            copy16_004BB4E0(sp30, o2 + 0xE0);
            func_003C5180(T + 0xD0, sp0, 1);
            func_L01_004515D8(sp10, sp0, 0);
            func_0038D890(sp10, sp10, sp30, 3.1415927f);
            func_0038D890(sp20, sp20, sp30, 3.1415927f);
            func_003C48A8(sp10, T + 0xE0);
        }
        func_L01_003EB438(0, T + 0xD0, T + 0xE0, 1, 0, 0);
        copy16_004BB4E0(sp0, T + 0xD0);
        if (*(s32 *)(T + 0x50) == 2) {
            sp0[1] = sp0[1] + 5.0f;
        }
        func_L01_003EB350(0, sp0);
        func_L01_003EB3C0(0, T + 0xE0);
        D_L01_001E2A40[0x27D] = 0;
        func_00384D88();
    }
    func_0038D000(D_L01_001F1AD0, &D_L01_001DAC30, (u8 *)*(s32 *)(T + 0x28) + 0xC0);
    copy16_004BB4E0(q, &D_L01_001DAC40);
    zero16_004BB4E0(D_L01_001F1AD0 + 0x10);
    zero16_004BB4E0(D_L01_001F1AD0 + 0x20);
    copy16_004BB4E0(D_L01_001F1AD0 - 0x10, q);
}
