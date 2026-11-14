#include "common.h"

/* NTSC-U counterpart of func_L40_003F11C8 (src/levels/shared/L40_003F11C8.c) */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};

/* localdecomp:start func_L40_003F0D20 */
extern s32 *D_L40_002412A0;
extern s32 D_001A5F78[];
extern u8 *func_L39_006197C0(s32);
extern s32 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, s32, s32, s32, void *);

void func_L40_003F0D20(Moby *self, s32 a1) {
    u8 *v = self->pVar;
    u8 *p = 0;
    s32 *n;
    s32 i;

    if (*(s32 *)(v + 0x264) != 0x539) {
        return;
    }
    if (*(s32 *)(v + 0x304) <= 0) {
        return;
    }
    for (i = 0; i < *D_L40_002412A0; i++) {
        p = func_L39_006197C0(i);
        if (*(s32 *)p == *(s32 *)(v + 0x304)) {
            break;
        }
    }
    if (i == *D_L40_002412A0) {
        return;
    }
    if (p[0x1A11] != 2) {
        return;
    }
    n = func_L39_006699B0();
    if (n != 0) {
        *n = func_L39_00669978(1, a1, D_001A5F78[0], 6, n);
    }
}
/* localdecomp:end func_L40_003F0D20 */
