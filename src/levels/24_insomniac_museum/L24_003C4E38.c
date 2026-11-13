#include "common.h"

typedef struct {
    u8 b[0x1C];
} S_003C5138;

/* localdecomp:start func_L24_003C4E38 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x1E0];
    s16 h1E0;
    u8 pad1E2[0x25ED - 0x1E2];
    u8 b25ED;
    u8 pad25EE[0x27FC - 0x25EE];
    s32 w27FC;
} G_3C4E38;
extern G_3C4E38 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001A4C60[];
extern u8 *D_001D52FC;
extern u8 *D_L24_001DF51C;
extern f32 D_L24_001DEED0;
__asm__(".extern D_L24_001DEED0, 16");
extern u8 *D_L24_001DF600;
__asm__(".extern D_L24_001DF600, 16");
extern s32 D_L24_002CF5B0[];
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C4138(void *, f32, f32);
extern void func_L01_0042B068(s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_003C7C38(void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00452658(s32, s32);
extern void func_L24_003C5138(void);

void func_L24_003C4E38(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 st = a0[0x20];
    if (st == 0) {
        if (*(s32 *)(p + 0xC) != -1) {
            u8 *m = D_L24_001DF51C + (*(s32 *)(p + 0xC) << 8);
            *(u8 **)(p + 0x10) = m;
            *(u128_t *)(p + 0x20) = *(u128_t *)(m + 0x10);
            *(u128_t *)(p + 0x30) = *(u128_t *)(m + 0xF0);
        } else {
            *(u8 **)(p + 0x10) = 0;
        }
        *(s32 *)p = 0;
        a0[0x30] = 0xFF;
        *(f32 *)(p + 0x14) = 0.0f;
        func_L01_004450F0(a0, 1, -1);
    } else {
        if (*(s32 *)(p + 0x4) == -1) {
            return;
        }
        if (*(s32 *)(p + 0x8) == -1) {
            return;
        }
        if (st == 2) {
            D_001A4BE0.h1E0 = 5;
            D_001A4BE0.b25ED = 1;
            func_003C4138(p + 0x14, 1.0f, 0.100000009f);
            D_L24_001DEED0 = *(f32 *)(p + 0x14);
            if (*(f32 *)(p + 0x14) != 1.0f) {
                return;
            }
            if (*(s32 *)p != 0) {
                D_001A4BE0.w27FC = 0;
                func_L01_0042B068(1, 0);
                func_L01_004F50C8(D_L24_001DF600 + (*(s32 *)(p + 0x8) << 7) + 0x30, D_L24_001DF600 + (*(s32 *)(p + 0x8) << 7) + 0x70, 0, 1);
            } else {
                D_001A4BE0.w27FC = 0;
                func_L01_0042B068(0, 0);
                func_L01_004F50C8(D_L24_001DF600 + (*(s32 *)(p + 0x4) << 7) + 0x30, D_L24_001DF600 + (*(s32 *)(p + 0x4) << 7) + 0x70, 0, 1);
            }
            func_L01_004450F0(a0, 3, -1);
            return;
        }
        if (st == 3) {
            func_003C4138(p + 0x14, 0.0f, 0.100000009f);
            D_L24_001DEED0 = *(f32 *)(p + 0x14);
            if (*(f32 *)(p + 0x14) != 0.0f) {
                return;
            }
            func_L01_004450F0(a0, 1, -1);
            return;
        }
    }
    if (*(s32 *)p != 0) {
        if (D_L24_002CF5B0[0] != 0) {
            return;
        }
        func_L01_00404808(func_L24_003C5138, a0);
        if (!(*(u32 *)(D_001D52FC + 0x1A4) & 0x10)) {
            return;
        }
        if (*(u8 **)(p + 0x10) != 0) {
            *(u128_t *)(*(u8 **)(p + 0x10) + 0x10) = *(u128_t *)(p + 0x20);
            *(u128_t *)(*(u8 **)(p + 0x10) + 0xF0) = *(u128_t *)(p + 0x30);
            (*(u8 **)(p + 0x10))[0x20] = 0;
            func_003C7C38(*(u8 **)(p + 0x10));
        }
        *(s32 *)p = 0;
        func_L01_004450F0(a0, 2, -1);
        return;
    }
    if (func_0038CF38(D_001A4C60, a0 + 0x10) <= 6.0f) {
        func_L01_00452560(0, 4, 0x16B8, 1, 0, 0, 0);
        if (*(u32 *)(D_001D52FC + 0x1A4) & 0x10) {
            *(s32 *)p = 1;
            func_L01_00452658(0, 4);
            func_L01_004450F0(a0, 2, -1);
        }
    }
}
/* localdecomp:end func_L24_003C4E38 */

/* localdecomp:start func_L24_003C5138 */
extern u8 D_L24_001DEA30[];
extern s32 func_00381FF0(s32);
extern void func_003AF408(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L24_003C5138(void) {
    S_003C5138 buf;
    s32 v;

    buf = *(S_003C5138 *)D_L24_001DEA30;
    v = func_00381FF0(0x850);
    func_003AF408(&buf, 0x80F0F0F0, v, 1, 0, -1, 0, 0, 0, 0);
}
/* localdecomp:end func_L24_003C5138 */
