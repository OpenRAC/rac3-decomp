/* Level 06 shared (src/levels/shared/L06_00356C80.c) draft, 2026-11-15; the function is at five places (levels 06, 07, 10, 23, 24). 87 differences with the file's flags: everything except the hit branch's two arms. Retail cross-jumps them from the `move $a3` before func_003D4D00 on (each arm ends with its own $f12, 0.3f or 0.6f); this C keeps two full arms, and a shared tail with a float variable moves the loads out of the arms (88). The prototypes here (func_L01_00446780 floats first, func_L01_004713C8 floats after the seventh argument) are the ones that give retail's argument order. The V_/D_/G_00358630 types would move to the file prelude, as func_L06_00358630's block defines them later, with pad19 named b19. */
#include "vu0.h"
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00358630;
typedef struct {
    V_00358630 dir;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00358630;
typedef struct { u8 pad[0x18]; u8 *target; } G_00358630;
extern void func_L01_00446780(f32, f32, f32, u8 *, u8 *, s32, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern void func_003A4F28(s32);
extern void func_003C2880(void *);
extern G_00358630 D_L06_001E8440;
extern u8 *D_L06_0021E63C[];
extern u8 D_001A30B0[];

void func_L06_00358098(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_00358630 d;
    V_00358630 e;
    V_00358630 np;
    D_00358630 dd;
    V_00358630 q;
    D_00358630 ee;
    u8 *p;
    u8 *m;
    u8 *owner;
    s32 hit;
    s32 slot;
    G_00358630 *g;

    if (++*(s32 *)(v + 0x24) > 0xF0) {
        func_L01_00446780(0.6f, *(f32 *)(v + 0x14), 0.0f, a0, a0 + 0x10, *(s32 *)(v + 0x2C), *(s32 *)(v + 0x34), 1, 0);
        func_L01_004450F0(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 0:
        func_0038CF68(&d, v, 0.020000001f);
        p = func_L01_004713C8(a0 + 0x10, &d, 0x11, 0x406080, 0, 0x30, 0, 105000.0f, 5250.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = *D_L06_0021E63C[0];
            p[3] = 0x48;
        }
        func_0038CF68(&d, &d, -1.0f);
        func_0038CF68(&d, &d, 0.25f);
        vec_add_ab(&e, &d, a0 + 0x10);
        func_0038CF68(&d, v, 0.020000001f);
        p = func_L01_004713C8(&e, &d, 0x11, 0x406080, 0, 0x30, 0, 105000.0f, 5250.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = *D_L06_0021E63C[0];
            p[3] = 0x48;
        }
        *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), 1.1170108f);
        vec_add_ba(&np, a0 + 0x10, v);
        func_L01_00446760(&dd, a0, *(s32 *)(v + 0x2C), v, *(f32 *)(v + 0x14));
        dd.b18 = v[0x34];
        dd.h1A = *(u16 *)(a0 + 0xAA);
        owner = *(u8 **)(a0 + 0xB8);
        func_L01_004CB320();
        hit = func_003D3CB0(a0 + 0x10, &np, 0, owner, &dd);
        if (hit) {
            m = D_L06_001E8440.target;
            if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
                m[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit) {
            g = &D_L06_001E8440;
            if (g->target != 0) {
                if (g->target == *(u8 **)(v + 0x10)) {
                    goto move;
                }
                q = *(V_00358630 *)v;
                func_0038CE20(&q, &q, 2.0f);
                q.w = 5627.925f;
                func_L01_00446760(&ee, a0, *(s32 *)(v + 0x2C), &q, *(f32 *)(v + 0x14));
                ee.b18 = v[0x34];
                ee.b19 = 1;
                ee.h1A = *(u16 *)(a0 + 0xAA);
                func_003D4D00((u8 *)g + 0x20, 0.3f, 0, *(u8 **)(a0 + 0xB8), &ee);
            } else {
                q = *(V_00358630 *)v;
                func_0038CE20(&q, &q, 3.0f);
                q.w = 5627.925f;
                func_L01_00446760(&ee, a0, *(s32 *)(v + 0x2C), &q, *(f32 *)(v + 0x14));
                ee.b18 = v[0x34];
                ee.b19 = 1;
                ee.h1A = *(u16 *)(a0 + 0xAA);
                func_003D4D00((u8 *)g + 0x20, 0.6f, 0, *(u8 **)(a0 + 0xB8), &ee);
            }
            func_L01_004450F0(a0, 1, -1);
            return;
        }
    move:
        *(V_00358630 *)(a0 + 0x10) = np;
        return;
    case 1:
        slot = *(s32 *)(v + 0x30);
        if (slot != -1 && *(u8 **)(D_001A30B0 + slot * 0x80 + 0xDC) == a0 && D_001A30B0[slot * 0x80 + 0xD0] != 0) {
            func_003A4F28(slot);
        }
        *(s32 *)(v + 0x30) = -1;
        func_003C2880(a0);
        return;
    }
}
