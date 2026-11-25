#include "common.h"
#include "vu0.h"
#include "structs/weapon.h"

/* localdecomp:start func_L01_00356C88 */
void func_L01_00356C88(void) {

}
/* localdecomp:end func_L01_00356C88 */

/* localdecomp:start func_L01_00356C90 */
void func_L01_00356C90(void) {

}
/* localdecomp:end func_L01_00356C90 */

/* localdecomp:start func_L01_00356C98 */
typedef struct {
    vu0_q saved;
    u8 pad10[4];
    f32 f14;
    u8 pad18[4];
    f32 f1C;
    struct UpdateObject *effect;
    s32 handle;
    s32 level;
    s32 unused;
    s32 count;
} UpdateVars;

typedef struct UpdateObject {
    vu0_q transform;
    vu0_v4 position;
    u8 state;
    u8 pad21[3];
    u8 *class_data;
    u8 pad28[4];
    f32 scale;
    u8 opacity;
    u8 pad31[3];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    UpdateVars *vars;
    u8 pad6c[0xC0 - 0x6C];
    vu0_q matrix[4];
} UpdateObject;

typedef struct {
    u8 pad0[0xE0];
    vu0_v4 position;
    u8 padF0[0x1B8 - 0xF0];
    s32 animation;
    u8 pad1BC[0x33C - 0x1BC];
    f32 f33C;
    u8 pad340[0x368 - 0x340];
    s16 h368;
    u8 pad36A[0x46C - 0x36A];
    u8 b46C;
    u8 pad46D;
    u8 b46E;
    u8 pad46F;
    u8 pad470[0x4A4 - 0x470];
    s32 f4A4;
    u8 pad4A8[0x69C - 0x4A8];
    s32 f69C;
    u8 pad6A0[0xC00 - 0x6A0];
    f32 fC00;
    u8 padC04[0xC0C - 0xC04];
    s32 fC0C;
    u8 padC10[0xC18 - 0xC10];
    f32 fC18;
    u8 padC1C[0x1200 - 0xC1C];
    UpdateObject *tgt;
    u8 pad1204[0x1210 - 0x1204];
    s32 mask;
    u8 pad1214[0x121A - 0x1214];
    u8 b121A;
    u8 pad121B;
    u8 b121C;
    u8 pad121D[0x1224 - 0x121D];
    s32 f1224;
    s32 f1228;
    u8 pad122C[0x147C - 0x122C];
    u8 b147C;
    u8 pad147D[0x16B0 - 0x147D];
    s32 f16B0;
    u8 pad16B4[0x25C0 - 0x16B4];
    UpdateObject *object;
    s32 state;
    u8 pad25C8[4];
    u32 f25CC;
    u8 pad25D0[0x25ED - 0x25D0];
    u8 busy;
    u8 pad25EE[0x28D0 - 0x25EE];
    void *pending;
} UpdateHero;

typedef struct {
    u8 pad[0x530];
} UpdateRow;

typedef struct {
    f32 red, green, blue;
    f32 unknown;
    f32 x, y, z, radius;
} UpdateLight;

extern s32 D_L01_001D6694;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern UpdateHero D_L01_001A4BE0_00356C98;
typedef struct {
    u8 pad0[0x150];
    u16 h150;
    u8 pad152[0x648 - 0x152];
    u16 h648;
} UpdatePad;
extern UpdatePad D_L01_001A7E18_00356C98;
typedef struct { u8 pad0[0x514]; struct { s32 f; u8 pad[0x52C]; } rows[25]; } UpdateTab;
extern UpdateTab D_L01_00284500_00356C98;
extern u8 D_L01_001A30B0_00356C98[];
extern UpdateObject *D_L01_001E1A20_00356C98a[2];
__asm__(".extern D_L01_001E1A20_00356C98a, 16");
extern s32 D_L01_001E1A50;
extern f32 D_L01_001E1A48;
extern UpdateLight D_L01_001F1B40_00356C98[];
extern s32 D_L01_001DD680_sda;
extern s32 D_L01_001DD65C_sda;
extern s32 D_L01_001DD660_sda;
extern s32 D_L01_001DD664_sda;
__asm__(".extern D_L01_001DD680_sda, 4");
__asm__(".extern D_L01_001DD65C_sda, 4");
__asm__(".extern D_L01_001DD660_sda, 4");
__asm__(".extern D_L01_001DD664_sda, 4");

extern void func_003C2880(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D590(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(void *);
extern void func_L01_00357E70(u8 *);
extern void func_L01_0035AEB8(UpdateObject *);
extern s32 func_L01_00424B88_00356C98(vu0_q *p, f32 x, f32 y, s32 color);
extern void func_L01_00424D88(s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_003A4F28(s32);
extern s32 func_L01_004AA710(UpdateObject *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_0038CAD0(s32 *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);

extern void func_L01_00358238(u8 *);
extern void func_L01_00358090(u8 *);
extern void func_L01_00358B00(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void *func_L01_003949E8(s32, vu0_q *, vu0_q *, f32, s32, s32);
extern void func_L01_003D80D0(void *, void *, void *);
extern s32 D_L01_001D673C;
extern s32 D_L01_001DD67C_sda;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
} UpdateFx;
extern UpdateFx D_L01_001E2A40_00356C98;
__asm__(".extern D_L01_001DD67C_sda, 4");

extern u8 *D_L01_001D52FC;
extern s32 func_L01_005119E0(s32);
extern s32 func_L01_00511A98(void);

extern void func_L01_005003D0(s32, s32);
extern void func_L01_004F5AE8(void);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_L01_004606E8(s32, s32, s32 *, s32);
extern s32 func_L01_00460778(s32, s32, s32, s32, s32);
extern void func_003C4138(void *, f32, f32);
extern s32 D_L01_001E1A44;
extern UpdateObject *D_L01_001E1A20_00356C98;
extern UpdateObject *D_L01_001E1A20_00356C98g;
__asm__(".extern D_L01_001E1A20_00356C98g, 4");
extern s32 D_L01_001D6740;
extern s32 D_L01_001DD654_sda;
extern s32 D_L01_001DD658_sda;
extern f32 D_L01_001DD668_sda;
extern f32 D_L01_001DD66C_sda;
extern f32 D_L01_001DD670_sda;
extern f32 D_L01_001DD674_sda;
extern s32 D_L01_001DD678_sda;
__asm__(".extern D_L01_001DD654_sda, 4");
__asm__(".extern D_L01_001DD658_sda, 4");
__asm__(".extern D_L01_001DD668_sda, 4");
__asm__(".extern D_L01_001DD66C_sda, 4");
__asm__(".extern D_L01_001DD670_sda, 4");
__asm__(".extern D_L01_001DD674_sda, 4");
__asm__(".extern D_L01_001DD678_sda, 4");
typedef struct { u8 pad[0x4C]; s32 (*fn)(void); } Vt_00356C98;
extern Vt_00356C98 *func_L01_0043B568(s32, s32, s32);

void func_L01_00356C98(UpdateObject *self)
{
    UpdateVars *vars = self->vars;
    vu0_q m[4];
    struct WeaponRow *row;
    s32 level;
    s32 t;

    if (D_L01_001D6694)
        return;
    level = D_L01_002C5600[D_001425C0[0x7F]].level;
    if (D_L01_001A4BE0_00356C98.pending) {
        func_003C2880(D_L01_001A4BE0_00356C98.pending);
        D_L01_001A4BE0_00356C98.pending = 0;
    }
    if (D_L01_001A4BE0_00356C98.f1228 != 0x7F)
        return;

    if (self->state == 0) {
        s32 i;
        f32 scale;
        self->opacity = 0xFF;
        scale = *(f32 *)(self->class_data + 0x24) * 0.3f;
        self->state = 1;
        self->flags |= 0x100;
        self->scale = scale;
        func_003C2EC0(D_L01_001A4BE0_00356C98.object, 0, m);
        *(vu0_q *)&self->position = m[3];
        func_0038D590(self->matrix, m);
        func_L01_00448E10(self->matrix);
        func_003C7DD8(self);
        func_L01_00357E70((u8 *)self);
        vars->handle = -1;
        D_L01_001E1A50 = 0;
        for (i = 24; i >= 0; i--)
            D_L01_00284500_00356C98.rows[i].f = 0;
        vars->count = (D_L01_001DD680_sda * 5 + 2) / 6;
    }
    func_L01_0035AEB8(self);
    if (D_L01_001DD65C_sda == -1)
        D_L01_001DD65C_sda = func_L01_00424B88_00356C98((vu0_q *)&self->position, 5.5f, 0.0f, 0x4080FF);
    if (!D_L01_001A7E18_00356C98.h150 && !D_L01_001A7E18_00356C98.h648 && level == 0
        && D_L01_001A4BE0_00356C98.f16B0 == 0)
        func_L01_0041A5B0(0xB79, 0x1C);
    if (!D_L01_001A7E18_00356C98.h150 && !D_L01_001A7E18_00356C98.h648 && level == 0
        && D_L01_001A4BE0_00356C98.f16B0 > 0)
        func_L01_0041A5B0(0xCDD, 0x86);

    if (D_L01_001E1A20_00356C98a[1] && ((((u8 *)D_L01_001E1A20_00356C98a[1])[0x34] ^ 1) & 1)) {
        if (vars->level != level) {
            s32 handle = vars->handle;
            if (handle != -1) {
                u8 *slot = D_L01_001A30B0_00356C98 + handle * 128;
                if (*(UpdateObject **)(slot + 0xDC) == self && slot[0xD0])
                    func_003A4F28(handle);
            }
            vars->handle = -1;
        }
        if ((u32)level < 2) {
            D_L01_001DD660_sda = 0x2055FF;
            D_L01_001DD664_sda = 0x5585FF;
            if (!func_L01_004AA710(self, vars->handle))
                vars->handle = func_003A52A0(0, 4, self);
        } else if ((u32)(level - 2) < 2) {
            D_L01_001DD660_sda = 0xFF5520;
            D_L01_001DD664_sda = 0xFF8555;
            if (!func_L01_004AA710(self, vars->handle))
                vars->handle = func_003A52A0(3, 4, self);
        } else if (level >= 4) {
            D_L01_001DD660_sda = 0xFF5520;
            D_L01_001DD664_sda = 0xFF8555;
            if (!func_L01_004AA710(self, vars->handle))
                vars->handle = func_003A52A0(3, 4, self);
        }
    }
    vars->level = level;

    if ((D_L01_001E1A20_00356C98a[1] && (D_L01_001E1A20_00356C98a[1]->flags & 1)) || D_L01_001A4BE0_00356C98.busy) {
        s32 handle = vars->handle;
        if (handle != -1) {
            u8 *slot = D_L01_001A30B0_00356C98 + handle * 128;
            if (*(UpdateObject **)(slot + 0xDC) == self && slot[0xD0])
                func_003A4F28(handle);
        }
        vars->handle = -1;
        if (D_L01_001DD65C_sda != -1) {
            func_L01_00424D88(D_L01_001DD65C_sda);
            D_L01_001DD65C_sda = -1;
        }
    }

    func_0038CAD0(&D_L01_001E1A50);
    m[0] = *(vu0_q *)&self->position;
    if (D_L01_001DD65C_sda >= 0) {
        UpdateLight *light = &D_L01_001F1B40_00356C98[D_L01_001DD65C_sda];
        f32 rate;
        f32 px, py, pz;
        f32 intensity;
        s32 color;
        px = ((f32 *)&m[0])[0];
        py = ((f32 *)&m[0])[1];
        pz = ((f32 *)&m[0])[2];
        light->x = px;
        light->y = py;
        light->z = pz;
        rate = func_003824E0(800.0f, 160.0f);
        D_L01_001E1A48 = func_0038DAB8(D_L01_001E1A48, rate * 0.017453292f * 0.020000001f);
        intensity = func_0038D0B0(D_L01_001E1A48 * 0.1f);
        light = &D_L01_001F1B40_00356C98[D_L01_001DD65C_sda];
        light->radius = intensity * 0.5f + 0.5f + 3.5f;
        intensity = func_0038D0B0(D_L01_001E1A48);
        color = func_0038DBD8(D_L01_001DD660_sda, D_L01_001DD664_sda, intensity * 0.5f + 0.5f);
        light = &D_L01_001F1B40_00356C98[D_L01_001DD65C_sda];
        light->red = (color & 255) * 0.0078125f;
        light->green = ((color >> 8) & 255) * 0.0078125f;
        light->blue = ((color >> 16) & 255) * 0.0078125f;
    }

    if (self->state == 0 || D_L01_001A4BE0_00356C98.f1228 != 0x7F)
        return;

    if (D_L01_001A4BE0_00356C98.state == 0x14 && D_L01_001A4BE0_00356C98.animation == 2)
        D_L01_001DD67C_sda = 1;
    if (D_L01_001DD67C_sda) {
        if (D_L01_001A4BE0_00356C98.state == 0x14 && D_L01_001A4BE0_00356C98.animation == 0x11 && level >= 3) {
            m[1] = D_L01_001A4BE0_00356C98.object->matrix[0];
            func_0038CE20(&m[1], &m[1], 0.75f);
            row = &D_L01_002C5600[D_001425C0[0x7F]];
            func_L01_003949E8((s32)self, (vu0_q *)&self->position, &m[1],
                            row->damage, 0x10000, 0);
            D_L01_001DD67C_sda = 0;
        }
        if (D_L01_001A4BE0_00356C98.state == 0x14 && D_L01_001A4BE0_00356C98.animation == 0x19) {
            D_L01_001E2A40_00356C98.f20 = 0.4f;
            D_L01_001E2A40_00356C98.f28 = 0x15;
            D_L01_001E2A40_00356C98.f2C = 0;
        }
        if (level >= 4 && !D_L01_001D673C && D_L01_001A4BE0_00356C98.state == 0x13) {
            s32 swing = ((u8 *)D_L01_001A4BE0_00356C98.object)[0x42];
            s32 spawn = 0;
            f32 angle = 0.0f;
            if (swing == 0x17) {
                spawn = D_L01_001A4BE0_00356C98.animation == 8;
            } else if (swing == 0x18) {
                spawn = D_L01_001A4BE0_00356C98.animation == 8;
                angle = -0.34906584f;
            } else if (swing == 0x19) {
                spawn = D_L01_001A4BE0_00356C98.animation == 0x19;
                angle = 0.17453292f;
            }
            if (spawn) {
                m[1] = D_L01_001A4BE0_00356C98.object->matrix[0];
                func_0038D890(&m[1], &m[1], &D_L01_001A4BE0_00356C98.object->matrix[2], angle);
                vec_add_ab((vu0_v4 *)&m[2], &D_L01_001A4BE0_00356C98.position, (vu0_v4 *)&D_L01_001A4BE0_00356C98.object->matrix[0]);
                func_L01_003D80D0(self, &m[2], &m[1]);
            }
        }
    }

    if (vars->effect && (u32)(vars->effect->state - 10) >= 2) {
        D_L01_001A4BE0_00356C98.b121C = 0;
        func_003C2880(vars->effect);
        vars->effect = 0;
    }
    if ((*(s32 *)(D_L01_001D52FC + 0x1A4) & D_L01_001A4BE0_00356C98.mask)
        && self->state != 10 && self->state != 11 && !vars->effect
        && func_L01_005119E0(-1) && !func_L01_00511A98()) {
        if (D_L01_001E1A20_00356C98a[1] && ((((u8 *)D_L01_001E1A20_00356C98a[1])[0x34] ^ 1) & 1)
            && !D_L01_001E1A50 && D_L01_001A4BE0_00356C98.state != 0x13) {
            if ((u32)level < 2) {
                D_L01_001E1A50 = 0x15;
                func_003A52A0(1, 0, self);
            } else if ((u32)(level - 2) < 2) {
                D_L01_001E1A50 = 0x15;
                func_003A52A0(4, 0, self);
            } else if (level >= 4) {
                D_L01_001E1A50 = 0x15;
                func_003A52A0(4, 0, self);
            }
        }
        t = 0;
        if (D_L01_001A4BE0_00356C98.f1224 == 2)
            t = D_L01_001A4BE0_00356C98.mask;
        if (!D_L01_001A4BE0_00356C98.b147C) {
            if (D_L01_001A4BE0_00356C98.f25CC < 2 || (D_L01_001A4BE0_00356C98.f25CC == 4 && D_L01_001A4BE0_00356C98.b46C) || D_L01_001A4BE0_00356C98.f25CC == 12) {
                s32 tmp[2];
                if (func_L01_004606E8(t, 8, tmp, 0)) {
                    if (!func_L01_00460778(0x20, 0x80, 8, 4, 0) && D_L01_001A4BE0_00356C98.tgt) {
                        if (D_L01_001A4BE0_00356C98.f1228 == 0x7F) {
                            if (!D_L01_001A4BE0_00356C98.b121A) {
                                if (!(*(s32 *)(D_L01_001D52FC + 0x1A0) & func_003A3BB8(8, 0))
                                    && !((D_L01_001A4BE0_00356C98.state == 1 || D_L01_001A4BE0_00356C98.state == 0x1D || D_L01_001A4BE0_00356C98.f16B0 == 2) && D_L01_001A4BE0_00356C98.animation >= 0x12))
                                    func_L01_005003D0(0x13, 1);
                                else if ((D_L01_001A4BE0_00356C98.state == 1 || D_L01_001A4BE0_00356C98.state == 0x1D || D_L01_001A4BE0_00356C98.f16B0 == 2) && D_L01_001A4BE0_00356C98.animation >= 0x12) {
                                    if (func_L01_005119E0(-1))
                                        func_L01_004F5AE8();
                                } else if (func_L01_005119E0(-1))
                                    func_L01_005003D0(0x15, 1);
                            }
                        }
                    }
                }
            } else {
                s32 k;
                if ((D_L01_001A4BE0_00356C98.state == 7 || D_L01_001A4BE0_00356C98.state == 9 || D_L01_001A4BE0_00356C98.state == 8 || D_L01_001A4BE0_00356C98.state == 6
                     || (D_L01_001A4BE0_00356C98.state == 0xE && 32.0f < D_L01_001A4BE0_00356C98.fC18)
                     || (D_L01_001A4BE0_00356C98.state == 0xB && (((k = D_L01_001A4BE0_00356C98.f4A4) != 3 && 18.0f < D_L01_001A4BE0_00356C98.fC18) || ((k = D_L01_001A4BE0_00356C98.f4A4) == 3 && 20.0f < D_L01_001A4BE0_00356C98.fC18)))
                     || D_L01_001A4BE0_00356C98.state == 0x2C || D_L01_001A4BE0_00356C98.state == 0x11)
                    && D_L01_001A4BE0_00356C98.animation >= 9) {
                    s32 a5 = 0xC;
                    if (D_L01_001A4BE0_00356C98.state == 0xB || D_L01_001A4BE0_00356C98.state == 0xE)
                        a5 = 0xF;
                    if (func_L01_004606E8(t, a5, 0, 0)) {
                        if ((D_L01_001A4BE0_00356C98.b46E == 0 ? 0.1f < D_L01_001A4BE0_00356C98.f33C : 0.57f < D_L01_001A4BE0_00356C98.f33C) || (D_L01_001A4BE0_00356C98.state == 8 && 0.57f < D_L01_001A4BE0_00356C98.f33C)) {
                            if (D_L01_001A4BE0_00356C98.f69C == 0)
                                func_L01_005003D0(0x14, 1);
                        } else
                            func_L01_005003D0(0x13, 1);
                    }
                }
            }
        }
    }

    if (D_L01_001A4BE0_00356C98.f1228 == 0x7F) {
        if ((*(s32 *)(D_L01_001D52FC + 0x1A4) & D_L01_001A4BE0_00356C98.mask) && !func_L01_005119E0(-1))
            func_003A52A0(0, 0, (void *)D_L01_001E1A44);
        if (D_L01_001A4BE0_00356C98.f1228 == 0x7F) {
            if (!vars->effect) {
                *(vu0_q *)vars = ((vu0_q *)D_L01_001E1A20_00356C98)[1];
                ((vu0_q *)D_L01_001E1A20_00356C98)[1] = ((vu0_q *)D_L01_001A4BE0_00356C98.tgt)[1];
                ((vu0_q *)D_L01_001E1A20_00356C98)[12] = ((vu0_q *)D_L01_001A4BE0_00356C98.tgt)[12];
                ((vu0_q *)D_L01_001E1A20_00356C98)[13] = ((vu0_q *)D_L01_001A4BE0_00356C98.tgt)[13];
                ((vu0_q *)D_L01_001E1A20_00356C98)[14] = ((vu0_q *)D_L01_001A4BE0_00356C98.tgt)[14];
                func_003C7DD8(D_L01_001E1A20_00356C98g);
            } else {
                *(vu0_q *)vars = ((vu0_q *)vars->effect)[1];
                ((vu0_q *)D_L01_001E1A20_00356C98)[1] = ((vu0_q *)vars->effect)[1];
                ((vu0_q *)D_L01_001E1A20_00356C98)[12] = ((vu0_q *)vars->effect)[12];
                ((vu0_q *)D_L01_001E1A20_00356C98)[13] = ((vu0_q *)vars->effect)[13];
                ((vu0_q *)D_L01_001E1A20_00356C98)[14] = ((vu0_q *)vars->effect)[14];
                func_003C7DD8(D_L01_001E1A20_00356C98g);
            }
        }
    }

    if (D_L01_001A4BE0_00356C98.state == 0x13) {
        Vt_00356C98 *vt = func_L01_0043B568(0x19E1, 1, 0x6C);
        s32 v = 0;
        if (vt)
            v = vt->fn();
        if (D_L01_001D673C || D_L01_001D6740 || D_L01_001A4BE0_00356C98.h368) {
            if ((D_L01_001DD678_sda * 5 + 2) / 6 < D_L01_001A4BE0_00356C98.animation) {
                vars->f14 = D_L01_001DD668_sda;
                vars->f1C = D_L01_001DD66C_sda;
            } else {
                vars->f14 = D_L01_001DD670_sda;
                vars->f1C = D_L01_001DD674_sda;
            }
        } else if (!v) {
            D_L01_001A4BE0_00356C98.fC00 = 1.1f;
            if (D_L01_001A4BE0_00356C98.animation >= 6) {
                if (((u8 *)D_L01_001A4BE0_00356C98.object)[0x42] == 0x19) {
                    func_003C4138(&vars->f14, 0.6f, 0.24000001f);
                    func_003C4138(&vars->f1C, 0.8f, 0.18f);
                } else {
                    if (D_L01_001DD658_sda)
                        func_003C4138(&vars->f14, 0.9f, 0.24000001f);
                    func_003C4138(&vars->f1C, 0.9f, 0.18f);
                }
            } else {
                if (D_L01_001DD658_sda)
                    vars->f14 = 0.25f;
                vars->f1C = 0.5f;
            }
        } else {
            D_L01_001A4BE0_00356C98.fC00 = 1.1f;
            if (D_L01_001A4BE0_00356C98.animation >= 0xD) {
                if (D_L01_001DD658_sda)
                    func_003C4138(&vars->f14, 0.9f, 0.24000001f);
                if (D_L01_001A4BE0_00356C98.fC0C)
                    vars->f1C = 0.4f;
                else
                    vars->f1C = 0.9f;
                if (((u8 *)D_L01_001A4BE0_00356C98.object)[0x42] == 0x19) {
                    func_003C4138(&vars->f14, 0.3f, 0.22000001f);
                    func_003C4138(&vars->f1C, 0.5f, 0.18f);
                }
            } else {
                if (D_L01_001DD658_sda)
                    func_003C4138(&vars->f14, 0.25f, 0.120000005f);
                func_003C4138(&vars->f1C, 0.5f, 0.040000003f);
            }
        }
    } else if (D_L01_001A4BE0_00356C98.state == 0x14 && D_L01_001A4BE0_00356C98.animation >= 6) {
        Vt_00356C98 *vt = func_L01_0043B568(0x19E1, 1, 0x6C);
        s32 v = 0;
        if (vt)
            v = vt->fn();
        if (!v) {
            if (D_L01_001A4BE0_00356C98.animation >= 0x12) {
                if (D_L01_001DD658_sda)
                    vars->f14 = 0.8f;
                vars->f1C = 0.8f;
            } else {
                if (D_L01_001DD658_sda)
                    func_003C4138(&vars->f14, 0.7f, 0.120000005f);
                func_003C4138(&vars->f1C, 0.7f, 0.040000003f);
            }
        } else {
            if (D_L01_001A4BE0_00356C98.animation >= 0x12) {
                if (D_L01_001DD658_sda)
                    vars->f14 = 0.7f;
                vars->f1C = 0.7f;
            } else {
                if (D_L01_001DD658_sda)
                    func_003C4138(&vars->f14, 0.5f, 0.120000005f);
                func_003C4138(&vars->f1C, 0.5f, 0.040000003f);
            }
        }
    } else {
        if (D_L01_001A4BE0_00356C98.tgt && vars->effect) {
            func_003C4138(&vars->f1C, 0.9f, 0.040000003f);
            func_003C4138(&vars->f14, 0.5f, 0.040000003f);
        } else {
            vars->f14 = *(f32 *)&D_L01_001DD654_sda;
            vars->f1C = 0.0f;
        }
    }

    if (D_L01_001E1A20_00356C98a[1]) {
        UpdateObject **tab = &D_L01_001E1A20_00356C98 + 1;
        s32 i;
        func_L01_00358238((u8 *)self);
        func_L01_00358090((u8 *)self);
        func_L01_00358B00((u8 *)self);
        for (i = 0; i < 9; i++) {
            if ((u32)level < 2) {
                func_L01_0043B9E8((u8 *)tab[i], 0xBF, 0x40, 0x20);
            } else if ((u32)(level - 2) < 2) {
                func_L01_0043B9E8((u8 *)tab[i], 0x20, 0x40, 0xBF);
            } else if (level >= 4) {
                tab[i]->flags &= ~0x200;
                func_L01_0043B9E8((u8 *)tab[i], 0, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_00356C98 */

/* localdecomp:start func_L01_00357E70 */
typedef struct {
    u8 pad0[0x23];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    u16 h34;
} O_00357E70;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0xF0 - 2];
} Ent_00357E70;
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern O_00357E70 *D_L01_001E1A20_00357E70[2];
extern O_00357E70 *D_L01_001E1A20_00357E70g;
__asm__(".extern D_L01_001E1A20_00357E70g, 4");
extern vu0_v4 D_L01_00284320_00357E70[];
extern u8 D_L01_002C5600_00357E70[];
extern u8 D_001425C0[];
extern f32 D_L01_001DD654;
__asm__(".extern D_L01_001DD654, 4");

void func_L01_00357E70(u8 *self) {
    vu0_v4 v;
    vu0_v4 m[4];
    u8 *st = *(u8 **)(self + 0x68);
    s32 i;
    s32 id;
    O_00357E70 **pp;
    Ent_00357E70 *e;

    D_L01_001E1A20_00357E70g = (O_00357E70 *)self;
    func_L01_0043B9E8(self, 0x40, 0x10, 0x80);
    pp = &D_L01_001E1A20_00357E70[1];
    for (i = 1; i < 10; i++) {
        if (i < 9) {
            D_L01_001E1A20_00357E70[i] = (O_00357E70 *)func_003C24B0(0x183A, 0x80);
        } else {
            D_L01_001E1A20_00357E70[i] = (O_00357E70 *)func_003C24B0(0x183C, 0x80);
        }
        func_L01_00456160(D_L01_001E1A20_00357E70[i], self);
        e = (Ent_00357E70 *)(D_L01_002C5600_00357E70 + D_001425C0[0x7F] * 0xF0);
        if (e->b1 < 4) {
            D_L01_001E1A20_00357E70[i]->h34 |= 0x200;
        }
        D_L01_001E1A20_00357E70[i]->b23 = 0x3C;
        if (((Ent_00357E70 *)(D_L01_002C5600_00357E70 + D_001425C0[0x7F] * 0xF0))->b1 == 0) {
            func_L01_0043B9E8((u8 *)D_L01_001E1A20_00357E70[i], 0xBF, 0x40, 0x20);
        } else if (((Ent_00357E70 *)(D_L01_002C5600_00357E70 + D_001425C0[0x7F] * 0xF0))->b1 == 1) {
            func_L01_0043B9E8((u8 *)D_L01_001E1A20_00357E70[i], 0x20, 0x40, 0xBF);
        }
        func_L01_0043B9E8((u8 *)pp[0], 0xBF, 0x40, 0x20);
        *(f32 *)((u8 *)pp[0] + 0x2C) = *(f32 *)(*(u8 **)((u8 *)pp[0] + 0x24) + 0x24) * 0.2f;
        func_L01_0044FD88(pp[-1], pp[0], 0, 0);
        func_003C2EC0(pp[-1], 0, m);
        pp++;
        func_0038CF68(&v, m, 0.1f);
        vec_add_ab(&D_L01_00284320_00357E70[i], &v, &m[3]);
    }
    func_003C2F58(D_L01_001E1A20_00357E70[0], 0, &v);
    *(vu0_q *)st = *(vu0_q *)&v;
    *(f32 *)(st + 0x14) = D_L01_001DD654;
}
/* localdecomp:end func_L01_00357E70 */

/* localdecomp:start func_L01_00358090 */
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern void *D_L01_001E1A20_00358090[2];
extern vu0_v4 D_L01_00284320_00358090[];
extern vu0_v4 D_L01_002843C0_00358090[];
extern f32 D_L01_001DD650;
__asm__(".extern D_L01_001DD650, 4");
extern f32 D_L01_001DD684;
__asm__(".extern D_L01_001DD684, 4");

void func_L01_00358090(u8 *o) {
    vu0_v4 v;
    vu0_v4 t1;
    vu0_v4 t2;
    u8 *st = *(u8 **)(o + 0x68);
    s32 i;
    vu0_v4 *a = D_L01_00284320_00358090;
    vu0_v4 *b = D_L01_002843C0_00358090;
    for (i = 1; i < 10; i++) {
        if (*(f32 *)(st + 0x14) >= D_L01_001DD650) {
            func_003C2F58(D_L01_001E1A20_00358090[i - 1], 0, &v);
            vec_sub_ba(&t1, &a[i], &v);
            vec_sub_ab(&t2, &b[i], &v);
            func_0038CF68(&t2, &t2, *(f32 *)(st + 0x14));
            func_0038CF68(&t1, &t1, *(f32 *)(st + 0x14));
            if (t1.z == 0.0f && t1.x == 0.0f && t1.y == 0.0f) {
                t1 = t2;
            }
            func_L01_0044C280(&t2, &t1, &t2, 0, D_L01_001DD684 + *(f32 *)(st + 0x1C));
            vec_add_ab(&a[i], &v, &t2);
            if (func_L01_004CB2D8()) {
                func_L01_004CAB30(&a[i], &a[i]);
            }
        } else {
            a[i] = b[i];
            if (func_L01_004CB2D8()) {
                func_L01_004CAB30(&a[i], &a[i]);
            }
        }
    }
}
/* localdecomp:end func_L01_00358090 */

/* localdecomp:start func_L01_00358238 */
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void *D_L01_001E1A20_00358238[2];
extern vu0_v4 D_L01_002843C0_00358238[];
extern vu0_v4 D_L01_00284320_00358238[];

void func_L01_00358238(u8 *o) {
    vu0_v4 v;
    vu0_v4 m[4];
    u8 *st = *(u8 **)(o + 0x68);
    s32 i;
    vu0_v4 *a = D_L01_002843C0_00358238;
    vu0_v4 *b = D_L01_00284320_00358238;
    void **p = D_L01_001E1A20_00358238;
    vu0_v4 *e;
    for (i = 0; i < 9; i++) {
        f32 t;
        func_003C2EC0(p[i], 0, m);
        func_0038CF68(&v, m, *(f32 *)(st + 0x14));
        e = &a[i + 1];
        vec_add_ab(e, &v, &m[3]);
        t = func_003C3D30(&b[i + 1], 2, 0, 0.5f) + 0.15f;
        if (e->z < t) e->z = t;
    }
}
/* localdecomp:end func_L01_00358238 */

/* localdecomp:start func_L01_00358338 */
typedef int Q_358338 __attribute__((mode(TI)));
typedef union { f32 f[4]; Q_358338 q; } V_358338;
typedef union { u8 b[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; f32 f[0x980]; void *p[0x980]; Q_358338 q[0x260]; } O_358338;
typedef union { V_358338 v[5]; u8 b[0x50]; } Hit_358338;
extern O_358338 D_001A4BE0;
extern s32 D_L01_001D673C_00358338;
extern s32 D_L01_001D6740_00358338;
extern s32 D_L01_001D6694_00358338;
extern s32 D_L01_001DD680;
extern O_358338 *D_L01_001E1A20;
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_003C7DD8(void *);
extern s32 func_L01_005119E0(s32);
extern s32 func_0038CAD0(s32 *);

void func_L01_00358338(O_358338 *owner, O_358338 *m, s32 kind, V_358338 *pos, s32 count, O_358338 *other) {
    V_358338 newpos;
    Hit_358338 hit;
    V_358338 up, side, dir;
    O_358338 *vars;
    f32 yaw, angle, weight;
    newpos.q = pos->q;
    vars = other->p[0x68/4];
    func_003C2EC0(owner, kind, &hit);
    hit.v[4].q = m->q[1];
    m->q[1] = newpos.q;
    func_003C6FE0(m);
    if (!(m->uh[0x34/2] & 4)) func_003C7C38(m);
    if (D_L01_001D673C_00358338 || D_L01_001D6740_00358338 || D_001A4BE0.h[0x368/2]) {
        func_L01_004C7D98(&m->q[1], &up);
        vec_sub_ba(&dir, &m->q[1], &hit.v[3]);
        func_0038CF68(&dir, &dir, 1.0f);
        func_0038CE90(&side, &dir, &up);
        func_0038CF68(&side, &side, 1.0f);
        func_0038CE90(&up, &side, &dir);
        func_0038CF68(&up, &up, 1.0f);
        m->q[0xC0/16] = dir.q;
        m->q[0xD0/16] = side.q;
        m->q[0xE0/16] = up.q;
    } else {
        yaw = func_0038DAB8(func_0038D160(hit.v[3].f[0] - m->f[0x10/4], hit.v[3].f[1] - m->f[0x14/4]), 3.1415927f);
        if (D_001A4BE0.i[0x25C4/4] == 19) {
            weight = 2 / count;
            vec_sub_ab(&up, &D_L01_001E1A20->q[1], &vars->q[0]);
            angle = func_0038D160(up.f[0], up.f[1]);
            if (count < 5) angle *= weight * 2.0f;
            else if (count > 5) angle = 0.0f;
            yaw = func_0038DAB8(angle, yaw);
        }
        m->f[0xF8/4] = yaw;
        m->f[0xF4/4] = func_0038D160(func_0038CF38(&m->q[1], &hit.v[3]), hit.v[3].f[2] - m->f[0x18/4]);
        if (D_001A4BE0.i[0x25C4/4] == 19) m->i[0xF4/4] = 0;
        m->f[0xF0/4] = 1.5707964f;
        if (D_001A4BE0.i[0x25C4/4] == 19) m->i[0xF0/4] = 0;
        func_0038D308(&m->q[0xC0/16], &m->f[0xF0/4]);
    }
    func_003C7DD8(m);
    if ((owner && (owner->uh[0x34/2] & 1)) || D_001A4BE0.b[0x25ED] || D_001A4BE0.i[0x25C4/4] == 29 || D_001A4BE0.i[0x16B0/4] == 2 || D_L01_001D6694_00358338 || D_001A4BE0.i[0x25C4/4] == 116) {
        m->uh[0x34/2] |= 0x41;
    } else if (func_L01_005119E0(-1)) {
        m->uh[0x34/2] &= 0xFFBE;
    }
    if ((D_001A4BE0.i[0x16B0/4] || D_001A4BE0.i[0x25C4/4] == 29) && vars->i[0x20/4]) m->uh[0x34/2] &= 0xFFBE;
    if (!func_L01_005119E0(-1) && !vars->i[0x20/4]) {
        if (func_0038CAD0(&vars->i[0x30/4])) m->uh[0x34/2] |= 0x41;
    } else vars->i[0x30/4] = (D_L01_001DD680 * 5 + 2) / 6;
    m->uh[0x34/2] |= 6;
}
/* localdecomp:end func_L01_00358338 */
