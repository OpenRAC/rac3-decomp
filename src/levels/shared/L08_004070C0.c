#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L08_004070C0 */
typedef struct { u8 pad0[0x1A0]; u8 *mobys[1]; } G_4070C0;
extern G_4070C0 D_L08_001E6080_004070C0;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(void *, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L08_00406AB0(void *, s32, s32, s32, f32, f32, f32);

void func_L08_004070C0(s32 idx, vu0_v4 *pos, s32 n1, s32 n2, s32 p4, s32 p5, s32 p6, s32 p7, f32 sz1, f32 sz2, s32 extra) {
    u8 *e;
    vu0_v4 base;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    s32 i;

    base = *pos;
    v30 = *pos;
    e = D_L08_001E6080_004070C0.mobys[idx];
    vec_add_ab(&v30, e + 0x10, &v30);
    if (n1 > 0) {
        vu0_v4 *q10 = &v10;
        vu0_v4 *q20 = &v20;
        i = n1;
        do {
            v10 = v30;
            func_003C4C18(q10, 1.0f);
            qzero(&v20);
            v20.z = func_003824E0(0.0f, 0.030000001f);
            func_L01_0046C470(q10, q20, p6, sz1 * func_003824E0(0.2f, 0.5f), p4, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
            i--;
        } while (i != 0);
    }
    if (n2 > 0) {
        vu0_v4 *q10 = &v10;
        vu0_v4 *q20 = &v20;
        i = n2;
        do {
            v10 = v30;
            func_003C4C18(q10, 0.3f);
            qzero(&v20);
            v20.z = func_003824E0(0.0f, 0.010000001f);
            func_L01_0046C470(q10, q20, p7, sz2 * func_003824E0(1.5f, 2.5f), p5, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
            i--;
        } while (i != 0);
    }
    func_L08_00406AB0(e, extra, extra, 10, 3.0f, 7.0f, 3.0f);
}
/* localdecomp:end func_L08_004070C0 */
