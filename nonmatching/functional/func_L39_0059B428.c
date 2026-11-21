/* functional: medium. jump table jtbl_00479E50 read from data.data.s (state1->B4E0, 2->BAB8, 3->B590, 4-6->B698, 7->BAC8); compiled under level_39 (501 diff lines, regalloc); callee arg types guessed (func_0038B4D0 takes 8 ints + two stack u64); gp slots D_001D7360..739C_sda are layout constants; the type list 0x150E/0x1DC/0xB0E/0x166A/0x1736 maps to ids 0x5D/0x5C/0x61/0x62/0x5E */
typedef struct {
    s32 state;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xC];
    s32 f30;
    u8 pad34[0xC];
    s32 f40;
    s32 f44;
} Cur_0059B428;

typedef struct {
    u8 pad0[0xE];
    s16 type;
} Ent_0059B428;

typedef struct {
    u8 pad0[0x22];
    u16 f22;
    u8 pad24[4];
    s16 f28;
    s16 f2A;
    u8 pad2C[4];
} Rect_0059B428;

typedef struct {
    u8 pad0[5];
    u8 b5;
} Cfg_0059B428;

extern Cur_0059B428 D_L39_004989E0;
extern Cfg_0059B428 D_001A5810;
extern s32 *D_L39_00241120;
extern Ent_0059B428 (*D_L39_0024BCC0)[];
extern s32 D_L39_00242850;
extern s32 D_001D7360_sda;
extern s32 D_001D7364_sda;
extern s32 D_001D7368_sda;
extern s32 D_001D736C_sda;
extern s32 D_001D7370_sda;
extern s32 D_001D7374_sda;
extern s32 D_001D7378_sda;
extern s32 D_001D7380_sda;
extern s32 D_001D7384_sda;
extern s32 D_001D7388_sda;
extern s32 D_001D738C_sda;
extern s32 D_001D7390_sda;
extern s32 D_001D7394_sda;
extern s32 D_001D739C_sda;

extern void func_L01_003DF8B8(void);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, u32, f32, f32, f32, f32);
extern void func_003910C0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern s64 func_L39_00589890(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, s64, s64);
extern void func_0038E150(s32);
extern void func_L39_00593468(void *, s64, s32, s32, s64, f32, f32);

void func_L39_0059B428(void) {
    Cur_0059B428 *t = &D_L39_004989E0;
    Rect_0059B428 rect;
    s32 ent0;
    s32 n;
    s32 a;
    s32 b;
    s32 hw;
    s32 hh;
    s32 m;
    s32 alpha;
    s32 type;
    s32 flag;
    s32 fp;
    s32 r23;
    s32 r19;
    s32 r17;
    s32 r18;
    s32 r21;
    s32 id;
    s32 w;
    s32 h;

    t->f44 -= 1;
    if (t->f44 < 0) {
        t->f44 = 0;
    }
    if (t->f44 == 0) {
        t->f40 = 0;
    }
    if (t->state == 0) {
        return;
    }
    if (t->f30 == 0) {
        return;
    }
    if (D_001A5810.b5 == 0) {
        return;
    }
    if (*D_L39_00241120 >= 2) {
        return;
    }
    if ((u32)(t->state - 1) >= 7) {
        return;
    }
    switch (t->state) {
    case 1:
        if (D_001A5810.b5 == 0) {
            func_L01_003DF8B8();
            return;
        }
        t->f1C = 8;
        t->f18 = 8;
        func_0038C3B0(t->f14 - 8 + t->f40, t->f14 + 8 + t->f40, t->f10 - 8, t->f10 + 8,
                      0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE, (f32)(t->f14 - t->f1C + t->f40),
                          (f32)(t->f14 + t->f1C + t->f40), (f32)(t->f10 - t->f18),
                          (f32)(t->f10 + t->f18));
        return;
    case 2:
        func_L01_003DF8B8();
        return;
    case 3:
        if (D_001A5810.b5 == 0) {
            func_L01_003DF8B8();
            return;
        }
        n = t->f4;
        if (n >= 9) {
            n = 8;
        }
        if (n < 0) {
            n = 0;
        }
        a = (t->fC - 0x20) * n;
        b = (t->f8 - 0x20) * n;
        hw = ((a >= 0 ? a : a + 7) >> 3) + 0x20;
        hh = ((b >= 0 ? b : b + 7) >> 3) + 0x20;
        t->f18 = hh;
        t->f1C = hw;
        func_0038C3B0(t->f14 - hw + t->f40, t->f14 + hw + t->f40, t->f10 - hh, t->f10 + hh,
                      0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE, (f32)(t->f14 - t->f1C + t->f40),
                          (f32)(t->f14 + t->f1C + t->f40), (f32)(t->f10 - t->f18),
                          (f32)(t->f10 + t->f18));
        return;
    case 4:
    case 5:
    case 6:
        if (D_001A5810.b5 == 0) {
            func_L01_003DF8B8();
            return;
        }
        m = 0;
        fp = 0xF0;
        r23 = 0x1E0;
        r19 = 0x2C;
        r21 = 0x10;
        type = (*D_L39_0024BCC0)[t->f20].type;
        flag = 0;
        if (type == 0x150E || type == 0x1DC || type == 0xB0E || type == 0x166A
            || type == 0x1736) {
            flag = 1;
        }
        if (flag != 0) {
            m = 10;
            if (t->fC + 10 < 0x22) {
                m = 2 - (t->fC - 0x20);
            }
            t->f8 = 0xD4;
        }
        t->f18 = t->f8;
        t->f1C = t->fC;
        func_0038C3B0(t->f14 - t->fC + t->f40 - m, t->f14 + t->fC + t->f40 + m,
                      t->f10 - t->f8, t->f10 + t->f8, 0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE, (f32)(t->f14 - t->f1C + t->f40 - m),
                          (f32)(t->f14 + t->f1C + t->f40 + m), (f32)(t->f10 - t->f18),
                          (f32)(t->f10 + t->f18));
        ent0 = *(s32 *)&(*D_L39_0024BCC0)[t->f20];
        r17 = D_001D7364_sda + 0x1D4;
        r18 = D_001D7360_sda + 0x100;
        if (*D_L39_00241120 == 2) {
            fp = D_001D7368_sda;
            r23 = D_001D736C_sda;
            r19 = D_001D7370_sda;
            r17 = D_001D7374_sda;
            r18 = D_001D7378_sda;
            r21 = D_001D7380_sda;
        } else if (*D_L39_00241120 == 4) {
            fp = D_001D7384_sda;
            r23 = D_001D7388_sda;
            r19 = D_001D738C_sda;
            r17 = D_001D7390_sda;
            r18 = D_001D7394_sda;
            r21 = D_001D739C_sda;
        }
        type = (*D_L39_0024BCC0)[t->f20].type;
        if (type > 0) {
            func_003910C0(&rect, fp + t->f40, r23 + t->f40, r19 + 0x44, r17, r19 + 0x44,
                          t->f14 + t->f40, r21, 2);
        } else {
            func_003910C0(&rect, fp + t->f40, r23 + t->f40, r19, r17, r18, t->f14 + t->f40,
                          r21, 3);
        }
        rect.f22 |= 0x20;
        rect.f2A = 2;
        rect.f28 = 2;
        type = (*D_L39_0024BCC0)[t->f20].type;
        if (type > 0) {
            if (type == 0x150E) {
                id = 0x5D;
            } else if (type == 0x1DC) {
                id = 0x5C;
            } else if (type == 0xB0E) {
                id = 0x61;
            } else if (type == 0x166A) {
                id = 0x62;
            } else if (type == 0x1736) {
                id = 0x5E;
            } else {
                id = 0;
            }
            if (id != 0) {
                func_0038B4D0(r19 + 6, t->f14 - 0x1E + t->f40, 0x38, 0x3D, 0, 0, 0x40, 0x40,
                              0x80808080LL, func_L39_00589890(id));
            } else {
                func_003910C0(&rect, fp + t->f40, r23 + t->f40, r19, r17, r18,
                              t->f14 + t->f40, r21, 3);
                rect.f22 |= 0x20;
                rect.f2A = 2;
                rect.f28 = 2;
            }
        }
        D_L39_00242850 = t->state == 4 ? 1 : 2;
        func_0038E150(1);
        func_L39_00593468(&rect, 0x8066CCFFLL, ent0, -1, 0x80000000LL, 1.0f, 1.0f);
        return;
    case 7:
        if (D_001A5810.b5 == 0) {
            func_L01_003DF8B8();
            return;
        }
        n = t->f4;
        if (n >= 9) {
            n = 8;
        }
        if (n < 0) {
            n = 0;
        }
        a = (t->f1C - 8) * n;
        b = (t->f18 - 8) * n;
        alpha = (8 - n) * 0xC;
        w = t->f1C - ((a >= 0 ? a : a + 7) >> 3);
        h = t->f18 - ((b >= 0 ? b : b + 7) >> 3);
        func_0038C3B0(t->f14 - w + t->f40, t->f14 + w + t->f40, t->f10 - h, t->f10 + h,
                      alpha, 0x600E5092);
        func_L01_00436020(alpha, 0x332299DE, (f32)(t->f14 - w + t->f40),
                          (f32)(t->f14 + w + t->f40), (f32)(t->f10 - h), (f32)(t->f10 + h));
        return;
    }
}
