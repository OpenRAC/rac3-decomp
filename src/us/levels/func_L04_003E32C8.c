#include "common.h"

/* NTSC-U counterpart of func_L04_003E5250 (src/levels/04_marcadia/L04_003E51D0.c) */
typedef struct { u8 pad_0[0xB0]; u8 flag; } MobyA_003E51D0;
typedef struct { u8 pad_0[0x70]; s32 index; } MobyB_003E51D0;
extern u8 *D_L04_001DFE1C;
extern s32 func_L01_00452F60(u8 *);

/* localdecomp:start func_L04_003E32C8 */
typedef struct R_3E5250 { u8 pad_0[0x10]; u8 f10; } R_3E5250;
typedef struct Q_3E5250 { u8 pad_0[0x10]; s32 f10; u8 pad_14[0x34]; R_3E5250 *f48; } Q_3E5250;
typedef struct V4_3E5250 { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E5250;
typedef struct B_3E5250 {
    u8 pad_0[0x30];
    u8 f30[0x40];
    s32 f70;
    s32 f74;
    f32 f78;
    f32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    f32 f8C;
} B_3E5250;
typedef struct A_3E5250 {
    u8 pad_0[0x20];
    u8 f20;
    u8 pad_21[0x3];
    Q_3E5250 *f24;
    u8 pad_28[0x1A];
    u8 f42;
    u8 f43;
    u8 pad_44[0x4];
    f32 f48;
    u8 pad_4c[0x14];
    u8 f60;
    u8 pad_61[0x7];
    B_3E5250 *f68;
    u8 pad_6c[0x2A];
    u16 f96;
    s32 f98;
    u8 pad_9c[0x54];
    V4_3E5250 vec;
} A_3E5250;
typedef struct G_3E5250 { u8 pad_0[0x35C]; void *f35C; s32 f360; } G_3E5250;

extern G_3E5250 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_L04_001D66B0_003E32C8[8];
extern f32 D_001DF1FC_sda;
__asm__(".extern D_001DF1FC_sda, 4");
extern f32 D_001DF1F8_sda;
__asm__(".extern D_001DF1F8_sda, 4");
extern f32 D_001DF200_sda;
__asm__(".extern D_001DF200_sda, 4");
extern s32 D_001DF204_sda;
__asm__(".extern D_001DF204_sda, 4");
extern s32 D_001DF208_sda;
__asm__(".extern D_001DF208_sda, 4");
extern f32 D_001DF20C_sda;
__asm__(".extern D_001DF20C_sda, 4");
extern f32 D_001DF210_sda;
__asm__(".extern D_001DF210_sda, 4");
extern f32 D_001DF214_sda;
__asm__(".extern D_001DF214_sda, 4");
extern u8 *D_001DFE1C_sda;
__asm__(".extern D_001DFE1C_sda, 4");

extern s32 func_L04_003E37E8(void *);
extern s32 func_L04_003E38F8(u8 *, s32);
extern void func_L04_003E3DE8(void *);
extern void func_L04_003E4018(u8 *, f32);
extern f32 func_L04_003E3ED8(void *);
extern void func_L04_003E39A0();
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_L01_00436500(void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_00388398(void *);
extern void func_003BEBF8(f32, f32, void *);
extern void func_003BF838(void *, void *, void *, void *);
extern void func_L01_00445558(void *, s32, f32, f32);
extern void func_L01_00402498(void *, void *);

void func_L04_003E32C8(A_3E5250 *a0) {
    B_3E5250 *s0;
    V4_3E5250 loc;
    s32 r;
    f32 f0;
    V4_3E5250 *vp;

    s0 = a0->f68;
    switch (a0->f20) {
    case 0:
        a0->f98 = 0;
        s0->f74 = func_L04_003E37E8(a0);
        r = func_0037E1D8(a0->f24->f48->f10);
        func_003BE4F0(a0, 0, r, 1);
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_L04_003E3248((MobyA_003E51D0 *)a0, (MobyB_003E51D0 *)s0) == 0) break;
        if (func_L04_003E38F8((u8 *)a0, 0) == 0) break;
        func_L01_00441FB8(a0, 2, -1);
        break;
    case 2:
        if (a0->f43 == 0) {
            s32 old = a0->f96;
            a0->f96 = old + 1;
            if ((s0->f74 + 1) * 15 < old) {
                if (s0->f74 == 0) func_0039FE80(1, 4, a0);
                if (a0->f43 == 1) break;
                func_003BE4F0(a0, 1, 0, 5);
                break;
            }
        }
        if (a0->f42 != 1) break;
        if ((a0->f60 & 2) == 0) break;
        func_L01_00441FB8(a0, 3, -1);
        if (a0->f43 == 2) break;
        func_003BE4F0(a0, 2, 0, 5);
        break;
    case 3:
        a0->f48 = 0.0f;
        if (func_L04_003E38F8((u8 *)a0, 2) == 0) break;
        func_L01_00441FB8(a0, 4, -1);
        if (s0->f74 == 0) {
            a0->f48 = D_001DF1FC_sda + 0.01f;
        } else {
            a0->f48 = func_0037E250(D_001DF1F8_sda, D_001DF1FC_sda);
        }
        break;
    case 4:
        if (a0->f42 != a0->f43) break;
        if (54.0f < func_L01_00436500(a0)) {
            f0 = func_L01_00440918(0.0f, D_001DF200_sda) * 0.0174532924f;
            s0->f7C = 1.0f;
            s0->f78 = f0 * 0.0166666675f;
            if (s0->f70 != -1 && func_L01_00452F60(D_L04_001DFE1C + (s0->f70 << 8)) != 0) {
                s0->f8C = 0.0f;
            } else {
                s0->f8C = 1.0f;
            }
            if (a0->f43 != 3) func_003BE4F0(a0, 3, 0, 1);
            a0->f98 = a0->f24->f10;
            func_L01_00441FB8(a0, 5, -1);
            func_L04_003E3DE8(a0);
        }
        break;
    case 5:
        if (s0->f74 == 0) func_L01_00402498((void *)func_L04_003E39A0, a0);
        if (D_001A4BE0.f35C == a0 && D_001A4BE0.f360 != 0) {
            if (s0->f84 == 0) {
                func_L04_003E3DE8(a0);
                s0->f84 = 1;
            }
        } else {
            s0->f84 = 0;
        }
        if (func_00388398(&s0->f80) != 0 && D_001A4BE0.f35C == a0 && D_001A4BE0.f360 != 0) {
            s0->f7C = 1.0f;
            r = func_0037E208(D_001DF204_sda, D_001DF208_sda);
            s0->f80 = r;
        } else {
            func_003BEBF8(0.0f, D_001DF20C_sda * 0.0166666675f, &s0->f7C);
        }
        vp = &a0->vec;
        loc = *vp;
        f0 = func_L04_003E3ED8(a0);
        func_L04_003E4018((u8 *)a0, f0);
        func_003BF838(s0->f30, D_L04_001D66B0_003E32C8, &loc, vp);
        if (s0->f70 != -1 && func_L01_00452F60(D_001DFE1C_sda + (s0->f70 << 8)) == 0) {
            func_003BEBF8(1.0f, D_001DF214_sda * 0.0166666675f, &s0->f8C);
            if (s0->f88 != 0 && func_L04_003E38F8((u8 *)a0, 3) != 0) {
                func_L01_00441FB8(a0, 6, -1);
                a0->f98 = 0;
            }
        } else {
            func_003BEBF8(0.0f, D_001DF210_sda * 0.0166666675f, &s0->f8C);
        }
        break;
    case 6:
        func_L01_00445558(&a0->vec, 0, 0.0f, 0.0174532942f);
        if (a0->f43 == 3) {
            s32 old = a0->f96++;
            if (s0->f74 * 15 < old) func_003BE4F0(a0, 4, 0, 5);
        } else if (a0->f42 == 4 && (a0->f60 & 2) != 0) {
            func_L01_00441FB8(a0, 1, -1);
            if (a0->f43 != 0) func_003BE4F0(a0, 0, 0, 5);
        }
        break;
    }
}
/* localdecomp:end func_L04_003E32C8 */
