#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L20_003F1A78);

INCLUDE_ASM("asm/levels", func_L20_003F21A8);

INCLUDE_ASM("asm/levels", func_L20_003F22C0);

/* localdecomp:start func_L20_003F27E8 */
typedef int q_003F27E8 __attribute__((mode(TI)));

typedef struct P_003F27E8 {
    q_003F27E8 q0;
    f32 f10;
    f32 f14;
} P_003F27E8;

typedef struct M_003F27E8 {
    u8 pad0[0x10];
    q_003F27E8 q10;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34;
    u8 pad36[0x32];
    P_003F27E8 *p68;
    u8 pad6C[0x2C];
    s32 i98;
    u8 pad9C[0x24];
    u8 vC0[0x30];
    u8 vF0[0x10];
} M_003F27E8;

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0044E820(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

M_003F27E8 *func_L20_003F27E8(u8 *a0, q_003F27E8 *a1, q_003F27E8 *a2, f32 x, f32 y) {
    M_003F27E8 *m = (M_003F27E8 *)func_003C24B0(0x1D8D, 0xD90);
    P_003F27E8 *p;
    if (m != 0) {
        func_L01_00456160((u8 *)m, a0);
        m->q10 = *a1;
        func_L01_00443B88(m->vF0, -3.1415927f, 3.1415927f);
        func_0038D308(m->vC0, m->vF0);
        m->i98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
        m->h34 |= 0x100;
        p = m->p68;
        p->q0 = *a2;
        p->f10 = x;
        p->f14 = y;
        m->f2C = *(f32 *)(m->p24 + 0x24) * 0.6f;
        func_L01_0044E820(m, 0x800000C0);
        func_L01_004450F0(m, 0, -1);
    }
    return m;
}
/* localdecomp:end func_L20_003F27E8 */

INCLUDE_ASM("asm/levels", func_L20_003F2918);

INCLUDE_ASM("asm/levels", func_L20_003F32D0);

INCLUDE_ASM("asm/levels", func_L20_003F3528);

/* localdecomp:start func_L20_003F3F28 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DF408;
__asm__(".extern D_L20_001DF408, 4");

void func_L20_003F3F28(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);

    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DF408, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DF408, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DF408, 2.0f, 0.1f);
    }
}
/* localdecomp:end func_L20_003F3F28 */

INCLUDE_ASM("asm/levels", func_L20_003F3FF8);

/* localdecomp:start func_L20_003F4320 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

u8 *func_L20_003F4320(u8 *a0, f32 x, f32 y) {
    u8 *o;
    u8 *p;

    o = func_003C24B0(0x1D91, 0xB0);
    if (o == 0) {
        return 0;
    }
    o[0x20] = 0;
    o[0x30] = 0xFF;
    *(s16 *)(o + 0x32) = 0xFF;
    p = *(u8 **)(o + 0x68);
    *(vu0_q *)(o + 0x10) = *(vu0_q *)a0;
    *(f32 *)(p + 0x90) = 10.0f;
    qzero(p);
    *(f32 *)(p + 0x94) = 10.0f;
    *(f32 *)(p + 0x98) = x;
    *(f32 *)(p + 0x9C) = y;
    func_L01_004450F0(o, 0, -1);
    return o;
}
/* localdecomp:end func_L20_003F4320 */

INCLUDE_ASM("asm/levels", func_L20_003F43D0);
