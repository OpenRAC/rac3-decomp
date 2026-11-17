#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern s32 D_001DA2D0_003BE448;
extern u8 D_001DA2D4_003BE448;
extern s32 D_001DA2D8_003BE448;
extern s32 D_001DA2DC_003BE448;
extern s32 D_001D8D28_003BE448;
extern s32 D_001D8D40_003BE448;
extern u8 D_001D8D2C_003BE448[8];
extern u8 D_001D8D44_003BE448[8];
extern s32 D_002FCDC4[];
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38();
extern void func_003BDE20();
extern void func_003BE308();
/* localdecomp:start func_003BE448 */
__asm__(".extern D_001D8D28_003BE448, 4");
__asm__(".extern D_001D8D40_003BE448, 4");
/* from boot_elf's func_003BE800, with the state at 0x1DA2D0 as one struct */
typedef struct { s32 mode; u8 b4; s32 x8; s32 xC; f32 e0[4] __attribute__((aligned(16))); f32 f0[4]; u8 b30; } G_003BE448;
extern G_003BE448 D_001DA2D0_003BE448g __attribute__((section(".sdata")));
extern void func_003BE528();
extern void func_003BE590();
s32 func_003BE448(s32 a) {
    D_001DA2D0_003BE448g.mode = a;
    D_001DA2D0_003BE448g.b4 = 0;
    D_001DA2D0_003BE448g.x8 = 0;
    D_001DA2D0_003BE448g.xC = 0;
    D_001DA2D0_003BE448g.b30 = 0;
    func_003BBA08(0, 0);
    switch (D_001DA2D0_003BE448g.mode) {
    case 0:
        func_003BC408(4, &D_001D8D28_003BE448);
        func_003BDCB0(3, (s32 *)D_001D8D2C_003BE448, D_001D8D28_003BE448);
        break;
    case 1:
        func_003BC408(4, &D_001D8D40_003BE448);
        func_003BDCB0(3, (s32 *)D_001D8D44_003BE448, D_001D8D40_003BE448);
        break;
    }
    func_003BDE20(func_003BDD38());
    func_003BE308(func_003BE528);
    D_002FCDC4[0] = (s32)func_003BE590;
    return 1;
}
/* localdecomp:end func_003BE448 */
