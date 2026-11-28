#include "common.h"

/* func_L39_0059B428, first byte draft (wave 13 r27; fresh entry, from the functional C and retail).
 * The state switch (jump table at D_L39_00479E50: 1, 3, 4-6, 2, 7 in that order), the global struct
 * D_L39_004989E0 used directly (retail keeps only its %hi in s4), D_L39_00241120 read once through its
 * gp slot D_001D5A10_sda and once through lui, the 5-type compare tree as a switch, x/8 divisions, the
 * sign-extended 0x80808080 colour, case 1 re-reading f1C/f18 after storing 8. 497 diff (first
 * placement). Still differs: gcc cross-jumps case 1's whole 0038C3B0/00436020 tail into case 3 (retail
 * keeps both and joins them to case 7's tail at the f15 conversion, the li 0x332299DE ori scheduled
 * before the last conversions); retail keeps a dead 'li s6, 0x3D' in case 4-6 (a layout variable whose use
 * became the immediate 0x3D), so it runs out of s-registers and spills ent0 to 0x30(sp) and uses fp: here
 * the constant is propagated early, one register is free and the whole 4-6 block's allocation shifts
 * (rect at 0x20 instead of 0x10); store orders of f18/f1C. */

/* localdecomp:start func_L39_0059B428 */
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
    s32 f0;
    u8 pad4[0xA];
    s16 type;
} Ent_0059B428;

typedef struct {
    u8 pad0[0x12];
    u16 f22;
    u8 pad24[4];
    s16 f28;
    s16 f2A;
    u8 pad2C[4];
} Rect_0059B428;

extern Cur_0059B428 D_L39_004989E0;
extern u8 D_001A5810[];
__asm__(".extern D_001D5A10_sda, 4");
extern s32 *D_001D5A10_sda;
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern Ent_0059B428 *D_L39_0024BCC0;
__asm__(".extern D_L39_0024BCC0, 16");
extern s32 D_L39_00242850;
__asm__(".extern D_L39_00242850, 16");
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
extern void func_L39_00593468(void *, u64, s32, s32, u64, f32, f32);

void func_L39_0059B428(void) {
    Rect_0059B428 rect;
    s32 ent0;
    s32 n;
    s32 m;
    s32 flag;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 y2;
    s32 h0;
    s32 h1;
    s32 id;
    s32 w;
    s32 h;
    s32 alpha;

    D_L39_004989E0.f44 -= 1;
    if (D_L39_004989E0.f44 < 0) {
        D_L39_004989E0.f44 = 0;
    }
    if (D_L39_004989E0.f44 == 0) {
        D_L39_004989E0.f40 = 0;
    }
    if (D_L39_004989E0.state == 0) {
        return;
    }
    if (D_L39_004989E0.f30 == 0) {
        return;
    }
    if (D_001A5810[5] == 0) {
        return;
    }
    if (*D_001D5A10_sda >= 2) {
        return;
    }
    switch (D_L39_004989E0.state) {
    case 1:
        if (D_001A5810[5] == 0) {
            func_L01_003DF8B8();
            return;
        }
        D_L39_004989E0.f1C = 8;
        D_L39_004989E0.f18 = 8;
        func_0038C3B0(D_L39_004989E0.f14 - D_L39_004989E0.f1C + D_L39_004989E0.f40,
                      D_L39_004989E0.f14 + D_L39_004989E0.f1C + D_L39_004989E0.f40,
                      D_L39_004989E0.f10 - D_L39_004989E0.f18, D_L39_004989E0.f10 + D_L39_004989E0.f18,
                      0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE,
                          (f32)(D_L39_004989E0.f14 - D_L39_004989E0.f1C + D_L39_004989E0.f40),
                          (f32)(D_L39_004989E0.f14 + D_L39_004989E0.f1C + D_L39_004989E0.f40),
                          (f32)(D_L39_004989E0.f10 - D_L39_004989E0.f18),
                          (f32)(D_L39_004989E0.f10 + D_L39_004989E0.f18));
        return;
    case 3:
        if (D_001A5810[5] == 0) {
            func_L01_003DF8B8();
            return;
        }
        n = D_L39_004989E0.f4;
        if (n >= 9) {
            n = 8;
        }
        if (n < 0) {
            n = 0;
        }
        D_L39_004989E0.f18 = (D_L39_004989E0.f8 - 0x20) * n / 8 + 0x20;
        D_L39_004989E0.f1C = (D_L39_004989E0.fC - 0x20) * n / 8 + 0x20;
        func_0038C3B0(D_L39_004989E0.f14 - D_L39_004989E0.f1C + D_L39_004989E0.f40,
                      D_L39_004989E0.f14 + D_L39_004989E0.f1C + D_L39_004989E0.f40,
                      D_L39_004989E0.f10 - D_L39_004989E0.f18, D_L39_004989E0.f10 + D_L39_004989E0.f18,
                      0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE,
                          (f32)(D_L39_004989E0.f14 - D_L39_004989E0.f1C + D_L39_004989E0.f40),
                          (f32)(D_L39_004989E0.f14 + D_L39_004989E0.f1C + D_L39_004989E0.f40),
                          (f32)(D_L39_004989E0.f10 - D_L39_004989E0.f18),
                          (f32)(D_L39_004989E0.f10 + D_L39_004989E0.f18));
        return;
    case 4:
    case 5:
    case 6:
        if (D_001A5810[5] == 0) {
            func_L01_003DF8B8();
            return;
        }
        m = 0;
        flag = 0;
        x0 = 0xF0;
        x1 = 0x1E0;
        y0 = 0x2C;
        h1 = 0x10;
        h0 = 0x3D;
        switch (D_L39_0024BCC0[D_L39_004989E0.f20].type) {
        case 0x150E:
        case 0x1DC:
        case 0xB0E:
        case 0x166A:
        case 0x1736:
            flag = 1;
            break;
        }
        if (flag != 0) {
            m = 10;
            if (D_L39_004989E0.fC + 10 < 0x22) {
                m = 2 - (D_L39_004989E0.fC - 0x20);
            }
            D_L39_004989E0.f8 = 0xD4;
        }
        D_L39_004989E0.f18 = D_L39_004989E0.f8;
        D_L39_004989E0.f1C = D_L39_004989E0.fC;
        func_0038C3B0(D_L39_004989E0.f14 - D_L39_004989E0.fC + D_L39_004989E0.f40 - m,
                      D_L39_004989E0.f14 + D_L39_004989E0.fC + D_L39_004989E0.f40 + m,
                      D_L39_004989E0.f10 - D_L39_004989E0.f8, D_L39_004989E0.f10 + D_L39_004989E0.f8,
                      0x60, 0x600E5092);
        func_L01_00436020(0x33, 0x332299DE,
                          (f32)(D_L39_004989E0.f14 - D_L39_004989E0.f1C + D_L39_004989E0.f40 - m),
                          (f32)(D_L39_004989E0.f14 + D_L39_004989E0.f1C + D_L39_004989E0.f40 + m),
                          (f32)(D_L39_004989E0.f10 - D_L39_004989E0.f18),
                          (f32)(D_L39_004989E0.f10 + D_L39_004989E0.f18));
        ent0 = D_L39_0024BCC0[D_L39_004989E0.f20].f0;
        y1 = D_001D7364_sda + 0x1D4;
        y2 = D_001D7360_sda + 0x100;
        if (*D_L39_00241120 == 2) {
            x0 = D_001D7368_sda;
            x1 = D_001D736C_sda;
            y0 = D_001D7370_sda;
            y1 = D_001D7374_sda;
            y2 = D_001D7378_sda;
            h1 = D_001D7380_sda;
        } else if (*D_L39_00241120 == 4) {
            x0 = D_001D7384_sda;
            x1 = D_001D7388_sda;
            y0 = D_001D738C_sda;
            y1 = D_001D7390_sda;
            y2 = D_001D7394_sda;
            h1 = D_001D739C_sda;
        }
        if (D_L39_0024BCC0[D_L39_004989E0.f20].type > 0) {
            func_003910C0(&rect, x0 + D_L39_004989E0.f40, x1 + D_L39_004989E0.f40, y0 + 0x44, y1, y0 + 0x44,
                          D_L39_004989E0.f14 + D_L39_004989E0.f40, h1, 2);
        } else {
            func_003910C0(&rect, x0 + D_L39_004989E0.f40, x1 + D_L39_004989E0.f40, y0, y1, y2,
                          D_L39_004989E0.f14 + D_L39_004989E0.f40, h1, 3);
        }
        rect.f22 |= 0x20;
        rect.f2A = 2;
        rect.f28 = 2;
        if (D_L39_0024BCC0[D_L39_004989E0.f20].type > 0) {
            switch (D_L39_0024BCC0[D_L39_004989E0.f20].type) {
            case 0x150E:
                id = 0x5D;
                break;
            case 0x1DC:
                id = 0x5C;
                break;
            case 0xB0E:
                id = 0x61;
                break;
            case 0x166A:
                id = 0x62;
                break;
            case 0x1736:
                id = 0x5E;
                break;
            default:
                id = 0;
                break;
            }
            if (id != 0) {
                func_0038B4D0(y0 + 6, D_L39_004989E0.f14 - 0x1E + D_L39_004989E0.f40, 0x38, h0, 0, 0, 0x40, 0x40,
                              (s32)0x80808080, func_L39_00589890(id));
            } else {
                func_003910C0(&rect, x0 + D_L39_004989E0.f40, x1 + D_L39_004989E0.f40, y0, y1, y2,
                              D_L39_004989E0.f14 + D_L39_004989E0.f40, h1, 3);
                rect.f22 |= 0x20;
                rect.f2A = 2;
                rect.f28 = 2;
            }
        }
        D_L39_00242850 = D_L39_004989E0.state == 4 ? 1 : 2;
        func_0038E150(1);
        func_L39_00593468(&rect, 0x8066CCFF, ent0, -1, 0x80000000, 1.0f, 1.0f);
        return;
    case 2:
        func_L01_003DF8B8();
        return;
    case 7:
        if (D_001A5810[5] == 0) {
            func_L01_003DF8B8();
            return;
        }
        n = D_L39_004989E0.f4;
        if (n >= 9) {
            n = 8;
        }
        if (n < 0) {
            n = 0;
        }
        alpha = (8 - n) * 0xC;
        w = D_L39_004989E0.f1C - (D_L39_004989E0.f1C - 8) * n / 8;
        h = D_L39_004989E0.f18 - (D_L39_004989E0.f18 - 8) * n / 8;
        func_0038C3B0(D_L39_004989E0.f14 - w + D_L39_004989E0.f40, D_L39_004989E0.f14 + w + D_L39_004989E0.f40,
                      D_L39_004989E0.f10 - h, D_L39_004989E0.f10 + h, alpha, 0x600E5092);
        func_L01_00436020(alpha, 0x332299DE,
                          (f32)(D_L39_004989E0.f14 - w + D_L39_004989E0.f40),
                          (f32)(D_L39_004989E0.f14 + w + D_L39_004989E0.f40),
                          (f32)(D_L39_004989E0.f10 - h), (f32)(D_L39_004989E0.f10 + h));
        return;
    }
}
/* localdecomp:end func_L39_0059B428 */
