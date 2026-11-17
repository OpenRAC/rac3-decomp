#include "common.h"

/* localdecomp:start func_L01_0032ADF0 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0xF]; u8 b30; u8 p31; s16 h32; u8 p34[0x34]; u8 *p68;
    u8 p6C[0x29]; u8 b95; u16 h96; u8 p98[0x28]; u8 mC0[0x30]; f32 fF0; f32 fF4; f32 fF8; f32 fFC;
} M_32ADF0;
typedef struct { void *w0; s32 w4; M_32ADF0 *child; f32 fC; s32 w10; f32 f14; f32 f18; } P_32ADF0;
typedef struct { s32 n; u8 p4[0xC]; vu0_v4 pts[1]; } B_32ADF0;
typedef struct { u8 p0[0x34]; u16 h34; } Q_32ADF0;
extern u8 D_L01_001DCE20;
__asm__(".extern D_L01_001DCE20, 1");
extern struct { f32 x, y; } D_L01_001E0E70;
__asm__(".extern D_L01_001E0E70, 16");
extern f32 D_L01_001E0E78[1];
extern s32 D_L01_001D6694;
extern f32 D_L01_001DF950;
extern u8 *D_L01_001EA954[];
extern Q_32ADF0 *D_0016C580;
extern B_32ADF0 *D_L01_0021F6C0[];
extern void func_003C2880(void *);
extern void *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_003A56F8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_003A8220(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045F328(s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003EC9E0(void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_004AD7A8(void);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_0038CED8(void *);
extern void func_003C7C38(void *);
extern void func_L01_0032B2C8(u8 *);
extern s32 func_L01_003ECA10(void *);
extern void func_L01_004AA760(s32, void *);
extern void func_003A56A0(void);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L01_0032ADF0(M_32ADF0 *m) {
    P_32ADF0 *p = (P_32ADF0 *)m->p68;
    switch (m->b20) {
    case 0:
    case 1: {
        B_32ADF0 *b;
        m->b30 = 0xFF;
        if (D_L01_001DCE20 != 0) {
            func_003C2880(m);
            return;
        }
        D_L01_001DCE20 = 1;
        p->child = func_003C24B0(0xD54, 0x80);
        func_L01_00456160(p->child, m);
        func_003A56F8(p->child);
        p->child->h32 = 0x28F;
        b = D_L01_0021F6C0[p->w4];
        p->child->pos = b->pts[0];
        p->child->fF8 = func_0038D160(b->pts[1].x - m->pos.x, b->pts[1].y - m->pos.y);
        func_0038D308(p->child->mC0, &p->child->fF0);
        p->w10 = 1;
        func_003A8220(D_L01_001EA954[0] + 0xF0000);
        func_L01_004450F0(m, 2, -1);
        break;
    }
    case 2: {
        B_32ADF0 *b;
        f32 a, y, cy;
        vu0_v4 d;
        if (D_L01_001D6694 != 0) break;
        if (func_L01_004561B8(m)) {
            func_L01_0045F328(0);
            func_003A52A0(0, 0x35, m);
            func_003A52A0(1, 4, m);
            func_L01_003EC9E0(p->w0);
            D_L01_001DF950 = 1.5f;
        }
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        if (D_0016C580 != 0) D_0016C580->h34 |= 1;
        a = func_0038DAB8(p->child->fF8, 3.1415927f);
        y = p->child->fF4;
        cy = func_0038D098(y);
        D_L01_001E0E70.x = func_0038D098(a) * cy * 0.72f;
        D_L01_001E0E70.y = func_0038D0B0(a) * cy * 0.72f;
        D_L01_001E0E78[0] = func_0038D0B0(y) * 0.72f;
        p->child->b95 = 0xFF;
        func_L01_00404808(func_L01_004AD7A8, p->child);
        b = D_L01_0021F6C0[p->w4];
        if (func_0038CF38(&p->child->pos, &b->pts[p->w10]) < 0.75f) p->w10++;
        if (b->n - 1 < p->w10) p->w10 = b->n - 1;
        vec_sub_ba(&d, &b->pts[p->w10], &p->child->pos);
        func_0038CF68(&d, &d, p->fC * 0.020000001f);
        vec_add_ba(&p->child->pos, &p->child->pos, &d);
        {
            f32 *r = &p->child->fF8;
            f32 t = func_0038D160(d.x, d.y);
            func_L01_00448890(r, &p->f14, t, 0.0050265486f, 0.0050265486f, 0.25132743f, 0);
        }
        {
            f32 *r = &p->child->fF4;
            f32 t = -func_0038D160(func_0038CED8(&d), d.z);
            func_L01_00448890(r, &p->f18, t, 0.0050265486f, 0.0050265486f, 0.25132743f, 0);
        }
        func_003C7C38(p->child);
        func_L01_0032B2C8((u8 *)p->child);
        if (++m->h96 >= 0xB && func_L01_003ECA10(p->w0)) {
            func_L01_004AA760(0, m);
            func_L01_004AA760(1, m);
            func_003C2880(p->child);
            p->child = 0;
            func_003A56A0();
            func_L01_004450F0(m, 3, -1);
        }
        break;
    }
    case 3:
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        if (D_0016C580 != 0) D_0016C580->h34 &= ~1;
        D_L01_001DF950 = 1.5f;
        func_003A0EC0(6, 1, 3, 0, 0);
        func_L01_004450F0(m, 4, -1);
        break;
    case 4:
        func_003C2880(m);
        break;
    }
    if (p->child != 0) m->pos = p->child->pos;
}
/* localdecomp:end func_L01_0032ADF0 */

/* localdecomp:start func_L01_0032B2C8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; u8 q10[16]; u8 pad20[4]; u8 *p24; u8 pad28[0xc]; u16 h34; u8 pad36[0x62]; s32 f98; u8 pad9c[0x24]; f32 m[12]; } S_A;
extern S_A *D_L01_0023AC70[];
extern void func_003C2EC0(void *, s32, f32 *);
extern void func_003C48A8(void *, void *);
extern void func_003C7DD8(void *);
void func_L01_0032B2C8(u8 *a0) {
    f32 v[16];
    s32 i = 0;
    s32 j;
    f32 *q;
    if (D_L01_0023AC70[0] != 0) {
        do {
            D_L01_0023AC70[i]->h34 &= 0xffbe;
            D_L01_0023AC70[i]->h34 |= *(u16 *)(D_L01_0023AC70[i]->p24 + 0x44) & 0x1000;
            D_L01_0023AC70[i]->f98 = *(s32 *)(D_L01_0023AC70[i]->p24 + 0x10);
            *(u128_t *)D_L01_0023AC70[i]->q10 = *(u128_t *)(a0 + 0x10);
            func_003C2EC0(a0, 0, v);
            for (j = 0, q = v; j < 3; j++) {
                *(f32 *)((u8 *)D_L01_0023AC70[i] + (j << 4) + 0xc0) = q[0];
                *(f32 *)((u8 *)D_L01_0023AC70[i] + (j << 4) + 0xc4) = q[1];
                *(f32 *)((u8 *)D_L01_0023AC70[i] + (j << 4) + 0xc8) = q[2];
                q += 4;
            }
            func_003C48A8(&D_L01_0023AC70[i]->m[0], &D_L01_0023AC70[i]->m[12]);
            func_003C7DD8(D_L01_0023AC70[i]);
            D_L01_0023AC70[i]->f98 = 0;
            i++;
        } while (D_L01_0023AC70[i] != 0);
    }
}
/* localdecomp:end func_L01_0032B2C8 */
