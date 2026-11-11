#include "common.h"

typedef struct Obj_003A88E8 {
    u8 pad0[0x94C];
    s16 f94C;
    u8 pad94E[0x0E];
    s32 f95C;
    u8 pad960[0x20];
    s32 f980;
    s32 f984;
} Obj_003A88E8;


INCLUDE_ASM("asm/levels", func_L24_003A8668);

INCLUDE_ASM("asm/levels", func_L24_003A8898);

/* localdecomp:start func_L24_003A88E8 */
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00404808(void (*)(void), void *);
extern void func_L24_003A7F58(void);

void func_L24_003A88E8(u8 *a0) {
    Obj_003A88E8 *obj;
    s32 c;

    obj = *(Obj_003A88E8 **)(a0 + 0x68);
    if (obj->f980 != 0) {
        obj->f984++;
        if (obj->f984 >= 0x1F5) {
            obj->f984 = 0;
            obj->f980 = 0;
        }
    }
    if (obj->f94C > 0) {
        obj->f94C--;
        c = obj->f95C;
        if (c >= 2) {
            if (obj->f94C == 0) {
                c--;
                obj->f95C = c;
                obj->f94C = 10;
            }
        }
    }
    func_003C2F58(a0, 2, *(u8 **)(a0 + 0x68) + 0x960);
    func_L01_00404808(func_L24_003A7F58, a0);
}
/* localdecomp:end func_L24_003A88E8 */

INCLUDE_ASM("asm/levels", func_L24_003A8998);
