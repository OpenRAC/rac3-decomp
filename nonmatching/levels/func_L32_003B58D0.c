/* func_L32_003B58D0: 143 diff with --flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division' --as ps2as. Remaining: a1/m s-register swap (m=s1,a1=s2 vs retail a1=s1,m=s2), f20-f22 numbering in the sin/cos block. */
#include "common.h"

#include "vu0.h"
extern f32 D_L32_001DEEC0;
extern f32 D_L32_001DEEC4;
extern s32 D_L32_001DEEC8[2];
extern f32 D_L32_001DEED4;
extern f32 D_L32_001DEED8;
extern f32 D_L32_001DEEDC;
extern s32 D_L32_001DEE90;
extern s32 D_L32_001DEE94;
extern s32 D_L32_001DEE98;
extern f32 D_L32_001DEEB0;
extern f32 D_L32_001DEEB4;
extern f32 D_L32_001DEEAC;
extern u8 *D_L32_0021FAEC[];
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L32_003B6618(void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

__asm__(".extern D_L32_001DEEC0, 4");
__asm__(".extern D_L32_001DEEC4, 4");
__asm__(".extern D_L32_001DEEC8, 8");
__asm__(".extern D_L32_001DEED4, 4");
__asm__(".extern D_L32_001DEED8, 4");
__asm__(".extern D_L32_001DEEDC, 4");
__asm__(".extern D_L32_001DEE90, 4");
__asm__(".extern D_L32_001DEE94, 4");
__asm__(".extern D_L32_001DEE98, 4");
__asm__(".extern D_L32_001DEEB0, 4");
__asm__(".extern D_L32_001DEEB4, 4");
__asm__(".extern D_L32_001DEEAC, 4");

void func_L32_003B58D0(u8 *a0, u8 *a1) {
    f32 vec[4] __attribute__((aligned(16)));
    u8 *m;
    u8 *n;
    u8 *v;
    f32 f20;
    f32 f21;
    f32 f22;
    s32 r;
    f32 f0;

    if (a1 != 0) {
        m = *(u8 **)a1;
        n = *(u8 **)(a1 + 4);
        v = m != 0 ? *(u8 **)(m + 0x68) : 0;
        if (m != 0 && n != 0 && v != 0) {
            if (*(u16 *)(a1 + 0xA) & 1) {
                f22 = func_003824E0(0.0f, D_L32_001DEEC0);
                f20 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
                vec[0] = func_0038D098(f20) * f22;
                vec[2] = func_0038D0B0(f20) * f22;
                vec[1] = 0.0f;
                r = func_L32_003B6618(m);
                if (r == -2) {
                    *(s16 *)(a0 + 0xA) = 0;
                    return;
                }
                if (r == -1) {
                    func_003C2F58(m, 1, a0 + 0x10);
                } else {
                    func_003C2F58(m, r % 8 + 2, a0 + 0x10);
                }
                vec_add_ab(a0 + 0x10, a0 + 0x10, vec);
                *(f32 *)(a0 + 0x14) = *(f32 *)(a0 + 0x14) + D_L32_001DEEDC;
                f0 = func_003824E0(0.0f, 1.0f);
                if (D_L32_001DEEC4 < f0) {
                    f0 = func_003824E0(D_L32_001DEED8, D_L32_001DEED4);
                    *(f32 *)(a1 + 0x10) = f0 * *(f32 *)(v + 0x140);
                    f0 = f0 * *(f32 *)(v + 0x148);
                } else {
                    f20 = func_0038CEA8((f32 *)(v + 0x140));
                    func_0038CF68(vec, vec, f20 * func_003824E0(0.0f, 0.2f));
                    *(f32 *)(a1 + 0x10) = *(f32 *)(v + 0x140) + vec[0];
                    f0 = *(f32 *)(v + 0x148) + vec[2];
                }
                *(f32 *)(a1 + 0x14) = f0;
                *(s32 *)(a1 + 0x18) = func_L30_0034DBA0(D_L32_001DEE94, D_L32_001DEE98);
                *(f32 *)(a0 + 0xC) = func_003824E0(D_L32_001DEEB4, D_L32_001DEEB0);
                a0[3] = n[0x10];
                a0[2] = D_L32_0021FAEC[0][D_L32_001DEEC8[func_00382498(0, 2)]];
                if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                    a0[3] = 0x48;
                    *(f32 *)(a0 + 0xC) = *(f32 *)(a0 + 0xC) * 1.5f;
                } else {
                    a0[3] = 0x44;
                }
            }
            f0 = func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(a0 + 0xA), (f32)*(s16 *)(a1 + 8), 1.0f);
            *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + *(f32 *)(a1 + 0x10);
            *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + *(f32 *)(a1 + 0x14);
            *(s32 *)(a0 + 4) = func_0038DBD8(f0, *(s32 *)(a1 + 0x18), D_L32_001DEE90);
            f20 = D_L32_001DEEAC * (f32)*(s16 *)(a1 + 8) * (f32)(*(u16 *)(a1 + 0xE) >> 8) * 0.00390625f;
            f21 = (f32)(*(u16 *)(a1 + 0xE) & 0xFF);
            f20 = f21 + f20;
            f0 = func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), 0.0f);
            a0[8] = (s32)func_003C4088(f21, f20, f0);
            *(f32 *)(a0 + 0xC) = *(f32 *)(a0 + 0xC) * ((f32)*(s16 *)(a0 + 0xA) / (f32)(*(s16 *)(a0 + 0xA) + 1));
        }
    }
}

INCLUDE_ASM("asm/levels", func_L32_003B58D0);
