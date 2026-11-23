#include "common.h"

/* NTSC-U dialog update with 60 Hz timing. PAL counterpart func_003E2258. */
/* localdecomp:start func_U_003DCD08 */
#include "vu0.h"

extern void func_U_003DE8B8(void);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E2258;
typedef struct {
    V4_003E2258 v0;
    V4_003E2258 v10;
    V4_003E2258 v20;
    V4_003E2258 v30;
    s32 f40;
    s32 f44;
    s32 f48, f4C, f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    f32 f6C;
    f32 f70;
    s32 f74, f78;
    s16 f7C, f7E;
    s32 f80;
    s16 f84, f86;
    s32 f88, f8C, f90, f94;
} S_003E2258;
typedef struct {
    u8 pad0[0x100];
    s32 f100;
    u8 pad104[0x148 - 0x104];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    s32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 f1C0;
    s32 f1C4;
} P_003E2258;
typedef struct { u8 pad[0x64]; void (*f64)(void *); u8 pad68[0xAA - 0x68]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_003E2258;
typedef struct { u8 pad[8]; s32 f8; s32 fC; s32 f10; } M_003E2258;

/* globals the retail reaches with lui (or $gp in a delay slot) */
__asm__(".extern D_001D52FC_003E2258, 16");
__asm__(".extern D_001D4CE8_003E2258, 16");
__asm__(".extern D_001D4CEC_003E2258, 16");
__asm__(".extern D_001D545C_003E2258, 16");
__asm__(".extern D_001D5520_003E2258, 16");
__asm__(".extern D_U_001D5B90_003E2258, 16");
__asm__(".extern D_U_001D5BDC_003E2258, 16");
__asm__(".extern D_U_001D5BDD_003E2258, 16");
__asm__(".extern D_U_001DA020_003E2258, 16");
__asm__(".extern D_U_001DA268_003E2258, 16");
__asm__(".extern D_U_001D9DD0_003E2258, 16");
__asm__(".extern D_U_001D9DD4_003E2258, 16");
__asm__(".extern D_U_001D9E90_003E2258, 16");
__asm__(".extern D_U_001DA520_003E2258, 16");

extern P_003E2258 *D_001D52FC_003E2258;
extern s32 D_001D4CE8_003E2258;
extern s32 D_001D4CEC_003E2258;
extern s32 D_001D545C_003E2258;
extern s32 D_001D5520_003E2258;
extern s32 D_U_001D5B90_003E2258;
extern u8 D_U_001D5BDC_003E2258;
extern u8 D_U_001D5BDD_003E2258;
extern u8 D_U_001DA020_003E2258;
extern u8 D_U_001DA268_003E2258;
extern s32 D_U_001D9DD0_003E2258;
extern s32 D_U_001D9DD4_003E2258;
extern f32 D_U_001D9E90_003E2258;
extern E_003E2258 *D_U_001DA520_003E2258;

/* $gp in retail */
__asm__(".extern D_U_001D94D0, 4");
__asm__(".extern D_U_001D94D4, 4");
__asm__(".extern D_U_001D94D8, 4");
__asm__(".extern D_U_001D94F0, 4");
__asm__(".extern D_U_001D9504, 4");
__asm__(".extern D_U_001D9508, 4");
__asm__(".extern D_U_001DA51C_003E2258, 4");
extern s32 D_U_001D94D0;
extern s32 D_U_001D94D4;
extern s32 D_U_001D94D8;
extern s32 D_U_001D94F0;
extern s32 D_U_001D9504;
extern f32 D_U_001D9508;
extern E_003E2258 *D_U_001DA51C_003E2258;

extern S_003E2258 D_U_00302D80;
extern M_003E2258 D_00142430_003E2258;
extern u16 D_001A7E18_003E2258[];
extern s32 D_001425AC[];
extern u8 D_001A71C4[];
typedef struct { V4_003E2258 position; V4_003E2258 angles; f32 matrix[16]; } Cam_003E2258;
extern Cam_003E2258 D_U_00222480_003E2258;


extern s32 func_U_0039EE68(void);
extern s32 func_U_0039BEC0(s32, s32, s32, s32, s32);
extern void func_U_0039BEA0(s32);
extern void func_U_0039BF98(s32, s32);
extern void func_U_0039FF28(s32, s32, s32);
extern void func_U_003B3558(s32);
extern void func_U_003A3A00(void);
extern void func_U_00385B60(s32);
extern s32 func_U_003B6198(void);
extern void func_U_003970A0(void);
extern void func_U_003971E8(void);
extern void func_U_00397200(void);
extern void func_U_00397380(void);
extern f32 func_U_00388770(void *);
extern void func_U_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern void func_U_00388830(void *, void *, f32);
extern void func_U_003888C8(void *, void *, void *);
extern void func_U_003BF640(void *, f32);
extern void func_U_003886E8(void *, void *, f32);
extern void func_U_003DE3A8(f32 *);
extern void func_U_003DE260(f32 *, s32);
extern void func_U_003DE430(f32 *);
extern void func_U_003DBE20(void);
extern void func_U_00388E78(void *, void *);
extern void func_U_003BF360(void *, void *);
extern void func_U_003886C0(void *, void *, void *, f32);
extern void func_U_003BEA80(void *, void *);
extern void func_U_00388F90(void *, void *, void *, f32);
extern void func_U_003890D8(void *, void *);
extern s32 func_U_0037DD00(void);
extern void func_U_00393370(void);
extern s32 func_U_0038EB10(s32, s32, void *, void *, void *, s32, s32);
extern void func_U_003AA290(void);
extern void func_U_00393428(void);
extern void func_U_00393420(void);
extern void func_U_00380AB0(void);
extern void func_U_003DE560(void);
extern void func_U_0038F3A0(void);
extern void func_U_0038F3F8(void);
extern void func_U_0038FDC0(void);
extern void func_U_003906E8(void);
extern void func_U_00390730(void);
extern void func_U_00390C18(void);
extern void func_U_003DF7C0(s32);
extern void func_U_003DFF90(s32);
extern void func_U_003DE8D0(void);

void func_U_003DCD08(void) {
    f32 delta[4] __attribute__((aligned(16)));
    f32 target[4] __attribute__((aligned(16)));
    f32 transform[16];
    f32 distance;
    S_003E2258 *dlg, *dlg3;

    func_U_0039EE68();
    D_U_001D9DD0_003E2258 = D_U_00302D80.f94;
    if (D_U_00302D80.f44)
        --D_U_00302D80.f44;
    if (D_U_00302D80.f7C)
        --D_U_00302D80.f7C;
    switch (D_U_00302D80.f40) {
    case 2:
        ++D_U_00302D80.f5C;
        if (D_U_00302D80.f5C > 0x5A && D_U_00302D80.f60)
            --D_U_00302D80.f60;
        if (D_001D4CE8_003E2258 == 3) {
            func_U_0039BEC0(4, 2, 1, 0, 0);
            break;
        }
        if (D_U_00302D80.f5C >= 0x79 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
            if (!D_001A7E18_003E2258[0x120 / 2])
                D_001A7E18_003E2258[0x120 / 2] = 1;
            func_U_0039FF28(4, 0, 0);
            func_U_0039BF98(0, 0);
            break;
        }
        break;
    case 5:
        ++D_U_00302D80.f5C;
        if (D_U_00302D80.f5C > 0x1E && D_U_00302D80.f60)
            --D_U_00302D80.f60;
        if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
            D_001D4CEC_003E2258 &= ~0x40;
            D_001425AC[0] = 0;
            func_U_003B3558(-1);
            func_U_003A3A00();
            break;
        }
        break;
    case 4:
        ++D_U_00302D80.f5C;
        if (D_U_00302D80.f5C > 0x1E && D_U_00302D80.f60)
            --D_U_00302D80.f60;
        if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
            D_001425AC[0] = 0;
            func_U_003B3558(-1);
            func_U_003A3A00();
            break;
        }
        break;
    case 3:
        switch (D_U_00302D80.f58) {
        case 0:
            if (!D_U_00302D80.f44)
                D_U_00302D80.f58 = 1;
            break;
        case 1:
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                func_U_0039BF98(0, 0);
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x40) {
                func_U_00385B60(4);
                D_U_001DA268_003E2258 = 0;
                D_U_00302D80.f58 = 2;
                D_U_00302D80.f5C = 0x258;
            }
            break;
        case 2:
            if (!D_U_00302D80.f5C || --D_U_00302D80.f5C == 0) {
                D_U_001DA268_003E2258 = 1;
                D_U_00302D80.f58 = 3;
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                func_U_00385B60(4);
                D_U_001DA268_003E2258 = 1;
                func_U_0039BF98(0, 0);
                break;
            } else if (D_001D52FC_003E2258->f1A4 & 0x40) {
                D_U_001DA268_003E2258 = 0;
                func_U_0039BF98(0, 0);
                break;
            }
            break;
        case 3:
            if (!(D_001D52FC_003E2258->f1A4 & 0x40))
                break;
        default:
            func_U_0039BF98(0, 0);
            break;
        }
        break;
    case 1:
        if (D_U_001D5B90_003E2258 != -2)
            break;
        ++D_U_00302D80.f5C;
        if (D_U_00302D80.f5C > 0x1E && D_U_00302D80.f60)
            --D_U_00302D80.f60;
        switch (D_001D4CE8_003E2258) {
        case 3:
            if (D_U_00302D80.f60 || !(D_001D52FC_003E2258->f1A4 & 0x40))
                break;
            D_001D4CEC_003E2258 &= ~1;
            D_U_00302D80.f84 = 2;
            if (D_U_001D5BDD_003E2258) {
                func_U_0039BEA0(5);
                func_U_0039BEC0(3, 2, 7, 0, 0);
                break;
            }
            func_U_0039BF98(0, 0);
            break;
        case 8:
            if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x20)) {
                D_001D4CEC_003E2258 |= 8;
                D_U_00302D80.f84 = 2;
                break;
            }
            if (D_U_00302D80.f44 || !(D_001D52FC_003E2258->f1A4 & 0x10))
                break;
            if (D_U_001D5BDD_003E2258) {
                D_U_00302D80.f84 = 2;
                func_U_003A3A00();
                break;
            }
            D_001D4CEC_003E2258 |= 0x20;
            if (!func_U_003B6198())
                D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            D_U_00302D80.f84 = 1;
            if (!D_U_001D5BDC_003E2258) {
                func_U_0039BF98(0, 0);
                break;
            }
            break;
        case 15:
            if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x20)) {
                func_U_003970A0();
                D_U_00302D80.f84 = 2;
                break;
            }
            if (D_U_00302D80.f44 || !(D_001D52FC_003E2258->f1A4 & 0x10))
                break;
            if (D_U_001D5BDD_003E2258) {
                D_U_00302D80.f84 = 2;
                func_U_003A3A00();
                break;
            }
            D_001D4CEC_003E2258 |= 0x20;
            D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            D_U_00302D80.f84 = 1;
            if (!D_U_001D5BDC_003E2258) {
                func_U_0039BF98(0, 0);
                break;
            }
            break;
        case 33:
            if (D_001D52FC_003E2258->f1A4 & 0x20) {
                func_U_003970A0();
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                func_U_003971E8();
                func_U_00397200();
            }
            break;
        case 22:
            if (D_U_00302D80.f60 || !(D_001D52FC_003E2258->f1A4 & 0x40))
                break;
            D_001D4CEC_003E2258 &= ~0x40;
            D_001D4CEC_003E2258 &= ~0x400;
            D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            D_U_00302D80.f84 = 2;
            if (D_U_001D5BDC_003E2258) {
                func_U_0039BF98(0, 0);
            } else {
                func_U_0039BF98(0, 0);
            }
            break;
        case 19:
        case 20:
        case 24:
            if (D_U_00302D80.f68 > 0) {
                if (--D_U_00302D80.f68 <= 0) {
                    if (D_00142430_003E2258.f8 == 2) {
                        if (!D_00142430_003E2258.f10) {
                            D_001D4CE8_003E2258 = 0xB;
                        } else if (D_00142430_003E2258.f10 == -1) {
                            D_001D4CE8_003E2258 = 0xB;
                            D_00142430_003E2258.f10 = 0;
                        } else if (D_00142430_003E2258.f10 == -2) {
                            D_001D4CE8_003E2258 = 7;
                        } else {
                            D_001D4CE8_003E2258 = 0xE;
                        }
                        func_U_0039BF98(0, 0);
                    } else {
                        D_U_00302D80.f84 = 2;
                        func_U_003A3A00();
                    }
                    break;
                }
            } else {
                if (D_U_00302D80.f60 || !(D_001D52FC_003E2258->f1A4 & 0x40))
                    break;
                if (D_U_001D5BDD_003E2258) {
                    D_U_00302D80.f68 = 0xF;
                } else {
                    D_001D4CEC_003E2258 &= ~0x40;
                    D_001D4CEC_003E2258 &= ~0x400;
                    D_001D4CEC_003E2258 &= ~2;
                    D_001D4CEC_003E2258 &= ~4;
                    D_U_00302D80.f84 = 2;
                    func_U_0039BF98(0, 0);
                }
            }
            break;
        case 1:
        case 18:
            if (!(D_001D4CEC_003E2258 & 6))
                func_U_0039BF98(0, 0);
            break;
        case 14:
            if (!D_U_001DA020_003E2258)
                break;
        case 4:
        case 5:
        case 7:
            if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x10)) {
                D_U_00302D80.f84 = 1;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                func_U_0039BF98(0, 0);
                break;
            }
            break;
        case 21:
            if (D_U_001D5BDC_003E2258 && !D_U_001DA020_003E2258) {

                if (D_U_00302D80.f60)
                    break;
                if (D_001D52FC_003E2258->f1A4 & 0x40) {
                    func_U_00397380();
                    D_U_00302D80.f84 = 2;
                    D_001D4CEC_003E2258 &= ~2;
                    D_001D4CEC_003E2258 &= ~4;
                    D_001D4CEC_003E2258 |= 0x20;
                    func_U_003A3A00();
                    break;
                }
                if (!(D_001D52FC_003E2258->f1A4 & 0x10))
                    break;
                D_U_00302D80.f84 = 1;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                func_U_0039BF98(0, 0);
                break;
            }
            if (D_U_001D5BDD_003E2258) {
                if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
                    D_U_00302D80.f84 = 2;
                    func_U_003A3A00();
                }
                break;
            }
            if (D_U_00302D80.f60)
                break;
            if (!(D_001D52FC_003E2258->f1A4 & 0x10))
                break;
            D_U_00302D80.f84 = 1;
            D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            func_U_0039BF98(0, 0);
            break;
        case 26:
        case 27:
            dlg = &D_U_00302D80;
            if (dlg->f60)
                break;
            if (D_001D52FC_003E2258->f1A4 & 0x40) {
                func_U_00397380();
                dlg->f84 = 2;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                D_001D4CEC_003E2258 |= 0x20;
                func_U_003A3A00();
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                dlg->f84 = 1;
                D_001D4CEC_003E2258 |= 0x20;
                func_U_0039BF98(0, 0);
            }
            break;
        case 6:
            if (D_U_001D5BDC_003E2258) {
                if (!D_U_001DA020_003E2258) {
                    dlg3 = &D_U_00302D80;
                    if (dlg3->f60)
                        break;
                    if (D_001D52FC_003E2258->f1A4 & 0x40) {
                        func_U_00397380();
                        dlg3->f84 = 2;
                        D_001D4CEC_003E2258 &= ~2;
                        D_001D4CEC_003E2258 &= ~4;
                        func_U_003A3A00();
                    }
                    if (!dlg3->f60 && (D_001D52FC_003E2258->f1A4 & 0x10)) {
                        dlg3->f84 = 1;
                        D_001D4CEC_003E2258 |= 0x20;
                        D_001D4CEC_003E2258 &= ~2;
                        D_001D4CEC_003E2258 &= ~4;
                        func_U_0039BF98(0, 0);
                    }
                    break;
                }
            } else if (D_U_001D5BDD_003E2258) {
                if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x20)) {
                    D_U_00302D80.f84 = 2;
                    func_U_003A3A00();
                }
                break;
            }
            if (!D_U_00302D80.f60 && (D_001D52FC_003E2258->f1A4 & 0x10)) {
                D_U_00302D80.f84 = 1;
                D_001D4CEC_003E2258 |= 0x20;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                func_U_0039BF98(0, 0);
            }
            break;
        case 11:
            if (!(D_001D4CEC_003E2258 & 6))
                func_U_0039BF98(0, 0);
            break;
        }
        break;
    case 6:
        switch (D_U_00302D80.f58) {
        case 0:
            D_U_00302D80.v0 = D_U_00222480_003E2258.position;
            D_U_00302D80.v10 = D_U_00222480_003E2258.angles;
            D_U_00302D80.f58 = 1;
            if (D_001D545C_003E2258 == 0xB) {
                if (D_U_001D9E90_003E2258 == 200.0f)
                    D_U_001D9504 = 0xAF;
                else
                    D_U_001D9504 = 0x7D;
            }
            break;
        case 1:
            if (D_001D545C_003E2258 != 0xB)
                D_U_001D9DD0_003E2258 = 3;
            /* VU0 in retail: vsub.xyz */
            vec_sub_ab(delta, &D_U_00222480_003E2258.position, &D_U_001D9E90_003E2258);
            distance = func_U_00388770(delta);
            func_U_003BEC60(&distance, &D_U_00302D80.f6C, (f32)D_U_001D9504, 0.041666668f, 0.041666668f, 5.0000005f);
            func_U_00388830(delta, delta, distance);
            /* VU0 in retail: vadd.xyz */
            vec_add_ab(&D_U_00222480_003E2258.position, delta, &D_U_001D9E90_003E2258);
            func_U_003DE260(&D_U_00302D80.f70, 0);
            if ((f32)D_U_001D9504 <= distance)
                D_U_00302D80.f58 = 2;
            break;
        case 2:
            if (D_001D545C_003E2258 != 0xB)
                D_U_001D9DD0_003E2258 = 3;
            if (D_001D52FC_003E2258->f148 != 0.0f || D_001D52FC_003E2258->f14C != 0.0f) {
                *(vu0_q *)target = 0;
                target[1] = D_001D52FC_003E2258->f148;
                target[2] = D_001D52FC_003E2258->f14C;
                *(vu0_q *)delta = *(vu0_q *)target;
                func_U_003888C8(delta, delta, D_U_00222480_003E2258.matrix);
                func_U_003BF640(delta, 1.0f);
                func_U_003886E8(delta, delta, (f32)-D_U_001D9504 * (D_U_001D9508 * 0.017453292f * 0.016666668f));
                func_U_003DE430(delta);
            }
            func_U_003DE260(&D_U_00302D80.f70, 1);
            func_U_003DE3A8((f32 *)((u8 *)D_001D52FC_003E2258 + 0x100));
            break;
        case 3: {
            f32 speed;
            if (D_001D545C_003E2258 != 0xB)
                D_U_001D9DD0_003E2258 = 3;
            speed = (f32)D_U_001D9504 * (D_U_001D9508 * 0.017453292f * 0.016666668f);
            /* VU0 in retail: vsub.xyz */
            vec_sub_ab(target, &D_U_00302D80, &D_U_001D9E90_003E2258);
            func_U_00388830(target, target, (f32)D_U_001D9504);
            /* vadd.xyz, vsub.xyz */
            vec_add_ab(target, target, &D_U_001D9E90_003E2258);
            vec_sub_ab(delta, target, &D_U_00222480_003E2258.position);
            func_U_00388E78(transform, D_U_00222480_003E2258.matrix);
            func_U_003888C8(delta, delta, transform);
            delta[0] = 0.0f;
            if (delta[1] == 0.0f && delta[2] == 0.0f)
                delta[1] = 1.0f;
            func_U_003BF640(delta, speed);
            func_U_003888C8(delta, delta, D_U_00222480_003E2258.matrix);
            func_U_003DE430(delta);
            func_U_003DE260(&D_U_00302D80.f70, 1);
            if (func_U_00388770(delta) < speed - 0.01f) {
                D_U_001D9DD4_003E2258 = 2;
                *(vu0_q *)&D_U_00302D80.v20 = *(vu0_q *)&D_U_00222480_003E2258.position;
                func_U_003BF360(D_U_00222480_003E2258.matrix, &D_U_00302D80.v30);
                D_U_00302D80.f58 = 4;
            }
            break;
        }
        case 4:
            if (D_001D545C_003E2258 != 0xB)
                D_U_001D9DD0_003E2258 = 3;
            func_U_003BEC60(&D_U_00302D80.f6C, &D_U_00302D80.f70, 1.0f, 0.00055555557f, 0.00055555557f, 0.025000002f);
            func_U_003886C0(&D_U_00222480_003E2258, &D_U_00302D80.v20, &D_U_00302D80, D_U_00302D80.f6C);
            func_U_003BEA80(delta, &D_U_00302D80.v30);
            func_U_003BEA80(target, &D_U_00302D80.v10);
            func_U_00388F90(transform, delta, target, D_U_00302D80.f6C);
            func_U_003890D8(transform, D_U_00222480_003E2258.matrix);
            if (D_U_00302D80.f6C >= 1.0f)
                func_U_0039BF98(0, 0);
            break;
        }
        D_U_00302D80.f7E = 1;
        if ((D_001D52FC_003E2258->f1A4 & 0x500) && D_U_00302D80.f58 == 2) {
            D_U_00302D80.f6C = 0.0f;
            D_U_00302D80.f58 = 3;
            D_U_00302D80.f70 = 0.0f;
        }
        if ((unsigned)(D_001D545C_003E2258 - 22) < 2) {
            E_003E2258 *object = D_U_001DA51C_003E2258;
            if (object < D_U_001DA520_003E2258) {
                do {
                    if (object->fAA == 0xD3D && object->f64)
                        object->f64(object);
                    ++object;
                } while (object < D_U_001DA520_003E2258);
            }
        }
        break;
    case 7:
        switch (D_U_00302D80.f58) {
        case 0:
            D_U_00302D80.f7E = 1;
            D_U_00302D80.f58 = 1;
            if (D_001A71C4[0] != 1)
                func_U_0037DD00();
            D_U_001D94D8 = 0;
            D_U_001D94D0 = D_U_001D94D4;
            func_U_00393370();
            func_U_003DE8B8();
            break;
        case 1:
            if (D_001A71C4[0] != 1) {
                func_U_0037DD00();
                func_U_0038EB10(0x23, 0, func_U_0038F3A0, func_U_0038F3F8, func_U_0038FDC0, 0, 0);
            } else {
                func_U_0038EB10(0x23, 0, func_U_003906E8, func_U_00390730, func_U_00390C18, 0, 0);
            }
            func_U_003AA290();
            func_U_003DE560();
            func_U_003DF7C0(0x168);
            func_U_003DFF90(0xB4);
            func_U_00393370();
            {
                int remaining = D_U_001D94D0;
                if (remaining > 0) {
                    D_U_001D94D0 = remaining - 1;
                    remaining = D_U_001D94D0;
                }
                D_U_001D94D0 = remaining;
            }
            --D_U_001D94F0;
            if (D_U_001D94F0 < 0)
                D_U_001D94F0 = 0;
            if (!D_U_001D94F0)
                ++D_U_00302D80.f58;
            break;
        case 2:
            if (D_001A71C4[0] != 1) {
                func_U_0037DD00();
                func_U_0038EB10(0x23, 0, func_U_0038F3A0, func_U_0038F3F8, func_U_0038FDC0, 0, 0);
            } else {
                func_U_0038EB10(0x23, 0, func_U_003906E8, func_U_00390730, func_U_00390C18, 0, 0);
            }
            func_U_003AA290();
            func_U_003DF7C0(0x168);
            func_U_003DFF90(0xB4);
            func_U_00393370();
            {
                int remaining = D_U_001D94D0;
                if (remaining > 0) {
                    D_U_001D94D0 = remaining - 1;
                    remaining = D_U_001D94D0;
                }
                D_U_001D94D0 = remaining;
            }
            if (D_U_001D94D0 <= 0) {
                D_U_001D94D0 = 0;
                ++D_U_00302D80.f58;
            }
            break;
        case 3:
            if (D_001A71C4[0] != 1)
                func_U_0037DD00();
            func_U_00393428();
            func_U_00393420();
            func_U_0039BF98(0, 0);
            break;
        }
        break;
    case 8:
        dlg = &D_U_00302D80;
        if (dlg->f58 != 2) {
            if (dlg->f58 >= 3)
                break;
            if (dlg->f58 < 0)
                break;
            ++dlg->f58;
            break;
        }
        func_U_0039BEC0(3, 2, dlg->f54, 0, 0);
        func_U_0039BEA0(3);
        goto advance;
    case 9:
        dlg = &D_U_00302D80;
        switch (dlg->f58) {
        case 1:
            if (D_001D52FC_003E2258->f1C4 & dlg->f8C) {
                dlg->f84 = 2;
                func_U_0039BF98(0, 0);
            } else if (D_001D52FC_003E2258->f1C4 & dlg->f90) {
                dlg->f84 = 1;
                func_U_0039BF98(0, 0);
            }
            break;
        case 0:
            goto initialize;
        }
        break;
    case 10:
        dlg = &D_U_00302D80;
        switch (dlg->f58) {
        case 0:
initialize:
            func_U_003DE8D0();
advance:
            ++dlg->f58;
            break;
        case 1:
            if (D_001D52FC_003E2258->f1C4 & dlg->f8C) {
                dlg->f84 = 2;
                func_U_0039FF28(0x12, 0, 0);
                func_U_0039BF98(0, 0);
            }
            break;
        default:
            break;
        }
        break;
    case 11:
        switch (D_U_00302D80.f58) {
        case 0:
            func_U_003DE8D0();
            ++D_U_00302D80.f58;
            if (D_001D5520_003E2258) {
                D_001D5520_003E2258 = !D_001D5520_003E2258;
                func_U_003DBE20();
                func_U_0039BF98(D_U_00302D80.f54, 0);
                break;
            }
            break;
        case 1:
            if (D_001D52FC_003E2258->f1C4 & 0x40) {
                D_U_00302D80.f84 = 2;
                ++D_U_00302D80.f58;
            } else if (D_001D52FC_003E2258->f1C0 & 0x10) {
                D_U_00302D80.f84 = 1;
                func_U_0039BF98(D_U_00302D80.f54, 0);
                break;
            }
            break;
        case 2:
            D_U_00302D80.f5C = 0x384;
            D_U_00302D80.f60 = 0;
            ++D_U_00302D80.f58;
            D_U_00302D80.f84 = 0;
            D_001D5520_003E2258 = !D_001D5520_003E2258;
            func_U_003DBE20();
            break;
        case 3:
            if (D_001D52FC_003E2258->f1C4 & 0x20)
                D_U_00302D80.f84 = 2;
            else if (D_001D52FC_003E2258->f1C4 & 0x10)
                D_U_00302D80.f84 = 1;
            --D_U_00302D80.f5C;
            if (D_U_00302D80.f5C <= 0)
                goto advanceConfirm;
            if (!D_U_00302D80.f84)
                break;
            goto advanceConfirm;
        case 4:
            if (D_U_00302D80.f84 < 0)
                goto advanceConfirm;
            if (D_U_00302D80.f84 < 2) {
                D_001D5520_003E2258 = !D_001D5520_003E2258;
                func_U_003DBE20();
            }
advanceConfirm:
            ++D_U_00302D80.f58;
            break;
        case 5:
            func_U_0039BF98(D_U_00302D80.f54, 0);
            break;
        }
        break;
    case 12:
        func_U_00380AB0();
        break;
    }
}
/* localdecomp:end func_U_003DCD08 */
