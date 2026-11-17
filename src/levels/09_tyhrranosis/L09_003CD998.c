#include "common.h"

typedef struct {
    u8 pad[4];
    s32 (*f4)(void *);
    s32 (*f8)(void *);
} V_003CDA30;


/* localdecomp:start func_L09_003CD998 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L09_003CD998(void *arg0, s32 arg1) {
    s32 var_v0;

    if (((*(u8 *)((u8 *)arg0 + 0x20)) == 1) || (var_v0 = 0, (arg1 != 0))) {
        *(s8 *)((u8 *)arg0 + 0xBC) = 0;
        if (arg1 == 0) {
            func_L01_004450F0((s32) arg0, 2, -1);
        } else {
            func_L01_004450F0((s32) arg0, 3, -1);
        }
        var_v0 = 1;
    }
    return var_v0;
}
/* localdecomp:end func_L09_003CD998 */

/* localdecomp:start func_L09_003CD9F0 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L09_003CD9F0(u8 *a) {
    if (a[0x20] == 3) {
        a[0xBC] = 0;
        func_L01_004450F0((s32)a, 4, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L09_003CD9F0 */

/* localdecomp:start func_L09_003CDA30 */
extern u16 *D_L09_0021CDA0[];
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern s32 D_L09_001E00D8_sda;
extern V_003CDA30 *func_L01_0043B568(s32, s32, s32);

void func_L09_003CDA30(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;
    V_003CDA30 *v;
    for (p = D_L09_0021CDA0[*(s32 *)(s + 0x10)];
         (*(s32 *)(s + 0x10) & 0xFF) != 0xFF && *(s32 *)(s + 0x10) <= D_L09_001E00D8_sda && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L09_0021CDA0[*(s32 *)(s + 0x10)]);
         p++) {
        e = D_L09_001E009C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        v = func_L01_0043B568(*(s16 *)(e + 0xAA), 5, 0xC);
        if (v != 0) {
            if (v->f8(e) == 0) {
                v->f4(e);
            }
        }
    }
}
/* localdecomp:end func_L09_003CDA30 */
