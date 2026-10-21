#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3D6C70.c's earlier functions (tools/port_from_us.py) */
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6F78;
extern s32 D_001D4BD4_003D6F78;

/* localdecomp:start func_003D72A0 */
void func_003D72A0(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12) {
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a2 - 1) << 16) | ((long)(a3 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 13) | ((long)a4 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x4400000000008001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x306;
    *(*pp)++ = a9 | ((long)a10 << 8) | ((long)a11 << 16) | ((long)a12 << 24);
    *(*pp)++ = a5 | ((long)a6 << 16);
    *(*pp)++ = a7 | ((long)a8 << 16);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D72A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D7430);

/* localdecomp:start func_003D7438 */
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D7438(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17, s32 a18) {
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a8 - 1) << 16) | ((long)(a9 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 8) | ((long)a4 << 14) | ((long)a5 << 26) | ((long)a6 << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a7 >> 13) | ((long)a10 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_003D6E98(pp, a11, a12, a15, a16, a13, a14, a17, a18);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D7438 */
