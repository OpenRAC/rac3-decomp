#include "common.h"

/* localdecomp:start func_L39_0052D348 */
typedef struct { u8 p0[0x20]; f32 f20; s32 w24; s32 w28; s32 w2C; f32 f30; s32 w34; s32 w38; s32 w3C; f32 f40; s32 w44; s32 w48; u8 p4C[0x460 - 0x4C]; } E_0052D348;
typedef struct { u8 p0[0x1A14]; u8 b1A14; u8 p1A15[0x24C9 - 0x1A15]; u8 b24C9; u8 p24CA[0x2534 - 0x24CA]; s32 w2534; } P_0052D348;
typedef struct { u8 p0[0x2D8]; P_0052D348 *pl0; P_0052D348 *pl1; } R_0052D348;
typedef struct { u8 p0[0x6D0]; R_0052D348 *r; } Q_0052D348;
typedef struct { u8 p0[0x68]; Q_0052D348 *q; } O_0052D348;
extern E_0052D348 D_L39_0024DE80[];
extern void func_L01_003F1F20(s32, s32);

void func_L39_0052D348(O_0052D348 *o) {
    Q_0052D348 *q = o->q;
    P_0052D348 *p = q->r->pl0;
    s32 idx;
    if (p != 0 && p->b1A14 != 0) {
        func_L01_003F1F20(0x12, p->w2534);
        (D_L39_0024DE80 + p->b24C9)->f20 = 0.3f;
        (D_L39_0024DE80 + p->b24C9)->w28 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
        (D_L39_0024DE80 + p->b24C9)->f30 = 0.1f;
        (D_L39_0024DE80 + p->b24C9)->w38 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
        (D_L39_0024DE80 + p->b24C9)->f40 = 0.01f;
        (D_L39_0024DE80 + p->b24C9)->w48 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
    }
    p = q->r->pl1;
    idx = -1;
    if (p != 0 && p->b1A14 != 0) {
        func_L01_003F1F20(0x12, p->w2534);
        idx = p->b24C9;
    }
    if (idx >= 0) {
        (D_L39_0024DE80 + idx)->f20 = 0.3f;
        (D_L39_0024DE80 + idx)->w28 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
        (D_L39_0024DE80 + idx)->f30 = 0.1f;
        (D_L39_0024DE80 + idx)->w38 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
        (D_L39_0024DE80 + idx)->f40 = 0.01f;
        (D_L39_0024DE80 + idx)->w48 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
    }
}
/* localdecomp:end func_L39_0052D348 */

/* localdecomp:start func_L39_0052D4E8 */
#include "vu0.h"

extern void func_L01_003F1F20_0052D4E8(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void *func_L39_006472D0_0052D4E8(void *, void *, void *, f32, f32, f32, f32, f32, s32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern u8 *func_00382348(void *);
extern void func_L01_003F6F20_0052D4E8(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern u8 *func_L39_0061D7B0_0052D4E8(void *);
extern u8 *func_L39_00668620_0052D4E8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L07_003CAE10_0052D4E8(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern s32 func_L39_005F33E0_0052D4E8(s32, s32, void *);
extern s32 func_L39_0066E010_0052D4E8(void *, s32, void *, void *, void *);
extern s32 func_0038CB00(void *);
__asm__(".extern D_L39_0024ABF0_0052D4E8, 4");
extern vu0_v4 D_L39_0024ABF0_0052D4E8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AB3C_0052D4E8, 4");
extern f32 D_L39_0024AB3C_0052D4E8;
__asm__(".extern D_L39_0024ABD4_0052D4E8, 4");
extern f32 D_L39_0024ABD4_0052D4E8;
__asm__(".extern D_L39_0024AB38_0052D4E8, 4");
extern s32 D_L39_0024AB38_0052D4E8;
__asm__(".extern D_L39_0024ABD0_0052D4E8, 4");
extern s32 D_L39_0024ABD0_0052D4E8;

void func_L39_0052D4E8(u8 *a0)
{
    u8 *g = *(u8 **)(a0 + 0x68);
    u8 *c = *(u8 **)(g + 0x6D0);
    u8 *pl = *(u8 **)(c + 0x2D8);
    u8 *m;
    u8 *r;
    u8 *t;
    u8 *hit;
    u8 *h;
    u8 *e;
    s32 st;
    s32 id;
    s16 oc;
    f32 sc;
    f32 d;
    f32 a;
    s32 mask;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;

    if (pl[0x1A14] == 0) {
        return;
    }
    if (*(s16 *)(pl + 0x320) > 0) {
        return;
    }
    if (*(f32 *)(c + 0x308) <= 0.0f) {
        return;
    }
    st = a0[0xBC];
    if (st == 10) {
        return;
    }
    if (st == 11) {
        return;
    }
    if (st == 7) {
        return;
    }
    if (st == 8) {
        return;
    }
    *(s32 *)(*(u8 **)(c + 0x2D0) + 0x98) = 0;
    *(vu0_q *)&v20 = *(vu0_q *)(*(u8 **)(c + 0x2D0) + 0xC0);
    func_0038CE20(&v0, *(u8 **)(c + 0x2D0) + 0xE0, 0.5f);
    vec_add_ab(&v0, &v0, *(u8 **)(c + 0x2D0) + 0x10);
    r = func_L39_006472D0_0052D4E8(pl, &v0, &v20, 0.08726646f, 0.17453292f, 70.0f, 0.6981317f, 0.2617994f, 1);
    *(s32 *)(*(u8 **)(c + 0x2D0) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(c + 0x2D0) + 0x24) + 0x10);
    func_0038D000(&v0, &D_L39_0024ABF0_0052D4E8[c[0x2FE]], a0 + 0xC0);
    vec_add_ab(&v0, &v0, a0 + 0x10);
    if (r != 0) {
        sc = 0.1f;
        d = func_0038CF00(*(void **)(pl + 0x2530), r + 0x10) / 150.0f;
        h = func_00382348(r);
        if (h != 0) {
            sc = *(f32 *)(h + 0x10);
        }
        func_0038CE20(&v30, r + 0xE0, sc);
        vec_add_ab(&v30, r + 0x10, &v30);
        a = fabs_asm(0.9f - d * 0.65f);
        m = *(u8 **)(c + 0x2D0);
        if (pl[0x1A14] != 0) {
            func_L01_003F6F20_0052D4E8(pl[0x24C9], m, 0xFF0FFF0F, &v30, 0x26, -1, 4, a, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
        vec_sub_ab(&v10, &v30, &v0);
        sc = func_0038CEA8(&v10);
        qzero(&v40);
        e = func_L39_0061D7B0_0052D4E8(r);
        t = 0;
        if (e != 0) {
            t = (e[3] & 0xF) ? 0 : e;
        }
        if (t != 0) {
            *(vu0_q *)&v40 = *(vu0_q *)(t + 0x140);
            v40.z += 0.015f;
        } else {
            oc = *(s16 *)(r + 0xAA);
            if (oc < 0x1080) {
                if (oc >= 0x107C) {
                    *(vu0_q *)&v40 = *(vu0_q *)(func_L39_00668620_0052D4E8(r) + 0x270);
                }
            }
        }
        if (0.0f < sc) {
            func_0038CE20(&v40, &v40, D_L39_0024AB3C_0052D4E8 / sc);
            func_0038CE20(&v10, &v10, (*(f32 *)(c + 0x310) + 1.8000001f) / sc);
        } else {
            func_0038CE20(&v40, &v40, D_L39_0024AB3C_0052D4E8);
            func_0038CE20(&v10, &v10, *(f32 *)(c + 0x310) + 1.8000001f);
        }
        vec_add_ab(&v10, &v10, &v40);
    } else {
        func_00382760(&v10, *(f32 *)(c + 0x310) + 1.8000001f, *(f32 *)(*(u8 **)(c + 0x2D0) + 0xF8), -(*(f32 *)(*(u8 **)(c + 0x2D0) + 0xF4) + 0.03f));
    }
    if ((*(s32 *)(*(u8 **)(pl + 0x2534) + 0x1A0) & 0x28) && *(s16 *)(g + 0x716) <= 0) {
        id = *(s32 *)(pl + 0x2544);
        mask = 0x80000000;
        hit = func_L07_003CAE10_0052D4E8(&v0, &v10, a0, 1, &mask, id, 0xFFFFFFFF, 6.0f, D_L39_0024ABD4_0052D4E8);
        func_L39_005F33E0_0052D4E8(3, 0, a0);
        func_L01_003F1F20_0052D4E8(D_L39_0024AB38_0052D4E8, *(s32 *)(pl + 0x2534));
        if (hit != 0) {
            *(s32 *)(hit + 0x90) = *(s32 *)pl;
            st = func_L39_0066E010_0052D4E8(pl, 6, hit, r, 0);
            *(s32 *)(*(u8 **)(hit + 0x68) + 0x44) = st;
            *(s32 *)(*(u8 **)(hit + 0x68) + 0x24) = 50;
            *(f32 *)(*(u8 **)(hit + 0x68) + 0x28) = 0.016666668f;
            c[0x2FE] ^= 1;
            *(s16 *)(g + 0x716) = (D_L39_0024ABD0_0052D4E8 * 5 + 2) / 6;
        }
    }
    func_0038CB00(g + 0x716);
}
/* localdecomp:end func_L39_0052D4E8 */

/* localdecomp:start func_L39_0052D9D0 */
#include "vu0.h"

extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern f32 D_L39_0024AB34;
extern f32 D_L39_0024AB30;
extern f32 D_L39_0024D510[] __attribute__((section(".sdata")));
extern const f32 D_L39_0024AC68[] __attribute__((section(".sdata")));
extern const f32 D_L39_0024AC58[] __attribute__((section(".sdata")));
extern void func_L09_003CA6A8(void *, s32);
extern void func_L09_003CA7E8(void *, s32);
extern void func_003C3FC0(void *, void *);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V_0052D9D0;

void func_L39_0052D9D0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *q = *(u8 **)(p + 0x6D0);
    u8 *r;
    f32 f;
    s32 i;
    s32 mode;
    s32 *ia;
    f32 *fa;
    V_0052D9D0 v;

    qzero(q + 0x270);
    mode = D_L39_002412DC;
    *(s32 *)(q + 0x310) = 0;
    if (mode == 0x12) {
        f = D_L39_0024AB34;
        *(f32 *)(q + 0x308) = f;
        *(f32 *)(q + 0x30C) = f;
    } else if (mode == 0x14) {
        f = 200.0f;
        *(f32 *)(q + 0x308) = f;
        *(f32 *)(q + 0x30C) = f;
    } else {
        f = D_L39_0024AB30;
        *(f32 *)(q + 0x308) = f;
        *(f32 *)(q + 0x30C) = f;
    }
    r = *(u8 **)(p + 0x720);
    *(f32 *)(p + 0x700) = *(f32 *)(r + 0x80);
    *(s32 *)(p + 0x6F8) = 0;
    qzero(p + 0x620);
    qzero(p + 0x6A0);
    *(s32 *)(p + 0x704) = 0;
    qzero(p + 0x630);
    *(s32 *)(p + 0x708) = 0;
    qzero(p + 0x640);
    *(s16 *)(p + 0x718) = 0;
    qzero(p + 0x650);
    *(s16 *)(p + 0x71A) = 0;
    *(s32 *)(p + 0x6DC) = 0;
    *(s32 *)(p + 0x6D4) = 0;
    *(f32 *)(p + 0x6D8) = *(f32 *)(r + 0x70);
    *(f32 *)(p + 0x724) = -999.0f;
    *(s32 *)(p + 0x72C) = -1;
    *(u8 *)(p + 0x714) = 0;
    *(u8 *)(p + 0x713) = 0;
    *(s32 *)(p + 0x7A4) = 0;
    *(s32 *)(p + 0x7A8) = 0;
    *(s16 *)(p + 0x710) = 0;
    *(s32 *)(p + 0x6F0) = 0;
    *(s32 *)(p + 0x6F4) = 0;
    *(s32 *)(p + 0x74C) = 0;
    *(s32 *)(p + 0x750) = 0;
    *(s32 *)(p + 0x70C) = 0;
    *(s16 *)(p + 0x71C) = 0;
    *(s16 *)(p + 0x71E) = 0;
    *(s32 *)(p + 0x728) = 0;
    *(s32 *)(p + 0x730) = 0;
    *(s32 *)(p + 0x6E8) = 0;
    *(s32 *)(p + 0x6E0) = 0;
    ia = (s32 *)(p + 0x6B0);
    fa = (f32 *)(p + 0x6C0);
    for (i = 0; i < 4; i++) {
        ia[i] = 0;
        fa[i] = -1.0f;
        D_L39_0024D510[i] = D_L39_0024AC68[i] + fabs_asm(D_L39_0024AC58[i]);
    }
    func_L09_003CA6A8(p, 0);
    func_L09_003CA6A8(p, 1);
    func_L09_003CA7E8(p, 2);
    func_L09_003CA7E8(p, 3);
    qzero(&v);
    v.x = *(f32 *)(p + 0x6F0);
    v.y = *(f32 *)(p + 0x74C);
    func_003C3FC0(p + 0x2B0, &v);
    qzero(&v);
    v.x = *(f32 *)(p + 0x6F0);
    v.y = -*(f32 *)(p + 0x74C);
    func_003C3FC0(p + 0x3B0, &v);
}
/* localdecomp:end func_L39_0052D9D0 */
