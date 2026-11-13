#include "common.h"

/* NTSC-U counterpart of func_L39_0060B750 (src/levels/shared/L39_0060B428.c): 5 -> 6 */
extern void func_001264E0(s32);

/* localdecomp:start func_L39_00609050 */
typedef struct S_0060B750 {
    u8 pad0[0x18];
    s16 h18;
    u8 pad1A[0x15C - 0x1A];
    s32 f15C;
    u8 pad160[0x164 - 0x160];
    s32 f164;
    u8 pad168[0x17C - 0x168];
    s32 f17C;
} S_0060B750;

typedef struct T_0060B750 {
    u8 pad0[7];
    u8 b7;
} T_0060B750;

extern void func_0038CB78_00609050(void *, s32, s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_005BD4E8(void);
extern void func_001264E0(s32);
extern void func_00194CB8(s32, s32, s32, s32, s32);
extern void func_00194760(void);
extern s32 func_00193680(void);
extern void func_L39_005F1248(void);
extern void func_L39_005BFDC8(void);
extern void func_00193C70(s32);
extern void func_00193C40(void);
extern void func_L39_005A43D8(void);
extern void func_L39_005A33A0(void);
extern s32 func_00194C78(s32);
extern void func_L39_005C0AC8(s32);
extern void func_00195AE8(void);
extern void func_L39_00589460(s32);
extern void func_L39_005A2130(void);
extern void func_00194B28(s32);
extern void func_L39_005FAF60(void);

extern u8 D_L39_0025F680_00609050[];
extern s32 D_L39_0025F840[];
extern u8 D_L39_002257E0[];
extern s32 D_L39_001FE1A0[];
extern S_0060B750 D_001A4560;
extern s32 D_L39_0024BC6C;
__asm__(".extern D_L39_0024BC6C, 16");
extern s32 D_L39_0024BC40;
__asm__(".extern D_L39_0024BC40, 16");
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024057C, 16");
extern s32 D_001D4CEC_sda_00609050;
extern s32 D_001D5BCC_sda_00609050;

void func_L39_00609050(void) {
    s32 i;
    s32 *p;

    func_0038CB78_00609050(D_L39_0025F680_00609050, -1, 0x80);
    func_L39_005BD7D8(6, 2, 0, 0, 0);
    func_L39_005BD4E8();
    D_L39_0025F840[4] |= 0x80000000;
    func_001264E0(0);
    func_00194CB8(2, 0, 0, 0, 0);
    func_00194760();
    func_00193680();
    func_L39_005F1248();
    func_L39_005BFDC8();
    D_L39_002257E0[7] = 1;
    for (i = 0; i < 6; i++) {
        if (D_L39_001FE1A0[36 + i] != 0) {
            func_00193C70(D_L39_001FE1A0[36 + i]);
            func_00193C40();
            D_L39_0024BC6C = 0;
            D_L39_001FE1A0[36 + i] = 0;
        }
    }
    while (D_001A4560.f15C >= 3 || D_001A4560.f164 >= 0) {
        func_L39_005A43D8();
        func_L39_005A33A0();
    }
    if (D_001A4560.f17C != 0) {
        D_001A4560.f17C = 0;
    }
    if (D_001A4560.h18 >= 0) {
        D_001A4560.h18 = -1;
    }
    D_001D4CEC_sda_00609050 = D_L39_0024057C & ~0x200;
    func_00194C78(0);
    D_L39_002257E0[7] = 0;
    func_L39_005C0AC8(1);
    while (func_00193680() != 0) {
        func_00195AE8();
    }
    D_L39_002257E0[7] = 1;
    func_L39_00589460(6);
    D_001D5BCC_sda_00609050 = D_L39_0024BC40;
    func_L39_005A2130();
    func_00194B28(0);
    D_L39_002257E0[7] = 0;
    func_L39_005FAF60();
}
/* localdecomp:end func_L39_00609050 */
