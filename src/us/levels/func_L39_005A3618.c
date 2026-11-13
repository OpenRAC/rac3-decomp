#include "common.h"

/* NTSC-U counterpart of func_L39_005A5288 (src/levels/shared/L39_005A5238.c) */
typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;
extern S_005A5238 D_001A4560;
extern S_005A5238 D_001A4560;

/* localdecomp:start func_L39_005A3618 */
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;

void func_L39_005A3618(void) {
    s32 *s = (s32 *)&D_001A4560;

    D_L39_0024057C = D_L39_0024057C & ~0x20;
    if (s[2] == 2) {
        if (s[5] == 0) {
            D_L39_00240578 = 7;
        } else if (s[4] != 0) {
            s[4] = 0;
            D_L39_00240578 = 0xB;
        } else {
            D_L39_00240578 = 0xB;
        }
    }
}
/* localdecomp:end func_L39_005A3618 */
