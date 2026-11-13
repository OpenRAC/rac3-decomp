#include "common.h"

/* localdecomp:start func_L39_005A9310 */
void func_003AAE60(s32);
extern s32 D_001A5810[];

void func_L39_005A9310(void) {
    func_003AAE60(D_001A5810[0] != 0);
}
/* localdecomp:end func_L39_005A9310 */

/* localdecomp:start func_L39_005A9338 */
typedef struct { u8 pad0[0x84]; s32 f84; } G_005A9338;
typedef struct {
    u8 pad0[0x1A0];
    s32 f1A0, f1A4, f1A8, f1AC, f1B0, f1B4, f1B8, f1BC, f1C0, f1C4, f1C8, f1CC;
} P_005A9338;
extern G_005A9338 D_L39_0025F680[];
extern P_005A9338 D_00225780[];
extern s32 D_001A5810[];
extern s32 D_L39_00242A50;
__asm__(".extern D_L39_002412DC, 16");
extern s32 D_L39_002412DC;
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L01_00521C90(s32, s32);
extern s32 func_L39_00607498(s32, s32);
extern void func_L01_003F1F08_005A9338(void);
extern void func_L01_003F1F10_005A9338(void);
extern void func_L01_004365A0_005A9338(void);
extern void func_L01_00436570_005A9338(void);
extern void func_L39_005A9310(void);

void func_L39_005A9338(void) {
    s32 base;

    func_0011D534((void *)D_L39_0025F680->f84, 0xCD, 0x40000);
    D_00225780->f1A0 = 0;
    D_00225780->f1A4 = 0;
    D_00225780->f1A8 = 0;
    D_00225780->f1AC = 0;
    D_00225780->f1B0 = 0;
    D_00225780->f1B4 = 0;
    D_00225780->f1B8 = 0;
    D_00225780->f1BC = 0;
    D_00225780->f1C0 = 0;
    D_00225780->f1C4 = 0;
    D_00225780->f1C8 = 0;
    D_00225780->f1CC = 0;
    ((void (*)(s32))func_L39_005A9310)(D_001A5810[0]);
    base = func_L39_00607498(func_L01_00521C90(0x24EE0, D_L39_0025F680->f84), 0x40000);
    D_L39_00242A50 = base;
    if (D_L39_002412DC == 0x1F5) {
        *(void (**)(void))(base + 0x24D9C) = func_L01_003F1F08_005A9338;
        *(void (**)(void))(base + 0x24DA0) = func_L01_003F1F10_005A9338;
    } else {
        *(void (**)(void))(base + 0x24D9C) = func_L01_004365A0_005A9338;
        *(void (**)(void))(base + 0x24DA0) = func_L01_00436570_005A9338;
    }
}
/* localdecomp:end func_L39_005A9338 */
