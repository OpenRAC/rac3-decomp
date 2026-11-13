#include "common.h"

/* localdecomp:start func_L39_005D2AA0 */
#include "vu0.h"
extern s32 D_L39_0024112C;
extern vu0_v4 D_L39_0024DCC0;
extern void func_L39_005FFB48(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern void func_003CD250(s32);

void func_L39_005D2AA0(u8 *p) {
    u8 *m = p + 0x20;
    vu0_v4 v;
    f32 f;
    f32 scale;

    func_L39_005FFB48(p + 0x10, p + 0x10);
    func_0038CE20(m, m, 0.9f);
    *(f32 *)(m + 8) -= *(f32 *)(m + 0xC);
    vec_add_ab(p + 0x10, p + 0x10, p + 0x20);
    if (D_L39_0024112C % 10 == 0) {
        f = func_0038DAB8(*(f32 *)(m + 0x1C), 1.0f);
        *(f32 *)(m + 0x1C) = f;
        scale = func_0038D0B0(f) * 0.0075f;
        func_0038CF68(&v, &D_L39_0024DCC0, scale);
        vec_add_ab(p + 0x20, p + 0x20, &v);
    }
    if (*(s16 *)(m + 0x14) >= 160) {
        if (*(s16 *)(p + 0xA) < *(s16 *)(m + 0x14)) {
            *(u32 *)(p + 4) = ((s32)((f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(m + 0x14) * 128.0f) << 24) | 0x353535;
        } else {
            *(u32 *)(p + 4) = 0x9F353535;
        }
    } else {
        if (*(s16 *)(p + 0xA) < *(s16 *)(m + 0x14)) {
            *(u32 *)(p + 4) = ((s32)((f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(m + 0x14) * 64.0f) << 24) | 0x909090;
        } else {
            *(u32 *)(p + 4) = 0x40909090;
        }
    }
    p[8] += m[0x16];
    if (func_0038CB00(p + 0xA)) {
        func_003CD250((s32)p);
    }
}
/* localdecomp:end func_L39_005D2AA0 */
