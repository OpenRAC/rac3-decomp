/* functional: high. Byte-exact (MATCH at levels 39, 40, 50); port of frontbin func_003A9830, GS texture upload DMA packet builder. */
/* localdecomp:start func_L39_005FD458 */
#include "vu0.h"
__asm__(".extern D_L39_0024CAD0, 16");
extern s32 D_L39_0024CAD0;
__asm__(".extern D_L39_0024CAD0_b, 4");
extern s32 D_L39_0024CAD0_b;
extern void func_00139EA0(s32, s16, s16, s16, s16, s16, s16, s16);
long func_L39_005FD458(s32 src, s32 dst, s32 w, s32 h) {
    s32 tw, th, t, t2, t3;
    s32 size, chunk, i;
    s32 p;
    t = plzcw_asm(w);
    tw = 0x1E - t;
    if (w & (w - 1)) tw++;
    chunk = w << 7;
    t2 = plzcw_asm(h);
    th = 0x1E - t2;
    if (h & (h - 1)) th++;
    size = w * (h << 2);
    t3 = size - 1;
    size = (t3 + chunk) & -chunk;
    i = 0;
    while (size > 0) {
        *(s32 *)(D_L39_0024CAD0 + 0) = 0x10000006;
        *(s32 *)(D_L39_0024CAD0 + 4) = 0;
        *(s32 *)(D_L39_0024CAD0 + 8) = 0;
        *(s32 *)(D_L39_0024CAD0 + 0xC) = 0x50000006;
        size -= chunk;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 0x10;
        func_00139EA0(D_L39_0024CAD0_b, (dst + i) >> 8, w >> 6, 0, 0, 0, w, 0x20);
        p = D_L39_0024CAD0;
        D_L39_0024CAD0 = p + 0x60;
        *(s32 *)(p + 0x60) = (chunk >> 4) | 0x30000000;
        *(s32 *)(D_L39_0024CAD0 + 4) = src + i;
        *(s32 *)(D_L39_0024CAD0 + 8) = 0;
        *(s32 *)(D_L39_0024CAD0 + 0xC) = (chunk >> 4) | 0x50000000;
        i += chunk;
        D_L39_0024CAD0_b = D_L39_0024CAD0 + 0x10;
    }
    return (dst >> 8) | ((long)(w >> 6) << 14) | ((long)tw << 26) | ((long)th << 30) | (0x8000UL << 19);
}
/* localdecomp:end func_L39_005FD458 */
