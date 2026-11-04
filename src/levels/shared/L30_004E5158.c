#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L30_004CF4B0(s32, s32);

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E6D08;
typedef struct {
    u8 pad0[0xC08];
    s32 w_C08;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 w_1AC0;
    u8 pad2[0x25C0 - 0x1AC4];
    P_004E6D08 *p_25C0;
    s32 w_25C4;
    u8 pad3[0x25CC - 0x25C8];
    s32 w_25CC;
    u8 pad4[0x25E9 - 0x25D0];
    u8 b_25E9;
    u8 pad5[0x25EB - 0x25EA];
    u8 b_25EB;
} S_004E6D08;

INCLUDE_ASM("asm/levels", func_L30_004E5158);

INCLUDE_ASM("asm/levels", func_L30_004E5370);

INCLUDE_ASM("asm/levels", func_L30_004E5410);

INCLUDE_ASM("asm/levels", func_L30_004E5598);

/* localdecomp:start func_L30_004E56D0 */
void func_L30_004E56D0(void) {
    u8 *obj = 0;

    switch (((S_004E56D0 *)&D_001A4BE0)->x1B04) {
    case 1:
        obj = func_003C24B0(0x15D5, 0x80);
        break;
    case 2:
        obj = func_003C24B0(0x1C7D, 0x80);
        break;
    case 4:
        obj = func_003C24B0(0x1C7E, 0x80);
        break;
    case 3:
    case 5:
        obj = func_003C24B0(0x1C7C, 0x80);
        break;
    default:
        break;
    }

    if (obj != 0) {
        ((S_004E56D0 *)&D_001A4BE0)->x1B24 = obj;
        *(s16 *)(obj + 0x32) = 0xFF;
        obj[0x31] = 1;
        *(long *)(obj + 0x38) = *(long *)(((S_004E56D0 *)&D_001A4BE0)->x25C0 + 0x38);
    }
}
/* localdecomp:end func_L30_004E56D0 */

INCLUDE_ASM("asm/levels", func_L30_004E5788);

INCLUDE_ASM("asm/levels", func_L30_004E58F8);

INCLUDE_ASM("asm/levels", func_L30_004E5BF0);

INCLUDE_ASM("asm/levels", func_L30_004E5DD8);

/* localdecomp:start func_L30_004E5F28 */
extern void func_L01_005110E8(s32, f32, f32, f32, s32);

void func_L30_004E5F28(s32 a) {
    func_L01_005110E8(a, 0.0f, 0.0f, 2.3f, 1);
}
/* localdecomp:end func_L30_004E5F28 */

INCLUDE_ASM("asm/levels", func_L30_004E5F58);

INCLUDE_ASM("asm/levels", func_L30_004E6068);

INCLUDE_ASM("asm/levels", func_L30_004E6200);

/* localdecomp:start func_L30_004E6988 */
f32 func_L30_004E6988(void) {
    s32 x = D_001A4BE0.p25C0[0x43];
    f32 f = 0.0f;
    if (D_001A4BE0.w25C4 == 0xA3) {
        if ((u32)(x - 0x11) < 3) {
            f = 1.5707964f;
        }
        if ((u32)(x - 0x14) < 3) {
            f = 0.7853982f;
        }
        if ((u32)(x - 0x1A) < 3) {
            f = -0.7853982f;
        }
        if ((u32)(x - 0x1D) < 3) {
            f = -1.5707964f;
        }
    }
    if (*(u16 *)(D_001A4BE0.p25C0 + 0x34) & 0x8000) {
        f = 3.1415927f - f;
    }
    return f;
}
/* localdecomp:end func_L30_004E6988 */

INCLUDE_ASM("asm/levels", func_L30_004E6A48);

INCLUDE_ASM("asm/levels", func_L30_004E6AD0);

LINKER_REMNANT("asm/levels", func_L30_004E6D00);

/* localdecomp:start func_L30_004E6D08 */
void func_L30_004E6D08(void) {
    if (((*(S_004E6D08 *)&D_001A4BE0).w_C08 & 2) != 0 && (*(S_004E6D08 *)&D_001A4BE0).b_25EB == 0) {
        s32 t = (*(S_004E6D08 *)&D_001A4BE0).p_25C0->b43;
        if (t == 19 || t == 22 || t == 25 || t == 28 || t == 31) {
            func_L01_0050FB40((*(S_004E6D08 *)&D_001A4BE0).p_25C0->b43 - 2, 0, 3.0f);
        }
        (*(S_004E6D08 *)&D_001A4BE0).b_25E9 = 0;
    }
    if ((*(S_004E6D08 *)&D_001A4BE0).w_25CC != 0) {
        if ((*(S_004E6D08 *)&D_001A4BE0).w_1AC0 == 0) {
            (*(S_004E6D08 *)&D_001A4BE0).b_25E9 = 0;
        }
    }
}
/* localdecomp:end func_L30_004E6D08 */

INCLUDE_ASM("asm/levels", func_L30_004E6DC8);

/* localdecomp:start func_L30_004E6E50 */
void func_L30_004E6E50(void) {
    u8 *b = (u8 *)&D_001A4BE0;
    u8 *q = *(u8 **)(b + 0x25C0);
    s32 a1 = 0xE;
    s32 f = 2;
    s32 v;

    if (q[0x43] == 0x3A) {
        a1 = 0xB;
        f = 4;
    }
    func_L01_0050FB40(0x3A, a1, (f32)f);
    v = *(s32 *)(b + 0x25CC);
    *(s16 *)(b + 0x1B3C) = 1;
    *(s16 *)(b + 0xBDC) = 0;
    if (v != 2) {
        func_L30_004CF4B0(0x9C, 0);
    }
    *(s16 *)(b + 0x1E0) = 0x11;
}
/* localdecomp:end func_L30_004E6E50 */

INCLUDE_ASM("asm/levels", func_L30_004E6ED8);

INCLUDE_ASM("asm/levels", func_L30_004E70A8);

INCLUDE_ASM("asm/levels", func_L30_004E71F0);
