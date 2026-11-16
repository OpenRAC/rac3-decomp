#include "common.h"

/* NTSC-U counterpart of func_L09_003BC288 (src/levels/09_tyhrranosis/L09_003B8580.c) */
#include "vu0.h"
#include "vu0.h"
extern u8 D_001A4BE0[];
extern u8 *D_L09_001E011C;
extern void func_00399F90(void);
extern void func_003BD360(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);
extern void func_L09_003BAA10(u8 *);
extern u8 *D_L09_001E011C;
extern void func_00399F90(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);
extern u8 *D_L09_001E011C;

/* localdecomp:start func_L09_003BAA10 */
extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern u8 D_001A4BE0[];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern void func_003BD360(void *);
extern s32 func_L01_0032FE90_003BAA10(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00399F90(void);
extern void func_L01_00416BF8(s32);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_00438430(s32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);

void func_L09_003BAA10(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    u8 *h;
    if (a0[0x7F] != 0) {
        return;
    }
    h = D_001A4BE0;
    if (*(s32 *)(h + 0x2850) > 0
        && *(s32 *)(h + 0x25C4) != 0x6A && *(s32 *)(h + 0x25C4) != 0x7D) {
        *(s16 *)(h + 0x1DC) = 0xB4;
        func_003BD360(e);
        func_L01_0032FE90_003BAA10(e + 0x10, 0, 5, 5, 5, 5, 10, 1, 1.3f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        D_0014271D[0] = 1;
        func_00399F90();
        func_L01_00416BF8(0x67);
        func_L01_00452F40(D_L09_001E011C + (*(s32 *)(p + 0xD24) << 8), 1);
        func_L01_00438430(*(s32 *)(p + 0xD5C));
        func_L01_004412D0(a0, 0, 3);
        func_L01_00441FB8(a0, 1, 9);
        func_L01_00442050(a0, 0);
    }
}
/* localdecomp:end func_L09_003BAA10 */
