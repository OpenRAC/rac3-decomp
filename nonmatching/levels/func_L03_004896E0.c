/* near miss (level 3, Starship Phoenix): 137 differences, almost all register allocation (case 0 matches retail apart from register names; the 5-entry jump table with case 4 next to default and the inner loops are structurally right): retail keeps next in $s3, e in $s0/$s1/$a2 and the table pointer in $s1/$s7 and saves s2, s7 first, the C puts next in $s1 and the high-half pointer in $s5; an explicit table pointer and offset made it worse; sibling of func_L03_0048B918 and func_L03_0048A810 */
#include "common.h"

/* localdecomp:start func_L03_004896E0 */
typedef struct {
    s32 id;
    s32 pad4;
    s32 pad8;
    s32 c;
    s32 type;
    u8 flag;
    u8 pad15[3];
} S_004896E0;

extern S_004896E0 D_L03_002EB498[];
extern u32 D_00142BA0[];
extern u8 D_00142693;
__asm__(".extern D_00142693, 16");
extern s32 func_L01_0041A4F0();

void func_L03_004896E0(void) {
    s32 i;
    s32 next;
    S_004896E0 *e;
    s32 r;
    s32 t;
    s32 k;
    s32 **lp;

    if (D_L03_002EB498[0].id == 0) {
        return;
    }
    i = 0;
    do {
        switch (D_L03_002EB498[i].type) {
        case 0:
            e = &D_L03_002EB498[i];
            r = 0;
            if (func_L01_0041A4F0() != 0 || (D_00142BA0[(u32)D_L03_002EB498[i].c >> 2] & (1 << (D_L03_002EB498[i].c & 0x1F))) != 0) {
                r = 1;
            }
            e->flag = r;
            next = i + 1;
            break;
        case 1:
            e = &D_L03_002EB498[i];
            next = i + 1;
            e->flag = 1;
            lp = (s32 **)&e->c;
            if ((*lp)[0] != 0) {
                k = 0;
                do {
                    i = 0;
                    if (func_L01_0041A4F0() != 0) {
                        i = 1;
                    } else if (e->flag != 0) {
                        s32 v = (*lp)[k];
                        if ((D_00142BA0[(u32)v >> 2] & (1 << (v & 0x1F))) != 0) {
                            i = 1;
                        } else {
                            e->flag = i;
                            goto cont1;
                        }
                    } else {
                        i = 1;
                    }
                    e->flag = i;
                cont1:
                    k++;
                    i = next;
                } while ((*lp)[k] != 0);
                goto top;
            }
            break;
        case 2:
            next = i + 1;
            D_L03_002EB498[i].flag = (D_00142BA0[(u32)D_L03_002EB498[i].c >> 2] & (1 << (D_L03_002EB498[i].c & 0x1F))) != 0;
            break;
        case 3:
            e = &D_L03_002EB498[i];
            next = i + 1;
            t = D_00142693 != 0;
            goto tail;
        case 4:
        default:
            e = &D_L03_002EB498[i];
            if (e->id == 0x1C3) {
                next = i + 1;
                e->flag = 1;
            } else {
                next = i + 1;
                t = D_00142693 != 0;
            tail:
                e->flag = t;
                e->flag = func_L01_0041A4F0();
            }
            break;
        }
        i = next;
    top:;
    } while (D_L03_002EB498[i].id != 0);
}
/* localdecomp:end func_L03_004896E0 */
