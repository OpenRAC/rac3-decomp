/* functional: low. Rewritten from PAL asm; low confidence because of size and the many inferred layouts (u+0x148 list stride is 16 in modes 3/5 but 0x24 in mode 2), the unreachable retail tail block omitted. */
/* localdecomp:start func_L01_004BF980 */
extern S_00244740 D_L01_002446C0[];
extern s32 D_001DADE0[];
extern s32 D_001D4B60_sda;
extern s32 D_001DAC60_sda[];
extern s16 D_001426A0[];
extern s32 D_00143950[];
extern f32 D_001DBD38_sda;
extern u8 D_001E13E0[];
extern f32 D_001E1400[];
extern f32 D_001E1404[];
extern f32 D_001E1408[];
extern u8 D_00251400[];
extern s32 D_001D54D0[];
extern s32 D_0016C580[];
extern s16 D_001D6700[];
extern s16 D_001D6706[];
extern s16 D_001D6708[];
extern s16 D_001D670A[];
extern s16 D_001D670C[];
extern s32 D_001DADF4_sda;
extern void func_L01_004BF950(void);
extern char *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern void func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_003C25D8(u8 *, s32);
extern void func_003C6F90(u8 *, s32, s32, s32, s32);
extern void func_003C7C38(u8 *);
extern void func_003C29B0(u8 *);
extern s32 func_00381CB0(void);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038CB78(u8 *, s32, s32);
extern void func_L01_0043A430(s32, s32, u8 *);
extern void func_L01_0043C8F8(u8 *, s32, s32, s32);
extern void func_00398BB8(s32);
extern void func_00398C80(s32);

void func_L01_004BF980(void) {
    u8 *u = (u8 *)D_L01_002446C0;
    s32 mode;
    s32 ids[5];
    u32 slots[12];
    s32 sel, e, e0, n, i, k, cnt;
    u8 *o;
    u8 *a;
    u8 *t6;
    s32 j;
    f32 fa, fb;

    mode = *(s32 *)(u + 0x50);
    if (mode == 0) return;
    if (u[0x89] != 0) func_L01_004BF950();
    *(s32 *)(u + 0x34) = 1;

    if (mode == 5 || mode == 3) {
        *(s32 *)(u + 0x34) = 0;
        for (i = 0; i < 5; i++) ids[i] = D_001DADE0[i];
        sel = *(s32 *)(u + 0x80);
        e = *(s32 *)(u + 0x148 + (sel << 4));
        if (e == 0) {
            func_L01_004BC0B8((s32)func_00381FF0(0x4AC));
        } else {
            if (D_001D4B60_sda != e && *(s32 *)(u + 0x768) == 0) {
                if (mode == 5) {
                    if (e == -1) {
                        func_L01_005147A8(0);
                        func_L01_00425978(D_001426A0[0]);
                    } else {
                        func_L01_005147A8(e);
                        func_L01_00425978(*(s32 *)(u + 0x148 + (*(s32 *)(u + 0x80) << 4)));
                    }
                } else {
                    func_L01_00425978(e);
                }
            }
            func_L01_004BC0B8((s32)func_00381FF0(D_001DAC60_sda[*(s32 *)(u + 0x148 + (*(s32 *)(u + 0x80) << 4))]));
        }
        if (ids[*(s32 *)(u + 0x34)] >= 0) {
            do {
                n = *(s32 *)(u + 0x34);
                o = (u8 *)*(s32 *)(u + 0x2C) + (n << 8);
                func_003C25D8(o, ids[n]);
                func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
                if (mode == 5) {
                    o[0x30] = 0;
                    o[0x23] = 0;
                    o[0x20] = 0;
                    *(s32 *)(o + 0x98) = 0;
                    *(s32 *)(o + 0xF0) = 0;
                    *(s32 *)(o + 0xF4) = 0;
                    *(s32 *)(o + 0x78) = 0x80808080;
                    *(u16 *)(o + 0x32) = 0x40;
                    o[0x31] = 1;
                    *(u16 *)(o + 0x34) = 0x2010;
                    o[0x62] = 0xFF;
                    *(f32 *)(o + 0xF8) = 2.0f;
                    func_003C7C38(o);
                    o[0x42] = 0;
                    o[0x43] = 0;
                    func_003C29B0(o);
                    if (D_001D4B60_sda >= 4 || func_00381CB0() > 0) {
                        if (*(s16 *)(o + 0xAA) == 0x50A) *(u16 *)(o + 0x34) |= 1;
                    }
                    if (!(D_001D4B60_sda < 3)) {
                        if (*(s16 *)(o + 0xAA) == 0xA73) *(u16 *)(o + 0x34) |= 1;
                    }
                } else {
                    o[0x30] = 0;
                    o[0x23] = 0;
                    o[0x20] = 0;
                    *(s32 *)(o + 0x98) = 0;
                    *(s32 *)(o + 0xF0) = 0;
                    *(s32 *)(o + 0xF4) = 0;
                    *(s32 *)(o + 0x78) = 0x80808080;
                    o[0x62] = 0xFF;
                    o[0x31] = 1;
                    *(u16 *)(o + 0x34) = 0x2010;
                    *(u16 *)(o + 0x32) = 0x40;
                    *(f32 *)(o + 0xF8) = func_0038DB48(*(f32 *)(o + 0xF8));
                    func_003C7C38(o);
                    o[0x42] = 0;
                    o[0x43] = 0;
                    func_003C29B0(o);
                    if (D_001D4B60_sda == 4) {
                        if (*(s16 *)(o + 0xAA) == 0x50A) *(u16 *)(o + 0x34) |= 1;
                    }
                    if (!(D_001D4B60_sda < 3)) {
                        if (*(s16 *)(o + 0xAA) == 0xA73) *(u16 *)(o + 0x34) |= 1;
                    }
                }
                *(s32 *)(u + 0x34) = *(s32 *)(u + 0x34) + 1;
            } while (ids[*(s32 *)(u + 0x34)] >= 0);
        }
        func_0038CB78(D_001E13E0, 0, 0x40);
        func_L01_0043A430(*(s32 *)(u + 0x2C), 0x18, D_001E13E0);
        fa = D_001DBD38_sda;
        fb = fa * 0.97f;
        D_001E1408[0] = fa;
        D_001E1404[0] = fb;
        D_001E1400[0] = fb;
        if (D_001D4B60_sda < 3) {
            a = D_00251400;
            func_0038CB78(a, 0, 0x40);
            func_0038CB78(a + 0x40, 0, 0x40);
            for (j = 0; j < 2; j++, a += 0x40) {
                func_L01_0043A430(*(s32 *)(u + 0x2C), 0x16 + j, a);
                *(f32 *)(a + 0x20) = 0.01f;
                *(f32 *)(a + 0x24) = 0.01f;
                *(f32 *)(a + 0x28) = 0.01f;
            }
        }
        goto tail;
    }

    if (mode == 2) {
        sel = *(s32 *)(u + 0x80);
        e0 = *(s32 *)(u + 0x148 + sel * 0x24);
        *(s32 *)(u + 0x34) = 10;
        *(s32 *)(u + 0x4C) = (D_001D54D0[0] & ~e0) | *(s32 *)(u + 0x14C + sel * 0x24);
        t6 = (u8 *)D_0016C580[0];
        slots[0] = (u32)((s32)*(s16 *)(t6 + 0xAA) << 16);
        if (e0 == 3) slots[0] |= 0x80000000;
        {
            s32 v = *(s16 *)((u8 *)D_001D6700 + ((*(s32 *)(u + 0x4C) & 0xC) >> 1));
            slots[1] = (u32)(v << 16);
            slots[2] = slots[1] | 0x8000;
            if (e0 == 0xC) { slots[2] |= 0x80000000; slots[1] |= 0x80000000; }
        }
        {
            s32 v = D_001D670C[0];
            slots[3] = (u32)(v << 16);
            slots[4] = slots[3] | 0x8000;
            if (e0 == 0xC00) { slots[4] |= 0x80000000; slots[3] |= 0x80000000; }
        }
        {
            s32 v = D_001D6706[0];
            slots[5] = (u32)(v << 16);
            if (e0 == 0x30) slots[5] |= 0x80000000;
        }
        {
            s32 v = D_001D6708[0];
            slots[6] = (u32)(v << 16);
            slots[7] = slots[6] | 0x8000;
            if (e0 == 0x40) { slots[7] |= 0x80000000; slots[6] |= 0x80000000; }
        }
        {
            s32 v = D_001D670A[0];
            slots[8] = (u32)(v << 16);
            slots[9] = slots[8] | 0x8000;
            if (e0 == 0x200) { slots[9] |= 0x80000000; slots[8] |= 0x80000000; }
        }
        *(s32 *)(u + 0xA0) = 0;
        slots[*(s32 *)(u + 0x34)] = 0x10E30000;
        *(s32 *)(u + 0x34) = *(s32 *)(u + 0x34) + 1;
        if (e0 == 0xC00 || e0 == 0x200 || e0 == 0xC || e0 == 3 || e0 == 0x40) {
            *(f32 *)(u + 0xA4) = 0.346f;
            *(f32 *)(u + 0xA8) = 0.3227f;
            *(f32 *)(u + 0xAC) = func_0038DAB8(0.8566f, 3.1415927f);
        } else if (e0 == 0x30 || e0 == 0x2000) {
            *(f32 *)(u + 0xA4) = 0.0225f;
            *(f32 *)(u + 0xA8) = 0.0239f;
            *(f32 *)(u + 0xAC) = func_0038DB00(-3.0301f, 1.5707964f);
        } else {
            e = *(s32 *)(u + 0x148 + sel * 0x24);
            if (e == 0x1000 || e == 0x180) {
                *(f32 *)(u + 0xA4) = -0.587f;
                *(f32 *)(u + 0xA8) = 0.165f;
                *(f32 *)(u + 0xAC) = func_0038DAB8(2.055f, 1.5707964f);
            } else if (e == 0x1F0000) {
                *(f32 *)(u + 0xA4) = (sel & 1) ? 0.533f : 0.566f;
                *(f32 *)(u + 0xA8) = (sel & 1) ? 0.3203f : 0.165f;
                *(f32 *)(u + 0xAC) = func_0038DAB8((sel & 1) ? 0.6699f : 1.4345f, 3.1415927f);
            } else if (e == 0xC000) {
                *(f32 *)(u + 0xA4) = -0.5f;
                *(f32 *)(u + 0xA8) = -0.4f;
                *(f32 *)(u + 0xAC) = func_0038DB00(-2.1f, 1.5707964f);
            } else {
                *(s32 *)(u + 0xA4) = 0;
                *(f32 *)(u + 0xAC) = -1.5707964f;
                *(s32 *)(u + 0xA8) = 0;
            }
        }
        *(s32 *)(u + 0x58) = -1;
        *(s32 *)(u + 0x54) = -1;
        k = 0;
        cnt = *(s32 *)(u + 0x34);
        for (i = 0; i < cnt; i = i + 1) {
            o = (u8 *)*(s32 *)(u + 0x2C) + (i << 8);
            func_003C25D8(o, *(u16 *)((u8 *)&slots[i] + 2) & 0x7FFF);
            func_003C6F90(o, 0x202020, 0xE, 0xE, 0);
            if (slots[i] & 0x80000000) {
                *(s32 *)(u + 0x54 + k * 4) = i;
                k++;
            }
            if (o[0x63] != 0) o[0x63] = 0xF;
            *(u16 *)(o + 0x32) = 0x100;
            o[0x31] = 1;
            *(s32 *)(o + 0x78) = 0x80808080;
            o[0x30] = 0;
            o[0x23] = 0xFF;
            *(u16 *)(o + 0x34) = *(u16 *)&slots[i] | 0x2010;
            o[0x20] = 0;
            *(s32 *)(o + 0x98) = 0;
            *(f32 *)(o + 0x2C) = 1.0f;
            *(f32 *)(u + 0xC0) = -12.0f;
            *(f32 *)(u + 0x94) = 1.0f;
            *(s32 *)(u + 0xC4) = 0;
            *(f32 *)(u + 0xC8) = (((u8 *)D_00143950)[0xAD] != 0) ? 1.45f : 2.0f;
            *(s32 *)(o + 0xF0) = 0;
            *(s32 *)(o + 0xF4) = 0;
            *(f32 *)(o + 0xF8) = -1.5707964f;
            func_003C7C38(o);
        }
        *(u8 *)(u + 0x88) = 1;
        *(s32 *)(u + 0x98) = 0;
        u[0x89] = 0;
        *(s32 *)(u + 0x8C) = 0;
        if (D_001DADF4_sda != (*(s32 *)(u + 0x4C) & 3)) {
            func_00398BB8(*(s32 *)(u + 0x4C) & 3);
            D_001DADF4_sda = *(s32 *)(u + 0x4C) & 3;
        }
        if (D_0016C580[12] != (*(u16 *)(u + 0x4E) & 0x1F)) func_00398C80(*(u16 *)(u + 0x4E) & 0x1F);
        return;
    }

    /* modes other than 0, 2, 3, 5 (retail's remaining mode-0 body after this test is unreachable) */
    u[0x88] = 0;
    u[0x89] = 0;
    return;

tail:
    o = (u8 *)*(s32 *)(u + 0x2C);
    t6 = (u8 *)*(s32 *)(o + 0x24);
    a = (u8 *)*(s32 *)(t6 + o[0x42] * 4 + 0x48);
    if (*(u32 *)(a + 0x1C) & 0xF0000000) {
        func_L01_0043C8F8(a + 0x1C + a[0x10] * 4 + a[0x13] * 4, *(s32 *)(a + o[0x40] * 4 + 0x1C), *(s32 *)(u + 0x20), t6[8]);
        *(s32 *)(o + 0x58) = *(s32 *)(u + 0x20);
        t6 = (u8 *)*(s32 *)(o + 0x24);
    }
    a = (u8 *)*(s32 *)(t6 + o[0x43] * 4 + 0x48);
    if (*(u32 *)(a + 0x1C) & 0xF0000000) {
        func_L01_0043C8F8(a + 0x1C + a[0x10] * 4 + a[0x13] * 4, *(s32 *)(a + o[0x41] * 4 + 0x1C), *(s32 *)(u + 0x24), t6[8]);
        *(s32 *)(o + 0x5C) = *(s32 *)(u + 0x24);
    }
    *(f32 *)(u + 0xC0) = -9.0f;
    *(f32 *)(u + 0xC4) = 3.25f;
    *(f32 *)(u + 0xC8) = (((u8 *)D_00143950)[0xAD] != 0) ? -0.02f : 0.5f;
    *(f32 *)(u + 0x94) = 3.5f;
    u[0x88] = 1;
    *(s32 *)(u + 0x8C) = 0;
    *(s32 *)(u + 0x98) = 0;
    u[0x89] = 0;
}
/* localdecomp:end func_L01_004BF980 */
