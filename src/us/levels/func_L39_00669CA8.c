#include "common.h"

/* NTSC-U counterpart of func_L39_0066C5B0 (src/levels/shared/L39_0066C4D8.c) */
typedef struct S_0066C4D8 {
    u8 pad0[8];
    s32 f8;
    u8 pad1[0x11C];
    s32 f128;
} S_0066C4D8;
extern S_0066C4D8 D_001A5E50;

/* localdecomp:start func_L39_00669CA8 */
typedef struct {
    s32 f0;
    u8 pad4[0x2C];
    u8 f30;
    u8 f31;
    u8 pad32[10];
    s32 f3C;
    s32 f40;
} Ent_0066C5B0;

extern Ent_0066C5B0 D_L39_0033ACA0[];
extern s32 func_L39_00669BD0(s32);
extern void func_L39_00669C50(void *);

void func_L39_00669CA8(void) {
    s32 i;

    for (i = 0; i < 50; i++) {
        u8 f = D_L39_0033ACA0[i].f31;
        if (f == 1 && func_L39_00669BD0(D_L39_0033ACA0[i].f3C) != 0) {
            D_L39_0033ACA0[i].f30 = f;
            D_L39_0033ACA0[i].f3C = D_001A5E50.f8;
            func_L39_00669C50((void *)D_L39_0033ACA0[i].f0);
        }
    }
}
/* localdecomp:end func_L39_00669CA8 */
