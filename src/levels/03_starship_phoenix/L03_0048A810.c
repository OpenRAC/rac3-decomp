#include "common.h"

typedef struct {
    s32 active;
    s32 pad4;
    s32 pad8;
    u32 *list;
    u32 type;
    u8 flag;
    u8 pad15[3];
} S_0048A810;

/* localdecomp:start func_L03_0048A810 */
/* Starship Phoenix: n = i + 1 in every case and i = n after the switch, as in the siblings
   func_L03_0048B918 / func_L03_004896E0; cases 3 and 4 are written out separately (jump2
   cross-jumps them), which gives n enough references to share i's register. */

extern S_0048A810 D_L03_002EB928[];
extern s32 D_00142BA0[];
extern u8 D_00142693 __attribute__((section(".data")));
extern s32 func_L01_0041A4F0(void);
void func_L03_0048A810(void) {
    s32 i = 0;
    s32 j;
    s32 m;
    u32 id;
    u32 y;
    s32 q;
    u32 x;
    s32 k;
    s32 n;
    while (D_L03_002EB928[i].active != 0) {
        switch (D_L03_002EB928[i].type) {
        case 0:
            y = (u32)D_L03_002EB928[i].list;
            q = 1 << (y & 0x1F);
            D_L03_002EB928[i].flag = (D_00142BA0[y >> 2] & q) || func_L01_0041A4F0() != 0;
            n = i + 1;
            break;
        case 1:
            D_L03_002EB928[i].flag = 0;
            n = i + 1;
            j = 0;
            if (D_L03_002EB928[i].list[0] != 0) {
                do {
                    D_L03_002EB928[i].flag = D_L03_002EB928[i].flag != 0
                        || (x = D_L03_002EB928[i].list[j], k = 1 << (x & 0x1F), D_00142BA0[x >> 2] & k)
                        || func_L01_0041A4F0() != 0;
                    j++;
                } while (D_L03_002EB928[i].list[j] != 0);
            }
            break;
        case 2:
            id = (u32)D_L03_002EB928[i].list;
            m = 1 << (id & 0x1F);
            D_L03_002EB928[i].flag = (D_00142BA0[id >> 2] & m) || func_L01_0041A4F0() != 0;
            n = i + 1;
            break;
        case 3:
            D_L03_002EB928[i].flag = D_00142693 != 0 || func_L01_0041A4F0() != 0;
            n = i + 1;
            break;
        case 4:
        default:
            D_L03_002EB928[i].flag = D_00142693 != 0 || func_L01_0041A4F0() != 0;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L03_0048A810 */
