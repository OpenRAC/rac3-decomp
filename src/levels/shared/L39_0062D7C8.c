#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

INCLUDE_ASM("asm/levels", func_L39_0062D7C8);

INCLUDE_ASM("asm/levels", func_L39_0062DA30);

INCLUDE_ASM("asm/levels", func_L39_0062E930);

INCLUDE_ASM("asm/levels", func_L39_0062EF58);

INCLUDE_ASM("asm/levels", func_L39_0062FCF0);

INCLUDE_ASM("asm/levels", func_L39_0062FE58);

INCLUDE_ASM("asm/levels", func_L39_006302E0);

INCLUDE_ASM("asm/levels", func_L39_006304A8);

INCLUDE_ASM("asm/levels", func_L39_00630548);

INCLUDE_ASM("asm/levels", func_L39_00631100);

INCLUDE_ASM("asm/levels", func_L39_006314E0);

INCLUDE_ASM("asm/levels", func_L39_006318E8);

/* localdecomp:start func_L39_006319D8 */
s32 func_L39_006319D8(char *a0, s32 a1) {
    char *p = a0 + a1 * 80;
    s32 x = (*(s32 *)(p + 1140) == 2) ? *(s32 *)(p + 1144) : -1;
    return x == 14 || x == 15;
}
/* localdecomp:end func_L39_006319D8 */

/* localdecomp:start func_L39_00631A08 */
s32 func_L39_00631A08(s32 a0, u8 *p, s32 v) {
    if (v == 255) {
        v = p[169];
    }
    return v;
}
/* localdecomp:end func_L39_00631A08 */

/* localdecomp:start func_L39_00631A20 */
s32 func_L39_00631A20(u8 *a0, s32 a1, f32 *a2) {
    *a2 = 0.0f;
    switch (a1) {
    case 28:
    case 29:
    case 31:
        if (*(f32 *)(a0 + 1576) > 25.0f) {
            *a2 = -1.4835298f;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00631A20 */

/* localdecomp:start func_L39_00631A88 */

f32 func_L39_00631A88(S_0062F240 *a0, int a1)
{
    int n;
    if (a1 >= 32) {
        a1 = 31;
    }
    n = a0->count;
    if (n < a1) {
        a1 = n;
    }
    return a0->hist[(a0->head - a1 + 31) % 32];
}
/* localdecomp:end func_L39_00631A88 */

INCLUDE_ASM("asm/levels", func_L39_00631AD8);

INCLUDE_ASM("asm/levels", func_L39_00631CB0);

INCLUDE_ASM("asm/levels", func_L39_00631E90);

/* localdecomp:start func_L39_00632100 */

extern f32 func_0038CED8(Vec4 *);
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038D160(f32, f32);

f32 func_L39_00632100(u8 *m, Vec4 *v) {
    Vec4 t;

    switch (m[6662]) {
    case 0:
        return func_0038D160(v->f[2], func_0038CED8(v));
    case 1:
    case 2:
        t.q = v->q;
        func_0038D028(&t, &t, m + 96);
        return func_0038D160(t.f[2], func_0038CED8(&t));
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00632100 */

INCLUDE_ASM("asm/levels", func_L39_00632180);

INCLUDE_ASM("asm/levels", func_L39_006321F0);

/* localdecomp:start func_L39_00632298 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);

extern void func_0038CFB8(f32 *, f32 *, f32);

void func_L39_00632298(Obj62FA50 *o, f32 *dst, f32 *src, f32 scale) {
    switch (o->mode) {
    case 0:
        func_0038CFB8(dst, src, scale);
        break;
    case 1:
    case 2:
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, src, o->m1);
        func_0038CFB8(dst, dst, scale);
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, dst, o->m0);
        break;
    }
}
/* localdecomp:end func_L39_00632298 */

INCLUDE_ASM("asm/levels", func_L39_00632328);

/* localdecomp:start func_L39_006323B8 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
void func_L39_006323B8(u8 *p, float *v, void *m, float s) {
    switch (p[6662]) {
    case 0:
        v[0] *= s;
        v[1] *= s;
        break;
    case 1:
    case 2:
        ((void (*)(float *, void *, void *))func_0038D028)(v, m, p + 96);
        v[0] *= s;
        v[1] *= s;
        ((void (*)(float *, void *, void *))func_0038D028)(v, v, p + 32);
        break;
    }
}
/* localdecomp:end func_L39_006323B8 */

INCLUDE_ASM("asm/levels", func_L39_00632458);

/* localdecomp:start func_L39_00632558 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);



void func_L39_00632558(S_62FD10 *s, Vec4 *out, Vec4 *in, f32 z) {
    s32 m = s->mode;

    if (m == 0) {
        out->q = in->q;
        out->f[2] = z;
        return;
    }
    if (m < 0) {
        return;
    }
    if (m < 3) {
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, in, s->m60);
        out->f[2] = z;
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, out, s->m20);
    }
}
/* localdecomp:end func_L39_00632558 */

/* localdecomp:start func_L39_006325D8 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038CED8(Vec4 *);
extern void func_0038D328(float *, void *);
extern void func_0038D5B0(float *, float *);
float func_L39_006325D8(u8 *p, float *v) {
    float m[16];
    float inv[16];
    float t[4];
    switch (p[6662]) {
    case 0:
        return ((float (*)(float *))func_0038CED8)(v);
    case 1:
    case 2:
        func_0038D328(m, (void *)(*(s32 *)(p + 9508) + 240));
        func_0038D5B0(inv, m);
        ((void (*)(float *, void *, void *))func_0038D028)(t, v, inv);
        return ((float (*)(float *))func_0038CED8)(t);
    }
    return 0.0f;
}
/* localdecomp:end func_L39_006325D8 */

/* localdecomp:start func_L39_00632678 */
extern void func_0038D000(f32 *, f32 *, u8 *);
f32 func_L39_00632678(u8 *a, f32 *b) {
    f32 tmp[4];
    switch (a[6662]) {
    case 0:
        return b[2];
    case 1:
    case 2:
        func_0038D000(tmp, b, a + 96);
        return tmp[2];
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00632678 */

INCLUDE_ASM("asm/levels", func_L39_006326C8);

INCLUDE_ASM("asm/levels", func_L39_00632818);
