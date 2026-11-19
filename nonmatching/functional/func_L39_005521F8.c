/* functional: medium. Multiplayer-menu lightning/beam renderer: from the beam record (D_L39_003C1020, 0x60 bytes per slot = state+0x3A) it builds a 4x4 basis (rec+0x30, cross, rec+0x40, rec+0x10*strand), makes three jittered strands of 20 points from the D_L39_0047F550 noise table (scaled 0.12) and draws closed ribbon quads between strand pairs (tex 0x15, fading colour), then two straight beam cores along the record points (tex 0xE then 0x17, half-width 1.0 and 0.1, scrolling v) with alpha from life*{64,80,255}; vector math component-wise (w from the first operand, as vadd/vsub.xyz would); 364 words differ (stack 0x5C0 vs 0x5A0, scheduling). Unverified: meaning of func_0038D028 (matrix transform assumed from the 4-row basis at the stack) and the quad field layout beyond the stores. */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_005521F8;

extern u8 D_L39_003C1020[];
extern V4_005521F8 D_L39_0047F550[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);

static void add_005521F8(V4_005521F8 *d, V4_005521F8 *a, V4_005521F8 *b) {
    V4_005521F8 r;
    r.x = a->x + b->x;
    r.y = a->y + b->y;
    r.z = a->z + b->z;
    r.w = a->w;
    *d = r;
}

static void sub_005521F8(V4_005521F8 *d, V4_005521F8 *a, V4_005521F8 *b) {
    V4_005521F8 r;
    r.x = a->x - b->x;
    r.y = a->y - b->y;
    r.z = a->z - b->z;
    r.w = a->w;
    *d = r;
}

void func_L39_005521F8(u8 *m) {
    u8 *p;
    u8 *rec;
    u8 q[0x90];
    V4_005521F8 mat[4];
    V4_005521F8 pts[3][20];
    V4_005521F8 tmp;
    V4_005521F8 view;
    V4_005521F8 side;
    V4_005521F8 prev;
    V4_005521F8 prev2;
    V4_005521F8 cur;
    f32 *tc;
    f32 life;
    f32 u0;
    f32 u1;
    f32 v;
    f32 vn;
    f32 f0;
    f32 base;
    s32 col;
    s32 c2;
    s32 cc;
    s32 i;
    s32 j;
    s32 k;
    s32 jp;
    V4_005521F8 *r;

    p = *(u8 **)(m + 0x68);
    rec = D_L39_003C1020 + p[0x3A] * 0x60;
    func_003D93B0(q, 0x15, 0, 0x60);
    if (*(s16 *)(rec + 0x50) == 0) return;
    tc = (f32 *)(q + 0x50);
    mat[0] = *(V4_005521F8 *)(rec + 0x30);
    mat[2] = *(V4_005521F8 *)(rec + 0x40);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    life = (f32)*(s16 *)(rec + 0x52) * *(f32 *)(rec + 0x5C);
    col = ((s32)(life * 64.0f) << 24) | 0x804020;
    *(s32 *)(q + 0x4C) = col;
    *(s32 *)(q + 0x48) = col;
    *(s32 *)(q + 0x44) = col;
    *(s32 *)(q + 0x40) = col;
    for (j = 0; j < 3; j++) {
        mat[3] = *(V4_005521F8 *)(rec + 0x10 * j);
        for (k = 0; k < 20; k++) {
            func_0038CE20(&tmp, &D_L39_0047F550[k], 0.12f);
            func_0038D028(&pts[j][k], &tmp, mat);
        }
    }
    u0 = *(f32 *)(rec + 0x54);
    u1 = u0 + 4.0f;
    cc = 0x804020;
    for (jp = 0; jp < 2; jp++) {
        v = 0.0f;
        for (i = 0; i < 20; i++) {
            s32 nx = (i + 1) % 20;
            *(V4_005521F8 *)q = pts[jp + 1][i];
            *(V4_005521F8 *)(q + 0x10) = pts[jp + 1][nx];
            *(V4_005521F8 *)(q + 0x20) = pts[jp][i];
            *(V4_005521F8 *)(q + 0x30) = pts[jp][nx];
            vn = v + 0.05f;
            tc[5] = v;
            tc[1] = v;
            *(s32 *)(q + 0x48) = cc;
            *(s32 *)(q + 0x4C) = cc;
            tc[0] = u0;
            tc[2] = u0;
            tc[3] = vn;
            tc[4] = u1;
            tc[6] = u1;
            tc[7] = vn;
            func_003D2DA0(q, 0, 0);
            v = vn;
        }
        cc = col;
    }

    func_003D93B0(q, 0xE, 1, 0x80);
    c2 = ((s32)(life * 80.0f) << 24) | 0x804020;
    tmp = *(V4_005521F8 *)rec;
    tc[0] = 0.0f;
    tc[4] = 0.5f;
    tc[1] = 0.0f;
    tc[2] = 0.0f;
    tc[3] = 1.0f;
    tc[5] = 0.0f;
    tc[7] = 1.0f;
    *(s32 *)(q + 0x4C) = c2;
    *(s32 *)(q + 0x48) = c2;
    *(s32 *)(q + 0x44) = c2;
    *(s32 *)(q + 0x40) = c2;
    tc[6] = 0.5f;
    sub_005521F8(&view, (V4_005521F8 *)(*(u8 **)(p + 0x3C) + 0x23A0), &tmp);
    func_0038CE90(&mat[1], &mat[0], &view);
    func_0038CF68(&side, &mat[1], 1.0f);
    r = (V4_005521F8 *)(rec + 0x10);
    cc = 0x804020;
    for (i = 1; i >= 0; i--) {
        add_005521F8((V4_005521F8 *)q, r, &side);
        cur = *r;
        prev = r[-1];
        prev2 = r[-1];
        r++;
        sub_005521F8((V4_005521F8 *)(q + 0x10), &cur, &side);
        add_005521F8((V4_005521F8 *)(q + 0x20), &prev, &side);
        sub_005521F8((V4_005521F8 *)(q + 0x30), &prev2, &side);
        *(s32 *)(q + 0x4C) = cc;
        *(s32 *)(q + 0x48) = cc;
        func_003D2DA0(q, 0, 0);
        cc = c2;
        f0 = tc[4];
        tc[6] = 3.0f;
        tc[0] = f0;
        tc[2] = f0;
        tc[4] = 3.0f;
    }

    func_003D93B0(q, 0x17, 1, 0x80);
    base = *(f32 *)(rec + 0x58);
    c2 = ((s32)(life * 255.0f) << 24) | 0x804020;
    func_0038CF68(&side, &mat[1], 0.1f);
    tc[7] = 1.0f;
    tc[0] = 0.0f;
    tc[4] = base + 0.5f;
    tc[1] = 0.0f;
    tc[2] = 0.0f;
    tc[3] = 1.0f;
    *(s32 *)(q + 0x4C) = c2;
    *(s32 *)(q + 0x48) = c2;
    *(s32 *)(q + 0x44) = c2;
    *(s32 *)(q + 0x40) = c2;
    tc[5] = 0.0f;
    tc[6] = base + 0.5f;
    r = (V4_005521F8 *)(rec + 0x10);
    cc = 0x7F7F7F;
    for (i = 1; i >= 0; i--) {
        add_005521F8((V4_005521F8 *)q, r, &side);
        cur = *r;
        prev = r[-1];
        prev2 = r[-1];
        r++;
        sub_005521F8((V4_005521F8 *)(q + 0x10), &cur, &side);
        add_005521F8((V4_005521F8 *)(q + 0x20), &prev, &side);
        sub_005521F8((V4_005521F8 *)(q + 0x30), &prev2, &side);
        *(s32 *)(q + 0x4C) = cc;
        *(s32 *)(q + 0x48) = cc;
        func_003D2DA0(q, 0, 0);
        cc = c2;
        f0 = tc[4];
        tc[0] = f0;
        tc[4] = base + 3.0f;
        tc[2] = f0;
        tc[6] = base + 3.0f;
    }
}
