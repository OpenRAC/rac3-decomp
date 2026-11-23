#include "common.h"

/* localdecomp:start func_L09_003C4550 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003C4550;

extern u8 *D_L09_001E011C;
extern V_003C4550 D_L09_001DEA20 __attribute__((section(".sdata")));
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003890D8(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_003888C8(void *, void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, int, int);
extern int func_0037E208(int, int);
extern f32 func_L01_00436500(void *);

void func_L09_003C4550(u8 *m) {
    V_003C4550 joints[4];
    f32 matrix[12] __attribute__((aligned(16)));
    V_003C4550 point;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *a;
    s32 active;

    if (*(s32 *)(v + 0x758) == -1) return;
    a = D_L09_001E011C + (*(s32 *)(v + 0x758) << 8);
    if (*(f32 *)(v + 0x30) <= 0.0f && m[0xBC] != 9) {
        *(s32 *)(a + 0x98) = 0;
        *(u16 *)(a + 0x34) = (*(u16 *)(a + 0x34) | 0x41) & 0xEFFF;
        func_L01_004A6DF8(a, 1);
    }
    func_003BD9A0(m, 14, joints);
    func_003890D8(v + 0x570, matrix);
    func_00388EB8(a + 0xC0, m + 0xC0, matrix);
    func_003888C8(&point, &D_L09_001DEA20, a + 0xC0);
    vec_add_ab(a + 0x10, &joints[3], &point);
    active = (a[0x20] == 7 || a[0x20] == 8);
    if (a[0x20] != 6 && *(u16 *)(a + 0x96) > 20 && *(s16 *)(v + 0x78E) >= 2) {
        if (*(s16 *)(v + 0x78E) >= 4) {
            func_003BE4F0(a, 8, 0, 2);
            func_L01_00441FB8(a, 8, -1);
        } else {
            func_003BE4F0(a, 7, 0, 2);
            func_L01_00441FB8(a, 7, -1);
        }
        *(s16 *)(v + 0x78E) = 0;
        active = 1;
    }
    if (!active && v[0x7AE] && a[0x20] != 6) {
        func_003BE4F0(a, 6, 0, 2);
        func_L01_00441FB8(a, 6, -1);
    }
    if (!active && v[0x7AF] && *(f32 *)(*(u8 **)(v + 0x6D0) + 0x138) > 0.0333333351f &&
        (*(unsigned long *)(v + 0x7A8) & 0xF00000000000000UL)) {
        func_003BE4F0(a, 3, 0, 2);
        active = 1;
        func_L01_00441FB8(a, 3, -1);
    }
    if (!active && *(f32 *)(*(u8 **)(v + 0x6D0) + 0xD8) > 0.02036217600107193f) {
        func_003BE4F0(a, 4, 0, 6);
        active = 1;
        func_L01_00441FB8(a, 4, -1);
    }
    if (!active && *(f32 *)(*(u8 **)(v + 0x6D0) + 0xD8) < -0.02036217600107193f) {
        func_003BE4F0(a, 5, 0, 6);
        active = 1;
        func_L01_00441FB8(a, 5, -1);
    }
    if (!active && a[0x20] != 9 && *(s16 *)(*(u8 **)(v + 0x6D0) + 0x12A) >= 16) {
        func_003BE4F0(a, 9, 0, 2);
        func_L01_00441FB8(a, 9, -1);
    }
    v[0x7AE] = 0;
    switch (a[0x20]) {
    case 1:
        if (*(u16 *)(a + 0x96) > *(s16 *)(v + 0x7AC)) {
            func_003BE4F0(a, 2, 0, 10);
            *(s16 *)(v + 0x7AC) = func_0037E208(170, 300);
            func_L01_00441FB8(a, 2, -1);
        }
        break;
    case 2:
        if (*(u16 *)(a + 0x96) > *(s16 *)(v + 0x7AC)) {
            func_003BE4F0(a, 1, 0, 10);
            *(s16 *)(v + 0x7AC) = func_0037E208(150, 300);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 6:
        *(f32 *)(a + 0x48) = 1.5f;
        if (a[0x60] & 2) {
            *(f32 *)(a + 0x48) = 1.0f;
            func_003BE4F0(a, 1, 0, 10);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 9:
        if (*(s16 *)(*(u8 **)(v + 0x6D0) + 0x128)) {
            if (func_L01_00436500(a) >= 4.0f) *(f32 *)(a + 0x48) = 0.0f;
            else *(f32 *)(a + 0x48) = 0.15f;
        } else {
            *(f32 *)(a + 0x48) = 1.0f;
        }
    case 7:
    case 8:
        if (a[0x60] & 2) {
            func_003BE4F0(a, 1, 0, 10);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 3:
    case 4:
    case 5:
        if (*(u16 *)(a + 0x96) > 30) {
            func_003BE4F0(a, 1, 0, 10);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    }
    ++*(u16 *)(a + 0x96);
}
/* localdecomp:end func_L09_003C4550 */
