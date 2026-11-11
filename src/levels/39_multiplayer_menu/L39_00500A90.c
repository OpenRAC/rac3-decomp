#include "common.h"

/* localdecomp:start func_L39_00500A90 */
extern s32 func_L39_00500C78(void *, s32, s32);
extern s32 func_L39_00506198(void);
extern s32 func_L39_005061B8(void);
extern s32 func_11C090(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
s32 func_L39_00500A90(void *self, s32 a1, s32 a2, long a3) {
    void *p = ((void **)self)[3];
    s32 r = 0;
    if (a1 == 2) {
        if (a3 == 3) {
            r = func_L39_00500C78(p, func_L39_00506198(), 1);
            if (r == 0) {
                func_L39_004BC6C8(0xB, 0xD7, 0x9C, 0, 0);
            } else {
                r = func_L39_00500C78(p, func_11C090(func_L39_005061B8()), 1);
            }
        } else {
            r = func_L39_00500C78(p, a2, a3);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00500A90 */

/* localdecomp:start func_L39_00500B50 */
extern void *func_L39_004BEED8(s32 size);
extern s32 func_L39_004DB110(void);
extern void func_L39_004BEF28(void *p);
typedef struct S_00500B50 { s32 a0, a4, a8, aC, a10; } S_00500B50;
s32 func_L39_00500B50(void *self) {
    S_00500B50 *p = func_L39_004BEED8(0x14);
    if (p == 0) return 0;
    p->a0 = func_L39_004DB110();
    if (p->a0 == 0) { func_L39_004BEF28(p); return 0; }
    p->a4 = 0; p->a8 = 0; p->aC = 0; p->a10 = 0;
    ((s32 *)self)[3] = (s32)p;
    return 1;
}
/* localdecomp:end func_L39_00500B50 */

INCLUDE_ASM("asm/levels", func_L39_00500BC8);

INCLUDE_ASM("asm/levels", func_L39_00500C78);

INCLUDE_ASM("asm/levels", func_L39_00500EC8);
