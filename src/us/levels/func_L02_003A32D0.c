#include "common.h"

/* NTSC-U counterpart of func_L02_003A51F0 (src/levels/shared/L02_003A51F0.c): 0.04 -> 0.0333333; 71 -> 85; 84 -> 101; 0.06 -> 0.05; 108 -> 130 */
/* localdecomp:start func_L02_003A32D0 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
} P_003A51F0;

typedef struct {
    u8 p0[0x30];
    u8 v30[0x8];
    f32 f38;
    u8 p3C[0x34];
    u8 v70[0x8];
    f32 f78;
} R_003A51F0;

extern void func_L02_003C3A40(s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_003EAB30(s32);
extern void func_L01_0050DA68(void *, s32, f32);
extern void func_0038E5B8(s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_004282C0(s32, s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_0049FDB0(u8 *, u8 *);
extern void func_L01_0044ECE0(s32, s32, s32);
extern s32 func_L01_003EAB60(s32);
extern void func_L02_004CF3B8(s32, s32);

extern s32 D_001D545C;
extern u8 *D_001D52FC;
extern u8 D_001A4C60[];
extern u8 D_001426E0[];
extern s32 D_L02_002CF1F0[];
extern u8 *D_L02_001DEB00;
extern f32 D_L02_001DE350;

void func_L02_003A32D0(u8 *a0) {
    P_003A51F0 *p = *(P_003A51F0 **)(a0 + 0x68);
    s32 mode;

    if (p->w10 != -1 && a0[0xBC] == 0) {
        a0[0xBC] = 1;
        func_L02_003C3A40(p->w10);
    }
    if (a0[0x20] == 0) {
        a0[0x30] = 0xFF;
        if (D_001D545C == 4) {
            if (func_0037E0F0(D_001A4C60, p->w0, 0)) {
                func_L01_0044F2E8(0, 9, 0xA48, 1, 0, 0, 0);
                if (*(s32 *)(D_001D52FC + 0x1A4) == 0x10 && D_L02_002CF1F0[0] == 9) {
                    func_L01_00441FB8(a0, 1, -1);
                }
            }
        } else if (D_001D545C == 8 || D_001D545C == 0x1B || D_001D545C == 0x1C) {
            if (D_001D545C == 8 && p->w8 == 0x1B && D_001426E0[0x17] == 1) {
            } else if (func_0037E0F0(D_001A4C60, p->w0, 0)) {
                switch (p->wC) {
                case 1:
                    break;
                case 0:
                    func_L01_0044F2E8(0, 9, 0xC53, 1, 0, 0, 0);
                    break;
                case 2:
                    func_L01_0044F2E8(0, 9, 0x850, 1, 0, 0, 0);
                    break;
                case 3:
                    func_L01_0044F2E8(0, 9, 0xC54, 1, 0, 0, 0);
                    break;
                default:
                    func_L01_0044F2E8(0, 9, 0x850, 1, 0, 0, 0);
                    break;
                }
                mode = D_001D545C;
                if ((mode == 0x1B && p->wC == 1)
                    || (*(s32 *)(D_001D52FC + 0x1A4) == 0x10 && D_L02_002CF1F0[0] == 9)) {
                    if (p->w4 == -1) {
                        if (mode == 0x1C && p->w8 == 8) {
                            D_001426E0[0x17] = 1;
                        }
                        if (p->w8 == 0x1B) {
                            D_001426E0[0x17] = 1;
                        }
                        if (p->w10 != -1) {
                            func_L01_00441FB8(a0, 3, -1);
                            func_L01_003EAB30(p->w10);
                        } else if (p->w14 != -1) {
                            R_003A51F0 *r;
                            func_L01_00441FB8(a0, 4, -1);
                            r = (R_003A51F0 *)(D_L02_001DEB00 + (p->w14 << 7));
                            func_L01_0050DA68(r->v30, 0, r->f78);
                        } else {
                            func_0038E5B8(p->w8, 1);
                        }
                    } else {
                        func_L01_00441FB8(a0, 1, -1);
                    }
                }
            }
        } else {
            if (func_0037E0F0(D_001A4C60, p->w0, 0)) {
                func_L01_00441FB8(a0, 1, -1);
            }
        }
    }
    if (a0[0x20] == 1) {
        f32 one = 1.0f;
        func_003BEBF8(&D_L02_001DE350, one, 0.0333333351f);
        if (D_L02_001DE350 == one) {
            D_L02_001DE350 = 1.5f;
        }
        if (one <= D_L02_001DE350) {
            R_003A51F0 *r;
            func_L01_004282C0(p->w8, 0);
            r = (R_003A51F0 *)(D_L02_001DEB00 + (p->w4 << 7));
            func_L01_004F12C0(r->v30, r->v70, 0, 1);
            func_L01_0049FDB0(r->v30, r->v70);
            if (D_001D545C == 2 && r->f38 < 50.0f) {
                func_L01_0044ECE0(0xC7A, -1, 0);
            }
            func_L01_00441FB8(a0, 2, -1);
        }
    }
    if (a0[0x20] == 2) {
        f32 zero = 0.0f;
        func_003BEBF8(&D_L02_001DE350, zero, 0.0333333351f);
        if (D_L02_001DE350 <= zero) {
            D_L02_001DE350 = zero;
            func_L01_00441FB8(a0, 0, -1);
        }
    }
    if (a0[0x20] == 3) {
        if (func_L01_003EAB60(p->w10)) {
            func_0038E5B8(p->w8, 1);
        }
    }
    if (a0[0x20] == 4) {
        *(u16 *)(a0 + 0x96) += 1;
        if (*(u16 *)(a0 + 0x96) == 0x55) {
            func_L02_004CF3B8(0x69, 1);
        }
        if (*(u16 *)(a0 + 0x96) >= 0x65) {
            func_003BEBF8(&D_L02_001DE350, 1.0f, 0.0500000045f);
        }
        if (*(u16 *)(a0 + 0x96) == 0x82) {
            func_0038E5B8(p->w8, 1);
        }
    }
}
/* localdecomp:end func_L02_003A32D0 */
