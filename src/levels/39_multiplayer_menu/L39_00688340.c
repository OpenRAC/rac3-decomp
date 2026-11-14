#include "common.h"

typedef struct { u8 pad0[0xF4]; u8 *p; } O_A;

/* declared by functions of L39_006876A0.c, which this file was cut from */
void func_L39_0067EE00(void *);

/* localdecomp:start func_L39_00688340 */
void func_L39_005F1718();
s32 func_L39_005F3548();

s32 func_L39_00688340(void) {
    s32 temp_s0;

    temp_s0 = func_L39_005F3548();
    func_L39_005F1718();
    func_L39_005F1718();
    return temp_s0;
}
/* localdecomp:end func_L39_00688340 */

LINKER_REMNANT("asm/levels", func_L39_00688378);

/* localdecomp:start func_L39_00688388 */
extern u8 D_L39_0047C2F8[];
void func_L39_0067EE00(void *);

void *func_L39_00688388(void *arg0) {
    u8 *obj;
    s32 i;

    obj = arg0;
    ((void *(*)(void *))func_L39_0067EE00)(arg0);
    *(s32 *)(obj + 0x10C) = 0;
    *(u8 **)(obj + 0x60) = D_L39_0047C2F8;
    for (i = 0x5F; i >= 0; i--) {
        ((s32 *)(obj + 0x110))[i] = 0;
    }
    *(s32 *)(obj + 0x290) = -1;
    *(u8 **)(obj + 0x2A4) = obj + 0x2A8;
    return obj;
}
/* localdecomp:end func_L39_00688388 */
