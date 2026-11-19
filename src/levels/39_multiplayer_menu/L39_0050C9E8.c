#include "common.h"

/* localdecomp:start func_L39_0050C9E8 */
typedef struct {
    char _p0[0x30];
    u8 *f30;
} S_0050C9E8;
typedef struct {
    u8 *f0;
    u32 f4;
} O_0050C9E8;

s32 func_L39_0050C9E8(S_0050C9E8 *s, O_0050C9E8 *out, u32 n) {
    u8 *p = s->f30;
    u32 i;

    if (p[0] != 0 || p[1] != 1) {
        return 0x20C;
    }
    for (i = 2; i < n; i++) {
        if (p[i] != 0xFF) {
            break;
        }
    }
    i++;
    if (i > n || p[i - 1] != 0) {
        return 0x20C;
    }
    out->f4 = n - i;
    out->f0 = s->f30 + i;
    return 0;
}
/* localdecomp:end func_L39_0050C9E8 */

LINKER_REMNANT("asm/levels", func_L39_0050CA78);

/* localdecomp:start func_L39_0050CA80 */
s32 func_L39_0050CA80(s32 err) {
    if (err == 0) {
        return 0;
    }
    switch (err) {
    case 0x64:
    case 0x65:
    case 0x1F4:
    case 0x1F5:
    case 0x1F7:
    case 0x1F8:
    case 0x1FB:
    case 0x3EA:
    case 0x3EF:
    case 0x3F1:
    case 0x3F2:
    case 0x3F3:
    case 0x3F4:
    case 0x4B1:
    case 0x4B2:
    case 0x4B3:
        return 5;
    case 0x101:
    case 0x102:
    case 0x103:
    case 0x104:
        return 5;
    case 0x105:
        return 5;
    case 0x1F9:
    case 0x3F0:
        return 10;
    case 0x100:
        return 0x10;
    case 0x106:
        return 5;
    case 0x107:
        return 7;
    case 0x108:
        return 5;
    case 0x109:
        return 5;
    case 0x10A:
        return 5;
    case 0x10B:
        return 5;
    case 0x10C:
        return 10;
    case 0x3E9:
        return 0x10;
    }
    return err;
}
/* localdecomp:end func_L39_0050CA80 */
