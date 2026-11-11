/* near miss (level 28): 21 diff with --as ps2as; all instructions in retail's order, but gcc turns the two small ifs of the nibble test into movn/movz (n++ and the h&1 shift) where retail has branches (beql/beqz), the u8 local that stops one of them makes it srl instead of sra, and p/h swap $a3/$a2; needs @ps2as for the file (inline float-free but the $gp global D_001DCF18 is written before the loop) */
#include "common.h"

/* localdecomp:start func_L28_003420C0 */
extern u8 *D_L28_001DECA0;
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DECA0, 16");
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_001DCF18;
__asm__(".extern D_001DCF18, 4");
extern s32 D_001D545C_003420C0;
__asm__(".extern D_001D545C_003420C0, 16");
extern u8 D_L28_00234EE4[];
extern u8 D_001BBE90[];
extern s32 func_L28_004104C0(s32);
s32 func_L28_003420C0(void) {
    u8 *p;
    s32 n;
    u8 v;
    u16 h;
    D_001DCF18 = func_L28_004104C0(0x1A9E) + func_L28_004104C0(0x8C4);
    n = 0;
    for (p = D_L28_001DEC9C; p < D_L28_001DECA0; p += 0x100) {
        if (p != 0 && (*(s16 *)(p + 0xAA) == 0x199F || *(s16 *)(p + 0xAA) == 0x19C2) && p[0x20] != 0xFE && p[0x20] != 0xFD) {
            h = *(u16 *)(p + 0xB2);
            if (D_L28_00234EE4[(s16)h] == 0) {
                v = D_001BBE90[((s16)h >> 1) + (D_001D545C_003420C0 << 10)];
                if (h & 1) v = v >> 4;
                if ((v & 7) == 0) n++;
            }
        }
    }
    D_001DCF18 += n;
    return D_001DCF18;
}
/* localdecomp:end func_L28_003420C0 */
