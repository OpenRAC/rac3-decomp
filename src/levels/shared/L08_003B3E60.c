#include "common.h"

/* localdecomp:start func_L08_003B3E60 */
#include "vu0.h"

extern u8 D_001D558C;
__asm__(".extern D_001D558C, 16");
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00456160(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L08_003B3E60(u8 *o) {
    u8 *st;
    u8 *m;
    vu0_v4 v;

    st = *(u8 **)(o + 0x68);
    if (o[0x31] != 0) {
        func_L01_00451DB8(o, st, 0x80909090, 0x80404040, 0.097738445f);
    }
    if (*(s32 *)(st + 4) != 0) {
        if (o[0x20] == 0) {
            if (D_001D558C != 0) {
                o[0x20] = 1;
                m = func_003C24B0(0x1BBE, 0x80);
                func_0038CF68(&v, o + 0xC0, -3.0f);
                func_L01_00456160(m, o);
                vec_add_ba(m + 0x10, m + 0x10, &v);
                func_0038DAB8(*(f32 *)(m + 0xF8), 3.1415927f);
                func_0038D308(m + 0xC0, m + 0xF0);
                *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 4.0f;
                if (o[0x43] != 3) {
                    func_003C3A10(o, 3, 0, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L08_003B3E60 */
