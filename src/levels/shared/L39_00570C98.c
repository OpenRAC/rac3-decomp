#include "common.h"

/* localdecomp:start func_L39_00570C98 */
extern void func_L01_003EBA68(u8 *);
extern void func_L01_003F6048(s32, u8 *, f32);

void func_L39_00570C98(u8 *o) {
    u8 *s = (u8 *)*(s32 *)(o + 112) + 224;
    func_L01_003EBA68(o);
    if (*(s32 *)(s + 64)) {
        o[137] = 0;
        func_L01_003F6048(*(s32 *)(o + 148), o + 48, 0.5f);
    }
}
/* localdecomp:end func_L39_00570C98 */
