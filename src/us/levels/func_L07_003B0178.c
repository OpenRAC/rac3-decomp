#include "common.h"

/* localdecomp:start func_L07_003B0178 */
extern u8 D_001A4BE0[];
extern s32 D_L07_001ECC80[];
extern s32 func_L01_00443648(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_L01_00452F40(u8 *entity, s32 enabled);

s32 func_L07_003B0178(u8 *self) {
    u8 *st;
    f32 t;
    s32 n;
    s32 i;

    st = *(u8 **)(self + 0x68);
    if (st[0x24] != 0) {
        t = *(f32 *)(st + 0x1C);
        if (t < 1.6f) {
            if (t < 1.0f) {
                t = t * 0.7f;
            } else {
                t = 0.7f;
            }
            n = func_L01_00443648(*(s32 *)(self + 0xB8), t, (s32)st, 1, (f32)st[0x26], 1.0f, 0, 1, 0);
            for (i = 0; i < n; i++) {
                s32 e = D_L07_001ECC80[i];
                u8 *hero = D_001A4BE0;
                if (e == *(s32 *)(hero + 0x25C0)) {
                    func_L01_00452F40(*(u8 **)(self + 0xB8), 1);
                }
            }
        }
        *(f32 *)(st + 0x20) = *(f32 *)(st + 0x20) + 0.08f;
        if (*(f32 *)(st + 0x20) > 1.0f) {
            *(f32 *)(st + 0x20) = *(f32 *)(st + 0x20) - 1.0f;
        }
        if (!(*(f32 *)(st + 0x1C) < 1.0f)) {
            *(f32 *)(st + 0x1C) = *(f32 *)(st + 0x1C) + 0.03f;
            if (*(f32 *)(st + 0x1C) >= 2.0f) {
                *(f32 *)(st + 0x1C) = 2.0f;
                return 1;
            }
        } else {
            *(f32 *)(st + 0x1C) = *(f32 *)(st + 0x1C) + 0.05f;
            if (*(f32 *)(st + 0x1C) >= 1.0f) {
                *(f32 *)(st + 0x1C) = 1.0f;
            }
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L07_003B0178 */
