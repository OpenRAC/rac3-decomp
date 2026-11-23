#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L19_00333160 (src/levels/shared/L19_00331380.c): f16C = 1/180 (60 Hz) in place of 0.008 */
/* localdecomp:start func_L19_00332788 */
extern void func_L01_00441FB8(u8 *, s32, s32);

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[2];
    u8 b38;
    u8 pad39[0x140 - 0x39];
    f32 f140;
    f32 f144;
    f32 f148;
    f32 f14C;
    f32 f150;
    u8 pad154[0x16C - 0x154];
    f32 f16C;
    f32 f170;
    f32 f174;
    u8 pad178[0x188 - 0x178];
    u8 *p188;
    u8 *p18C;
    u8 pad190[0x230 - 0x190];
    u8 a230[0x80];
    u8 a2B0[0xA0];
    s32 w350;
    u8 pad354[4];
    s32 w358[14];
    u8 pad390[0x10];
    s32 w3A0;
    f32 f3A4;
    s32 w3A8;
    u8 pad3AC[4];
    s32 w3B0;
    s32 w3B4;
    u8 pad3B8[4];
    f32 f3BC;
    vu0_v4 v3C0;
    vu0_v4 v3D0;
} S_00332788;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[0xC];
    u16 h34;
    u8 pad36[0xD];
    u8 b43;
    u8 pad44[0x24];
    S_00332788 *s;
    u8 pad6C[0x12];
    u8 b7E;
    u8 pad7F[0x2B];
    s16 hAA;
    u8 padAC[0x14];
    vu0_v4 vC0;
} A_00332788;

extern s32 D_L19_001DCC20 __attribute__((section(".sdata")));
extern s32 D_L19_001DCC14 __attribute__((section(".sdata")));
extern s32 D_L19_001DCC10 __attribute__((section(".sdata")));
__asm__(".extern D_L19_001DCC20, 4");
__asm__(".extern D_L19_001DCC14, 4");
__asm__(".extern D_L19_001DCC10, 4");
extern s32 func_0037E1D8(s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L19_00332A90(u8 *);
extern void func_00388830(void *, void *, f32);
extern void func_003BE4F0(u8 *, s32, s32, s32);

void func_L19_00332788(u8 *arg0) {
    A_00332788 *a = (A_00332788 *)arg0;
    S_00332788 *s = a->s;
    vu0_v4 v;
    f32 y;

    if (func_0037E1D8(2)) {
        a->h34 |= 0x8000;
    } else {
        a->h34 &= 0x7FFF;
    }
    a->b7E |= 1;
    D_L19_001DCC20 = 0;
    D_L19_001DCC14 = 0;
    a->pos.z = func_003BE7F0(&a->pos, 0, 0, 0.5f);
    if (s->w350 == 0) {
        func_L19_00332A90(arg0);
    }
    s->f30 = 1.0f;
    s->h34 = 1;
    s->b38 = 3;
    s->f174 = 0.5f;
    s->f140 = 0.1f;
    s->f144 = 0.1f;
    s->f148 = 0.5f;
    s->f14C = 0.5f;
    s->f150 = 1.5882496f;
    s->f170 = 0.5235988f;
    s->p188 = s->a230;
    s->p18C = s->a2B0;
    s->f16C = 0.0055555557f;
    switch (a->hAA) {
    case 0x93C:
        s->f140 = 0.42f;
        a->pos.z += 0.089f;
        break;
    case 0x940:
        s->f140 = 0.39f;
        a->pos.z += 0.089f;
        func_00388830(&v, &a->vC0, -0.2f);
        vec_add_ba(&a->pos, &v, &a->pos);
        break;
    case 0xA59:
        s->f140 = 0.42f;
        a->pos.z += 0.089f;
        break;
    default:
        s->f140 = 0.1f;
        a->pos.z += 0.089f;
        break;
    }
    s->w358[0] = 0;
    s->w358[1] = 0;
    s->w358[2] = 0;
    s->w358[3] = 0;
    s->w358[4] = 0;
    s->w358[5] = 0;
    s->w358[6] = 0;
    s->w358[7] = 0;
    s->w358[8] = 0;
    s->w358[9] = 0;
    s->w358[10] = 0;
    s->w358[11] = 0;
    s->w358[12] = 0;
    s->w358[13] = 0;
    s->w3A0 = 0;
    y = a->pos.z;
    s->f3A4 = y;
    s->w3A8 = -1;
    s->w3B0 = D_L19_001DCC10++;
    s->w3B4 = 0;
    if (s->f3BC <= -999.0f) {
        s->f3BC = y - 10.0f;
    }
    qzero(&s->v3C0);
    qzero(&s->v3D0);
    func_L01_00441FB8(arg0, 1, 0);
    if (a->hAA == 0xA59) {
        if (a->b43 != 6) {
            func_003BE4F0(arg0, 6, 0, 0);
        }
    } else if (a->b43 != 0) {
        func_003BE4F0(arg0, 0, func_0037E1D8(*(u8 *)(*(u8 **)(a->p24 + 0x48) + 0x10)), 0);
    }
}
/* localdecomp:end func_L19_00332788 */
