#include "common.h"

/* localdecomp:start func_L39_005A4058 */
typedef struct {
    u8 pad0[0x79A4];
    s32 f79A4;
    u8 pad79A8[0x79B0 - 0x79A8];
    s32 f79B0;
    s32 f79B4;
    u8 pad79B8[0x79C0 - 0x79B8];
    s32 f79C0;
    s32 f79C4;
} S_005A4058;

extern S_005A4058 D_L39_001F0A00;
extern u32 D_L39_001FE0B0[];
extern u32 D_L39_001FE0B4[];
typedef struct {
    s32 stage;
    s32 busy;
    s32 archive0;
    s32 archive1;
} Load_005A4058;

extern Load_005A4058 D_L39_00240288 __attribute__((section(".sdata")));
extern s32 D_L39_00240428;
extern s32 D_L39_0024042C;
extern s32 D_L39_002410E4;
extern s32 D_L39_0025F6EC[];

extern void func_00194670(void);
extern s32 func_00193590(void);
extern s32 func_00194A38(s32);
extern s32 func_00194AF8(void);
extern s32 func_00139048(void);
extern void func_00193B50(void);
extern s32 func_L39_005C2A40(s32, s32, s32);
extern void func_L39_005F16F0(void);
extern void func_L39_005C1310(void);
extern void func_L39_005C1368(s32);

/* from rac2-decomp's func_00293A60 */
s32 func_L39_005A4058(void) {
    func_00194670();
    func_00193590();
    if (func_00194A38(1) != 0) {
        D_L39_00240428++;
        if (D_L39_002410E4 != 1) {
            return 0;
        }
        if (D_L39_00240428 < 0x2D1) {
            return 0;
        }
        D_L39_0024042C = D_L39_002410E4;
        D_L39_002410E4 = 0;
        if (D_L39_00240288.stage < 3) {
            D_L39_00240288.stage--;
        }
        func_00194AF8();
        return 0;
    }
    if (func_00139048() != 0 && D_L39_0024042C == 0) {
        D_L39_0024042C = 1;
        D_L39_002410E4 = 0;
        if (D_L39_00240288.stage < 3) {
            D_L39_00240288.stage--;
        }
    }
    switch (D_L39_00240288.stage) {
    case 0: {
        u32 bytes;

        bytes = ((D_L39_001F0A00.f79C4 << 11) + 4095) & 0xFFFFF000;
        D_L39_00240288.archive1 = D_L39_0025F6EC[0] - bytes;
        bytes = ((D_L39_001F0A00.f79B4 << 11) + 4095) & 0xFFFFF000;
        D_L39_00240288.archive0 = D_L39_00240288.archive1 - bytes;
        func_L39_005C2A40(D_L39_00240288.archive0, D_L39_001F0A00.f79B0 + D_L39_001F0A00.f79A4, D_L39_001F0A00.f79B4);
        D_L39_00240288.stage++;
        break;
    }
    case 1:
        func_L39_005C2A40(D_L39_00240288.archive1, D_L39_001F0A00.f79C0 + D_L39_001F0A00.f79A4, D_L39_001F0A00.f79C4);
        D_L39_00240288.stage++;
        break;
    case 2:
        if (D_L39_00240288.busy != 0) {
            return 0;
        }
        func_L39_005F16F0();
        func_L39_005C1310();
        D_L39_00240288.stage++;
        break;
    case 3:
        func_00193590();
        if (D_L39_001FE0B0[0] != 0xFFFFFFFF) {
            D_L39_00240288.stage++;
        }
        break;
    case 4:
        func_L39_005C1368(0);
        D_L39_00240288.stage++;
        break;
    case 5:
        func_00193590();
        if (D_L39_001FE0B4[0] != 0xFFFFFFFF) {
            func_00193B50();
            return 1;
        }
        break;
    }
    return 0;
}
/* localdecomp:end func_L39_005A4058 */

INCLUDE_ASM("asm/levels", func_L39_005A4290);
