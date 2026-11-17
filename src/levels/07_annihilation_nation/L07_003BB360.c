#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;


/* localdecomp:start func_L07_003BB360 */
extern u8 D_001A4C60[];
s32 func_00382380(void *, s32, s32);

void func_L07_003BB360(void *arg0) {
    u8 *p;
    s32 *q;
    s32 i;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    *(u16 *)(p + 0xA0) = 0;
    q = (s32 *)(p + 0x50);
    i = 0;
    do {
        do {
            if (((((*(s16 *)(p + 0xA2)) >> i) ^ 1) & 1) != 0) {
                if (func_00382380(D_001A4C60, *q, 0) != 0) {
                    *(u16 *)(p + 0xA0) |= (1 << i);
                }
            }
        } while (0);
        i++;
        q++;
    } while (i < 16);
    *(u16 *)(p + 0xA2) |= *(u16 *)(p + 0xA0);
}
/* localdecomp:end func_L07_003BB360 */
