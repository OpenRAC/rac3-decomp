#include "common.h"

INCLUDE_ASM("asm/levels", func_L27_003A1250);

INCLUDE_ASM("asm/levels", func_L27_003A17B0);

INCLUDE_ASM("asm/levels", func_L27_003A1B30);

INCLUDE_ASM("asm/levels", func_L27_003A2548);

INCLUDE_ASM("asm/levels", func_L27_003A2B98);

INCLUDE_ASM("asm/levels", func_L27_003A2E08);

/* localdecomp:start func_L27_003A2F58 */
typedef struct { u8 p0[0x4A0]; s32 f4A0; } S_2F58_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2F58_D *f68; } S_2F58_E;
typedef struct { u8 p0[0x98]; s32 f98; s32 f9C; u8 pA0[0x24]; s32 fC4; s32 fC8; s32 fCC; s32 fD0; } S_2F58_P;
typedef struct { u8 p0[0x68]; S_2F58_P *f68; u8 p6C[0x29]; u8 b95; } S_2F58_O;
extern u8 *D_001DED1C_sda;
__asm__(".extern D_001DED1C_sda, 4");
extern u8 *D_L27_001DED1C_003A2F58;
__asm__(".extern D_L27_001DED1C_003A2F58, 16");
extern void func_L27_0039F718(void *, void *);

void func_L27_003A2F58(S_2F58_O *arg0) {
    S_2F58_P *p;
    s32 i;
    s32 j;
    p = arg0->f68;
    if (arg0->b95 == 0) return;
    i = p->fC4;
    if (i == -1 || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_L27_001DED1C_003A2F58 + (i << 8), D_L27_001DED1C_003A2F58 + (p->fC8 << 8));
    }
    i = p->fCC;
    if (i == -1 || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_L27_001DED1C_003A2F58 + (i << 8), D_L27_001DED1C_003A2F58 + (p->fD0 << 8));
    }
    j = p->f98;
    if (j == -1 || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_001DED1C_sda + (j << 8), D_001DED1C_sda + (p->f9C << 8));
    }
}
/* localdecomp:end func_L27_003A2F58 */

INCLUDE_ASM("asm/levels", func_L27_003A3098);

INCLUDE_ASM("asm/levels", func_L27_003A3310);

INCLUDE_ASM("asm/levels", func_L27_003A3498);
