#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L04_0035A050 */
__asm__(".extern D_L04_001DD4E8, 4");
__asm__(".extern D_L04_001DD4EC, 4");
__asm__(".extern D_L04_001DD4F0, 4");
__asm__(".extern D_L04_001DD4F4, 4");
extern s32 D_001D545C;
extern f32 D_L04_001DD4E8;
extern s32 D_L04_001DD4EC;
extern f32 D_L04_001DD4F0;
extern s32 D_L04_001DD4F4;
extern s32 func_L01_0044C108(void *);
extern void func_L04_0035A158(void *, void *);
extern void func_L04_0035BC10(void *, void *);
extern void func_L04_0035C9C8(void);
extern void func_L01_00404A10_0035A050(void *, void *);
void func_L04_0035A050(u8 *o) {
    u8 *m = *(u8 **)(o + 0x68);
    if (D_001D545C == 11 && D_L04_001DD4E8 != 255.0f) {
        D_L04_001DD4E8 = 255.0f;
        D_L04_001DD4F0 = 255.0f;
        D_L04_001DD4EC = 255;
        D_L04_001DD4F4 = 255;
    } else if (D_001D545C == 19 && D_L04_001DD4E8 != 255.0f) {
        D_L04_001DD4E8 = 64.0f;
        D_L04_001DD4F0 = 64.0f;
        D_L04_001DD4EC = 64;
        D_L04_001DD4F4 = 64;
    }
    if (func_L01_0044C108(o + 0x10)) {
        if (o[0x20] == 0) func_L04_0035A158(o, m);
        if (o[0x20] == 1) {
            func_L04_0035BC10(o, m);
            func_L01_00404A10_0035A050(func_L04_0035C9C8, o);
        }
    }
}
/* localdecomp:end func_L04_0035A050 */

/* localdecomp:start func_L04_0035A158 */
/* PROVISIONAL, VU0 j-constraint form (docs/wiki/Matching-Patterns.md, "VU0 j-form") */
typedef struct {
    vu0_v4 p0;
    vu0_v4 p1;
    s32 st;
    s32 t;
    u8 pad28[8];
} Seg_0035A158;

typedef struct {
    s32 st;
    s32 t;
    u8 *moby;
    s32 time;
} Slot_0035A158;

typedef struct {
    s32 w0;
    u8 *moby;
    u8 *target;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    s32 w1C;
    s32 w20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 pad3C[4];
    u32 w40;
    u32 w44;
    s32 w48;
    s32 w4C;
    Seg_0035A158 seg[4];
    Slot_0035A158 slot[4];
    vu0_v4 v150;
} S_0035A158;

__asm__(".extern D_L04_001DFE80, 4");
extern u8 *D_L04_001DFE80;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001BBB18[][8];
extern u8 *func_L04_003BB5A0(u8 *);
extern u8 *func_L04_003BB468(u8 *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L04_003796C8(u8 *);
extern u8 *func_L04_00379410(void *);
extern s32 func_L01_004450F0(u8 *, s32, s32);

void func_L04_0035A158(void *ov, void *mv) {
    u8 *o = ov;
    S_0035A158 *m = mv;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    u8 *t;
    s32 i;
    s32 k;

    o[0x30] = 0x20;
    *(s16 *)(o + 0x32) = 0x20;
    m->w0 = 0;
    m->moby = 0;
    m->target = 0;
    m->w30 = 0;
    if (m->w14 >= 2) {
        m->w14 = 1;
    } else if (m->w14 < 0) {
        m->w14 = 0;
    }
    if (m->wC != -1 || m->w10 != -1) {
        m->w18 = m->w14;
    } else {
        m->w18 = 1;
    }
    m->w2C = 0;
    for (i = 0; i < 4; i++) {
        m->seg[i].t = 0;
        m->seg[i].st = 0;
        m->slot[i].st = 0;
        m->slot[i].t = 0;
        m->slot[i].moby = 0;
        m->slot[i].time = 0;
    }
    m->w40 = 0xFFFFFFFF;
    m->w44 = 0xFFFFFFFF;
    t = 0;
    if (m->w20 != -1) {
        if (m->w20 != 0) {
            t = func_L04_003BB5A0(o);
        } else {
            t = func_L04_003BB468(o);
        }
    }
    o[0x30] = 0xFE;
    if (D_001D545C == 11) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
    }
    if (m->w48 != 0 && t != 0) {
        *(s32 *)(t + 0x98) = 0;
        *(u16 *)(t + 0x34) = (*(u16 *)(t + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(t, 1);
    }
    k = m->w4C;
    if (k != -1) {
        u8 *p = D_L04_001DFE80 + (k << 7);
        *(u16 *)(o + 0x34) |= 0x100;
        {
            vu0_q qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(p + 0x30)));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(o + 0x10)));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qr));
        }
        func_0038CF68(&a, &a, 1.0f);
        func_003C5180(o + 0x10, &b, 1);
        func_0038CF68(&b, &b, 1.0f);
        func_0038CE90(&c, &a, &b);
        func_0038CF68(&c, &c, 1.0f);
        *(vu0_q *)(o + 0xC0) = *(vu0_q *)&a;
        *(vu0_q *)(o + 0xD0) = *(vu0_q *)&c;
        *(vu0_q *)(o + 0xE0) = *(vu0_q *)&b;
    }
    if (m->w1C != 0) {
        if ((o[0xB0] != 0xFF && (D_001BBC40[D_001D545C][o[0xB0]] & 0x80)) ||
            (m->w34 != -1 && D_001BBB18[D_001D545C][m->w34])) {
            m->w18 = m->w14 ^ 1;
            m->w2C = 0;
            if (m->w1C != 0) {
                m->wC = -1;
                m->w10 = -1;
            }
            if (m->w38 != -1) {
                u8 *v = D_L04_001DFE80 + (m->w38 << 7);
                *(vu0_q *)&a = *(vu0_q *)(v + 0x30);
                func_0038CE20(&b, v, D_001D545C == 11 ? 80.0f : 40.0f);
                vec_add_ba(&b, &b, &a);
                vec_sub_ab(&c, &b, &a);
                func_0038CF68(&c, &c, 1.0f);
                if (m->moby != 0) {
                    func_L04_003796C8(m->moby);
                }
                t = func_L04_00379410(&a);
                m->moby = t;
                *(vu0_q *)&m->v150 = *(vu0_q *)&c;
                m->slot[0].st = 4;
            }
        }
    }
    func_L01_004450F0(o, 1, -1);
}
/* localdecomp:end func_L04_0035A158 */

/* localdecomp:start func_L04_0035A4F8 */
__asm__(".extern D_L04_001DF940_0035A4F8, 4");
extern s32 D_L04_001DF940_0035A4F8;

void func_L04_0035A4F8(s32 *a, s32 *b) {
    if (a[8] == 1) {
        s32 t = D_L04_001DF940_0035A4F8;
        a[8] = 2;
        a[9] = t;
        b[0] = 0;
        b[2] = 0;
        b[3] = 0;
    }
}
/* localdecomp:end func_L04_0035A4F8 */

/* localdecomp:start func_L04_0035A528 */
extern s32 D_L04_001DF940;

void func_L04_0035A528(s32 *a, s32 *b) {
    if (a[8] != 1) {
        if (a[8] == 2) {
            a[9] = 0;
        } else {
            a[9] = D_L04_001DF940;
        }
        a[8] = 1;
    }
    b[1] = D_L04_001DF940;
}
/* localdecomp:end func_L04_0035A528 */

/* localdecomp:start func_L04_0035A568 */
extern u8 *D_L04_001DFD9C;
u8 *func_L04_0035A568(u8 *a0, u8 *a1) {
    u8 *p = *(u8 **)(a0 + 104);
    if ((*(s32 *)(p + 36) != -1 && a1 == D_L04_001DFD9C + (*(s32 *)(p + 36) << 8)) ||
        (*(s32 *)(p + 40) != -1 && a1 == D_L04_001DFD9C + (*(s32 *)(p + 40) << 8))) {
        return a1;
    }
    return 0;
}
/* localdecomp:end func_L04_0035A568 */

/* localdecomp:start func_L04_0035A5B8 */
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;
extern u8 D_L04_001E95A0[];
extern s32 func_003D3CB0(void *, Vec4 *, s32, s32, s32);
extern void func_L01_00446630(Vec4 *, void *, void *, void *);
extern float func_L01_0040E548(void *, Vec4 *);
s32 func_L04_0035A5B8(void *a, Vec4 *pos, void *b) {
    Vec4 tmp;
    if (func_003D3CB0(a, pos, 2, 0, 0)) {
        func_L01_00446630(&tmp, a, D_L04_001E95A0, b);
    } else {
        tmp = *pos;
    }
    if (func_L01_0040E548(b, &tmp) > 0.16000001f) return 0;
    return 1;
}
/* localdecomp:end func_L04_0035A5B8 */

/* localdecomp:start func_L04_0035A660 */
s32 func_L04_0035A660(u8 **arr, s32 *n, u8 *o) {
    if (*n >= 15) {
        return 0;
    }
    arr[*n] = o;
    (*n)++;
    *(s32 *)(o + 152) = 0;
    return 1;
}
/* localdecomp:end func_L04_0035A660 */

/* localdecomp:start func_L04_0035A6A0 */
void func_L04_0035A6A0(u8 **arr, s32 *n) {
    s32 i;
    for (i = 0; i < *n; i++) {
        u8 *o = arr[i];
        *(s32 *)(o + 152) = *(s32 *)(*(u8 **)(o + 36) + 16);
    }
    *n = 0;
}
/* localdecomp:end func_L04_0035A6A0 */
