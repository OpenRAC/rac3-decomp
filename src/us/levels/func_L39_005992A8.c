#include "common.h"

/* NTSC-U counterpart of func_L39_0059A578 (src/levels/shared/L39_0059A578.c) */
/* localdecomp:start func_L39_005992A8 */
typedef struct {
    u8 pad00[0x18];
    s16 f18;
    u8 pad1A[0x17C - 0x1A];
    s32 f17C;
} S_0059A578;
extern S_0059A578 D_001A4560;
extern s32 D_001D71E4_sda_005992A8;
extern s32 D_L39_0024BC40 __attribute__((section(".sdata")));
extern s32 D_L39_0024145C;
__asm__(".extern D_L39_0024145C, 16");
extern s32 D_L39_00240580;
__asm__(".extern D_L39_00240580, 16");
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024057C, 16");
extern void func_L01_003D31A0_005992A8(s32 *);

void func_L39_005992A8(s32 a0) {
    s32 v = a0;
    s32 w;
    func_L01_003D31A0_005992A8(&v);
    w = v;
    D_001D71E4_sda_005992A8 = 1;
    D_L39_00240580 = D_L39_0024145C;
    D_L39_0024BC40 = w;
    if (w == -1) {
        if (D_001A4560.f17C != 0) {
            D_001A4560.f17C = 0;
        }
        if (D_001A4560.f18 >= 0) {
            D_001A4560.f18 = w;
        }
        D_L39_0024057C &= ~0x200;
    }
}
/* localdecomp:end func_L39_005992A8 */
