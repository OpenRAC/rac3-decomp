#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 1301D8.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u8 pad0[0x184];
    int f184;
    int f188;
} S_130210;
typedef struct {
    int f0;
    u8 pad4[0x10 - 4];
    int f10;
} Pic_130AA0;
typedef struct {
    int f0;
    int pad4;
    int f8;
    int fC;
    int f10;
    u8 pad14[0x140 - 0x14];
} Blk_130AA0;
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x184 - 0x140];
    int f184;
    u8 pad188[0x1D0 - 0x188];
    Pic_130AA0 *f1D0;
    u8 pad1D4[0x1E0 - 0x1D4];
    Pic_130AA0 *f1E0;
    u8 pad1E4[0x1F0 - 0x1E4];
    Pic_130AA0 *f1F0;
    u8 pad1F4[0x6C8 - 0x1F4];
    Blk_130AA0 blk[1];
    u8 pad808[0x820 - 0x808];
    int f820;
} S_130AA0;
extern char D_00151CF0[];
void func_0013A150(void *s, char *fmt, int x);
void func_00130398(S_130AA0 *s, int x, int y, int flags, int mode, int *mv, int *fs, int a7);
void func_00132D48();

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00130CF0);
