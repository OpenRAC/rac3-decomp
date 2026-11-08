/* near miss (level 3, Starship Phoenix): 91 differences, register allocation and ordering: the 5-entry jump table compiles as retail's (case 4 next to default) and the dispatch prologue matches; the bit test needs a separate mask statement for sllv+and; retail keeps the base in $a1/$t5, sets the flag value in delay slots and loads the list pointer and flag inside the loop, the C if-converts to movz/movn when a local is used */
#include "common.h"

/* localdecomp:start func_L03_0048B918 */
typedef struct {
    int *p0;
    int pad4, pad8;
    unsigned *list;
    unsigned type;
    u8 flag;
    u8 pad15[3];
} S_0048B918;
extern S_0048B918 D_L03_002EBD18[];
extern int D_00142BA0[];
extern u8 D_00142693;
extern s32 D_001D9518_sda;
__asm__(".extern D_001D9518_sda, 4");

void func_L03_0048B918(void) {
    int i = 0;
    int n;
    int j;
    unsigned m;
    unsigned id;
    if (D_L03_002EBD18[0].p0 != 0) {
        do {
            switch (D_L03_002EBD18[i].type) {
            case 1:
                D_L03_002EBD18[i].flag = 1;
                n = i + 1;
                for (j = 0; D_L03_002EBD18[i].list[j] != 0; j++) {
                    id = D_L03_002EBD18[i].list[j];
                    m = 1U << (id & 0x1F);
                    if (D_L03_002EBD18[i].flag && (m & D_00142BA0[id >> 2])) {
                        D_L03_002EBD18[i].flag = 1;
                    } else if (D_001D9518_sda == 0) {
                        D_L03_002EBD18[i].flag = 0;
                    } else {
                        D_L03_002EBD18[i].flag = 1;
                    }
                }
                i = n;
                break;
            case 0:
            case 2:
                id = (unsigned)D_L03_002EBD18[i].list;
                m = 1U << (id & 0x1F);
                if (m & D_00142BA0[id >> 2]) {
                    D_L03_002EBD18[i].flag = 1;
                } else if (D_001D9518_sda == 0) {
                    D_L03_002EBD18[i].flag = 0;
                } else {
                    D_L03_002EBD18[i].flag = 1;
                }
                i = i + 1;
                break;
            case 3:
                if (D_00142693 != 0) {
                    D_L03_002EBD18[i].flag = 1;
                } else if (D_001D9518_sda == 0) {
                    D_L03_002EBD18[i].flag = 0;
                } else {
                    D_L03_002EBD18[i].flag = 1;
                }
                i = i + 1;
                break;
            case 4:
            default:
                D_L03_002EBD18[i].flag = 1;
                i = i + 1;
                break;
            }
        } while (D_L03_002EBD18[i].p0 != 0);
    }
}
/* localdecomp:end func_L03_0048B918 */
