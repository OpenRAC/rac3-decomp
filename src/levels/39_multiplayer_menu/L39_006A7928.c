#include "common.h"

/* localdecomp:start func_L39_006A7928 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");
extern s32 **D_L39_0024D760;
extern s32 *D_L39_00247914;
extern s32 D_001A5CD0[];
extern s32 *D_001DC204_sda;
extern void func_00199050(void);
extern void func_L39_006D40B0(s32);
extern void func_L39_006DA680(s32, s32, s32);
extern void func_L39_006BD408(s32, s32);

void func_L39_006A7928(void)
{
    s32 s;

    func_00199050();
    if (D_001A5CD0[0x174 / 4] != 0) {
        D_001DC204_sda[0x284 / 4] = 0x15;
    } else {
        func_L39_006D40B0(((s32 *)D_L39_0024D760)[0x3C / 4]);
        s = D_L39_00247914[0xE0 / 4];
        func_L39_006DA680(((s32 *)D_L39_0024D760)[0x4C / 4], D_001A5CD0[0x78 / 4], 0);
        func_L39_006BD408(s, D_001A5CD0[0x78 / 4]);
        D_L39_00247914[0x284 / 4] = 0x1F;
    }
}
/* localdecomp:end func_L39_006A7928 */

/* localdecomp:start func_L39_006A79C0 */
typedef struct S_006A79C0_obj S_006A79C0_obj;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(S_006A79C0_obj *, s32, s32);
    u8 pad20[0x8];
    void (*f28)(S_006A79C0_obj *, f32, f32);
    void (*f2C)(S_006A79C0_obj *, f32, f32);
    u8 pad30[0x10];
    void (*f40)(S_006A79C0_obj *, s32);
    void (*f44)(S_006A79C0_obj *, s32, f32, f32);
    void (*f48)(S_006A79C0_obj *, s32, s32);
    void (*f4C)(S_006A79C0_obj *, s32, s32);
    u8 pad50[0xC];
    void (*f5C)(S_006A79C0_obj *, f32);
} S_006A79C0_vt;
struct S_006A79C0_obj {
    u8 pad0[0x60];
    S_006A79C0_vt *vt;
};
typedef struct {
    u8 pad0[0x110];
    S_006A79C0_obj *w[0x42];
} S_006A79C0;
typedef struct {
    f32 a, b, c, d;
    u32 e;
} S_006A79C0_r;
typedef struct {
    s32 a;
    f32 b, c, d, e;
    u32 f;
} S_006A79C0_q;
extern u8 D_001A5810[];
extern S_006A79C0_r D_L39_004B0478, D_L39_004B04A8, D_L39_004B0508, D_L39_004B0550, D_L39_004B0580;
extern S_006A79C0_q D_L39_004B04C0, D_L39_004B0598, D_L39_004B05B0;
extern f32 D_L39_004B0490[], D_L39_004B04D8[], D_L39_004B04F0[], D_L39_004B0520[], D_L39_004B0568[];
typedef struct {
    f32 x, y;
    f32 xs[5];
    f32 ys[5];
    f32 dy;
} S_006A79C0_t;
extern S_006A79C0_t D_L39_004B05C8, D_L39_004B0600;
extern const S_006A79C0_t D_L39_004B0638;
extern f32 D_L39_004B0670[];
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);

void func_L39_006A79C0(void *a0)
{
    S_006A79C0 *p = a0;
    s32 i, j, k;
    f32 y;

    func_L39_0068A6D0(p, 0, D_L39_004B0478.a, D_L39_004B0478.b, D_L39_004B0478.c, D_L39_004B0478.d, D_L39_004B0478.e);
    p->w[0]->vt->f28(p->w[0], D_L39_004B0490[0], D_L39_004B0490[1]);
    p->w[0]->vt->f2C(p->w[0], D_L39_004B0490[2], D_L39_004B0490[3]);
    p->w[0]->vt->f4C(p->w[0], 0x40, 1);
    p->w[0]->vt->f48(p->w[0], 3, 3);
    p->w[0]->vt->f1C(p->w[0], 1, 0);
    func_L39_0068A6D0(p, 1, D_L39_004B04A8.a, D_L39_004B04A8.b, D_L39_004B04A8.c, D_L39_004B04A8.d, D_L39_004B04A8.e);
    func_L39_0068A4A8(p, 0, D_L39_004B04C0.a, D_L39_004B04C0.b, D_L39_004B04C0.c, D_L39_004B04C0.d, D_L39_004B04C0.e, D_L39_004B04C0.f);
    p->w[1]->vt->f28(p->w[1], D_L39_004B04D8[0], D_L39_004B04D8[1]);
    p->w[1]->vt->f2C(p->w[1], D_L39_004B04D8[2], D_L39_004B04D8[3]);
    p->w[1]->vt->f40(p->w[1], 1);
    p->w[1]->vt->f4C(p->w[1], 0x40, 1);
    p->w[1]->vt->f48(p->w[1], 3, 3);
    p->w[1]->vt->f1C(p->w[1], 1, 0);
    p->w[1]->vt->f44(p->w[1], 1, D_L39_004B04D8[2], 0.0f);
    p->w[2]->vt->f28(p->w[2], D_L39_004B04F0[0], D_L39_004B04F0[1]);
    p->w[2]->vt->f2C(p->w[2], D_L39_004B04F0[2], D_L39_004B04F0[3]);
    p->w[2]->vt->f40(p->w[2], 1);
    p->w[2]->vt->f4C(p->w[2], 0x40, 1);
    p->w[2]->vt->f48(p->w[2], 3, 3);
    p->w[2]->vt->f1C(p->w[2], 1, 0);
    func_L39_0068A6D0(p, 2, D_L39_004B0508.a, D_L39_004B0508.b, D_L39_004B0508.c, D_L39_004B0508.d, D_L39_004B0508.e);
    p->w[3]->vt->f28(p->w[3], D_L39_004B0520[0], D_L39_004B0520[1]);
    p->w[3]->vt->f2C(p->w[3], D_L39_004B0520[2], D_L39_004B0520[3]);
    p->w[3]->vt->f4C(p->w[3], 0x40, 1);
    func_L39_0068A6D0(p, 3, D_L39_004B0550.a, D_L39_004B0550.b, D_L39_004B0550.c, D_L39_004B0550.d, D_L39_004B0550.e);
    p->w[4]->vt->f28(p->w[4], D_L39_004B0568[0], D_L39_004B0568[1]);
    p->w[4]->vt->f2C(p->w[4], D_L39_004B0568[2], D_L39_004B0568[3]);
    p->w[4]->vt->f1C(p->w[4], 1, 0);
    func_L39_0068A6D0(p, 4, D_L39_004B0580.a, D_L39_004B0580.b, D_L39_004B0580.c, D_L39_004B0580.d, D_L39_004B0580.e);
    func_L39_0068A4A8(p, 1, D_L39_004B0598.a, D_L39_004B0598.b, D_L39_004B0598.c, D_L39_004B0598.d, D_L39_004B0598.e, D_L39_004B0598.f);
    func_L39_0068A4A8(p, 2, D_L39_004B05B0.a, D_L39_004B05B0.b, D_L39_004B05B0.c, D_L39_004B05B0.d, D_L39_004B05B0.e, D_L39_004B05B0.f);

    for (i = 0; i < 5; i++) {
        if (D_001A5810[0xB7] == 3) {
            {
                S_006A79C0_obj *o = p->w[0x15 + i];
                f32 x = D_L39_004B0600.xs[i];
                f32 y = D_L39_004B0600.x;
                o->vt->f28(o, x, y);
            }
            {
                S_006A79C0_obj *o = p->w[0x15 + i];
                f32 x = D_L39_004B0600.ys[i];
                f32 y = D_L39_004B0600.y;
                o->vt->f2C(o, x, y);
            }
        } else {
            {
                S_006A79C0_obj *o = p->w[0x15 + i];
                f32 x = D_L39_004B05C8.xs[i];
                f32 y = D_L39_004B05C8.x;
                o->vt->f28(o, x, y);
            }
            {
                S_006A79C0_obj *o = p->w[0x15 + i];
                f32 x = D_L39_004B05C8.ys[i];
                f32 y = D_L39_004B05C8.y;
                o->vt->f2C(o, x, y);
            }
        }
        p->w[0x15 + i]->vt->f40(p->w[0x15 + i], 1);
        p->w[0x15 + i]->vt->f4C(p->w[0x15 + i], 0x40, 1);
        p->w[0x15 + i]->vt->f48(p->w[0x15 + i], 1, 3);
        p->w[0x15 + i]->vt->f1C(p->w[0x15 + i], 1, 0);
    }

    y = D_L39_004B0670[1];
    for (i = 0; i < 8; i++) {
        p->w[5 + i]->vt->f28(p->w[5 + i], D_L39_004B0670[0], y);
        p->w[5 + i]->vt->f2C(p->w[5 + i], D_L39_004B0670[2], D_L39_004B0670[3]);
        p->w[5 + i]->vt->f1C(p->w[5 + i], 0, 0);
        p->w[13 + i]->vt->f28(p->w[13 + i], D_L39_004B0670[0], y);
        p->w[13 + i]->vt->f2C(p->w[13 + i], D_L39_004B0670[2] * 0.7f, D_L39_004B0670[3] * 0.7f);
        p->w[13 + i]->vt->f1C(p->w[13 + i], 0, 0);
        y += D_L39_004B0670[5];
    }

    for (j = 0; j < 8; j++) {
        for (i = 0; i < 5; i++) {
            if (i == 0) {
                p->w[0x1A + j * 5]->vt->f5C(p->w[0x1A + j * 5], 0.2f);
                p->w[0x1A + j * 5]->vt->f44(p->w[0x1A + j * 5], 1, 0.2f, 0.0f);
            }
            p->w[0x1A + j * 5 + i]->vt->f28(p->w[0x1A + j * 5 + i], D_L39_004B0638.xs[i], D_L39_004B0638.x + D_L39_004B0638.dy * (f32)j);
            p->w[0x1A + j * 5 + i]->vt->f2C(p->w[0x1A + j * 5 + i], D_L39_004B0638.ys[i], D_L39_004B0638.y);
            p->w[0x1A + j * 5 + i]->vt->f40(p->w[0x1A + j * 5 + i], 1);
            p->w[0x1A + j * 5 + i]->vt->f4C(p->w[0x1A + j * 5 + i], 0x40, 1);
            p->w[0x1A + j * 5 + i]->vt->f48(p->w[0x1A + j * 5 + i], 1, 3);
            p->w[0x1A + j * 5 + i]->vt->f1C(p->w[0x1A + j * 5 + i], 1, 0);
        }
    }
}
/* localdecomp:end func_L39_006A79C0 */

/* localdecomp:start func_L39_006A8138 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct S_006A8138_obj S_006A8138_obj;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(S_006A8138_obj *, s32, s32);
    u8 pad20[0x4];
    void (*f24)(S_006A8138_obj *, s32);
} S_006A8138_vt;
struct S_006A8138_obj {
    u8 pad0[0x60];
    S_006A8138_vt *vt;
};
typedef struct {
    u8 pad0[0x11C];
    S_006A8138_obj *obj;
    u8 pad120[0x470 - 0x120];
    s32 f470;
    u8 f474;
    u8 pad475[3];
    s32 f478;
} S_006A8138;
extern s32 D_001A5CD0[];
extern s32 **D_L39_0024D760;
extern f32 D_L39_004B0538[];
extern u8 D_L39_002488C0[];
extern void func_L39_00689D28(void *, void *);
extern void *func_00381FF0(s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_00689F00(void *, s32, f32, f32, s32, s32, f32, f32, f32, f32);

void func_L39_006A8138(void *a0)
{
    S_006A8138 *p = a0;
    S_006A8138_vt *vt;
    s32 w;

    if (D_001A5CD0[0x174 / 4] == 0 &&
        (D_001A5CD0[0x170 / 4] != 0 || ((u8 *)D_001A5CD0)[0x168] != 0)) {
        p->f474 = 1;
    } else {
        p->f474 = 0;
        func_L39_00689D28(p, D_L39_002488C0);
    }
    if (D_001A5CD0[0x174 / 4] != 0) {
        return;
    }
    w = *D_L39_0024D760[0x30 / 4];
    if (((u8 *)D_001A5CD0)[0x168] != 0 && p->f478 < 0) {
        vt = p->obj->vt;
        vt->f24(p->obj, (s32)func_00381FF0(0x1297));
        if (p->f470 == -1 || w == p->f470) {
            p->obj->vt->f1C(p->obj, 3, 0);
            func_L39_0068B2F8(p, 3, 0);
            func_L39_00689F00(p, 0, D_L39_004B0538[0], D_L39_004B0538[1], 3, 3, D_L39_004B0538[2], D_L39_004B0538[3], 0.026f, 0.25f);
            func_L39_00689D28(p, func_00381FF0(0x124));
        } else {
            p->obj->vt->f1C(p->obj, 2, 0);
        }
    } else {
        vt = p->obj->vt;
        vt->f24(p->obj, (s32)func_00381FF0(0xF8C));
        if (p->f478 != -1) {
            p->obj->vt->f1C(p->obj, 3, 0);
            func_L39_0068B2F8(p, 3, 0);
            func_L39_00689F00(p, 0, D_L39_004B0538[0], D_L39_004B0538[1], 3, 3, D_L39_004B0538[2], D_L39_004B0538[3], 0.026f, 0.25f);
        } else {
            p->obj->vt->f1C(p->obj, 2, 0);
            func_L39_00689F00(p, 0, 2.0f, 2.0f, 3, 3, D_L39_004B0538[2], D_L39_004B0538[3], 0.026f, 0.25f);
            func_L39_00689D28(p, D_L39_002488C0);
        }
    }
}
/* localdecomp:end func_L39_006A8138 */

INCLUDE_ASM("asm/levels", func_L39_006A83B8);
