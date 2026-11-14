/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00446480, the NTSC-U twin of func_L01_004495F0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00448CC0.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_004495F0 (src/levels/shared/L01_00448CC0.c).
 * Byte-exact only with @ps2as added to the PAL file's flags (float constants as lui/ori/mtc1). */
/* localdecomp:start func_L01_00446480 */
#include "vu0.h"
typedef struct { vu0_v4 a; vu0_v4 b; } Rec_446480;
typedef struct { u8 pad[0x10]; f32 f10; } Hdr_446480;
extern Rec_446480 D_L01_70000000[];
extern u8 D_L01_001D66B0;
__asm__(".extern D_L01_001D66B0, 16");
extern u8 *D_L01_00221118[];
extern s32 func_003BD668(void *, s32);
extern Hdr_446480 *func_0037E0B8(void *);
extern s32 func_L01_00444800(void *, s32, void *, void *, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388770(void *);
extern f32 func_00388730(void *, void *);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L01_00446480(u8 *obj, s32 unused, void *a2) {
    vu0_v4 va;
    vu0_v4 vb;
    vu0_v4 vc;
    vu0_v4 pts[8];
    s32 n;
    s32 m;

    n = func_003BD668(obj, 0);
    if (n != 0) {
        Rec_446480 *r = (Rec_446480 *)0x70000000;
        s32 i;
        for (i = 0; i < n; i++, r++) {
            u8 *b;
            s32 life;
            s32 ang;
            s32 v;
            if (r->b.w == 0.0f) {
                va = r->a;
                va.w = 1.0f;
                func_0037E2F0(&vb, 0.0f, r->a.w);
                vec_add_ab(&va, &va, &vb);
                life = func_0037E208(10, 20);
                ang = func_0037E208(-10, 10);
                b = func_L01_0046C468(&va, &D_L01_001D66B0, life, 0xAF8080, ang, 0x40, 0, 0,
                                      r->a.w * 189000.0f, r->a.w * 420000.0f,
                                      func_0037E250(-1.0f, -2.0f) * 0.00027777778f);
                if (b != 0) {
                    v = func_0037E208(0, 3);
                    if (v == 0) {
                        b[2] = *D_L01_00221118[0x198 / 4];
                    } else if (v == 1) {
                        b[2] = *D_L01_00221118[0x5C / 4];
                    } else if (v > 1) {
                        b[2] = D_L01_00221118[0x184 / 4][0xA];
                    }
                }
            } else {
                va = r->a;
                vb = r->b;
                va.w = 1.0f;
                vb.w = 1.0f;
                func_003886C0(&vc, &va, &vb, func_0037E250(0.0f, 1.0f));
                vc.x += func_0037E250(-r->a.w * 0.4f, r->a.w * 0.4f);
                vc.y += func_0037E250(-r->a.w * 0.4f, r->a.w * 0.4f);
                vc.z += func_0037E250(-r->a.w * 0.4f, r->a.w * 0.4f);
                life = func_0037E208(10, 20);
                ang = func_0037E208(-10, 10);
                b = func_L01_0046C468(&vc, &D_L01_001D66B0, life, 0xAF8080, ang, 0x40, 0, 0,
                                      r->a.w * 189000.0f, r->a.w * 420000.0f,
                                      func_0037E250(-1.0f, -2.0f) * 0.00027777778f);
                if (b != 0) {
                    v = func_0037E208(0, 3);
                    if (v == 0) {
                        b[2] = *D_L01_00221118[0x198 / 4];
                    } else if (v == 1) {
                        b[2] = *D_L01_00221118[0x5C / 4];
                    } else if (v > 1) {
                        b[2] = D_L01_00221118[0x184 / 4][0xA];
                    }
                }
            }
        }
    } else {
        Hdr_446480 *h = func_0037E0B8(obj);
        if (h != 0 && h->f10 > 5.0f) {
            return;
        }
        m = func_L01_00444800(obj, 8, pts, a2, 6.0f);
        if (m != 0) {
            s32 i;
            for (i = 0; i < m; i++) {
                s32 add;
                s32 j;
                vec_sub_ba(&va, &pts[i], obj + 0x10);
                func_00388770(&va);
                func_003886E8(&va, &va, 0.8f);
                vec_add_ab(&pts[i], &va, obj + 0x10);
                func_00388830(&vb, &va, 1.0f);
                {
                    f32 d = func_00388730(&vb, obj + 0xE0);
                    add = (s32)(d * d * d * d * d * d * 20.0f);
                }
                for (j = 0; j >= 0; j--) {
                    u8 *b;
                    s32 life = func_0037E208(10, 20) + add;
                    s32 ang = func_0037E208(-10, 10);
                    b = func_L01_0046C468(&pts[i], &D_L01_001D66B0, life, 0x808080, ang, 0x40, 0, 0,
                                          63000.004f, 210000.0f,
                                          func_0037E250(-4.0f, -10.0f) * 0.00027777778f);
                    if (b != 0) {
                        if (func_0037E1D8(3) != 0) {
                            b[2] = D_L01_00221118[0x16C / 4][4];
                            b[3] = func_0037E1D8(4) != 0 ? 0x44 : 0x48;
                        } else {
                            b[2] = *D_L01_00221118[0x16C / 4];
                            b[3] = 0x48;
                        }
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00446480 */
