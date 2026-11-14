#include "common.h"

/* NTSC-U counterpart of func_L24_0034F828 (src/levels/24_insomniac_museum/L24_0034F040.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern u8 *func_0037E0B8(void *);

/* localdecomp:start func_L24_0034E938 */
#include "vu0.h"
extern void func_00388E58(void *, void *);
extern void func_00388E78(void *, void *);
extern s32 func_003883C8(void *);
extern f32 func_003887C8(void *, void *);
extern void func_003BDA38(void *, s32, void *);
extern u8 *func_0037E0B8(void *);
extern u8 *func_L24_0034E6E8(f32 *, f32 *, f32, f32, f32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *D_001D52FC;
extern u8 D_L24_001E2040_0034E938[];
extern f32 D_L24_001E2180_0034E938[];
extern vu0_q D_L24_001E2190_0034E938;
__asm__(".extern D_L24_001DD4DC_0034E938, 4");
__asm__(".extern D_L24_001DD4E0_0034E938, 4");
__asm__(".extern D_L24_001DD4E4_0034E938, 4");
extern f32 D_L24_001DD4DC_0034E938;
extern f32 D_L24_001DD4E0_0034E938;
extern f32 D_L24_001DD4E4_0034E938;

void func_L24_0034E938(u8 *obj) {
    u8 *s;
    u8 *t;
    u8 *m;
    u8 *r;
    u8 m1[0x30];
    u8 m2[0x40];
    f32 v[4];
    f32 p[4];
    f32 f;

    *(s32 *)(obj + 0x98) = 0;
    s = *(u8 **)(obj + 0x68);
    func_00388E58(m1, D_L24_001E2040_0034E938);
    func_00388E78(m2, m1);
    if ((*(s32 *)(D_001D52FC + 0x1A0) & 0xC3) == 0) {
        if (func_003883C8(s + 0x164) != 0 || *(u8 **)(s + 0x15C) == 0 || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFE
            || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFD || *(u8 *)(*(u8 **)(s + 0x15C) + 0x31) == 0) {
            *(u8 **)(s + 0x15C) = 0;
            *(f32 *)(s + 0x160) = 0.0f;
        }
        *(vu0_q *)v = D_L24_001E2190_0034E938;
        v[1] = 0.0f;
        func_003BDA38(obj, 2, p);
        m = func_L24_0034E6E8(p, v, D_L24_001DD4DC_0034E938, D_L24_001DD4E0_0034E938, D_L24_001DD4E4_0034E938);
        if ((m != 0 && *(u8 **)(s + 0x15C) == 0) || *(u8 **)(s + 0x15C) == 0 || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFE
            || *(u8 *)(*(u8 **)(s + 0x15C) + 0x20) == 0xFD || *(u8 *)(*(u8 **)(s + 0x15C) + 0x31) == 0) {
            *(f32 *)(s + 0x160) = 0.0f;
            *(s16 *)(s + 0x164) = 0x14;
            *(u8 **)(s + 0x15C) = m;
            r = func_0037E0B8(m);
            if (r != 0) {
                *(f32 *)(s + 0x160) = *(f32 *)(r + 0x10);
            }
        }
        if (*(u8 **)(s + 0x15C) != 0 && func_003883C8(s + 0x168) != 0) {
            t = *(u8 **)(s + 0x15C);
            if (t == 0 || *(u8 *)(t + 0x20) == 0xFE || *(u8 *)(t + 0x20) == 0xFD) {
                *(u8 **)(s + 0x15C) = 0;
                *(f32 *)(s + 0x160) = 0.0f;
            } else {
                f = func_003887C8(D_L24_001E2180_0034E938, t + 0x10) / 150.0f;
                *(vu0_q *)v = *(vu0_q *)(*(u8 **)(s + 0x15C) + 0x10);
                v[2] = v[2] + *(f32 *)(s + 0x160);
                *(vu0_q *)(s + 0x170) = *(vu0_q *)v;
                func_L01_003F4D78(0, obj, 0xFF0FFF0F, v, 0x23, -1, 4, fabs_asm(0.9f - f * 0.65f), 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
        }
    }
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
}
/* localdecomp:end func_L24_0034E938 */
