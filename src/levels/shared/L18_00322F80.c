#include "common.h"

INCLUDE_ASM("asm/levels", func_L18_00322F80);

/* localdecomp:start func_L18_00323178 */
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA;
} M_00323178;
extern M_00323178 *D_L18_001EAA98 __attribute__((section(".data")));
extern void (**func_L01_0043B568(s32, s32, s32))(void);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L18_00323178(s32 a0, void *a1, void *a2, s32 a3, void *a4, s32 a5) {
    void (**v)(void) = func_L01_0043B568(0x1E6F, 0, 0xC);
    s32 r;
    if (v != 0) {
        v[1]();
    }
    func_L01_004CB320();
    r = func_003D3CB0(a1, a2, a3, a4, a5);
    if (r != 0) {
        M_00323178 *m = D_L18_001EAA98;
        if (m != 0 && m->hAA == 0x186D && m->b20 != 2 && m->b20 != 5) {
            m->b20 = 4;
        }
    }
    func_L01_004CB358();
    if (v != 0) {
        v[2]();
    }
    return r;
}
/* localdecomp:end func_L18_00323178 */

INCLUDE_ASM("asm/levels", func_L18_00323278);

INCLUDE_ASM("asm/levels", func_L18_00323518);

INCLUDE_ASM("asm/levels", func_L18_00323760);
