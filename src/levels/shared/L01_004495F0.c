#include "common.h"

/* localdecomp:start func_L01_004495F0 */
#include "vu0.h"
typedef struct { vu0_v4 a; vu0_v4 b; } Rec_446480;
typedef struct { u8 pad[0x10]; f32 f10; } Hdr_446480;
extern u8 D_L01_001D66B0;
__asm__(".extern D_L01_001D66B0, 16");
extern u8 *D_L01_00221098[];
extern s32 func_003C2B88(void *, s32);
extern Hdr_446480 *func_00382348(void *);
extern s32 func_L01_00447938(void *, s32, void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L01_004495F0(u8 *obj, s32 unused, void *a2) {
    vu0_v4 va;
    vu0_v4 vb;
    vu0_v4 vc;
    vu0_v4 pts[8];
    s32 n;
    s32 m;

    n = func_003C2B88(obj, 0);
    if (n != 0) {
        volatile Rec_446480 *vr = (volatile Rec_446480 *)0x70000000;
        Rec_446480 *r = (Rec_446480 *)vr;
        s32 i;
        for (i = 0; i < n; i++, r++) {
            u8 *b;
            s32 v;
            if (r->b.w == 0.0f) {
                va = r->a;
                va.w = 1.0f;
                func_00382580(&vb, 0.0f, r->a.w);
                vec_add_ab(&va, &va, &vb);
                {
                s32 life = (func_00382498(10, 20) * 5 + 2) / 6;
                s32 ang = func_00382498(-10, 10);
                b = func_L01_0046FB40(&va, &D_L01_001D66B0, life, 0xAF8080, ang, 0x40, 0, 0,
                                      r->a.w * 189000.0f, r->a.w * 420000.0f,
                                      func_003824E0(-1.0f, -2.0f) * 0.0004000000189f);
                }
                if (b != 0) {
                    v = func_00382498(0, 3);
                    if (v == 0) {
                        b[2] = *D_L01_00221098[0x198 / 4];
                    } else if (v == 1) {
                        b[2] = *D_L01_00221098[0x5C / 4];
                    } else if (v > 1) {
                        b[2] = D_L01_00221098[0x184 / 4][0xA];
                    }
                }
            } else {
                va = r->a;
                vb = r->b;
                va.w = 1.0f;
                vb.w = 1.0f;
                func_0038CDF8(&vc, &va, &vb, func_003824E0(0.0f, 1.0f));
                vc.x += func_003824E0(-r->a.w * 0.4f, r->a.w * 0.4f);
                vc.y += func_003824E0(-r->a.w * 0.4f, r->a.w * 0.4f);
                vc.z += func_003824E0(-r->a.w * 0.4f, r->a.w * 0.4f);
                {
                s32 life = (func_00382498(10, 20) * 5 + 2) / 6;
                s32 ang = func_00382498(-10, 10);
                b = func_L01_0046FB40(&vc, &D_L01_001D66B0, life, 0xAF8080, ang, 0x40, 0, 0,
                                      r->a.w * 189000.0f, r->a.w * 420000.0f,
                                      func_003824E0(-1.0f, -2.0f) * 0.0004000000189f);
                }
                if (b != 0) {
                    v = func_00382498(0, 3);
                    if (v == 0) {
                        b[2] = *D_L01_00221098[0x198 / 4];
                    } else if (v == 1) {
                        b[2] = *D_L01_00221098[0x5C / 4];
                    } else if (v > 1) {
                        b[2] = D_L01_00221098[0x184 / 4][0xA];
                    }
                }
            }
        }
    } else {
        Hdr_446480 *h = func_00382348(obj);
        if (h != 0 && h->f10 > 5.0f) {
            return;
        }
        m = func_L01_00447938(obj, 8, pts, a2, 6.0f);
        if (m != 0) {
            s32 i;
            for (i = 0; i < m; i++) {
                s32 add;
                s32 j;
                vec_sub_ba(&va, &pts[i], obj + 0x10);
                func_0038CEA8(&va);
                func_0038CE20(&va, &va, 0.8f);
                vec_add_ab(&pts[i], &va, obj + 0x10);
                func_0038CF68(&vb, &va, 1.0f);
                {
                    f32 d = func_0038CE68(&vb, obj + 0xE0);
                    add = (s32)(d * d * d * d * d * d * 20.0f);
                }
                for (j = 0; j >= 0; j--) {
                    u8 *b;
                    {
                s32 life = ((func_00382498(10, 20) + add) * 5 + 2) / 6;
                    s32 ang = func_00382498(-10, 10);
                    b = func_L01_0046FB40(&pts[i], &D_L01_001D66B0, life, 0x808080, ang, 0x40, 0, 0,
                                          63000.004f, 210000.0f,
                                          func_003824E0(-4.0f, -10.0f) * 0.0004000000189f);
                }
                    if (b != 0) {
                        if (func_00382468(3) != 0) {
                            b[2] = D_L01_00221098[0x16C / 4][4];
                            b[3] = func_00382468(4) != 0 ? 0x44 : 0x48;
                        } else {
                            b[2] = *D_L01_00221098[0x16C / 4];
                            b[3] = 0x48;
                        }
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L01_004495F0 */
