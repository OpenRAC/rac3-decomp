#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L27_003A1250);

INCLUDE_ASM("asm/levels", func_L27_003A17B0);

INCLUDE_ASM("asm/levels", func_L27_003A1B30);

INCLUDE_ASM("asm/levels", func_L27_003A2548);

/* localdecomp:start func_L27_003A2B98 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x30]; u16 h44; } S_2B98_Q;
typedef struct { u8 pad[0x10]; vu0_v4 v10; u8 pad20[4]; S_2B98_Q *f24; u8 pad28[0xC]; u16 h34; u8 pad36[0x62]; s32 f98; u8 pad9C[0x54]; vu0_v4 vF0; } S_2B98_E1;
typedef struct { s32 f0; s32 f4; u8 pad8[0x38]; s32 f40; u8 pad44[4]; s32 f48; s32 f4C; } S_2B98_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2B98_D *f68; } S_2B98_O;
typedef struct S_L27_001DEE00 { u8 pad[0x30]; vu0_v4 v30; u8 p40[0x30]; f32 f70; f32 f74; f32 f78; u8 p7C[4]; } S_2B98_E;
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004ED3F8(s32, s32, void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *D_L27_001DED1C;
extern S_2B98_E *D_L27_001DEE00;

void func_L27_003A2B98(S_2B98_O *self) {
    S_2B98_D *d = self->f68;
    vu0_v4 v;
    func_L01_003EB5E0(0, 2);
    func_L01_004ED3F8(1, 0x3F, D_L27_001DED1C + (d->f0 << 8));
    if (self->b20 == 4) {
        func_L01_004F50C8(&D_L27_001DEE00[d->f40].v30, &D_L27_001DEE00[d->f40].f70, -1, 1);
        v.x = func_0038D098(D_L27_001DEE00[d->f40].f78);
        v.y = func_0038D0B0(D_L27_001DEE00[d->f40].f78);
        v.z = 0;
        vec_add_ab(&v, &v, &D_L27_001DEE00[d->f40].v30);
        func_L01_00511A40(&v, 1, D_L27_001DEE00[d->f40].f78);
    } else if (self->b20 == 6) {
        S_2B98_E1 *a;
        S_2B98_E1 *b;
        func_L01_004F50C8(&D_L27_001DEE00[d->f48].v30, &D_L27_001DEE00[d->f48].f70, -1, 0);
        a = (S_2B98_E1 *)(D_L27_001DED1C + (d->f0 << 8));
        b = (S_2B98_E1 *)(D_L27_001DED1C + (d->f4 << 8));
        v.x = -func_0038D098(a->vF0.z);
        v.y = -func_0038D0B0(a->vF0.z);
        v.z = 0;
        v.w = 1.0f;
        vec_add_ba(&b->v10, &a->v10, &v);
        *(vu0_q *)&b->vF0 = *(vu0_q *)&a->vF0;
        b->h34 &= 0xFFBE;
        b->h34 |= b->f24->h44 & 0x1000;
        b->f98 = b->f24->f10;
        b->h34 &= 0xFFFD;
        v.x = func_0038D098(D_L27_001DEE00[d->f48].f78);
        v.y = func_0038D0B0(D_L27_001DEE00[d->f48].f78);
        v.z = 0;
        vec_add_ab(&v, &v, &D_L27_001DEE00[d->f48].v30);
        func_L01_00511A40(&v, 1, D_L27_001DEE00[d->f48].f78);
    }
}
/* localdecomp:end func_L27_003A2B98 */

/* localdecomp:start func_L27_003A2E08 */
typedef struct { u8 pad[0x44]; s32 f44; s32 f48; s32 f4C; } S_2E08_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2E08_D *f68; } S_2E08_O;
typedef struct S_L27_001DEE00 S_2E08_E;
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004ED658(s32);
extern void func_L01_004F5DC8(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00504E38(s32);
extern void func_L01_00511A40(void *, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s16 D_001A7464[];
extern S_2E08_E *D_L27_001DEE00;

void func_L27_003A2E08(S_2E08_O *self) {
    S_2E08_D *d = self->f68;
    vu0_v4 v;
    func_L01_003EB5E0(0, 2);
    D_001A7464[0] = 1;
    func_L01_004ED658(0);
    func_L01_004F5DC8();
    if (self->b20 == 5) {
        func_L01_004F50C8(&D_L27_001DEE00[d->f44].v30, &D_L27_001DEE00[d->f44].f70, -1, 1);
        func_L01_00504E38(0);
    } else if (self->b20 == 7) {
        func_L01_004F50C8(&D_L27_001DEE00[d->f4C].v30, &D_L27_001DEE00[d->f4C].f70, -1, 1);
        v.x = func_0038D098(D_L27_001DEE00[d->f4C].f78);
        v.y = func_0038D0B0(D_L27_001DEE00[d->f4C].f78);
        v.z = 0;
        vec_add_ab(&v, &v, &D_L27_001DEE00[d->f4C].v30);
        func_L01_00511A40(&v, 1, D_L27_001DEE00[d->f4C].f78);
    }
}
/* localdecomp:end func_L27_003A2E08 */

/* localdecomp:start func_L27_003A2F58 */
typedef struct { u8 p0[0x4A0]; s32 f4A0; } S_2F58_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2F58_D *f68; } S_2F58_E;
typedef struct { u8 p0[0x98]; s32 f98; s32 f9C; u8 pA0[0x24]; s32 fC4; s32 fC8; s32 fCC; s32 fD0; } S_2F58_P;
typedef struct { u8 p0[0x68]; S_2F58_P *f68; u8 p6C[0x29]; u8 b95; } S_2F58_O;
extern u8 *D_001DED1C_sda;
__asm__(".extern D_001DED1C_sda, 4");
extern u8 *D_L27_001DED1C_003A2F58;
__asm__(".extern D_L27_001DED1C_003A2F58, 16");
extern void func_L27_0039F718(void *, void *);

void func_L27_003A2F58(S_2F58_O *arg0) {
    S_2F58_P *p;
    s32 i;
    s32 j;
    p = arg0->f68;
    if (arg0->b95 == 0) return;
    i = p->fC4;
    if (i == -1 || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_L27_001DED1C_003A2F58 + (i << 8), D_L27_001DED1C_003A2F58 + (p->fC8 << 8));
    }
    i = p->fCC;
    if (i == -1 || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_L27_001DED1C_003A2F58 + (i << 8), D_L27_001DED1C_003A2F58 + (p->fD0 << 8));
    }
    j = p->f98;
    if (j == -1 || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_001DED1C_sda + (j << 8), D_001DED1C_sda + (p->f9C << 8));
    }
}
/* localdecomp:end func_L27_003A2F58 */

/* localdecomp:start func_L27_003A3098 */
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; u8 p24[0x48]; s32 f6C; } S_3098_D;
typedef struct { u8 p0[0x68]; S_3098_D *f68; u8 p6C[0x29]; u8 b95; } S_3098_O;
typedef struct { u8 pad[0xAA]; s16 hAA; } S_3098_M;
typedef struct { u8 pad[0x2540]; S_3098_M *f2540; } S_3098_G;
typedef struct { u8 pad[0xD0]; u8 bD0; u8 padD1[0xB]; void *fDC; } S_3098_E;
typedef struct { u8 pad[0x34]; u16 h34; u8 pad36[0x42]; u32 f78; } S_3098_T;
extern S_3098_G D_001A4C60;
extern u8 D_001A30B0[];
extern u8 *D_L27_001DED1C;
__asm__(".extern D_L27_001DED1C, 16");
extern s16 *D_L27_0021B7E0[];
extern s32 D_001DED58_sda;
__asm__(".extern D_001DED58_sda, 4");
extern s32 func_L01_00456500(void *, s32);
extern void func_0038CAD0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_003A4F28(s32);
extern s32 func_L01_004AADE8(s32, s32, void *, s32);
extern void func_L27_003A3498(void);

void func_L27_003A3098(S_3098_O *self) {
    S_3098_D *d = self->f68;
    s16 *q;
    u32 c;
    s32 flag;
    if (d->f6C != 0) {
        d->f18 = 1;
    } else if (self->b95 == 2) {
        d->f18 = 0;
    } else {
        s32 v = 0;
        if (func_L01_00456500(&D_001A4C60, d->f8) == 0) {
            v = D_001A4C60.f2540->hAA != 0x1A4E;
        }
        d->f18 = v;
    }
    if (d->f18 != 0 && d->f6C == 0) {
        func_0038CAD0(&d->f14);
        if (d->f14 <= 0) {
            d->f6C = 1;
        } else if (d->f14 >= 0xE2) {
            return;
        }
    } else {
        d->f14 = 0xFA;
    }
    if (d->f18 != 0) {
        flag = d->f1C == 0;
        c = 0x7F2020FF;
        func_L01_00404808(func_L27_003A3498, self);
    } else {
        flag = d->f1C;
        c = 0x7F000040;
    }
    if (flag == 0) return;
    d->f1C = d->f18;
    if (d->f18 != 0) {
        if (d->f20 != -1) {
            S_3098_E *e = (S_3098_E *)(D_001A30B0 + (d->f20 << 7));
            if (e->fDC == (void *)self && e->bD0 != 0) func_003A4F28(d->f20);
        }
        d->f20 = -1;
        d->f20 = func_L01_004AADE8(0x10, 4, self, 0);
    } else {
        if (d->f20 != -1) {
            S_3098_E *e = (S_3098_E *)(D_001A30B0 + (d->f20 << 7));
            if (e->fDC == (void *)self && e->bD0 != 0) func_003A4F28(d->f20);
        }
        d->f20 = -1;
    }
    q = D_L27_0021B7E0[d->f10];
    while ((d->f10 & 0xFF) != 0xFF && d->f10 <= D_001DED58_sda && q != 0 && (q[-1] >= 0 || q == D_L27_0021B7E0[d->f10])) {
        S_3098_T *t = (S_3098_T *)(D_L27_001DED1C + ((*(u16 *)q & 0x7FFF) << 8));
        if (t == 0) break;
        t->h34 |= 0x10;
        t->f78 = c;
        q++;
    }
}
/* localdecomp:end func_L27_003A3098 */

/* localdecomp:start func_L27_003A3310 */
typedef struct { u8 p0[0x150]; s32 f150; s32 f154; s32 f158; } S_3310;
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 D_001DE060_sda;
__asm__(".extern D_001DE060_sda, 4");
extern f32 D_001DE0B0_sda;
__asm__(".extern D_001DE0B0_sda, 4");
extern f32 D_001DE0B4_sda;
__asm__(".extern D_001DE0B4_sda, 4");

void func_L27_003A3310(void *arg0) {
    S_3310 *p;
    s32 c;
    s32 c2;
    f32 f; f32 f2;
    u8 *b;
    p = *(void **)((u8 *)arg0 + 0x68);
    func_L01_0040C948((u8 *)p + 0x130, &D_001DE060_sda);
    c = func_0038DBD8(p->f150, p->f158, func_003824E0(0.0f, 1.0f)) | 0x60000000;
    f = D_001DE0B0_sda * func_003824E0(0.75f, 1.25f);
    func_003D9508((u8 *)p + 0x130, 0x31, c, 1, f, D_001DE0B4_sda, func_003824E0(-3.1415927f, 3.1415927f));
    b = (u8 *)p + 0x140;
    c2 = func_0038DBD8(p->f150, p->f158, func_003824E0(0.0f, 1.0f)) | 0x60000000;
    f2 = D_001DE0B0_sda * func_003824E0(0.75f, 1.25f);
    func_003D9508(b, 0x31, c2, 1, f2, D_001DE0B4_sda, func_003824E0(-3.1415927f, 3.1415927f));
}
/* localdecomp:end func_L27_003A3310 */

INCLUDE_ASM("asm/levels", func_L27_003A3498);
