/* PAL near miss: 36 differing words with PROPOSED whole-file
 * -mvu0-use-vf0-vf2 flags and required divs_nops row
 * "func_L14_0035DBA8 2", not the centrally retained owning configuration.
 * Future integration requires the real two-argument declaration
 * void func_L14_0035DBA8(void *, void *);
 * and DE68 must call func_L14_0035DBA8(arg0, arg1), forwarding its defined
 * incoming second argument. These source/config changes are prerequisites,
 * not part of central draft-only retention.
 * P02: incomplete small-table declarations recover retail's
 * split-address unaligned copies; separate search/selection counters improve
 * allocation; typed choice/time stores recover the final GP-load ordering.
 * Retail/caller dataflow proves target is a defined second argument.
 * Existing three C neighbours check MATCH with explicit forwarding and vf2.
 * Original-source full level-14 baseline MATCHES with complete --setup.
 * Earlier failures without --setup were incomplete/stale setup artifacts,
 * not an upstream defect. This draft has not passed a full linked build.
 * Remaining: pointer-table store ordering, search-loop strength reduction,
 * and d/mask/selection register choice. No new C promotion.
 */
#include "common.h"
/* localdecomp:start func_L14_0035DBA8 */
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
typedef struct {
    u8 pad[0x44];
    s32 time;
    s32 choice;
} Choice_35DBA8;
extern S_35DBA8_f D_L14_001DD720;
extern S_35DBA8_b D_L14_001DD738[];
extern S_35DBA8_b D_L14_001DD740[];
extern S_35DBA8_b D_L14_001DD748[];
extern S_35DBA8_b D_L14_001DD750[];
__asm__(".extern D_L14_001DD6E4, 4");
extern s32 D_L14_001DD6E4;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L14_0035DA48(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L14_0035DBA8(void *arg0, void *target) {
    u8 *a0 = arg0;
    S_35DBA8_f thr = D_L14_001DD720;
    S_35DBA8_b l0 = D_L14_001DD738[0];
    S_35DBA8_b l1 = D_L14_001DD740[0];
    S_35DBA8_b l2 = D_L14_001DD748[0];
    S_35DBA8_b l3 = D_L14_001DD750[0];
    S_35DBA8_p tab = { { l0.b, l1.b, l2.b, l3.b } };
    vu0_v4 v;
    u8 *s;
    u8 *sel;
    f32 f;
    s32 i;
    s32 j;
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
    for (j = 0; j < 4; j++) {
        b = sel[j];
        if ((mask >> b) & 1) {
            if (d + *(s16 *)(s + 0x36) >= 5) {
                func_L14_0035DA48(a0, b);
                func_L01_004450F0(a0, 2, -1);
                ((Choice_35DBA8 *)s)->choice = b;
                ((Choice_35DBA8 *)s)->time = (D_L14_001DD6E4 * 5 + 2) / 6;
                return;
            }
        }
    }
}
/* localdecomp:end func_L14_0035DBA8 */
