#include "common.h"

/* NTSC-U counterpart of func_L18_003543C8 (src/levels/shared/L18_00350FB0.c) */
extern s32 D_001D545C;

/* localdecomp:start func_L18_003537C0 */
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
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001DD400_sda;
__asm__(".extern D_001DD400_sda, 4");
extern u8 D_001DD348_sda[8];
__asm__(".extern D_001DD348_sda, 8");
extern u8 *func_L01_00444358(void *, s32, s32);
extern void func_003DF7C0(s32);
extern s32 func_003883C8(void *);
extern void func_L18_00352BE0(void *);
extern void func_L18_00350468(void *);
extern void func_L01_004EA040(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L18_00353350(void *, s32, void *);
extern void func_L18_00353648(void *);
extern void func_L01_004FC518(s32, s32);

void func_L18_003537C0(Obj_3543C8 *obj) {
    Vars_3543C8 *vars = (Vars_3543C8 *)obj->vars;
    u8 *hit = func_L01_00444358(obj, 1, 0);
    func_003DF7C0(0x1E);
    func_003883C8(&vars->hurt);
    if (hit != 0) {
        if (vars->hurt <= 0) {
            if (obj->state != 9) {
                if (obj->state != 10) {
                    f32 dmg = *(f32 *)(hit + 0x2C);
                    vars->hurt = 60;
                    vars->hp = vars->hp - dmg;
                    func_L18_00352BE0(obj);
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
        if (obj->timer >= 0x79) {
            obj->w98 = *(s32 *)(obj->def + 0x10);
            obj->flags = obj->flags & 0xFFBE;
            if (vars->w80 == 0) {
                obj->state = 0;
            } else {
                func_L18_00350468(obj);
                func_L01_004EA040();
                vars->b382 = 1;
                obj->state = 0;
            }
            func_L01_00441FB8(obj, 0, 3);
            obj->pos = vars->q400;
            obj->pos2 = vars->q410;
            vars->hp = (f32)vars->maxhp;
        }
    } else if (obj->state == 9) {
        func_L18_00353350(obj, 6, D_001DD348_sda);
        if (obj->timer > D_001DD400_sda) {
            obj->state = 10;
            func_L01_00441FB8(obj, 0, 8);
            obj->w98 = 0;
            obj->flags = obj->flags | 0x41;
            func_L18_00353648(obj);
            if (D_001D545C == 0x14) {
                func_L01_004FC518(0x86, 1);
            }
        }
    }
}
/* localdecomp:end func_L18_003537C0 */
