#include "common.h"

/* localdecomp:start func_L30_004BC770 */
typedef int s128_004BC770 __attribute__((mode(TI)));
typedef struct {
    /* 0x0000 */ u8 pad0[64];
    /* 0x0040 */ u8 v64[64];
    /* 0x0080 */ s128_004BC770 v128;
    /* 0x0090 */ u8 v144[8];
    /* 0x0098 */ f32 f152;
    /* 0x009C */ u8 pad9c[656 - 156];
    /* 0x0290 */ s32 w656;
    /* 0x0294 */ u8 pad294[5172 - 660];
    /* 0x1434 */ s16 h5172;
    /* 0x1436 */ u8 pad1436[8256 - 5174];
    /* 0x2040 */ s128_004BC770 hist[32];
    /* 0x2240 */ u8 pad2240[8800 - 8768];
    /* 0x2260 */ f32 f8800;
    /* 0x2264 */ f32 f8804;
    /* 0x2268 */ u8 pad2268[9668 - 8808];
    /* 0x25C4 */ s32 w9668;
    /* 0x25C8 */ u8 pad25c8[9700 - 9672];
    /* 0x25E4 */ u8 b9700;
    /* 0x25E5 */ u8 pad25e5[9716 - 9701];
    /* 0x25F4 */ u8 b9716;
    /* 0x25F5 */ u8 pad25f5[9836 - 9717];
    /* 0x266C */ f32 fhist[32];
    /* 0x26EC */ s32 w9964;
    /* 0x26F0 */ s32 w9968;
    /* 0x26F4 */ s32 w9972;
    /* 0x26F8 */ s32 w9976;
    /* 0x26FC */ u8 pad26fc[10296 - 9980];
    /* 0x2838 */ f32 f10296;
    /* 0x283C */ f32 f10300;
    /* 0x2840 */ f32 f10304;
} H_004BC770;
extern u8 D_001A4BE0[];
extern u8 D_001A6EC0[];
extern u8 D_001A6014[];
extern u8 *D_001D52FC;
extern s32 func_L01_00513EF0(void);
extern s32 func_0038CB00(void *a0);
extern u8 func_L01_00510E40(void);
extern f32 func_L01_004EE780(void);
extern f32 func_0038CED8(void *a0);
extern f32 func_0038D160(f32 a, f32 b);
extern void **func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern void func_L30_00344188(f32);
extern void func_L30_004C4318(void);
extern void func_0038D328(void *a0, void *a1);
extern void func_0038D2A0(void *a0);
extern void func_0038D5B0(void *a0, void *a1);
extern void func_L30_004BC210(s32 a0);
extern void func_L01_004FE668(void);
extern void func_L30_004CD998(void);
/* from func_L01_004EE4E0 (src/levels/shared/L01_004E7338.c) */
void func_L30_004BC770(void) {
    void **prof;
    u8 *pl;
    H_004BC770 *q;
    s32 t;

    *(s128_004BC770 *)D_001A6EC0 = *(s128_004BC770 *)(D_001A6EC0 - 8800);
    if ((*(u32 *)(D_001D52FC + 416) & 3) && func_L01_00513EF0() == 0) {
        q = (H_004BC770 *)(D_001A6EC0 - 8928);
        if (q->h5172 <= 0) {
            q->h5172 = 1;
        }
    } else {
        func_0038CB00(D_001A6014);
    }
    if ((*(H_004BC770 *)&D_001A4BE0).w9668 == 16) {
        (*(H_004BC770 *)&D_001A4BE0).h5172 = 0;
    }
    (*(H_004BC770 *)&D_001A4BE0).b9716 = func_L01_00510E40();
    (*(H_004BC770 *)&D_001A4BE0).w656 = 0;
    (*(H_004BC770 *)&D_001A4BE0).f8800 = *(f32 *)(D_001D52FC + 264);
    (*(H_004BC770 *)&D_001A4BE0).f8804 = -*(f32 *)(D_001D52FC + 268);
    (*(H_004BC770 *)&D_001A4BE0).f10300 = func_L01_004EE780();
    if (func_0038CED8(&(*(H_004BC770 *)&D_001A4BE0).f8800) < 0.25f) {
        pl = D_001D52FC;
        t = ((*(s32 *)(pl + 432) >> 13) & 1) - ((*(s32 *)(pl + 432) >> 15) & 1);
        (*(H_004BC770 *)&D_001A4BE0).f8800 = (f32)t;
        t = (*(s32 *)(pl + 432) >> 14) & 1;
        (*(H_004BC770 *)&D_001A4BE0).f8804 = (f32)((*(s32 *)(pl + 432) & 0x1000) ? 1 - t : -t);
    }
    (*(H_004BC770 *)&D_001A4BE0).f10296 = func_L01_004EE780();
    (*(H_004BC770 *)&D_001A4BE0).f10304 = func_0038D160((*(H_004BC770 *)&D_001A4BE0).f8800, (*(H_004BC770 *)&D_001A4BE0).f8804);
    if ((*(H_004BC770 *)&D_001A4BE0).b9700 == 5) {
        func_L30_00344188(0.0f);
    }
    prof = func_L01_0043B568(7791, 0, 12);
    if (prof != 0) {
        ((void (*)(void))prof[1])();
    }
    func_L30_004C4318();
    (*(H_004BC770 *)&D_001A4BE0).fhist[(*(H_004BC770 *)&D_001A4BE0).w9964] = (*(H_004BC770 *)&D_001A4BE0).f152;
    (*(H_004BC770 *)&D_001A4BE0).w9964 = ((*(H_004BC770 *)&D_001A4BE0).w9964 + 1) % 32;
    if (++(*(H_004BC770 *)&D_001A4BE0).w9968 > 32) {
        (*(H_004BC770 *)&D_001A4BE0).w9968 = 32;
    }
    (*(H_004BC770 *)&D_001A4BE0).hist[(*(H_004BC770 *)&D_001A4BE0).w9972] = (*(H_004BC770 *)&D_001A4BE0).v128;
    (*(H_004BC770 *)&D_001A4BE0).w9972 = ((*(H_004BC770 *)&D_001A4BE0).w9972 + 1) % 32;
    if (++(*(H_004BC770 *)&D_001A4BE0).w9976 > 32) {
        (*(H_004BC770 *)&D_001A4BE0).w9976 = 32;
    }
    func_0038D328(&(*(H_004BC770 *)&D_001A4BE0), (*(H_004BC770 *)&D_001A4BE0).v144);
    func_0038D2A0((*(H_004BC770 *)&D_001A4BE0).v64);
    func_0038D5B0((*(H_004BC770 *)&D_001A4BE0).v64, &(*(H_004BC770 *)&D_001A4BE0));
    func_L30_004BC210(0);
    func_L01_004FE668();
    func_L30_004CD998();
    if ((*(H_004BC770 *)&D_001A4BE0).b9700 == 5) {
        func_L30_00344188(1.0f);
    }
    if (prof != 0) {
        ((void (*)(void))prof[2])();
    }
}
/* localdecomp:end func_L30_004BC770 */
