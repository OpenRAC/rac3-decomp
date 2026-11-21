/* functional: medium. Written from the PAL asm only. Per-frame update of the spawner/mob-holder object (sibling of func_L04_0035A158/func_L04_0035B430): releases pending effects, runs the mob lifetime check, repositions the two anchor vectors (m+0x50, m+0x60) from the object basis at +0xC0, runs the slot logic (func_L04_0035A6E0, func_L04_0035B838), picks a candidate target object (type 0x1860) and, when it is in range or just spawned, respawns the sub-object and its facing vector; then refreshes slot timers, and scales the sub-object's size at +0x2C. Unsure: meaning of the two byte tables (D_001BBC40, D_001BBB18) and of m+0x110/+0x120 == 4 states; the calls to func_L04_003796E0 and func_L04_003776F8 pass the register a0 retail leaves (m->sub / the object plus &vec). */
#include "common.h"
#include "vu0.h"

extern s32 D_001D545C;
extern u8 *D_L04_001DFE80;
extern u8 D_001BBC40[][16];
extern u8 D_001BBB18[][8];
extern s32 D_L04_001DF940;
extern f32 D_L04_001DD50C;
extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_L01_00367430(s32, f32);
extern void func_L04_0037A5B8(void *, void *, s32);
extern s32 func_L04_0035BA58(void *, void *);
extern void func_L04_0035B908(void *, void *, void *, void *);
extern s32 func_L04_003796E0(u8 *);
extern void func_L01_0038B988(void *);
extern void func_L04_003796C8(u8 *);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040BE10(void *, void *);
extern void func_L04_0035A6E0(void *, void *, s32, s32);
extern s32 func_L04_0035B838(void *, void *, s32);
extern u8 *func_L04_003776D8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L04_0035B5D8(void *, void *, void *);
extern s32 func_L04_00377720(void *);
extern void func_L04_00379CC0(u8 *, void *);
extern s32 func_L04_0035A5B8(void *, void *, void *);
extern u8 *func_L04_00379410(void *);
extern void func_L04_003776F8(void *, void *);
extern void func_L04_0035A4F8(void *, void *);
extern void func_L04_0035B430(void *, void *);
extern void func_L04_0035C1B8(void *, void *);

static void v3_add_ab(void *d, void *a, void *b) {
    ((f32 *)d)[0] = ((f32 *)a)[0] + ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] + ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] + ((f32 *)b)[2];
}
static void v3_add_ba(void *d, void *a, void *b) {
    v3_add_ab(d, a, b);
}
static void v3_sub_ab(void *d, void *a, void *b) {
    ((f32 *)d)[0] = ((f32 *)a)[0] - ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] - ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] - ((f32 *)b)[2];
}

void func_L04_0035BC10(void *op, void *mp) {
    u8 *o = op;
    u8 *m = mp;
    vu0_v4 t0, t1, t2;
    u8 *m4;
    u8 *obj;
    u8 *p;
    s32 a, ok, i;
    f32 scale;

    if (*(s32 *)(m + 0) != 0) {
        func_L01_00367260(o, -1, 0, o + 0x10, o + 0x10, -1);
        func_L01_00367430((s32)o, 0.0f);
        *(s32 *)(m + 0) = 0;
    }
    a = *(s32 *)(m + 8);
    if (a != 0) {
        func_L04_0037A5B8((void *)a, o, 0);
        *(s32 *)(m + 8) = 0;
    }
    if (func_L04_0035BA58(o, m) == 0) {
        func_L04_0035B908(o, m + 0x50, m + 0x80, m + 0x40);
        func_L04_0035B908(o, m + 0xB0, m + 0xE0, m + 0x44);
        return;
    }
    m4 = *(u8 **)(m + 4);
    if (m4 != 0) {
        if (func_L04_003796E0(m4) != 0) {
            func_L01_0038B988(*(u8 **)(m + 4));
            *(s32 *)(m + 4) = 0;
        }
    }
    if (*(s32 *)(m + 0x4C) == -1) {
        func_0038D308(o + 0xC0, o + 0xF0);
    }
    a = *(s32 *)(m + 0x20);
    if (a == -1) {
        func_0038CE20(m + 0x50, o + 0xC0, 0.33f);
    } else if (a != 0) {
        func_0038CE20(m + 0x50, o + 0xC0, 0.23f);
    } else {
        func_0038CE20(m + 0x50, o + 0xC0, 0.33f);
    }
    v3_add_ab(m + 0x50, m + 0x50, o + 0x10);
    scale = 40.0f;
    if (D_001D545C == 11) scale = 80.0f;
    func_0038CE20(m + 0x60, o + 0xC0, scale);
    v3_add_ab(m + 0x60, m + 0x60, o + 0x10);
    func_L01_0040BE10(o + 0x10, m + 0x60);
    func_L04_0035A6E0(o, m, 0, 0);
    if (func_L04_0035B838(o, m, 0) != 0) {
        ok = 0;
        obj = func_L04_003776D8(o);
        if (obj != 0 && *(s16 *)(obj + 0xAA) == 0x1860 && obj != *(u8 **)(m + 8)) {
            if (*(s32 *)(*(u8 **)(obj + 0x68) + 4) != -1) {
                ok = 1;
            } else {
                u8 *sub = *(u8 **)(*(u8 **)(obj + 0xB8) + 0x68);
                u8 *ent = D_L04_001DFE80 + (*(s32 *)(sub + 0x13C) << 7);
                if (func_L01_0040E548(sub + 0x2C0, ent + 0x30) < 0.25f) ok = 1;
            }
        }
        if (ok != 0) {
            func_L04_0035B5D8(o, m, &t0);
            func_L04_00377720(&t1);
            v3_sub_ab(&t2, &t1, &t0);
            func_0038CF68(&t2, &t2, 1.0f);
            if (obj != 0) {
                func_L04_00379CC0(obj, &t1);
                v3_sub_ab(&t2, &t1, &t0);
                func_0038CF68(&t2, &t2, 1.0f);
            }
            if (func_L04_0035A5B8(&t0, &t1, &t1) == 0) ok = 0;
            if (ok != 0) {
                if (*(s32 *)(m + 4) != 0) {
                    func_L04_003796C8(*(u8 **)(m + 4));
                }
                *(u8 **)(m + 4) = func_L04_00379410(&t0);
                *(vu0_v4 *)(m + 0x150) = t2;
                if (obj != 0 && *(s32 *)(*(u8 **)(obj + 0x68) + 4) == -1) {
                    *(u8 **)(m + 0x30) = obj;
                }
                *(s32 *)(m + 0x110) = 4;
                func_L04_003776F8(o, &t0);
                a = *(s32 *)(m + 8);
                if (a != 0) {
                    func_L04_0037A5B8((void *)a, o, 0);
                    *(s32 *)(m + 8) = 0;
                }
            }
        }
    }
    m4 = *(u8 **)(m + 4);
    if (m4 != 0) {
        s32 refresh = 0;
        if (*(s32 *)(m + 0x110) == 4 || *(s32 *)(m + 0x120) == 4) {
            refresh = 1;
        } else if (*(s32 *)(m + 0x1C) != 0) {
            u8 c = o[0xB0];
            if (c != 0xFF && (D_001BBC40[D_001D545C][c] & 0x80)) {
                /* keep */
            } else {
                a = *(s32 *)(m + 0x34);
                if (a == -1 || D_001BBB18[D_001D545C][a] == 0) {
                    func_L04_003796C8(*(u8 **)(m + 4));
                }
            }
        } else {
            func_L04_003796C8(*(u8 **)(m + 4));
        }
        if (refresh) {
            *(vu0_v4 *)(m + 0xB0) = *(vu0_v4 *)(m4 + 0x10);
            scale = 40.0f;
            if (D_001D545C == 11) scale = 80.0f;
            func_0038CE20(m + 0xC0, m + 0x150, scale);
            v3_add_ba(m + 0xC0, m + 0xC0, m + 0xB0);
            func_L01_0040BE10(m + 0xB0, m + 0xC0);
            func_L04_0035A6E0(o, m, 2, 0);
        }
    }
    p = m + 0x50;
    for (i = 3; i >= 0; i--) {
        u8 *q = m + 0x110 + (3 - i) * 0x10;
        if (*(s32 *)(q + 4) < D_L04_001DF940) {
            func_L04_0035A4F8(p, q);
        }
        p += 0x30;
    }
    func_L04_0035B908(o, m + 0x50, m + 0x80, m + 0x40);
    func_L04_0035B908(o, m + 0xB0, m + 0xE0, m + 0x44);
    m4 = *(u8 **)(m + 4);
    if (m4 != 0) {
        f32 v = *(f32 *)(*(u8 **)(m4 + 0x24) + 0x24);
        if (*(s32 *)(m + 0xA0) == 1) {
            v = v * 1.5f;
            v = v * D_L04_001DD50C;
        } else {
            v = v * 1.5f;
        }
        *(f32 *)(m4 + 0x2C) = v;
    }
    func_L04_0035B430(o, m);
    func_L04_0035C1B8(o, m);
}
