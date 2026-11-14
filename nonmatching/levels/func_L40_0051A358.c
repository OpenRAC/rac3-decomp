/* near miss (levels 40-53): first full draft from retail (c13, 2026-11-14), 116 aligned rows under -mvu0-use-vf0-vf2 @ps2as (the file needs both added). Structure, calls and constants follow retail. Open: retail spills prev (0x1B0) and mask (0x1B4) and keeps the p/g+0x30 VU0 values in spill slots 0x1D0/0x1C0 (register pressure: the three lqc2 of the candidate-position step are issued together; the explicit asm block below reproduces the 0x1B0 spill but leaves mask in $fp); the retry loop keeps its 'tries < 2' test in retail (ours folds it away). */
#include "common.h"

/* localdecomp:start func_L40_0051A358 */
#include "vu0.h"

#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct VT_0051A358 VT_0051A358;
typedef struct {
    u8 pad0[0x14];
    VT_0051A358 *vt;
} O_0051A358;
struct VT_0051A358 {
    u8 pad0[0x1C];
    s32 (*f1C)(O_0051A358 *, s32);
};

typedef struct {
    u8 pad0[0x18];
    u8 *p18;
} H_0051A358;

extern H_0051A358 D_L40_0025B980;
extern vu0_v4 D_L40_0025B9A0;
extern u8 D_L40_00249FC0[];
extern u8 *D_L40_00260FA8[];
__asm__(".extern D_L40_00241640, 4");
extern u8 *D_L40_00241640;

extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern O_0051A358 *func_L39_0061D7B0(u8 *);
extern s32 func_L39_006487E8(u8 *, O_0051A358 *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038D098(f32);
extern u8 *func_00382348(u8 *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

void func_L40_0051A358(u8 *g) {
    u8 *prev = PTR(g, 0x8C);
    s32 mask;
    vu0_v4 tgt;
    void *cand[16];
    vu0_v4 cpos[16];
    f32 cw[16];
    s32 found;
    s32 tries;
    s32 mode;

    if (S16(g, 0xE2) != 0) {
        mask = (S16(g, 0xE2) == 1) ? 8 : 0;
    } else {
        mask = 0x10;
    }
    PTR(g, 0x8C) = 0;
    F32(g, 0xB0) = 0.0f;
    found = 0;
    tries = 0;
    func_0038CF68(&tgt, g, F32(g, 0x120));
    vec_add_ab(&tgt, &tgt, g + 0x30);
    mode = 0;
    while (func_003D3CB0(g + 0x30, &tgt, mode, PTR(g, 0xBC), 0) != 0 && tries < 2) {
        s32 ok = 0;
        if (D_L40_0025B980.p18 != 0 && (U16(D_L40_0025B980.p18, 0x34) & 0x1000)) {
            ok = (U8(D_L40_0025B980.p18, 0xBE) & mask) != 0;
            if (!ok) {
                O_0051A358 *o = func_L39_0061D7B0(D_L40_0025B980.p18);
                if (o != 0) {
                    ok = 1;
                    if (o->vt->f1C(o, S16(g, 0xE2)) == 0 && func_L39_006487E8(D_L40_0025B980.p18, o) == 0) {
                        ok = 0;
                        PTR(g, 0x8C) = D_L40_0025B980.p18;
                        F32(g, 0xB0) = 1.0f;
                    }
                }
            }
        }
        if (ok == 0 || tries != 0 || !(func_L01_0040E548(g + 0x30, &D_L40_0025B9A0) < 25.0f)) {
            found = 1;
            *(vu0_v4 *)(g + 0x110) = D_L40_0025B9A0;
            break;
        }
        tries++;
        mode = 2;
    }
    if (!found) {
        *(vu0_v4 *)(g + 0x110) = tgt;
    }
    if (PTR(g, 0x8C) == 0 && F32(g, 0x120) != 0.0f) {
        s32 n = 0;
        s32 i;
        f32 best = 37000000.0f;
        f32 cosl = func_0038D098(F32(g, 0x7C) * (F32(D_L40_00249FC0 + S32(g, 0x12C) * 0x460, 0x424) / 1.1100293f));
        for (i = 0; i < 0x100; i++) {
            u8 *e = D_L40_00260FA8[i];
            u8 *m;
            vu0_v4 p;
            vu0_v4 d;
            f32 dist;
            f32 dot;
            f32 w;
            f32 score;
            O_0051A358 *o;
            if (e == 0 || S32(e, 0x98) == 0 || e == PTR(g, 0xBC)) {
                continue;
            }
            if (S32(D_L40_00241640, 0x180) != 2 && (U8(e, 0xBE) & mask)) {
                continue;
            }
            if (U8(e, 0x31) == 0) {
                continue;
            }
            m = func_00382348(e);
            if (m == 0) {
                continue;
            }
            *(vu0_q *)&d = 0;
            d.z = F32(m, 0x10);
            p = d;
            func_0038D000(&p, &p, e + 0xC0);
            {
                vu0_q qp;
                vu0_q qg;
                vu0_q qe;
                vu0_q qr;
                __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(p));
                __asm__("lqc2 %0, %1" : "=j"(qg) : "m"(*(vu0_v4 *)(g + 0x30)));
                __asm__("lqc2 %0, %1" : "=j"(qe) : "m"(*(vu0_v4 *)(e + 0x10)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qp), "j"(qe));
                __asm__("sqc2 %1, %0" : "=m"(p) : "j"(qr));
                __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(p));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qp), "j"(qg));
                __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qr));
            }
            dist = func_0038CEA8(&d);
            if (F32(g, 0x120) < dist) {
                continue;
            }
            func_0038CE20(&d, &d, 1.0f / dist);
            dot = func_0038CE68(&d, g);
            if (dot < cosl) {
                continue;
            }
            w = (dot - cosl) / (1.0f - cosl);
            score = dist + (dist + dist) * (1.0f - w);
            o = func_L39_0061D7B0(e);
            if (o != 0 && PTR(g, 0x130) != 0 && o->vt->f1C(o, S32(PTR(g, 0x130), 0x2548)) != 0) {
                continue;
            }
            if (!(score < best)) {
                continue;
            }
            if (o != 0 && func_L39_006487E8(e, o) != 0) {
                continue;
            }
            best = score;
            cand[n] = e;
            cpos[n] = p;
            cw[n] = w;
            n++;
            if (n >= 16) {
                break;
            }
        }
        for (i = n - 1; i >= 0; i--) {
            if (func_003D3CB0(g + 0x30, &cpos[i], 0, PTR(g, 0xBC), 0) == 0 || D_L40_0025B980.p18 == cand[i] ||
                (S16(cand[i], 0xAA) == 0x109F && D_L40_0025B980.p18 != 0 && S16(D_L40_0025B980.p18, 0xAA) == 0x109E)) {
                F32(g, 0xB0) = cw[i];
                PTR(g, 0x8C) = cand[i];
                break;
            }
        }
    }
    if (PTR(g, 0x8C) != 0) {
        if (PTR(g, 0x8C) == prev) {
            vec_sub_ab(g + 0xA0, PTR(g, 0x8C) + 0x10, g + 0x90);
            if (func_0038CEA8(g + 0xA0) > 0.2f) {
                func_0038CF68(g + 0xA0, g + 0xA0, 0.2f);
            }
        }
        *(vu0_v4 *)(g + 0x90) = *(vu0_v4 *)(PTR(g, 0x8C) + 0x10);
    } else {
        qzero(g + 0xA0);
    }
}
/* localdecomp:end func_L40_0051A358 */
