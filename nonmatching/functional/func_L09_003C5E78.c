/* functional: high. Rewritten from the PAL assembly (the NTSC draft's code differs: other thresholds, callees, globals). Compiles at level 09 with the file's flags, 260 of ~324 words differ only through shifted branch targets/scheduling (same stack 0xB0, same call sequence); switch states 1..9 from jtbl_002BF780 (3,4,5 share a case, 9 falls into 7/8). */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C5E78;
extern u8 *D_L09_001E009C;
extern V4_003C5E78 D_L09_001DE9E0;
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_004395E0(void *);

void func_L09_003C5E78(u8 *m) {
    V4_003C5E78 joints[4];
    f32 matrix[12] __attribute__((aligned(16)));
    V4_003C5E78 point;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *a;
    s32 active;
    s32 idx = *(s32 *)(v + 0x758);

    if (idx == -1) {
        return;
    }
    a = D_L09_001E009C + (idx << 8);
    if (*(f32 *)(v + 0x30) <= 0.0f && m[0xBC] != 9) {
        *(s32 *)(a + 0x98) = 0;
        *(u16 *)(a + 0x34) = (*(u16 *)(a + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a, 1);
    }
    func_003C2EC0(m, 14, joints);
    func_0038D810(v + 0x570, matrix);
    func_0038D5F0(a + 0xC0, m + 0xC0, matrix);
    func_0038D000(&point, &D_L09_001DE9E0, a + 0xC0);
    vec_add_ab(a + 0x10, &joints[3], &point);

    active = (u8)(a[0x20] - 7) < 2;
    if (a[0x20] != 6 && *(u16 *)(a + 0x96) >= 0x12 && *(s16 *)(v + 0x78E) >= 2) {
        if (*(s16 *)(v + 0x78E) >= 4) {
            func_003C3A10(a, 8, 0, 2);
            func_L01_004450F0(a, 8, -1);
            *(s16 *)(v + 0x78E) = 0;
        } else {
            func_003C3A10(a, 7, 0, 2);
            func_L01_004450F0(a, 7, -1);
            *(s16 *)(v + 0x78E) = 0;
        }
        active = 1;
    }
    if (!active && v[0x7AE] != 0 && a[0x20] != 6) {
        func_003C3A10(a, 6, 0, 2);
        func_L01_004450F0(a, 6, -1);
    }
    if (!active && v[0x7AF] != 0 && *(f32 *)(*(u8 **)(v + 0x6D0) + 0x138) > 0.040000003f &&
        (*(unsigned long *)(v + 0x7A8) & 0xF00000000000000UL) != 0) {
        func_003C3A10(a, 3, 0, 2);
        active = 1;
        func_L01_004450F0(a, 3, -1);
    }
    if (!active && *(f32 *)(*(u8 **)(v + 0x6D0) + 0xD8) > 0.024434611f) {
        func_003C3A10(a, 4, 0, 5);
        active = 1;
        func_L01_004450F0(a, 4, -1);
    }
    if (!active && *(f32 *)(*(u8 **)(v + 0x6D0) + 0xD8) < -0.024434611f) {
        func_003C3A10(a, 5, 0, 5);
        active = 1;
        func_L01_004450F0(a, 5, -1);
    }
    if (!active && a[0x20] != 9 && *(s16 *)(*(u8 **)(v + 0x6D0) + 0x12A) >= 0xD) {
        func_003C3A10(a, 9, 0, 2);
        func_L01_004450F0(a, 9, -1);
    }
    v[0x7AE] = 0;

    switch (a[0x20]) {
    case 1:
        if ((*(s16 *)(v + 0x7AC) * 5 + 2) / 6 < *(u16 *)(a + 0x96)) {
            func_003C3A10(a, 2, 0, 8);
            *(s16 *)(v + 0x7AC) = func_00382498(170, 300);
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 2:
        if ((*(s16 *)(v + 0x7AC) * 5 + 2) / 6 < *(u16 *)(a + 0x96)) {
            func_003C3A10(a, 1, 0, 8);
            *(s16 *)(v + 0x7AC) = func_00382498(150, 300);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 6:
        *(f32 *)(a + 0x48) = 1.5f;
        if (a[0x60] & 2) {
            *(f32 *)(a + 0x48) = 1.0f;
            func_003C3A10(a, 1, 0, 8);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 9:
        if (*(s16 *)(*(u8 **)(v + 0x6D0) + 0x128) != 0) {
            if (func_L01_004395E0(a) >= 4.0f) {
                *(s32 *)(a + 0x48) = 0;
            } else {
                *(f32 *)(a + 0x48) = 0.15f;
            }
        } else {
            *(f32 *)(a + 0x48) = 1.0f;
        }
        /* fall through */
    case 7:
    case 8:
        if (a[0x60] & 2) {
            func_003C3A10(a, 1, 0, 8);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 3:
    case 4:
    case 5:
        if (*(u16 *)(a + 0x96) >= 0x1A) {
            func_003C3A10(a, 1, 0, 8);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    }
    *(u16 *)(a + 0x96) = *(u16 *)(a + 0x96) + 1;
}
