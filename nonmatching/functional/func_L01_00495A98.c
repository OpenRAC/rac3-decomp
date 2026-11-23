/* functional: high. Ported from the NTSC-U draft (renamed callees/data by PAL asm), 311 diff at level_01 (compiles). PAL runs at 50 Hz: time formatting uses t/3000%60, t/50%60, t/5%10 instead of NTSC's 60 Hz divisors; init bytes of buf[5] copied from the NTSC draft ({1F,21,22,20,23}) and not re-verified in PAL data. */
typedef struct {
    void (*f0)(s32);
    s32 (*f1)(s32);
    void (*f2)(s32);
} Ops_4922A0;
extern s32 D_001D52FC;
extern s32 D_L01_001D9028;
extern s32 D_L01_001D9140;
extern u8 D_L01_001D90D4;
extern s32 D_L01_001D90C0[2];
extern char D_L01_001E0B30[8];
extern char D_L01_001E0B40[8];
extern u8 D_001426E0[];
extern u8 D_001BBB18[];
extern u16 D_001D55A0[4];
extern char D_L01_001D9150[];
extern char D_L01_001D9168[];
extern char D_L01_001D9170[];
extern char D_L01_001D9180[];
extern Ops_4922A0 *func_L01_0043B548(s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_003B9700(s32, s32, s32, char *, s32);
extern s32 func_003B97B0(void);
extern s32 func_L01_00498110(void);
extern void func_0039EF28(void);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00516FD8(s32, char *);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00517190(s32, s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_003825F8(u32, u32, s32, s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_0041A4F0(void);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);

void func_L01_00495A98(s32 a0) {
    Ops_4922A0 *ops = func_L01_0043B548(0x18E2, 0xC);
    u8 buf[5] = {0x1F, 0x21, 0x22, 0x20, 0x23};
    s32 st;
    s32 k;
    s32 ok;
    s32 s5;
    s32 old;
    s32 t;
    s32 buttons;
    s32 b2;

    st = D_L01_001D9140;
    switch (st) {
    case 1:
        func_003B9700(0, func_00381FF0(0x8E2), func_00381FF0(0x177), D_L01_001D9150, 0);
        D_L01_001D9140 = 2;
        return;
    case 2:
        if (func_003B97B0() != 0) {
            return;
        }
        D_L01_001D9140 = 0;
        if (func_L01_00498110() == st) {
            ops->f0(D_L01_001D9028);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090(a0);
            return;
        }
        if ((u8)(buf[D_L01_001D9028] - 0x1E) < 8) {
            D_001426E0[0x54] |= 1 << (buf[D_L01_001D9028] - 0x1E);
        }
        func_0039EF28();
        ops->f2(buf[D_L01_001D9028]);
        if (buf[D_L01_001D9028] == 0x1F) {
            D_001426E0[0xB] = 1;
            func_0039EF28();
        }
        return;
    case 0:
    default:
        buttons = *(s32 *)(D_001D52FC + 0x1C4);
        old = D_L01_001D9028;
        if (buttons & 0x1000) {
            func_003A5348(3, 0, 0);
            func_003825F8(0x332299DE, 0x8066CCFF, 0x28, 0, 1, 1);
            func_L01_005170B8(D_L01_001D9028 + 0x11000C, 0x332299DE);
            do {
                D_L01_001D9028 = D_L01_001D9028 - 1;
                if (D_L01_001D9028 < 0) {
                    D_L01_001D9028 = 5;
                }
            } while (ops->f1(D_L01_001D9028) == 0 && D_L01_001D9028 != old);
            func_L01_00517190(0x110022, D_L01_001D9028 + 1);
        } else if (buttons & 0x4000) {
            func_003A5348(3, 0, 0);
            func_003825F8(0x332299DE, 0x8066CCFF, 0x28, 0, 1, 1);
            func_L01_005170B8(D_L01_001D9028 + 0x11000C, 0x332299DE);
            do {
                D_L01_001D9028 = D_L01_001D9028 + 1;
                if (D_L01_001D9028 >= 6) {
                    D_L01_001D9028 = 0;
                }
            } while (ops->f1(D_L01_001D9028) == 0 && D_L01_001D9028 != old);
            func_L01_00517190(0x110022, D_L01_001D9028 + 1);
        }
        t = func_003825F8(0x332299DE, 0x8066CCFF, 0x28, 0, 0, 1);
        s5 = 1;
        func_L01_005170B8(D_L01_001D9028 + 0x11000C, t);
        func_L01_00516FD8(0x110023, func_00381FF0(D_L01_001D90C0[D_L01_001D9028]));
        k = buf[D_L01_001D9028] - 0x1E;
        if (buf[D_L01_001D9028] != 0x1F
            && ((u8)(buf[D_L01_001D9028 - 1] - 0x1E) >= 8 || (((D_001426E0[0x54] >> (buf[D_L01_001D9028 - 1] - 0x1E)) ^ 1) & 1))) {
            s5 = 0;
            func_L01_00516FD8(0x11002C, func_00381FF0(0x1873));
            func_L01_00517538(0x11002C, 0.8f, 1.0f);
            func_L01_00516D60(0x11002C, 1);
            func_L01_00516D60(0x110024, 0);
            func_L01_00516D60(0x110025, 0);
            func_L01_00516D60(0x110026, 0);
            func_L01_00516D60(0x110027, 0);
            func_L01_00516D60(0x110028, 0);
            func_L01_00516D60(0x110029, 0);
            func_L01_00516D60(0x11002A, 0);
            func_L01_00516D60(0x11002B, 0);
        } else {
            ok = (u32)k < 8;
            if (ok && ((D_001426E0[0x54] >> k) & 1)) {
                if (D_001BBB18[buf[D_L01_001D9028] - 5] != 0) {
                    func_L01_00516FD8(0x11002B, func_00381FF0(0x14F0));
                } else {
                    func_L01_00516FD8(0x11002B, func_00381FF0(0x14F1));
                }
                if (ok && ((D_001426E0[0x51] >> k) & 1)) {
                    func_L01_00516FD8(0x110029, func_00381FF0(0x14F0));
                } else {
                    func_L01_00516FD8(0x110029, func_00381FF0(0x14F1));
                }
                func_0011B2E8(D_L01_001E0B30, D_L01_001D9168, D_001426E0[0x4A + k]);
                func_L01_00516FD8(0x110027, D_L01_001E0B30);
                t = D_001D55A0[k];
                if (t / 50 % 60 < 10) {
                    func_0011B2E8(D_L01_001E0B40, D_L01_001D9170, t / 3000 % 60, t / 50 % 60, t / 5 % 10);
                } else {
                    func_0011B2E8(D_L01_001E0B40, D_L01_001D9180, t / 3000 % 60, t / 50 % 60, t / 5 % 10);
                }
                func_L01_00516FD8(0x110025, D_L01_001E0B40);
                func_L01_00516D60(0x11002C, 0);
                func_L01_00516D60(0x110024, 1);
                func_L01_00516D60(0x110025, 1);
                func_L01_00516D60(0x110026, 1);
                func_L01_00516D60(0x110027, 1);
                func_L01_00516D60(0x110028, 1);
                func_L01_00516D60(0x110029, 1);
                func_L01_00516D60(0x11002A, 1);
                func_L01_00516D60(0x11002B, 1);
            } else {
                func_L01_00516FD8(0x11002C, func_00381FF0(0x14F7));
                func_L01_00517538(0x11002C, 1.0f, 1.0f);
                func_L01_00516D60(0x11002C, 1);
                func_L01_00516D60(0x110024, 0);
                func_L01_00516D60(0x110025, 0);
                func_L01_00516D60(0x110026, 0);
                func_L01_00516D60(0x110027, 0);
                func_L01_00516D60(0x110028, 0);
                func_L01_00516D60(0x110029, 0);
                func_L01_00516D60(0x11002A, 0);
                func_L01_00516D60(0x11002B, 0);
            }
        }
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x80) {
            D_L01_001D90D4 = 1;
            func_003A5348(4, 0, 0);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090(a0);
        }
        b2 = *(s32 *)(D_001D52FC + 0x1C4);
        if (b2 & 0x10) {
            func_003A5348(4, 0, 0);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090(a0);
            return;
        }
        if (s5 != 0 && (b2 & 0x40)) {
            func_003A5348(4, 0, 0);
            if (func_L01_0041A4F0() != 0) {
                D_L01_001D9140 = 1;
                return;
            }
            ops->f0(D_L01_001D9028);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090(a0);
            return;
        }
        func_L01_00516D60(0x11002D, 1);
        break;
    }
}

