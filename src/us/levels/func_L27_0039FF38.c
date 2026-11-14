#include "common.h"

/* NTSC-U counterpart of func_L27_003A17B0 (src/levels/27_aquatos_base/L27_003A1250.c): 250 -> 300 */
#include "vu0.h"
extern u8 *D_L27_001DED1C_0039FF38;
extern struct S_L27_001DEE00 *D_L27_001DEE00_0039FF38;
extern void func_L01_004A6DF8(void *, s32);
extern void func_L27_0039FF38(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L27_0039FF38 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x30]; u16 h44; } S_17B0_Q;
typedef struct { u8 pad[0x10]; vu0_v4 v10; u8 pad20[4]; S_17B0_Q *f24; u8 pad28[0xC]; u16 h34; u16 h36; u8 pad38[0x60]; s32 f98; u8 pad9C[0x54]; vu0_v4 vF0; } S_17B0_E;
typedef struct { u8 p0[4]; s32 f4; u8 p8[0xC]; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; u8 p28[4]; s32 f2C; s32 f30; s32 f34; s32 f38;
    u8 p3C[0x14]; u8 b50; u8 b51; u8 b52; u8 b53; u8 p54[4]; s32 f58; u8 p5C[4]; s32 f60; u8 p64[8]; s32 f6C; u8 p70[4]; s32 f74; u8 p78[8];
    vu0_v4 v80; s32 f90; u8 p94[0x24]; s32 fB8; u8 pBC[0x20]; s32 fDC; } S_17B0_D;
extern u8 *D_L27_001DED1C_0039FF38;
extern struct S_L27_001DEE00 *D_L27_001DEE00_0039FF38;
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00457230(void);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003C2868(void *);

void func_L27_0039FF38(u8 *self) {
    S_17B0_D *d = *(S_17B0_D **)(self + 0x68);
    S_17B0_E *e;
    d->b50 = 0;
    d->b51 = 0;
    d->b52 = 0;
    d->b53 = 0;
    e = (S_17B0_E *)(D_L27_001DED1C_0039FF38 + (d->f90 << 8));
    d->f18 = 0;
    d->f14 = 0x12C;
    d->f20 = -1;
    d->f24 = -1;
    d->f1C = 0;
    d->f74 = 0;
    d->f6C = 0;
    d->fB8 = 0;
    d->fDC = 0;
    *(vu0_q *)&d->v80 = *(vu0_q *)&e->v10;
    e->h36 = 0x7F80;
    e->v10.z += -15.0f;
    func_L01_00441FB8(self, 1, 0);
    if (func_L01_00457230() != 0) {
        d->b51 = 1;
        *(vu0_q *)&((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->v10 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00_0039FF38 + 0x30);
        *(vu0_q *)&((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->vF0 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00_0039FF38 + 0x70);
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 &= 0xFFBE;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 |= ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->f24->h44 & 0x1000;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->f98 = ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->f24->f10;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 &= 0xFFFD;
        ((S_17B0_E *)((d->f58 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 |= 0x41;
        ((S_17B0_E *)((d->f58 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 &= 0xEFFF;
        ((S_17B0_E *)((d->f58 << 8) + (s32)D_L27_001DED1C_0039FF38))->f98 = 0;
        func_L01_004A6DF8(D_L27_001DED1C_0039FF38 + (d->f58 << 8), 1);
    } else {
        d->b51 = 0;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 |= 0x41;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 &= 0xEFFF;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->f98 = 0;
        func_L01_004A6DF8(D_L27_001DED1C_0039FF38 + (d->f4 << 8), 1);
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C_0039FF38))->h34 |= 2;
    }
    if (D_001BBC40[d->f2C + (D_001D545C << 4)] & 0x80) {
        d->b50 = 1;
        func_L01_00441FB8(self, 4, 2);
    }
    if (D_001BBC40[d->f30 + (D_001D545C << 4)] & 0x80) {
        d->b52 = 1;
        func_L01_00441FB8(self, 5, 1);
    }
    if (D_001BBC40[d->f34 + (D_001D545C << 4)] & 0x80) {
        *(vu0_q *)&e->v10 = *(vu0_q *)&d->v80;
        d->f74 = 1;
        func_L01_00441FB8(self, 6, 2);
    }
    if (D_001BBC40[d->f38 + (D_001D545C << 4)] & 0x80) {
        func_L01_00441FB8(self, 7, 1);
    }
    func_003C2868(e);
}
/* localdecomp:end func_L27_0039FF38 */
