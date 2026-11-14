#include "common.h"

/* NTSC-U counterpart of func_L39_005A5010 (src/levels/shared/L39_005A5000.c) */
/* localdecomp:start func_L39_005A33A0 */
__asm__(".extern D_L39_0024BF78, 16");
__asm__(".extern D_L39_0024BF74, 16");
__asm__(".extern D_L39_0024057C, 16");
__asm__(".extern D_L39_00240578, 16");
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
extern S_5A5010 D_001A4560;
extern char D_L39_0024BF78;
extern int D_L39_0024BF74;
extern int D_L39_0024057C;
extern int D_L39_00240578;
extern int D_001D4CE8_sda_005A33A0 __attribute__((section(".sdata")));
extern void (*D_L39_00499378[])(void);

void func_L39_005A33A0(void) {
    int old;
    if (D_001A4560.f16c != 0 || (D_001A4560.f08 == 2 && D_001A4560.f10 != 0) || D_001A4560.f24 > 0)
        D_L39_0024BF78 = 1;
    old = D_001D4CE8_sda_005A33A0;
    if (D_L39_0024057C & 0x80) {
        D_L39_00240578 = 24;
        D_L39_0024057C = (D_L39_0024057C & ~0x80) | 0x40;
    }
    if (D_L39_0024057C & 0x100) {
        D_L39_00240578 = 22;
        D_L39_0024057C = (D_L39_0024057C & ~0x100) | 0x40;
    }
    D_L39_00499378[D_L39_00240578]();
    D_L39_0024BF74++;
    if (D_L39_00240578 != old)
        D_L39_0024BF74 = 0;
}
/* localdecomp:end func_L39_005A33A0 */
