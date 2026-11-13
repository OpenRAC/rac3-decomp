#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005A5000);

/* localdecomp:start func_L39_005A5010 */
__asm__(".extern D_L39_0024BE78, 16");
__asm__(".extern D_L39_0024BE74, 16");
__asm__(".extern D_L39_002403FC, 16");
__asm__(".extern D_L39_002403F8, 16");
typedef struct {
    char pad00[8];
    int f08;
    char pad0c[4];
    int f10;
    char pad14[0x10];
    int f24;
    char pad28[0x144];
    int f16c;
} S_5A5010;
extern S_5A5010 D_001A43E0;
extern char D_L39_0024BE78;
extern int D_L39_0024BE74;
extern int D_L39_002403FC;
extern int D_L39_002403F8;
extern int D_001D4CE8_sda __attribute__((section(".sdata")));
extern void (*D_L39_004992B8[])(void);

void func_L39_005A5010(void) {
    int old;
    if (D_001A43E0.f16c != 0 || (D_001A43E0.f08 == 2 && D_001A43E0.f10 != 0) || D_001A43E0.f24 > 0)
        D_L39_0024BE78 = 1;
    old = D_001D4CE8_sda;
    if (D_L39_002403FC & 0x80) {
        D_L39_002403F8 = 24;
        D_L39_002403FC = (D_L39_002403FC & ~0x80) | 0x40;
    }
    if (D_L39_002403FC & 0x100) {
        D_L39_002403F8 = 22;
        D_L39_002403FC = (D_L39_002403FC & ~0x100) | 0x40;
    }
    D_L39_004992B8[D_L39_002403F8]();
    D_L39_0024BE74++;
    if (D_L39_002403F8 != old)
        D_L39_0024BE74 = 0;
}
/* localdecomp:end func_L39_005A5010 */
