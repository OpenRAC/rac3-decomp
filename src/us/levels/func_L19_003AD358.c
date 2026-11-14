#include "common.h"

/* NTSC-U counterpart of func_L19_003AEFA8 (src/levels/shared/L19_003ADE70.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_003AD358 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0xC];
    s32 ids[8];
    u8 quads[0x80];
} P_003AD358;

extern void func_L01_00441FB8(void *, s32, s32);
extern u8 *D_L19_001DF71C_003AD358;

void func_L19_003AD358(u8 *obj)
{
    P_003AD358 *p = *(P_003AD358 **)(obj + 0x68);
    s32 i;
    s32 *src;
    u8 *dst;

    p->f8 = (s32)((f32)p->f8 * 60.0f);
    p->f10 = -1;
    i = 0;
    if (p->ids[0] >= 0) {
        src = p->ids;
        dst = p->quads;
        do {
            i++;
            *(u128_t *)dst = *(u128_t *)((*src << 8) + (s32)D_L19_001DF71C_003AD358 + 0x10);
            src++;
            dst += 16;
        } while (i < 8 && *src >= 0);
    }
    p->fC = i;
    if (p->f0 != 0) {
        func_L01_00441FB8(obj, 3, -1);
        p->f4 = p->f8;
    } else {
        func_L01_00441FB8(obj, 1, -1);
        p->f4 = 0;
    }
}
/* localdecomp:end func_L19_003AD358 */
