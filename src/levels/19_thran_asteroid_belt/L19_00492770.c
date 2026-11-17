#include "common.h"

/* localdecomp:start func_L19_00492770 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_492770;
extern E_492770 D_L19_002EF138[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_L19_001D9418;
__asm__(".extern D_L19_001D9418, 4");

void func_L19_00492770(void) {
    s32 i = 0;
    s32 n;
    while (D_L19_002EF138[i].f0 != 0) {
        switch (D_L19_002EF138[i].mode) {
        case 1: {
            s32 k;
            D_L19_002EF138[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L19_002EF138[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if ((D_L19_002EF138[i].flag && (D_00142BA0[D_L19_002EF138[i].c.list[k] >> 2] & (1 << (D_L19_002EF138[i].c.list[k] & 31)))) || D_L19_001D9418) v = 1;
                D_L19_002EF138[i].flag = v;
            }
            break;
        }
        case 0:
        case 2: {
            E_492770 *e = &D_L19_002EF138[i];
            u8 v = 0;
            if ((D_00142BA0[D_L19_002EF138[i].c.bit >> 2] & (1 << (D_L19_002EF138[i].c.bit & 31))) || D_L19_001D9418) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3: {
            E_492770 *e = &D_L19_002EF138[i];
            u8 v = 0;
            if (D_00142693[0] || D_L19_001D9418) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 4:
        default:
            D_L19_002EF138[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L19_00492770 */
