#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L27_003A1250 */
typedef struct { s32 f0; u8 p4[8]; s32 fC; } S_1250_V;
typedef struct { u8 pad[0x20]; u8 b20; u8 pad21[0x13]; u16 h34; u8 pad36[0x32]; S_1250_V *f68; u8 pad6C[0x2C]; s32 f98; } S_1250_E;
typedef struct { u8 pad[0xD0]; u8 bD0; u8 padD1[0xB]; void *fDC; } S_1250_M;
typedef struct {
    u8 p0[0x10]; s32 f10; u8 p14[0xC]; s32 f20; u8 p24[4]; s32 f28; u8 p2C[0x24]; u8 b50; u8 p51[2]; u8 b53;
    u8 p54[4]; s32 f58; s32 f5C; u8 p60[0xC]; s32 f6C; u8 p70[0x84]; s32 fF4; u8 pF8[0x2C]; s32 f124; u8 p128[8];
    vu0_v4 v130; vu0_v4 v140; s32 f150; s32 f154; s32 f158; s32 f15C; u8 p160[0x80]; s32 f1E0;
} S_1250_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_1250_D *f68; u8 p6C[0x29]; u8 b95; } S_1250_O;
extern u8 *D_L27_001DED1C;
extern struct S_L27_001DEE00 *D_L27_001DEE00;
extern s16 *D_L27_0021B7E0[];
extern u8 D_001A30B0[];
extern struct S_L27_001A4C60 D_001A4C60;
extern s32 D_L27_001D6694;
__asm__(".extern D_L27_001D6694, 4");
extern s32 D_L27_001D6690;
typedef struct { u8 p0[0x30]; s32 f30; } S_1250_L;
extern S_1250_L D_L27_001E59C0;
extern f32 D_L27_001D6720;
extern u8 D_L27_001E8180[];
extern s32 D_00142C68[];
extern u8 D_00142CC1[];
extern u8 D_00142D61[];
extern s16 D_001A7464[];
extern s32 D_001DED58_sda;
__asm__(".extern D_001DED58_sda, 4");
extern s32 D_001DE060_sda;
__asm__(".extern D_001DE060_sda, 4");
extern s32 D_001DE0A0_sda;
__asm__(".extern D_001DE0A0_sda, 4");
extern s32 D_001DE0A4_sda;
__asm__(".extern D_001DE0A4_sda, 4");
extern f32 D_001DE0A8_sda;
__asm__(".extern D_001DE0A8_sda, 4");
extern f32 D_001DE0AC_sda;
__asm__(".extern D_001DE0AC_sda, 4");
extern s32 func_L01_0044C108(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003A4F28(s32);
extern void func_L27_003A17B0(u8 *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_0039EF28(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L27_003A1B30(u8 *);
extern void func_L27_003A2548(u8 *);
extern void func_L27_003A2F58();
extern void func_L27_003A3098();
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_0040C7A0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004DFEA0(s32);
extern s32 func_L27_004D1568(s32, s32);
extern void func_L01_0040C8A0(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L27_003A3310(void *);

void func_L27_003A1250(u8 *self) {
    S_1250_D *d;
    s32 v;
    u8 b;
    if (func_L01_0044C108(self + 0x10) == 0) return;
    d = ((S_1250_O *)self)->f68;
    if (D_L27_001D6694 == 1 || D_L27_001D6694 == 2 || D_L27_001D6690 == 1 || D_L27_001D6690 == 2) {
        if (D_L27_001D6694 == 2 && D_L27_001E59C0.f30 == 1) {
            ((S_1250_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->h34 |= 0x41;
            ((S_1250_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xEFFF;
            ((S_1250_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->f98 = 0;
            func_L01_004AA7E8(D_L27_001DED1C + (d->f58 << 8), 1);
        }
        if (d->f20 != -1) {
            S_1250_M *e = (S_1250_M *)(D_001A30B0 + (d->f20 << 7));
            if (e->fDC == (void *)self && e->bD0 != 0) func_003A4F28(d->f20);
        }
        d->f20 = -1;
        return;
    }
    b = ((S_1250_O *)self)->b95;
    if (b == 0) {
        if (((S_1250_O *)self)->b20 == 0) func_L27_003A17B0(self);
        if (((S_1250_O *)self)->b20 == 1) {
            if (func_00382380(&D_001A4C60, d->f28, 0) != 0) func_L01_004450F0(self, 2, -1);
        }
        if (((S_1250_O *)self)->b20 == 2) {
            if (func_L01_004561B8(self) != 0) {
                if (d->b50 == 0 && func_00392B20(D_L27_001E8180, 0xC6) != 0) {
                    func_00392C78(D_L27_001E8180);
                    D_L27_001D6720 = 2.0f;
                    d->b50 = 1;
                }
            } else {
                func_L01_004450F0(self, 4, 2);
            }
        }
        if (((S_1250_O *)self)->b20 == 3) {
            if (func_L01_004561B8(self) != 0) {
                if ((D_00142C68[0] & 0x200) == 0 && d->b53 == 0 && func_00392B20(D_L27_001E8180, 0xC9) != 0) {
                    func_00392C78(D_L27_001E8180);
                    d->b53 = 1;
                    D_00142CC1[0] = 1;
                    D_00142D61[0] = 1;
                    func_0039EF28();
                }
            } else {
                D_001A7464[0] = 0;
            }
        }
        if (((S_1250_O *)self)->b20 == 3 && d->f5C == 0 && func_L01_004BA800() == 0) {
            d->f5C = 1;
            func_L01_004F50C8((u8 *)D_L27_001DEE00 + (d->f1E0 << 7) + 0x30, (u8 *)D_L27_001DEE00 + (d->f1E0 << 7) + 0x70, 0, 1);
        }
        ((S_1250_E *)((d->fF4 << 8) + (s32)D_L27_001DED1C))->f68->fC = ((S_1250_E *)((d->f124 << 8) + (s32)D_L27_001DED1C))->f68->f0;
    } else if (b == 1) {
        func_L27_003A1B30(self);
    } else if (b == 2) {
        func_L27_003A2548(self);
    }
    func_L27_003A2F58(self);
    func_L27_003A3098(self);
    if (d->f6C == 1) {
        u8 *best = 0;
        f32 bd = 100000000.0f;
        s16 *q = D_L27_0021B7E0[d->f10];
        vu0_v4 dv;
        while ((d->f10 & 0xFF) != 0xFF && d->f10 <= D_001DED58_sda && q != 0 && (q[-1] >= 0 || q == D_L27_0021B7E0[d->f10])) {
            u8 *e = D_L27_001DED1C + ((*(u16 *)q & 0x7FFF) << 8);
            f32 dist;
            if (e == 0) break;
            dist = func_L01_0040E570(e + 0x10, &D_001A4C60);
            if (dist < bd) {
                vec_sub_ba(&dv, &D_001A4C60, e + 0x10);
                if (0.0f < func_0038CE68(&dv, e + 0xE0)) {
                    bd = dist;
                    best = e;
                }
            }
            q++;
        }
        if (best != 0) {
            func_L01_0040C7A0(&d->v130, &D_001DE060_sda);
            func_0038CE20(&d->v130, best + 0xE0, D_001DE0AC_sda);
            vec_add_ba(&d->v130, &d->v130, best + 0x10);
            *(vu0_q *)&d->v140 = *(vu0_q *)&D_001A4C60;
            d->v140.z += D_001DE0A8_sda;
            d->f150 = d->f154 = D_001DE0A0_sda;
            d->f158 = d->f15C = D_001DE0A4_sda;
            func_L01_004DFEA0(*(s32 *)((u8 *)&D_001A4C60 + 0x27D0));
            func_L27_004D1568(0x82, 1);
            d->f6C = 2;
        }
    }
    if (d->f6C == 2) {
        *(vu0_q *)&d->v140 = *(vu0_q *)&D_001A4C60;
        d->v140.z += D_001DE0A8_sda;
        func_L01_0040C8A0(&d->v130, &D_001DE060_sda);
        func_L01_00404808(func_L27_003A3310, self);
    }
}
/* localdecomp:end func_L27_003A1250 */

/* localdecomp:start func_L27_003A17B0 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad14[0x30]; u16 h44; } S_17B0_Q;
typedef struct { u8 pad[0x10]; vu0_v4 v10; u8 pad20[4]; S_17B0_Q *f24; u8 pad28[0xC]; u16 h34; u16 h36; u8 pad38[0x60]; s32 f98; u8 pad9C[0x54]; vu0_v4 vF0; } S_17B0_E;
typedef struct { u8 p0[4]; s32 f4; u8 p8[0xC]; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; u8 p28[4]; s32 f2C; s32 f30; s32 f34; s32 f38;
    u8 p3C[0x14]; u8 b50; u8 b51; u8 b52; u8 b53; u8 p54[4]; s32 f58; u8 p5C[4]; s32 f60; u8 p64[8]; s32 f6C; u8 p70[4]; s32 f74; u8 p78[8];
    vu0_v4 v80; s32 f90; u8 p94[0x24]; s32 fB8; u8 pBC[0x20]; s32 fDC; } S_17B0_D;
extern u8 *D_L27_001DED1C;
extern struct S_L27_001DEE00 *D_L27_001DEE00;
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_0045A520(void);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);

void func_L27_003A17B0(u8 *self) {
    S_17B0_D *d = *(S_17B0_D **)(self + 0x68);
    S_17B0_E *e;
    d->b50 = 0;
    d->b51 = 0;
    d->b52 = 0;
    d->b53 = 0;
    e = (S_17B0_E *)(D_L27_001DED1C + (d->f90 << 8));
    d->f18 = 0;
    d->f14 = 0xFA;
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
    func_L01_004450F0(self, 1, 0);
    if (func_L01_0045A520() != 0) {
        d->b51 = 1;
        *(vu0_q *)&((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->v10 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00 + 0x30);
        *(vu0_q *)&((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->vF0 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00 + 0x70);
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xFFBE;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 |= ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f24->h44 & 0x1000;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f98 = ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f24->f10;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xFFFD;
        ((S_17B0_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->h34 |= 0x41;
        ((S_17B0_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xEFFF;
        ((S_17B0_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->f98 = 0;
        func_L01_004AA7E8(D_L27_001DED1C + (d->f58 << 8), 1);
    } else {
        d->b51 = 0;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 |= 0x41;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xEFFF;
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f98 = 0;
        func_L01_004AA7E8(D_L27_001DED1C + (d->f4 << 8), 1);
        ((S_17B0_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 |= 2;
    }
    if (D_001BBC40[d->f2C + (D_001D545C << 4)] & 0x80) {
        d->b50 = 1;
        func_L01_004450F0(self, 4, 2);
    }
    if (D_001BBC40[d->f30 + (D_001D545C << 4)] & 0x80) {
        d->b52 = 1;
        func_L01_004450F0(self, 5, 1);
    }
    if (D_001BBC40[d->f34 + (D_001D545C << 4)] & 0x80) {
        *(vu0_q *)&e->v10 = *(vu0_q *)&d->v80;
        d->f74 = 1;
        func_L01_004450F0(self, 6, 2);
    }
    if (D_001BBC40[d->f38 + (D_001D545C << 4)] & 0x80) {
        func_L01_004450F0(self, 7, 1);
    }
    func_003C7DD8(e);
}
/* localdecomp:end func_L27_003A17B0 */

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
typedef struct S_L27_001A4C60 { u8 pad[0x2540]; S_3098_M *f2540; } S_3098_G;
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
extern void func_L27_003A3498(u8 *);

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

/* localdecomp:start func_L27_003A3498 */
typedef struct { f32 v[16]; s32 c0; s32 c1; s32 c2; s32 c3; s32 z0; s32 z1; s32 z2; f32 g0; f32 g1; s32 z3; f32 g2; f32 g3; u8 p70[0x20]; } S_3498_S;
typedef struct { vu0_v4 r[4]; } S_3498_M;
typedef struct { u8 p0[0x10]; s32 f10; } S_3498_D;
typedef struct { u8 p0[0x68]; S_3498_D *f68; } S_3498_O;
extern void func_003D93B0(void *, s32, s32, long);
extern void func_0038D570(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern s32 D_L27_001DE8C0;

void func_L27_003A3498(u8 *self) {
    S_3498_D *d = ((S_3498_O *)self)->f68;
    S_3498_S s;
    S_3498_M m;
    vu0_v4 r;
    S_3498_M rm;
    s16 *q;
    func_003D93B0(&s, 0x16, 1, 0x80);
    s.z0 = 0;
    s.z1 = 0;
    s.z2 = 0;
    s.g0 = 1.0f;
    s.g1 = 1.0f;
    s.z3 = 0;
    s.g2 = 1.0f;
    s.c1 = 0x80;
    s.g3 = 1.0f;
    s.c3 = 0x60000080;
    s.c0 = 0x80;
    s.c2 = 0x60000080;
    q = D_L27_0021B7E0[d->f10];
    while ((d->f10 & 0xFF) != 0xFF && d->f10 <= D_001DED58_sda && q != 0 && (q[-1] >= 0 || q == D_L27_0021B7E0[d->f10])) {
        u8 *e = D_L27_001DED1C + ((*(u16 *)q & 0x7FFF) << 8);
        if (e == 0) break;
        func_0038D570(&m, e + 0xC0);
        *(vu0_q *)&m.r[3] = *(vu0_q *)(e + 0x10);
        m.r[3].w = 1.0f;
        qzero(&r);
        r.z = (f32)(D_L27_001DE8C0 % 90) * 6.2831855f / 90.0f + -3.1415927f;
        func_0038D328(&rm, &r);
        func_0038D640(&m, &m, &rm);
        s.v[0] = 0; s.v[1] = 1.5f; s.v[2] = 0.2f; s.v[3] = 1.0f;
        s.v[4] = 1.5f; s.v[5] = 0; s.v[6] = 0.2f; s.v[7] = 1.0f;
        s.v[8] = 0; s.v[9] = 0.1f; s.v[10] = 0.2f; s.v[11] = 1.0f;
        s.v[12] = 0.1f; s.v[13] = 0; s.v[14] = 0.2f; s.v[15] = 1.0f;
        func_003D2DA0(&s, &m, 1);
        s.v[0] = 0; s.v[1] = -1.5f; s.v[2] = 0.2f; s.v[3] = 1.0f;
        s.v[4] = -1.5f; s.v[5] = 0; s.v[6] = 0.2f; s.v[7] = 1.0f;
        s.v[8] = 0; s.v[9] = -0.1f; s.v[10] = 0.2f; s.v[11] = 1.0f;
        s.v[12] = -0.1f; s.v[13] = 0; s.v[14] = 0.2f; s.v[15] = 1.0f;
        func_003D2DA0(&s, &m, 1);
        q++;
    }
}
/* localdecomp:end func_L27_003A3498 */
