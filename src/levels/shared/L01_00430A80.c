#include "common.h"

/* localdecomp:start func_L01_00430A80 */
extern void func_L01_00430D28(u8 *dst, u8 *src);
extern s32 D_L01_001F3FC8[];
extern void func_L01_00431808_00430A80(s32 a0, u8 *a1, s32 a2);
extern void func_L01_00430AF8(s32 a0, u8 *a1, s32 a2);
void func_L01_00430A80(s32 a0, u8 *a1, s32 a2) {
    func_L01_00431808_00430A80(a0, a1, a2);
    if (D_L01_001F3FC8[0] != 0) {
        if (a1[0] & 1) {
            func_L01_00430AF8(a0, a1, a2);
        } else {
            ((void (*)(s32 a0, u8 *a1))func_L01_00430D28)(a0, a1);
        }
    }
}
/* localdecomp:end func_L01_00430A80 */

INCLUDE_ASM("asm/levels", func_L01_00430AF8);

/* localdecomp:start func_L01_00430D28 */
extern void func_0038CD28(u8 *, u32 *, s32);

void func_L01_00430D28(u8 *dst, u8 *src) {
    u32 table[256];
    u32 buf[16];
    s32 k;
    s32 i;
    s32 j;

    for (i = 0; i < 256; i++) {
        table[i] = 0;
        if (i & 1) table[i] = 0xF;
        if (i & 2) table[i] |= 0xF0;
        if (i & 4) table[i] |= 0xF00;
        if (i & 8) table[i] |= 0xF000;
        if (i & 0x10) table[i] |= 0xF0000;
        if (i & 0x20) table[i] |= 0xF00000;
        if (i & 0x40) table[i] |= 0xF000000;
        if (i & 0x80) table[i] |= 0xF0000000;
    }
    for (k = 0; k < 128; k++) {
        u32 *q = buf;
        for (j = 0; j < 16; j++) {
            *q++ = table[*src++];
        }
        func_0038CD28(dst, buf, 64);
        dst += 64;
        func_0038CD28(dst, buf, 64);
        dst += 64;
        func_0038CD28(dst, buf, 64);
        dst += 64;
        func_0038CD28(dst, buf, 64);
        dst += 64;
    }
}
/* localdecomp:end func_L01_00430D28 */

LINKER_REMNANT("asm/levels", func_L01_00430EF8);
