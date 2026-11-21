#include "common.h"

/* NTSC-U counterpart of func_L20_003F1A78 (src/levels/20_final_boss/L20_003F1A78.c) */
#include "vu0.h"

/* localdecomp:start func_L20_003EFA10 */
#include "vu0.h"

typedef struct P_003F1A78 {
    vu0_v4 v0;
    vu0_v4 v10;
    s32 i20;
    s32 i24;
    s32 snd;
    u8 *target;
    vu0_v4 hist[4];
} P_003F1A78;

typedef struct G_003F1A78 {
    u8 pad0[0xD0];
    vu0_v4 vD0;
    u8 padE0[0x19E0 - 0xE0];
    u8 *p19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    u8 *p25C0;
} G_003F1A78;

extern u8 D_001A30B0[];
extern G_003F1A78 D_001A4BE0;
extern vu0_v4 D_L20_001D66B0_003EFA10 __attribute__((section(".sdata")));
extern u8 *D_L20_002202B4_003EFA10 __attribute__((section(".data")));
extern u8 *D_L20_001E9BD8_003EFA10[];
extern vu0_v4 D_L20_001E9BE0_003EFA10;
extern void func_L13_003C3C58(void *);

extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90_003EFA10(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_L01_004C76F0(void);
extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BD360(void *);
extern void func_L01_004026A0(void (*)(void *), void *);

static __inline__ s32 collide_003F1A78(u8 *p, void *from, void *info) {
    void *o;
    s32 hit;

    o = *(void **)(p + 0xB8);
    func_L01_004C76B8();
    hit = func_003CE740(from, p + 0x10, 0, (s32)o, (s32)info);
    if (hit != 0) {
        u8 *b = D_L20_001E9BD8_003EFA10[0];
        if (b != 0 && *(s16 *)(b + 0xAA) == 0x186D && b[0x20] != 2 && b[0x20] != 5) {
            b[0x20] = 4;
        }
    }
    func_L01_004C76F0();
    return hit;
}

void func_L20_003EFA10(u8 *p) {
    f32 pos[4] __attribute__((aligned(16)));
    vu0_v4 dir;
    vu0_v4 v;
    vu0_v4 off;
    u8 info[0x30];
    P_003F1A78 *pv;
    u8 *e;
    u8 *t;
    u8 *m;
    u8 *pt;
    s32 n;
    s32 i;
    s32 hit;
    vu0_v4 *h;

    pv = *(P_003F1A78 **)(p + 0x68);
    if (pv->snd == -1 || (e = D_001A30B0 + (pv->snd << 7), *(u8 **)(e + 0xDC) != p) || e[0xD0] == 0) {
        pv->snd = func_0039FE80(1, 4, p);
    }
    if (*(u16 *)(p + 0x96) >= 0x1A5) {
        if (pv->snd != -1) {
            e = D_001A30B0 + (pv->snd << 7);
            if (*(u8 **)(e + 0xDC) == p && e[0xD0] != 0) {
                func_0039FB08(pv->snd);
            }
        }
        pv->snd = -1;
        func_0039FE80(0, 0, p);
        func_L01_0032FE90_003EFA10(p + 0x10, 1.0f, 0, 6, 6, 6, 6, 10, 0, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(p);
        return;
    }
    func_003BDA38(p, 0, pos);
    n = func_0037E1D8(0x28);
    pt = func_L01_00466F98(pos, &D_L20_001D66B0_003EFA10, 0x14, 0x60, 0x101010, n,
                           252000.02f, func_0037E250(500.0f, 1500.0f), 1.0f, 0.0f, 0.0f);
    if (pt != 0) {
        pt[2] = *D_L20_002202B4_003EFA10;
        pt[3] = 0x44;
    }
    if (*(u16 *)(p + 0x96) >= 0x3D) {
        t = pv->target;
        if (t == D_001A4BE0.p25C0) {
            vec_sub_ab(&dir, &D_001A4BE0.vD0, p + 0x10);
        } else {
            vec_sub_ab(&dir, t + 0x10, p + 0x10);
        }
        m = D_001A4BE0.p19E0;
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x1A17 && pv->target == D_001A4BE0.p25C0
            && 0.16666667f < *(f32 *)(*(u8 **)(*(u8 **)(m + 0x68) + 0x6D0) + 0x138)) {
            func_00388830(&off, m + 0xC0, (f32)func_0037E208(0xF, 0x1E));
            vec_add_ba(&v, &off, &D_001A4BE0.vD0);
            vec_sub_ab(&dir, &v, p + 0x10);
        }
        v = pv->v10;
        func_003BEB58(&pv->v10, &v, &dir, 0.01f);
    }
    if (*(u16 *)(p + 0x96) >= 0x3D && pv->i20 != 0) {
        dir = pv->v0;
        v = pv->v10;
        func_003BEB58(pv, &dir, &v, 0.005f);
        if (func_00388770(pv) > 1.6666667f) {
            func_00388830(pv, pv, 1.6666667f);
        }
        if (pv->i20 == 1) {
            func_00388830(pv, pv, 1.0f);
        }
    }
    dir = *(vu0_v4 *)(p + 0x10);
    func_00389158(pv, pv, &pv->v10, 0.11635529f);
    *(f32 *)(p + 0xF4) = -func_00388A28(func_003887A0(pv), pv->v0.z);
    *(f32 *)(p + 0xF8) = func_00388A28(pv->v0.x, pv->v0.y);
    *(f32 *)(p + 0xF0) = func_00389380(*(f32 *)(p + 0xF0), 0.11635529f);
    vec_add_ba(p + 0x10, p + 0x10, pv);
    func_00388830(&v, pv, 1.0f);
    func_L01_00443628(info, p, 1, &v, 45.0f);
    info[0x18] = 1;
    info[0x19] = 1;
    *(u16 *)(info + 0x1A) = *(u16 *)(p + 0xAA);
    hit = collide_003F1A78(p, &dir, info);
    if (hit != 0) {
        u8 *b = D_L20_001E9BD8_003EFA10[0];
        if (b == 0 || (u16)(*(u16 *)(b + 0xAA) - 0x199A) >= 3) {
            if (pv->snd != -1) {
                e = D_001A30B0 + (pv->snd << 7);
                if (*(u8 **)(e + 0xDC) == p && e[0xD0] != 0) {
                    func_0039FB08(pv->snd);
                }
            }
            pv->snd = -1;
            func_0039FE80(0, 0, p);
            func_L01_0032FE90_003EFA10(&D_L20_001E9BE0_003EFA10, 1.0f, 0, 6, 6, 6, 6, 10, 0, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00443648(p, &D_L20_001E9BE0_003EFA10, 1, 0, 1, 0, 2.0f, 45.0f, 1.0f);
            func_003BD360(p);
            return;
        }
    }
    off = *(vu0_v4 *)pos;
    for (i = 3, h = &pv->hist[2]; i > 0; i--, h--) {
        h[1] = h[0];
    }
    pv->hist[0] = off;
    pv->i24++;
    if (pv->i24 >= 4) {
        func_L01_004026A0(func_L13_003C3C58, p);
    }
    *(u16 *)(p + 0x96) += 1;
}
/* localdecomp:end func_L20_003EFA10 */
