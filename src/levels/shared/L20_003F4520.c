#include "common.h"

/* localdecomp:start func_L20_003F4520 */
extern s32 D_L20_001DF430;
extern s32 D_L20_001DF434;
extern s32 D_L20_001DF438;
extern s32 D_L20_001DF43C;
extern s32 D_L20_001DF440;
extern s32 D_L20_001DF444;
extern s32 D_L20_001DF448;
extern s32 D_L20_001DF44C;
extern s32 D_L20_001DF450;
extern s32 D_L20_001DF454;

void func_L20_003F4520(s32 *sel, s32 *o1, s32 *o2, s32 *o3) {
    switch (*sel) {
    case 0:
        *o1 = D_L20_001DF430;
        *o2 = D_L20_001DF434;
        break;
    case 1:
        *o1 = D_L20_001DF438;
        *o2 = D_L20_001DF43C;
        *o3 = 0;
        break;
    case 2:
        *o1 = D_L20_001DF440;
        *o2 = D_L20_001DF444;
        *o3 = 1;
        break;
    case 3:
        *o1 = D_L20_001DF448;
        *o2 = D_L20_001DF44C;
        *o3 = 0;
        break;
    case 4:
        *o1 = D_L20_001DF450;
        *o2 = D_L20_001DF454;
        *o3 = 0;
        break;
    }
}
/* localdecomp:end func_L20_003F4520 */
