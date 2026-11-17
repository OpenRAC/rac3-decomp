#include "common.h"

/* localdecomp:start func_L03_003D0A28 */
#include "vu0.h"
typedef int u128_003D0A28 __attribute__((mode(TI)));
extern u8 D_00142CBE[];
extern s32 D_001D6694;
extern s32 D_001A71A4[];
extern s32 D_00142C10[];
extern u8 D_001D5470[8];
extern f32 D_001DEFC0_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DEFC0_sda, 4");
extern f32 D_001DEFD0_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DEFD0_sda, 4");
extern void func_003C2880(void *);
extern s32 func_L01_004BA800(void);
extern void func_L03_003D0E88(u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern s32 func_L02_003E71A8(f32, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L02_00431568(void *, void *, f32, s32, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CAD0(void *);
extern void func_L03_00449C30(void *, s32, s32, s32);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_L01_0045BD10(void *, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
void func_L03_003D0A28(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 d[4];
    f32 ang;
    if (D_00142CBE[0] != 0) {
        func_003C2880(a0);
        return;
    }
    if (func_L01_004BA800() != 0 || D_001A71A4[0] == 0x65) {
        if (D_001D6694 == 2) {
            a0[0x31] = 0;
            *(u16 *)(a0 + 0x34) |= 1;
        }
        return;
    }
    a0[0x31] = 1;
    *(u16 *)(a0 + 0x34) &= ~1;
    switch (a0[0x20]) {
    case 0:
        func_L03_003D0E88(a0);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 1);
        }
        func_L01_004450F0(a0, 4, -1);
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 1);
            }
        }
        if (D_00142C10[0] & 0x10000) {
            *(u128_003D0A28 *)(a0 + 0x10) = *(u128_003D0A28 *)D_001DEFC0_sda;
            *(f32 *)(a0 + 0xF8) = 1.5707964f;
            *(s32 *)(q + 0x68) &= ~0x10;
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            func_0038CDF8((f32 *)(q + 0x120), D_001DEFC0_sda, D_001DEFD0_sda, func_003824E0(0.0f, 1.0f));
            if (func_L02_003E71A8(0.5f, q + 0x120, a0 + 0x10) != 0) {
                func_L01_004450F0(a0, 3, -1);
                break;
            }
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 12);
            }
            vec_sub_ab(d, q + 0x120, a0 + 0x10);
            *(f32 *)(q + 0x138) = func_0038D160(d[0], d[1]);
        }
        if (func_0038DBA0(*(f32 *)(a0 + 0xF8), *(f32 *)(q + 0x138)) > 0.017453292f) {
            func_L01_0045AA10(a0, *(f32 *)(q + 0x138));
        } else {
            func_L02_00431568(a0, q + 0x120, *(f32 *)(q + 0x138), *(s32 *)(q + 0x68), 0.040000003f, 0.0016000001f, 0.0032000002f);
        }
        if (func_L02_003E71A8(0.2f, a0 + 0x10, q + 0x120) != 0) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            *(s32 *)(q + 0x134) = func_00382498(0x21, 0x64);
        }
        ang = 1.5707964f;
        if (func_0038DBA0(*(f32 *)(a0 + 0xF8), ang) > 0.08726646f) {
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 12);
            }
            func_L01_0045AA10(a0, ang);
        } else {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 12);
            }
            func_L01_0045A9F0(a0);
        }
        if (func_0038CAD0(q + 0x134) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) != 0) {
            func_L03_00449C30(a0, *(s32 *)(q + 0x130), -1, 0);
        }
        if (func_L01_0045BDE8(a0, *(s32 *)(q + 0x130)) == 0 && !(D_00142C10[0] & 0x10000)) {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(q + 0xD0), *(f32 *)(q + 0xD4)));
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    if (D_001D5470[1] != 0) {
        *(f32 *)(q + 0x1E0) = 2.75f;
    }
    func_L01_0044E850(a0, q + 0x170, 6, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L03_003D0A28 */
