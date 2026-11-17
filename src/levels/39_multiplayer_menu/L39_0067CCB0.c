#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067C948.c, which this file was cut from */
void func_L39_0067EC30(void);
void func_L39_005F1718(void);
void func_L39_0067C9C0(void);

/* localdecomp:start func_L39_0067CCB0 */
__asm__(".extern D_L39_002467E0, 4");
extern s32 D_L39_002467E0;
extern s32 D_L39_0024BB44;
extern f32 D_L39_0024BB48;
__asm__(".extern D_L39_0024BB48, 16");
extern s32 D_L39_0024B9C8;
extern u8 D_L39_002429AE;
__asm__(".extern D_L39_002429AE, 16");
extern unsigned long D_L39_00240200;
__asm__(".extern D_L39_00240200, 16");
extern s32 D_001A5810[];
void func_L39_005A61D8(void);
void func_003A92F0(s32);
s32 func_00139E08(s32);
void func_00388138(void);
void func_L39_0058CC68(void);
void func_L39_005FCDF8(void);
void func_003A9150(void);
void func_003923D0(void);
void func_00392748(s32);
void func_L39_00597E70(void);
void func_L01_00461818(void);

void func_L39_0067CCB0(void) {
    D_L39_002467E0++;
    func_L39_0067C9C0();
    D_L39_0024BB44++;
    func_L39_005A61D8();
    func_003A92F0(1);
    D_L39_0024BB48 = (f32)*(volatile u32 *)0x10000800 / (D_001A5810[0] != 0 ? 11520.0f : 9600.0f); /* T0_COUNT */
    func_00139E08(0);
    D_L39_002429AE = 0;
    D_L39_0024B9C8++;
    func_00388138();
    D_L39_00240200 += *(volatile u32 *)0x10000800;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0058CC68();
    func_L39_005FCDF8();
    func_003A9150();
    func_003923D0();
    func_00392748(1);
    func_L39_00597E70();
    func_L01_00461818();
    func_L39_0067EC30();
    ((s32 (*)(void))func_L39_005F1718)();
    D_L39_002467E0--;
}
/* localdecomp:end func_L39_0067CCB0 */
