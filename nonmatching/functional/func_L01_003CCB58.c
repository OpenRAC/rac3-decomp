/* functional: high. 43 instructions differ (scheduling and branch layout); same calls and state changes. */
#include "vu0.h"
extern void func_L01_003CCED8(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_003CD068(void *);

void func_L01_003CCB58(u8 *obj) {
    vu0_v4 old;
    u8 *st = *(u8 **)(obj + 0x68);
    s32 s = obj[0x20];
    if (s == 0 || s == 1) {
        if (s == 0) obj[0x20] = 1;
        *(vu0_q *)&old = *(vu0_q *)(obj + 0x10);
        vec_add_ab(obj + 0x10, st, obj + 0x10);
        func_L01_003CCED8(obj, &old);
        if (func_0038CAD0(st + 0x10)) obj[0x20] = 2;
    } else if (s == 2) {
        func_003C2880(obj);
        return;
    }
    func_L01_00404A10((void *)func_L01_003CD068, obj);
}
