#include "common.h"

/* NTSC-U counterpart of func_L24_0034CD58 (src/levels/24_insomniac_museum/L24_0034CD58.c) */
/* localdecomp:start func_L24_0034BF10 */
#include "vu0.h"
extern void func_L01_004C4AD8(s32, void *, s32);
extern void func_L01_004C4AB8(s32);
extern void func_003BD360(void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_003CF790(f32 *, s32, f32, void *, void *);
extern s32 func_L01_0032FE90_0034BF10(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L24_0034C2C8(u8 *);
extern void func_L24_0034C480(u8 *, f32 *, f32 *);
typedef struct {
    u8 p0[0x18];
    s32 x18;
    u8 p1C[4];
    vu0_v4 x20;
} S_34CD58;
extern S_34CD58 D_L24_001E8F40_0034BF10;

void func_L24_0034BF10(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v[4];
    f32 w[4];
    u8 c[0x30];
    s32 t;
    f32 *pv;
    vu0_v4 *g;

    switch (obj[0x20]) {
    case 1:
        pv = v;
        *(vu0_q *)pv = *(vu0_q *)(obj + 0x10);
        vec_add_ba(obj + 0x10, s, obj + 0x10);
        func_L01_004C4AD8(*(s32 *)(s + 0x20), s, 0);
        *(vu0_q *)(*(u8 **)(s + 0x18) + 0x10) = *(vu0_q *)(obj + 0x10);
        *(f32 *)(*(u8 **)(s + 0x18) + 0x2C) = *(f32 *)(*(u8 **)(s + 0x18) + 0x2C) * 1.03f;
        if (0.06f < *(f32 *)(*(u8 **)(s + 0x18) + 0x2C)) {
            *(f32 *)(*(u8 **)(s + 0x18) + 0x2C) = 0.06f;
        }
        if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10)
            || *(f32 *)(obj + 0x14) < 2.0f || 1021.0f < *(f32 *)(obj + 0x14)
            || *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
            func_L01_004C4AB8(*(s32 *)(s + 0x20));
            if (*(u8 **)(s + 0x18) != 0) {
                func_003BD360(*(u8 **)(s + 0x18));
            }
            func_003BD360(obj);
            return;
        }
        *(s32 *)(s + 0x14) = *(s32 *)(s + 0x14) + 1;
        if (func_003CE740(pv, obj + 0x10, 0, *(void **)(s + 0x1C), 0) != 0) {
            g = &D_L24_001E8F40_0034BF10.x20;
            *(vu0_v4 *)(obj + 0x10) = *g;
            obj[0x20] = 2;
            *(vu0_q *)w = *(vu0_q *)s;
            func_003886E8(w, w, 3.0f);
            w[3] = 5627.9248f;
            func_L01_00443628(c, obj, 0x10001, w, *(f32 *)(s + 0x24));
            c[0x18] = 0;
            c[0x19] = 1;
            *(u16 *)(c + 0x1A) = *(u16 *)(obj + 0xAA);
            t = D_L24_001E8F40_0034BF10.x18;
            if (t != 0) {
                if (t != *(s32 *)(s + 0x1C)) {
                    func_003CF790((f32 *)g, 0, 0.3f, obj, c);
                }
            } else {
                func_003CF790((f32 *)g, 0, 0.6f, obj, c);
            }
        }
        if (*(s32 *)(s + 0x14) >= 0xB5) {
            func_003BD360(obj);
            return;
        }
        break;
    case 2:
        func_L01_0032FE90_0034BF10(obj + 0x10, 0, 15, 5, 15, 20, 0, 1, 0.25f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 1, 0, 0x1010001, 0, 0x1010FF, 0x4040FF, 0x407FFF, 0x20FF, 0x20FF, 0xFF3000, 0x7F2020FF, 0x280000FF, 0xFF2034, 0);
        func_L01_004C4AB8(*(s32 *)(s + 0x20));
        if (*(u8 **)(s + 0x18) != 0) {
            func_003BD360(*(u8 **)(s + 0x18));
            *(u8 **)(s + 0x18) = 0;
        }
        func_003BD360(obj);
        return;
    }
    func_L01_004026A0(func_L24_0034C2C8, obj);
    *(vu0_q *)w = *(vu0_q *)(obj + 0x10);
    func_L24_0034C480(obj, w, v);
}
/* localdecomp:end func_L24_0034BF10 */
