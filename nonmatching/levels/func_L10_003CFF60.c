/* near miss (level 10, Zeldrin Starport): 1 difference: the jr $ra delay slot (addiu $sp,$sp,0x10) at 0x003D0000 is catalogued as the remnant func_L01_003AE6E0, so the catalogue size (0xA0) cuts it and the C is one instruction longer; every other word is retail's. The inventory takes the delay slot for a start because a data word points at it (tools/inventory.py, the 'after finished code' rule accepts w[k] == jr $ra). Needs @ps2as on its file (float constant built inline) */
#include "common.h"

/* localdecomp:start func_L10_003CFF60 */
typedef struct {
    u8 pad0[0x124];
    s32 f124;
    u8 pad128[0x2A0 - 0x128];
    s16 f2A0;
    u8 f2A2;
    u8 f2A3;
    u8 pad2A4[0x2B8 - 0x2A4];
    f32 f2B8;
    u8 pad2BC[0x2C8 - 0x2BC];
    f32 f2C8;
    u8 pad2CC[0x460 - 0x2CC];
} S_3CFF60;
extern S_3CFF60 D_L10_001E1BC0[];
extern void func_L01_003EAAE8(u8 *);
extern void func_003A52A0(s32, s32, s32);

void func_L10_003CFF60(u8 *m) {
    S_3CFF60 *e = &D_L10_001E1BC0[*(s32 *)(m + 0x94)];
    s16 v;

    if (e->f2A0 != 0) {
        e->f2A0 = 2;
    } else {
        e->f2A0 = 1;
    }
    e->f2A3 = 0;
    (&D_L10_001E1BC0[*(s32 *)(m + 0x94)])->f2C8 = 0.075f;
    D_L10_001E1BC0[*(s32 *)(m + 0x94)].f2B8 = 0.075f;
    func_L01_003EAAE8(m);
    if (e->f124 != 0) {
        func_003A52A0(0, 0, e->f124);
    }
}
/* localdecomp:end func_L10_003CFF60 */
