#include "vu0.h"
#include "common.h"

/* NTSC-U counterpart of func_L06_00358098 with regional motion and particle timing. */

/* localdecomp:start func_L06_00357398 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00357398;
typedef struct {
    V_00357398 dir;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00357398;
typedef struct { u8 pad[0x18]; u8 *target; } G_00357398;
extern void func_L01_00443648(f32, f32, f32, u8 *, u8 *, s32, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CF790(void *, f32, s32, void *, void *);
extern void func_0039FB08(s32);
extern void func_003BD360(void *);
extern G_00357398 D_L06_001E8440;
extern u8 *D_L06_0021E63C[];
extern u8 D_001A30B0[];

void func_L06_00357398(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    V_00357398 d;
    V_00357398 e;
    V_00357398 np;
    D_00357398 dd;
    V_00357398 q;
    D_00357398 ee;
    u8 *p;
    u8 *m;
    u8 *owner;
    s32 hit;
    s32 slot;
    G_00357398 *g;

    if (++*(s32 *)(v + 0x24) > 0xF0) {
        func_L01_00443648(0.6f, *(f32 *)(v + 0x14), 0.0f, a0, a0 + 0x10, *(s32 *)(v + 0x2C), *(s32 *)(v + 0x34), 1, 0);
        func_L01_00441FB8(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 0:
        func_00388830(&d, v, 0.016666668f);
        p = func_L01_0046DCB8(a0 + 0x10, &d, 0x14, 0x406080, 0, 0x30, 0, 105000.0f, 5250.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = *D_L06_0021E63C[0];
            p[3] = 0x48;
        }
        func_00388830(&d, &d, -1.0f);
        func_00388830(&d, &d, 0.25f);
        vec_add_ab(&e, &d, a0 + 0x10);
        func_00388830(&d, v, 0.016666668f);
        p = func_L01_0046DCB8(&e, &d, 0x14, 0x406080, 0, 0x30, 0, 105000.0f, 5250.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = *D_L06_0021E63C[0];
            p[3] = 0x48;
        }
        *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), 0.93084234f);
        vec_add_ba(&np, a0 + 0x10, v);
        func_L01_00443628(&dd, a0, *(s32 *)(v + 0x2C), v, *(f32 *)(v + 0x14));
        dd.b18 = v[0x34];
        dd.h1A = *(u16 *)(a0 + 0xAA);
        owner = *(u8 **)(a0 + 0xB8);
        func_L01_004C76B8();
        hit = func_003CE740(a0 + 0x10, &np, 0, owner, &dd);
        if (hit) {
            m = D_L06_001E8440.target;
            if (m != 0 && *(s16 *)(m + 0xAA) == 0x186D && m[0x20] != 2 && m[0x20] != 5) {
                m[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit) {
            g = &D_L06_001E8440;
            if (g->target != 0) {
                if (g->target != *(u8 **)(v + 0x10)) {
                    q = *(V_00357398 *)v;
                    func_003886E8(&q, &q, 2.0f);
                    q.w = 5627.925f;
                    func_L01_00443628(&ee, a0, *(s32 *)(v + 0x2C), &q, *(f32 *)(v + 0x14));
                    ee.b18 = v[0x34];
                    ee.b19 = 1;
                    ee.h1A = *(u16 *)(a0 + 0xAA);
                    func_003CF790((u8 *)g + 0x20, 0.3f, 0, *(u8 **)(a0 + 0xB8), &ee);
                    func_L01_00441FB8(a0, 1, -1);
                    return;
                }
            } else {
                q = *(V_00357398 *)v;
                func_003886E8(&q, &q, 3.0f);
                q.w = 5627.925f;
                func_L01_00443628(&ee, a0, *(s32 *)(v + 0x2C), &q, *(f32 *)(v + 0x14));
                ee.b18 = v[0x34];
                ee.b19 = 1;
                ee.h1A = *(u16 *)(a0 + 0xAA);
                func_003CF790((u8 *)g + 0x20, 0.6f, 0, *(u8 **)(a0 + 0xB8), &ee);
                func_L01_00441FB8(a0, 1, -1);
                return;
            }
        }
        *(V_00357398 *)(a0 + 0x10) = np;
        return;
    case 1:
        slot = *(s32 *)(v + 0x30);
        if (slot != -1) {
            u8 *entry = D_001A30B0 + slot * 0x80;
            if (*(u8 **)(entry + 0xDC) == a0 && entry[0xD0] != 0) {
                func_0039FB08(slot);
            }
        }
        *(s32 *)(v + 0x30) = -1;
        func_003BD360(a0);
        return;
    }
}
/* localdecomp:end func_L06_00357398 */
