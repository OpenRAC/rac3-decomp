#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00518C30);

INCLUDE_ASM("asm/levels", func_L39_00518E34);

/* localdecomp:start func_L39_00518E48 */
typedef struct S_00518E48 {
    long f0;
    long f8;
    u16 f10;
} S_00518E48;

extern S_00518E48 D_L39_00479AA0;
extern S_00518E48 D_L39_00453DB8;
extern void func_L39_00518EA8(s32, s32 *, S_00518E48 *, s32);

S_00518E48 *func_L39_00518E48(s32 arg0) {
    s32 local = arg0;
    D_L39_00453DB8.f0 = D_L39_00479AA0.f0;
    D_L39_00453DB8.f8 = D_L39_00479AA0.f8;
    D_L39_00453DB8.f10 = D_L39_00479AA0.f10;
    func_L39_00518EA8(2, &local, &D_L39_00453DB8, 0x12);
    return &D_L39_00453DB8;
}
/* localdecomp:end func_L39_00518E48 */

INCLUDE_ASM("asm/levels", func_L39_00518EA8);

INCLUDE_ASM("asm/levels", func_L39_00518F20);

INCLUDE_ASM("asm/levels", func_L39_00518FC4);
