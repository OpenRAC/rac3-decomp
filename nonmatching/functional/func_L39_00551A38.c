/* functional: medium. Multiplayer-menu projectile trail renderer: for each of the state's trail points (D_L39_003C13E0 ring slot state+0x3A, 0x30 bytes per point) builds two camera-facing ribbon quads (cross of segment and view vector, half-width = point w, the second 3x wider), textured with a scrolling u (state+0x48), colours blended along the trail with func_0038DBD8 (alpha scaled by life*0.0/255/128, halved when the owner has the check word 0x1D or owner+0x1310), and submits one quad per segment pair with func_003D2DA0; the retail table-decode check on owner+0x19E4 is reproduced in a static helper; vector math component-wise; 376 words differ (stack layout/scheduling). Unverified: exact quad vertex/colour field layout beyond what the stores show. */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00551A38;

extern u8 D_L39_003C13E0[];
extern u8 D_L39_004997E0[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);

/* the player block's check word (retail's table decode, 8 bytes from D_L39_004997E0 keyed by owner+0x19E4) */
static s32 func_L39_00551A38_check(u8 *owner) {
    u8 buf[8];
    u32 *w = (u32 *)buf;
    u8 *addr = owner + 0x19E4;
    s32 b = owner[0x19E4];
    s32 k;
    s32 idx;

    if (b == 0) return 0;
    for (k = 0; k < 8; k++) {
        idx = (((s32)(u32)addr - b) + 5 * k) & 7;
        buf[k] = D_L39_004997E0[b + 1 + idx * 255];
    }
    w[0] ^= (u32)addr;
    w[1] ^= w[0];
    return w[1];
}

void func_L39_00551A38(u8 *m) {
    u8 *p;
    u8 *tbl;
    u8 *owner;
    u8 qa[0x90];
    u8 qb[0x90];
    V4_00551A38 side;
    V4_00551A38 cross;
    V4_00551A38 view;
    V4_00551A38 dir;
    V4_00551A38 tmp;
    V4_00551A38 na0;
    V4_00551A38 na1;
    V4_00551A38 nb0;
    V4_00551A38 nb1;
    f32 scroll;
    f32 s;
    f32 inv;
    f32 t;
    s32 colA;
    s32 startA;
    s32 startB;
    s32 colB;
    s32 endA;
    s32 endB;
    s32 c;
    s32 i;
    s32 n;
    f32 *a;
    f32 *b;

    p = *(u8 **)(m + 0x68);
    if (*(s16 *)(p + 0x30) < 2) return;
    if (*(s16 *)(p + 0x32) == 0) return;
    tbl = D_L39_003C13E0 + p[0x3A] * 0x12C0;

    func_003D93B0(qa, 0xE, 1, 0x80);
    a = (f32 *)(qa + 0x50);
    a[0] = 0.0f; a[2] = 0.0f; a[4] = 1.0f; a[6] = 1.0f;
    a[1] = 0.0f; a[3] = 1.0f; a[5] = 0.0f; a[7] = 1.0f;
    scroll = a[0];
    a[0] = *(f32 *)(p + 0x48) + scroll;
    a[2] = a[0];
    a[4] = *(f32 *)(p + 0x48) + 1.0f;
    a[6] = a[4];
    func_003D93B0(qb, 0xE, 1, 0x80);
    b = (f32 *)(qb + 0x50);
    b[0] = scroll; b[2] = scroll; b[4] = 1.0f; b[6] = 1.0f;
    b[1] = scroll; b[3] = 1.0f; b[5] = scroll; b[7] = 1.0f;
    b[0] = *(f32 *)(p + 0x48) + scroll;
    b[2] = b[0];
    b[4] = *(f32 *)(p + 0x48) + 1.0f;
    b[6] = b[4];

    owner = *(u8 **)(p + 0x3C);
    s = (f32)*(s16 *)(p + 0x32) * *(f32 *)(p + 0x34);
    if (owner[0x1A14] != 0) {
        if (func_L39_00551A38_check(owner) == 0x1D || *(s32 *)(*(u8 **)(p + 0x3C) + 0x1310) != 0) {
            s = s * 0.5f;
        }
    }
    colA = ((s32)(s * 0.0f) << 24) | 0x804000;
    endA = ((s32)(s * 255.0f) << 24) | 0xFFFF00;
    colB = ((s32)(s * 0.0f) << 24) | 0xFF1010;
    endB = ((s32)(s * 128.0f) << 24) | 0x404000;
    startA = colA;
    startB = colB;
    *(s32 *)(qa + 0x44) = colA;
    *(s32 *)(qa + 0x40) = colA;
    *(s32 *)(qb + 0x44) = colB;
    *(s32 *)(qb + 0x40) = colB;

    tmp = *(V4_00551A38 *)tbl;
    dir.x = ((V4_00551A38 *)(tbl + 0x30))->x - ((V4_00551A38 *)tbl)->x;
    dir.y = ((V4_00551A38 *)(tbl + 0x30))->y - ((V4_00551A38 *)tbl)->y;
    dir.z = ((V4_00551A38 *)(tbl + 0x30))->z - ((V4_00551A38 *)tbl)->z;
    dir.w = ((V4_00551A38 *)(tbl + 0x30))->w;
    view.x = tmp.x - ((V4_00551A38 *)(*(u8 **)(p + 0x3C) + 0x23A0))->x;
    view.y = tmp.y - ((V4_00551A38 *)(*(u8 **)(p + 0x3C) + 0x23A0))->y;
    view.z = tmp.z - ((V4_00551A38 *)(*(u8 **)(p + 0x3C) + 0x23A0))->z;
    view.w = tmp.w;
    func_0038CE90(&cross, &dir, &view);
    func_0038CF68(&side, &cross, *(f32 *)(tbl + 0xC));
    *(V4_00551A38 *)qa = *(V4_00551A38 *)tbl;
    ((f32 *)qa)[0] += side.x; ((f32 *)qa)[1] += side.y; ((f32 *)qa)[2] += side.z;
    ((V4_00551A38 *)(qa + 0x10))->x = ((V4_00551A38 *)tbl)->x - side.x;
    ((V4_00551A38 *)(qa + 0x10))->y = ((V4_00551A38 *)tbl)->y - side.y;
    ((V4_00551A38 *)(qa + 0x10))->z = ((V4_00551A38 *)tbl)->z - side.z;
    ((V4_00551A38 *)(qa + 0x10))->w = ((V4_00551A38 *)tbl)->w;
    func_0038CE20(&side, &side, 3.0f);
    *(V4_00551A38 *)qb = *(V4_00551A38 *)tbl;
    ((f32 *)qb)[0] += side.x; ((f32 *)qb)[1] += side.y; ((f32 *)qb)[2] += side.z;
    ((V4_00551A38 *)(qb + 0x10))->x = ((V4_00551A38 *)tbl)->x - side.x;
    ((V4_00551A38 *)(qb + 0x10))->y = ((V4_00551A38 *)tbl)->y - side.y;
    ((V4_00551A38 *)(qb + 0x10))->z = ((V4_00551A38 *)tbl)->z - side.z;
    ((V4_00551A38 *)(qb + 0x10))->w = ((V4_00551A38 *)tbl)->w;

    n = *(s16 *)(p + 0x30);
    inv = 1.0f / (f32)n;
    for (i = 1; i < *(s16 *)(p + 0x30); i++) {
        V4_00551A38 *cur = (V4_00551A38 *)(tbl + i * 0x30);
        V4_00551A38 *prev = (V4_00551A38 *)(tbl + i * 0x30 - 0x30);
        V4_00551A38 *cam = (V4_00551A38 *)(*(u8 **)(p + 0x3C) + 0x23A0);

        view.x = cur->x - cam->x; view.y = cur->y - cam->y; view.z = cur->z - cam->z; view.w = cur->w;
        dir.x = cur->x - prev->x; dir.y = cur->y - prev->y; dir.z = cur->z - prev->z; dir.w = cur->w;
        func_0038CE90(&cross, &dir, &view);
        func_0038CF68(&side, &cross, cur->w);
        na0.x = cur->x + side.x; na0.y = cur->y + side.y; na0.z = cur->z + side.z; na0.w = cur->w;
        na1.x = cur->x - side.x; na1.y = cur->y - side.y; na1.z = cur->z - side.z; na1.w = cur->w;
        func_0038CE20(&side, &side, 3.0f);
        nb0.x = cur->x + side.x; nb0.y = cur->y + side.y; nb0.z = cur->z + side.z; nb0.w = cur->w;
        nb1.x = cur->x - side.x; nb1.y = cur->y - side.y; nb1.z = cur->z - side.z; nb1.w = cur->w;
        t = (f32)i * inv;
        c = func_0038DBD8(startA, endA, t);
        *(s32 *)(qa + 0x48) = c;
        *(s32 *)(qa + 0x4C) = c;
        colA = c;
        c = func_0038DBD8(startB, endB, t);
        *(s32 *)(qb + 0x48) = c;
        *(s32 *)(qb + 0x4C) = c;
        colB = c;
        func_003D2DA0(qa, 0, 0);
        func_003D2DA0(qb, 0, 0);
        *(V4_00551A38 *)qa = na0;
        *(V4_00551A38 *)(qa + 0x10) = na1;
        *(V4_00551A38 *)qb = nb0;
        *(V4_00551A38 *)(qb + 0x10) = nb1;
        *(s32 *)(qa + 0x40) = colA;
        startA = colA;
    startB = colB;
    *(s32 *)(qa + 0x44) = colA;
        *(s32 *)(qb + 0x40) = colB;
        *(s32 *)(qb + 0x44) = colB;
    }
}
