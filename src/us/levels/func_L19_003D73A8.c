#include "common.h"

/* NTSC-U counterpart of func_L19_003D98E0 (src/levels/19_thran_asteroid_belt/L19_003D98E0.c) */
#include "vu0.h"

/* localdecomp:start func_L19_003D73A8 */
typedef int u128_t_3D98E0 __attribute__((mode(TI)));
typedef struct P_3D98E0 {
    u8 pad0[0x10];
    f32 f10;
    s16 f14;
} P_3D98E0;
typedef struct S_3D98E0 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x3];
    u8 *f24;
    u8 pad2[0x4];
    f32 f2C;
    u8 pad3[0x1];
    u8 f31;
    u8 pad4[0x2];
    u16 f34;
    u8 pad5[0xC];
    u8 f42;
    u8 f43;
    u8 pad6[0x1C];
    u8 f60;
    u8 pad7[0x7];
    P_3D98E0 *f68;
    u8 pad8[0x8C];
    f32 fF8;
} S_3D98E0;
extern u8 D_001A4BE0[];
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_3D98E0;
extern G_3D98E0 D_001CCFD0;
extern u8 D_00142CC3[];
extern u8 D_00142D63[];
typedef struct T_3D98E0 { s16 f0; s16 f2; s32 f4; } T_3D98E0;
extern T_3D98E0 D_L19_001DF434_003D73A8;
__asm__(".extern D_L19_001DF434_003D73A8, 16");
extern s32 D_L19_001DF05C_003D73A8;

extern void func_003BD360(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452F60(void *);
extern void func_L19_003D7638(u8 *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039C710(void);
extern void func_L04_003E19F0(void *);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern s32 func_003883C8(void *);
extern void func_00399F90(void);
extern void func_L01_00416A10(s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern s32 func_00399C90(s32, s32);

void func_L19_003D73A8(void *m) {
    S_3D98E0 *s = m;
    P_3D98E0 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CC3[0] != 0) {
            func_003BD360(s);
            return;
        }
        *(u128_t_3D98E0 *)p = *(u128_t_3D98E0 *)((u8 *)s + 0x10);
        p->f10 = s->fF8;
        s->f31 = 0;
        s->f34 = s->f34 | 1;
        func_L01_00441FB8(s, 1, -1);
    }

    switch (s->f20) {
    case 1:
        if (func_L01_00452F60(s)) {
            func_L19_003D7638((u8 *)s);
        }
        break;
    case 2:
        c = (u8 *)&D_001CCFD0;
        if (*(s16 *)(c + 0x76) == 0) {
            if (*(s16 *)(c + 0x9E) == 3 && *(s16 *)(c + 0x98) < 0x1B58) {
                if (func_L01_00452EC8(s)) {
                    func_0039C710();
                }
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        D_L19_001DF434_003D73A8.f4 = 1;
        func_L04_003E19F0(s);
        *(u128_t_3D98E0 *)((u8 *)s + 0x10) = *(u128_t_3D98E0 *)(g + 0x80);
        *(u128_t_3D98E0 *)((u8 *)s + 0xF0) = *(u128_t_3D98E0 *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050BB98(0, 0, 30.0f);
        }
        if (s->f42 == 1 && (s->f60 & 2)) {
            if (s->f43 != 0) {
                func_003BE4F0(s, 0, 0, 0);
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_00441FB8(s, 3, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(s)) {
            func_L01_0044ECE0(0xAF5, 0x78, 0);
        }
        func_003BD360(s);
        break;
    case 3:
        if (func_003883C8((u8 *)p + 0x14) != 0) {
            u8 *h;
            D_00142CC3[0] = 1;
            D_00142D63[0] = 1;
            func_00399F90();
            func_L01_00416A10(0x23);
            h = D_001A4BE0;
            *(s32 *)(h + 0x25F8) = 0x23;
            D_L19_001DF05C_003D73A8 = 0;
            func_L01_004F12C0(h + 0x80, h + 0x90, 0, 0);
            func_L01_003E9730(0, 0);
            func_00399C90(0, -1);
            func_L01_00441FB8(s, 4, -1);
        }
        break;
    }
}
/* localdecomp:end func_L19_003D73A8 */
