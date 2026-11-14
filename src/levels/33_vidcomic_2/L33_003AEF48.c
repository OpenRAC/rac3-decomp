#include "common.h"

INCLUDE_ASM("asm/levels", func_L33_003AEF48);

INCLUDE_ASM("asm/levels", func_L33_003AF098);

/* localdecomp:start func_L33_003AF2B8 */
extern s32 D_L33_001DF6C0;

s32 func_L33_003AF2B8(char *obj) {
    char *p = *(char **)(obj + 0x68);
    s32 i;
    s32 r;
    f32 t;

    t = (f32)(D_L33_001DF6C0 % *(s32 *)(p + 0x114)) / (f32)*(s32 *)(p + 0x114);
    r = 0;
    for (i = 0; i < 4 && !r; i++) {
        f32 *lo = (f32 *)(p + 0xF0);
        f32 *hi = (f32 *)(p + 0x100);
        r = 0;
        if (lo[i] <= t && t <= hi[i]) {
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_L33_003AF2B8 */

/* localdecomp:start func_L33_003AF340 */
/* log: first draft 40 diff (frame 0x40, por+sq); 0x30-byte struct + qzero + base pointer g: 7 diff; store p+0x2C before p+0x28 with temp v: MATCH (--as ps2as). The second D_L33_001DF6C0 read is $gp-relative while the first is lui: alias with .extern size, as L33_003BD978.c does. */
#include "vu0.h"

typedef struct {
    vu0_q q;
    char *obj;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    u8 pad20[0x10];
} __attribute__((aligned(16))) S_003AF340;

__asm__(".extern D_L33_001DEE78, 4");
__asm__(".extern D_L33_001DF6C0_3AF340, 4");
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00446978(void *, void *);
extern s32 func_003A52A0_003AF340(s32, s32, void *);
extern u8 D_L33_001E9600[];
extern s32 D_L33_001DEE78;
extern s32 D_L33_001DF6C0;
extern s32 D_L33_001DF6C0_3AF340;
extern s32 D_001A71A0[];

void func_L33_003AF340(char *obj) {
    char *p = *(char **)(obj + 0x68);
    u8 *g;
    s32 v;
    S_003AF340 s;

    if (func_003D3CB0(p, p + 0x10, 0x11, 0, 0) == 0) {
        return;
    }
    g = D_L33_001E9600;
    if (*(s32 *)(g + 0x18) == 0) {
        return;
    }
    s.flags = 0x1010001;
    qzero(&s.q);
    s.b18 = 3;
    s.f1C = 20.0f;
    s.b19 = 2;
    s.h1A = *(u16 *)(obj + 0xAA);
    s.obj = obj;
    func_L01_00446978(*(void **)(g + 0x18), &s);
    if (*(s32 *)(p + 0x2C) + D_L33_001DEE78 < D_L33_001DF6C0) {
        *(s32 *)(p + 0x28) = 0;
    }
    v = *(s32 *)(g + 0x18);
    if (v != *(s32 *)(p + 0x28)) {
        *(s32 *)(p + 0x2C) = D_L33_001DF6C0_3AF340;
        *(s32 *)(p + 0x28) = v;
        func_003A52A0_003AF340(0x1E, 0, (void *)D_001A71A0[0]);
    }
}
/* localdecomp:end func_L33_003AF340 */

/* localdecomp:start func_L33_003AF430 */
typedef int u128_003AF430 __attribute__((mode(TI)));
typedef struct {
    s32 f0;
    f32 f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30;
    s32 f34;
    s32 f38;
} S_003AF430;

__asm__(".extern D_L33_001DFC00, 4");
__asm__(".extern D_L33_001DEE48, 4");
__asm__(".extern D_L33_001DEE54, 4");
__asm__(".extern D_L33_001DEE60, 4");
__asm__(".extern D_L33_001DEE68, 4");
__asm__(".extern D_L33_001DEE64, 4");
__asm__(".extern D_L33_001DEE70, 4");
__asm__(".extern D_L33_001DEE6C, 4");
__asm__(".extern D_L33_001DEE74, 4");
__asm__(".extern D_L33_001DEE28, 4");
__asm__(".extern D_L33_001DEE20, 4");
__asm__(".extern D_L33_001DEE3C, 4");
__asm__(".extern D_L33_001DEE34, 4");
__asm__(".extern D_L33_001DEE0C, 4");
__asm__(".extern D_L33_001DEE04, 4");
extern u8 *D_L33_001DFC00;
extern s32 D_L33_001DEE48;
extern s32 D_L33_001DEE54;
extern f32 D_L33_001DEE60;
extern f32 D_L33_001DEE68;
extern f32 D_L33_001DEE64;
extern f32 D_L33_001DEE70;
extern f32 D_L33_001DEE6C;
extern f32 D_L33_001DEE74;
extern f32 D_L33_001DEE28;
extern f32 D_L33_001DEE20;
extern f32 D_L33_001DEE3C;
extern f32 D_L33_001DEE34;
extern f32 D_L33_001DEE0C;
extern f32 D_L33_001DEE04;
extern char D_L33_001E2190;
extern S_003AF430 D_L33_001E2190_3AF430 __attribute__((section(".sdata")));
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0040C7A0(void *, void *);

typedef struct {
    u128_003AF430 pa;
    union {
        u128_003AF430 q;
        f32 f[4];
    } pb;
    s32 a;
    s32 b;
    s32 f28;
    s32 f2C;
    u8 u30[0xB0];
    f32 r[4];
    u8 padF0[0x20];
    s32 f110;
    s32 pad114;
    s32 f118;
    s32 f11C;
} P_003AF430;

void func_L33_003AF430(char *obj) {
    P_003AF430 *p;

    *(s32 *)(obj + 0x98) = 0;
    *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & ~0x1000;
    p = *(P_003AF430 **)(obj + 0x68);
    func_L01_004AA7E8(obj, 1);
    if (p->a != -1) {
        p->pa = *(u128_003AF430 *)(D_L33_001DFC00 + p->a * 0x80 + 0x30);
    } else {
        p->pa = *(u128_003AF430 *)(obj + 0x10);
    }
    if (p->b != -1) {
        p->pb.q = *(u128_003AF430 *)(D_L33_001DFC00 + p->b * 0x80 + 0x30);
    } else {
        p->pb.q = *(u128_003AF430 *)(obj + 0x10);
        p->pb.f[0] += 2.0f;
    }
    p->f118 = 0;
    p->f110 = 1;
    p->f28 = 0;
    p->f2C = 0;
    p->f11C = -1;
    p->r[1] = func_003824E0(0.0f, 1.0f);
    p->r[0] = func_003824E0(0.0f, 1.0f);
    p->r[3] = func_003824E0(0.0f, 1.0f);
    p->r[2] = func_003824E0(0.0f, 1.0f);
    if (D_L33_001DEE48 == 0) {
        D_L33_001DEE48 = 1;
        D_L33_001E2190_3AF430.f0 = D_L33_001DEE54;
        D_L33_001E2190_3AF430.f4 = D_L33_001DEE60;
        D_L33_001E2190_3AF430.f8 = D_L33_001DEE68;
        D_L33_001E2190_3AF430.fC = D_L33_001DEE64;
        D_L33_001E2190_3AF430.f10 = D_L33_001DEE70;
        D_L33_001E2190_3AF430.f14 = D_L33_001DEE6C;
        D_L33_001E2190_3AF430.f18 = D_L33_001DEE74;
        D_L33_001E2190_3AF430.f1C = D_L33_001DEE28;
        D_L33_001E2190_3AF430.f20 = D_L33_001DEE20;
        D_L33_001E2190_3AF430.f24 = D_L33_001DEE3C;
        D_L33_001E2190_3AF430.f28 = D_L33_001DEE34;
        D_L33_001E2190_3AF430.f2C = D_L33_001DEE0C;
        D_L33_001E2190_3AF430.f30 = D_L33_001DEE04;
        D_L33_001E2190_3AF430.f34 = 0;
        D_L33_001E2190_3AF430.f38 = 0;
    }
    func_L01_0040C7A0(p->u30, &D_L33_001E2190);
}
/* localdecomp:end func_L33_003AF430 */
