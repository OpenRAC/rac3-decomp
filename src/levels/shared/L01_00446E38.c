#include "common.h"

/* localdecomp:start func_L01_00446E38 */
#include "vu0.h"

extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003A92F0(s32);
extern s32 func_L01_003FB640_00446E38(void *, f32, s32, void *);
extern s32 func_L01_003FDCA0_00446E38(void *, s32, f32);
extern s32 func_L01_003FE1D8_00446E38(void *, s32, f32);
extern s32 func_L01_003FE378_00446E38(void *, void *, f32, s32);
extern s32 func_L01_003FE540_00446E38(void *, void *, f32, f32, s32);

extern s32 D_L01_001DFC08_00446E38;
extern s32 D_L01_001E1060_00446E38[];
extern s32 D_L01_001E1068_00446E38;
extern s32 D_L01_001E1070_00446E38;
extern s32 D_L01_001E1074_00446E38;
typedef struct { s32 w0; u8 p4[0x14]; s32 w18; u8 p1C[4]; vu0_v4 v20; vu0_v4 v30; vu0_v4 v40; } T_446E38_00446E38;
extern T_446E38_00446E38 D_L01_001EAA00_00446E38;

f32 func_L01_00446E38(void *a0, void *a1, f32 radius, s32 flags, void *obj) {
    vu0_v4 v;
    f32 len;
    f32 r;
    f32 reach;
    s32 bit8;
    s32 n;
    s32 k1;
    s32 k2;
    s32 i;
    s32 p;

    bit8 = (flags >> 8) & 1;
    func_0038CDF8(&v, a0, a1, 0.5f);
    r = 1.0f;
    len = func_0038CF00(a0, a1);
    reach = radius + len * 0.5f;
    D_L01_001DFC08_00446E38 = D_L01_001E1060_00446E38[D_L01_001E1074_00446E38] + D_L01_001E1070_00446E38 - 0x8000;
    if (D_L01_001DFC08_00446E38 < D_L01_001E1068_00446E38 + 0x1000) {
        func_003A92F0(1);
        D_L01_001DFC08_00446E38 = D_L01_001E1060_00446E38[1 - D_L01_001E1074_00446E38] + D_L01_001E1070_00446E38 - 0x8000;
    }
    flags &= 0xA7;
    flags |= 0x50;
    n = func_L01_003FB640_00446E38(&v, reach, flags, obj);
    if (flags & 0x80) {
        k1 = func_L01_003FDCA0_00446E38(&v, D_L01_001DFC08_00446E38, reach);
        n += k1;
        D_L01_001DFC08_00446E38 -= k1 << 6;
    }
    if (bit8) {
        k2 = func_L01_003FE1D8_00446E38(&v, D_L01_001DFC08_00446E38, reach);
        n += k2;
        D_L01_001DFC08_00446E38 -= k2 << 6;
    }
    if (n) {
        qzero(&D_L01_001EAA00_00446E38.v40);
        if (func_L01_003FE378_00446E38(a0, a1, radius, n)) {
            r = func_0038CF00(&D_L01_001EAA00_00446E38.v20, a0) / len;
            func_0038CF68(&D_L01_001EAA00_00446E38.v40, &D_L01_001EAA00_00446E38.v40, 1.0f);
        }
        p = D_L01_001DFC08_00446E38;
        for (i = 0; i < n; i++) {
            if (func_L01_003FE540_00446E38(a0, a1, radius, r, p)) {
                r = func_0038CF00(&D_L01_001EAA00_00446E38.v20, a0) / len;
                func_0038CF68(&D_L01_001EAA00_00446E38.v40, &D_L01_001EAA00_00446E38.v40, 1.0f);
            }
            p += 0x40;
        }
    }
    if (r < 1.0f) {
        vu0_v4 *q = &D_L01_001EAA00_00446E38.v30;
        vu0_v4 *p20 = &D_L01_001EAA00_00446E38.v20;
        *q = *p20;
        func_0038CE20(p20, &D_L01_001EAA00_00446E38.v40, -radius);
        vec_add_ba(p20, p20, q);
        if (D_L01_001EAA00_00446E38.w18 == D_L01_001EAA00_00446E38.w0) {
            D_L01_001EAA00_00446E38.w18 = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L01_00446E38 */
