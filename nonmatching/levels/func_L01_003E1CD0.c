/* Level 01. 31 diff, all from how the jump-table address is built: retail does lui/sll/addiu/addu/lw (the %lo in a separate addiu); this C folds %lo into the lw and puts the lui after the sll. The control flow, callees and the hoisted a->q load already match. */
#include "common.h"
typedef struct { char p0[0x20]; u8 k; char p1[0x47]; s32 *q; } O;
extern void func_L01_003E1D68(O *);
extern void func_L01_003E1DC0(O *);
extern void func_L01_003E1F08(O *);
extern s32 func_0040DFC0(void *);
extern void func_00439300(O *);

void func_L01_003E1CD0(O *a) {
    s32 *q;
    u8 k = a->k;
    q = a->q;
    switch (k) {
    case 0:
        func_L01_003E1D68(a);
        break;
    case 1:
        break;
    case 2:
        if (func_0040DFC0(q + 2)) {
            func_L01_003E1F08(a);
        }
        break;
    case 3:
        func_L01_003E1DC0(a);
        break;
    case 4:
        func_00439300(a);
        break;
    }
}
