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

/* localdecomp:start func_L27_003A1B30 */
/* match (level 27, Aquatos Base), 0 diff with the divs_nops row func_L27_003A1B30 2.
   Notes: the file's own context already declares func_L27_003A1B30(u8 *) and func_00382380 /
   func_0038CE20 / func_L27_004D1568, so their declarations are not repeated here.
   - D_001A818C, not D_001B818C: retail's %hi/%lo pair points at 0x001A818C.
   - the trailing func_00382380 call passes d->f68 (0x68 of the S_D), not d.
   - each `i = d->fXX` is a block-scoped local: one shared variable stays in $a1 across
     blocks, while retail uses $v1/$a0/$a1 per block.
   - the o0->pos / o0->vF0 copies are u128_t casts, not struct/vu0_v4 assignments: the
     integer store makes gcc reload d->f78 and D_L27_001DEE00 after it, as retail does.
   - d->f70 = 0 comes before the o0/o4 address computations; that order is what makes the
     first DEE load precede the moby base load.
   - the action if body is the whole middle (stops cse of 1.0f); D_001A4BE0 is the Hero union
     (ptr[0x970] / i[0x971]); vec_sub_ba / vec_add_ab for the vector block; d->f70 += 1.0f
     through a temporary and a.z + -15.0f (not -=). */

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1B30;
typedef union {
    u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80];
    f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0];
} Hero_3A1B30;
typedef struct { u8 p00[0xAA]; s16 hAA; } S_HOBJ_3A1B30;
typedef struct { s32 f0; u8 p04[8]; s32 fC; u8 p10[0x490]; s32 f4A0; } S_M68_3A1B30;
typedef struct {
    u8 p00[0x10];
    V4_3A1B30 pos;
    u8 b20;
    u8 p21[0x47];
    S_M68_3A1B30 *f68;
    u8 p6C[0x84];
    V4_3A1B30 vF0;
} S_MOB_3A1B30;
typedef struct {
    s32 f0, f4, f8; u8 p0C[0x18]; s32 f24; u8 p28[0xC]; s32 f34; u8 p38[4]; s32 f3C;
    u8 p40[0x28]; s32 f68; s32 f6C; f32 f70; s32 f74; s32 f78; s32 f7C; V4_3A1B30 v80;
    s32 f90, f94, f98, f9C, fA0; u8 pA4[0x20]; s32 fC4, fC8, fCC, fD0, fD4; u8 pD8[4];
    s32 fDC, fE0, fE4, fE8; u8 pEC[8]; s32 fF4, fF8, fFC; u8 p100[0x18];
    s32 f118, f11C, f120, f124, f128;
} S_D_3A1B30;
typedef struct { u8 p00[0x20]; u8 b20; u8 p21[0x47]; S_D_3A1B30 *f68; } S_SELF_3A1B30;
typedef struct { u8 p0[0xD0]; u8 bD0; u8 pD1[0xB]; void *fDC; } S_G7_3A1B30;
typedef struct { u8 p00[0x30]; V4_3A1B30 v30; u8 p40[0x30]; V4_3A1B30 v70; } S_DEE_3A1B30;

extern Hero_3A1B30 D_001A4BE0;
extern u8 *D_001DED1C_sda;
__asm__(".extern D_001DED1C_sda, 4");
extern S_MOB_3A1B30 *D_L27_001DED1C_003A1B30;
__asm__(".extern D_L27_001DED1C_003A1B30, 16");
extern S_DEE_3A1B30 *D_L27_001DEE00_003A1B30;
__asm__(".extern D_L27_001DEE00_003A1B30, 16");
extern u8 D_001A30B0[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_001A818C[4];
extern u8 D_L27_001E1600[];
extern s32 func_L01_004561E0(void *);
extern void func_L27_003A2E08();
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0041A5B0(s32, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L22_003B72F0(void *, f32, void *, s32);

extern void func_L27_0039F6A8(void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00456250(void *);

extern void func_003C7DD8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_0043B510(s32);
extern void func_L01_004450F0(void *, s32, s32);


void func_L27_003A1B30(u8 *pself) {
    S_SELF_3A1B30 *self = (S_SELF_3A1B30 *)pself;
    S_D_3A1B30 *d = self->f68;
    S_MOB_3A1B30 *m, *o0, *o4;
    S_G7_3A1B30 *g;
    V4_3A1B30 a, b, c;
    f32 x, t, u;

    if (func_L01_004561E0(self) != 0) {
        func_L27_003A2E08(self);
        d->fDC = 0;
    }
    if (d->f6C == 0) {
        if ((d->fC4 == -1 || ((S_MOB_3A1B30 *)((d->fC4 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fC4 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->fC8 == -1 || ((S_MOB_3A1B30 *)((d->fC8 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fC8 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->fCC == -1 || ((S_MOB_3A1B30 *)((d->fCC << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fCC << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->fD0 == -1 || ((S_MOB_3A1B30 *)((d->fD0 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fD0 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->f7C == -1 || ((S_MOB_3A1B30 *)((d->f7C << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->f7C << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->fD4 == -1 || ((S_MOB_3A1B30 *)((d->fD4 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->fD4 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->f98 == -1 || ((S_MOB_3A1B30 *)((d->f98 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->f98 << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD) ||
            (d->f9C == -1 || ((S_MOB_3A1B30 *)((d->f9C << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_MOB_3A1B30 *)((d->f9C << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD))
            d->f6C = 1;
    }
    if (func_L01_00456500(&D_001A4BE0.i[0x20], d->f8) == 0) {
        if ((D_001BBC40[d->f34 + (D_001D545C << 4)] & 0x80) == 0) {
            if (((S_HOBJ_3A1B30 *)D_001A4BE0.ptr[0x970])->hAA != 0x1A4E &&
                D_001A4BE0.i[0x973] != 0x14 && D_001A4BE0.i[0x973] != 0x19 && D_001A818C[0] >= 0) {
                func_L01_0041A5B0(0xBA6, 0x49);
            }
        }
    }
    if (D_L27_001DED1C_003A1B30[d->fE0].f68->fC == 0) {
        s32 i = d->fC4;
        if (i != -1 && D_L27_001DED1C_003A1B30[i].b20 != 0xFE && D_L27_001DED1C_003A1B30[i].b20 != 0xFD &&
            D_L27_001DED1C_003A1B30[i].f68->f4A0 > 0) {
            a = D_L27_001DED1C_003A1B30[d->f118].pos;
            func_L22_003B72F0(&D_L27_001DED1C_003A1B30[i],
                func_0038D160(((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.x - D_L27_001DED1C_003A1B30[d->f118].pos.x,
                              ((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.y - D_L27_001DED1C_003A1B30[d->f118].pos.y), &a, 0);
        }
    }
    D_L27_001DED1C_003A1B30[d->fE0].f68->fC = D_L27_001DED1C_003A1B30[d->f118].f68->f0;

    if (D_L27_001DED1C_003A1B30[d->fE4].f68->fC == 0) {
        s32 i = d->fCC;
        if (i != -1 && D_L27_001DED1C_003A1B30[i].b20 != 0xFE && D_L27_001DED1C_003A1B30[i].b20 != 0xFD &&
            D_L27_001DED1C_003A1B30[i].f68->f4A0 > 0) {
            a = D_L27_001DED1C_003A1B30[d->f11C].pos;
            func_L22_003B72F0(&D_L27_001DED1C_003A1B30[i],
                func_0038D160(((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.x - D_L27_001DED1C_003A1B30[d->f11C].pos.x,
                              ((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.y - D_L27_001DED1C_003A1B30[d->f11C].pos.y), &a, 0);
        }
    }
    D_L27_001DED1C_003A1B30[d->fE4].f68->fC = D_L27_001DED1C_003A1B30[d->f11C].f68->f0;

    if (D_L27_001DED1C_003A1B30[d->fE8].f68->fC == 0) {
        s32 i = d->fD4;
        if (i != -1 && D_L27_001DED1C_003A1B30[i].b20 != 0xFE && D_L27_001DED1C_003A1B30[i].b20 != 0xFD &&
            D_L27_001DED1C_003A1B30[i].f68->f4A0 > 0) {
            a = D_L27_001DED1C_003A1B30[d->f120].pos;
            func_L22_003B72F0(&D_L27_001DED1C_003A1B30[i],
                func_0038D160(((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.x - D_L27_001DED1C_003A1B30[d->f120].pos.x,
                              ((S_MOB_3A1B30 *)D_001A4BE0.ptr[0x970])->pos.y - D_L27_001DED1C_003A1B30[d->f120].pos.y), &a, 0);
        }
    }
    D_L27_001DED1C_003A1B30[d->fE8].f68->fC = D_L27_001DED1C_003A1B30[d->f120].f68->f0;
    D_L27_001DED1C_003A1B30[d->fF4].f68->fC = D_L27_001DED1C_003A1B30[d->f124].f68->f0;
    D_L27_001DED1C_003A1B30[d->fF8].f68->fC = 1;
    D_L27_001DED1C_003A1B30[d->fFC].f68->fC = D_L27_001DED1C_003A1B30[d->f128].f68->f0;

    if (d->f74 == 0) {
        if (d->f7C != -1 && D_L27_001DED1C_003A1B30[d->f7C].b20 != 0xFE &&
            D_L27_001DED1C_003A1B30[d->f7C].b20 != 0xFD && D_L27_001DED1C_003A1B30[d->f7C].f68->f4A0 > 0) {
            m = &D_L27_001DED1C_003A1B30[d->f90];
            if (D_001A4BE0.i[0x971] != 0x74 && D_001A4BE0.i[0x971] != 0x58) {
                if (((S_HOBJ_3A1B30 *)D_001A4BE0.ptr[0x970])->hAA == 0x1A4E) {
                    func_L27_004D1568(0x58, 0);
                } else {
                    func_L27_004D1568(0x74, 0);
                }
                func_L27_0039F6A8(&D_L27_001DED1C_003A1B30[d->f7C]);
                func_L01_003EB438(0, D_L27_001E1600, D_L27_001E1600 + 0x10, 0, 0, 0);
                func_L01_003EB350(0, &D_L27_001DEE00_003A1B30[d->f94].v30);
                d->f70 = 0;
                o0 = &D_L27_001DED1C_003A1B30[d->f0];
                o4 = &D_L27_001DED1C_003A1B30[d->f4];
                *(u128_t *)&o0->pos = *(u128_t *)&D_L27_001DEE00_003A1B30[d->f78].v30;
                *(u128_t *)&o0->vF0 = *(u128_t *)&D_L27_001DEE00_003A1B30[d->f78].v70;
                func_003C3A10(o0, 0x14, 0, 4);
                a.x = -func_0038D098(o0->vF0.z);
                a.y = -func_0038D0B0(o0->vF0.z);
                a.z = 0;
                a.w = 1.0f;
                vec_add_ab(&o4->pos, &o0->pos, &a);
                o4->vF0 = o0->vF0;
            }
            if (func_L01_00456250(&D_L27_001DED1C_003A1B30[d->f7C]) != 0) {
                x = d->f70 + 1.0f;
                d->f70 = x;
                t = x / 250.0f;
                u = t > 1.0f ? 1.0f : t;
                a = d->v80;
                a.z = a.z + -15.0f;
                b = d->v80;
                vec_sub_ba(&c, &b, &a);
                func_0038CE20(&c, &c, u);
                vec_add_ab(&m->pos, &c, &a);
                func_003C7DD8(m);
                {
                s32 i = d->f24;
                if (i == -1 || ((S_G7_3A1B30 *)(D_001A30B0 + (i << 7)))->fDC != m ||
                    ((S_G7_3A1B30 *)(D_001A30B0 + (i << 7)))->bD0 == 0) {
                    d->f24 = func_003A52A0(0, 4, m);
                }
                }
                if (u >= 1.0f) {
                    s32 i;
                    d->f74 = 1;
                    i = d->f24;
                    if (i != -1) {
                        g = (S_G7_3A1B30 *)(D_001A30B0 + (i << 7));
                        if (g->fDC == m && g->bD0 != 0) func_003A4F28(i);
                    }
                    d->f24 = -1;
                }
            }
            a.x = 0;
            a.y = -func_0038D160(func_0038CF38(&D_L27_001DEE00_003A1B30[d->f94].v30, &m->pos),
                                 m->pos.z - D_L27_001DEE00_003A1B30[d->f94].v30.z);
            a.z = func_0038D160(m->pos.x - D_L27_001DEE00_003A1B30[d->f94].v30.x,
                                m->pos.y - D_L27_001DEE00_003A1B30[d->f94].v30.y);
            func_L01_003EB3C0(0, &a);
        }
    }
    if (D_L27_001DED1C_003A1B30[d->fA0].f68->f0 == 0) {
        if (d->f98 != -1 && D_L27_001DED1C_003A1B30[d->f98].b20 != 0xFE &&
            D_L27_001DED1C_003A1B30[d->f98].b20 != 0xFD && D_L27_001DED1C_003A1B30[d->f98].f68->f4A0 > 0) {
            if (func_L01_00456250(&D_L27_001DED1C_003A1B30[d->f98]) == 0) {
                func_L27_0039F6A8(&D_L27_001DED1C_003A1B30[d->f98]);
            } else {
                D_L27_001DED1C_003A1B30[d->fA0].f68->f0 = 1;
            }
        }
    }
    if (d->f74 != 0) {
        if (self->b20 == 5) {
            func_L01_0043B510(d->f34);
            D_L27_001DED1C_003A1B30[d->f90].pos = d->v80;
            func_L01_004450F0(self, 6, 2);
        }
    }
    if (func_00382380(&D_001A4BE0.i[0x20], d->f68, 0) != 0) {
        func_L01_0043B510(d->f3C);
        func_L01_004450F0(self, 3, 0);
    }
}
/* localdecomp:end func_L27_003A1B30 */

/* localdecomp:start func_L27_003A2548 */
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
extern u8 *D_L27_001DED1C;
extern struct S_L27_001DEE00 *D_L27_001DEE00;
extern struct S_L27_001A4C60 D_001A4C60;
extern S_2548_G D_001A7E18;
extern s32 D_001A663C[];
extern u8 D_L27_001E8180[];
extern f32 D_L27_001DE6D0;
extern s32 func_L01_004561E0(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern S_2548_F *func_L01_003F2A50(s32, s32);
extern void func_L01_003F2AF8(s32, void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_0043B510(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L23_003D8628(s32, s32, f32);
extern void func_L01_003F5498(s32, f32);
extern void func_L27_003A2B98();

void func_L27_003A2548(u8 *self) {
    S_2548_D *d = *(S_2548_D **)(self + 0x68);
    S_2548_F *f;
    if (func_L01_004561E0(self) != 0) {
        func_L27_003A2B98(self);
        d->fDC = 0;
    }
    ((S_2548_E *)((d->fEC << 8) + (s32)D_L27_001DED1C))->f68->fC = ((S_2548_E *)((d->f104 << 8) + (s32)D_L27_001DED1C))->f68->f0 != 0 || ((S_2548_E *)((d->f108 << 8) + (s32)D_L27_001DED1C))->f68->f0 != 0;
    ((S_2548_E *)((d->fF0 << 8) + (s32)D_L27_001DED1C))->f68->fC = ((S_2548_E *)((d->f110 << 8) + (s32)D_L27_001DED1C))->f68->f0 != 0 || ((S_2548_E *)((d->f114 << 8) + (s32)D_L27_001DED1C))->f68->f0 != 0;
    ((S_2548_E *)((d->fA8 << 8) + (s32)D_L27_001DED1C))->f68->f98 = ((S_2548_E *)((d->f12C << 8) + (s32)D_L27_001DED1C))->f68->f0;
    if (d->f54 >= 0 && func_00382380(&D_001A4C60, d->f54, 0) != 0) {
        if (D_001A7E18.fCA4 >= 0) func_L01_0041A5B0(0x140B, 0x10D);
        d->f54 = -1;
    }
    if (d->fB8 == 0 && func_00382380(&D_001A4C60, d->fBC, 0) != 0) {
        f = func_L01_003F2A50(0, 5);
        d->fB8 = f;
        if (f != 0) f->f4 = 3.0f;
    } else if (d->fB8 != 0 && func_00382380(&D_001A4C60, d->fBC, 0) == 0) {
        func_L01_003F2AF8(0, d->fB8);
        d->fB8 = 0;
    }
    if (((S_2548_E *)((d->fA4 << 8) + (s32)D_L27_001DED1C))->f68->f0 == 0) {
        if (func_00382380(&D_001A4C60, d->fAC, 0) != 0) {
            *(f32 *)((u8 *)&D_001A4C60 + 0x19DC) = 0.43633232f;
            if (d->b51 == 0 && func_00392B20(D_L27_001E8180, 0xC7) != 0) {
                func_00392C78(D_L27_001E8180);
                d->b51 = 1;
            } else if (d->b51 != 0) {
                if (d->f60 >= 0) {
                    *(vu0_q *)&((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->v10 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00 + 0x30);
                    *(vu0_q *)&((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->vF0 = *(vu0_q *)((d->f60 << 7) + (s32)D_L27_001DEE00 + 0x70);
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xFFBE;
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 |= ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f24->h44 & 0x1000;
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f98 = ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->f24->f10;
                    ((S_2548_E *)((d->f4 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xFFFD;
                    ((S_2548_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->h34 |= 0x41;
                    ((S_2548_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->h34 &= 0xEFFF;
                    ((S_2548_E *)((d->f58 << 8) + (s32)D_L27_001DED1C))->f98 = 0;
                    func_L01_004AA7E8(D_L27_001DED1C + (d->f58 << 8), 1);
                    d->f60 = -1;
                }
                if ((D_001A7E18.f344 & 0x80000000) == 0) func_L01_0041A5B0(0xBA2, 0x45);
                if (++d->fDC >= 0x5DD && (D_001A7E18.f350 & 0x80000000) == 0) func_L01_0041A5B0(0xBA3, 0x46);
            }
        }
        if (((S_2548_E *)((d->f10C << 8) + (s32)D_L27_001DED1C))->f68->f0 != 0) {
            ((S_2548_E *)((d->fA4 << 8) + (s32)D_L27_001DED1C))->f68->f0 = 1;
            D_001A663C[0] = 0;
            d->fDC = 0;
        }
    }
    if (d->fB0 >= 0 && func_00382380(&D_001A4C60, d->fB0, 0) != 0) {
        if (++d->fDC >= 0xFB) {
            if (D_001A7E18.f35C >= 0) func_L01_0041A5B0(0xBA4, 0x47);
            d->fDC = 0;
            d->fB0 = -1;
        }
    }
    if (d->fB4 >= 0 && func_00382380(&D_001A4C60, d->fB4, 0) != 0 && d->fC0 != -1
        && ((S_2548_E *)((d->fC0 << 8) + (s32)D_L27_001DED1C))->b20 != 0xFE && ((S_2548_E *)((d->fC0 << 8) + (s32)D_L27_001DED1C))->b20 != 0xFD) {
        if (++d->fDC >= 0x1F5) {
            if (D_001A7E18.f29C >= 0) func_L01_0041A5B0(0xB94, 0x37);
            d->fB4 = -1;
            d->fDC = 0;
        }
    }
    ((S_2548_E *)((d->f100 << 8) + (s32)D_L27_001DED1C))->f68->fC = func_L01_00456250(D_L27_001DED1C + (d->fD8 << 8));
    if (d->f74 == 0 && func_00382380(&D_001A4C60, d->f78, 0) != 0) {
        if (d->b52 == 0 && func_00392B20(D_L27_001E8180, 0xC8) != 0) {
            func_00392C78(D_L27_001E8180);
            d->b52 = 1;
        } else if (d->b52 != 0) {
            func_L01_0043B510(d->f30);
            func_L01_004450F0(self, 5, 1);
        }
    }
    if (func_00382380(&D_001A4C60, d->f64, 0) != 0) {
        func_L23_003D8628(0, 1, 25.0f);
        if (1.0f <= D_L27_001DE6D0) {
            func_L01_003F5498(0, 25.0f);
            func_L01_0043B510(d->f38);
            func_L01_004450F0(self, 7, 1);
        }
    }
}
/* localdecomp:end func_L27_003A2548 */

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
