/* func_L19_003D26C0: 1 instruction off (sqc2 position); needs -mvu0-use-vf0-vf2 on L19_003D26C0.c */
#include "vu0.h"

extern void func_L19_003D2A40(void *, vu0_v4);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L19_003D2BF8();

void func_L19_003D26C0(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    vu0_v4 t;
    switch (a[0x20]) {
    case 0:
        a[0x20] = 1;
    case 1:
        t = *(vu0_v4 *)(a + 0x10);
        vec_add_ba(a + 0x10, s, a + 0x10);
        func_L19_003D2A40(a, t);
        if (func_0038CAD0(s + 0x10)) {
            a[0x20] = 2;
        }
        break;
    case 2:
        func_003C2880(a);
        return;
    }
    func_L01_00404A10(func_L19_003D2BF8, a);
}
