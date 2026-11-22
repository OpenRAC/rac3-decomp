#include "common.h"

/* localdecomp:start func_L03_003AE9A0 */
extern s32 func_L03_0043F5D0(s32, s32, f32);
extern void func_L01_00421988(s32, s32, s32, s32, f32);
__asm__(".extern D_L03_001DE7D8, 4");
extern s32 D_L03_001DE7D8;
extern s32 D_L03_001DE7DC[];

void func_L03_003AE9A0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 n = *(s32 *)(v + 0x50);
    s32 total = v[(*(s32 *)(v + 0x2C) << 5) + 0x20A];
    f32 t = 1.0f - (f32)n / (f32)total;
    s32 c;
    if (total - n < 2) {
        c = func_L03_0043F5D0(D_L03_001DE7D8, D_L03_001DE7DC[0], *(f32 *)(v + 0x10));
    } else {
        c = D_L03_001DE7D8;
    }
    func_L01_00421988(3, c, 0, 0, t);
}
/* localdecomp:end func_L03_003AE9A0 */

/* localdecomp:start func_L03_003AEA48 */
typedef int u128_003AEA48 __attribute__((mode(TI)));

typedef struct {
    u128_003AEA48 a;
    u128_003AEA48 b;
    s32 c20;
    s32 c24;
    u8 pad28[0x88];
} E_003AEA48;

typedef struct {
    void *p0;
    u8 pad4[0x26C];
    E_003AEA48 arr[8];
    u8 x7F0[0x10];
} V_003AEA48;

typedef struct {
    u8 pad0[0x68];
    V_003AEA48 *p68;
} S_003AEA48;

extern void func_003C2F58(void *, s32, u128_003AEA48 *);
extern void func_L01_0040C7A0(void *, void *);

void func_L03_003AEA48(S_003AEA48 *a0) {
    u128_003AEA48 mats[9];
    V_003AEA48 *v = a0->p68;
    s32 i, j;

    for (i = 0; i < 8; i++) {
        func_003C2F58(v->p0, i * 4 + 0x20, &mats[i + 1]);
    }
    func_003C2F58(v->p0, 0x41, &mats[0]);
    for (j = 0; j < 8; j++) {
        V_003AEA48 *q = (V_003AEA48 *)((u8 *)v + j * 0xB0);
        u128_003AEA48 *mp = &mats[j];
        q->arr[0].c20 = 0x1B4E206C;
        q->arr[0].c24 = -1;
        func_L01_0040C7A0(q->arr, v->x7F0);
        q->arr[0].a = mats[0];
        q->arr[0].b = mp[1];
    }
}
/* localdecomp:end func_L03_003AEA48 */

/* localdecomp:start func_L03_003AEB30 */
typedef struct {
    u8 pad0[0xB0];
} S_3AD1F8c;

typedef struct {
    u8 pad0[0x270];
    S_3AD1F8c arr[8];
    u8 x7F0[0x10];
} S_3AD1F8b;

typedef struct {
    u8 pad0[0x68];
    S_3AD1F8b *p68;
} S_3AD1F8;

extern void func_L01_0040C8A0(S_3AD1F8c *a0, u8 *a1);
extern void func_L01_0040C948(S_3AD1F8c *a0, u8 *a1);

void func_L03_003AEB30(S_3AD1F8 *a0) {
    S_3AD1F8b *p = a0->p68;
    s32 i;
    for (i = 0; i < 8; i++) {
        func_L01_0040C8A0(&p->arr[i], p->x7F0);
        func_L01_0040C948(&p->arr[i], p->x7F0);
    }
}
/* localdecomp:end func_L03_003AEB30 */

/* localdecomp:start func_L03_003AEB98 */
void func_L03_003AEB98(u8 *self) {
    u8 *v = *(u8 **)(self + 104);

    *(s32 *)(v + 2032) = 12;
    *(f32 *)(v + 2036) = 0.33f;
    *(f32 *)(v + 2040) = 1200.0f;
    *(f32 *)(v + 2044) = 1500.0f;
    *(f32 *)(v + 2048) = 3.0f;
    *(f32 *)(v + 2052) = 3.5f;
    *(f32 *)(v + 2056) = 0.08f;
    *(f32 *)(v + 2060) = 0.02f;
    *(f32 *)(v + 2064) = 0.05f;
    *(f32 *)(v + 2068) = 3.0f;
    *(f32 *)(v + 2072) = 5.0f;
    *(f32 *)(v + 2076) = 0.2f;
    *(f32 *)(v + 2080) = 1.0f;
    *(s32 *)(v + 2084) = 0;
    *(s32 *)(v + 2088) = 0;
}
/* localdecomp:end func_L03_003AEB98 */
