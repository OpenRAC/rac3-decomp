/* functional: high. Near miss (95 diffs: register choice in unaligned struct copies and loop shape only); angle thresholds, selection table (l1 default), d computation, bit test and the final writes verified against PAL asm. Needs -mvu0-use-vf0-vf2. */
#include "vu0.h"
static void pv4_sub(void *d, void *a, void *b) {
    f32 *dd = (f32 *)d, *aa = (f32 *)a, *bb = (f32 *)b;
    dd[0] = aa[0] - bb[0];
    dd[1] = aa[1] - bb[1];
    dd[2] = aa[2] - bb[2];
}
static void pv4_add(void *d, void *a, void *b) {
    f32 *dd = (f32 *)d, *aa = (f32 *)a, *bb = (f32 *)b;
    dd[0] = aa[0] + bb[0];
    dd[1] = aa[1] + bb[1];
    dd[2] = aa[2] + bb[2];
}
static void pv4_zero(void *d) {
    f32 *dd = (f32 *)d;
    dd[0] = 0.0f;
    dd[1] = 0.0f;
    dd[2] = 0.0f;
    dd[3] = 0.0f;
}
typedef struct {
    f32 v[5];
} S_35DBA8_f;
typedef struct {
    u8 b[4];
} S_35DBA8_b;
typedef struct {
    u8 *p[4];
} S_35DBA8_p;
extern S_35DBA8_f D_L14_001DD720;
extern S_35DBA8_b D_L14_001DD738;
extern S_35DBA8_b D_L14_001DD740;
extern S_35DBA8_b D_L14_001DD748;
extern S_35DBA8_b D_L14_001DD750;
__asm__(".extern D_L14_001DD6E4, 4");
extern s32 D_L14_001DD6E4;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L14_0035DA48(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L14_0035DBA8(u8 *a0, void *target) {
    S_35DBA8_f thr = D_L14_001DD720;
    S_35DBA8_b l0 = D_L14_001DD738;
    S_35DBA8_b l1 = D_L14_001DD740;
    S_35DBA8_b l2 = D_L14_001DD748;
    S_35DBA8_b l3 = D_L14_001DD750;
    S_35DBA8_p tab = { { l0.b, l1.b, l2.b, l3.b } };
    vu0_v4 v;
    u8 *s;
    u8 *sel;
    f32 f;
    s32 i;
    s32 d;
    s32 b;
    u16 mask;
    s = *(u8 **)(a0 + 0x68);
    pv4_sub(&v, target, a0 + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    f = fabs_asm(func_0038D0C8(func_0038CE68(&v, a0 + 0xD0)) - 1.5707964f);
    if (0.0f < func_0038CE68(&v, a0 + 0xC0)) {
        f = 6.2831855f - f;
    }
    d = 4 - (s32)(*(f32 *)s / (f32)*(s16 *)(s + 4) * 4.0f);
    f += 0.7853982f;
    sel = l1.b;
    mask = *(u16 *)(a0 + 0x7C);
    i = 0;
    while (i < 4) {
        if (thr.v[i++] < f && f <= thr.v[i]) {
            sel = tab.p[i - 1];
            break;
        }
    }
    for (i = 0; i < 4; i++) {
        b = sel[i];
        if ((mask >> b) & 1) {
            if (d + *(s16 *)(s + 0x36) >= 5) {
                func_L14_0035DA48(a0, b);
                func_L01_004450F0(a0, 2, -1);
                *(s32 *)(s + 0x48) = b;
                *(s32 *)(s + 0x44) = (D_L14_001DD6E4 * 5 + 2) / 6;
                return;
            }
        }
    }
}
