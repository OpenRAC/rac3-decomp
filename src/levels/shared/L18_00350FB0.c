#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L18_00350FB0);

INCLUDE_ASM("asm/levels", func_L18_00351068);

INCLUDE_ASM("asm/levels", func_L18_00351298);

/* localdecomp:start func_L18_003514B8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
void func_L18_003514B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    *(u128_t *)(s + 752) = *(u128_t *)(s + 960);
    func_0038CE90(s + 736, s + 752, s + 720);
    func_0038CF68(s + 736, s + 736, 1.0f);
    func_0038CE90(s + 720, s + 736, s + 752);
    *(s32 *)(s + 732) = 0;
    *(s32 *)(s + 748) = 0;
    *(s32 *)(s + 764) = 0;
}
/* localdecomp:end func_L18_003514B8 */

INCLUDE_ASM("asm/levels", func_L18_00351548);

INCLUDE_ASM("asm/levels", func_L18_00351908);

INCLUDE_ASM("asm/levels", func_L18_00352288);

INCLUDE_ASM("asm/levels", func_L18_00352350);

INCLUDE_ASM("asm/levels", func_L18_00352AF8);

INCLUDE_ASM("asm/levels", func_L18_00352D30);

INCLUDE_ASM("asm/levels", func_L18_00353110);

INCLUDE_ASM("asm/levels", func_L18_00353138);

INCLUDE_ASM("asm/levels", func_L18_00353280);

INCLUDE_ASM("asm/levels", func_L18_00353658);

/* localdecomp:start func_L18_003537D8 */
s32 func_L18_003537D8(u8 *obj) {
    return obj[149] == 5;
}
/* localdecomp:end func_L18_003537D8 */

INCLUDE_ASM("asm/levels", func_L18_003537E8);

INCLUDE_ASM("asm/levels", func_L18_00353870);

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

INCLUDE_ASM("asm/levels", func_L18_00354250);

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

INCLUDE_ASM("asm/levels", func_L18_00354C60);
