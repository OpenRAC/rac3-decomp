#include "common.h"

/* localdecomp:start func_L30_00344340 */
#include "vu0.h"

extern u8 *D_L30_001DF800;
extern u8 *D_L30_00283960[];
extern s32 D_L30_001DCECC;
__asm__(".extern D_L30_001DCECC, 4");
extern s32 D_L30_001DCEC0;
__asm__(".extern D_L30_001DCEC0, 4");
extern s32 D_L30_001DCE9C;
__asm__(".extern D_L30_001DCE9C, 4");
extern s32 D_L30_001DCEA0;
__asm__(".extern D_L30_001DCEA0, 4");
extern f32 D_L30_001DCEA4;
__asm__(".extern D_L30_001DCEA4, 4");
extern s32 D_L30_001DCEA8;
__asm__(".extern D_L30_001DCEA8, 4");
extern s32 D_L30_001DCEAC;
__asm__(".extern D_L30_001DCEAC, 4");
extern s32 D_L30_001DCEB0;
__asm__(".extern D_L30_001DCEB0, 4");
extern f32 D_L30_001DCEB8;
__asm__(".extern D_L30_001DCEB8, 4");
extern s32 D_L30_001DCEBC;
__asm__(".extern D_L30_001DCEBC, 4");
typedef struct {
    u8 pad0[0x10];
    s32 f10;
} S_00344340;

extern S_00344340 D_L30_001E1108 __attribute__((section(".sdata")));
extern S_00344340 D_L30_001E1128 __attribute__((section(".sdata")));

extern void func_L30_00343AC8(u8 *, void *, s32, s32);
extern void func_003C6680(void *, void *, s32, s32, void *, s32, s32, s32, void *, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L30_00343E10();
extern void func_L01_0034F7E8(void);

void func_L30_00344340(u8 *a0)
{
    vu0_v4 v;
    u8 *s;
    s32 found;

    *(u16 *)(a0 + 0x34) |= 0x100;
    s = *(u8 **)(a0 + 0x68);
    *(s32 *)(s + 0x6C) |= 0x40;
    func_L30_00343AC8(a0, &v, 0, 0);
    vec_add_ab(s + 0x130, a0 + 0x10, &v);
    *(vu0_q *)(s + 0x140) = *(vu0_q *)(s + 0x130);
    if (*(s32 *)(s + 0x16C) != -1) {
        vec_add_ab(s + 0x150, &v, D_L30_001DF800 + *(s32 *)(s + 0x16C) * 0x80 + 0x30);
    } else {
        *(vu0_q *)(s + 0x150) = *(vu0_q *)(s + 0x130);
    }
    *(u16 *)(a0 + 0x34) &= ~0x41;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    func_003C6680(a0, s + 0x70, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    *(s32 *)(s + 0x1A0) = -1;
    *(f32 *)(s + 0x1A4) = 1.0f;
    *(f32 *)(s + 0x1A8) = 1.0f;
    *(s32 *)(s + 0x198) = 0;
    *(s32 *)(s + 0x19C) = 0;
    *(u8 *)(s + 0x1B8) = 0;
    switch (*(u32 *)(s + 0x168)) {
    case 0:
        func_L01_004450F0(a0, 4, -1);
        break;
    case 1:
        func_L01_004450F0(a0, 9, -1);
        break;
    case 2:
        func_L01_004450F0(a0, 0xC, -1);
        break;
    case 4:
        func_L01_004450F0(a0, 0xD, -1);
        break;
    case 5:
        func_L01_004450F0(a0, 0x11, -1);
        break;
    case 6:
        func_L01_004450F0(a0, 0x13, -1);
        break;
    }
    if (*(u8 *)(s + 0x1B2) != 0) {
        s32 i;

        found = 0;
        for (i = 0; i < D_L30_001DCECC; i++) {
            found |= (a0 == D_L30_00283960[i]);
        }
        if (D_L30_001DCECC < 0x80 && !found) {
            D_L30_00283960[D_L30_001DCECC++] = a0;
        }
    }
    if (D_L30_001DCEC0 == 0) {
        D_L30_001DCEC0 = 1;
        func_L03_0034B218((u8 *)&D_L30_001E1128, D_L30_001DCEAC, D_L30_001DCEB0, D_L30_001DCEB8, D_L30_001DCEBC, (void *)func_L30_00343E10);
        D_L30_001E1128.f10 = 0x44;
        func_L03_0034B218((u8 *)&D_L30_001E1108, D_L30_001DCE9C, D_L30_001DCEA0, D_L30_001DCEA4, D_L30_001DCEA8, (void *)func_L01_0034F7E8);
    }
}
/* localdecomp:end func_L30_00344340 */
