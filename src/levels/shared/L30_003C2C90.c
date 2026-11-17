#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_003C2C90 */

extern u128_t D_L30_001E1CD0;
extern u128_t D_L30_001E1CC0;
extern void func_0038CF68(u8 *, u8 *, f32);
extern void func_0038CE90(u8 *, u8 *, u8 *);

void func_L30_003C2C90(u8 *m) {
    u8 *p;

    *(u128_t *)m = D_L30_001E1CD0;
    func_0038CF68(m, m, 1.0f);
    p = m + 32;
    *(u128_t *)p = D_L30_001E1CC0;
    func_0038CF68(p, p, 1.0f);
    func_0038CE90(m + 16, m, p);
}
/* localdecomp:end func_L30_003C2C90 */

/* localdecomp:start func_L30_003C2D18 */

extern u8 *D_L30_001DEF84[];
extern void func_L30_003A8E10(s32, u128_t *, u128_t *, s32);

void func_L30_003C2D18(u8 *a0) {
    u128_t out;
    u128_t tmp;
    u8 *s = *(u8 **)(D_L30_001DEF84[0] + *(s16 *)(a0 + 132) * 32 + 28);

    tmp = *(u128_t *)(a0 + 48);
    func_L30_003A8E10(*(s32 *)(s + 252), &out, &tmp, *(s32 *)(s + 36));
    *(u128_t *)(a0 + 48) = out;
}
/* localdecomp:end func_L30_003C2D18 */

/* localdecomp:start func_L30_003C2D78 */
s32 func_L30_003C2D78(void) {
    return -1;
}
/* localdecomp:end func_L30_003C2D78 */

/* localdecomp:start func_L30_003C2D80 */
extern u8 *func_L01_003F34E0(s32, s32);
extern void func_L01_003EC848(void *);
extern void func_00382E10(void *, s32);
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DF728, 16");
extern u8 D_001A4C60[];

typedef struct {
    char pad0[0x1D];
    u8 f1D;
    char pad1E[2];
    s32 f20;
    u8 *f24;
    f32 f28;
    u8 *list[52];
    u8 *fFC;
} S_003C2D80;

void func_L30_003C2D80(u128_t *a, u128_t *b, s32 c, f32 f) {
    u8 *m;
    S_003C2D80 *s;
    u8 *p;
    s32 i;
    s32 n = 0;

    m = func_L01_003F34E0(0, 0x1E);
    s = *(S_003C2D80 **)(D_L30_001DEF84[0] + *(s16 *)(m + 0x84) * 32 + 0x1C);
    s->f1D = 0;
    s->f20 = c;
    p = D_L30_001DF728;
    if (p != 0) {
        do {
            if (*(s16 *)(p + 0xAA) == 0x184C) {
                s->f24 = p;
            }
            p = *(u8 **)(p + 0x28);
        } while (p != 0);
    }
    p = D_L30_001DF728;
    if (p != 0) {
        do {
            if (*(s16 *)(p + 0xAA) == 0x1B55) {
                s->fFC = p;
            }
            p = *(u8 **)(p + 0x28);
        } while (p != 0);
    }
    D_L30_001E1CC0 = *a;
    D_L30_001E1CD0 = *b;
    s->f28 = f;
    for (i = 0x33; i >= 0; i--) {
        s->list[i] = 0;
    }
    p = D_L30_001DF728;
    if (p != 0) {
        do {
            if (*(s16 *)(p + 0xAA) == 0x1667 && n < 0x34) {
                s->list[n] = p;
                n++;
            }
            p = *(u8 **)(p + 0x28);
        } while (p != 0);
    }
    s->f28 = 15.0f;
    *(u128_t *)(m + 0x30) = *(u128_t *)D_001A4C60;
    func_L01_003EC848(m);
    func_00382E10(m, 0);
}
/* localdecomp:end func_L30_003C2D80 */
