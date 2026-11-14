#include "common.h"

/* NTSC-U counterpart of func_L01_0032ADF0 (src/levels/01_veldin/L01_0032ADF0.c): 0.72 -> 0.6; 0.02 -> 0.0166667; 0.00502655 -> 0.00349066; 0.251327 -> 0.20944 */
/* localdecomp:start func_L01_0032A998 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0xF]; u8 b30; u8 p31; s16 h32; u8 p34[0x34]; u8 *p68;
    u8 p6C[0x29]; u8 b95; u16 h96; u8 p98[0x28]; u8 mC0[0x30]; f32 fF0; f32 fF4; f32 fF8; f32 fFC;
} M_32ADF0;
typedef struct { void *w0; s32 w4; M_32ADF0 *child; f32 fC; s32 w10; f32 f14; f32 f18; } P_32ADF0;
typedef struct { s32 n; u8 p4[0xC]; vu0_v4 pts[1]; } B_32ADF0;
typedef struct { u8 p0[0x34]; u16 h34; } Q_32ADF0;
extern u8 D_L01_001DCE60;
__asm__(".extern D_L01_001DCE60, 1");
extern struct { f32 x, y; } D_L01_001E0EF0;
__asm__(".extern D_L01_001E0EF0, 16");
extern f32 D_L01_001E0EF8[1];
extern s32 D_L01_001D6694_0032A998;
extern f32 D_L01_001DF9D0;
extern u8 *D_L01_001EA9D4[];
extern Q_32ADF0 *D_0016C580;
extern B_32ADF0 *D_L01_0021F740[];
extern void func_003BD360(void *);
extern void *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, void *);
extern void func_003A02D8(void *);
extern f32 func_00388A28(f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_003A2DF8(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_0045BF98(s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_003EAB30(void *);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_004A9D88(void);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00445758(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_003887A0(void *);
extern void func_003C26C8(void *);
extern void func_L01_0032AE70(u8 *);
extern s32 func_L01_003EAB60(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_003A0280(void);
extern void func_0039BEC0(s32, s32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
void func_L01_0032A998(M_32ADF0 *m) {
    P_32ADF0 *p = (P_32ADF0 *)m->p68;
    switch (m->b20) {
    case 0:
    case 1: {
        B_32ADF0 *b;
        m->b30 = 0xFF;
        if (D_L01_001DCE60 != 0) {
            func_003BD360(m);
            return;
        }
        D_L01_001DCE60 = 1;
        p->child = func_003BCFB0(0xD54, 0x80);
        func_L01_00452E70(p->child, m);
        func_003A02D8(p->child);
        p->child->h32 = 0x28F;
        b = D_L01_0021F740[p->w4];
        p->child->pos = b->pts[0];
        p->child->fF8 = func_00388A28(b->pts[1].x - m->pos.x, b->pts[1].y - m->pos.y);
        func_00388BD0(p->child->mC0, &p->child->fF0);
        p->w10 = 1;
        func_003A2DF8(D_L01_001EA9D4[0] + 0xF0000);
        func_L01_00441FB8(m, 2, -1);
        break;
    }
    case 2: {
        B_32ADF0 *b;
        f32 a, y, cy;
        vu0_v4 d;
        if (D_L01_001D6694_0032A998 != 0) break;
        if (func_L01_00452EC8(m)) {
            func_L01_0045BF98(0);
            func_0039FE80(0, 0x35, m);
            func_0039FE80(1, 4, m);
            func_L01_003EAB30(p->w0);
            D_L01_001DF9D0 = 1.5f;
        }
        func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
        if (D_0016C580 != 0) D_0016C580->h34 |= 1;
        a = func_00389380(p->child->fF8, 3.1415927f);
        y = p->child->fF4;
        cy = func_00388960(y);
        D_L01_001E0EF0.x = func_00388960(a) * cy * 0.600000024f;
        D_L01_001E0EF0.y = func_00388978(a) * cy * 0.600000024f;
        D_L01_001E0EF8[0] = func_00388978(y) * 0.600000024f;
        p->child->b95 = 0xFF;
        func_L01_00402498(func_L01_004A9D88, p->child);
        b = D_L01_0021F740[p->w4];
        if (func_00388800(&p->child->pos, &b->pts[p->w10]) < 0.75f) p->w10++;
        if (b->n - 1 < p->w10) p->w10 = b->n - 1;
        vec_sub_ba(&d, &b->pts[p->w10], &p->child->pos);
        func_00388830(&d, &d, p->fC * 0.0166666675f);
        vec_add_ba(&p->child->pos, &p->child->pos, &d);
        {
            f32 *r = &p->child->fF8;
            f32 t = func_00388A28(d.x, d.y);
            func_L01_00445758(r, &p->f14, t, 0.00349065871f, 0.00349065871f, 0.209439531f, 0);
        }
        {
            f32 *r = &p->child->fF4;
            f32 t = -func_00388A28(func_003887A0(&d), d.z);
            func_L01_00445758(r, &p->f18, t, 0.00349065871f, 0.00349065871f, 0.209439531f, 0);
        }
        func_003C26C8(p->child);
        func_L01_0032AE70((u8 *)p->child);
        if (++m->h96 >= 0xB && func_L01_003EAB60(p->w0)) {
            func_L01_004A6D70(0, m);
            func_L01_004A6D70(1, m);
            func_003BD360(p->child);
            p->child = 0;
            func_003A0280();
            func_L01_00441FB8(m, 3, -1);
        }
        break;
    }
    case 3:
        func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
        if (D_0016C580 != 0) D_0016C580->h34 &= ~1;
        D_L01_001DF9D0 = 1.5f;
        func_0039BEC0(6, 1, 3, 0, 0);
        func_L01_00441FB8(m, 4, -1);
        break;
    case 4:
        func_003BD360(m);
        break;
    }
    if (p->child != 0) m->pos = p->child->pos;
}
/* localdecomp:end func_L01_0032A998 */
