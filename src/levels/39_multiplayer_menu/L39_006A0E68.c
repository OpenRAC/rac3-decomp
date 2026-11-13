#include "common.h"

typedef struct { char pad[0x70]; char *f70; } T;

LINKER_REMNANT("asm/levels", func_L39_006A0E68);

INCLUDE_ASM("asm/levels", func_L39_006A0E80);

LINKER_REMNANT("asm/levels", func_L39_006A1728);

/* localdecomp:start func_L39_006A1730 */
void func_L39_00688400(void *, s32);
void func_L39_006CC158(void *, s32);
extern u8 D_L39_0047D730[];

void func_L39_006A1730(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047D730;
    func_L39_006CC158(arg0 + 0x146C, 2);
    func_L39_006CC158(arg0 + 0x1298, 2);
    func_L39_006CC158(arg0 + 0x10C4, 2);
    func_L39_00688400(arg0, arg1);
}
/* localdecomp:end func_L39_006A1730 */
