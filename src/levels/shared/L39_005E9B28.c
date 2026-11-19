#include "common.h"

typedef struct { u8 b[16]; } V16_48DCD8;

/* declared by functions of L39_005E94F8.c, which this file was cut from */
extern void func_L39_005E9B28(void *);

/* localdecomp:start func_L39_005E9B28 */
typedef struct {
    u8 pad0[0x1C4];
    s32 f1C4;
    u8 pad1[0x1CC - 0x1C8];
    s32 f1CC;
    u8 pad2[0x5C0 - 0x1D0];
} Q_005E9B28;

typedef struct {
    u8 pad0[0x2534];
    Q_005E9B28 *f2534;
} P_005E9B28;

extern Q_005E9B28 D_L39_00225780[];
extern s32 D_001D8584_sda;
__asm__(".extern D_L39_002429AC, 16");
extern u8 D_L39_002429AC;

extern s32 func_L01_00517688(void);
extern P_005E9B28 *func_L39_0061BF38(s32);
extern void func_L39_005D6A78(s32, s32);
extern s32 func_003B9BD0(s32);
extern void func_L39_005E8598(s32, s32);
extern void func_L39_005EAF10(void *);
extern void func_L39_005EAFF0(void);
extern void func_L39_005EB198(void);
extern void func_L01_004A0A80(void);
extern void func_L39_005EBCB8(void);
extern s32 func_L01_00432F50(void);
extern void func_L01_0041A508(void);
extern void func_L01_00353C80(void *);
extern s32 func_00381CC0(void);
extern void func_L01_00517748(s32);

void func_L39_005E9B28(void *a) {
    s32 mode = 0;
    P_005E9B28 *p;
    s32 s0;

    switch (func_L01_00517688()) {
    case 0:
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    }
    p = func_L39_0061BF38(func_L01_00517688());
    p->f2534->f1CC = 2;
    D_001D8584_sda = p->f2534 - D_L39_00225780;
    s0 = p->f2534->f1C4;
    func_L39_005D6A78(func_L01_00517688(), 10);
    func_L39_005E8598(func_003B9BD0(mode), s0);
    func_L39_005EAF10(a);
    func_L39_005EAFF0();
    func_L39_005EB198();
    func_L01_004A0A80();
    func_L39_005EBCB8();
    if (func_L01_00432F50() != 0) {
        func_L01_0041A508();
        func_L01_00353C80(a);
        if (D_L39_002429AC == 0) {
            func_L01_00517748(func_00381CC0());
        }
    }
}
/* localdecomp:end func_L39_005E9B28 */
