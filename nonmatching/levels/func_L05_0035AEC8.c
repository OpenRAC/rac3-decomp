/* func_L05_0035AEC8 (PAL, level 5 shared code): 11 differences with its file's flags
 * (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as), all registers in the 0x38C block:
 * retail keeps the argument copy in $a2 and the 0x38C index, the table base and the halfword in $a0/$v1;
 * this C puts the argument in $a3 and the index in $a2. Logic, layout and the rest of the allocation match.
 * Tried without effect (all 11, same bytes): seven wordings of the 0x30-stride table read (byte offsets in both
 * orders, &tab[i * 0x30] + 0x32, an s16 array index, a (s32) base, a pointer-typed table read through
 * element i + 1), a local for the index. The 0x80-stride table as a struct array and the object as a struct
 * took it from 23 to 11. 0x1DF7CC is level data (the NTSC-U twin's draft of func_L05_00359C78 reads it as
 * D_L05_001DF84C). Promises, 2026-11-20. */
#include "common.h"

/* localdecomp:start func_L05_0035AEC8 */
typedef int u128_35AEC8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x30]; u128_35AEC8 pos; u8 pad2[0x40]; } E_35AEC8;
extern E_35AEC8 *D_L05_001DFC80;
__asm__(".extern D_L05_001DFC80, 4");
extern u8 *D_L05_001DF7CC;
__asm__(".extern D_L05_001DF7CC, 16");
typedef struct {
    u8 pad[0x350]; u128_35AEC8 x350; u8 pad1[0x380 - 0x360];
    s32 x380; s32 x384; s32 x388; s32 x38C; u8 pad2[0x398 - 0x390];
    s32 x398; u8 pad3[0x3A4 - 0x39C]; s32 x3A4; u8 pad4[0x3E0 - 0x3A8];
    s32 x3E0; u8 pad5[0x3FC - 0x3E4]; s32 x3FC;
} V_35AEC8;

void func_L05_0035AEC8(u8 *a0) {
    V_35AEC8 *v = *(V_35AEC8 **)(a0 + 0x68);
    v->x3E0 = 1;
    if (v->x384 != -1) {
        v->x3E0 = 2;
    } else if (v->x388 != -1) {
        v->x3E0 = 4;
        v->x350 = D_L05_001DFC80[v->x388].pos;
    } else if (v->x380 != -1) {
        v->x3E0 = 3;
    } else if (v->x38C != -1 && *(s16 *)(D_L05_001DF7CC + v->x38C * 0x30 + 0x32) != 0) {
        v->x3E0 = 5;
    } else if (v->x398 != 0 || v->x3FC != 0) {
        v->x3E0 = 4;
        v->x350 = *(u128_35AEC8 *)(a0 + 0x10);
    }
    if (v->x3A4 != -1 && *(long *)&v->x380 == -1 && *(long *)&v->x388 == -1) {
        v->x3E0 = 4;
    }
}
/* localdecomp:end func_L05_0035AEC8 */
