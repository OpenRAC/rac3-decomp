/* functional: high. Per-frame update of a falling ember mob: timer tick/remove, collision sweeps (two coll_line calls, second with mask 2), hero hit flag (state 4), spark burst, trail particles. func_L01_0040E020 is hand-written asm (byte timer tick, nonzero return = expired); its exact semantics are taken from how retail branches on the result. Compiles in the level context with the same frame size (0xD0) as retail. */
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    u8 *moby;
    u8 pad1[4];
    vu0_v4 pos;
} Hit_003E5140;

extern s32 func_L01_0040E020(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_003C2880(void *);
extern void func_003A4F28(s32);
extern f32 func_0038CEA8(void *);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L20_003E5058(void *);
extern void func_L13_003B3DA8(void *);
extern u8 D_1A30B0[];
extern u8 D_00220258[];
extern u8 D_L20_001D66B0[8];
extern u8 *D_L20_001E9BD8[];
extern Hit_003E5140 D_L20_001E9BC0;
extern vu0_v4 D_L20_001E9BE0;

/* Per-frame update of a falling spark/ember mob (vars at +0x68: direction vector, position at +0x10,
 * speed at +0x30, timer byte at +0x25, sound slot at +0x38, "landed" flag at +0x34): ticks its timer
 * (and removes it, stopping its sound, when it runs out), accelerates, sweeps a collision line from
 * its position to position + direction * speed, flags the hero hit (state 4) and, on a hit, shortens
 * itself to the hit point and bursts sparks (func_L20_003E5058); then spawns its trail particles. */
void func_L20_003E5140(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    vu0_v4 D;
    vu0_v4 dir;
    vu0_v4 info[3];
    vu0_v4 G;
    vu0_v4 E;
    u8 *e;
    u8 *m;
    u8 *p;
    s32 snd;
    s32 hit;
    s32 i;
    s32 lo;
    s32 hi;
    s32 cnt;
    f32 t;

    func_0038CF68(&D, v, *(f32 *)(v + 0x30));
    vec_add_ab(&D, v + 0x10, &D);
    if (func_L01_0040E020(v + 0x25) != 0) {
        snd = *(s32 *)(v + 0x38);
        if (snd != -1) {
            e = D_1A30B0 + snd * 128;
            if (*(u8 **)(e + 0xDC) == obj && e[0xD0] != 0) {
                func_003A4F28(snd);
            }
        }
        *(s32 *)(v + 0x38) = -1;
        func_003C2880(obj);
        return;
    }
    *(f32 *)(v + 0x30) = *(f32 *)(v + 0x30) + 1.2f;
    if (v[0x25] < 0xD) {
        t = *(f32 *)(v + 0x2C) - 0.15f;
        *(f32 *)(v + 0x2C) = t;
        if (t < 0.0f) {
            *(f32 *)(v + 0x2C) = 0.0f;
        }
    }
    func_0038CF68(&dir, v, 1.0f);
    func_L01_00446760(info, obj, *(s32 *)(v + 0x20), &dir, (f32)v[0x24]);
    ((u8 *)info)[0x19] = 1;
    *(u16 *)((u8 *)info + 0x1A) = *(u16 *)(obj + 0xAA);
    ((u8 *)info)[0x18] = 1;

    func_L01_004CB320();
    hit = func_003D3CB0(v + 0x10, &D, 0, *(void **)(obj + 0xB8), info);
    if (hit != 0) {
        m = D_L20_001E9BD8[0];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
            m[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        p = D_L20_001E9BC0.moby;
        if (p == 0 || *(s16 *)(p + 0xAA) == 0x1868) {
            *(s32 *)(v + 0x34) = 1;
            D = D_L20_001E9BC0.pos;
            vec_sub_ab(&G, &D, v + 0x10);
            *(f32 *)(v + 0x30) = func_0038CEA8(&G);
            func_L20_003E5058(obj);
        }
    }

    func_L01_004CB320();
    hit = func_003D3CB0(v + 0x10, &D, 2, *(void **)(obj + 0xB8), 0);
    if (hit != 0) {
        m = D_L20_001E9BD8[0];
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
            m[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        *(s32 *)(v + 0x34) = 1;
        D = D_L20_001E9BE0;
        vec_sub_ab(&G, &D, v + 0x10);
        *(f32 *)(v + 0x30) = func_0038CEA8(&G);
        func_L20_003E5058(obj);
    }

    lo = 20;
    hi = 30;
    if (*(s32 *)(v + 0x34) != 0) {
        lo = 3;
        hi = 5;
    }
    if (v[0x25] >= 3) {
        p = func_L01_0046B458(v + 0x10, 4, 2.0f, 0.0f, 0xAF000000, 0, 2, D_L20_001D66B0, 0.0f, 0);
        if (p != 0) {
            p[3] = 0x44;
        }
    }
    for (i = 1; i >= 0; i--) {
        t = func_003824E0(0.0f, 50.0f) * 0.020000001f;
        func_0038CF68(&E, v, -t);
        vec_add_ab(&G, &D, &E);
        cnt = (5 * func_00382498(lo, hi) + 2) / 6;
        p = func_L01_004713C8(&G, D_L20_001D66B0, cnt, 0x7F000000, func_00382498(-5, 5), 0x4F, 0, 0,
                              210000.0f, 21000.0f, -0.00040000002f);
        if (p != 0) {
            p[3] = 0x44;
            p[2] = **(u8 **)(D_00220258 + 0xD4);
        }
    }
    G = D;
    for (i = 0; i < 1; i++) {
        G.x += func_003824E0(-0.2f, 0.2f);
        G.y += func_003824E0(-0.2f, 0.2f);
        G.z += func_003824E0(-0.2f, 0.2f);
        cnt = (5 * func_00382498(lo, hi) + 2) / 6;
        p = func_L01_004713C8(&G, D_L20_001D66B0, cnt, 0xA0A96, func_00382498(-5, 5), 0x4F, 0, 0,
                              157500.0f, 0.0f, -0.00040000002f);
        if (p != 0) {
            p[2] = **(u8 **)(D_00220258 + 0xD4);
        }
    }
    func_L01_00404808(func_L13_003B3DA8, obj);
}
