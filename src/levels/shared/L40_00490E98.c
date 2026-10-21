#include "common.h"

typedef int u128_48EF48 __attribute__((mode(TI)));
typedef struct {
    u128_48EF48 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    s32 x1C;
} E_48EF48;

/* localdecomp:start func_L40_00490E98 */


extern void func_L01_004A0A78_00490E98(void *);
extern s32 D_L40_00248624;
extern u8 D_L40_002433D8[];
extern E_48EF48 D_L40_002916E0[];

s32 func_L40_00490E98(u128_48EF48 *a0, f32 f12, f32 f13, f32 f14) {
    E_48EF48 *e;
    if (D_L40_00248624 >= 128) {
        func_L01_004A0A78_00490E98(D_L40_002433D8);
    }
    e = &D_L40_002916E0[D_L40_00248624++];
    e->pos = *a0;
    e->x10 = f12;
    e->x14 = f13;
    e->x18 = f14;
    return e->x1C;
}
/* localdecomp:end func_L40_00490E98 */
