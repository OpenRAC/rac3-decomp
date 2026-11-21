/* functional: high. Draft near miss (30 words, weapon-table addressing/scheduling). Every v+offset store, constant, branch condition (state==29 || +0x16B0; D_001D673C || hero+0x368) and callee arg checked against PAL asm; $gp counter is D_001DD9A0 (gp+0x10F0). */
#include "common.h"
/* localdecomp:start func_L01_003706F0 */
typedef int Q_003706F0 __attribute__((mode(TI)));
typedef struct { u8 bytes[0xF0]; } WeaponRow_003706F0;
typedef struct { Q_003706F0 rows[3]; } Basis_003706F0;
extern u8 D_0014260F[];
extern WeaponRow_003706F0 D_L01_002C5600[];
extern s32 D_001DD9A0_sda;
__asm__(".extern D_001DD9A0_sda, 4");
typedef struct { u8 pad0[0x368]; s16 h368; u8 pad36A[0x16B0-0x36A]; s32 i16B0; u8 pad16B4[0x25C0-0x16B4]; u8 *p25C0; s32 i25C4; } Hero_003706F0;
extern Hero_003706F0 D_001A4BE0;
extern Basis_003706F0 D_L01_001E29E0;
extern s32 D_L01_001D673C[];
extern u8 D_001A4C60[];
void *func_L01_003706F0(void *owner, Q_003706F0 *position, Q_003706F0 *direction, s32 arg3, s32 arg4, s16 arg5, s32 arg6, f32 damage) {
    extern void *func_003C24B0(s32, s32);
    extern f32 func_00382538(void);
    extern s32 func_00382468(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    Q_003706F0 temporary, projected;
    u8 *m = func_003C24B0(0x1867, 0x300);
    if (m) {
        u8 *v;
        m[0x30] = *(u16 *)(m + 0x32) = 0xFF;
        *(f32 *)(m + 0x2C) = 0.019f;
        v = *(u8 **)(m + 0x68);
        *(s32 *)(v + 0x2D4) = D_L01_002C5600[D_0014260F[0]].bytes[1];
        m[0x20] = 0;
        *(u16 *)(m + 0x34) |= 0x100;
        *(Q_003706F0 *)(m + 0x10) = *position;
        *(s32 *)(v + 0x17C) = arg3;
        *(void **)(v + 0x174) = owner;
        *(Q_003706F0 *)v = *direction;
        *(f32 *)(v + 0x180) = func_00382538();
        *(s16 *)(v + 0x188) = func_00382468(2);
        *(f32 *)(v + 0x178) = damage;
        *(s32 *)(v + 0x184) = arg4;
        *(s32 *)(v + 0x2DC) = arg6;
        *(s16 *)(v + 0x18A) = arg5;
        *(s32 *)(v + 0x2D0) = -1;
        *(f32 *)(v + 0x2A0) = 0.5f;
        *(f32 *)(v + 0x2B0) = -0.5f;
        *(s32 *)(v + 0x170) = 0;
        *(s32 *)(v + 0x2A4) = 0;
        *(s32 *)(v + 0x2A8) = 0;
        *(f32 *)(v + 0x2AC) = 1.0f;
        *(s32 *)(v + 0x2B4) = 0;
        *(s32 *)(v + 0x2B8) = 0;
        *(f32 *)(v + 0x2BC) = 1.0f;
        *(s32 *)(v + 0x2C4) = 0;
        if (*(s32 *)(v + 0x2D4) >= 4) D_001DD9A0_sda++;
        if (D_001A4BE0.i25C4 == 29 || D_001A4BE0.i16B0) {
            *(Basis_003706F0 *)(m + 0xC0) = D_L01_001E29E0;
        } else {
            *(Q_003706F0 *)(m + 0xC0) = *(Q_003706F0 *)v;
            func_0038CF68(m + 0xC0, m + 0xC0, 1.0f);
            func_0038CE90(m + 0xE0, D_001A4BE0.p25C0 + 0xD0, m + 0xC0);
            func_0038CE90(m + 0xD0, m + 0xC0, m + 0xE0);
            func_0038D890(m + 0xD0, m + 0xD0, v, 1.57079637f);
            func_0038D890(m + 0xE0, m + 0xE0, v, 1.57079637f);
        }
        *(Q_003706F0 *)(v + 0x10) = *(Q_003706F0 *)v;
        if (D_L01_001D673C[0] || D_001A4BE0.h368) {
            func_L01_004C7D98(D_001A4C60, &temporary);
            func_0038CE20(&projected, &temporary, func_0038CE68(v, &temporary));
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Q_003706F0 *)(v + 0x10)) : "m"(*(Q_003706F0 *)v), "m"(projected) : "memory");
        } else {
            *(s32 *)(v + 0x18) = 0;
            func_0038CF68(v + 0x10, v + 0x10, 1.0f);
        }
        if (D_001A4BE0.i16B0) {
            func_L01_004CAC78(v + 0x10, position, func_0038CEA8(v + 0x10), 30.0f, 1.39626336f);
            func_L01_004CAC78(v, position, func_0038CEA8(v), 30.0f, 1.39626336f);
        }
        *(s32 *)(v + 0x2D8) = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    }
    return m;
}
/* localdecomp:end func_L01_003706F0 */
