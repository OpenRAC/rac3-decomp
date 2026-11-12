#include "common.h"

typedef struct S_003BED60 {
    u8 pad00[4];
    u8 f04[8];
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} S_003BED60;
typedef struct S_003BED60_arg {
    u8 pad00[0x68];
    S_003BED60 *f68;
} S_003BED60_arg;

/* localdecomp:start func_L32_003BE008 */
void func_L32_003BE830();
void func_L32_003BED60(void *);
void func_L32_003BE960(void *);
void func_L32_003BE498(void *);
void func_L01_00404A10(void *, void *);
void func_L01_004450F0(void *, s32, s32);

void func_L32_003BE008(void *arg0) {
    u8 a = *(volatile u8 *)((u8 *)arg0 + 0x20);
    u8 t;
    if (a != 0) {
        t = *(u8 *)((u8 *)arg0 + 0x20);
    } else {
        do {
            func_L32_003BE830();
        } while (0);
        func_L01_004450F0(arg0, 1, -1);
        t = *(u8 *)((u8 *)arg0 + 0x20);
    }
    switch (t) {
    case 1:
        func_L32_003BED60(arg0);
        break;
    case 2:
        func_L32_003BE960(arg0);
        break;
    }
    func_L01_00404A10(func_L32_003BE498, arg0);
}
/* localdecomp:end func_L32_003BE008 */

INCLUDE_ASM("asm/levels", func_L32_003BE098);

/* localdecomp:start func_L32_003BE498 */
void func_L32_003BE098(void *);
void func_L32_003BE4E8();

void func_L32_003BE498(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 0xFDU) {
        func_L32_003BE4E8();
        if ((*(u8 *)((u8 *)arg0 + 0x20)) == 2) {
            func_L32_003BE098(arg0);
        }
    }
}
/* localdecomp:end func_L32_003BE498 */

INCLUDE_ASM("asm/levels", func_L32_003BE4E8);

INCLUDE_ASM("asm/levels", func_L32_003BE5E0);

INCLUDE_ASM("asm/levels", func_L32_003BE830);

/* localdecomp:start func_L32_003BE8E0 */
typedef int u128_t __attribute__((mode(TI)));

extern s32 D_L32_001DF1D8;
__asm__(".extern D_L32_001DF1D8, 4");
extern u8 *func_003C24B0(s32, s32);

u8 *func_L32_003BE8E0(void *arg0, s32 arg1) {
    u8 *r = func_003C24B0(0x1D82, 0x40);
    u8 *p;

    if (r == 0) {
        return 0;
    }
    p = *(u8 **)(r + 0x68);
    *(u8 *)(r + 0x30) = 0xFF;
    *(u128_t *)(r + 0x10) = *(u128_t *)arg0;
    if (arg1 <= 0) {
        s32 g = D_L32_001DF1D8;
        *(s32 *)(p + 0x4) = g;
        *(s32 *)(p + 0x8) = g;
    } else {
        *(s32 *)(p + 0x4) = arg1;
        *(s32 *)(p + 0x8) = arg1;
    }
    return r;
}
/* localdecomp:end func_L32_003BE8E0 */

INCLUDE_ASM("asm/levels", func_L32_003BE960);

/* localdecomp:start func_L32_003BED60 */
extern u8 D_001A30B0[];
extern f32 D_L32_001DF1E0;
extern f32 D_L32_001DF1E4;
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);

void func_L32_003BED60(void *a) {
    S_003BED60_arg *arg0 = a;
    S_003BED60 *p;
    u8 *t;
    f32 a;
    f32 b;

    p = arg0->f68;
    a = func_0038DAB8(p->f0C, D_L32_001DF1E0);
    p->f0C = a;
    b = func_0038DAB8(p->f10, D_L32_001DF1E4);
    p->f10 = b;
    if (p->f3C != -1) {
        t = D_001A30B0 + p->f3C * 0x80;
        if (*(void **)(t + 0xDC) == arg0) {
            if (t[0xD0] != 0) {
                goto skip;
            }
        }
    }
    p->f3C = func_L01_004AAC98(10, 4, (s32)arg0, 0x19D1);
skip:
    if (func_0038CAD0(p->f04) != 0) {
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L32_003BED60 */
