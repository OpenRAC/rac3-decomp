#include "common.h"

/* localdecomp:start func_L19_003357A0 */
typedef struct {
    u8 pad0[0x38];
    s32 w38;
    u8 pad3C[4];
    s32 a40[2][2];
    f32 f50[2][2];
    s32 a60[2][2];
    f32 f70[2][2];
    u8 pad80[0xDC - 0x80];
    s32 wDC;
} S_003357A0;
typedef struct {
    u8 b[0x100];
} E_003357A0;
extern E_003357A0 D_L19_00276F40[];
extern void func_L19_00335898(void *, E_003357A0 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);

/* from rac2-decomp's func_L03_0038AA20 */
void func_L19_003357A0(u8 *m) {
    S_003357A0 *p = *(S_003357A0 **)(m + 0x68);
    s32 i;

    for (i = 0; i < 4; i++) {
        func_L19_00335898(m, &D_L19_00276F40[p->wDC + i], p->w38, p->a40[0][0], p->a60[0][0], p->a40[0][1], p->a60[0][1],
                          p->f50[0][0], p->f70[0][0], p->f50[0][1], p->f70[0][1], 0.9f);
        func_L19_00335898(m, &D_L19_00276F40[p->wDC + i + 4], p->w38, p->a40[1][0], p->a60[1][0], p->a40[1][1], p->a60[1][1],
                          p->f50[1][0], p->f70[1][0], p->f50[1][1], p->f70[1][1], 0.1f);
    }
}
/* localdecomp:end func_L19_003357A0 */
