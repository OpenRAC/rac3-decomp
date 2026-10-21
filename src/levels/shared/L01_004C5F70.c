#include "common.h"

/* localdecomp:start func_L01_004C5F70 */
extern void func_0012CB88(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_0011F0A0(s32);
extern void func_0012CE48(void *, s32);
extern void func_0012A9F0(s32, s32);

void func_L01_004C5F70(s32 dst, s32 src, s32 size) {
    u8 buf[112];
    s32 n = (size + 16383) & ~16383;
    s32 s = 0;
    s32 d = 0;

    while (n > 0) {
        func_0012CB88(buf, (src + s) >> 8, 1, 1, 0, 0, 64, 64);
        s += 16384;
        func_0011F0A0(0);
        func_0012CE48(buf, dst + d);
        d += 12288;
        func_0012A9F0(0, 0);
        n -= 16384;
    }
}
/* localdecomp:end func_L01_004C5F70 */

/* localdecomp:start func_L01_004C6030 */
extern u32 *D_L01_001E1068;
extern void func_0012C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
void func_L01_004C6030(s32 a0, s32 a1, s32 size) {
    s32 n;
    s32 dst = 0;
    s32 src = 0;
    n = (size + 0x3FFF) & ~0x3FFF;
    while (n > 0) {
        D_L01_001E1068[0] = 0x10000006;
        D_L01_001E1068[1] = 0;
        D_L01_001E1068[2] = 0;
        D_L01_001E1068[3] = 0x50000006;
        D_L01_001E1068 += 4;
        func_0012C9A0(D_L01_001E1068, (a1 + dst) >> 8, 1, 1, 0, 0, 64, 64);
        dst += 0x4000;
        n -= 0x4000;
        D_L01_001E1068 = (u32 *)((u8 *)D_L01_001E1068 + 0x60);
        D_L01_001E1068[0] = 0x30000300;
        D_L01_001E1068[1] = a0 + src;
        D_L01_001E1068[2] = 0;
        D_L01_001E1068[3] = 0x50000300;
        D_L01_001E1068 += 4;
        src += 0x3000;
    }
}
/* localdecomp:end func_L01_004C6030 */
