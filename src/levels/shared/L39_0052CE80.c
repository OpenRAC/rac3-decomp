#include "common.h"

/* localdecomp:start func_L39_0052CE80 */
typedef struct { u8 pad[0x180]; s32 f180; } G_0052CE80;
typedef struct { u8 pad[0x90]; s32 f90; } R_0052CE80;
typedef struct { u8 pad[0x1D8]; s32 f1D8; } T_0052CE80;
typedef struct { u8 pad[0x68]; T_0052CE80 *f68; } O_0052CE80;
__asm__(".extern D_L39_00241640, 16");
extern G_0052CE80 *D_L39_00241640;
extern void func_003C2F58(void *, s32, void *);
extern f32 D_L39_0024AAE0;
extern R_0052CE80 *func_L39_005422E8(f32, void *, s32, void *, s32, s32, s32, s32);

void func_L39_0052CE80(O_0052CE80 *arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4, u32 arg5) {
    T_0052CE80 *t = arg0->f68;
    u8 buf[16];
    R_0052CE80 *r;
    if (arg3 == 10) {
        t->f1D8 = 0;
    } else {
        t->f1D8 = 1;
    }
    func_003C2F58(arg0, t->f1D8, buf);
    r = func_L39_005422E8(D_L39_0024AAE0, arg0, arg1, buf, 0x10001, arg2, 1, (D_L39_00241640->f180 != 2) ? arg4 : 0);
    if (r != 0) {
        if (arg5 != 0xFFFFFFFF) {
            r->f90 = arg5;
        }
    }
    t->f1D8 = t->f1D8 ^ 1;
}
/* localdecomp:end func_L39_0052CE80 */

INCLUDE_ASM("asm/levels", func_L39_0052CF70);

INCLUDE_ASM("asm/levels", func_L39_0052D1C0);
