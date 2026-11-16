#include "common.h"

/* NTSC-U counterpart of func_L35_003A5F00 (src/levels/35_vidcomic_5/L35_003A5F00.c) */
/* localdecomp:start func_L35_003A45E8 */
typedef struct {
    u8 pad0[0x31];
    u8 active;
    u8 pad32[2];
    u16 flags;
    u8 pad36[0xCA];
} S_003A5F00;
extern S_003A5F00 *D_L35_001DF91C;
extern u8 *D_L35_001DFA00;
__asm__(".extern D_L35_001DFA00, 4");
extern s32 D_L35_0021D900[];
extern void func_L01_00441FB8(void *, s32, s32);

void func_L35_003A45E8(u8 *a0) {
    u8 *v;
    f32 *p;
    s32 i;
    S_003A5F00 *m;
    f32 f;

    a0[0x30] = 0xFF;
    v = *(u8 **)(a0 + 0x68);
    *(s16 *)(a0 + 0x32) = 0;
    p = (f32 *)(v + 0x10);
    for (i = 3; i >= 0; i--) {
        *p = *p * 0.0166666675f;
        p++;
    }
    f = *(f32 *)(v + 0x54);
    m = &D_L35_001DF91C[*(s32 *)(v + 0x6C)];
    *(f32 *)(v + 0x48) = f;
    *(s32 *)(v + 0x58) = 0;
    m->active = 1;
    m->flags &= ~1;
    if (*(s32 *)(v + 0x5C) != -1) {
        *(u8 **)(v + 0x60) = D_L35_001DFA00 + *(s32 *)(v + 0x5C) * 0x80;
    }
    if (*(s32 *)(v + 0x64) != -1) {
        *(s32 *)(v + 0x68) = D_L35_0021D900[*(s32 *)(v + 0x64)];
    }
    func_L01_00441FB8(a0, 1, -1);
}
/* localdecomp:end func_L35_003A45E8 */
