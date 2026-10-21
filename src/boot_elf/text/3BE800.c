#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* US draft of func_003BE800 (rac3-uya-decomp func_003BE710, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */

/* localdecomp:start func_003BE800 */
__asm__(".extern D_001D8D28_003BE800, 4");
__asm__(".extern D_001D8D40_003BE800, 4");
extern s32 D_001DA2D0_003BE800;
extern u8 D_001DA2D4_003BE800;
extern s32 D_001DA2D8_003BE800;
extern s32 D_001DA2DC_003BE800;
extern s32 D_001D8D28_003BE800;
extern s32 D_001D8D40_003BE800;
extern u8 D_001D8D2C_003BE800[8];
extern u8 D_001D8D44_003BE800[8];
extern s32 D_002FCDC4[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern void func_003BE068(s32, s32 *, s32);
extern s32 func_003BE0F0();
extern void func_003BE1D8();
extern void func_003BE6C0();
extern void func_003BE8E0();
extern void func_003BE948();
s32 func_003BE800(s32 a) {
    D_001DA2D0_003BE800 = a;
    D_001DA2D4_003BE800 = 0;
    D_001DA2D8_003BE800 = 0;
    D_001DA2DC_003BE800 = 0;
    *(u8 *)0x1DA300 = 0;
    func_003BBDC0(0, 0);
    switch (D_001DA2D0_003BE800) {
    case 0:
        func_003BC7C0(4, &D_001D8D28_003BE800);
        func_003BE068(3, (s32 *)D_001D8D2C_003BE800, D_001D8D28_003BE800);
        break;
    case 1:
        func_003BC7C0(4, &D_001D8D40_003BE800);
        func_003BE068(3, (s32 *)D_001D8D44_003BE800, D_001D8D40_003BE800);
        break;
    }
    func_003BE1D8(func_003BE0F0());
    func_003BE6C0(func_003BE8E0);
    D_002FCDC4[0] = (s32)func_003BE948;
    return 1;
}
/* localdecomp:end func_003BE800 */
