#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003AF048 */
extern f32 func_L01_0040E4C0(u8 *);
extern void func_0038CF68(void *, void *, f32);

void func_L13_003AF048(u8 *a0, f32 f12, f32 f13, f32 f14) {
    u8 *p = a0 + 0xA0;
    f32 r;

    *(f32 *)(a0 + 0x20) = f13;
    *(f32 *)(a0 + 0x24) = f14;
    *(f32 *)(a0 + 0x28) = f12;
    r = func_L01_0040E4C0(p);
    if (f12 * f12 < r) {
        func_0038CF68(p, p, f12);
    }
}
/* localdecomp:end func_L13_003AF048 */

/* localdecomp:start func_L13_003AF0B0 */
void func_L13_003AF0B0(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f0;
    f32 var_f12;

    var_f12 = fparg0;
    temp_f0 = *(f32 *)((u8 *)arg0 + 0xB4);
    *(f32 *)((u8 *)arg0 + 0x14) = fparg1;
    *(f32 *)((u8 *)arg0 + 0x18) = fparg2;
    *(f32 *)((u8 *)arg0 + 0x1C) = var_f12;
    if ((var_f12 < temp_f0) || (var_f12 = -var_f12, (temp_f0 < var_f12))) {
        *(f32 *)((u8 *)arg0 + 0xB4) = var_f12;
    }
}
/* localdecomp:end func_L13_003AF0B0 */

INCLUDE_ASM("asm/levels", func_L13_003AF0E8);

/* localdecomp:start func_L13_003AF260 */
extern u8 *D_L13_001DF59C;
extern s32 func_L01_00445AD0(s32, s32, s32);

s32 func_L13_003AF260(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 104);
    u8 *m;

    if (*(s32 *)(p + 996) != 0) {
        *(s32 *)(p + 996) = 0;
        return 1;
    }
    if (*(s16 *)(p + 324) != 1) {
        return 0;
    }
    if (*(s32 *)(p + 924) != -1) {
        m = D_L13_001DF59C + (*(s32 *)(p + 924) << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            return 0;
        }
    }
    if (*(s32 *)(p + 920) != -1 && func_L01_00445AD0(*(s32 *)(p + 920), -1, 0) != 0) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L13_003AF260 */
