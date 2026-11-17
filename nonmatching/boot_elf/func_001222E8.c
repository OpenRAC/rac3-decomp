/* NTSC-U draft (Claude wave E): C of func_001222E8 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 31 words differ on NTSC-U with the file's flags (NTSC-U twin "func_001222E8").
 * Study aid: it uses inline asm for EE instructions (move), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: 31 diff with `@ee29 -O2 -G0` (16-byte slots, $ra first; 0x121D70 line is SN) and gp-switching asm like func_0012ADC8/func_00135DC8 (two `__asm__ __volatile__("move %0, $28
 */
#include "common.h"

/* localdecomp:start func_001222E8 */
typedef struct {
    void *x0;
    s32 x4;
    s32 x8;
    u8 padC[8];
    s32 x14;
    s32 x18;
    s32 (*x1C)(s32);
    s32 x20;
    s32 x24;
} Q_1222E8;
typedef struct {
    u8 pad[0x1C];
    Q_1222E8 *x1C;
    u32 x20;
    s32 x24;
    s32 x28;
} P_1222E8;
extern void func_0011EE50(s32);
void func_001222E8(P_1222E8 *p) {
    Q_1222E8 *q = p->x1C;
    switch (p->x20) {
    case 0x8000000B:
    case 0x8000000C:
        break;
    case 0x8000000A:
        if (q->x1C != 0) {
            s32 old;
            s32 cur;
            __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(old) : "r"(q->x18) : "memory");
            q->x1C(q->x20);
            __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(cur) : "r"(old));
            q = p->x1C;
        }
        break;
    case 0x80000009:
        q->x24 = p->x24;
        q->x14 = p->x28;
        break;
    }
    if (q->x8 >= 0) {
        func_0011EE50(q->x8);
    }
    func_00122258(q->x0);
    q->x0 = 0;
}
/* localdecomp:end func_001222E8 */
