/* near miss (level 3, Starship Phoenix): 21 differences, register choices only: in case 1 retail increments i in place before the inner loop (the loop works on copies of the entry and list pointers), the C keeps n = i + 1 in its own register ($s4) with i = n at the end, which shifts the inner loop's j and flag value by one register ($s3/$s2 for retail's $s4/$s3); and in cases 0 and 2 retail builds the 0x18 stride in $v1 where the C uses $v0. The shape is func_L03_0048B918's (matched): while loop, flags as one || expression, the inner id and mask as their own variables, D_00142693 through %hi/%lo. Tried: k = i++ with D[k] in the loop (50, extra copy of k), pointer variables before or after the first uses (110), n = i + 1 in every case (36), the entry pointer assigned after the id read in cases 0/2 (fixes the stride register but swaps the two base registers, 27-34). */
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
    u32 x;
    s32 k;
    u32 **p;
    s32 n;
    while (D_L03_002EB928[i].active != 0) {
        switch (D_L03_002EB928[i].type) {
        case 0:
            id = (u32)D_L03_002EB928[i].list;
            m = 1 << (id & 0x1F);
            D_L03_002EB928[i].flag = (D_00142BA0[id >> 2] & m) || func_L01_0041A4F0() != 0;
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
