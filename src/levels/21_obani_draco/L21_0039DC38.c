#include "common.h"

/* localdecomp:start func_L21_0039DC38 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    f32 f10;
    s32 f14;
} V_0039DC38;

extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L21_003B2A40(void *, s32);
extern void func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern u8 D_1A4C60[];
__asm__(".extern D_L21_001D66B0, 16");
extern u8 D_L21_001D66B0;
extern u16 *D_L21_0021B860[];
extern u8 *D_L21_001DED9C;
__asm__(".extern D_L21_001DED9C, 16");
extern s32 D_L21_001DEDD8;

void func_L21_0039DC38(u8 *m) {
    u8 state = m[0x20];
    V_0039DC38 *v = *(V_0039DC38 **)(m + 0x68);
    u8 *e;
    u16 *p;

    switch (state) {
    case 0:
        if (v->f4 == -1) {
            func_L01_004450F0(m, 2, -1);
        } else if (v->fC == -1) {
            v->f0 = (v->f4 * 5 + 2) / 6;
            func_L01_004450F0(m, 3, -1);
        } else {
            v->f0 = (v->f4 * 5 + 2) / 6;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_0038CAD0(v)) {
            func_L01_004450F0(m, 2, -1);
            if (v->f10 < func_0038CF00(m + 0x10, D_1A4C60)) {
                func_L21_003B2A40(m, v->f14);
                func_L01_0046B458(m + 0x10, 0x21, 10.0f, 15.0f, 0xAF076007, 0, 2, &D_L21_001D66B0, 0.0f, 0);
                func_L01_0046B458(m + 0x10, 0x21, 8.0f, 12.0f, 0x7F7F7F7F, 0, 2, &D_L21_001D66B0, 0.0f, 0);
            }
            {
                u8 *o = D_L21_001DED9C + (v->fC << 8);
                (*(V_0039DC38 **)(o + 0x68))->f0 = (v->f8 * 5 + 2) / 6;
                o[0x20] = state;
            }
        }
        break;
    case 3:
        if (func_0038CAD0(v)) {
            if (v->f10 < func_0038CF00(m + 0x10, D_1A4C60)) {
                p = D_L21_0021B860[m[0x21]];
                while (m[0x21] != 0xFF && m[0x21] <= D_L21_001DEDD8 && p != 0 &&
                       ((s16)p[-1] >= 0 || p == D_L21_0021B860[m[0x21]])) {
                    e = D_L21_001DED9C + ((*p & 0x7FFF) << 8);
                    if (e == 0) break;
                    if (*(s16 *)(e + 0xAA) == *(s16 *)(m + 0xAA)) {
                        func_L21_003B2A40(e, v->f14);
                        func_L01_0046B458(e + 0x10, 0x21, 2.0f, 7.0f, 0xAF076007, 0, 2, &D_L21_001D66B0, 0.0f, 0);
                        func_L01_0046B458(e + 0x10, 0x21, 0.5f, 3.0f, 0x7F7F7F7F, 0, 2, &D_L21_001D66B0, 0.0f, 0);
                    }
                    p++;
                }
            }
            v->f0 = (v->f4 * 5 + 2) / 6;
        }
        break;
    }
}
/* localdecomp:end func_L21_0039DC38 */
