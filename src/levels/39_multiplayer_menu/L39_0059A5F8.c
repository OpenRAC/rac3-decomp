#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_0059A5F8);

/* localdecomp:start func_L39_0059A638 */
extern s32 D_L39_00241444;
__asm__(".extern D_L39_00241444, 16");
void func_L39_0059A660(s32, s32);

void func_L39_0059A638(s32 arg0) {
    func_L39_0059A660(D_L39_00241444, arg0);
}
/* localdecomp:end func_L39_0059A638 */

/* localdecomp:start func_L39_0059A660 */
typedef struct { u8 a; u8 b; u8 pad2[2]; s32 c; } Slot_0059A660;
typedef struct {
    s32 w0;
    Slot_0059A660 s[3];
    u8 pad1C[0x4F - 0x1C];
    u8 f4F;
    u8 pad50[0x171 - 0x50];
    u8 f171;
    s16 f172;
    u8 pad174[0x1F0 - 0x174];
} E_0059A660;
typedef struct {
    u8 pad0[4];
    u8 f4;
    u8 f5;
    u8 pad6[6];
    s32 fC;
    u8 pad10[4];
    s32 b[3][4];
    s32 a[3][4];
    s32 c[3][4];
    u8 padA4[0xAE - 0xA4];
    u8 fAE[4];
} G_0059A660;
extern E_0059A660 D_001FC6B0_0059A660[];
extern s32 D_L39_00240370[] __attribute__((section(".sdata")));
extern s32 D_001A5CEC[];
/* the $at macro store of retail: a scalar the assembler is told is large */
extern s32 D_L39_00241444_0059A660;
__asm__(".extern D_L39_00241444_0059A660, 16");
extern G_0059A660 D_001A5810_0059A660;

void func_L39_0059A660(s32 idx, s32 k)
{
    E_0059A660 *e;
    s32 i;

    e = &D_001FC6B0_0059A660[idx];
    D_L39_00240370[k] = idx;
    D_001A5CEC[0] = e->w0;
    D_L39_00241444_0059A660 = idx;
    for (i = 0; i < 3; i++) {
        D_001A5810_0059A660.a[i][k] = (i == 0) ? e->s[0].a : e->s[i].a ^ 1;
        D_001A5810_0059A660.b[i][k] = e->s[i].b;
        D_001A5810_0059A660.c[i][k] = e->s[i].c;
    }
    D_001A5810_0059A660.f5 = e->f4F == 0;
    D_001A5810_0059A660.f4 = e->f4F == 0;
    D_001A5810_0059A660.fC = e->f172;
    D_001A5810_0059A660.fAE[k] = e->f171;
}
/* localdecomp:end func_L39_0059A660 */
