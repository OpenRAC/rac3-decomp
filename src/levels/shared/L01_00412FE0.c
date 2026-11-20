#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00412FE0);

/* localdecomp:start func_L01_004130C0 */
void func_L01_004130C0(u8 *a) {
    *(u16 *)(a + 0xE0) &= ~2;
}
/* localdecomp:end func_L01_004130C0 */

/* localdecomp:start func_L01_004130D0 */
extern f32 func_0038CED8(void *v);
extern f32 func_0038D160(f32 a, f32 b);

void func_L01_004130D0(u8 *a0)
{
    if (!(*(u16 *)(a0 + 224) & 2)) {
        *(u16 *)(a0 + 224) |= 2;
        *(f32 *)(a0 + 96) = -func_0038D160(func_0038CED8(a0 + 240), *(f32 *)(a0 + 248));
        *(f32 *)(a0 + 64) = func_0038D160(*(f32 *)(a0 + 240), *(f32 *)(a0 + 244));
    }
}
/* localdecomp:end func_L01_004130D0 */

INCLUDE_ASM("asm/levels", func_L01_00413138);

/* localdecomp:start func_L01_00413AE0 */
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038DB00(f32 a, f32 b);
s32 func_L01_00413AE0(u8 *a0, f32 s) {
    u8 *p;
    p = *(u8 **)(a0 + 140);
    if (p != 0) {
        return s * func_0038DB00(func_0038D160(*(f32 *)(p + 16) - *(f32 *)(a0 + 48), *(f32 *)(p + 20) - *(f32 *)(a0 + 52)), *(f32 *)(a0 + 64)) > 0.0f;
    }
    return 0;
}
/* localdecomp:end func_L01_00413AE0 */

INCLUDE_ASM("asm/levels", func_L01_00413B68);

/* localdecomp:start func_L01_00413F48 */
#include "vu0.h"
typedef struct { u8 p0[0x18]; u8 *p18; } T_13F48;
typedef struct { u8 p0[0x424]; f32 f424; u8 p428[0x38]; } E_13F48;
extern T_13F48 D_L01_001EAA00_00413F48;
extern vu0_q D_L01_001EAA20_00413F48;
extern u8 *D_L01_0021E860_00413F48[];
extern E_13F48 D_L01_001E2A40_00413F48[];
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038D098(f32);
extern f32 *func_00382348(u8 *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_003C4B50(void *);

void func_L01_00413F48(u8 *a0) {
    vu0_v4 *vp;
    vu0_v4 sp0;
    u8 *cand[16];
    vu0_v4 vecs[16];
    f32 dist[16];
    vu0_v4 t190;
    vu0_v4 t1A0;
    u8 *fp;
    s32 k;
    vu0_v4 *pt;
    E_13F48 *tab;
    u8 *m;
    s32 n;
    s32 i;
    f32 best;
    f32 lim;
    f32 d;
    f32 cost;
    f32 t;
    f32 dot;
    void (*fn)(u8 *) = *(void (**)(u8 *))(a0 + 0xE4);

    if (fn != 0) {
        fn(a0);
        return;
    }
    fp = *(u8 **)(a0 + 0x8C);
    *(s32 *)(a0 + 0x8C) = 0;
    *(f32 *)(a0 + 0xB0) = 0;
    func_0038CF68(&sp0, a0, *(f32 *)(a0 + 0x120));
    vec_add_ab(&sp0, &sp0, a0 + 0x30);
    if (func_003D3CB0(a0 + 0x30, &sp0, 0, *(u8 **)(a0 + 0xBC), 0) != 0) {
        u8 *p = D_L01_001EAA00_00413F48.p18;
        if (p != 0 && *(u8 **)(p + 0x24) != 0 && (*(u8 **)(p + 0x24))[0x46] == 5) {
            s32 h = *(s16 *)(p + 0xAA);
            if (h != 0x19C0 && h != 0x1AE6) {
                *(u8 **)(a0 + 0x8C) = p;
                *(f32 *)(a0 + 0xB0) = 1.0f;
            }
        }
        *(vu0_q *)(a0 + 0x110) = D_L01_001EAA20_00413F48;
    } else {
        *(vu0_q *)(a0 + 0x110) = *(vu0_q *)&sp0;
    }
    if (*(u8 **)(a0 + 0x8C) == 0) {
        n = 0;
        lim = 37000000.0f;
        tab = &D_L01_001E2A40_00413F48[*(s32 *)(a0 + 0x12C)];
        best = func_0038D098(*(f32 *)(a0 + 0x7C) * (tab->f424 / 1.1100293f));
        m = D_L01_0021E860_00413F48[0];
        if (m != 0) {
            k = 0;
            pt = &t190;
            vp = vecs;
            do {
                if (m[0x31] != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 5 &&
                    *(s32 *)(m + 0x98) != 0 && m != *(u8 **)(a0 + 0xBC) && *(s16 *)(m + 0xAA) != 0x19C0 &&
                    *(s16 *)(m + 0xAA) != 0x1AE6) {
                    f32 *r = func_00382348(m);
                    if (r != 0) {
                        *(vu0_q *)&t1A0 = 0;
                        t1A0.z = r[4];
                        t190 = t1A0;
                        func_0038D000(pt, pt, m + 0xC0);
                        vec_add_ab(&t190, &t190, m + 0x10);
                        vec_sub_ab(&t1A0, &t190, a0 + 0x30);
                        d = func_0038CEA8(&t1A0);
                        if (!(*(f32 *)(a0 + 0x120) < d)) {
                            func_0038CE20(&t1A0, &t1A0, 1.0f / d);
                            dot = func_0038CE68(&t1A0, a0);
                            if (!(dot < best)) {
                                t = (dot - best) / (1.0f - best);
                                cost = d + d * t;
                                if (func_003C4B50(m) != 0) {
                                    cost += 10.0f;
                                }
                                if (cost < lim) {
                                    lim = cost;
                                    cand[n] = m;
                                    *vp = t190;
                                    dist[n] = t;
                                    n++;
                                    vp++;
                                    if (n >= 16) break;
                                }
                            }
                        }
                    }
                }
                k++;
                m = D_L01_0021E860_00413F48[k];
            } while (m != 0);
        }
        for (i = n - 1; i >= 0; i--) {
            if (func_003D3CB0(a0 + 0x30, &vecs[i], 0, *(u8 **)(a0 + 0xBC), 0) == 0 ||
                D_L01_001EAA00_00413F48.p18 == cand[i]) {
                *(u8 **)(a0 + 0x8C) = cand[i];
                *(f32 *)(a0 + 0xB0) = dist[i];
                break;
            }
        }
    }
    if (*(u8 **)(a0 + 0x8C) != 0) {
        if (*(u8 **)(a0 + 0x8C) == fp) {
            vec_sub_ab(a0 + 0xA0, *(u8 **)(a0 + 0x8C) + 0x10, a0 + 0x90);
        }
        *(vu0_q *)(a0 + 0x90) = *(vu0_q *)(*(u8 **)(a0 + 0x8C) + 0x10);
    } else {
        qzero(a0 + 0xA0);
    }
}
/* localdecomp:end func_L01_00413F48 */

LINKER_REMNANT("asm/levels", func_L01_00414360);
