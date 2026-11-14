/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003BAA10, the NTSC-U twin of func_L09_003BC288, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (PAL line lacks @ps2as)" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L09_003BAA10 */
typedef struct {
    u8 pad0[0x1DC];
    s16 h1DC;
    u8 pad1DE[0x25C4 - 0x1DE];
    s32 w25C4;
    u8 pad25C8[0x2850 - 0x25C8];
    s32 w2850;
} Hero_3BAA10;

extern Hero_3BAA10 D_001A4BE0;
__asm__(".extern D_L09_001E011C, 16");
extern u8 *D_L09_001E011C;
extern u8 D_0014271D[];
extern void func_003BD360(void *);
extern void func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00399F90(void);
extern void func_L01_00416BF8(s32);
extern void func_L01_00452F40(u8 *, s32);
extern void func_L01_00438430(s32);
extern void func_L01_004412D0(u8 *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(void *, s32);

void func_L09_003BAA10(u8 *o) {
    u8 *st = *(u8 **)(o + 0x68);
    u8 *e = D_L09_001E011C + (*(s32 *)(st + 0xCD0) << 8);

    if (o[0x7F] == 0 && D_001A4BE0.w2850 > 0 && D_001A4BE0.w25C4 != 0x6A && D_001A4BE0.w25C4 != 0x7D) {
        D_001A4BE0.h1DC = 0xB4;
        func_003BD360(e);
        func_L01_0032FE90(e + 0x10, 0, 5, 5, 5, 5, 0xA, 1, 1.3f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        D_0014271D[0] = 1;
        func_00399F90();
        func_L01_00416BF8(0x67);
        func_L01_00452F40(D_L09_001E011C + (*(s32 *)(st + 0xD24) << 8), 1);
        func_L01_00438430(*(s32 *)(st + 0xD5C));
        func_L01_004412D0(o, 0, 3);
        func_L01_00441FB8(o, 1, 9);
        func_L01_00442050(o, 0);
    }
}
/* localdecomp:end func_L09_003BAA10 */
