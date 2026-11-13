#include "common.h"

typedef struct {
    u8 pad[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_1A4BE0_0034CE78;

/* localdecomp:start func_L30_0034CE78 */
extern S_1A4BE0_0034CE78 D_1A4BE0;
extern f32 D_L30_001DD4AC;
extern f32 D_L30_001DD4B0;
extern s32 func_L30_0034CF00(u8 *obj);

f32 func_L30_0034CE78(u8 *obj) {
    s32 r;

    if (obj == 0) {
        return 0.5f;
    }
    if (obj == D_1A4BE0.p25C0) {
        if (D_1A4BE0.w25C4 == 0xA3) {
            return D_L30_001DD4B0;
        }
        return D_L30_001DD4AC;
    }
    r = func_L30_0034CF00(obj);
    if (r != 0) {
        return *(f32 *)(r + 0x10);
    }
    return *(f32 *)(obj + 0xC) * 0.00048828125f;
}
/* localdecomp:end func_L30_0034CE78 */

/* localdecomp:start func_L30_0034CF00 */
s32 func_L30_0034CF00(u8 *obj) {
    s32 *p;
    if (!(*(u16 *)(obj + 52) & 0x20)) {
        return 0;
    }
    p = *(s32 **)(obj + 104);
    return *p;
}
/* localdecomp:end func_L30_0034CF00 */
