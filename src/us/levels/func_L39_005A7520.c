#include "common.h"

/* NTSC-U counterpart of func_L39_005A9338 (src/levels/shared/L39_005A9310.c) */
extern s32 D_001A5990[];

/* localdecomp:start func_L39_005A7520 */
typedef struct { u8 pad0[0x84]; s32 f84; } G_005A9338;
typedef struct {
    u8 pad0[0x1A0];
    s32 f1A0, f1A4, f1A8, f1AC, f1B0, f1B4, f1B8, f1BC, f1C0, f1C4, f1C8, f1CC;
} P_005A9338;
extern G_005A9338 D_L39_0025F780_005A7520[];
extern P_005A9338 D_L39_00225900[];
extern s32 D_001A5990[];
extern s32 D_L39_00242BD0;
__asm__(".extern D_L39_0024145C, 16");
extern s32 D_L39_0024145C;
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L01_0051DC40(s32, s32);
extern s32 func_L39_00604D98(s32, s32);
extern void func_L01_003EFFC8_005A7520(void);
extern void func_L01_003EFFD0_005A7520(void);
extern void func_L01_00433568_005A7520(void);
extern void func_L01_00433538_005A7520(void);
extern void func_L39_005A74F8(void);

void func_L39_005A7520(void) {
    s32 base;

    func_0011D534((void *)D_L39_0025F780_005A7520->f84, 0xCD, 0x40000);
    D_L39_00225900->f1A0 = 0;
    D_L39_00225900->f1A4 = 0;
    D_L39_00225900->f1A8 = 0;
    D_L39_00225900->f1AC = 0;
    D_L39_00225900->f1B0 = 0;
    D_L39_00225900->f1B4 = 0;
    D_L39_00225900->f1B8 = 0;
    D_L39_00225900->f1BC = 0;
    D_L39_00225900->f1C0 = 0;
    D_L39_00225900->f1C4 = 0;
    D_L39_00225900->f1C8 = 0;
    D_L39_00225900->f1CC = 0;
    ((void (*)(s32))func_L39_005A74F8)(D_001A5990[0]);
    base = func_L39_00604D98(func_L01_0051DC40(0x24EE0, D_L39_0025F780_005A7520->f84), 0x40000);
    D_L39_00242BD0 = base;
    if (D_L39_0024145C == 0x1F5) {
        *(void (**)(void))(base + 0x24D9C) = func_L01_003EFFC8_005A7520;
        *(void (**)(void))(base + 0x24DA0) = func_L01_003EFFD0_005A7520;
    } else {
        *(void (**)(void))(base + 0x24D9C) = func_L01_00433568_005A7520;
        *(void (**)(void))(base + 0x24DA0) = func_L01_00433538_005A7520;
    }
}
/* localdecomp:end func_L39_005A7520 */
