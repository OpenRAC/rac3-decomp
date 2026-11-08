/* near miss (level 3, Starship Phoenix): 133 differences, saved-register assignment: the structure matches (5-entry jump table, three simple cases sharing a tail written with goto, a list walk through e->ids, 0x50 frame) but retail keeps i in $s2 and the C in $s4, and e/l and ok/any coalesce differently, shifting nearly every line; 7 declaration orders and merging ok/l via casts changed nothing; sibling of func_L03_0048B918 */
#include "common.h"

/* localdecomp:start func_L03_0048A810 */
typedef struct S_0048A810 {
    s32 active;
    s32 pad4[2];
    u32 id;
    s32 type;
    u8 flag;
    u8 pad15[3];
} S_0048A810;

typedef struct S_0048A810_list {
    s32 active;
    s32 pad4[2];
    u32 **ids;
    s32 type;
    u8 flag;
    u8 pad15[3];
} S_0048A810_list;

extern S_0048A810 D_L03_002EB928[];
extern u32 D_00142BA0[];
extern u8 D_00142693;
extern s32 func_L01_0041A4F0(void);

void func_L03_0048A810(void) {
    s32 i;
    s32 ok;
    s32 j;
    s32 any;
    S_0048A810 *e;
    S_0048A810_list *l;
    u32 ***pp;

    i = 0;
    if (D_L03_002EB928[0].active == 0) {
        return;
    }
    do {
        switch (D_L03_002EB928[i].type) {
        case 0:
            e = &D_L03_002EB928[i];
            ok = 0;
            if ((D_00142BA0[e->id >> 2] & (1 << (e->id & 0x1F))) != 0) {
                goto set;
            }
            goto call;
        case 1:
            l = (S_0048A810_list *)&D_L03_002EB928[i];
            l->flag = 0;
            i++;
            pp = &l->ids;
            if (**pp != 0) {
                j = 0;
                do {
                    any = 0;
                    if (l->flag == 0) {
                        u32 id = (*pp)[j];
                        if ((D_00142BA0[id >> 2] & (1 << (id & 0x1F))) == 0 && func_L01_0041A4F0() == 0) {
                        } else {
                            any = 1;
                        }
                    } else {
                        any = 1;
                    }
                    l->flag = any;
                    j++;
                } while ((*pp)[j] != 0);
            }
            continue;
        case 2:
            e = &D_L03_002EB928[i];
            ok = 0;
            if ((D_00142BA0[e->id >> 2] & (1 << (e->id & 0x1F))) != 0) {
                goto set;
            }
            goto call;
        case 3:
        case 4:
        default:
            e = &D_L03_002EB928[i];
            ok = 0;
            if (D_00142693 != 0) {
                goto set;
            }
        call:
            if (func_L01_0041A4F0() == 0) {
                e->flag = ok;
                goto inc;
            }
        set:
            ok = 1;
            e->flag = ok;
        inc:
            i++;
            break;
        }
    } while (D_L03_002EB928[i].active != 0);
}
/* localdecomp:end func_L03_0048A810 */
