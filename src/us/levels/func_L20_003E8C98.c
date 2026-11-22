#include "common.h"

/* NTSC-U counterpart of func_L20_003EABD8 (src/levels/20_final_boss/L20_003E6150.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BD360(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00402498(void (*)(void *), void *);
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);
extern void func_L01_00402498(void (*)(void *), void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern f32 func_00388A28(f32, f32);

/* localdecomp:start func_L20_003E8C98 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EABD8;
typedef struct {
    u8 p0[0x10];
    V4_003EABD8 pos;
    u8 state;
    u8 p21[3];
    u8 *cls;
    u8 p28[8];      /* 0x2C: scale, written through an offset (see the log) */
    u8 p30[4];
    u16 flags;
    u8 p36[0x32];
    u8 *vars;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0xE];
    s16 oclass;
    u8 pAC[0xC];
    u8 *owner;
    u8 pBC[4];
    u8 mtx[0x30];
    f32 rot[4];
} M_003EABD8;
typedef struct {
    V4_003EABD8 v;
    u8 p10[8];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 p1C[4];
    s32 w20;
    u8 p24[0xC];
} S_003EABD8;

extern void func_00388830(void *, void *, f32);
extern void func_L01_00449008(void *, void *, void *, s32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_00388398(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L20_003E95A0(void *pv, void *qv);
extern void func_003BD360(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00402498(void (*)(void *), void *);
extern void func_L20_003E9B58(void);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L01_004C76F0(void);
extern s32 func_L01_003F9498(void *, s32, f32, void *);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern void func_L01_00452F40(void *, s32);
extern void *func_L20_003EC788(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_00388770(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_00388BD0(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L20_003E98F8(u8 *arg0, u8 *arg1);
extern s32 D_L20_001DF2C0_003E8C98;
__asm__(".extern D_L20_001DF2C0_003E8C98, 4");
extern f32 D_L20_001DF2D4_003E8C98;
__asm__(".extern D_L20_001DF2D4_003E8C98, 4");
extern s32 D_L20_001DF2C4;
__asm__(".extern D_L20_001DF2C4, 4");
extern s32 D_L20_001DF2C8_003E8C98;
__asm__(".extern D_L20_001DF2C8_003E8C98, 4");
extern s32 D_L20_001DF2CC_003E8C98;
__asm__(".extern D_L20_001DF2CC_003E8C98, 4");
extern s32 D_L20_001DF2D0_003E8C98;
__asm__(".extern D_L20_001DF2D0_003E8C98, 4");
extern f32 D_L20_001DF2D8_003E8C98;
__asm__(".extern D_L20_001DF2D8_003E8C98, 4");
extern f32 D_L20_001DF2DC_003E8C98;
__asm__(".extern D_L20_001DF2DC_003E8C98, 4");
extern f32 D_L20_001DF2E0_003E8C98;
__asm__(".extern D_L20_001DF2E0_003E8C98, 4");
extern f32 D_L20_001DF2E4_003E8C98;
__asm__(".extern D_L20_001DF2E4_003E8C98, 4");
extern f32 D_L20_001DF2E8_003E8C98;
__asm__(".extern D_L20_001DF2E8_003E8C98, 4");
extern f32 D_L20_001DF2EC_003E8C98;
__asm__(".extern D_L20_001DF2EC_003E8C98, 4");
extern f32 D_L20_001DF2F0;
__asm__(".extern D_L20_001DF2F0, 4");
extern s32 D_L20_001DF2F4;
__asm__(".extern D_L20_001DF2F4, 4");
extern s16 D_L20_001DF300;
__asm__(".extern D_L20_001DF300, 16");
extern s16 D_L20_001DF302;
__asm__(".extern D_L20_001DF302, 16");
extern u8 D_L20_001D9BE0[];
extern u8 *D_L20_001E9BD8_003E8C98[];
extern s32 D_L20_001EDC40_003E8C98[];
extern u8 D_001A4BE0[];

void func_L20_003E8C98(M_003EABD8 *m) {
    u8 *pv = m->vars;
    V4_003EABD8 tmp;
    S_003EABD8 s;
    V4_003EABD8 dir;
    f32 t;
    f32 k;
    f32 drop;
    s32 hit;
    s32 n;
    s32 i;
    void *o;
    u8 *e;

    switch (m->state) {
    case 1:
        k = (f32)*(s32 *)pv / (f32)D_L20_001DF2C0_003E8C98;
        *(f32 *)((u8 *)m + 0x2C) = *(f32 *)(m->cls + 0x24) * D_L20_001DF2D4_003E8C98 * k;
        *(s16 *)(pv + 0x38) = (f32)D_L20_001DF300 * k;
        *(s16 *)(pv + 0x3A) = (f32)D_L20_001DF302 * k;
        func_00388830(&dir, pv + 0x10, 1.0f);
        func_L01_00449008(&dir, &dir, D_L20_001D9BE0, 1, D_L20_001DF2E0_003E8C98);
        func_00388830(pv + 0x10, &dir, func_00388770(pv + 0x10));
        m->rot[2] = func_00388A28(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
        m->rot[1] = -func_00388A28(func_003887A0(pv + 0x10), *(f32 *)(pv + 0x18));
        vec_add_ba(&tmp, &m->pos, pv + 0x10);
        m->rot[0] = func_00389380(m->rot[0], D_L20_001DF2E4_003E8C98);
        func_00388BD0(m->mtx, m->rot);
        m->pos = tmp;
        func_L20_003E98F8((u8 *)m, pv);
        if (func_00388398(pv)) {
            func_L01_00441FB8(m, 2, -1);
            m->flags = (m->flags | 0x41) & ~0x1000;
            m->w98 = 0;
            func_L01_004A6DF8(m, 1);
            *(s32 *)pv = D_L20_001DF2C4;
        }
        break;
    case 2:
        if (func_00388398(pv)) {
            func_L01_00441FB8(m, 3, -1);
            if (func_L20_003E95A0(m, pv) == 0) {
                func_003BD360(m);
                return;
            }
            *(s32 *)pv = D_L20_001DF2C8_003E8C98;
            func_0039FE80(1, 0, m);
        }
        break;
    case 3:
        func_L01_00402498(func_L20_003E9B58, m);
        if (func_00388398(pv)) {
            func_L01_00441FB8(m, 4, -1);
            *(s32 *)pv = D_L20_001DF2CC_003E8C98;
        }
        break;
    case 4:
        func_L01_00402498(func_L20_003E9B58, m);
        if (func_00388398(pv)) {
            u8 *c;
            u8 *vel = pv + 0x10;
            func_L01_00441FB8(m, 5, -1);
            m->flags &= ~0x41;
            c = m->cls;
            m->flags |= *(u16 *)(c + 0x44) & 0x1000;
            m->w98 = *(s32 *)(c + 0x10);
            qzero(vel);
            *(f32 *)(pv + 0x18) = -*(f32 *)(pv + 0x8);
            m->rot[2] = func_00388A28(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
            m->rot[1] = -func_00388A28(func_003887A0(vel), *(f32 *)(pv + 0x18));
            func_00388BD0(m->mtx, m->rot);
            *(vu0_q *)&m->pos = *(vu0_q *)(pv + 0x20);
            m->pos.z += D_L20_001DF2E8_003E8C98;
            *(s32 *)pv = D_L20_001DF2D0_003E8C98;
        }
        break;
    case 5:
        if (func_L01_00452EC8(m)) {
            *(f32 *)(pv + 0x40) = 0.0f;
            *(f32 *)(pv + 0x44) = 0.0f;
        }
        if (*(s32 *)pv < 0x14) {
            *(f32 *)(pv + 0x40) -= 0.05f;
            if (*(f32 *)(pv + 0x40) < 0.0f) {
                *(f32 *)(pv + 0x40) = 0.0f;
            }
        } else {
            *(f32 *)(pv + 0x40) += 0.05f;
            *(f32 *)(pv + 0x44) += 0.15f;
            if (1.0f < *(f32 *)(pv + 0x40)) {
                *(f32 *)(pv + 0x40) = 1.0f;
            }
        }
        if (2.5f < *(f32 *)(pv + 0x44)) {
            *(f32 *)(pv + 0x44) = 2.5f;
        }
        func_L01_00402498(func_L20_003E9B58, m);
        k = *(f32 *)((u8 *)m + 0x2C) / *(f32 *)(m->cls + 0x24) + D_L20_001DF2EC_003E8C98 * D_L20_001DF2D4_003E8C98;
        if (D_L20_001DF2D4_003E8C98 < k) {
            k = D_L20_001DF2D4_003E8C98;
        }
        t = 1.0f / D_L20_001DF2D4_003E8C98;
        drop = D_L20_001DF2F0 * 0.00027777778450399637f;
        *(f32 *)((u8 *)m + 0x2C) = *(f32 *)(m->cls + 0x24) * k;
        k = k * t;
        *(s16 *)(pv + 0x38) = (f32)D_L20_001DF300 * k;
        *(s16 *)(pv + 0x3A) = (f32)D_L20_001DF302 * k;
        vec_add_ba(&tmp, &m->pos, pv + 0x10);
        *(f32 *)(pv + 0x18) -= drop;
        func_L01_00443628(&s, m->owner, 0x8000001, pv + 0x10, *(f32 *)(pv + 0x4));
        s.h1A = m->oclass;
        vec_sub_ab(&s.v, &m->pos, m->owner + 0x10);
        s.v.z = 0.0f;
        func_00388830(&s.v, &s.v, 1.6666667461395264f);
        s.b18 = 3;
        s.v.w = 5627.925f;
        s.w20 |= 1;
        o = m->owner;
        func_L01_004C76B8();
        hit = func_003CE740(&m->pos, &tmp, 0, o, &s);
        if (hit) {
            e = D_L20_001E9BD8_003E8C98[0];
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit || func_L01_003F9498(&m->pos, 1, D_L20_001DF2D8_003E8C98, m->owner) ||
            func_00388398(pv)) {
            n = func_003CF790(&m->pos, 0, D_L20_001DF2DC_003E8C98, m->owner, &s);
            for (i = 0; i < n; i++) {
                s32 *l = D_L20_001EDC40_003E8C98;
                u8 *h = D_001A4BE0;
                if (l[i] == *(s32 *)(h + 0x25C0)) {
                    func_L01_00452F40(m->owner, 1);
                }
            }
            func_0039FE80(0, 0, m);
            func_L20_003EC788(&m->pos, 1, 0xF, 10, 10, 10, 0x19, 0, 0.75f, 0.0f, 0.0f, 0.0f,
                              0, 1, 0, 0, 0, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            m->flags = (m->flags | 0x41) & ~0x1000;
            m->w98 = 0;
            func_L01_004A6DF8(m, 1);
            func_L01_00441FB8(m, 6, -1);
            return;
        }
        m->pos = tmp;
        func_L20_003E98F8((u8 *)m, pv);
        break;
    case 6:
        if (func_L01_00452EC8(m)) {
            *(s32 *)pv = D_L20_001DF2F4;
        }
        if (func_00388398(pv)) {
            func_003BD360(m);
        }
        break;
    }
}
/* localdecomp:end func_L20_003E8C98 */
