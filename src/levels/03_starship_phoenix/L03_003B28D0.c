#include "common.h"

/* localdecomp:start func_L03_003B28D0 */
typedef struct S_003B28D0 { char pad[0x128]; s32 f128; s32 f12C; } S_003B28D0;
typedef struct O_003B28D0 { char p0[0x20]; u8 k20; char p1[0x10]; u8 k31; char p2[2]; u16 f34; char p3[0x0D]; u8 k43; char p4[0x1C]; u8 k60; char p5[7]; S_003B28D0 *p68; } O_003B28D0;
extern u8 D_00142CBE[];
__asm__(".extern D_00142CBE, 16");
extern s32 D_L03_001D6694;
__asm__(".extern D_L03_001D6694, 16");

void func_L03_003B2B30(O_003B28D0 *);

void func_L03_003B28D0(O_003B28D0 *o) {
    S_003B28D0 *p = o->p68;
    switch (o->k20) {
    case 0:
        if (p->f12C != 0 || D_00142CBE[0] == 0) {
            if (o->k43 != 1) func_003C3A10(o, 1, 0, 8);
            func_L01_004450F0(o, 2, -1);
        } else {
            func_003C2880(o);
            return;
        }
    case 2:
        if (func_L01_004561B8(o) != 0) {
            if (o->k43 != 1) func_003C3A10(o, 1, 0, 8);
            p->f128 = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
        }
        if (func_0038CAD0(&p->f128) != 0) {
            p->f128 = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
            if (o->k43 != 2) {
                func_003C3A10(o, 2, 0, 0x11);
            }
        } else if ((o->k60 & 2) && o->k43 != 1) {
            func_003C3A10(o, 1, 0, 0x11);
        }
        break;
    case 4:
        if (func_L01_004561B8(o) != 0 && o->k43 != 3) {
            func_003C3A10(o, 3, 0, 8);
        }
        break;
    case 3:
        if (func_L01_004561B8(o) != 0 && o->k43 != 4) {
            func_003C3A10(o, 4, 0, 8);
        }
        break;
    case 5:
        if (func_L01_004561B8(o) != 0 && o->k43 != 5) func_003C3A10(o, 5, 0, 8);
        break;
    }
    if (D_L03_001D6694 == 2) {
        o->k31 = 0;
        o->f34 |= 1;
    } else {
        if (func_L01_004BA800() == 0) {
            o->k31 = 1;
            o->f34 &= 0xFFFE;
        }
        func_L03_003B2B30(o);
    }
}
/* localdecomp:end func_L03_003B28D0 */
