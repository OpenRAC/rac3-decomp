/* PAL retail reconstruction, P08 wave 3.
 * Stock check.py: 226 positional differences with the owner's unchanged
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as flags.
 * Requires Obj_003E2638 and Q_003E2638 from the owning file's prelude;
 * these argument types preserve that file's earlier function declaration.
 * The 0x140 frame agrees. Remaining: aggregate-copy register allocation,
 * initializer scheduling, object/damage register roles and division padding.
 * No divs_nops row currently exists for this function.
 * The owning INCLUDE_ASM remains. Full PAL/US linkage is not verified.
 */
#include "common.h"
#include "vu0.h"
typedef struct { f32 v[9]; } Angles_3E26E8;
typedef struct { u8 v[5]; } Order_3E26E8;
extern Angles_3E26E8 D_L16_001DF358;
extern Order_3E26E8 D_L16_001DF380, D_L16_001DF388, D_L16_001DF390, D_L16_001DF398;
extern Order_3E26E8 D_L16_001DF3A0, D_L16_001DF3A8, D_L16_001DF3B0, D_L16_001DF3B8;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L16_003E2C88();
extern void func_L16_003E2E30();
extern s32 func_00382468(s32);
extern void func_L16_003E2C28();
extern void func_L16_003E3068();
extern void func_L14_0035DA48();
void func_L16_003E26E8(Obj_003E2638 *object, Q_003E2638 *impact) {
    Angles_3E26E8 angles = D_L16_001DF358;
    Order_3E26E8 b0 = D_L16_001DF380;
    Order_3E26E8 b1 = D_L16_001DF388;
    Order_3E26E8 b2 = D_L16_001DF390;
    Order_3E26E8 b3 = D_L16_001DF398;
    Order_3E26E8 b4 = D_L16_001DF3A0;
    Order_3E26E8 b5 = D_L16_001DF3A8;
    Order_3E26E8 b6 = D_L16_001DF3B0;
    Order_3E26E8 b7 = D_L16_001DF3B8;
    u8 *orders[8] = { b0.v, b1.v, b2.v, b3.v, b4.v, b5.v, b6.v, b7.v };
    vu0_v4 delta;
    u8 *a0 = (u8 *)object;
    u8 *a1 = (u8 *)impact;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *order;
    f32 angle;
    s32 damage;
    s32 i;
    vec_sub_ab(&delta, a1, a0 + 0x10);
    delta.z = 0.0f;
    func_0038CF68(&delta, &delta, 1.0f);
    angle = fabs_asm(func_0038D0C8(func_0038CE68(&delta, a0 + 0xD0)) - 1.5707964f);
    if (func_0038CE68(&delta, a0 + 0xC0) > 0.0f) angle = 6.2831855f - angle;
    angle += 0.3926991f;
    damage = 9 - (s32)(*(f32 *)s / (f32)*(s16 *)(s + 4) * 9.0f);
    if (damage != 0) func_L16_003E2C88(object, impact);
    if (damage < 7) func_L16_003E2E30(object, impact);
    if (damage < 5) {
        if (func_00382468(3)) func_L16_003E2C28(object, impact, 2);
        for (i = 0; i < damage; i++) {
            if ((*(u16 *)(a0 + 0x7C) >> i) & 1) func_L16_003E3068(object, i);
        }
    } else {
        order = b1.v;
        for (i = 0; i < 8; i++) {
            if (angles.v[i] < angle && angle <= angles.v[i + 1]) {
                order = orders[i];
                break;
            }
        }
        for (i = 0; i < 5; i++) {
            if (((*(u16 *)(a0 + 0x7C) >> order[i]) & 1) &&
                damage + *(s16 *)(s + 0x36) >= 10) {
                func_L14_0035DA48(object);
                break;
            }
        }
    }
}
