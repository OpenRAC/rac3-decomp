#include "common.h"

typedef struct Obj_00322548 {
    u8 pad0[0x30];
    u8 f30;
    u8 pad31[0x33];
    void (*f64)(struct Obj_00322548 *);
    u8 pad68[0x98];
} Obj_00322548;

INCLUDE_ASM("asm/levels", func_L03_00321DD0);

INCLUDE_ASM("asm/levels", func_L03_003220D8);

INCLUDE_ASM("asm/levels", func_L03_00322160);

/* localdecomp:start func_L03_00322548 */
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

extern Obj_00322548 *D_L03_001DF99C[];

void func_L03_00322548(u8 *a, s32 b) {
    Obj_00322548 *p = D_L03_001DF99C[0] + b;

    func_L01_00456230((u8 *)p, 1);
    p->f30 = 0xFF;
    p->f64(p);
    func_L01_004450F0(a, 4, -1);
}
/* localdecomp:end func_L03_00322548 */
