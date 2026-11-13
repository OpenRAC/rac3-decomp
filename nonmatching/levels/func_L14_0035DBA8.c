/* func_L14_0035DBA8: near miss, 95 diff: needs -mvu0-use-vf0-vf2 on L14_0035DBA8.c (its three C functions still match with it) and the divs_nops row "func_L14_0035DBA8 2"; frame, stack slots and the five .lit table copies are right (initialisers at the declarations, so the pointer table is built in the temporary that v later reuses); left: register choice in the unaligned copies (retail v0/v1/a2 through $t1), the first search loop (retail neither rotates nor strength-reduces it; a goto loop gives that shape at 113 but moves the rest), and the d/mask/sel registers ($t0/$a2/$a3)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
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
    vec_sub_ba(&v, target, a0 + 0x10);
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
