#include "common.h"

/* NTSC-U counterpart of func_L39_006D4030 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006D18A8 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x24];
    s8 *f3C;
} S_006D4030;
typedef struct {
    char _p0[0x18];
    s32 f18;
    s32 f1C;
} A_006D4030;
void func_0019B6F8(s32);
void func_0019B8D8(s32);

void func_L39_006D18A8(A_006D4030 *arg) {
    S_006D4030 *g = (S_006D4030 *)D_L39_0024D860;
    s8 *p = g->f3C;
    s32 k = arg->f18;

    if (k != 0) {
        switch (k) {
        case -0x3CF:
            g->f10 = 0x2B;
            if (g->f14 == 0) {
                g->f14 = 0x2B;
            }
            break;
        case -0x3C7:
            g->f10 = 3;
            if (g->f14 == 0) {
                g->f14 = 3;
            }
            break;
        default:
            g->f10 = 0x2A;
            if (g->f14 == 0) {
                g->f14 = 0x2A;
            }
            break;
        }
    } else {
        func_0019B6F8(arg->f1C);
        func_0019B8D8(1);
    }
    p[1] = 0;
}
/* localdecomp:end func_L39_006D18A8 */
