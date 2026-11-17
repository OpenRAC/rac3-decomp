#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L30_004CF4B0(s32, s32);

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E6D08;
typedef struct {
    u8 pad0[0xC08];
    s32 w_C08;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 w_1AC0;
    u8 pad2[0x25C0 - 0x1AC4];
    P_004E6D08 *p_25C0;
    s32 w_25C4;
    u8 pad3[0x25CC - 0x25C8];
    s32 w_25CC;
    u8 pad4[0x25E9 - 0x25D0];
    u8 b_25E9;
    u8 pad5[0x25EB - 0x25EA];
    u8 b_25EB;
} S_004E6D08;

/* localdecomp:start func_L30_004E5158 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004E5158;
typedef struct {
    u8 pad0[0x34]; u16 h34;
    u8 pad1[0x42 - 0x36]; u8 b42; u8 b43;
} P_004E5158;
typedef struct {
    u8 pad0[0x84]; f32 f84;
    u8 pad1[0xBDC - 0x88]; s16 hBDC;
    u8 pad2[0xC0C - 0xBDE]; s32 wC0C;
    u8 pad3[0xC18 - 0xC10]; f32 fC18;
    u8 pad4[0x1AC0 - 0xC1C]; u8 *p1AC0;
    u8 pad5[0x1ACC - 0x1AC4]; f32 f1ACC;
    u8 pad6[0x1AE0 - 0x1AD0]; f32 f1AE0[4];
    u8 pad7[0x25C0 - 0x1AF0]; P_004E5158 *p25C0;
    s32 w25C4;
} S_004E5158;
extern f32 D_001DBF70_sda[] __attribute__((section(".sdata")));
extern f32 D_001DBF80_sda[] __attribute__((section(".sdata")));
extern f32 D_001DBF90_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DBF70_sda, 8");
__asm__(".extern D_001DBF80_sda, 8");
__asm__(".extern D_001DBF90_sda, 8");
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_004EE7F8(f32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);

void func_L30_004E5158(void) {
    V4_004E5158 a;
    V4_004E5158 b;
    V4_004E5158 c;
    s32 flag = 0;
    s32 side;
    f32 f;
    f32 sc;

    if (((S_004E5158 *)&D_001A4BE0)->p1AC0 != 0) {
        flag = ((S_004E5158 *)&D_001A4BE0)->p1AC0[0x23] == 0x21;
    }
    if (((S_004E5158 *)&D_001A4BE0)->w25C4 != 0x9D && !flag) {
        return;
    }
    if (((S_004E5158 *)&D_001A4BE0)->hBDC == 1 || ((S_004E5158 *)&D_001A4BE0)->hBDC == 3) {
        side = 1;
    } else {
        side = 0;
    }
    func_003C2F58(((S_004E5158 *)&D_001A4BE0)->p25C0, side, &a);
    f = ((S_004E5158 *)&D_001A4BE0)->fC18;
    if (flag) {
        f = ((S_004E5158 *)&D_001A4BE0)->f1ACC;
    }
    func_003C2F58(((S_004E5158 *)&D_001A4BE0)->p25C0, side, &b);
    if (((S_004E5158 *)&D_001A4BE0)->hBDC == 2) {
        sc = -0.5f;
    } else {
        sc = -0.2f;
    }
    func_0038CF68(&c, &D_001A4BE0, sc);
    vec_add_ab(&b, &b, &c);
    b.y = ((S_004E5158 *)&D_001A4BE0)->f84;
    if (func_L01_004EE7F8(D_001DBF80_sda[((S_004E5158 *)&D_001A4BE0)->hBDC]) != 0
        && ((S_004E5158 *)&D_001A4BE0)->p25C0->b42 == ((S_004E5158 *)&D_001A4BE0)->p25C0->b43) {
        func_L01_004F4E70(7, 0);
    }
    if (((S_004E5158 *)&D_001A4BE0)->wC0C == 0) {
        if (D_001DBF80_sda[((S_004E5158 *)&D_001A4BE0)->hBDC] <= f && f <= D_001DBF90_sda[((S_004E5158 *)&D_001A4BE0)->hBDC]) {
            V4_004E5158 up = { 1.0f };

            up.w = 1.0f;
            if (((S_004E5158 *)&D_001A4BE0)->p25C0->h34 & 0x8000) {
                func_0038CE20(&up, &up, -1.0f);
            }
            func_L30_0034CB68(((S_004E5158 *)&D_001A4BE0)->p25C0, &up, 0, -1, (s32)&b, 0,
                              ((S_004E5158 *)&D_001A4BE0)->f1AE0[((S_004E5158 *)&D_001A4BE0)->hBDC], D_001DBF70_sda[((S_004E5158 *)&D_001A4BE0)->hBDC]);
        }
    }
}
/* localdecomp:end func_L30_004E5158 */
