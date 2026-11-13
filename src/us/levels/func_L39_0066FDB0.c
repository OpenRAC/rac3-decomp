#include "common.h"

/* NTSC-U counterpart of func_L39_00672700 (src/levels/shared/L39_00672700.c) */
/* localdecomp:start func_L39_0066FDB0 */
extern s32 D_001A6F10[];
extern u32 D_L39_00481168[];

s32 func_L39_0066FDB0(void) {
    s32 crc = -1;
    s32 *pc;
    s32 start = (s32)D_001A6F10;
    s32 end = start + 0x1D4;
    s32 r;
    u32 *p;
    u32 c;

    r = start % 16;
    if (r != 0) {
        start += 16 - r;
    }
    r = end % 16;
    if (r != 0) {
        end = end - r;
    }
    pc = &crc;
    c = (u32)*pc;
    for (p = (u32 *)start; p < (u32 *)end; p++) {
        c ^= *p;
        c = (c >> 8) ^ D_L39_00481168[c & 0xFF];
        c = (c >> 8) ^ D_L39_00481168[c & 0xFF];
        c = (c >> 8) ^ D_L39_00481168[c & 0xFF];
        c = (c >> 8) ^ D_L39_00481168[c & 0xFF];
    }
    *pc = c;
    return crc;
}
/* localdecomp:end func_L39_0066FDB0 */
