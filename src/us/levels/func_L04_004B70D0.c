#include "common.h"

/* localdecomp:start func_L04_004B70D0 */
typedef int s128_004B70D0 __attribute__((mode(TI)));

typedef struct {
    u8 pad00[8];
    f32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0x24];
    s128_004B70D0 q40;
    s128_004B70D0 q50;
} S_004B70D0;

void func_L04_004B70D0(S_004B70D0 *o, u32 which, void *src) {
    switch (which) {
    case 3:
        o->f0C = *(s32 *)src;
        break;
    case 0:
        o->q40 = *(s128_004B70D0 *)src;
        break;
    case 1:
        o->q50 = *(s128_004B70D0 *)src;
        break;
    case 2:
        o->f08 = *(f32 *)src;
        break;
    case 4:
        o->f10 = *(s32 *)src;
        break;
    case 5:
        o->f14 = (s32)src;
        break;
    case 6:
        o->f18 = *(s32 *)src;
        break;
    }
}
/* localdecomp:end func_L04_004B70D0 */
