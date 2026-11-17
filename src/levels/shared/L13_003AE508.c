#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003AE508 */
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
} T_003AE508;
typedef struct {
    u8 pad0[0x47];
    u8 b47;
    T_003AE508 *p48;
    u8 pad4C[0x3E0 - 0x4C];
    void *p3E0;
} S_003AE508;
extern s32 D_001D545C;
extern s32 D_L13_001D67B4;
extern s32 D_L13_001D67C0;
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_L01_004443E8(void *, s32, s32);

void func_L13_003AE508(u8 *m) {
    S_003AE508 *p = *(S_003AE508 **)(m + 0x68);

    if (D_001D545C == 12 && p->p48 != 0 && p->b47 == 9) {
        if (++D_L13_001D67B4 >= 20) {
            func_L01_00459C50(15);
        }
    } else if (D_001D545C == 18 && p->p48 != 0 && p->p48->hAA == 0x185E) {
        if (++D_L13_001D67C0 >= 20) {
            func_L01_00459C50(21);
        }
    }
    if (p->p3E0 != 0) {
        func_003C2880(p->p3E0);
        p->p3E0 = 0;
    }
    func_L01_004443E8(m, 0, 3);
}
/* localdecomp:end func_L13_003AE508 */
