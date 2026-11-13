#include "common.h"

/* localdecomp:start func_L19_003AFB40 */
typedef struct { u8 pad[0x3C0]; s32 a[2]; } P_3AFB40;
typedef struct { u8 pad24[0x24]; s32 x24; u8 pad28[0x44]; s32 x6C; u8 pad70[0x24]; s32 x94; } G_3AFB40;
extern G_3AFB40 D_001CCFD0;
extern s32 D_L19_001E198C;
extern s32 D_L19_001E1990;
extern s32 D_L19_001E1984;
extern s32 D_L19_001E1988;
__asm__(".extern D_L19_001E1970, 16");
extern s32 D_L19_001E1970;
extern s32 D_L19_001DF240;
extern s32 D_L19_001DED24;
extern s32 func_00382468(s32);
extern void func_003A2B68(s32, u8 *);

void func_L19_003AFB40(u8 *obj, s32 mode) {
    u8 *p = *(u8 **)(obj + 0x68);
    s32 sel;

    if (D_001CCFD0.x6C != 0)
        return;
    if (D_001CCFD0.x24 != -1)
        return;
    if (D_001CCFD0.x94 != 0)
        return;
    sel = -1;
    if (mode == 0 && func_00382468(2) == 0 && D_L19_001E198C + 1000 < D_L19_001DF240) {
        sel = ((P_3AFB40 *)p)->a[D_L19_001E1984];
        D_L19_001E1984 = D_L19_001E1984 + 1;
        if (D_L19_001E1984 >= 2)
            D_L19_001E1984 = 0;
        D_L19_001E198C = D_L19_001DF240;
    } else if (mode == 1) {
    } else if (mode == 2) {
        if (func_00382468(2) == 0 && D_L19_001E1990 + 500 < D_L19_001DF240) {
            sel = (&D_L19_001E1970)[D_L19_001E1988++];
            if (D_L19_001E1988 >= 5)
                D_L19_001E1988 = 0;
            D_L19_001E1990 = D_L19_001DF240;
        }
    }
    if (sel != -1) {
        func_003A2B68(sel + 2000, obj);
        D_L19_001DED24 = 1;
    }
}
/* localdecomp:end func_L19_003AFB40 */
