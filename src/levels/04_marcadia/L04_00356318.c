#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00356318 */
typedef int u128_t_356318 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;

extern u8 *D_L04_001E9598[];
extern u8 D_L04_001D66B0[8];
__asm__(".extern D_L04_001D66B0, 16");
__asm__(".extern D_L04_001DD310, 4");
__asm__(".extern D_L04_001DD314, 4");
__asm__(".extern D_L04_001DD318, 4");
extern f32 D_L04_001DD310;
extern f32 D_L04_001DD314;
extern f32 D_L04_001DD318;
extern s32 func_L01_0044C108(void *);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_004EDE10(void);
extern f32 func_0038CF38(void *, void *);
extern void func_003C2880(void *);
extern void func_0038CE50(f32 *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L04_00356690(void *);
extern f32 func_003C4138(f32 *, f32, f32);

void func_L04_00356318(u8 *a0) {
    f32 *q = *(f32 **)(a0 + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    u8 c[0x30];
    vu0_v4 e;
    u8 *h;
    u8 *h2;
    f32 dt;
    s32 i;
    f32 k;
    f32 *p;

    if (func_L01_0044C108(a0 + 0x10) == 0)
        return;
    switch (a0[0x20]) {
    case 0:
        q[0] = 1.0f;
        q[8] = func_00382538();
        q[2] = 0.5f;
        q[1] = 0.0f;
        q[0] = 1.0f;
        for (i = 0; i < 4; i++)
            q[4 + i] = 1.0f;
        a0[0x30] = 0xFF;
        func_L01_004450F0(a0, 1, -1);
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        break;
    case 1:
        if (D_001D545C == 0x10) {
            *(u128_t_356318 *)&a = *(u128_t_356318 *)(D_001A4BE0 + 0x80);
            h = D_001A4BE0;
            func_0038CF68(&b, *(u8 **)(h + 0x25C0) + 0xE0, 0.75f);
            vec_add_ab(&a, &a, &b);
            if (func_L01_003FB640(&a, 0, *(u8 **)(h + 0x25C0), 0.5f) != 0 && D_L04_001E9598[0] != 0 && D_L04_001E9598[0] == a0) {
                func_L01_00446760(c, a0, 1, 100.0f, D_L04_001D66B0);
                *(u16 *)(c + 0x1A) = *(u16 *)(a0 + 0xAA);
                func_L01_004EDE10();
            }
            h2 = D_001A4BE0;
            if (*(u8 **)(h2 + 0x35C) != 0 && *(u8 **)(h2 + 0x35C) == a0 && *(s32 *)(h2 + 0x360) != 0) {
                e.x = 0.0f;
                e.y = 1.0f;
                e.z = 0.0f;
                e.w = 1.0f;
                func_0038CF68(&e, &e, 10.0f);
                func_L01_00446760(c, a0, 1, 10.0f, &e);
                *(u16 *)(c + 0x1A) = *(u16 *)(a0 + 0xAA);
                func_L01_004EDE10();
            }
        }
        break;
    case 2:
        break;
    }
    if (func_0038CF38(a0 + 0x10, D_001A4BE0 + 0x80) < 8.0f) {
        func_003C2880(a0);
        return;
    }
    if (q[0] == 0.0f)
        return;
    dt = 0.020000001f;
    func_0038CE50(&a.x, a0, 0.0009765625f);
    q[8] = func_0038DAB8(q[8], D_L04_001DD310 * 0.017453292f * dt);
    q[3] = q[3] + (D_L04_001DD314 + func_L01_00443A18(0.25f, 0.5f)) * dt;
    if (1.0f < q[3])
        q[3] = q[3] - 1.0f;
    k = D_L04_001DD318 * dt;
    p = q + 1;
    for (i = 0; i < 2; i++) {
        *p = *p + k;
        if (1.0f < *p)
            *p = *p - 1.0f;
        p++;
    }
    func_L01_00404808(func_L04_00356690, a0);
    func_003C4138(q, 1.0f, 0.010000001f);
}
/* localdecomp:end func_L04_00356318 */

INCLUDE_ASM("asm/levels", func_L04_00356690);
