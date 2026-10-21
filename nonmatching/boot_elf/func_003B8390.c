/* US draft of func_003B8390 (rac3-uya-decomp func_003B82B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003B8390 */
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3B2AF8;
extern s32 D_001D4CE8_003B8390;
extern u8 D_001D9FA0_003B8390;
extern u8 D_001D5BDC_003B8390;
extern u8 D_001D5BDD;
extern u16 D_001D4BC4;
extern char D_001D8B48[];
extern char D_001D8B50[];
extern char D_00280AF0[];
extern char *func_00382468(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_003AF7C0(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern void func_11B2E8();
void func_003B8390(void) {
    T_3B2AF8 s10;
    T_3B2AF8 s30;
    char *a = 0;
    char *b = 0;
    char *c;
    s32 draw = 1;
    func_0038E530(0);
    c = D_001D8B48;
    switch (D_001D4CE8_003B8390) {
    case 8:
        a = (char *)func_003823D0(0x8E3);
        b = (char *)func_003823D0(0x8DF);
        c = (char *)func_003823D0(0x1A3);
        break;
    case 14:
        if (D_001D9FA0_003B8390 == 0) break;
        c = func_00382468(0x195);
        a = (char *)func_003823D0(0x197);
        break;
    case 15:
        a = (char *)func_003823D0(0x8E3);
        b = (char *)func_003823D0(0x8DF);
        c = func_00382468(0x19F);
        break;
    case 33:
        a = (char *)func_003823D0(0x8E3);
        b = (char *)func_003823D0(0x8DF);
        c = func_00382468(0x1A8);
        break;
    case 12: case 13: case 31: case 32:
        c = func_00382468(0x1AF);
        break;
    case 9: case 10:
        c = func_00382468(0x1AD);
        break;
    case 16: case 17:
        c = func_00382468(0x1AE);
        break;
    case 25: case 29:
        c = func_00382468(0x1AB);
        break;
    case 23: case 30:
        c = func_00382468(0x1AC);
        break;
    case 19:
        c = func_00382468(0x1B0);
        a = (char *)func_003823D0(0x8DE);
        break;
    case 20:
        c = func_00382468(0x1B2);
        a = (char *)func_003823D0(0x8DE);
        break;
    case 3:
        c = func_00382468(0x194);
        break;
    case 21:
        if (D_001D9FA0_003B8390 != 0) {
            c = func_00382468(0x195);
            a = (char *)func_003823D0(0x197);
        } else if (D_001D5BDC_003B8390 != 0) {
            char *buf, *fmt;
            s32 x;
            buf = D_00280AF0;
            fmt = D_001D8B50;
            x = func_003823D0(0x198);
            func_11B2E8(buf, fmt, x, 1, 1, func_003823D0(0x19A));
            c = buf;
            a = (char *)func_003823D0(0x8E2);
            b = (char *)func_003823D0(0x8DF);
        } else {
            char *buf, *fmt;
            s32 x;
            buf = D_00280AF0;
            fmt = D_001D8B50;
            x = func_003823D0(0x198);
            func_11B2E8(buf, fmt, x, 1, 1, func_00382468(0x19A));
            c = buf;
            a = (char *)func_003823D0(0x8E2);
        }
        break;
    case 24:
        if (D_001D5BDC_003B8390) c = func_00382468(0x1B2);
        else c = func_00382468(0x1B3);
        a = (char *)func_003823D0(0x8DE);
        break;
    case 22:
        c = func_00382468(0x1B1);
        a = (char *)func_003823D0(0x8DE);
        break;
    case 27: {
        char *buf, *fmt, *x;
        a = (char *)func_003823D0(0x8E2);
        b = (char *)func_003823D0(0x8DF);
        buf = D_00280AF0;
        fmt = D_001D8B50;
        x = func_00382468(0x1A1);
        func_11B2E8(buf, fmt, x, 1, 1, func_00382468(0x19A));
        c = buf;
        break;
    }
    case 26:
        a = (char *)func_003823D0(0x8E2);
        b = (char *)func_003823D0(0x8DF);
        c = func_00382468(0x1A5);
        break;
    case 4: case 5: case 6:
        if (D_001D5BDC_003B8390 != 0 && D_001D9FA0_003B8390 == 0) {
            a = (char *)func_003823D0(0x8E2);
            b = (char *)func_003823D0(0x8DF);
            c = func_00382468(0x19B);
        } else if (D_001D5BDD != 0) {
            a = (char *)func_003823D0(0x8E3);
            c = func_00382468(0x19B);
        } else if (D_001D9FA0_003B8390 == 0) {
            c = func_00382468(0x19D);
            a = (char *)func_003823D0(0x197);
        } else {
    case 7:
            c = func_00382468(0x195);
            a = (char *)func_003823D0(0x197);
        }
        break;
    case 11: case 18: case 28:
    default:
        draw = 0;
        break;
    }
    if (draw) {
        func_0011A264(&s30, 0, 0x1C);
        s30.f2 = D_001D4BC4;
        s30.f4 = 0x60;
        s30.f6 = 0x1A0;
        s30.f8 = 0x100;
        s30.fA = 0x68;
        s30.f10 = 0x10;
        s30.f12 = 1;
        s10 = s30;
        func_0038E530(1);
        func_003AF7C0(&s10, 0x8066CCFF, c, 1, 1, -1, 0, a, b, 0);
    }
}
/* localdecomp:end func_003B8390 */
