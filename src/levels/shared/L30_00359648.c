#include "common.h"

/* localdecomp:start func_L30_00359648 */
extern u8 D_001A4C60[];
extern s32 D_L30_001DDAE0;

extern int func_00382380(void *, int, int);
extern void func_L30_003582E0(int, int);

void func_L30_00359648(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    int i;
    int *p = (int *)(vars + 160);
    for (i = 0; i < 4; i++, p++) {
        int id = p[-24];
        if (id != -1 && func_00382380(D_001A4C60, id, 0)) {
            D_L30_001DDAE0 = *p;
        }
    }
    if (func_00382380(D_001A4C60, *(int *)(vars + 88), 0)) {
        func_L30_003582E0(3173, 80);
    }
}
/* localdecomp:end func_L30_00359648 */

/* localdecomp:start func_L30_003596E8 */
extern s32 D_00142BC0[];
extern s32 D_L30_001DDAE0;
extern s32 D_L30_001DDAE4;
extern u8 D_L30_001E8DC0[];
extern void func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
void func_L30_003596E8(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    unsigned long t;
    D_L30_001DDAE0 = 0;
    D_L30_001DDAE4 = 0;
    t = D_00142BC0[0];
    if (!((t >> 3) & 1)) {
        func_00392B20(D_L30_001E8DC0, 35);
        func_00392C78(D_L30_001E8DC0);
        *(s32 *)(s1 + 212) = 1;
    }
}
/* localdecomp:end func_L30_003596E8 */
