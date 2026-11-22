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

/* declared by functions of L01_0045B538.c, which this file was cut from */
extern void func_L01_0045B8F0(u8 *, u8 *);
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

/* localdecomp:start func_L01_0045B8D8 */
extern u128_t D_L01_001E0240[] __attribute__((section(".sdata")));

void func_L01_0045B8D8(u8 *a0, u8 *a1) {
    D_L01_001E0240[0] = *(u128_t *)(a0 + 0x10);
}
/* localdecomp:end func_L01_0045B8D8 */

/* localdecomp:start func_L01_0045B8F0 */
extern u128_t D_L01_001E0240[] __attribute__((section(".sdata")));

void func_L01_0045B8F0(u8 *a0, u8 *a1) {
    *(u128_t *)(a0 + 0x10) = D_L01_001E0240[0];
}
/* localdecomp:end func_L01_0045B8F0 */

/* localdecomp:start func_L01_0045B908 */
extern int func_L01_0044C638(u8 *a, int b, u8 *c, u8 *d, u8 *e, u8 *f);

void func_L01_0045B908(u8 *a0, u8 *a1)
{
    int v = *(int *)(a1 + 136);
    if (v != 0) {
        if (func_L01_0044C638(a0, v, a0 + 16, a0 + 240, a0 + 16, a0 + 240) != 0) {
            *(int *)(a1 + 148) |= 0x40;
        }
    }
}
/* localdecomp:end func_L01_0045B908 */

/* localdecomp:start func_L01_0045B958 */
typedef struct { u8 pad[0x1C]; S_4574A0 *target; } Link_45B958;
/* from rac4-decomp's func_00142220 */
S_4574A0 *func_L01_0045B958(M_4574A0 *m) {
    return (*(Link_45B958 **)((u8 *)m + 0x68))->target;
}
/* localdecomp:end func_L01_0045B958 */

/* localdecomp:start func_L01_0045B968 */
#include "vu0.h"

typedef struct { u8 pad0[0x18]; u8 *object; s32 m1C; vu0_v4 position; u8 pad30[8]; f32 f38; } Hit_0045B968;
extern Hit_0045B968 D_L01_001EAA00_0045B968;
extern vu0_v4 D_L01_001EAA30_0045B968;
extern void func_0038CF68(f32 *, f32 *, f32);
extern s32 func_L01_003FB640_0045B968(f32 *, s32, u8 *, f32);

#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

s32 func_L01_0045B968(u8 *a0, u8 *a1) {
    vu0_v4 p;
    vu0_v4 v;
    vu0_v4 t;

    if (S32(a1, 0x38) & 0x400) {
        func_0038CF68(&v.x, (f32 *)(a0 + 0xE0), F32(a1, 4) + F32(a1, 0));
    } else {
        qzero(&v);
        v.z = F32(a1, 4) + F32(a1, 0);
    }
    if (F32(a1, 0xEC) != 0.0f) {
        func_0038CF68(&t.x, (f32 *)(a0 + 0xC0), F32(a1, 0xEC));
        vec_add_ab(&v, &v, &t);
    }
    vec_add_ba(&p, a0 + 0x10, &v);
    if (func_L01_003FB640_0045B968(&p.x, (S32(a1, 0x38) & 2) ? 6 : 4, a0, F32(a1, 0))) {
        Hit_0045B968 *h = &D_L01_001EAA00_0045B968;
        *(u8 **)(a1 + 0x84) = h->object;
        *(vu0_v4 *)(a1 + 0x60) = h->position;
        if (h->object != 0 && h->m1C < 0 && h->f38 > p.z) {
            h->f38 = p.z;
        }
        p = D_L01_001EAA30_0045B968;
        vec_sub_ab(a0 + 0x10, &p, &v);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0045B968 */

/* localdecomp:start func_L01_0045BAC0 */
#include "vu0.h"
extern s32 func_L01_00476F10(s32, f32, u8 *, f32 *);
extern void func_0038CF68(f32 *, f32 *, f32);
s32 func_L01_0045BAC0(u8 *self, u8 *b) {
    vu0_v4 q;
    if (*(s32 *)(b + 60) == -1) {
        return 0;
    }
    if (*(s32 *)(b + 156) & 1) {
        return 0;
    }
    q = *(vu0_v4 *)(self + 16);
    if (func_L01_00476F10(*(s32 *)(b + 60), *(f32 *)b, (u8 *)&q, (f32 *)(self + 16)) == 0) {
        return 0;
    }
    vec_sub_ba(b + 96, &q, self + 16);
    func_0038CF68((f32 *)(b + 96), (f32 *)(b + 96), *(f32 *)b);
    *(s32 *)(b + 148) |= 16;
    return 1;
}
/* localdecomp:end func_L01_0045BAC0 */
