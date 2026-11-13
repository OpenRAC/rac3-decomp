#include "common.h"

/* localdecomp:start func_L28_003420C0 */
__asm__(".extern D_L28_001DECA0, 16");
__asm__(".extern D_L28_001DEC9C, 16");
__asm__(".extern D_001D545C, 16");
extern u8 *D_L28_001DECA0;
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DCF18, 4");
extern s32 D_L28_001DCF18;
extern s32 D_001D545C;
extern u8 D_L28_00234EE4[];
extern u8 D_001BBE90[];
extern s32 func_L28_004104C0(s32);
s32 func_L28_003420C0(void) {
    u8 *p;
    s32 n;
    s32 v;
    u16 h;
    D_L28_001DCF18 = func_L28_004104C0(0x1A9E) + func_L28_004104C0(0x8C4);
    n = 0;
    for (p = D_L28_001DEC9C; p < D_L28_001DECA0; p += 0x100) {
        if (p != 0 && (*(s16 *)(p + 0xAA) == 0x199F || *(s16 *)(p + 0xAA) == 0x19C2) && p[0x20] != 0xFE && p[0x20] != 0xFD) {
            h = *(u16 *)(p + 0xB2);
            if (D_L28_00234EE4[(s16)h] == 0) {
                v = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)]; if ((((h & 1) ? v >> 4 : v) & 7) == 0) n++;
            }
        }
    }
    D_L28_001DCF18 += n;
    return D_L28_001DCF18;
}
/* localdecomp:end func_L28_003420C0 */

INCLUDE_ASM("asm/levels", func_L28_003421E0);
