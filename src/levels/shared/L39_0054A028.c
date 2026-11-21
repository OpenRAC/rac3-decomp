#include "common.h"

/* localdecomp:start func_L39_0054A028 */
typedef struct V4_0054A028 {
    f32 x, y, z, w;
} V4_0054A028;
typedef struct V3_0054A028 {
    f32 x, y, z;
} V3_0054A028;
typedef struct O_0054A028 {
    char pad0[0x14];
    s32 (**vt)(void *);
} O_0054A028;
static __inline__ void set_0054A028(V4_0054A028 *d, V3_0054A028 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
    d->w = 0;
}
extern void func_003C2F58(void *, s32, void *);
extern O_0054A028 *func_L39_0061D1D8(s32);
extern u8 *func_L39_0054AC10(void *, void *, s32, void *, f32, s32, s32, f32);
extern s32 func_L39_00577818(void);
extern s32 func_L39_0066E010(s32, s32, void *, s32, s32);

void func_L39_0054A028(u8 *a0, u8 *a1) {
    u8 *c = *(u8 **)(a0 + 0x68);
    V4_0054A028 buf;
    V4_0054A028 v1;
    V4_0054A028 v2;
    s32 h = 0;
    s32 k;
    s32 id;
    s32 i;
    u8 *r;
    O_0054A028 *o;
    func_003C2F58(a0, 0, &buf);
    set_0054A028(&v1, (V3_0054A028 *)(a1 + 0x3C));
    set_0054A028(&v2, (V3_0054A028 *)(a1 + 0x30));
    id = *(s32 *)(a1 + 0x2C);
    i = -1;
    if (id != 0xFFFFFFFF) {
        o = func_L39_0061D1D8(id);
        if (o) {
            h = o->vt[4](o);
        }
        i = (s32)v2.y;
    }
    r = func_L39_0054AC10(a0, &buf, h, &v1, v2.z, *(s32 *)(c + 0x40), i, v2.x);
    k = -1;
    if (func_L39_00577818()) {
        k = func_L39_0066E010(*(s32 *)(c + 0x40), 4, r, *(s32 *)(c + 0x20), 0);
    }
    if (r) {
        *(u8 **)(r + 0xB8) = a0;
        *(s32 *)(*(u8 **)(r + 0x68) + 0x54) = k;
    }
}
/* localdecomp:end func_L39_0054A028 */

/* localdecomp:start func_L39_0054A160 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_0054A160;
typedef struct { f32 x, y, z; } V3_0054A160;

static __inline__ void copy_0054A160(V3_0054A160 *d, Q_0054A160 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

extern void func_0038CE20(f32 *, void *, f32);
extern u32 func_L39_0061D780(s32);
extern s32 func_L39_0054AA20(void);

void func_L39_0054A160(u8 *obj, u8 *msg) {
    Q_0054A160 vec;
    Q_0054A160 w;
    Q_0054A160 v;
    u8 *p;
    f32 y;

    if (msg[3] == 8) {
        p = *(u8 **)(obj + 0x68);
        func_0038CE20(&vec.x, obj + 0xD0, -1.0f);
        copy_0054A160((V3_0054A160 *)(msg + 0x18), &vec);
        if (*(s32 *)(p + 0x20) != 0) {
            *(u32 *)(msg + 8) = func_L39_0061D780(*(s32 *)(p + 0x20));
            y = (f32)func_L39_0054AA20();
            *(u128_t *)&v = 0;
            v.x = *(f32 *)(p + 0x44);
            v.y = y;
            v.z = *(f32 *)(p + 0x28);
            w = v;
            copy_0054A160((V3_0054A160 *)(msg + 0xC), &w);
        } else {
            *(u32 *)(msg + 8) = 0xFFFFFFFF;
        }
    }
}
/* localdecomp:end func_L39_0054A160 */
