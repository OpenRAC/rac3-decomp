#include "common.h"

/* localdecomp:start func_L20_003F4CC8 */
#include "vu0.h"
extern s32 D_L20_001DEBF0;
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_0038CF68(void *, void *, f32);
void func_L20_003F4CC8(u8 *self) {
    s32 *p;
    u8 *q;
    vu0_v4 d;
    p = *(s32 **)(self + 0x68);
    if (*p != 0 && self[0x20] == 0) {
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & ~0x1000;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004AA7E8(self, 1);
        self[0x20] = 1;
    }
    if (self[0x20] == 1 && D_L20_001DEBF0 != 0) {
        q = *(u8 **)(self + 0x24);
        *(u16 *)(self + 0x34) &= ~0x41;
        *(u16 *)(self + 0x34) |= *(u16 *)(q + 0x44) & 0x1000;
        *(s32 *)(self + 0x98) = *(s32 *)(q + 0x10);
        *p = 0;
        self[0x20] = 0;
    }
    if (func_L01_00456250(self) != 0) {
        self[0x20] = 2;
    }
    if (self[0x20] == 2) {
        func_0038CF68(&d, self + 0xC0, -0.16000001f);
        vec_add_ba(self + 0x10, &d, self + 0x10);
        if (++*(u16 *)(self + 0x96) > 50) {
            self[0x20] = 3;
        }
    }
    if (self[0x20] == 3 && D_L20_001DEBF0 != 0) {
        self[0x20] = 4;
    }
    if (self[0x20] == 4) {
        func_0038CF68(&d, self + 0xC0, 0.16000001f);
        vec_add_ba(self + 0x10, &d, self + 0x10);
        if (--*(u16 *)(self + 0x96) == 0) {
            self[0x20] = 5;
        }
    }
}
/* localdecomp:end func_L20_003F4CC8 */

/* localdecomp:start func_L20_003F4E60 */
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
extern s32 D_L20_001D6694;
__asm__(".extern D_L20_001D6694, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_L20_001DBD2C;
__asm__(".extern D_L20_001DBD2C, 16");
extern f32 D_L20_001DBD28;
__asm__(".extern D_L20_001DBD28, 16");
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern A_003F4E60 *D_L20_001E0380_003F4E60;
__asm__(".extern D_L20_001E0380_003F4E60, 16");
extern M_003F4E60 *D_L20_001E029C_003F4E60;
__asm__(".extern D_L20_001E029C_003F4E60, 16");
void func_L20_003F51F8(u8 *self, vu0_v4 *out);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_003F2AF8(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A1798(void);
void func_L20_003F4E60(u8 *self) {
    P_003F4E60 *p;
    f32 scale;
    f32 t;
    u8 *hero;
    vu0_v4 v;
    u8 *cam;
    p = *(P_003F4E60 **)(self + 0x68);
    if (D_L20_001D6694 == 2) {
        return;
    }
    switch (self[0x20]) {
    case 0:
        p->x30 = -1;
        self[0x30] = 0xFF;
        func_L20_003F51F8(self, &p->v20);
        func_L01_004450F0(self, 1, -1);
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
        func_L20_003F51F8(self, &p->v20);
        if (++p->x4C >= 3) {
            p->x4C = 0;
        }
        scale = 0.5f;
        a = &D_L20_001E0380_003F4E60[p->x40[p->x4C]];
        v = a->v;
        m = &D_L20_001E029C_003F4E60[p->x50];
        *(q_003F4E60 *)&m->pos = *(q_003F4E60 *)&v;
        *(q_003F4E60 *)(m->x68 + 0x400) = *(q_003F4E60 *)&v;
        n = &D_L20_001E029C_003F4E60[p->x4];
        o = (O_003F4E60 *)n->x68;
        o->x30 = o->x34;
        if (D_001D545C == 0x10) {
            scale = 0.3f;
        }
        dist = func_0038CF38(hero + 0x80, &p->v20);
        vec_sub_ba(&d, &p->v20, hero + 0x80);
        d.z = 0.0f;
        t = D_L20_001DBD2C * 0.00040000002f * dist * scale / D_L20_001DBD28;
        func_0038CFB8(&p->v10, &d, sqrt_asm((t + t) * dist));
        func_0038CFB8(hero + 0xF0, hero + 0xF0, 0.0f);
        p->xC = t;
        func_L01_004450F0(self, 2, -1);
        break;
    }
    case 2:
        cam = D_001CCFD0;
        if (*(s16 *)(cam + 0x76) == 0 && *(s16 *)(cam + 0x9E) == 3 && *(s16 *)(cam + 0x98) < 7000) {
            p->x58 = 1;
            func_003A1798();
        }
        hero = D_001A4BE0;
        if (*(s32 *)(hero + 0x25C4) == 0x86) {
            u8 *h;
            scale = func_0038CED8(&p->v10);
            if (func_0038CF38(hero + 0x80, &p->v20) < 0.5f) {
                scale = 0.0f;
            } else if (scale != 0.0f) {
                vec_sub_ba(&v, &p->v20, hero + 0x80);
                v.z = 0.0f;
                if (func_0038CE68(&v, &p->v10) < 0.0f) {
                    scale = 0.0f;
                }
            }
            scale -= p->xC;
            func_0038CFB8(&p->v10, &p->v10, scale);
            func_0038CFB8(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, 0.0f);
            *(q_003F4E60 *)(D_001A4BE0 + 0x100) = *(q_003F4E60 *)&p->v10;
            h = D_001A4BE0;
            *(f32 *)(h + 0x10C) = 0.0f;
            if (scale != 0.0f) {
                *(f32 *)(h + 0x1A0) = func_0038D160(p->v10.x, p->v10.y);
            }
            *(s16 *)(h + 0x1DC) = 8;
        } else {
            if (p->x38 != 0) {
                *(s16 *)(p->x3C + 0x1A) = 0;
                func_L01_003F2AF8(0, (s32)p->x3C);
                p->x38 = 0;
            }
            func_L01_004450F0(self, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L20_003F4E60 */

/* localdecomp:start func_L20_003F51F8 */
#include "vu0.h"
typedef int u128_003F51F8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x30]; u128_003F51F8 v; u8 pad1[0x40]; } A_003F51F8;
typedef struct { u8 pad0[0x10]; u128_003F51F8 pos; u8 pad1[0xB0]; u8 xD0[0x30]; } M_003F51F8;
extern A_003F51F8 *D_L20_001E0380;
__asm__(".extern D_L20_001E0380, 16");
extern M_003F51F8 *D_L20_001E029C;
__asm__(".extern D_L20_001E029C, 16");
extern void func_0038CF68(void *, void *, f32);
void func_L20_003F51F8(u8 *self, vu0_v4 *out) {
    s32 *p;
    vu0_v4 off;
    p = *(s32 **)(self + 0x68);
    if (p[1] == -1) {
        *(u128_003F51F8 *)out = D_L20_001E0380[p[0]].v;
    } else {
        *(u128_003F51F8 *)out = D_L20_001E029C[p[1]].pos;
        func_0038CF68(&off, D_L20_001E029C[p[1]].xD0, 5.0f);
        vec_add_ab(out, out, &off);
    }
}
/* localdecomp:end func_L20_003F51F8 */
