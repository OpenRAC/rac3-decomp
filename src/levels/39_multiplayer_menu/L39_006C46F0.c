#include "common.h"

/* localdecomp:start func_L39_006C46F0 */
typedef struct {
    u8 name[8][16];
    u8 pad[0x60];
    s16 slot[8];
} S_006C46F0;
extern S_006C46F0 *D_001D5F30_sda;
extern s32 func_001205B0(s32, s32);

s32 func_L39_006C46F0(u8 *obj, s32 slot) {
    u8 *name;
    s32 i;
    slot += 15;
    obj += slot * 4;
    name = *(u8 **)(obj + 0x110) + 0x14;
    for (i = 0; i < 8; i++) {
        S_006C46F0 *tbl = D_001D5F30_sda;
        if (tbl == 0) continue;
        if (tbl->slot[i] == -1) continue;
        if (func_001205B0((s32)name, (s32)tbl->name[i]) == 0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_006C46F0 */

/* localdecomp:start func_L39_006C4788 */
extern s32 D_001A5CD8[];

s32 func_L39_006C4788(s32 a, s32 n) {
    s32 idx;
    s32 i;
    if (D_001D5F30_sda == 0) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 8; i++) {
        if (D_001D5F30_sda->slot[i] != -1) {
            idx++;
        }
        if (D_001D5F30_sda->slot[i] == D_001A5CD8[0]) {
            if (n == 0) {
                return idx;
            }
            n--;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_006C4788 */

LINKER_REMNANT("asm/levels", func_L39_006C47F8);

INCLUDE_ASM("asm/levels", func_L39_006C4818);

LINKER_REMNANT("asm/levels", func_L39_006C5510);
