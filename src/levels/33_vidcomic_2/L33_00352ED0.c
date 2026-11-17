#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00352ED0 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 D_L33_001DDB48;
__asm__(".extern D_L33_001DDB48, 4");
extern s32 D_L33_001DDB44;
__asm__(".extern D_L33_001DDB44, 4");
extern s32 D_L33_001DDA70;
__asm__(".extern D_L33_001DDA70, 4");
extern f32 D_L33_001DD8E8;
__asm__(".extern D_L33_001DD8E8, 4");
extern f32 D_L33_001DDA84;
__asm__(".extern D_L33_001DDA84, 4");
extern f32 D_L33_001DDA6C;
__asm__(".extern D_L33_001DDA6C, 4");
extern f32 D_L33_001DD878[2];
__asm__(".extern D_L33_001DD878, 8");
extern f32 D_L33_001DD868[2];
__asm__(".extern D_L33_001DD868, 8");
extern f32 D_L33_001DD958[2];
__asm__(".extern D_L33_001DD958, 8");
extern f32 D_L33_001DD988[2];
__asm__(".extern D_L33_001DD988, 8");
extern f32 D_L33_001DDA30[2];
__asm__(".extern D_L33_001DDA30, 8");
extern f32 D_L33_001DD9B0[2];
__asm__(".extern D_L33_001DD9B0, 8");
extern f32 D_L33_001DDA40[2];
__asm__(".extern D_L33_001DDA40, 8");
extern f32 D_L33_001DDA60[2];
__asm__(".extern D_L33_001DDA60, 8");

void func_L33_00352ED0(u8 *a0, s32 a1) {
    s32 i = 0x1761 - *(s16 *)(a0 + 0xAA);

    func_L01_004450F0(a0, a1, -1);
    switch (a0[0x20]) {
    case 1:
        func_003C3A10(a0, 4, (s32)D_L33_001DD878[i], (D_L33_001DDB48 * 5 + 2) / 6);
        *(f32 *)(a0 + 0x48) = D_L33_001DD868[i];
        break;
    case 2:
        if (a0[0x43] != 0xB) {
            func_003C3A10(a0, 0xB, (s32)D_L33_001DD958[i], D_L33_001DDB44);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        *(f32 *)(a0 + 0x44) += *(f32 *)(a0 + 0x4C);
        break;
    case 3:
        if (a0[0x43] != 7) {
            func_003C3A10(a0, 7, 0, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DD988[i];
        break;
    case 4:
        func_003C3A10(a0, 0xA, (s32)D_L33_001DDA30[i], D_L33_001DDB44);
        *(f32 *)(a0 + 0x48) = D_L33_001DD9B0[i];
        *(f32 *)(a0 + 0x44) += *(f32 *)(a0 + 0x4C);
        break;
    case 5:
        if (func_00382498(0, 1) == 0) {
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, (D_L33_001DDB48 * 5 + 2) / 6);
            }
        } else {
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, (D_L33_001DDB48 * 5 + 2) / 6);
            }
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 7:
        if (a0[0x43] != 5) {
            func_003C3A10(a0, 5, 0, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DD8E8;
        break;
    case 8:
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, (s32)D_L33_001DDA84, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 9:
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, 0, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        break;
    case 10:
        if (a0[0x43] != 0xC) {
            func_003C3A10(a0, 0xC, (s32)D_L33_001DDA6C, (D_L33_001DDA70 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DDA40[i];
        break;
    case 11:
        if (a0[0x43] != 8) {
            func_003C3A10(a0, 8, (s32)D_L33_001DDA60[i], (D_L33_001DDA70 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DDA40[i];
        break;
    case 13:
        if (a0[0x43] != 9) {
            func_003C3A10(a0, 9, 0, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 6:
    case 12:
    case 14:
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        break;
    case 15:
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, (D_L33_001DDB48 * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 0:
    case 0x42:
        break;
    }
}
/* localdecomp:end func_L33_00352ED0 */

/* localdecomp:start func_L33_003532D8 */
typedef struct { u8 r, g, b, a; } C_003532D8;
extern void func_L31_00346998(void *, void *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L33_00353970();
extern void func_L33_003523C0();
extern void func_L33_00353EF0();
extern void func_L33_00353540();
extern C_003532D8 D_L33_001DD898[2];
__asm__(".extern D_L33_001DD898, 8");
extern f32 D_L33_001DD9D0[2];
__asm__(".extern D_L33_001DD9D0, 8");
extern f32 D_L33_001DDAA0[2];
__asm__(".extern D_L33_001DDAA0, 8");
extern f32 D_L33_001DDA90[2];
__asm__(".extern D_L33_001DDA90, 8");
extern f32 D_L33_001DDAC0[2];
__asm__(".extern D_L33_001DDAC0, 8");
extern f32 D_L33_001DDAB0[2];
__asm__(".extern D_L33_001DDAB0, 8");
extern f32 D_L33_001DDB60[2];
__asm__(".extern D_L33_001DDB60, 8");
extern f32 D_L33_001DDB50[2];
__asm__(".extern D_L33_001DDB50, 8");
extern f32 D_L33_001DDB88[2];
__asm__(".extern D_L33_001DDB88, 8");
extern f32 D_L33_001DDB78[2];
__asm__(".extern D_L33_001DDB78, 8");
extern s32 D_L33_001DDB94;
__asm__(".extern D_L33_001DDB94, 4");
extern s32 D_L33_001DDC30;
__asm__(".extern D_L33_001DDC30, 4");
extern s32 D_L33_001DDC34;
__asm__(".extern D_L33_001DDC34, 4");
extern s32 D_L33_001DDC40;
__asm__(".extern D_L33_001DDC40, 4");
extern s32 D_L33_001DDBB4;
__asm__(".extern D_L33_001DDBB4, 4");
extern s32 D_L33_001DDBB8;
__asm__(".extern D_L33_001DDBB8, 4");
extern s32 D_L33_001DDBC4;
__asm__(".extern D_L33_001DDBC4, 4");
extern s32 D_L33_001DDC7C;
__asm__(".extern D_L33_001DDC7C, 4");
extern s32 D_L33_001DDC80;
__asm__(".extern D_L33_001DDC80, 4");
extern s32 D_L33_001DDCA4;
__asm__(".extern D_L33_001DDCA4, 4");
extern s32 D_L33_001DDC74;
__asm__(".extern D_L33_001DDC74, 4");
extern s32 D_L33_001DDBEC;
__asm__(".extern D_L33_001DDBEC, 4");
extern s32 D_L33_001DDBF0;
__asm__(".extern D_L33_001DDBF0, 4");
extern s32 D_L33_001DDC0C;
__asm__(".extern D_L33_001DDC0C, 4");
extern f32 D_L33_001DDC3C;
__asm__(".extern D_L33_001DDC3C, 4");
extern f32 D_L33_001DDBC0;
__asm__(".extern D_L33_001DDBC0, 4");
extern f32 D_L33_001DDC8C;
__asm__(".extern D_L33_001DDC8C, 4");
extern f32 D_L33_001DDC04;
__asm__(".extern D_L33_001DDC04, 4");
extern u8 D_L33_001E1898[] __attribute__((section(".sdata")));
extern u8 D_L33_001E1858[] __attribute__((section(".sdata")));
extern u8 D_L33_001E18B8[] __attribute__((section(".sdata")));
extern u8 D_L33_001E1878[] __attribute__((section(".sdata")));

void func_L33_003532D8(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s32 initialized;
    s32 i = 0x1761 - *(s16 *)(a0 + 0xAA);

    *(s16 *)(s1 + 0x4C) = 4;
    *(s16 *)(s1 + 0x4E) = 0xF;
    *(u8 *)(s1 + 0x47) = 0xFF;
    *(f32 *)(s1 + 0x0) = D_L33_001DD9D0[i];
    *(s16 *)(s1 + 0x4) = (s32)D_L33_001DD9D0[i];
    *(u8 *)(s1 + 0x14) = D_L33_001DD898[i].r;
    func_L31_00346998(a0, s1 + 0x50);
    *(f32 *)(s1 + 0xB4) = func_003824E0(D_L33_001DDAA0[i], D_L33_001DDA90[i]);
    *(f32 *)(s1 + 0xB8) = func_003824E0(D_L33_001DDAC0[i], D_L33_001DDAB0[i]);
    *(f32 *)(s1 + 0xBC) = func_003824E0(D_L33_001DDB60[i], D_L33_001DDB50[i]);
    *(f32 *)(s1 + 0xC0) = func_003824E0(D_L33_001DDB88[i], D_L33_001DDB78[i]);
    *(vu0_q *)(s1 + 0x80) = *(vu0_q *)(a0 + 0x10);
    *(f32 *)(s1 + 0x90) = 1.5707964f;
    *(s32 *)(s1 + 0xB0) = 0;
    initialized = D_L33_001DDB94;
    *(s32 *)(s1 + 0xA8) = 0;
    *(s32 *)(s1 + 0x94) = 0;
    if (initialized == 0) {
        D_L33_001DDB94 = 1;
        func_L03_0034B218(D_L33_001E1898, D_L33_001DDC30, D_L33_001DDC34, D_L33_001DDC3C, D_L33_001DDC40, func_L33_00353970);
        *(s32 *)(D_L33_001E1898 + 0x10) = 0x44;
        func_L03_0034B218(D_L33_001E1858, D_L33_001DDBB4, D_L33_001DDBB8, D_L33_001DDBC0, D_L33_001DDBC4, func_L33_003523C0);
        *(s32 *)(D_L33_001E1858 + 0x10) = 0x44;
        func_L03_0034B218(D_L33_001E18B8, D_L33_001DDC7C, D_L33_001DDC80, D_L33_001DDC8C, D_L33_001DDCA4, func_L33_00353EF0);
        *(s32 *)(D_L33_001E18B8 + 0x10) = D_L33_001DDC74;
        func_L03_0034B218(D_L33_001E1878, D_L33_001DDBEC, D_L33_001DDBF0, D_L33_001DDC04, D_L33_001DDC0C, func_L33_00353540);
        *(s32 *)(D_L33_001E1858 + 0x10) = 0x44;
    }
}
/* localdecomp:end func_L33_003532D8 */
