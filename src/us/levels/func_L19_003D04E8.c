#include "common.h"

/* NTSC-U counterpart of func_L19_003D2788 (src/levels/19_thran_asteroid_belt/L19_003D26C0.c) */
#include "vu0.h"

/* localdecomp:start func_L19_003D04E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2788;
typedef struct { V4_3D2788 dir; s32 x10; s32 x14; s32 x18; f32 x1C; void *x20; s32 x24; } D_3D2788;
typedef struct {
    u8 pad0[0x10]; V4_3D2788 pos; u8 x20; u8 pad21[0xF]; u8 x30; u8 pad31; s16 x32; u8 pad34[0x34];
    D_3D2788 *x68; u8 pad6C[0x54]; V4_3D2788 xC0; V4_3D2788 xD0; V4_3D2788 xE0;
} M_3D2788;
__asm__(".extern D_L19_001DEB90, 4");
__asm__(".extern D_L19_001DEB94, 4");
__asm__(".extern D_L19_001DEB98, 4");
__asm__(".extern D_L19_001DEB9C, 4");
__asm__(".extern D_L19_001DEBA0_003D04E8, 4");
__asm__(".extern D_L19_001DEBC0_003D04E8, 4");
__asm__(".extern D_L19_001DEBE0_003D04E8, 4");
__asm__(".extern D_L19_001DEC00_003D04E8, 4");
extern f32 D_L19_001DEB90;
extern f32 D_L19_001DEB94;
extern f32 D_L19_001DEB98;
extern f32 D_L19_001DEB9C;
extern s32 D_L19_001DEBA0_003D04E8;
extern s32 D_L19_001DEBA0_2[] __attribute__((section(".sdata")));
extern f32 D_L19_001DEBC0_003D04E8;
extern f32 D_L19_001DEBE0_003D04E8;
extern s32 D_L19_001DEC00_003D04E8;
extern u8 D_L19_001D66F0_003D04E8[8];
extern void func_003BFC18(void *, void *, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_004708F8(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern u8 *func_L01_00467DA8(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_0046D570(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 a3, s32 spin,
                             void *velocity, s32 t2, s32 t3, s16 arg8, s32 arg9);

M_3D2788 *func_L19_003D04E8(void *owner, u8 *pos, V4_3D2788 *dir, f32 f, s32 a3) {
    V4_3D2788 m;
    V4_3D2788 v;
    V4_3D2788 r;
    M_3D2788 *p;
    D_3D2788 *d;
    s32 i;

    func_003BFC18(pos, &m, 1);
    p = (M_3D2788 *)func_003BCFB0(0x1DE0, 0x30);
    if (p != 0) {
        d = p->x68;
        d->x10 = 0x190;
        p->x30 = 0xFF;
        p->x32 = 0xFF;
        p->x20 = 0;
        p->pos = *(V4_3D2788 *)pos;
        d->dir = *dir;
        d->x1C = f;
        d->x18 = 0;
        d->x14 = 0;
        func_00388830(&v, dir, 1.0f);
        p->xC0 = v;
        func_00388758(&p->xD0, &p->xC0, &m);
        func_00388830(&p->xD0, &p->xD0, 1.0f);
        func_00388758(&p->xE0, &p->xD0, &p->xC0);
        p->xC0.w = p->xD0.w = p->xE0.w = 0.0f;
        d->x20 = owner;
        d->x24 = a3;
        for (i = 0; i < 10; i++) {
            func_0037E2F0(&r, 0.0833333358168602f, 0.1666666716337204f);
            func_L01_004708F8(pos, &r, func_0037E208(10, 0x19), D_L19_001DEB90, D_L19_001DEB94,
                              D_L19_001DEB98, D_L19_001DEB9C, D_L19_001DEBA0_003D04E8, D_L19_001DEBA0_2[1], 0, 0);
        }
        for (i = 0; i < 4; i++)
            func_L01_00467DA8(pos, 0xE, (&D_L19_001DEBC0_003D04E8)[i], (&D_L19_001DEBE0_003D04E8)[i], (&D_L19_001DEBA0_003D04E8)[i],
                              2, 1, D_L19_001D66F0_003D04E8, 0.0f, 1);
        for (; i < 7; i++)
            func_L01_0046D570(pos, 0x14, (&D_L19_001DEBC0_003D04E8)[i], (&D_L19_001DEBE0_003D04E8)[i], (&D_L19_001DEBA0_003D04E8)[i], 2, 2,
                              D_L19_001D66F0_003D04E8, 0, (&D_L19_001DEC00_003D04E8)[i - 4], 6, 1);
    }
    return p;
}
/* localdecomp:end func_L19_003D04E8 */
