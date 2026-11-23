#include "common.h"

/* localdecomp:start func_L01_00435FC8 */
extern u8 D_001426E0[];

s32 func_L01_00435FC8(s32 a0) {
    return D_001426E0[(a0 >> 3) + 195] & (1 << (a0 & 7));
}
/* localdecomp:end func_L01_00435FC8 */

/* localdecomp:start func_L01_00435FF0 */
extern unsigned char D_001426E0[];
void func_L01_00435FF0(int a) {
    D_001426E0[(a >> 3) + 195] |= 1 << (a & 7);
}
/* localdecomp:end func_L01_00435FF0 */

/* localdecomp:start func_L01_00436020 */
extern void func_003AC638(char *, unsigned int, unsigned int, float, float, float, float);
extern s32 D_L01_001D67C8;

void func_L01_00436020(s32 arg0, s32 arg1, float top, float bottom, float left, float right) {
    s32 a;
    s32 b;
    a = arg0;
    b = arg1;
    if (D_L01_001D67C8 != 0) {
        func_003AC638((char *)(D_L01_001D67C8 + 0x1FCA8), a, b, top, bottom, left, right);
    }
}
/* localdecomp:end func_L01_00436020 */

LINKER_REMNANT("asm/levels", func_L01_00436068);

/* localdecomp:start func_L01_00436070 */
extern s32 D_L01_001D67C8;
typedef struct { s32 a; s32 b; } GePair;
typedef struct { u8 pad[0x24E10]; GePair e[3]; } GeBig;
s32 func_L01_00436070(s32 a, s32 b, u32 i) {
    GeBig *p = (GeBig *)D_L01_001D67C8;
    if (p != 0 && i < 3) {
        p->e[i].a = a;
        p->e[i].b = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00436070 */

/* localdecomp:start func_L01_004360B8 */
extern s32 D_L01_001D67C8;
__asm__(".extern D_L01_001D67C8, 4");

typedef struct { s32 a; s32 b; } P8;
typedef struct { u8 pad[0x24E10]; P8 arr[3]; } Big;

void func_L01_004360B8(u32 i) {
    if (i < 3) {
        Big *b = (Big *)D_L01_001D67C8;
        b->arr[i].a = 0;
        b->arr[i].b = 0;
    }
}
/* localdecomp:end func_L01_004360B8 */

LINKER_REMNANT("asm/levels", func_L01_004360E8);
