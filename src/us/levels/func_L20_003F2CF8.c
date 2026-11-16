#include "common.h"

/* NTSC-U counterpart of func_L20_003F4E60 (src/levels/20_final_boss/L20_003F4CC8.c) */
#include "vu0.h"

/* localdecomp:start func_L20_003F2CF8 */
#include "vu0.h"
typedef int q_003F4E60 __attribute__((mode(TI)));
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[4];
    f32 xC;
    vu0_v4 v10;
    vu0_v4 v20;
    s32 x30;
    u8 pad34[4];
    s32 x38;
    u8 *x3C;
    s32 x40[3];
    s32 x4C;
    s32 x50;
    u8 pad54[4];
    s32 x58;
} P_003F4E60;
typedef struct { u8 pad0[0x30]; f32 x30; s16 x34; } O_003F4E60;
typedef struct { u8 pad0[0x30]; vu0_v4 v; u8 pad1[0x40]; } A_003F4E60;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad1[0x48]; u8 *x68; u8 pad2[0x94]; } M_003F4E60;
extern s32 D_L20_001D6694_003F2CF8;
__asm__(".extern D_L20_001D6694_003F2CF8, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_L20_001DBD6C;
__asm__(".extern D_L20_001DBD6C, 16");
extern f32 D_L20_001DBD68;
__asm__(".extern D_L20_001DBD68, 16");
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern A_003F4E60 *D_L20_001E0380_003F2CF8;
__asm__(".extern D_L20_001E0380_003F2CF8, 16");
extern M_003F4E60 *D_L20_001E029C_003F2CF8;
__asm__(".extern D_L20_001E029C_003F2CF8, 16");
void func_L20_003F3090(u8 *self, vu0_v4 *out);
extern f32 func_00388800(void *, void *);
extern void func_00388880(void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_003F0980(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039C710(void);
void func_L20_003F2CF8(u8 *self) {
    P_003F4E60 *p;
    f32 scale;
    f32 t;
    u8 *hero;
    vu0_v4 v;
    u8 *cam;
    p = *(P_003F4E60 **)(self + 0x68);
    if (D_L20_001D6694_003F2CF8 == 2) {
        return;
    }
    switch (self[0x20]) {
    case 0:
        p->x30 = -1;
        self[0x30] = 0xFF;
        func_L20_003F3090(self, &p->v20);
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1: {
        A_003F4E60 *a;
        M_003F4E60 *m;
        M_003F4E60 *n;
        O_003F4E60 *o;
        vu0_v4 d;
        f32 dist;
        hero = D_001A4BE0;
        if (*(s32 *)(hero + 0x25C4) != 0x86) {
            break;
        }
        func_L20_003F3090(self, &p->v20);
        if (++p->x4C >= 3) {
            p->x4C = 0;
        }
        scale = 0.5f;
        a = &D_L20_001E0380_003F2CF8[p->x40[p->x4C]];
        v = a->v;
        m = &D_L20_001E029C_003F2CF8[p->x50];
        *(q_003F4E60 *)&m->pos = *(q_003F4E60 *)&v;
        *(q_003F4E60 *)(m->x68 + 0x400) = *(q_003F4E60 *)&v;
        n = &D_L20_001E029C_003F2CF8[p->x4];
        o = (O_003F4E60 *)n->x68;
        o->x30 = o->x34;
        if (D_001D545C == 0x10) {
            scale = 0.3f;
        }
        dist = func_00388800(hero + 0x80, &p->v20);
        vec_sub_ba(&d, &p->v20, hero + 0x80);
        d.z = 0.0f;
        t = D_L20_001DBD6C * 0.00027777778450399637f * dist * scale / D_L20_001DBD68;
        func_00388880(&p->v10, &d, sqrt_asm((t + t) * dist));
        func_00388880(hero + 0xF0, hero + 0xF0, 0.0f);
        p->xC = t;
        func_L01_00441FB8(self, 2, -1);
        break;
    }
    case 2:
        cam = D_001CCFD0;
        if (*(s16 *)(cam + 0x76) == 0 && *(s16 *)(cam + 0x9E) == 3 && *(s16 *)(cam + 0x98) < 7000) {
            p->x58 = 1;
            func_0039C710();
        }
        hero = D_001A4BE0;
        if (*(s32 *)(hero + 0x25C4) == 0x86) {
            u8 *h;
            scale = func_003887A0(&p->v10);
            if (func_00388800(hero + 0x80, &p->v20) < 0.5f) {
                scale = 0.0f;
            } else if (scale != 0.0f) {
                vec_sub_ba(&v, &p->v20, hero + 0x80);
                v.z = 0.0f;
                if (func_00388730(&v, &p->v10) < 0.0f) {
                    scale = 0.0f;
                }
            }
            scale -= p->xC;
            func_00388880(&p->v10, &p->v10, scale);
            func_00388880(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, 0.0f);
            *(q_003F4E60 *)(D_001A4BE0 + 0x100) = *(q_003F4E60 *)&p->v10;
            h = D_001A4BE0;
            *(f32 *)(h + 0x10C) = 0.0f;
            if (scale != 0.0f) {
                *(f32 *)(h + 0x1A0) = func_00388A28(p->v10.x, p->v10.y);
            }
            *(s16 *)(h + 0x1DC) = 10;
        } else {
            if (p->x38 != 0) {
                *(s16 *)(p->x3C + 0x1A) = 0;
                func_L01_003F0980(0, (s32)p->x3C);
                p->x38 = 0;
            }
            func_L01_00441FB8(self, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L20_003F2CF8 */
