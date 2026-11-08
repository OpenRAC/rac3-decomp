/* near miss (level 5, Daxx): 37 differences: retail builds the D_001A4BE0 base once per block (addiu t0) and uses 0xa54/0x25cc offsets; gcc folds them into the lui; flag byte register a3 vs t1 */
#include "common.h"

/* localdecomp:start func_L05_00360070 */
typedef struct {
    u8 pad0[0x58];
    s32 f58[5];
    s32 f6C[5];
    u8 pad80[0x4A];
    u8 fCA;
} S_360070;

extern u8 D_001A4BE0[8];
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern s32 func_00382380(u8 *, s32, s32);

s32 func_L05_00360070(u8 *a0, s32 a1) {
    S_360070 *s = *(S_360070 **)(a0 + 0x68);
    s32 r;
    if (s->f6C[a1] == -1 && s->f58[a1] == -1) {
        return 1;
    }
    r = 0;
    if (((s->fCA >> a1) & 1) == 0) {
        if (s->f6C[a1] != -1 && *(s32 *)(D_001A4BE0 + 0xA54) == (s32)D_L05_001DFB9C + (s->f6C[a1] << 8)
            && *(s32 *)(D_001A4BE0 + 0x25CC) == 0xE) {
            s->fCA |= 1 << a1;
        } else if (s->f58[a1] != -1 && func_00382380(D_001A4C60, s->f58[a1], 0)) {
            r = 1;
        } else if (*(s32 *)(D_001A4BE0 + 0x360) != 0) {
            r = *(s32 *)(D_001A4BE0 + 0x35C) == (s32)D_L05_001DFB9C + (s->f6C[a1] << 8);
        }
    } else if (*(s32 *)(D_001A4BE0 + 0xA54) != (s32)D_L05_001DFB9C + (s->f6C[a1] << 8)
               || *(s32 *)(D_001A4BE0 + 0x25CC) != 0xE) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_00360070 */
