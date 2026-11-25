#include "common.h"

/* localdecomp:start func_L02_003A0EE8 */
#include "vu0.h"
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0EE8;
typedef struct {
    s32 f0;
    u8 f4;
    u8 f5;
    s16 f6;
    f32 f8;
    s32 fC;
    V4_3A0EE8 v;
    s32 t20;
    f32 f24;
    f32 f28;
    s16 f2C;
    s16 f2E;
} Vars_3A0EE8;
typedef struct Self_3A0EE8 {
    u8 pad0[0x10];
    V4_3A0EE8 pos;
    u8 state;
    u8 pad21[3];
    struct { u8 pad[0x10]; s32 f10; } *f24;
    u8 pad28[0x40];
    Vars_3A0EE8 *vars;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0xE];
    u16 fAA;
    u8 padAC[0x44];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} Self_3A0EE8;
typedef struct { u8 pad0[0x18]; u8 f18; u8 f19; u16 f1A; u8 pad1C[4]; } Info_3A0EE8;
typedef struct {
    u8 pad0[0x1DC]; s16 f1DC; u8 pad1DE[0x15E]; f32 f33C; u8 pad340[0x2E]; s16 f36E;
    u8 pad370[0x2250]; s32 f25C0; s32 f25C4; u8 pad25C8[0x288]; s32 f2850;
} G_3A0EE8;
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 f28; s32 f2C; } T_3A0EE8;
typedef struct { u8 pad[0xAA]; s16 fAA; } Obj_3A0EE8;
typedef union { V4_3A0EE8 v[2]; Info_3A0EE8 i; } A_3A0EE8;

struct O_3A2320;
extern void func_L02_003A2320(struct O_3A2320 *);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CB00(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_004471A8(void *, f32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446978(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003A4F28(s32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003C4C18(void *, f32);
extern void *func_L01_003016B0(void *, s32, f32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_00468A68(void *, void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern G_3A0EE8 D_001A4BE0;
extern V4_3A0EE8 D_L02_001E8040[];
extern T_3A0EE8 D_L02_001E1300;
extern Obj_3A0EE8 *D_L02_001E8058[];
extern Obj_3A0EE8 *D_L02_001EC0C0[];
extern f32 D_L02_002EF1F0[];
extern u8 *D_L02_0021E0D8[];
extern s32 D_001D545C_sda;

void func_L02_003A0EE8(Self_3A0EE8 *self) {
    Vars_3A0EE8 *v;
    V4_3A0EE8 prev;
    A_3A0EE8 a;
    V4_3A0EE8 pos2;
    V4_3A0EE8 tmp;
    u8 *rr;
    f32 f;
    f32 d;
    s32 i;
    s32 n;
    s32 hit;
    s32 mode;
    s32 cnt;
    s32 k;

    func_L02_003A2320((struct O_3A2320 *)self);
    v = self->vars;
    switch (self->state) {
    case 1:
        if (v->f0 != -1 && func_L01_00456500(D_001A4C60, v->f0) != 0) {
            self->state = 2;
        }
        break;
    case 2:
        prev = self->pos;
        v->v.z -= v->f8;
        vec_add_ab(&self->pos, &self->pos, &v->v);
        self->fF0 = func_0038DAB8(self->fF0, v->f28);
        if (v->f6 == 1) self->fF8 = 2.3561945f;
        if (self->pos.x < 2.0f || self->pos.x > 1021.0f || self->pos.y < 2.0f || self->pos.y > 1021.0f
            || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
            self->state = 5;
        }
        if (func_0038CB00(&v->f2C) != 0
            && (func_003D3CB0(&prev, &self->pos, 2, self, 0) != 0
                || func_L01_003FB640(&self->pos, 2, self, v->f24) != 0)) {
            V4_3A0EE8 *contact;
            if (v->f4 != 0) {
                func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                v->f28 = func_0038CEA8(&v->v);
            } else {
                func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                v->v.z *= 0.7f;
                v->v.y *= 1.15f;
                v->v.x = 0.0f;
                v->f28 = func_0038CEA8(&v->v) * 0.6f;
                if (v->v.y < -0.120000005f) v->v.y = -0.18f;
                if (v->f28 > 1.32f) v->f28 = 1.32f;
            }
            contact = &D_L02_001E8040[2];
            a.v[0] = *contact;
            a.v[0].z += 0.15f;
            cnt = v->f2E * 6;
            for (i = 0; i < cnt; i++) {
                f32 f = func_003824E0(0.3f, 0.6f) * 210000.0f;
                u8 *rr;
                a.v[1].x = func_L01_00443A18(0.0f, 0.020000001f);
                a.v[1].y = func_L01_00443A18(0.0f, 0.020000001f);
                a.v[1].z = func_003824E0(0.25f, 0.8f) * 0.020000001f;
                pos2 = a.v[0];
                pos2.x += func_L01_00443A18(0.0f, 0.6f);
                pos2.y += func_L01_00443A18(0.0f, 0.6f);
                pos2.z += func_L01_00443A18(0.0f, 0.2f);
                rr = func_L01_0046FB40(&pos2, &a.v[1], (func_00382498(35, 60) * 5 + 2) / 6, 0x128090A0,
                                       func_00382468(2) != 0 ? 1 : -1, 0x32, 0, f, f, 0.0f, 0);
                if (rr != 0) {
                    rr[2] = D_L02_0021E0D8[23][0];
                    rr[3] = 0x44;
                }
                if (v->f4 != 0) {
                    self->state = 3;
                    v->v.z = 0.0f;
                    self->pos.z = D_L02_001E8040[2].z + 0.98f;
                    v->f8 = 0.008f;
                }
            }
            func_003A52A0(0, 0, self);
            {
            f32 dd = func_0038CF00(&self->pos, D_001A4C60);
            f32 e = ((f32)v->f2E * dd == 0.0f) ? 1.0f : 0.5f / dd;
            D_L02_001E1300.f20 = e;
            }
            D_L02_001E1300.f28 = 0x15;
            D_L02_001E1300.f2C = 0;
            if (--v->f2E == 0) self->state = 3;
        }
        func_L01_004471A8(self, v->f6 == 0 ? 0.7f : 1.1f);
        hit = 0;
        n = func_003D4D00(&self->pos, 0, self, 0, v->f6 == 0 ? 0.8f : 1.1f);
        if (n != 0) {
            s32 j;
            for (j = 0; j < n; j++) {
                if (D_L02_001EC0C0[j]->fAA != 0x18C2) {
                    if (D_L02_001EC0C0[j]->fAA == 0) {
                        if (D_001A4BE0.f36E != 0 && D_001A4BE0.f33C > 0.5f) {
                            tmp = v->v;
                            func_0038CE20(&tmp, &tmp, 3.0f);
                            tmp.w = 5627.9248f;
                            self->f98 = self->f24->f10;
                            func_L01_00446760(&a, self, 1, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C] : 1.0f, &tmp);
                        } else if (D_001A4BE0.f25C4 != 0x91 && D_001A4BE0.f2850 != 0) {
                            if (D_001A4BE0.f1DC == 0) {
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8,
                                                  func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
                                hit = 1;
                            } else {
                                D_001A4BE0.f1DC = 0;
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8, 0.0f);
                                hit = 1;
                            }
                        }
                    } else {
                        tmp = v->v;
                        func_0038CE20(&tmp, &tmp, 3.0f);
                        tmp.w = 5627.9248f;
                        self->f98 = self->f24->f10;
                        func_L01_00446760(&a, self, 0x10000, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C] : 1.0f, &tmp);
                        hit = 1;
                    }
                    a.i.f19 = 1;
                    a.i.f1A = self->fAA;
                    a.i.f18 = 0;
                    func_L01_00446978(D_L02_001EC0C0[j], &a);
                }
            }
        }
        if (hit != 0) {
            if ((s32)D_L02_001E8058[0] != D_001A4BE0.f25C0 || D_001A4BE0.f1DC == 0) {
                func_003A52A0(2, 0, self);
            }
        }
        if ((v->f6 == 0 && self->pos.y < 248.0f) || self->pos.z <= 22.0f) {
            self->state = 4;
            if (v->fC != -1) {
                u8 *e = D_001A30B0 + (v->fC << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) func_003A4F28(v->fC);
            }
            v->fC = -1;
            self->f98 = self->f24->f10;
        }
        break;
    case 3:
        prev = self->pos;
        v->v.z -= v->f8;
        vec_add_ab(&self->pos, &self->pos, &v->v);
        self->fF0 = func_0038DAB8(self->fF0, v->f28);
        if (v->f6 == 1) self->fF8 = 2.3561945f;
        if (self->pos.x < 2.0f || self->pos.x > 1021.0f || self->pos.y < 2.0f || self->pos.y > 1021.0f
            || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
            self->state = 5;
        }
        if (func_L01_004AA710(self, v->fC) == 0) v->fC = func_003A52A0(1, 4, self);
        if (func_0038CB00(&v->f2C) != 0
            && (func_003D3CB0(&prev, &self->pos, 2, self, 0) != 0
                || func_L01_003FB640(&self->pos, 2, self, v->f24) != 0)) {
            V4_3A0EE8 *contact;
            f32 f;
            u8 *rr;
            if (v->f4 != 0) {
                if (D_L02_001E8058[0] != 0 && D_L02_001E8058[0]->fAA == 0x18C2) {
                    self->pos.z += 0.2f;
                } else {
                    func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                    v->f28 = func_0038CEA8(&v->v);
                    if (v->v.z > 0.0f) v->v.z = 0.0f;
                }
            } else {
                func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
                v->v.z *= 0.15999997f;
                v->v.y *= 1.18f;
                v->v.x = 0.0f;
                v->f28 = func_0038CEA8(&v->v) * 0.52f;
                if (v->v.y < -0.120000005f) v->v.y = -0.18f;
                if (v->f28 > 1.32f) v->f28 = 1.32f;
            }
            contact = &D_L02_001E8040[2];
            a.v[0] = *contact;
            func_003C4C18(&a.v[0], 0.2f);
            *(u128_t *)&pos2 = 0;
            pos2.z = func_003824E0(0.05f, 0.5f) * 0.020000001f;
            a.v[1] = pos2;
            f = func_003824E0(0.7f, 1.0f) * 210000.0f;
            rr = func_L01_0046FB40(&a.v[0], &a.v[1], (func_00382498(35, 60) * 5 + 2) / 6, 0x128090A0,
                                   func_00382468(2) != 0 ? 1 : -1, 0x32, 0, f, f, 0.0f, 0);
            if (rr != 0) {
                rr[2] = D_L02_0021E0D8[23][0];
                rr[3] = 0x44;
            }
            if (v->f4 != 0) self->pos.z = contact->z + 0.98f;
        }
        func_L01_004471A8(self, v->f6 == 0 ? 0.7f : 1.1f);
        hit = 0;
        n = func_003D4D00(&self->pos, 0, self, 0, v->f6 == 0 ? 0.8f : 1.1f);
        if (n != 0) {
            s32 j;
            for (j = 0; j < n; j++) {
                if (D_L02_001EC0C0[j]->fAA != 0x18C2) {
                    if (D_L02_001EC0C0[j]->fAA == 0) {
                        if (D_001A4BE0.f36E != 0 && D_001A4BE0.f33C > 0.5f) {
                            tmp = v->v;
                            func_0038CE20(&tmp, &tmp, 3.0f);
                            tmp.w = 5627.9248f;
                            self->f98 = self->f24->f10;
                            func_L01_00446760(&a, self, 1, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C] : 1.0f, &tmp);
                        } else if (D_001A4BE0.f25C4 != 0x91 && D_001A4BE0.f2850 != 0) {
                            if (D_001A4BE0.f1DC == 0) {
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8,
                                                  func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
                                hit = 1;
                            } else {
                                D_001A4BE0.f1DC = 0;
                                self->f98 = 0;
                                func_L01_00446748(&a, self, 8, 0.0f);
                                hit = 1;
                            }
                        }
                    } else {
                        tmp = v->v;
                        func_0038CE20(&tmp, &tmp, 3.0f);
                        tmp.w = 5627.9248f;
                        self->f98 = self->f24->f10;
                        func_L01_00446760(&a, self, 0x10000, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C] : 1.0f, &tmp);
                        hit = 1;
                    }
                    a.i.f19 = 1;
                    a.i.f1A = self->fAA;
                    a.i.f18 = 0;
                    func_L01_00446978(D_L02_001EC0C0[j], &a);
                }
            }
        }
        if (hit != 0) {
            if ((s32)D_L02_001E8058[0] != D_001A4BE0.f25C0 || D_001A4BE0.f1DC == 0) {
                func_003A52A0(2, 0, self);
            }
        }
        if ((v->f6 == 0 && self->pos.y < 248.0f) || (d = func_003C3D30(&self->pos, 0, 0, 0.5f), self->pos.z + 20.0f < d)
            || self->pos.z <= 22.0f) {
            self->state = 4;
            if (v->fC != -1) {
                u8 *e = D_001A30B0 + (v->fC << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) func_003A4F28(v->fC);
            }
            v->fC = -1;
            self->f98 = self->f24->f10;
        }
        break;
    case 4:
        prev = self->pos;
        v->v.z -= v->f8;
        vec_add_ab(&self->pos, &self->pos, &v->v);
        self->fF0 = func_0038DAB8(self->fF0, v->f28);
        if (v->f6 == 1) self->fF8 = 2.3561945f;
        mode = self->pos.z <= 22.0f ? 0xB20 : 0;
        if (func_0038CB00(&v->f2C) != 0
            && (func_003D3CB0(&prev, &self->pos, mode, self, 0) != 0
                || func_L01_003FB640(&self->pos, mode, self, v->f24) != 0)) {
            f32 f;
            u8 *rr;
            func_L01_0040E790(&v->v, &v->v, &D_L02_001E8040[4]);
            v->v.x *= 0.88f;
            v->v.y *= 0.88f;
            a.v[0] = D_L02_001E8040[2];
            func_003C4C18(&a.v[0], 0.2f);
            *(u128_t *)&pos2 = 0;
            pos2.z = func_003824E0(0.05f, 0.5f) * 0.020000001f;
            a.v[1] = pos2;
            f = func_003824E0(0.3f, 1.0f) * 210000.0f;
            rr = func_L01_0046FB40(&a.v[0], &a.v[1], (func_00382498(35, 60) * 5 + 2) / 6, 0x128090A0,
                                   func_00382468(2) == 0 ? -1 : 1, 0x10, 0, f, f, 0.0f, 0);
            if (rr != 0) {
                rr[2] = D_L02_0021E0D8[23][0];
                rr[3] = 0x44;
            }
            func_003A52A0(0, 0, self);
        }
        if (v->f5 == 0) {
            if (self->pos.z < 21.0f) {
                rr = func_L01_003016B0(&self->pos, 9, v->f6 == 1 ? 2.5f : 2.0f, 1.1f);
                if (rr != 0) func_L01_0043B9E8(rr, 0x7F, 0x30, 0x1F);
                for (k = 0; k < 20; k++) {
                    f32 ang = func_00382538();
                    f32 dd = func_003824E0(0.0f, 0.060000002f);
                    u8 *r;
                    a.v[0].x = func_0038D098(ang) * dd;
                    a.v[0].y = func_0038D0B0(ang) * dd;
                    a.v[0].z = func_003824E0(0.060000002f, 0.16000001f);
                    r = func_L01_00468A68(&self->pos, &a.v[0], func_00382468(2), func_00382498(90, 120));
                    if (r != 0) r[2] = D_L02_0021E0D8[91][0];
                }
                v->f5 = 1;
            }
        }
        if (func_0038CAD0(&v->t20) != 0 || self->pos.z < 17.0f || self->pos.x < 2.0f || self->pos.x > 1021.0f
            || self->pos.y < 2.0f || self->pos.y > 1021.0f || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
            self->state = 5;
        }
        break;
    case 5:
        func_003C2880(self);
        break;
    }
}
/* localdecomp:end func_L02_003A0EE8 */

/* localdecomp:start func_L02_003A2320 */
typedef struct P_3A2320 {
    u8 pad0[8]; float f8; u8 padC[0x14];
    s32 f20; float f24; float f28; s16 f2C; s16 f2E;
} P_3A2320;
typedef struct O_3A2320 {
    u8 pad0[0x20]; u8 f20; u8 pad21[0x13]; u16 f34; u8 pad36[0x32]; P_3A2320 *p;
} O_3A2320;
extern float func_003824E0(float a, float b);

void func_L02_003A2320(O_3A2320 *o) {
    P_3A2320 *p;
    if (o->f20 == 0) {
        p = o->p;
        p->f28 = func_003824E0(0.031415928f, 0.12566371f);
        p->f20 = 100;
        p->f24 = 0.65f;
        p->f2C = 0x32;
        p->f8 = 0.00392f;
        p->f2E = 7;
        o->f20 = 1;
        o->f34 |= 0x808;
    }
}
/* localdecomp:end func_L02_003A2320 */

/* localdecomp:start func_L02_003A23C8 */
typedef struct V4_3A23C8 { float x, y, z, w; } __attribute__((aligned(16))) V4_3A23C8;
typedef struct P_3A23C8 {
    u8 pad0[4]; u8 f4; u8 pad5; s16 f6; float f8; u8 padC[0x14];
    s32 f20; float f24; float f28; s16 f2C; s16 f2E;
} P_3A23C8;
typedef struct O_3A23C8 {
    u8 pad0[0x10]; V4_3A23C8 v; u8 f20; u8 pad21[0xB]; float f2C; u8 f30; u8 f31; s16 f32;
    u8 pad34[0x34]; P_3A23C8 *p;
} O_3A23C8;
extern O_3A23C8 *func_003C24B0(int a, int b);
extern float func_003824E0(float a, float b);
extern void func_003C7C38(O_3A23C8 *o);

void func_L02_003A23C8(int arg0, int arg1) {
    O_3A23C8 *o;
    P_3A23C8 *p;
    V4_3A23C8 t;
    o = func_003C24B0(0x1976, 0x80);
    if (o != 0) {
        p = o->p;
        p->f28 = func_003824E0(0.031415928f, 0.12566371f);
        p->f20 = 100;
        p->f24 = (arg1 == 0) ? 0.65f : 0.98f;
        p->f2C = 0x32;
        p->f2E = 7;
        p->f8 = 0.00392f;
        p->f4 = arg1;
        p->f6 = arg1;
        if (arg1 == 1) o->f2C *= 1.5f;
        o->f30 = 0xFF;
        o->f32 = 0xFF;
        o->f20 = 2;
        o->f31 = 1;
        switch (arg0) {
        case 0:
            if (arg1 == 0) { t.x = 139.304f; t.y = 288.992f; t.z = 42.556f; t.w = 0; }
            else { t.x = 225.54f; t.y = 211.71f; t.z = 54.05f; t.w = 0; }
            break;
        case 1:
            if (arg1 == 0) { t.x = 141.0f; t.y = 289.023f; t.z = 42.592f; t.w = 0; }
            else { t.x = 223.19f; t.y = 213.85f; t.z = 54.05f; t.w = 0; }
            break;
        case 2:
            if (arg1 == 0) { t.x = 142.685f; t.y = 288.919f; t.z = 42.61f; t.w = 0; }
            else { t.x = 221.01f; t.y = 215.79f; t.z = 54.05f; t.w = 0; }
            break;
        }
        o->v = t;
        func_003C7C38(o);
    }
}
/* localdecomp:end func_L02_003A23C8 */

/* localdecomp:start func_L02_003A2620 */
typedef struct S_3A2620 {
    u16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8 pad[4];
    s32 fC;
} S_3A2620;
typedef struct T_3A2620 {
    u8 pad[0x20];
    u8 state;
    u8 pad2[0x47];
    S_3A2620 *p;
} T_3A2620;
extern u8 D_001A4C60[];
extern void func_L02_003A2708(void *arg0);
extern int func_L01_00456500(void *a, int b);
extern int func_0038CB00(void *a);
extern int func_00382468(int a);
extern void func_L02_003A23C8(int a, int b);

void func_L02_003A2620(T_3A2620 *arg0) {
    S_3A2620 *q;
    int r;
    int s;
    func_L02_003A2708(arg0);
    q = arg0->p;
    s = arg0->state;
    if (s != 2) {
        if (s < 3) {
            if (s == 1) {
                if (q->fC != -1) {
                    if (func_L01_00456500(D_001A4C60, q->fC) != 0) {
                        arg0->state = 2;
                    }
                }
            }
        }
    } else {
        if (func_L01_00456500(D_001A4C60, q->fC) == 0) {
            arg0->state = 1;
        } else if (func_0038CB00(&q->f2) != 0) {
            do {
                r = func_00382468(3);
            } while (r == q->f4);
            func_L02_003A23C8(r, q->f6);
            q->f2 = q->f0;
            q->f4 = r;
        }
    }
}
/* localdecomp:end func_L02_003A2620 */

/* localdecomp:start func_L02_003A2708 */
void func_L02_003A2708(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s16 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 4) = -1;
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L02_003A2708 */
