#include "common.h"

/* NTSC-U counterpart of func_L39_00598780 (src/levels/shared/L39_00598780.c) */
/* localdecomp:start func_L39_005974B0 */
typedef struct S_00598780 {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ s32 f40;
    /* 0x44 */ char pad44[0x10];
    /* 0x54 */ s32 f54;
    /* 0x58 */ s32 f58;
    /* 0x5C */ s32 a5C[4];
    /* 0x6C */ s32 a6C[4];
    /* 0x7C */ s16 f7C;
    /* 0x7E */ s16 f7E;
    /* 0x80 */ s32 f80;
    /* 0x84 */ char pad84[4];
    /* 0x88 */ s32 f88;
} S_00598780;
extern S_00598780 D_L39_0025F540;
extern s32 D_001D718C_sda_005974B0;
extern s32 D_001A46DC[];
extern s32 D_L39_002412A8;
__asm__(".extern D_L39_002412A8, 16");
extern s32 func_L01_004573E8(void);
extern void func_00193F10(s32);
extern s32 func_003DE8A0(void);
extern void func_L01_0045BF98(s32);
extern void func_L39_005F0E48(s32, s32, s32);

void func_L39_005974B0(s32 a0, s32 a1) {
    s32 i;
    s32 v;
    S_00598780 *p;
    D_001D718C_sda_005974B0 = a0;
    if (a0 == 5) {
        D_L39_0025F540.f80 = D_001A46DC[0];
    } else {
        D_L39_0025F540.f80 = 0;
    }
    p = &D_L39_0025F540;
    p->f54 = a1;
    p->f7E = (a0 == 12);
    p->f40 = a0;
    p->f7C = 0;
    p->f58 = 0;
    if (func_L01_004573E8() != 3 && func_L01_004573E8() != 18) {
        v = 1;
    } else {
        v = 0;
    }
    p->f88 = v;
    if (D_L39_002412A8 != 3) {
        func_00193F10(0x4D);
        if (func_003DE8A0() == 0 && a0 != 12) {
            func_L01_0045BF98(0);
        }
    }
    for (i = 3; i >= 0; i--) {
        D_L39_0025F540.a5C[3 - i] = 0;
        D_L39_0025F540.a6C[3 - i] = 0;
    }
    if (a0 == 10) {
        func_L39_005F0E48(18, 0, 0);
    }
}
/* localdecomp:end func_L39_005974B0 */
