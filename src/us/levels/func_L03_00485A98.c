#include "common.h"

/* NTSC-U counterpart of func_L03_004896E0 (src/levels/03_starship_phoenix/L03_004896E0.c) */
/* localdecomp:start func_L03_00485A98 */
typedef struct {
    s32 id;
    s32 pad4;
    s32 pad8;
    u32 *list;
    u32 type;
    u8 flag;
    u8 pad15[3];
} S_004896E0;
extern S_004896E0 D_L03_002EB4E8[];
extern s32 D_00142BA0[];
extern u8 D_00142693 __attribute__((section(".data")));
extern s32 func_L01_00417EA0(void);
void func_L03_00485A98(void) {
    s32 i = 0;
    s32 n;
    s32 j;
    s32 m;
    u32 id;
    u32 x;
    s32 k;
    S_004896E0 *e;
    u32 y;
    s32 q;
    while (D_L03_002EB4E8[i].id != 0) {
        switch (D_L03_002EB4E8[i].type) {
        case 0:
            D_L03_002EB4E8[i].flag = func_L01_00417EA0() != 0
                || (y = (u32)D_L03_002EB4E8[i].list, q = 1 << (y & 0x1F), D_00142BA0[y >> 2] & q);
            n = i + 1;
            break;
        case 1:
            D_L03_002EB4E8[i].flag = 1;
            n = i + 1;
            j = 0;
            if (D_L03_002EB4E8[i].list[0] != 0) {
                do {
                    D_L03_002EB4E8[i].flag = func_L01_00417EA0() != 0
                        || (D_L03_002EB4E8[i].flag != 0 && (x = D_L03_002EB4E8[i].list[j], k = 1 << (x & 0x1F), D_00142BA0[x >> 2] & k));
                    j++;
                } while (D_L03_002EB4E8[i].list[j] != 0);
            }
            break;
        case 2:
            id = (u32)D_L03_002EB4E8[i].list;
            m = 1 << (id & 0x1F);
            D_L03_002EB4E8[i].flag = (D_00142BA0[id >> 2] & m) != 0;
            n = i + 1;
            break;
        case 3:
            n = i + 1;
            D_L03_002EB4E8[i].flag = D_00142693 != 0;
            D_L03_002EB4E8[i].flag = func_L01_00417EA0();
            break;
        case 4:
        default:
            e = &D_L03_002EB4E8[i];
            if (e->id == 0x1C3) {
                e->flag = 1;
                n = i + 1;
            } else {
                n = i + 1;
                e->flag = D_00142693 != 0;
                e->flag = func_L01_00417EA0();
            }
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L03_00485A98 */
