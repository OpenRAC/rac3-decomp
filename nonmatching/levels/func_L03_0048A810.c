/* near miss (level 3, Starship Phoenix): 13 differences, all in case 1: retail increments i in place before the inner loop (which works on copies of the entry and list pointers, so i is dead there), the C keeps n = i + 1 in its own register ($s4) with i = n at the end, which moves the inner loop's j and flag value up one register ($s3/$s2 for retail's $s4/$s3). Everything else is retail's, in the shape of the matched siblings func_L03_0048B918 and func_L03_004896E0 (while loop, flags as one || expression, per-case bit-test variables, D_00142693 through %hi/%lo). Tried for case 1: k = i++ with D[k] (37-50), pointer variables before or after the first uses (107-110), e = &D[i++] (118), n = i + 1 in every case (36). */
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
    u32 **p;
    s32 n;
    while (D_L03_002EB928[i].active != 0) {
        switch (D_L03_002EB928[i].type) {
        case 0:
            y = (u32)D_L03_002EB928[i].list;
            q = 1 << (y & 0x1F);
            D_L03_002EB928[i].flag = (D_00142BA0[y >> 2] & q) || func_L01_0041A4F0() != 0;
            i++;
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
            i = n;
            break;
        case 2:
            id = (u32)D_L03_002EB928[i].list;
            m = 1 << (id & 0x1F);
            D_L03_002EB928[i].flag = (D_00142BA0[id >> 2] & m) || func_L01_0041A4F0() != 0;
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L03_002EB928[i].flag = D_00142693 != 0 || func_L01_0041A4F0() != 0;
            i++;
            break;
        }
    }
}
