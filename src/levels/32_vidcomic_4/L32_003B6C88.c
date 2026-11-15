#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L32_003B6C88(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L32_003B6DD0(void *);

/* localdecomp:start func_L32_003B6C88 */
#include "vu0.h"
/* log: first draft (zero vector via a u128 store, both tuning values passed directly) 72 diff --as ps2as;
   qzero for retail's bare sq $0 + waiting divs row 2 -> 6/12/16 diff (only the scheduling of the
   two $gp loads for $f15/$f16 against li.s 0.5); 19 placements of amp/w locals and 10 statement orders
   all stayed at 6+; permuter (default as, so blind here) nothing. D_L32_001DEE7C/58 declared const
   (read-only tuning values: no alias dependence on the 0xF4 store) + amp/w locals -> MATCH.
   func_L32_003B5F58 also matches with the same const declarations. */
extern void func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
void func_L32_003B6170(void *);
extern s32 func_L30_0034D8D8(void *, f32);
s32 func_003A52A0(s32, s32, void *);
void func_003C2880(void *);
typedef struct {
    u8 pad[0x20];
    f32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
} S_003B6C88;
extern S_003B6C88 D_L32_001E2C40;
extern f32 D_L32_001DEE3C;
__asm__(".extern D_L32_001DEE3C, 4");
extern f32 D_L32_001DEE54;
__asm__(".extern D_L32_001DEE54, 4");
extern f32 D_L32_001DEE50;
__asm__(".extern D_L32_001DEE50, 4");
extern const f32 D_L32_001DEE7C;
__asm__(".extern D_L32_001DEE7C, 4");
extern const f32 D_L32_001DEE58;
__asm__(".extern D_L32_001DEE58, 4");
extern s32 D_L32_001DEE14;
__asm__(".extern D_L32_001DEE14, 4");
extern s32 D_L32_001DEE18;
__asm__(".extern D_L32_001DEE18, 4");

typedef struct {
    f32 v[4];
    u128_t pos;
} S2_003B6C88;

void func_L32_003B6C88(void *arg0) {
    u8 *a;
    u8 *p;
    S2_003B6C88 s;
    f32 t;
    f32 w;
    f32 amp;

    a = arg0;
    p = *(u8 **)(a + 0x68);
    qzero(s.v);
    s.v[2] = D_L32_001DEE3C;
    s.pos = *(u128_t *)(a + 0x10);
    t = (*(f32 *)(a + 0x18) - *(f32 *)(p + 0x138)) / D_L32_001DEE54;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < -1.0f) {
        t = -1.0f;
    }
    amp = D_L32_001DEE7C;
    w = D_L32_001DEE58;
    *(f32 *)(a + 0xF4) = -t * D_L32_001DEE50;
    func_L30_0034D1E8(a, a + 0x10, p + 0x140, &s, 0.5f, 0.0f, 1.0f, amp, w, 0.0f, 1, 0, 0, 0);
    func_L32_003B6170(a);
    if (func_L30_0034D8D8(a + 0x10, 2.0f) == 0) {
        D_L32_001E2C40.x20 = (f32)D_L32_001DEE14;
        D_L32_001E2C40.x28 = D_L32_001DEE18;
        D_L32_001E2C40.x2C = 0;
        func_003A52A0(4, 0, a);
        func_003C2880(a);
    }
}
/* localdecomp:end func_L32_003B6C88 */

/* localdecomp:start func_L32_003B6DD0 */
extern s32 func_L01_004561B8(void *);
extern s32 func_L05_00328FF8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L32_003B5F58();
void func_L32_003B6A58(void *);
void func_L32_003B6170(void *);
extern f32 D_001A4C60[];
extern f32 D_L32_001DEE08;
__asm__(".extern D_L32_001DEE08, 4");
extern f32 D_L32_001DEE60;
__asm__(".extern D_L32_001DEE60, 4");
extern f32 D_L32_001DEE88;
__asm__(".extern D_L32_001DEE88, 4");
extern f32 D_L32_001DEE84;
__asm__(".extern D_L32_001DEE84, 4");
extern s32 D_L32_001DEE44;
__asm__(".extern D_L32_001DEE44, 4");
extern f32 D_L32_001DEE10;
__asm__(".extern D_L32_001DEE10, 4");

void func_L32_003B6DD0(void *arg0) {
    u8 *a;
    u8 *p;
    f32 t;
    f32 d;
    f32 f;

    a = arg0;
    p = *(u8 **)(a + 0x68);
    if (func_L01_004561B8(a) != 0) {
        *(s32 *)(p + 0x24C) = 0;
    }
    if (*(u8 *)(a + 0x20) == 4) {
        *(f32 *)(p + 0x140) -= D_L32_001DEE08;
    } else {
        *(f32 *)(p + 0x140) += D_L32_001DEE08;
    }
    func_L32_003B5F58(a);
    if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x228)) {
        t = (*(f32 *)(a + 0x10) - *(f32 *)(p + 0x228)) / (*(f32 *)(p + 0x22C) - *(f32 *)(p + 0x228));
        if (t > 1.0f) {
            t = 1.0f;
        }
        *(f32 *)(p + 0x23C) = func_0038DAB8(*(f32 *)(p + 0x23C), func_003C4088((&D_L32_001DEE60)[1], (&D_L32_001DEE60)[2], t));
        f = func_003C4088(*(f32 *)(p + 0x244), *(f32 *)(p + 0x248), t);
    } else if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x224)) {
        t = (*(f32 *)(a + 0x10) - *(f32 *)(p + 0x224)) / (*(f32 *)(p + 0x228) - *(f32 *)(p + 0x224));
        *(f32 *)(p + 0x23C) = func_0038DAB8(*(f32 *)(p + 0x23C), func_003C4088(D_L32_001DEE60, (&D_L32_001DEE60)[1], t));
        f = func_003C4088(*(f32 *)(p + 0x240), *(f32 *)(p + 0x244), t);
    } else if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x238)) {
        t = (*(f32 *)(a + 0x10) - *(f32 *)(p + 0x238)) / (*(f32 *)(p + 0x224) - *(f32 *)(p + 0x238));
        *(f32 *)(p + 0x23C) = func_0038DAB8(*(f32 *)(p + 0x23C), func_003C4088(0.0f, D_L32_001DEE60, t));
        f = func_003C4088(0.0f, *(f32 *)(p + 0x240), t);
    }
    d = (*(f32 *)(a + 0x18) - *(f32 *)(p + 0x138)) / D_L32_001DEE88;
    if (d > 1.0f) {
        d = 1.0f;
    } else if (d < -1.0f) {
        d = -1.0f;
    }
    *(f32 *)(a + 0xF0) = f * func_0038D0B0(*(f32 *)(p + 0x23C)) + -d * D_L32_001DEE84;
    if (*(u8 *)(a + 0x20) == 3) {
        func_L32_003B6A58(a);
    }
    func_L32_003B6170(a);
    if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x238) && *(u8 *)(a + 0x20) == 2) {
        func_L01_004450F0(a, 3, -1);
    }
    if (func_L05_00328FF8(a) == 0) {
        *(s32 *)(p + 0x24C) = *(s32 *)(p + 0x24C) + 1;
    } else {
        *(s32 *)(p + 0x24C) = 0;
    }
    if (*(s32 *)(p + 0x24C) > D_L32_001DEE44 && *(f32 *)(a + 0x10) - D_L32_001DEE10 > D_001A4C60[0]) {
        func_L01_004450F0(a, 4, -1);
    }
    if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x22C) && *(u8 *)(a + 0x20) == 3) {
        func_L01_004450F0(a, 1, -1);
    }
    if (*(f32 *)(a + 0x10) < *(f32 *)(p + 0x130) && *(u8 *)(a + 0x20) == 4) {
        func_L01_004450F0(a, 5, -1);
    }
}
/* localdecomp:end func_L32_003B6DD0 */
