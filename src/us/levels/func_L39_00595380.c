#include "common.h"

/* NTSC-U counterpart of func_L39_00596630 (src/levels/shared/L39_00596630.c) */
/* localdecomp:start func_L39_00595380 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00596630;
typedef struct { u8 pad0[0x18]; s32 f18; u8 pad1C[4]; V_00596630 v20; V_00596630 v30; } S_00596630;
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_L01_00443D00(void *, void *, s32, f32, void *);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern f32 D_001D7168_sda_00595380;
extern f32 D_001D716C_sda_00595380;
__asm__(".extern D_001D7168_sda_00595380, 4");
__asm__(".extern D_001D716C_sda_00595380, 4");
extern S_00596630 D_L39_0025F840_00595380;

void func_L39_00595380(u8 *o, V_00596630 *a, V_00596630 *b) {
    V_00596630 v0;
    V_00596630 v10;
    V_00596630 v20;
    V_00596630 v30;
    V_00596630 v40;
    V_00596630 v50;
    V_00596630 v60;
    V_00596630 m70[3];
    f32 d;
    f32 len;
    f32 t;
    V_00596630 *pv0 = &v0;
    V_00596630 *pv10 = &v10;

    v0 = *a;
    v10 = *b;
    v30 = v0;
    vec_sub_ab(&v20, &v0, &v10);
    d = func_00388730(&v20, &v20);
    len = func_00388770(o + 0xC0);
    if (fabs_asm(d) > 0.01f) {
        t = func_L01_00443D00(pv10, &v0, 0x84, D_001D7168_sda_00595380, *(void **)(o + 0xBC));
        if (t < 1.0f) {
            if (D_L39_0025F840_00595380.f18 == 0 || t > 0.0f) {
                v0 = D_L39_0025F840_00595380.v30;
            }
        }
    }
    if (len == 0.0f) {
        *(V_00596630 *)(o + 0x30) = *pv0;
        return;
    }
    if (*(u16 *)(o + 0xE0) & 4) {
        *(u16 *)(o + 0xE0) &= ~4;
        func_003BEC60((f32 *)(o + 0x124), o + 0x128, 0.0f, 0.0222222228f, 0.0444444455f, 1.3333333731f);
    } else {
        func_003888C8(&v50, o + 0xC0, o);
        func_00388830(&v50, &v50, len + 0.5f);
        vec_add_ab(&v50, &v50, &v30);
        if (func_003CE740(pv0, &v50, 4, *(void **)(o + 0xBC), 0) != 0) {
            *(vu0_q *)&v60 = *(vu0_q *)&D_L39_0025F840_00595380.v20;
            if (D_L39_0025F840_00595380.f18 != 0 && func_003CF790(o + 0x30, 0, 0.51f, *(void **)(o + 0xBC), 0) != 0) {
                len = func_003887C8(&v30, &v60) - 0.5f;
            } else if (func_003CE740(pv0, &v50, 2, *(void **)(o + 0xBC), 0) != 0) {
                len = func_003887C8(&v30, &D_L39_0025F840_00595380.v20) - 0.5f;
            }
            if (len < 0.0f) {
                *(V_00596630 *)(o + 0x30) = *pv0;
                return;
            }
        }
        if (len < *(f32 *)(o + 0x124)) {
            *(f32 *)(o + 0x124) = len;
            *(f32 *)(o + 0x128) = 0.0f;
        } else if (len > *(f32 *)(o + 0x124)) {
            if (*(f32 *)(o + 0x128) < 0.0f) {
                *(f32 *)(o + 0x128) = 0.0f;
            }
            func_003BEC60((f32 *)(o + 0x124), o + 0x128, len, 0.00555555569f, 0.00555555569f, 0.3333333433f);
        }
    }
    func_003888C8(o + 0x30, o + 0xC0, o);
    func_00388830(&v40, o + 0x30, *(f32 *)(o + 0x124) - 1.0f);
    func_00388830(o + 0x30, o + 0x30, *(f32 *)(o + 0x124));
    vec_add_ba(o + 0x30, o + 0x30, &v30);
    vec_add_ba(&v40, &v40, pv0);
    if (func_L01_00443D00(&v40, o + 0x30, 0x104, D_001D716C_sda_00595380, *(void **)(o + 0xBC)) < 1.0f) {
        *(vu0_q *)(o + 0x30) = *(vu0_q *)&D_L39_0025F840_00595380.v30;
    }
    func_00388BD0(m70, o + 0xD0);
    func_00388EB8(o, o, m70);
}
/* localdecomp:end func_L39_00595380 */
