#include "common.h"

/* NTSC-U counterpart of func_L21_0039DC38 (src/levels/21_obani_draco/L21_0039DC38.c) */
/* localdecomp:start func_L21_0039C358 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    f32 f10;
    s32 f14;
} V_0039DC38;

extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_00388398(void *);
extern f32 func_003887C8(void *, void *);
extern void func_L21_003B0E68(void *, s32);
extern void func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern u8 D_001A4C60[];
__asm__(".extern D_L21_001D66B0_0039C358, 16");
extern u8 D_L21_001D66B0_0039C358;
extern u16 *D_L21_0021B8E0[];
extern u8 *D_L21_001DEE1C;
__asm__(".extern D_L21_001DEE1C, 16");
extern s32 D_L21_001DEE58;

void func_L21_0039C358(u8 *m) {
    u8 state = m[0x20];
    V_0039DC38 *v = *(V_0039DC38 **)(m + 0x68);
    u8 *e;
    u16 *p;

    switch (state) {
    case 0:
        if (v->f4 == -1) {
            func_L01_00441FB8(m, 2, -1);
        } else if (v->fC == -1) {
            v->f0 = v->f4;
            func_L01_00441FB8(m, 3, -1);
        } else {
            v->f0 = v->f4;
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 1:
        if (func_00388398(v)) {
            func_L01_00441FB8(m, 2, -1);
            if (v->f10 < func_003887C8(m + 0x10, D_001A4C60)) {
                func_L21_003B0E68(m, v->f14);
                func_L01_00467DA8(m + 0x10, 0x28, 10.0f, 15.0f, 0xAF076007, 0, 2, &D_L21_001D66B0_0039C358, 0.0f, 0);
                func_L01_00467DA8(m + 0x10, 0x28, 8.0f, 12.0f, 0x7F7F7F7F, 0, 2, &D_L21_001D66B0_0039C358, 0.0f, 0);
            }
            {
                u8 *o = D_L21_001DEE1C + (v->fC << 8);
                (*(V_0039DC38 **)(o + 0x68))->f0 = v->f8;
                o[0x20] = state;
            }
        }
        break;
    case 3:
        if (func_00388398(v)) {
            if (v->f10 < func_003887C8(m + 0x10, D_001A4C60)) {
                p = D_L21_0021B8E0[m[0x21]];
                while (m[0x21] != 0xFF && m[0x21] <= D_L21_001DEE58 && p != 0 &&
                       ((s16)p[-1] >= 0 || p == D_L21_0021B8E0[m[0x21]])) {
                    e = D_L21_001DEE1C + ((*p & 0x7FFF) << 8);
                    if (e == 0) break;
                    if (*(s16 *)(e + 0xAA) == *(s16 *)(m + 0xAA)) {
                        func_L21_003B0E68(e, v->f14);
                        func_L01_00467DA8(e + 0x10, 0x28, 2.0f, 7.0f, 0xAF076007, 0, 2, &D_L21_001D66B0_0039C358, 0.0f, 0);
                        func_L01_00467DA8(e + 0x10, 0x28, 0.5f, 3.0f, 0x7F7F7F7F, 0, 2, &D_L21_001D66B0_0039C358, 0.0f, 0);
                    }
                    p++;
                }
            }
            v->f0 = v->f4;
        }
        break;
    }
}
/* localdecomp:end func_L21_0039C358 */
