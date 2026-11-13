#include "common.h"

/* NTSC-U counterpart of func_L03_003CBA20 (src/levels/03_starship_phoenix/L03_003CB5E0.c) */
extern u8 D_001A4C60[];
extern s32 func_0037E0F0(void *, s32, s32);

/* localdecomp:start func_L03_003C9AF8 */
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x3C];
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[4];
    s32 f94;
} S_003CBA20;
extern u8 D_00142757[];
extern u8 D_00142CBE[];
extern u8 D_001A4C60[];
extern s32 D_L03_001DEF68[];
extern s32 D_L03_001DE898;
__asm__(".extern D_L03_001DE898, 16");
__asm__(".extern D_00142757, 16");
__asm__(".extern D_00142CBE, 16");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FF8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L03_003C99E8(void *);

void func_L03_003C9AF8(void *a0) {
    S_003CBA20 *s;
    s32 v;
    s32 i;
    s = *(S_003CBA20 **)((u8 *)a0 + 0x68);
    if (*((u8 *)a0 + 0x20) == 0) {
        *((u8 *)a0 + 0x30) = 0xFF;
        s->f84 = 0x3F;
        i = D_00142757[0];
        if ((((D_L03_001DE898 >> D_L03_001DEF68[i]) ^ 1) & 1) != 0) {
            s->f94 = 1;
        }
        func_L01_00441FB8(a0, 1, -1);
        v = func_0037E208(0x4B0, 0x960);
        s->f40 = v;
    }
    v = 1;
    if (D_00142CBE[0] != 0) {
        if (func_0037E0F0(D_001A4C60, s->f44, 0) != 0) {
            v = 2;
        } else if (func_0037E0F0(D_001A4C60, s->f88, 0) != 0) {
            v = 3;
        }
    }
    if (func_0037E0F0(D_001A4C60, s->f8C, 0) != 0) {
        v = 4;
    }
    func_L01_00441FF8(a0, v, -1);
    func_L03_003C99E8(a0);
}
/* localdecomp:end func_L03_003C9AF8 */
