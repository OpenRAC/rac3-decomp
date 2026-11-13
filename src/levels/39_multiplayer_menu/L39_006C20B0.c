#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006C20B0);

/* localdecomp:start func_L39_006C2C40 */
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_00241640;
typedef struct {
    char pad0[0xE0];
    s16 hE0[8];
    s16 hF0[1];
} S_241640_006C2C40;
extern S_241640_006C2C40 *D_001D5F30_sda;
extern s32 D_003D28BC __attribute__((section(".data")));

typedef struct {
    char pad0[0x128];
    s32 w128;
    char pad12C[4];
    s32 w130;
    char pad134[0x34];
    u8 b168;
} S_1A5CD0_006C2C40;
extern S_1A5CD0_006C2C40 D_001A5CD0 __attribute__((section(".data")));

typedef struct V_006C2C40 V_006C2C40;
typedef struct {
    void (*fn[32])(V_006C2C40 *, ...);
} VT_006C2C40;
struct V_006C2C40 {
    char pad[0x60];
    VT_006C2C40 *vt;
};

extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_00381FF0(s32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, s32);
s32 func_L01_005170B8(s32, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);
extern s32 func_L39_006C4788(void *, s32);
extern s32 func_L39_006C46F0(void *, s32);


void func_L39_006C2C40(u8 *obj) {
    u8 buf[64];
    s32 idx;
    s32 r;
    s32 flag;

    if (D_L39_00241640 != 0 && *(s16 *)(D_L39_00241640 + 0xF0) >= 7) {
        s32 n;
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[7](o, 0, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[7](o, 2, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[19](o, 0x40, 0);
        n = (*(s32 *)(D_L39_00241640 + 0x174) - D_001A5CD0.w128) / 1000 + 1;
        func_00120048(buf, (u8 *)func_00381FF0(0x1876), n);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[7](o, 1, 0);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[16](o, 1);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[19](o, 0x40, 1);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[9](o, buf);
    } else if (D_001A5CD0.b168 != 0) {
        V_006C2C40 *o;
        if (obj[0x2A8] != 0) {
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[8](o, 3, 0);
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[19](o, 0x40, 1);
        } else {
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[8](o, 2, 0);
            o = *(V_006C2C40 **)(obj + 0x120);
            o->vt->fn[19](o, 0x40, 0);
        }
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[7](o, 0, 0);
    } else {
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[7](o, 3, 0);
        o = *(V_006C2C40 **)(obj + 0x124);
        o->vt->fn[19](o, 0x40, 1);
        o = *(V_006C2C40 **)(obj + 0x120);
        o->vt->fn[7](o, 0, 0);
    }

    if (D_001A5CD0.w130 < *(s32 *)(obj + 0x2F8)) {
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[8](o, 3, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[19](o, 0x40, 1);
    } else {
        V_006C2C40 *o;
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[8](o, 2, 0);
        o = *(V_006C2C40 **)(obj + 0x11C);
        o->vt->fn[19](o, 0x40, 0);
    }

    idx = *(s32 *)(obj + 0x290) - 0xF;
    if ((u32)idx < 0x28) {
        S_241640_006C2C40 *g;
        if (D_001A5CD0.b168 != 0 && (g = D_001D5F30_sda) != 0 && g->hE0[idx] == -1) {
            func_L39_00689D28(obj, func_00381FF0(0x1669));
        } else {
            func_L39_00689D28(obj, func_00381FF0(0x1254));
        }
    } else {
        func_L39_00689D28(obj, func_00381FF0(0x124));
    }

    flag = 0;
    r = func_L39_006C4788(obj, 0);
    if (r >= 0) {
        S_241640_006C2C40 *g;
        s32 t;
        r = func_L39_006C46F0(obj, r);
        g = (S_241640_006C2C40 *)D_L39_00241640;
        t = 0;
        if (g != 0 && r >= 0) {
            t = g->hF0[r] == 6;
        }
        flag = t;
    }

    func_L39_00689E58(obj, flag ? func_00381FF0(0x16D9) : func_00381FF0(0x1102), 0x706EC8FF, 1.0f, 1.0f);

    if (*(s32 *)(obj + 0x2BC) > 0xC8 && !flag) {
        f32 f = func_0038D0B0((f32)((*(s32 *)(obj + 0x2BC) - 0xC8) % 45) / 45.0f * 6.2831855f - 3.1415927f);
        s32 c = func_0038DBD8(f * 0.5f + 0.5f, 0x706EC8FF, -1);
        func_L01_005170B8(D_003D28BC, c);
    } else if (*(s32 *)(obj + 0x2BC) == 0) {
        func_L01_005170B8(D_003D28BC, 0x706EC8FF);
    }
}
/* localdecomp:end func_L39_006C2C40 */

INCLUDE_ASM("asm/levels", func_L39_006C30A0);

/* localdecomp:start func_L39_006C3670 */
/* DIVS: with --as ps2as the only difference is the two nops retail has before div.s (19 diff, all from that shift); the default assembler also turns the first D_001D5F30_sda load (lui in retail) into $gp (21). */
typedef struct {
    u8 name[8][16];
    u8 pad[0x60];
    s16 slot[8];
    u8 pad2[0x20];
    f32 a[8];
    f32 b[8];
} S_006C3670;
extern u8 D_001A62C4[];
extern s32 func_L39_006CC238(s32, s32);
extern s32 func_L39_006DF598(f32, f32);
extern void func_L39_006CC2A8(s32, void *, s32);

void func_L39_006C3670(void) {
    u8 *d = (u8 *)&D_001A5CD0;
    s32 sum;
    s32 cnt;
    s32 i;
    s32 big;
    s32 v;
    if (d[0x168] == 0 || D_001D5F30_sda == 0) {
        return;
    }
    sum = 0;
    cnt = 0;
    big = func_L39_006CC238(3, *(s32 *)(d + 0x5F4)) >= 8;
    for (i = 0; i < 8; i++) {
        S_006C3670 *t = (S_006C3670 *)D_001D5F30_sda;
        if (t->slot[i] != -1) {
            cnt++;
            sum += func_L39_006DF598(t->a[i], t->b[i]);
        }
    }
    if (cnt > 0) {
        v = (f32)sum / (f32)cnt;
        func_L39_006CC2A8(3, D_001A62C4, big ? v + 8 : v);
    }
}
/* localdecomp:end func_L39_006C3670 */

INCLUDE_ASM("asm/levels", func_L39_006C3778);

INCLUDE_ASM("asm/levels", func_L39_006C38E0);

/* localdecomp:start func_L39_006C3AA8 */
/* best: 112 diff with --mode N --as ps2as (file flags: ~320 diff, float consts come from $gp
 * literals instead of lui/ori/mtc1, so this function wants ps2as / other flags).
 * Frame layout, names-array copy, switch, vtable calls now match. Still differs:
 * e lives in $s3 not $s4; trim loop: retail keeps a second copy of e->name ($s3) and puts
 * (e->name < q) into $s0; the D_001FD630 loop (retail walks &f0 and loads 4($s0)).
 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00249570, 16");
__asm__(".extern D_L39_00249550, 16");

typedef struct VT_006C3AA8 {
    u8 pad0[0x24];
    void (*fn24)(void *, void *);
    u8 pad28[0xDC - 0x28];
    void (*fnDC)(void *, s32);
} VT_006C3AA8;

typedef struct Obj_006C3AA8 {
    u8 pad0[0x60];
    VT_006C3AA8 *vt;
} Obj_006C3AA8;

typedef struct E_006C3AA8 {
    u8 pad0[0x134];
    u8 name[0x13];
} E_006C3AA8;

typedef struct S_006C3AA8 {
    s32 f0;
    s32 f4;
    u8 pad8[0x20];
} S_006C3AA8;

extern u8 *D_001E2050_sda;
extern u8 *D_L39_0024D760;
extern u8 D_L39_00249570[];
extern u8 D_L39_00249550[];
extern u8 D_001A5D8E[];
extern S_006C3AA8 D_001FD630[];

extern s32 func_0019B5C8(void);
extern u8 *func_L39_006D4380(void *, s32);
extern void *func_L39_006CC120(void *object);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_006CC350(s32 *a0, s32 a1);
extern void func_L39_006CC158(void *object, s32 flags);
extern void func_L39_0068A4A8(void *, s32, s32, u32, f32, f32, f32, f32);
extern s32 func_00120884(u8 *);
extern void func_L39_005958F8(u8 *, u8 *, s32);
extern void func_0038CBC8(void *, s32);
extern u8 *func_00120D28(void *, void *, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_006D9E68(void *, s32, u8 *, s32);

void func_L39_006C3AA8(u8 *obj) {
    s32 buf[0x1E0 / 4];
    u8 *e;
    u8 *q;
    void *s;
    s32 mode;
    s32 i;
    void *h;

    if ((obj[0x2B5] || obj[0x2B4]) && D_001D5F30_sda != 0) {
        h = *(void **)(D_001E2050_sda + 0x3C);
        e = func_L39_006D4380(h, func_0019B5C8());
        if (e != 0 && *(s32 *)(e + 0x18) == 0) {
            func_L39_006CC120(buf);
            func_L39_006CC4F8(buf, e);
            obj[0x2B5] = 0;
            func_L39_0068A4A8(obj, 1, func_L39_006CC350(buf, 1), 0x332299DE, 0.5f, 0.48677778f, 0.045777798f, 0.805f);
            *(s32 *)(obj + 0x2CC) = func_L39_006CC350(buf, 0xC);
            *(s32 *)(obj + 0x2D0) = func_L39_006CC350(buf, 3);
            *(s32 *)(obj + 0x2D4) = func_L39_006CC350(buf, 0xF) * 5;
            *(s32 *)(obj + 0x2E0) = func_L39_006CC350(buf, 0x11);
            obj[0x2E4] = func_L39_006CC350(buf, 0x13) == 0;
            obj[0x2E5] = func_L39_006CC350(buf, 0x14) == 1;
            *(s32 *)(obj + 0x2E8) = func_L39_006CC350(buf, 0x15) * 5;
            *(s32 *)(obj + 0x2EC) = func_L39_006CC350(buf, 0x17);
            *(s32 *)(obj + 0x2F0) = func_L39_006CC350(buf, 0x18);
            obj[0x302] = func_L39_006CC350(buf, 0x19) == 1;
            obj[0x300] = func_L39_006CC350(buf, 0x1A) == 1;
            obj[0x301] = func_L39_006CC350(buf, 0x1B) == 1;
            obj[0x303] = func_L39_006CC350(buf, 0x1C) == 1;
            obj[0x2F4] = func_L39_006CC350(buf, 0x16) == 1;
            obj[0x2D8] = func_L39_006CC350(buf, 4) == 0;
            obj[0x2D9] = func_L39_006CC350(buf, 5) == 0;
            obj[0x2DA] = func_L39_006CC350(buf, 6) == 0;
            obj[0x2DB] = func_L39_006CC350(buf, 7) == 0;
            obj[0x2DC] = func_L39_006CC350(buf, 8) == 0;
            obj[0x2DD] = func_L39_006CC350(buf, 9) == 0;
            obj[0x2DE] = func_L39_006CC350(buf, 0xA) == 0;
            obj[0x2DF] = func_L39_006CC350(buf, 0xB) == 0;
            *(s32 *)(obj + 0x2F8) = func_L39_006CC350(buf, 1);
            mode = func_L39_006CC350(buf, 0x10);
            {
                void *names[10] = {
                    (void *)func_00381FF0(0xBB1), (void *)func_00381FF0(0xBB2), (void *)func_00381FF0(0xDA),
                    (void *)func_00381FF0(0xBB4), (void *)func_00381FF0(0xD8), (void *)func_00381FF0(0xD4),
                    (void *)func_00381FF0(0x18C4), (void *)func_00381FF0(0x18C5), (void *)func_00381FF0(0x18C6),
                    (void *)func_00381FF0(0x18C7),
                };
                (*(Obj_006C3AA8 **)(obj + 0x114))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x114), names[(mode - 1) % 10]);
                {
                    u8 text[0x20];

                    s = (void *)func_00381FF0(0x1328);
                    switch (*(s32 *)(obj + 0x2E0)) {
                    case 0:
                        s = (void *)func_00381FF0(0x1024);
                        break;
                    case 1:
                        s = (void *)func_00381FF0(0x10E2);
                        break;
                    case 2:
                        if (((s8 *)D_001D5F30_sda)[0x19D]) {
                            s = (void *)func_00381FF0(0x162A);
                        } else {
                            s = (void *)func_00381FF0(0x1026);
                        }
                        break;
                    }
                    (*(Obj_006C3AA8 **)(obj + 0x118))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x118), s);
                    e[0x146] = 0;
                    q = &((E_006C3AA8 *)e)->name[func_00120884(((E_006C3AA8 *)e)->name) - 1];
                    while (((E_006C3AA8 *)e)->name < q && *q == ' ') {
                        q--;
                    }
                    q[1] = 0;
                    func_L39_005958F8(text, ((E_006C3AA8 *)e)->name, func_00120884(((E_006C3AA8 *)e)->name));
                    (*(Obj_006C3AA8 **)(obj + 0x110))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x110), text);
                    func_0038CBC8(D_001A5D8E, 0x40);
                    func_00120D28(D_001A5D8E, ((E_006C3AA8 *)e)->name, 0x11);
                    *(s32 *)(D_001A5D8E + 0x546) = *(s32 *)(e + 0x180);
                    (*(Obj_006C3AA8 **)(obj + 0x128))->vt->fnDC(*(Obj_006C3AA8 **)(obj + 0x128), mode + 0x24);
                    if (obj[0x2B4]) {
                        s32 me = func_0019B5C8();
                        s32 other = *(s32 *)(e + 0x188);
                        u8 tmp[0x50];

                        for (i = 0; i < 11; i++) {
                            if (D_001FD630[i].f4 == 1) {
                                tmp[0] = 'N';
                                func_00120048(tmp + 1, D_L39_00249570, me);
                                func_00120048(tmp + 9, D_L39_00249570, other);
                                func_L39_006D9E68(*(void **)(D_L39_0024D760 + 0x48), D_001FD630[i].f0, tmp, 1);
                            }
                        }
                        obj[0x2B4] = 0;
                    }
                }
            }
            func_L39_006CC158(buf, 2);
        } else {
            (*(Obj_006C3AA8 **)(obj + 0x110))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x110), D_L39_00249550);
        }
    }
}
/* localdecomp:end func_L39_006C3AA8 */
