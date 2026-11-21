#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern s32 D_001A1ED4[];
extern s32 D_001DA0C0_003B0BB8[2];
extern void func_003A1028_003B0BB8(s32, s32);
/* localdecomp:start func_003B0BB8 */
extern s32 D_001A1ED4[];
extern void func_003A1028_003B0BB8(s32, s32);
void func_003B0BB8(unsigned long *p, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i, j;
    s32 h = a3 >> 4;
    s32 w = a4 >> 4;
    p[0] = 0x10000003;
    p[1] = 0;
    p[2] = 0x1000000000000002UL;
    p[3] = 0xE;
    p[4] = (((long)D_001A1ED4[0] >> 8) << 32) | 0x8000000000000L;
    p[5] = 0x50;
    p[6] = 0x1000000010UL;
    p[7] = 0x52;
    p += 8;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            p[0] = 0x10000004;
            p[1] = 0;
            p[2] = 0x1000000000000002UL;
            p[3] = 0xE;
            p[4] = ((unsigned long)(j << 4) << 32) | ((unsigned long)(i << 4) << 48);
            p[5] = 0x51;
            p[6] = 0;
            p[7] = 0x53;
            p[8] = 0x800000000000040UL;
            p[9] = 0;
            ((u32 *)p)[20] = 0x30000040;
            ((u32 *)p)[21] = a1 & 0xFFFFFFF;
            p[11] = 0;
            a1 += 0x400;
            p += 12;
        }
    }
    {
    s32 *q = (s32 *)((a2 << 2) + (s32)D_001DA0C0_003B0BB8);
    ((u32 *)p)[0] = 0x20000000;
    ((u32 *)p)[1] = *q;
    ((u32 *)p)[2] = 0;
    ((u32 *)p)[3] = 0;
    func_003A1028_003B0BB8((*q & 0xFFFFFFF) | 0x20000000, 1);
    }
}
/* localdecomp:end func_003B0BB8 */
