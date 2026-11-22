#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045A9F0 */
extern s32 func_L01_0045A898(f32 *, f32 *, f32);
void func_L01_0045A9F0(S457 *p) {
    ((void (*)(S457 *, void *, f32))func_L01_0045A898)(p, p->sub, p->f);
}
/* localdecomp:end func_L01_0045A9F0 */

/* localdecomp:start func_L01_0045AA10 */
extern s32 func_L01_0045A898(f32 *, f32 *, f32);
void func_L01_0045AA10(u8 *a) {
    ((void (*)(u8 *, u8 *))func_L01_0045A898)(a, a + 16);
}
/* localdecomp:end func_L01_0045AA10 */

/* localdecomp:start func_L01_0045AA30 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
extern void func_L01_0045B8D8(u8 *, u8 *);
extern f32 func_0038CEA8(u8 *);
extern f32 func_0038CED8(u8 *);
extern void func_L01_0045AF28(u8 *, u8 *);
extern void func_L01_0045B538(u8 *, u8 *);

s32 func_L01_0045AA30(u8 *a, u128_t *v) {
    u8 *o;
    u8 *p;

    o = ((u8 * (*)(u8 *))func_L01_0045B958)(a);
    if (o == 0) {
        return 8;
    }
    p = o + 160;
    *(u128_t *)p = *v;
    func_L01_0045B8D8(a, o);
    if (*(s32 *)(o + 56) & 0x400) {
        *(f32 *)(o + 176) = func_0038CEA8(o + 160);
    } else {
        *(f32 *)(o + 176) = func_0038CED8(o + 160);
    }
    func_L01_0045AF28(a, o);
    func_L01_0045B538(a, o);
    return *(s32 *)(o + 148);
}
/* localdecomp:end func_L01_0045AA30 */
