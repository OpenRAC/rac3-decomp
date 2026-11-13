#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005F3E38);

INCLUDE_ASM("asm/levels", func_L39_005F3E58);

/* localdecomp:start func_L39_005F40B8 */
extern s32 D_00240248[10] __attribute__((section(".sdata")));
extern void func_00129490(s32);
extern s32 func_00129C38(void *, s32, s32);
extern s32 func_0012A018(void *);
extern s32 func_00129E18(void *, s32, s32, s32, s32, void *, s32, s32, s32);

void func_L39_005F40B8(void) {
    s32 buf[4];
    s32 i;

    func_00129490(0);
    while (1) {
        if (func_00129C38(D_00240248, 0x11, 1) < 0) {
            while (1) {
            }
        }
        while (func_0012A018(D_00240248) != 0) {
        }
        if (D_00240248[9] != 0) {
            break;
        }
        i = 0xFFFF;
        while (--i != -1) {
        }
    }
    func_00129E18(D_00240248, 2, 0, 0, 0, buf, 0x10, 0, 0);
}
/* localdecomp:end func_L39_005F40B8 */

/* localdecomp:start func_L39_005F4188 */
typedef struct {
    int start;       
    int end;         
    int pad[10];     
    int cursor;      
    int count;       
} LevelQueue5a29d35d;
extern LevelQueue5a29d35d D_00240240 __attribute__((section(".sdata")));
extern char D_L39_002B9220[];
extern int func_00126620(int *dma, int flag);

/* from rac2-decomp's func_002EED58, renamed */
int func_L39_005F4188(int p0, int p1, int p2, int p3)
{
    int args[4];
    int n, k;
    if (D_00240240.end - (D_00240240.cursor - D_00240240.start) < p2 * 16)
        return -1;
    if (D_00240240.count == 64)
        return -2;
    args[0] = p0;
    args[1] = D_00240240.cursor;
    args[2] = p1 * 16;
    args[3] = 0;
    func_00126620(args, 1);
    n = D_00240240.count;
    k = n;
    n = n + 1;
    D_00240240.count = n;
    *(int *)(D_L39_002B9220 + k * 16) = D_00240240.cursor;
    *(int *)(D_L39_002B9220 + k * 16 + 4) = p2;
    *(int *)(D_L39_002B9220 + k * 16 + 8) = p3;
    D_00240240.cursor = D_00240240.cursor + p2 * 16;
    return k;
}
/* localdecomp:end func_L39_005F4188 */
