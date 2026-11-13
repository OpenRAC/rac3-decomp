#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003B8F10);

INCLUDE_ASM("asm/levels", func_L03_003B8FA0);

/* localdecomp:start func_L03_003B9130 */
extern void func_L01_00443B88(f32 *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
__asm__(".extern D_L03_001DEA8C, 4");
__asm__(".extern D_L03_001DEA90, 4");
__asm__(".extern D_L03_001DEA94, 4");
__asm__(".extern D_L03_001DEA98, 4");
extern f32 D_L03_001DEA8C;
extern f32 D_L03_001DEA90;
extern u8 D_L03_001DEA94;
extern f32 D_L03_001DEA98;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    s32 pad0C;
    f32 v10[3];
} Ctl_3B9130;

void func_L03_003B9130(u8 *e, Ctl_3B9130 *s) {
    u8 *m;
    vu0_v4 d;
    s32 i;
    f32 f;
    f32 c;
    s32 w;
    if (s == 0) {
        return;
    }
    m = s->m;
    w = s->w4;
    if (m == 0 || w == 0) {
        return;
    }
    if ((u8)(m[0x20] + 2) < 2) {
        *(s16 *)(e + 0xA) = 0;
        return;
    }
    if (s->hA & 1) {
        e[2] = D_L03_001DEA94;
        *(vu0_q *)(e + 0x10) = *(vu0_q *)(m + 0x10);
        func_L01_00443B88(&d.x, D_L03_001DEA8C * 0.020000001f, D_L03_001DEA90 * 0.020000001f);
        c = D_L03_001DEA98 * 210000.0f;
        s->v10[0] = d.x;
        s->v10[1] = d.y;
        s->v10[2] = d.z;
        *(u32 *)(e + 4) = 0x88202080;
        *(f32 *)(e + 0xC) = c;
    }
    *(u32 *)(e + 4) = (*(u32 *)(e + 4) & 0xFFFFFF) | ((s32)((f32)*(s16 *)(e + 0xA) * 128.0f / (f32)s->h8) << 24);
    for (i = 0; i < 3; i++) {
        (&d.x)[i] = s->v10[i];
    }
    f = (f32)(s->h8 - *(s16 *)(e + 0xA));
    if (f < 1.0f) {
        f = 1.0f;
    }
    func_0038CE20(&d, &d, f);
    vec_add_ab(e + 0x10, m + 0x10, &d);
}
/* localdecomp:end func_L03_003B9130 */

INCLUDE_ASM("asm/levels", func_L03_003B92E8);

/* localdecomp:start func_L03_003B9688 */
typedef int u128_3B9760 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2F58(u8 *, s32, u8 *);

u8 *func_L03_003B9688(u8 *a0, s32 a1, f32 f) {
    u8 *m = func_003C24B0(0x1C19, 0x80);
    if (m != 0) {
        u8 *pv = *(u8 **)(m + 0x68);
        u8 *s;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(pv + 0x20) = f * 0.020000001f;
        *(s32 *)(pv + 0x28) = 0;
        *(s32 *)(pv + 0x2C) = 0;
        *(s32 *)(pv + 0x34) = a1;
        s = *(u8 **)(a0 + 0x68);
        func_003C2F58(*(u8 **)s, a1, pv + 0x10);
        func_003C2F58(*(u8 **)s, a1 - 0x20, pv);
        *(s32 *)(pv + 0x30) = *(s32 *)s;
        *(u128_3B9760 *)(m + 0x10) = *(u128_3B9760 *)(pv + 0x10);
    }
    return m;
}
/* localdecomp:end func_L03_003B9688 */

/* localdecomp:start func_L03_003B9760 */
extern void func_003D9508(u8 *, s32, u32, s32, f32, f32, f32);
__asm__(".extern D_L03_001DEAA0, 4");
__asm__(".extern D_L03_001DEAA4, 4");
extern s32 D_L03_001DEAA0;
extern s32 D_L03_001DEAA4;

void func_L03_003B9760(u8 *a0, u32 a1) {
    u128_3B9760 v = *(u128_3B9760 *)a0;
    func_003D9508((u8 *)&v, D_L03_001DEAA0, a1, 1, 0.75f, 0.0f, 0.0f);
    func_003D9508((u8 *)&v, D_L03_001DEAA4, 0x8020F020, 1, 0.5f, 0.08f, 0.0f);
}
/* localdecomp:end func_L03_003B9760 */

INCLUDE_ASM("asm/levels", func_L03_003B97E0);

INCLUDE_ASM("asm/levels", func_L03_003B9898);

/* localdecomp:start func_L03_003B9938 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32 a, s32 b);

u8 *func_L03_003B9938(u8 *a0) {
    u8 *m = func_003C24B0(7230, 128);
    if (m != 0) {
        *(u8 *)(m + 48) = 255;
        *(u16 *)(m + 52) &= ~0x80;
        *(s16 *)(m + 50) = 64;
        *(u8 *)(m + 49) = 1;
        *(u8 **)(m + 184) = a0;
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
    }
    return m;
}
/* localdecomp:end func_L03_003B9938 */
