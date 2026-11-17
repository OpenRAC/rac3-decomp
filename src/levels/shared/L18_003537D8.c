#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* declared by functions of L18_00350FB0.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L18_003537D8 */
s32 func_L18_003537D8(u8 *obj) {
    return obj[149] == 5;
}
/* localdecomp:end func_L18_003537D8 */

/* localdecomp:start func_L18_003537E8 */
typedef struct {
    f32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_003537E8;

extern S_003537E8 D_L18_001E2AC0[];
extern void func_L01_003F1F20(s32, s32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L18_003537E8(void *obj) {
    ((s32 (*)(s32, s32))func_L01_003F1F20)(18, 0);
    D_L18_001E2AC0[2].f8 = 25;
    D_L18_001E2AC0[3].f8 = 25;
    D_L18_001E2AC0[2].f0 = 0.5f;
    D_L18_001E2AC0[3].f0 = 0.2f;
    D_L18_001E2AC0[4].f0 = 0.02f;
    D_L18_001E2AC0[4].f8 = 25;
    D_L18_001E2AC0[2].fC = 0;
    func_003A52A0(6, 0, obj);
}
/* localdecomp:end func_L18_003537E8 */

/* localdecomp:start func_L18_00353870 */
typedef struct Vars_353870 {
    u8 pad0[0x290];
    u8 v290[0x20];
    f32 f2B0;
    u8 pad2B4[0x430 - 0x2B4];
    s8 h430;
    s8 h431;
    s8 h432;
    s8 h433;
    s32 state;
    f32 f438;
} Vars_353870;

extern u8 D_001A30B0[];
extern f32 D_001A6E44 __attribute__((section(".data")));
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A53E8(s32, s32);
extern void func_L01_004AB048(s32, s32);
extern s32 func_L01_00448070(s32, s32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);

void func_L18_00353870(Obj_3543C8 *self) {
    Vars_353870 *v = (Vars_353870 *)self->vars;
    s32 state = v->state;
    f32 s;

    switch (state) {
    case 2:
        if (self->state != 10 && self->state != 7 && self->state != 8) {
            v->state = 1;
        }
        break;
    case 1:
        if (func_L18_003537D8((u8 *)self) == state) {
            {
                s32 h = v->h431;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h431 = -1;
            }
            v->state = 0;
            break;
        }
        if (self->state == 10) {
            {
                s32 h = v->h431;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h431 = -1;
            }
            {
                s32 h = v->h432;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h432 = -1;
            }
            {
                s32 h = v->h430;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h430 = -1;
            }
            {
                s32 h = v->h433;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h433 = -1;
            }
            func_003A52A0(0, 0, self);
            v->state = 2;
            break;
        }
        {
            s32 h = v->h431;
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(void **)(e + 0xDC) != self) || e[0xD0] == 0) {
                v->h431 = func_003A52A0(3, 4, self);
            }
        }
        {
            s32 h = v->h431;
            if (h != -1) {
                u8 *e = D_001A30B0 + (h << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    func_003A53E8(h, 0x300);
                }
            }
        }
        break;
    case 0:
        if (func_L18_003537D8((u8 *)self) == 0) {
            {
                s32 h = v->h432;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h432 = -1;
            }
            {
                s32 h = v->h430;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h430 = -1;
            }
            {
                s32 h = v->h433;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h433 = -1;
            }
            v->state = 1;
            break;
        }
        if (self->state == 10) {
            {
                s32 h = v->h432;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h432 = -1;
            }
            {
                s32 h = v->h430;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h430 = -1;
            }
            {
                s32 h = v->h433;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h433 = -1;
            }
            func_003A52A0(0, 0, self);
            v->state = 2;
            break;
        }
        {
            s32 h = v->h430;
            u8 *e;
            if (h == -1 || (e = D_001A30B0 + (h << 7), *(void **)(e + 0xDC) != self) || e[0xD0] == 0) {
                v->h430 = func_003A52A0(2, 4, self);
            }
        }
        {
            s32 h = v->h433;
            if (h != -1) {
                u8 *e = D_001A30B0 + (h << 7);
                if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                    f32 f = func_0038CEA8(v->v290);
                    f32 g;
                    s32 vol;
                    v->f438 = func_0038DAB8(v->f438, 0.07853982f);
                    g = func_0038D0B0(v->f438);
                    vol = func_L01_00448070(-0x17D, 0x477, f);
                    func_L01_004AB048(v->h430, vol + (s32)(g * 40.0f));
                    func_003A53E8(v->h430, 0x300);
                }
            }
        }
        s = fabs_asm(v->f2B0);
        if (s > 1e-05f) {
            s32 vol;
            {
                s32 h = v->h433;
                u8 *e;
                if (h == -1 || (e = D_001A30B0 + (h << 7), *(void **)(e + 0xDC) != self) || e[0xD0] == 0) {
                    v->h433 = func_003A52A0(5, 4, self);
                }
            }
            s = s * 3.3333333f;
            vol = func_L01_00448070(0x28A, 0x348, s);
            {
                s32 h = v->h433;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        s32 pitch;
                        func_003A53E8(h, vol);
                        pitch = func_L01_00448070(0, 0x2FA, s);
                        func_L01_004AB048(v->h433, pitch);
                    }
                }
            }
        } else {
            {
                s32 h = v->h433;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h433 = -1;
            }
        }
        s = D_001A6E44;
        if (s > 0.0001f) {
            {
                s32 h = v->h432;
                u8 *e;
                if (h == -1 || (e = D_001A30B0 + (h << 7), *(void **)(e + 0xDC) != self) || e[0xD0] == 0) {
                    v->h432 = func_003A52A0(4, 4, self);
                }
            }
            {
                s32 h = v->h432;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        s32 vol = func_L01_00448070(0, 0x200, s);
                        s32 pitch = func_L01_00448070(-0xFE, 0xFE, s);
                        func_003A53E8(v->h432, vol);
                        func_L01_004AB048(v->h432, pitch);
                    }
                }
            }
        } else {
            {
                s32 h = v->h432;
                if (h != -1) {
                    u8 *e = D_001A30B0 + (h << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(h);
                    }
                }
                v->h432 = -1;
            }
        }
        break;
    }
}
/* localdecomp:end func_L18_00353870 */

INCLUDE_ASM("asm/levels", func_L18_00353F58);

/* localdecomp:start func_L18_00354198 */
typedef struct {
    void (*fn0)(void *);
} Iface;

typedef struct {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x80 - 0x34];
    s32 unk80;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
    char pad6C[0x96 - 0x6C];
    s16 unk96;
} Moby;

extern Moby *D_001A65C0[];
extern s32 D_001D545C;
extern void func_L18_00351068(Moby *);
extern void func_L01_003F1F20(s32, s32);
extern Iface *func_L01_0043B548(s32, s32);

void func_L18_00354198(Moby *m, s32 arg1) {
    Vars *v = m->vars;

    if (D_001A65C0[0] == m) {
        if (v->unk30 > 0.0f || D_001D545C == 20) {
            func_L18_00351068(m);
        }
        func_L01_003F1F20(28, 0);
    }
    if (v->unk80 != 0) {
        if (arg1 == 0) {
            func_L01_0043B548(6625, 108)->fn0(m);
        }
    } else {
        m->unk96 = 0;
    }
}
/* localdecomp:end func_L18_00354198 */

/* localdecomp:start func_L18_00354250 */
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *, s32, void *, s32, s32, f32, f32, f32, f32, f32, s32, f32, f32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);

/* from the NTSC-U draft of func_L18_00353648 */
void func_L18_00354250(void *arg0) {
    u8 *a0 = arg0;
    vu0_v4 v;
    u8 *s = *(u8 **)(a0 + 0x68);
    func_L01_003303B8(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.5f, 10.0f, 0.0f, 2.0f,
                      0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_0038CF68(&v, s + 0x290, 0.10000001f);
    func_L01_00452310(a0, 0x3FF, &v, 1, 0x23, -1.0f, 3.0f, 6.0f, 5.0f, 15.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_003A52A0(0, 0, a0);
    func_L18_00354198(arg0, 1);
}
/* localdecomp:end func_L18_00354250 */

/* localdecomp:start func_L18_003543C8 */
/* PAL port of the NTSC-U match src/us/levels/func_L18_003537C0.c */
extern s32 D_001D545C;

extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L18_001DD3C0;
__asm__(".extern D_L18_001DD3C0, 4");
extern u8 D_L18_001DD308[8];
__asm__(".extern D_L18_001DD308, 8");
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_003E4D10(s32);
extern s32 func_0038CB00(void *);
extern void func_L18_003537E8(void *);
extern void func_L18_00351068(Moby *);
extern void func_L01_004EDE10(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L18_00353F58(void *, s32, void *);
extern void func_L18_00354250(void *);
extern void func_L01_005003D0(s32, s32);

void func_L18_003543C8(Obj_3543C8 *obj) {
    Vars_3543C8 *vars = (Vars_3543C8 *)obj->vars;
    u8 *hit = func_L01_00447490(obj, 1, 0);
    func_003E4D10(25);
    func_0038CB00(&vars->hurt);
    if (hit != 0) {
        if (vars->hurt <= 0) {
            if (obj->state != 9) {
                if (obj->state != 10) {
                    f32 dmg = *(f32 *)(hit + 0x2C);
                    vars->hurt = 50;
                    vars->hp = vars->hp - dmg;
                    func_L18_003537E8(obj);
                    if (vars->hp < 0.0f) vars->hp = 0.0f;
                    if (vars->hp <= 0.0f) {
                        obj->state = 9;
                        obj->timer = 0;
                    }
                }
            }
        }
        obj->alpha = 0xFF;
    }
    if (obj->state == 10) {
        if (obj->timer >= 101) {
            obj->w98 = *(s32 *)(obj->def + 0x10);
            obj->flags = obj->flags & 0xFFBE;
            if (vars->w80 == 0) {
                obj->state = 0;
            } else {
                func_L18_00351068(obj);
                func_L01_004EDE10();
                vars->b382 = 1;
                obj->state = 0;
            }
            func_L01_004450F0(obj, 0, 3);
            obj->pos = vars->q400;
            obj->pos2 = vars->q410;
            vars->hp = (f32)vars->maxhp;
        }
    } else if (obj->state == 9) {
        func_L18_00353F58(obj, 6, D_L18_001DD308);
        if (obj->timer > (D_L18_001DD3C0 * 5 + 2) / 6) {
            obj->state = 10;
            func_L01_004450F0(obj, 0, 8);
            obj->w98 = 0;
            obj->flags = obj->flags | 0x41;
            func_L18_00354250(obj);
            if (D_001D545C == 0x14) {
                func_L01_005003D0(0x86, 1);
            }
        }
    }
}
/* localdecomp:end func_L18_003543C8 */

INCLUDE_ASM("asm/levels", func_L18_003545D0);

/* localdecomp:start func_L18_00354C60 */
typedef struct M_00354C60 {
    u8 pad[0x100];
} M_00354C60;

typedef struct V_00354C60 {
    u8 pad0[0x300];
    f32 x300;
    f32 x304;
    s32 list[18];
    u8 pad350[0xEC];
    s32 x43C;
    u8 x440;
    u8 pad441[3];
    f32 x444;
} V_00354C60;

extern s16 *D_L18_0021DEA0[];
extern M_00354C60 *D_L18_001E009C_00354C60;
extern s32 D_L18_001E00D8;

void func_L18_00354C60(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 0x68);
    V_00354C60 *v = *(V_00354C60 **)(a0 + 0x68);

    if (*(s32 *)(s + 0x2C) != -1) {
        s16 *p = D_L18_0021DEA0[*(s32 *)(s + 0x2C)];
        s32 i = 0;
        for (;;) {
            s32 n = *(s32 *)(s + 0x2C);
            M_00354C60 *m;
            if ((n & 0xFF) == 0xFF || n > D_L18_001E00D8 || p == 0 ||
                (p[-1] < 0 && p != D_L18_0021DEA0[n])) {
                break;
            }
            m = &D_L18_001E009C_00354C60[*p & 0x7FFF];
            if (m == 0 || i >= 18) {
                break;
            }
            v->list[i] = m - D_L18_001E009C_00354C60;
            i++;
            p++;
        }
    }
    v->x43C = *(s32 *)(s + 0x68);
    if (*(f32 *)(s + 0x4) > 0.0f) {
        v->x300 = *(f32 *)(s + 0x4);
    }
    if (*(f32 *)(s + 0xC) > 0.0f) {
        v->x304 = *(f32 *)(s + 0xC);
    }
    v->x440 = s[0x1C];
    v->x444 = *(f32 *)(s + 0x60);
}
/* localdecomp:end func_L18_00354C60 */
