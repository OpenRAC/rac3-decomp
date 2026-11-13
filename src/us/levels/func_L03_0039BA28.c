#include "common.h"

/* NTSC-U counterpart of func_L03_0039D188 (src/levels/03_starship_phoenix/L03_0039C888.c) */
extern u8 D_001A4C60[];
extern void func_L03_0039BA28();
extern void func_003BE4F0();
extern void func_L01_00441FB8();
extern void func_L03_0039BE18(u8 *, u8 *);

/* localdecomp:start func_L03_0039BA28 */
extern u8 D_001426E0[];
extern u16 D_00143954[];
extern u16 D_001A864C[];
extern s32 D_L03_002E5330[];
extern u8 D_001A4C60[];
extern s32 D_L03_001DFA1C_0039BA28;
extern s32 D_00142C10[];
extern u8 D_L03_001E2540[];
extern s32 func_0037E0F0_0039BA28();
extern void func_L01_00452F40();
extern void func_00399F90();
extern void func_L03_0039BE18();
extern f32 func_L01_0040C018();
extern void func_L01_00444188();
extern s32 func_L01_00444358();
extern void func_003BE4F0();
extern void func_L01_00441FB8();

typedef struct {
    u8 p0[0x20]; u8 x20; u8 p21[0xF]; u8 x30; u8 x31; u8 p32[2]; u8 x34; u8 p35[0xE]; u8 x43;
    u8 p44[0x23]; u8 x67; u8 p68[4]; u8 x6C; u8 p6D[2]; u8 x6F; u8 p70[0x38]; u8 xA8;
} S_0039D188;
typedef struct { u8 p[0x310]; s32 x310; u8 p314[4]; s32 x318; } T_0039D188;

void func_L03_0039BA28(S_0039D188 *a) {
    T_0039D188 *p = *(T_0039D188 **)((u8 *)a + 0x68);
    if (D_001426E0[8] == 0) {
        if (D_00143954[0] == 0 || (D_001A864C[0] != 0 && D_L03_002E5330[0] == 0 && D_L03_002E5330[9] == -1)) {
            if (func_0037E0F0_0039BA28(D_001A4C60, p->x310, 0) != 0) {
                func_L01_00452F40(D_L03_001DFA1C_0039BA28 + (p->x318 << 8), 1);
                D_001426E0[8] = 1;
                func_00399F90();
            }
        }
    }
    if (a->x20 < 6 && (D_00142C10[0] & 0x10000)) {
        func_L03_0039BE18(a, p);
    }
    if (((a->x34) ^ 1) & 1) {
        if (a->x31 != 0) {
            if (func_L01_0040C018(D_L03_001E2540, (u8 *)a + 0x10) < 576.0f) {
                func_L01_00444188(a);
                a->x6F = 0x16;
            }
        }
    }
    if ((u8)(a->x20 - 1) < 4) {
        if (func_L01_00444358(a, -1, 0) != 0) {
            if (a->x43 != 10) func_003BE4F0(a, 10, 4, 3);
            func_L01_00441FB8(a, 5, -1);
        }
    } else {
        if (a->x20 == 6) {
            if (func_L01_00444358(a, -1, 0) != 0) {
                if (a->x43 != 10) func_003BE4F0(a, 10, 4, 3);
                func_L01_00441FB8(a, 11, -1);
            }
        }
    }
    a->xA8 = 0xFF;
}
/* localdecomp:end func_L03_0039BA28 */
