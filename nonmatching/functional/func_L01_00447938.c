/* functional: high. Not byte-exact (about 470 words differ in register allocation and loop shape) but the frame size (0x180) and all 33 calls match in order. Written from the PAL assembly with no draft. Differences from retail: an unknown primitive type adds weight 0 (retail adds a stale stack slot) and a pick that runs past the last weight is clamped to the last primitive (retail reads one slot beyond the list). func_0012FF10 (boot_elf, used by the level code as func_12FF10) is assumed to scale a scratchpad vector by f12; func_L01_0040E408 divides xyz by f12; func_0038D000 is the matrix transform (vector, vector, matrix). */
#include "vu0.h"
typedef struct {
    u32 header;
    union {
        s32 index;
        f32 length;
        struct {
            s16 a;
            s16 b;
        } ends;
    } v4;
    u32 pad8;
    f32 radius;
    vu0_v4 vec;
} Prim_00447938;

typedef struct {
    u8 pad0[2];
    s16 init;
    s32 count;
    u8 pad8[8];
    Prim_00447938 prims[1];
} PrimTable_00447938;

extern s32 func_003C97F0(void *, s32, s32);
extern void func_0038CE50(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0040E408(void *, void *, f32);
extern void func_0012FF10(void *, void *, f32);

s32 func_L01_00447938(u8 *obj, s32 max, vu0_v4 *out, s32 mask, f32 density) {
    PrimTable_00447938 *table;
    Prim_00447938 *prim;
    Prim_00447938 *list[20];
    f32 weight[20];
    vu0_v4 a, b, c, d, e;
    vu0_v4 *scratch = (vu0_v4 *)0x70000000;
    f32 scale, total, r, len, h, u, rr, theta, pick;
    s32 type, idx, k, cnt, i, n, last;

    table = *(PrimTable_00447938 **)(*(u8 **)(obj + 0x24) + 0x10);
    if (table == 0) {
        return 0;
    }
    if (table->init != 0) {
        func_003C97F0(obj, table->init, 0);
    }
    if (table->count <= 0) {
        return 0;
    }
    prim = table->prims;
    total = 0.0f;
    cnt = 0;
    idx = 0;
    k = 0;
    do {
        s32 header = prim->header;
        last = (u32)header >> 31;
        type = header & 0xFF;
        if (((mask >> idx) & 1) && (header & 0x20000)) {
            list[k] = prim;
            scale = *(f32 *)(obj + 0x2C);
            switch (type) {
            case 0:
            case 1:
                *(vu0_q *)&a = *(vu0_q *)&prim->vec;
                func_0038CE50(&a, &a, scale * (1.0f / 1024.0f));
                r = a.w;
                weight[k] = r * 4.1887903213500977f * r * r;
                break;
            case 2:
                *(vu0_q *)&a = *(vu0_q *)&scratch[prim->v4.index];
                *(vu0_q *)&b = *(vu0_q *)&prim->vec;
                vec_add_ab(&a, &a, &b);
                func_0038CE20(&a, &a, scale * (1.0f / 1024.0f));
                r = prim->radius * scale * (1.0f / 1024.0f);
                weight[k] = r * 4.1887903213500977f * r * r;
                break;
            case 3:
                *(vu0_q *)&a = *(vu0_q *)&prim->vec;
                func_0038CE20(&a, &a, scale);
                r = a.w * scale * (1.0f / 1024.0f);
                len = prim->v4.length * (scale * (1.0f / 1024.0f));
                weight[k] = r * 4.187743186950684f * r * r + r * 1.5707963705062866f * r * len;
                break;
            case 4:
                func_0012FF10(&a, &scratch[prim->v4.ends.a], scale * (1.0f / 1024.0f));
                func_0012FF10(&b, &scratch[prim->v4.ends.b], scale * (1.0f / 1024.0f));
                vec_sub_ab(&c, &a, &b);
                len = func_0038CEA8(&c);
                r = prim->radius * scale * (1.0f / 1024.0f);
                weight[k] = r * 1.5707963705062866f * r * len;
                break;
            default:
                /* retail adds a stale (uninitialised) weight slot here; 0 is used */
                weight[k] = 0.0f;
                break;
            }
            total += weight[k];
            k++;
        }
        prim++;
        idx++;
    } while (last == 0);
    cnt = k;

    n = (s32)(density * total + 0.5f);
    if (max < n) {
        n = max;
    }
    if (n <= 0) {
        return n;
    }

    for (i = 0; i < n; i++) {
        scale = *(f32 *)(obj + 0x2C);
        pick = func_003824E0(0.0f, total);
        k = 0;
        if (cnt > 0 && !(pick < weight[0])) {
            k = 1;
            for (;;) {
                if (!(k < cnt)) {
                    break;
                }
                pick -= weight[k - 1];
                if (pick < weight[k]) {
                    break;
                }
                k++;
            }
        }
        if (k >= cnt) {
            k = cnt - 1; /* retail reads one past the list here */
        }
        prim = list[k];
        type = prim->header & 0xFF;
        switch (type) {
        case 0:
        case 1:
        case 2:
            if (type < 2) {
                *(vu0_q *)&a = *(vu0_q *)&prim->vec;
                func_0038CE20(&a, &a, scale);
                r = a.w;
            } else {
                *(vu0_q *)&a = *(vu0_q *)&scratch[prim->v4.index];
                *(vu0_q *)&b = *(vu0_q *)&prim->vec;
                vec_add_ab(&a, &a, &b);
                func_0038CE20(&a, &a, scale);
                r = prim->radius;
            }
            rr = r * scale * (1.0f / 1024.0f);
            func_L01_0040E408(&a, &a, 1024.0f);
            do {
                b.x = func_003824E0(-rr, rr);
                b.y = func_003824E0(-rr, rr);
                b.z = func_003824E0(-rr, rr);
            } while (!(func_0038CEA8(&b) <= rr));
            vec_add_ba(&b, &b, &a);
            func_0038D000(&b, &b, obj + 0xC0);
            vec_add_ab(&out[i], &b, obj + 0x10);
            break;
        case 3:
            *(vu0_q *)&a = *(vu0_q *)&prim->vec;
            func_0038CE20(&a, &a, scale);
            r = a.w * scale;
            h = prim->v4.length * scale;
            func_L01_0040E408(&a, &a, 1024.0f);
            r = r * (1.0f / 1024.0f);
            h = h * (1.0f / 1024.0f);
            u = func_003824E0(0.0f, r * r);
            rr = sqrt_asm(u);
            len = func_003824E0(0.0f, h);
            theta = func_00382538();
            b.x = func_0038D098(theta) * rr;
            b.y = func_0038D0B0(theta) * rr;
            b.z = len;
            vec_add_ab(&b, &b, obj + 0x10);
            vec_add_ba(&out[i], &a, &b);
            break;
        case 4:
            func_0012FF10(&a, &scratch[prim->v4.ends.a], scale);
            func_0012FF10(&b, &scratch[prim->v4.ends.b], scale);
            vec_sub_ba(&c, &b, &a);
            func_0038CE20(&c, &c, func_003824E0(0.0f, 1.0f));
            vec_add_ab(&d, &c, &a);
            func_L01_0040E408(&d, &d, 1024.0f);
            rr = prim->radius * scale * (1.0f / 1024.0f);
            do {
                e.x = func_003824E0(-rr, rr);
                e.y = func_003824E0(-rr, rr);
                e.z = func_003824E0(-rr, rr);
            } while (!(func_0038CEA8(&e) <= rr));
            vec_add_ba(&e, &e, &d);
            func_0038D000(&e, &e, obj + 0xC0);
            vec_add_ab(&out[i], &e, obj + 0x10);
            break;
        default:
            break;
        }
    }
    return n;
}
