#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_003622D0 */
typedef struct {
    u8 pad[0x30];
    s32 f30;
    s32 f34;
} S_3622D0;
extern S_3622D0 D_L14_001E6480;
__asm__(".extern D_L14_001DD8CC, 4");
__asm__(".extern D_L14_001DD8D0, 4");
__asm__(".extern D_L14_001DD8D4, 4");
__asm__(".extern D_L14_001DD8D8, 4");
extern s32 D_L14_001DD8CC;
extern s32 D_L14_001DD8D0;
extern f32 D_L14_001DD8D4;
extern f32 D_L14_001DD8D8;
extern s32 func_L01_004BA800(void);
extern u8 *func_L10_00406780(s32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L14_00361A50(u8 *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
s32 func_L14_003622D0(u8 *a0, u8 *a1) {
    vu0_v4 v;
    u8 *o;
    f32 f;
    if (func_L01_004BA800() != 0) {
        if (D_L14_001E6480.f30 == 1) {
            if (D_L14_001E6480.f34 == (D_L14_001DD8CC * 5 + 2) / 6) {
                o = func_L10_00406780(0x1C93);
                if (o == 0) {
                    goto state1;
                }
                vec_sub_ab(&v, o + 0x10, a0 + 0x10);
                v.x += D_L14_001DD8D4;
                v.z += D_L14_001DD8D8;
                *(f32 *)(a1 + 0x18) = func_0038D160(func_0038CED8(&v), v.z);
                f = func_0038D160(v.x, v.y);
                *(f32 *)(a1 + 0x1C) = f;
                *(f32 *)(a0 + 0xF8) = f;
                func_0038D308(a0 + 0xC0, a0 + 0xF0);
                *(s32 *)(a1 + 0x24) = 0;
                *(f32 *)(a1 + 0x1F4) = *(f32 *)(a1 + 0x18);
                *(s32 *)(a1 + 0x20) = 0;
                *(f32 *)(a1 + 0x214) = *(f32 *)(a1 + 0x18);
                goto state1;
            }
            if (D_L14_001E6480.f34 == (D_L14_001DD8D0 * 5 + 2) / 6) {
                o = func_L10_00406780(0x1C93);
                if (o != 0) {
                    vec_sub_ab(&v, o + 0x10, a0 + 0x10);
                    *(f32 *)(a1 + 0x18) = func_0038D160(func_0038CED8(&v), v.z);
                    *(f32 *)(a1 + 0x1C) = func_0038D160(v.x, v.y);
                    func_L01_004450F0(a0, 3, -1);
                return 1;
                }
            }
        } else {
            *(f32 *)(a1 + 0x18) = 0.0f;
            *(f32 *)(a1 + 0x1C) = 0.0f;
            if (a0[0x20] == 2) {
                func_L01_004450F0(a0, 3, -1);
                return 1;
            }
            goto check6;
        }
    }
    if (a0[0x20] == 2) {
        func_L14_00361A50(a0, a1);
        func_L01_004450F0(a0, 3, -1);
                return 1;
    }
check6:
    if (a0[0x20] == 6) {
        goto state1;
    }
    return 0;
state1:
    func_L01_004450F0(a0, 1, -1);
    return 1;
}
/* localdecomp:end func_L14_003622D0 */

/* localdecomp:start func_L14_003624B0 */
extern s32 func_L01_004561B8(u8 *a0);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L14_001DD828;
extern s32 D_L14_001DD82C;

s32 func_L14_003624B0(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0)) {
        *(s32 *)(a1 + 0x14) = func_00382498(D_L14_001DD828, D_L14_001DD82C);
    }
    if (func_0038CAD0(a1 + 0x14)) {
        func_L01_004450F0(a0, 2, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_003624B0 */

/* localdecomp:start func_L14_00362520 */
extern s32 D_001DD830;
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L14_00361B30(u8 *, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L14_00362520(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(a1 + 0x14) = D_001DD830;
    }
    func_L14_00361B30(a0, a1);
    if (func_0038CAD0(a1 + 0x14) != 0) {
        func_L01_004450F0(a0, 4, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_00362520 */

/* localdecomp:start func_L14_00362590 */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L14_00361B30(u8 *, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_001DD834;

s32 func_L14_00362590(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0)) {
        *(s32 *)(a1 + 0x14) = D_001DD834;
    }
    if (func_L14_00361B30(a0, a1)) {
        if (func_0038CAD0(a1 + 0x14)) {
            func_L01_004450F0(a0, 5, -1);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L14_00362590 */

/* localdecomp:start func_L14_00362608 */
__asm__(".extern D_L14_001DD838, 4");
__asm__(".extern D_L14_001DD83C, 4");
__asm__(".extern D_L14_001DD850, 4");
__asm__(".extern D_L14_001DD854, 4");
__asm__(".extern D_L14_001DD858, 4");
__asm__(".extern D_L14_001DD8E0, 4");
extern s32 D_L14_001DD838;
extern f32 D_L14_001DD83C;
extern f32 D_L14_001DD850;
extern f32 D_L14_001DD854;
extern f32 D_L14_001DD858;
extern s32 D_L14_001DD8E0;
extern s32 func_L01_004561B8(u8 *);
extern void func_L14_00361DC0(void *, u8 *);
extern void func_L01_004AADE8(s32, s32, void *, s32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
s32 func_L14_00362608(u8 *a0, u8 *a1) {
    s32 n;
    f32 t;
    f32 a;
    f32 s;
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(a1 + 0x14) = D_L14_001DD838;
        func_L14_00361DC0(a0, a1);
        func_L01_004AADE8(0x12, 0, a0, 0);
        func_L01_004AADE8(0x11, 0, a0, 0);
        func_L01_004AADE8(0x14, 0, a0, 0);
        func_L01_004AADE8(0x13, 0, a0, D_L14_001DD8E0);
    }
    n = *(s32 *)(a1 + 0x14) - 1;
    t = 1.0f - (f32)n / (f32)D_L14_001DD838;
    *(s32 *)(a1 + 0x14) = n;
    if (0.5f < t) {
        t = (t - 0.5f) * D_L14_001DD83C + 0.5f;
    }
    a = t * 3.1415927f;
    s = func_0038D0B0(a);
    if (0.0f < s) {
        if (t < 0.5f) {
            s = 1.0f - s * s;
            *(f32 *)(a1 + 0x200) = -D_L14_001DD850 + s * D_L14_001DD850;
        } else {
            *(f32 *)(a1 + 0x200) = s * -D_L14_001DD850;
        }
    } else {
        *(f32 *)(a1 + 0x200) = 0.0f;
    }
    s = func_0038D0B0(func_0038DAB8(a, -(D_L14_001DD858 * 0.017453292f)));
    if (0.0f < s) {
        if (t < 0.5f) {
            s = 1.0f - s * s;
            *(f32 *)(a1 + 0x220) = -D_L14_001DD854 + s * D_L14_001DD854;
        } else {
            *(f32 *)(a1 + 0x220) = s * -D_L14_001DD854;
        }
    } else {
        if (0.5f < t) {
            *(f32 *)(a1 + 0x200) = 0.0f;
            *(f32 *)(a1 + 0x220) = 0.0f;
            func_L01_004450F0(a0, 6, -1);
            return 1;
        }
        *(f32 *)(a1 + 0x220) = 0.0f;
    }
    return 0;
}
/* localdecomp:end func_L14_00362608 */

INCLUDE_ASM("asm/levels", func_L14_00362868);

/* localdecomp:start func_L14_00362A50 */
extern f32 D_L14_00286520[];
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_0038CE20(f32 *, void *, f32);
void func_L14_00362A50(f32 a, f32 b, s32 u0, s32 u1, f32 *p6, f32 *p7, f32 *p8, f32 *p9) {
    f32 v0[4];
    f32 v1[4];
    s32 i;
    f32 *o = D_L14_00286520;
    for (i = 3; i >= 0; i--) {
        func_0038CDF8(v0, p7, p8, p9[0]);
        func_0038CE20(v1, p6, (a + (b - a) * p9[0]) * ((p9[1] - 0.5f) * 2.0f));
        p9 += 2;
        o[0] = v0[0] + v1[0];
        o[1] = v0[1] + v1[1];
        o[2] = v0[2] + v1[2];
        o += 3;
    }
}
/* localdecomp:end func_L14_00362A50 */

INCLUDE_ASM("asm/levels", func_L14_00362B68);

/* localdecomp:start func_L14_00362BF8 */
extern int D_L14_001E1200[] __attribute__((section(".sdata")));
void func_L14_00362BF8(int a, int b, int v)
{
    int i;
    for (i = 3; i >= 0; i--)
        D_L14_001E1200[i] = v;
}
/* localdecomp:end func_L14_00362BF8 */

/* localdecomp:start func_L14_00362C28 */
extern f32 D_L14_00286520[];
extern int D_L14_001E1200[] __attribute__((section(".sdata")));
extern f32 D_L14_001E1220[] __attribute__((section(".sdata")));
extern void func_003A9440(s32, unsigned long);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern void func_L14_00362B68(f32, s32, s32, f32 *, f32 *);
void func_L14_00362C28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 t) {
    func_003A9440(0x42, 0x800000006AUL);
    func_L14_00362B68(t, a0, a1, (f32 *)a2, (f32 *)a4);
    func_003D3A24(4, D_L14_00286520, D_L14_001E1200, D_L14_001E1220, 1);
    func_003A9440(0x42, 0x8000000058UL);
    func_L14_00362B68(t, a0, a1, (f32 *)a3, (f32 *)a5);
    func_003D3A24(4, D_L14_00286520, D_L14_001E1200, D_L14_001E1220, 1);
}
/* localdecomp:end func_L14_00362C28 */

INCLUDE_ASM("asm/levels", func_L14_00362D30);
