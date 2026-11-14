#include "common.h"

/* NTSC-U counterpart of func_L27_003A2548 (src/levels/27_aquatos_base/L27_003A1250.c) */
#include "vu0.h"
extern u8 *D_L27_001DED1C_003A0CD0;
extern struct S_L27_001DEE00 *D_L27_001DEE00_003A0CD0;
extern struct S_L27_001A4C60 D_001A4C60;
extern u8 D_L27_001E8180_003A0CD0[];
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern void func_L27_003A0CD0(u8 *);
extern u8 *D_L27_001DED1C_003A0CD0;
extern struct S_L27_001DEE00 *D_L27_001DEE00_003A0CD0;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

/* localdecomp:start func_L27_003A0CD0 */
typedef struct { s32 f0; u8 p4[8]; s32 fC; u8 p10[0x88]; s32 f98; } S_2548_V;
typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x30]; u16 h44; } S_2548_Q;
typedef struct { u8 pad[0x10]; vu0_v4 v10; u8 b20; u8 pad21[3]; S_2548_Q *f24; u8 pad28[0xC]; u16 h34; u8 pad36[0x32]; S_2548_V *f68; u8 pad6C[0x2C]; s32 f98; u8 pad9C[0x54]; vu0_v4 vF0; } S_2548_E;
typedef struct { u8 p0[4]; f32 f4; } S_2548_F;
typedef struct {
    u8 p0[4]; s32 f4; u8 p8[0x28]; s32 f30; u8 p34[4]; s32 f38; u8 p3C[0x15]; u8 b51; u8 b52; u8 p53;
    s32 f54; s32 f58; u8 p5C[4]; s32 f60; s32 f64; u8 p68[0xC]; s32 f74; s32 f78; u8 p7C[0x28];
    s32 fA4; s32 fA8; s32 fAC; s32 fB0; s32 fB4; S_2548_F *fB8; s32 fBC; s32 fC0; u8 pC4[0x14]; s32 fD8; s32 fDC;
    u8 pE0[0xC]; s32 fEC; s32 fF0; u8 pF4[0xC]; s32 f100; s32 f104; s32 f108; s32 f10C; s32 f110; s32 f114; u8 p118[0x14]; s32 f12C;
} S_2548_D;
typedef struct { u8 p0[0x29C]; s32 f29C; u8 p2A0[0xA4]; s32 f344; u8 p348[8]; u32 f350; u8 p354[8]; s32 f35C; u8 p360[0x944]; s32 fCA4; } S_2548_G;
extern u8 *D_L27_001DED1C_003A0CD0;
extern struct S_L27_001DEE00 *D_L27_001DEE00_003A0CD0;
extern struct S_L27_001A4C60 D_001A4C60;
extern S_2548_G D_001A7E18;
extern s32 D_001A663C[];
extern u8 D_L27_001E8180_003A0CD0[];
extern f32 D_L27_001DE6D0_003A0CD0;
extern s32 func_L01_00452EF0(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00417F60(s32, s32);
extern S_2548_F *func_L01_003F08D8(s32, s32);
extern void func_L01_003F0980(s32, void *);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00438430(s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L23_003D6580(s32, s32, f32);
extern void func_L01_003F32F0(s32, f32);
extern void func_L27_003A1320();

void func_L27_003A0CD0(u8 *self) {
    S_2548_D *d = *(S_2548_D **)(self + 0x68);
    S_2548_F *f;
    if (func_L01_00452EF0(self) != 0) {
        func_L27_003A1320(self);
        d->fDC = 0;
    }
    ((S_2548_E *)((d->fEC << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->fC = ((S_2548_E *)((d->f104 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 != 0 || ((S_2548_E *)((d->f108 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 != 0;
    ((S_2548_E *)((d->fF0 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->fC = ((S_2548_E *)((d->f110 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 != 0 || ((S_2548_E *)((d->f114 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 != 0;
    ((S_2548_E *)((d->fA8 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f98 = ((S_2548_E *)((d->f12C << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0;
    if (d->f54 >= 0 && func_0037E0F0(&D_001A4C60, d->f54, 0) != 0) {
        if (D_001A7E18.fCA4 >= 0) func_L01_00417F60(0x140B, 0x10D);
        d->f54 = -1;
    }
    if (d->fB8 == 0 && func_0037E0F0(&D_001A4C60, d->fBC, 0) != 0) {
        f = func_L01_003F08D8(0, 5);
        d->fB8 = f;
        if (f != 0) f->f4 = 3.0f;
    } else if (d->fB8 != 0 && func_0037E0F0(&D_001A4C60, d->fBC, 0) == 0) {
        func_L01_003F0980(0, d->fB8);
        d->fB8 = 0;
    }
    if (((S_2548_E *)((d->fA4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 == 0) {
        if (func_0037E0F0(&D_001A4C60, d->fAC, 0) != 0) {
            *(f32 *)((u8 *)&D_001A4C60 + 0x19DC) = 0.43633232f;
            if (d->b51 == 0 && func_0038E2E8(D_L27_001E8180_003A0CD0, 0xC7) != 0) {
                func_0038E440(D_L27_001E8180_003A0CD0);
                d->b51 = 1;
            } else if (d->b51 != 0) {
                if (d->f60 >= 0) {
                    *(vu0_q *)&((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->v10 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00_003A0CD0 + 0x30);
                    *(vu0_q *)&((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->vF0 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00_003A0CD0 + 0x70);
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->h34 &= 0xFFBE;
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->h34 |= ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f24->h44 & 0x1000;
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f98 = ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f24->f10;
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->h34 &= 0xFFFD;
                    ((S_2548_E *)((d->f58 << 8) + (s32)D_L27_001DED1C_003A0CD0))->h34 |= 0x41;
                    ((S_2548_E *)((d->f58 << 8) + (s32)D_L27_001DED1C_003A0CD0))->h34 &= 0xEFFF;
                    ((S_2548_E *)((d->f58 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f98 = 0;
                    func_L01_004A6DF8(D_L27_001DED1C_003A0CD0 + (d->f58 << 8), 1);
                    d->f60 = -1;
                }
                if ((D_001A7E18.f344 & 0x80000000) == 0) func_L01_00417F60(0xBA2, 0x45);
                if (++d->fDC >= 0x709 && (D_001A7E18.f350 & 0x80000000) == 0) func_L01_00417F60(0xBA3, 0x46);
            }
        }
        if (((S_2548_E *)((d->f10C << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 != 0) {
            ((S_2548_E *)((d->fA4 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->f0 = 1;
            D_001A663C[0] = 0;
            d->fDC = 0;
        }
    }
    if (d->fB0 >= 0 && func_0037E0F0(&D_001A4C60, d->fB0, 0) != 0) {
        if (++d->fDC >= 0x12D) {
            if (D_001A7E18.f35C >= 0) func_L01_00417F60(0xBA4, 0x47);
            d->fDC = 0;
            d->fB0 = -1;
        }
    }
    if (d->fB4 >= 0 && func_0037E0F0(&D_001A4C60, d->fB4, 0) != 0 && d->fC0 != -1
        && ((S_2548_E *)((d->fC0 << 8) + (s32)D_L27_001DED1C_003A0CD0))->b20 != 0xFE && ((S_2548_E *)((d->fC0 << 8) + (s32)D_L27_001DED1C_003A0CD0))->b20 != 0xFD) {
        if (++d->fDC >= 0x259) {
            if (D_001A7E18.f29C >= 0) func_L01_00417F60(0xB94, 0x37);
            d->fB4 = -1;
            d->fDC = 0;
        }
    }
    ((S_2548_E *)((d->f100 << 8) + (s32)D_L27_001DED1C_003A0CD0))->f68->fC = func_L01_00452F60(D_L27_001DED1C_003A0CD0 + (d->fD8 << 8));
    if (d->f74 == 0 && func_0037E0F0(&D_001A4C60, d->f78, 0) != 0) {
        if (d->b52 == 0 && func_0038E2E8(D_L27_001E8180_003A0CD0, 0xC8) != 0) {
            func_0038E440(D_L27_001E8180_003A0CD0);
            d->b52 = 1;
        } else if (d->b52 != 0) {
            func_L01_00438430(d->f30);
            func_L01_00441FB8(self, 5, 1);
        }
    }
    if (func_0037E0F0(&D_001A4C60, d->f64, 0) != 0) {
        func_L23_003D6580(0, 1, 30.0f);
        if (1.0f <= D_L27_001DE6D0_003A0CD0) {
            func_L01_003F32F0(0, 30.0f);
            func_L01_00438430(d->f38);
            func_L01_00441FB8(self, 7, 1);
        }
    }
}
/* localdecomp:end func_L27_003A0CD0 */
