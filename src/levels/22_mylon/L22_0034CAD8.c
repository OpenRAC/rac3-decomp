#include "common.h"

/* localdecomp:start func_L22_0034CAD8 */
extern s32 D_L22_001F2D80[];
extern s32 D_L22_001E17C8;
__asm__(".extern D_L22_001E17C8, 16");
extern s32 D_L22_001DF8C0;
__asm__(".extern D_L22_001DF8C0, 16");
extern void func_L22_0044A390(void *, s32, s32);
extern void func_L22_0040A500(void *, void *);
extern void func_L22_0034CBD8(char *);

/* from rac2-decomp's func_L11_0045B5C8 */
void func_L22_0034CAD8(char *p) {
    char *q = *(char **)(p + 0x68);
    u16 c;
    s32 v;
    s32 old;
    s32 current;
    if (D_L22_001F2D80[0] != 0) {
        return;
    }
    switch (*(u8 *)(p + 0x20)) {
    case 0:
        *(u8 *)(p + 0x30) = 0xFF;
        func_L22_0044A390(p, 1, -1);
        *(s32 *)(q + 0x0) = 0x1000000;
        *(s32 *)(q + 0x8) = 1;
        *(s32 *)(q + 0x4) = 1;
        break;
    case 1:
        if (*(u16 *)(p + 0x96) >= 0x2D) {
            *(u16 *)(p + 0x96) = 0;
            *(s32 *)(q + 0x4) = -*(s32 *)(q + 0x4);
        }
        v = *(s32 *)(q + 0x8) + *(s32 *)(q + 0x4);
        old = D_L22_001E17C8;
        current = D_L22_001DF8C0;
        *(s32 *)(q + 0x0) = v << 24;
        *(s32 *)(q + 0x8) = v;
        if (old != current) {
            D_L22_001E17C8 = current;
            func_L22_0040A500(func_L22_0034CBD8, p);
        }
        break;
    }
    c = *(u16 *)(p + 0x96);
    if (c <= 0xFFFE) {
        *(u16 *)(p + 0x96) = c + 1;
    }
}
/* localdecomp:end func_L22_0034CAD8 */

INCLUDE_ASM("asm/levels", func_L22_0034CBD8);
