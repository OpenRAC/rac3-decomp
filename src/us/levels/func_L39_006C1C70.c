#include "common.h"

/* NTSC-U counterpart of func_L39_006C4788 (src/levels/39_multiplayer_menu/L39_006C46F0.c) */
typedef struct {
    u8 name[8][16];
    u8 pad[0x60];
    s16 slot[8];
} S_006C46F0;
extern S_006C46F0 *D_001D5F30_sda_006C1C70;

/* localdecomp:start func_L39_006C1C70 */
extern s32 D_001A5E58[];

s32 func_L39_006C1C70(s32 a, s32 n) {
    s32 idx;
    s32 i;
    if (D_001D5F30_sda_006C1C70 == 0) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 8; i++) {
        if (D_001D5F30_sda_006C1C70->slot[i] != -1) {
            idx++;
        }
        if (D_001D5F30_sda_006C1C70->slot[i] == D_001A5E58[0]) {
            if (n == 0) {
                return idx;
            }
            n--;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_006C1C70 */
