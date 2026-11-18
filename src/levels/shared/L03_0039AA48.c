#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039AA48);

/* localdecomp:start func_L03_0039AE90 */
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044F888(void *, s32, s32, void *, s32);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

void func_L03_0039AE90(u8 *m) {
    u8 *v;
    s32 i;
    if (m[0x20] != 0) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    *(f32 *)(v + 0x4FC) = *(f32 *)(m + 0x18);
    *(s32 *)(v + 0x500) = 0;
    func_L01_0044ED88(m, v, 0xF, *(s32 *)(v + 0x4F0), *(s32 *)(v + 0x4F4), -1, 7, 0);
    for (i = 0; i < 15; i++) {
        u8 *e = (u8 *)((s32)v + i * 0x50);
        if (e[0x4C] == 0) {
            u8 *t = (u8 *)D_L03_001DF99C + (*(s16 *)(e + 0x48) << 8);
            if (*(s16 *)(t + 0xAA) == 0x191F) {
                func_L01_0044F888(v, 0, *(s16 *)(e + 0x48), v + 0x4B0, 0);
            }
            if (*(s16 *)(t + 0xAA) == 0x1920) {
                func_L01_0044F888(v, 0, *(s16 *)(e + 0x48), v + 0x4D0, 0);
            }
        }
    }
    func_L01_004450F0(m, 1, -1);
}
/* localdecomp:end func_L03_0039AE90 */

/* localdecomp:start func_L03_0039AFB0 */
typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003998B0;

extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);

s32 func_L03_0039AFB0(Moby_003998B0 *m) {
    s32 r;
    s32 id = *(s32 *)(m->w68 + 1272);
    if (id == -1) {
        r = 0;
    } else {
        r = func_00382380(D_001A4C60, id, 0) != 0;
    }
    return r;
}
/* localdecomp:end func_L03_0039AFB0 */
