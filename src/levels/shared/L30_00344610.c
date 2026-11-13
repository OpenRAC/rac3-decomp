#include "common.h"

/* localdecomp:start func_L30_00344610 */
typedef struct {
    u8 pad0[0x160];
    f32 f160;
    u8 pad164[0x17C - 0x164];
    s32 f17C;
    s32 f180;
    u8 pad184[0x18C - 0x184];
    s32 f18C;
    s32 f190;
    u8 pad194[0x1A4 - 0x194];
    f32 f1A4;
    f32 f1A8;
} S_00344610;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[2];
    u8 b23;
    u8 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    S_00344610 *p68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
} M_00344610;

typedef struct {
    s16 x;
    s16 y;
} P_00344610;

__asm__(".extern D_L30_001DCEC8, 4");
extern f32 D_L30_001DCEC8;
__asm__(".extern D_L30_001DCF10, 4");
extern s32 D_L30_001DCF10;
__asm__(".extern D_L30_001DCF0C, 4");
extern s32 D_L30_001DCF0C;
__asm__(".extern D_L30_001DCF08, 4");
extern s32 D_L30_001DCF08;
__asm__(".extern D_L30_001DCEB4, 2");
extern u16 D_L30_001DCEB4;
extern s32 D_L30_001DF2C0;
extern P_00344610 D_L30_001E1128;
extern u8 D_001A4BE0[];

extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L30_00345BD0(void);
extern void func_L01_004AA7E8(void *, s32);

void func_L30_00344610(M_00344610 *a) {
    S_00344610 *s;
    s32 n;
    s32 c;
    f32 f;
    u8 *g;

    a->b23 = D_L30_001DCEC8;
    n = D_L30_001DCF10;
    s = a->p68;
    c = func_0038DBD8(D_L30_001DCF0C, D_L30_001DCF08,
                      func_0038D098(func_0038DB48((f32)(D_L30_001DF2C0 % n) * 6.2831855f / (f32)n)) * 0.5f + 0.5f);
    func_L01_0043B9E8(a, c & 0xFF, (c >> 8) & 0xFF, (c >> 16) & 0xFF);

    switch (a->b20) {
    case 1:
        if (func_L01_004561B8(a)) {
            if (a->hAA == 0x1AED) {
                func_003A52A0(0, 0, a);
            }
            s->f180 = s->f190;
            a->h34 &= ~0x41;
            a->h34 |= *(u16 *)(a->p24 + 0x44) & 0x1000;
            a->f98 = *(s32 *)(a->p24 + 0x10);
        }
        s->f160 = func_L03_0034B148(s->f190 - s->f180, s->f190, 0.0f);
        s->f1A8 = s->f1A4 = 1.0f - s->f160;
        if (func_0038CAD0(&s->f180)) {
            func_L01_004450F0(a, 4, -1);
        } else {
            if (s->f180 == s->f190 - 1) {
                D_L30_001E1128.x = (u16)s->f180 + D_L30_001DCEB4;
                D_L30_001E1128.y = (u16)s->f180 + D_L30_001DCEB4;
                func_L30_0034C8A8(&D_L30_001E1128, a);
            }
            func_L01_00404A10(func_L30_00345BD0, a);
        }
        break;
    case 2:
        if (func_L01_004561B8(a)) {
            s->f180 = s->f190;
            if (a->hAA == 0x1AED) {
                func_003A52A0(1, 0, a);
            }
        }
        f = func_L03_0034B148(s->f190 - s->f180, s->f190, 0.0f);
        s->f160 = f;
        s->f1A4 = f;
        s->f1A8 = f;
        if (func_0038CAD0(&s->f180)) {
            func_L01_004450F0(a, 3, -1);
        } else {
            if (s->f180 == s->f190 - 1) {
                D_L30_001E1128.x = (u16)s->f180 + D_L30_001DCEB4;
                D_L30_001E1128.y = (u16)s->f180 + D_L30_001DCEB4;
                func_L30_0034C8A8(&D_L30_001E1128, a);
            }
            func_L01_00404A10(func_L30_00345BD0, a);
        }
        break;
    case 3:
        if (func_L01_004561B8(a)) {
            s->f1A4 = 0.0f;
            s->f180 = s->f17C;
            s->f1A8 = 0.0f;
            a->f98 = 0;
            a->h34 = (a->h34 | 0x41) & ~0x1000;
            func_L01_004AA7E8(a, 1);
        }
        s->f160 = func_L03_0034B148(s->f17C - s->f180, s->f17C, 0.0f);
        if (func_0038CAD0(&s->f180)) {
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a)) {
            s->f1A4 = 1.0f;
            s->f1A8 = 1.0f;
        }
        g = D_001A4BE0;
        if (*(s16 *)(g + 0x36E) == 0 && *(void **)(g + 0x35C) == a) {
            if (a->hAA == 0x1AED) {
                func_003A52A0(2, 0, a);
            }
            func_L01_004450F0(a, 5, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a)) {
            s->f180 = s->f18C;
        }
        s->f160 = func_L03_0034B148(s->f18C - s->f180, s->f18C, 0.0f);
        if (func_0038CAD0(&s->f180)) {
            func_L01_004450F0(a, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L30_00344610 */

INCLUDE_ASM("asm/levels", func_L30_003449B0);
