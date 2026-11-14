#include "common.h"

/* NTSC-U counterpart of func_L03_0048B918 (src/levels/03_starship_phoenix/L03_0048B918.c) */
/* localdecomp:start func_L03_00487CD0 */
typedef struct {
    s32 p0;
    s32 pad4;
    s32 pad8;
    u32 *list;
    u32 type;
    u8 flag;
    u8 pad15[3];
} S_0048B918;
extern S_0048B918 D_L03_002EBD68[];
extern s32 D_00142BA0[];
extern u8 D_00142693 __attribute__((section(".data")));
extern s32 D_L03_001D9548;
__asm__(".extern D_L03_001D9548, 4");
void func_L03_00487CD0(void) {
    s32 i = 0;
    s32 n;
    s32 j;
    s32 g;
    s32 m;
    u32 id;
    u32 x;
    s32 k;
    S_0048B918 *e;
    while (D_L03_002EBD68[i].p0 != 0) {
        switch (D_L03_002EBD68[i].type) {
        case 1:
            e = &D_L03_002EBD68[i];
            e->flag = 1;
            n = i + 1;
            j = 0;
            if (D_L03_002EBD68[i].list[0] != 0) {
                g = D_L03_001D9548;
                do {
                    e->flag = (e->flag != 0 && (x = D_L03_002EBD68[i].list[j], k = 1 << (x & 0x1F), D_00142BA0[x >> 2] & k)) || g != 0;
                    j++;
                } while (D_L03_002EBD68[i].list[j] != 0);
            }
            break;
        case 0:
        case 2:
            id = (u32)D_L03_002EBD68[i].list;
            m = 1 << (id & 0x1F);
            D_L03_002EBD68[i].flag = (D_00142BA0[id >> 2] & m) || D_L03_001D9548 != 0;
            n = i + 1;
            break;
        case 3:
            D_L03_002EBD68[i].flag = D_00142693 != 0 || D_L03_001D9548 != 0;
            n = i + 1;
            break;
        case 4:
        default:
            D_L03_002EBD68[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L03_00487CD0 */
