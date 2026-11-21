/* functional: high. Written from the retail asm (no draft); same size (557 words) and identical call sequence as retail, diffs are register/schedule only. VU0 vadd/vsub via two local inline-asm helpers (lqc2/vadd.xyz/sqc2 with vf1/vf2). Hit-record globals reached as D_L01_001EAA00 + 0x18/0x20/0x40. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_004E8318 */
extern u8 D_001A4BE0[];
extern u8 D_L01_001EAA00[];
static __inline__ void v8318_add(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void v8318_sub(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
s32 func_L01_004E8318(vu0_v4 *pos, void *unused, u8 *out) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038CE68(void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D160(f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern s32 func_003D5630(void);
    extern u8 *func_00382348(void *);
    extern u8 *func_003C4D58(void *);
    extern f32 func_L01_005114B0(void *);
    extern void func_L01_00511508(void *, void *, f32);
    extern f32 func_L01_00511848(void *);
    extern s32 func_L01_003FB640(void *, s32, s32, f32);
    vu0_v4 vA, vB, vC, vD, vE, vF, vG, vH, vI, vJ, vK, vL, vM, vN, vO, vP, vQ, vR, vS, vT;
    u8 *h = D_001A4BE0;
    u8 *hit = D_L01_001EAA00;
    s32 flag = 0;
    s32 i, found, ok;
    s32 moby, x;
    f32 f20, f21, f22, f23, f24, f25, f26, f27, dist, sum;
    u8 *r1;
    u8 *r2;

    if (out) *(s32 *)(out + 0x28) = 0;
    if (*(s16 *)(h + 0x1D0) != 0) return 0;
    if (h[0x25E4] == 0) {
        s32 c = *(s32 *)(h + 0x25CC);
        s32 state;
        if (c == 4 && (h[0x46E] != 0 || func_L01_005114B0(h + 0xF0) < 0.07000000774860382f)) flag = 1;
        else {
            state = *(s32 *)(h + 0x25C4);
            if (c == 2 || state == 8 || state == 0x19 || state == 0x1A) flag = 1;
        }
        if (*(s32 *)(h + 0x25C4) == 0xE && *(f32 *)(h + 0xC18) < 37.0f) flag = 0;
    }
    if (h[0x25E4] == 1) {
        s32 c = *(s32 *)(h + 0x25CC);
        s32 state = *(s32 *)(h + 0x25C4);
        if ((c == 4 && h[0x46E] != 0) || c == 2 || state == 0x4B || state == 0x49 || state == 0x4A) flag = 1;
    }
    if ((u8 *)out != h + 0x500) flag = 1;
    if (!flag) return 0;

    f24 = -0.699999988079071f;
    f22 = 0.30000001192092896f;
    f21 = 1.5f;
    f20 = 1.149999976158142f;
    f26 = -1.4299999475479126f;
    f27 = 1.7999999523162842f;
    f25 = 0.5f;
    if (h[0x25E4] == 1) {
        f20 = 0.699999988079071f;
        f24 = -0.4000000059604645f;
        f22 = 0.25f;
        f27 = f20;
        f21 = 0.7250000238418579f;
        f26 = -0.7099999785423279f;
        f25 = 0.3199999928474426f;
    }
    f23 = 0.3490658402442932f;
    vA = *pos;
    func_0038CF68(&vE, h, *(f32 *)(h + 0x284));
    v8318_add(&vA, &vA, &vE);
    func_0038CF68(&vE, h + 0x20, f21 + 0.15000000596046448f);
    found = 0;
    v8318_add(&vB, &vA, &vE);
    func_0038CF68(&vE, h + 0x20, -f20);
    i = 0;
    v8318_add(&vC, &vA, &vE);
    func_0038CF68(&vD, h, f22 * 0.25f);
    do {
        v8318_add(&vB, &vB, &vD);
        v8318_add(&vC, &vC, &vD);
        if (func_003D3CB0(&vB, &vC, 4, *(s32 *)(h + 0x25C0), 0)) {
            s32 t = func_003D5630();
            if (t != 9 && t != 12 && t != 0) {
                if (func_L01_00511848(hit + 0x40) < f23) found = 1;
            }
        }
        if (found) break;
        i++;
    } while (i < 4);
    if (!found) return 0;

    moby = 0;
    if (*(s32 *)(hit + 0x18) != 0) {
        x = 0;
        r1 = func_00382348(*(void **)(hit + 0x18));
        r2 = func_003C4D58(*(void **)(hit + 0x18));
        if (r1 && (*(u16 *)(r1 + 0x1E) & 1)) x = 1;
        else if (r2) x = *(s32 *)(r2 + 0x3C) & 1;
        if (!x) return 0;
        moby = *(s32 *)(hit + 0x18);
    }
    if (out) *(s32 *)(out + 0x38) = *(s32 *)(hit + 0x18);
    vG = *(vu0_v4 *)(hit + 0x20);
    v8318_sub(&vF, &vG, pos);
    if (f21 < func_L01_005114B0(&vF)) return 0;
    func_0038CF68(&vH, h + 0x20, 0.004999999888241291f);
    v8318_add(&vH, &vH, &vG);
    func_0038CF68(&vI, h, -1.0f);
    v8318_add(&vI, &vI, &vH);
    if (func_003D3CB0(&vI, &vH, 2, *(s32 *)(h + 0x25C0), 0)) {
        s32 w = *(s32 *)(hit + 0x18);
        if (w == 0) return 0;
        if (w != moby) return 0;
    }
    if (out) {
        func_0038CF68(&vJ, h + 0x20, 0.6000000238418579f);
        v8318_add(&vJ, &vJ, &vG);
        if (func_L01_003FB640(&vJ, 4, *(s32 *)(h + 0x25C0), 0.44999998807907104f))
            *(s32 *)(out + 0x34) |= 1;
        else
            *(s32 *)(out + 0x34) &= ~1;
    }
    dist = func_L01_005114B0(&vF);
    sum = dist + *(f32 *)(h + 0x33C);
    if (sum < f27) return 0;
    if (dist < 0.5f) return 0;
    qzero(&vL);
    vL.x = 1.0f;
    vL.z = f24;
    func_0038D000(&vL, &vL, h);
    ok = 0;
    i = 0;
    v8318_add(&vL, &vL, &vG);
    v8318_sub(&vJ, pos, &vL);
    func_L01_00511508(&vJ, &vJ, 0.0f);
    v8318_add(&vJ, &vJ, &vL);
    func_0038CF68(&vK, h + 0x20, -f24 / 5.0f);
    while (i < 5) {
        if (func_003D3CB0(&vJ, &vL, 2, 0, 0)) {
            func_0038CF68(&vM, hit + 0x40, 1.0f);
            ok = 1;
            func_L01_00511508(&vM, &vM, 0.0f);
            break;
        }
        v8318_add(&vJ, &vJ, &vK);
        i++;
        v8318_add(&vL, &vL, &vK);
    }
    if (!ok) return 0;
    {
        f32 a = func_0038CE68(h);
        if (!(a < func_0038D098(1.1344640254974365f))) return 0;
    }
    vS = vG;
    func_0038CF68(&vR, h + 0x2E0, -0.05000000074505806f);
    f20 = 0.0f;
    func_0038CF68(&vQ, &vM, 0.029999999329447746f);
    v8318_add(&vP, &vQ, &vR);
    v8318_sub(&vQ, &vQ, &vR);
    v8318_add(&vN, &vS, &vQ);
    v8318_add(&vO, &vS, &vP);
    do {
        if (!func_003D3CB0(&vO, &vN, 4, *(s32 *)(h + 0x25C0), 0)) {
            if (out) {
                *(vu0_v4 *)(out + 0x10) = vS;
                func_0038CF68(&vT, &vM, f25);
                func_0038CF68(out, h + 0x2E0, -f26);
                v8318_add((vu0_v4 *)out, &vT, (vu0_v4 *)out);
                v8318_add((vu0_v4 *)out, (vu0_v4 *)(out + 0x10), (vu0_v4 *)out);
                *(f32 *)(out + 0x24) = func_0038D160(vM.x, vM.y);
                *(s32 *)(out + 0x28) = 1;
            }
            return 1;
        }
        f20 += 0.029999999329447746f;
        vS = *(vu0_v4 *)(hit + 0x20);
        v8318_add(&vO, &vS, &vP);
        v8318_add(&vN, &vS, &vQ);
    } while (f20 < 2.4000000953674316f);
    return 0;
}
/* localdecomp:end func_L01_004E8318 */
