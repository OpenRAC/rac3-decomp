#include "common.h"

/* localdecomp:start func_L39_0058A5D0 */
__asm__(".extern D_L39_001E02B8, 4");
__asm__(".extern D_L39_001E13C0, 4");
extern s32 D_L39_0024B9C8;
extern s32 D_L39_001E02B8;
extern u32 *D_L39_0024CAD0;
extern u32 *D_L39_001E13C0;
extern u8 D_1A3940[];
extern void func_003A92F0(s32);
extern s32 func_139E08(s32);
extern void func_003A9108(void);
extern void func_003A9150(void);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L39_005FCDF8(void);

void func_L39_0058A5D0(s32 arg0) {
    s32 i;
    s32 t;

    func_003A92F0(1);
    i = arg0 - 1;
    func_139E08(0);
    D_L39_001E02B8 = D_L39_0024B9C8 + 1;
    func_003A9108();

    while (i >= 0) {
        func_L39_00597E70();
        func_00392350(1);
        func_003923D0();
        func_003A9440(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A9440(1, (long)(0x80 - t) << 24);

        D_L39_0024CAD0[0] = 0x30000014;
        D_L39_0024CAD0[1] = (u32)D_1A3940;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000014;
        D_L39_001E13C0 = D_L39_0024CAD0 + 4;

        func_003A92F0(1);
        func_139E08(0);
        D_L39_001E02B8 = D_L39_0024B9C8 + 1;
        func_L39_005FCDF8();
        func_003A9150();
    }

    func_003A92F0(1);
    func_139E08(0);
    D_L39_001E02B8 = D_L39_0024B9C8 + 1;
    func_003A9108();
    func_L39_00597E70();
    func_00392350(1);
}
/* localdecomp:end func_L39_0058A5D0 */

INCLUDE_ASM("asm/levels", func_L39_0058A750);

INCLUDE_ASM("asm/levels", func_L39_0058A8B0);

INCLUDE_ASM("asm/levels", func_L39_0058ACE0);
