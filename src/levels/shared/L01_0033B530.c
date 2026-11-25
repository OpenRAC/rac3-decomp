#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0033B530 */
typedef vu0_v4 V4;
typedef int Q16 __attribute__((mode(TI)));
extern s32 D_L01_001D673C;
extern u8 D_L01_001EAA20[];
extern void **func_L01_0043B548(s32, s32);
extern s32 func_003C4B50(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern void func_L01_0033B7C0(u8 *);
extern u8 *func_L01_00301798(u8 *, s32, s32, s32, s32);
extern s32 func_L01_003D4BB0(u8 *);

void func_L01_0033B530(u8 *m) {
    Q16 first_frame[4];
    V4 ray_start;
    V4 ray_end;
    Q16 next_frame[4];
    u8 *p = *(u8 **)(m + 0x68);
    void **h;
    s32 t;

    if (*(s32 *)(p + 0xB0) > 0) {
        h = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(p + 0xB0) = -1;
        p[0xBE] = 7;
        ((void (*)(u8 *))h[0])(m);
        return;
    }
    if (*(s32 *)(p + 0xD0) != 0) {
        if (func_003C4B50(*(s32 *)(p + 0xD0)) == 0) {
            *(s32 *)(p + 0xD0) = 0;
        }
    }
    if (*(s32 *)(p + 0xD4) != 0) {
        if (func_003C4B50(*(s32 *)(p + 0xD4)) == 0) {
            *(s32 *)(p + 0xD4) = 0;
        }
    }
    qzero(p + 0xC0);
    m[0x20] = 1;
    *(s32 *)(p + 0xD8) = 0;
    if (*(s16 *)(m + 0xAA) == 0x1FF) {
        *(s32 *)(p + 0xE4) = *(s32 *)(p + 0xE4) + 1;
    }
    if (D_L01_001D673C != 0) {
        *(u16 *)(m + 0x34) |= 0x100;
        func_003C5180(m + 0x10, first_frame, 0);
        func_L01_004515D8(m + 0xC0, first_frame, first_frame + 1);
        func_0038CF68(&ray_start, m + 0xE0, 0.5f);
        func_0038CF68(&ray_end, m + 0xE0, -4.0f);
        vec_add_ba(&ray_start, &ray_start, m + 0x10);
        vec_add_ba(&ray_end, &ray_end, m + 0x10);
        if (func_003D3CB0(&ray_start, &ray_end, 2, m, 0) != 0) {
            *(Q16 *)(m + 0x10) = *(Q16 *)D_L01_001EAA20;
            func_003C5180(m + 0x10, next_frame, 0);
            func_L01_004515D8(m + 0xC0, next_frame, next_frame + 1);
        }
        *(s32 *)(p + 0xFC) = 1;
    }
    if (*(s32 *)(p + 0xFC) == 0) {
        *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) | 0x14;
        if (((p[0xDC] ^ 1) & 1) != 0) {
            func_L01_0033B7C0(m);
        }
    }
    *(s32 *)(p + 0x12C) = 0;
    t = *(s16 *)(m + 0xAA);
    if (t == 0x1FF) {
        *(s16 *)(p + 0xF6) = 0x64;
    } else if (t == 0x1F5) {
        *(u8 **)(p + 0x12C) = func_L01_00301798(m, 0, *(s32 *)(p + 0x134), *(s32 *)(p + 0x138), *(s32 *)(p + 0x13C));
    } else if (t == 0x200) {
        *(u8 **)(p + 0x12C) = func_L01_00301798(m, 1, *(s32 *)(p + 0x134), *(s32 *)(p + 0x138), *(s32 *)(p + 0x13C));
    } else if (t == 0x1FA) {
        *(s32 *)(p + 0x12C) = func_L01_003D4BB0(m);
    }
}
/* localdecomp:end func_L01_0033B530 */
