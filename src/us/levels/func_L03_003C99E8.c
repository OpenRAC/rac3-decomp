#include "common.h"

/* NTSC-U counterpart of func_L03_003CB910 (src/levels/03_starship_phoenix/L03_003CB5E0.c): 2500 -> 3000 */
/* localdecomp:start func_L03_003C99E8 */
typedef struct {
    u8 pad[0x7C];
    s32 f7C;
    u8 pad2[0x0C];
    s32 f8C;
    s32 f90;
} S_003CB910;
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern s16 D_001426A0[];
__asm__(".extern D_001426A0, 16");
extern void func_L01_00456960(s32);
extern s32 func_00382380(void *, s32, s32);

void func_L03_003C99E8(void *a0) {
    S_003CB910 *s = *(S_003CB910 **)((u8 *)a0 + 0x68);
    u8 *t = D_001426E0;
    s32 r;
    if (t[0x4B] >= 100 && t[0x4C] >= 100 && t[0x4D] >= 100 && t[0x4E] >= 100 && t[0x4F] >= 100 && (t[0x51] & 0x3E) == 0x3E) {
        func_L01_00456960(2);
    }
    if (func_00382380(D_001A4C60, s->f8C, 0) != 0) {
        s->f90 = s->f90 + 1;
        if (s->f90 < 0xBB8) {
            if (func_00382380(D_001A4C60, s->f7C, 0) != 0) {
                func_L01_00456960(3);
            }
        }
    } else {
        s->f90 = 0;
    }
    if (D_001426A0[0] == 4) {
        func_L01_00456960(4);
    }
}
/* localdecomp:end func_L03_003C99E8 */
