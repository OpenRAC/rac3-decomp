#include "common.h"

/* NTSC-U counterpart of func_L39_0067CCB0 (src/levels/39_multiplayer_menu/L39_0067CCB0.c) */
void func_L39_0067C110(void);
void func_L39_005EF018(void);
void func_L39_00679F08_0067A1F8(void);

/* localdecomp:start func_L39_0067A1F8 */
__asm__(".extern D_L39_00246940, 4");
extern s32 D_L39_00246940;
extern s32 D_L39_0024BC44;
extern f32 D_L39_0024BC48;
__asm__(".extern D_L39_0024BC48, 16");
extern s32 D_L39_0024BAC8;
extern u8 D_L39_00242B2E;
__asm__(".extern D_L39_00242B2E, 16");
extern unsigned long D_L39_00240380;
__asm__(".extern D_L39_00240380, 16");
extern s32 D_001A5990[];
void func_L39_005A43D8(void);
void func_003A3DA0(s32);
s32 func_00139E08(s32);
void func_00383A90(void);
void func_L39_0058BA98(void);
void func_L39_005FA660(void);
void func_003A3C00(void);
void func_0038DB98(void);
void func_0038DF10(s32);
void func_L39_00596BA0(void);
void func_L01_0045E370(void);

void func_L39_0067A1F8(void) {
    D_L39_00246940++;
    func_L39_00679F08_0067A1F8();
    D_L39_0024BC44++;
    func_L39_005A43D8();
    func_003A3DA0(1);
    D_L39_0024BC48 = (f32)*(volatile u32 *)0x10000800 / (D_001A5990[0] != 0 ? 11520.0f : 9600.0f); /* T0_COUNT */
    func_00139E08(0);
    D_L39_00242B2E = 0;
    D_L39_0024BAC8++;
    func_00383A90();
    D_L39_00240380 += *(volatile u32 *)0x10000800;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0058BA98();
    func_L39_005FA660();
    func_003A3C00();
    func_0038DB98();
    func_0038DF10(1);
    func_L39_00596BA0();
    func_L01_0045E370();
    func_L39_0067C110();
    ((s32 (*)(void))func_L39_005EF018)();
    D_L39_00246940--;
}
/* localdecomp:end func_L39_0067A1F8 */
