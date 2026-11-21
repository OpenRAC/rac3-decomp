#include "common.h"

/* NTSC-U counterpart of func_L01_00367780 (src/levels/shared/L01_00363E68.c): 60 Hz frame windows (0x3B, 0x3A for 0x31, 0x30) */
/* localdecomp:start func_L01_003669F8 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x1200];
    u8 *p1200;
    u8 pad2[0x24];
    s32 mode1228;
} State1200_003669F8;
extern State1200_003669F8 D_001A4BE0;
extern s32 D_001D545C;
extern void func_003886E8(s128 *, s128 *, f32);
extern s32 func_L01_003668D0(void);
extern f32 D_L01_002B38F0_003669F8[];
extern s32 D_L01_001E1D50_003669F8;
extern s32 D_L01_001E1CA4_003669F8;
extern f32 D_L01_001E1CA0_003669F8;
extern s32 D_L01_001DFBC0_003669F8;
#include "vu0.h"
typedef struct Moby_003669F8 {
    u8 pad0[0x24];
    struct { u8 pad[0x46]; u8 x46; } *p24;
    u8 pad28[0x34 - 0x28];
    u16 flags34;
    u8 pad36[0x68 - 0x36];
    s32 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 oclass;
    u8 padAC[0xB8 - 0xAC];
    struct Moby_003669F8 *pB8;
    u8 padBC[0x100 - 0xBC];
} Moby_003669F8;
typedef struct {
    u8 pad[0x25C0];
    struct Obj_003669F8 *p25C0;
    s32 x25C4;
} State_003669F8;
typedef struct Obj_003669F8 {
    u8 pad0[0x24];
    struct { u8 pad[0x10]; s32 x10; } *p24;
    u8 pad28[0x98 - 0x28];
    s32 x98;
} Obj_003669F8;
typedef struct {
    void (*f0)(void *, void *);
    void (*f4)(void *, void *, s32);
} Cls1860_003669F8;
typedef struct {
    Moby_003669F8 *(*f0)(void *, void *);
    s32 (*f4)(void *, void *, void *);
} Cls_003669F8;
typedef struct {
    u8 pad0[0x18];
    Moby_003669F8 *m18;
    u8 pad1C[4];
    vu0_v4 v20;
} Target_003669F8;
typedef struct {
    u8 pad0[0x18];
    Moby_003669F8 *m18;
    s16 x1C;
} Link_003669F8;
typedef struct {
    s128 v;
    u8 pad10[8];
    u8 x18;
    s16 x1A;
    u8 pad1C[0x14];
} Hit_003669F8;
extern Moby_003669F8 *D_L01_001E1D44_003669F8;
extern vu0_v4 D_L01_001E1CC0_003669F8[1] __attribute__((section(".sdata")));
typedef struct {
    vu0_v4 pos;
    vu0_v4 v;
    s32 state;
    s32 timer;
} Cam_003669F8;
extern Cam_003669F8 D_L01_001E1D60_003669F8 __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1CD0_003669F8[1] __attribute__((section(".sdata")));
extern u8 D_L01_001E2A40_003669F8[];
extern Target_003669F8 D_L01_001EAA80_003669F8;
extern Moby_003669F8 *D_L01_001E009C_003669F8;
extern Moby_003669F8 *D_L01_001E1D48_003669F8;
extern s32 D_L01_001E1D4C_003669F8;
extern u8 D_0014275B[];
extern f32 D_L01_002F1550_003669F8[];
extern f32 D_L01_001DAA70_003669F8;
extern Cls1860_003669F8 *func_L01_00438488(s32, s32, s32);
extern Cls_003669F8 *func_L01_00438468(s32, s32);
extern void func_L01_00366900(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00409940(void *, void *);
extern void func_003C26C8(void *);
extern void func_L01_003F15C8(s32);
extern void func_L01_003F15F0(s32);
extern void func_L01_00366808(void);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_00417EA0(void);
extern void func_00388758(void *, void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern s32 func_003CF790(void *, s32, f32, s32, void *);
extern s32 func_003BF5E0(void *);
extern Link_003669F8 *func_0037E0B8(void *);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_00388398(void *);

void func_L01_003669F8(Moby_003669F8 *a0) {
    Moby_003669F8 *m;
    Moby_003669F8 *hit;
    Cls_003669F8 *c;
    Cls1860_003669F8 *c2;
    vu0_v4 tmp;
    s32 i;

    if (D_L01_001E1D44_003669F8 != 0) {
        func_L01_00438488(0x1860, 0, 8)->f4(D_L01_001E1D44_003669F8, a0, 0);
        D_L01_001E1D44_003669F8 = 0;
    }
    if (D_L01_001E1CA0_003669F8 > 0.0f && func_L01_003668D0()) {
        D_L01_001E1D60_003669F8.pos = D_L01_001E1CC0_003669F8[0];
        if (((State_003669F8 *)&D_001A4BE0)->x25C4 == 1) {
            func_L01_00366900(D_L01_001E2A40_003669F8, D_L01_001E2A40_003669F8 + 0x20, &D_L01_001E1D60_003669F8.v);
            vec_sub_ba(&tmp, &D_L01_001E1D60_003669F8.v, &D_L01_001E1D60_003669F8.pos);
            func_00388830(&tmp, &tmp, 1.0f);
            vec_add_ab(&D_L01_001E1D60_003669F8.v, &D_L01_001E1D60_003669F8.v, &tmp);
        } else {
            func_00388830(&D_L01_001E1D60_003669F8.v, D_L01_001E1CD0_003669F8, D_001D545C == 11 ? 80.0f : 40.0f);
            vec_add_ab(&D_L01_001E1D60_003669F8.v, &D_L01_001E1D60_003669F8.v, &D_L01_001E1D60_003669F8.pos);
        }
        func_L01_00409940(&D_L01_001E1D60_003669F8.pos, &D_L01_001E1D60_003669F8.v);
        ((State_003669F8 *)&D_001A4BE0)->p25C0->x98 = 0;
        func_003C26C8(((State_003669F8 *)&D_001A4BE0)->p25C0);
        func_L01_003F15C8(0);
        func_L01_00366808();
        if (func_003CE740(&D_L01_001E1D60_003669F8.pos, &D_L01_001E1D60_003669F8.v, 0, ((State_003669F8 *)&D_001A4BE0)->p25C0, 0)) {
            vu0_v4 *tv = &D_L01_001EAA80_003669F8.v20;
            D_L01_001E1D60_003669F8.v = *tv;
            if (D_L01_001EAA80_003669F8.m18 != 0) {
                if (D_L01_001EAA80_003669F8.m18->oclass == 0x1751) {
                    Moby_003669F8 *o = (Moby_003669F8 *)D_L01_001EAA80_003669F8.m18->p68[0x12C / 4];
                    if (o != 0) D_L01_001EAA80_003669F8.m18 = o;
                }
                if (D_L01_001EAA80_003669F8.m18->oclass == 0x1BA8) {
                    i = D_L01_001EAA80_003669F8.m18->p68[0];
                    if (i != -1) D_L01_001EAA80_003669F8.m18 = &D_L01_001E009C_003669F8[i];
                }
                if (D_L01_001EAA80_003669F8.m18->oclass == 0x1860 && D_L01_001E1CA4_003669F8 != 0
                    && ((Moby_003669F8 *)D_L01_001E1CA4_003669F8)->oclass == 0x11C1) {
                    c = func_L01_00438468(0x11C1, 8);
                    hit = c->f0((void *)D_L01_001E1CA4_003669F8, D_L01_001EAA80_003669F8.m18);
                    if (hit != 0) {
                        c2 = (Cls1860_003669F8 *)func_L01_00438468(0x1860, 8);
                        c2->f0(hit, &tmp);
                        if (c->f4(&D_L01_001E1D60_003669F8.pos, &tmp, &tmp)) {
                            D_L01_001E1D60_003669F8.v = tmp;
                            c2->f0(hit, &D_L01_001E1D60_003669F8.v);
                            D_L01_001E1D44_003669F8 = hit;
                            if (hit->pB8 != 0 && hit->pB8->oclass == 0x1751) {
                                func_L01_00438488(0x1860, 0, 8)->f4(hit, a0, 1);
                            }
                        }
                    }
                } else {
                    vu0_v4 v10;
                    vu0_v4 v20;
                    Hit_003669F8 h;
                    Link_003669F8 *p;
                    f32 k;
                    s32 ok;

                    m = D_L01_001EAA80_003669F8.m18;
                    if (m->oclass != 0x185F && m->oclass != 0x1B92 && (m->flags34 & 0x4000)) {
                        func_003886E8((s128 *)&v20, (s128 *)D_L01_001E1CD0_003669F8, D_L01_002B38F0_003669F8[5] * 0.5f);
                        vec_add_ab(&v20, &v20, &D_L01_001E1D60_003669F8.v);
                        if (func_L01_00417EA0()) {
                            if (D_001D545C != 7 || D_0014275B[0] == 0) {
                                k = D_L01_001E1CA0_003669F8 * D_L01_002F1550_003669F8[D_001D545C];
                            } else {
                                k = D_L01_001E1CA0_003669F8 * D_L01_001DAA70_003669F8;
                            }
                        } else {
                            k = D_L01_001E1CA0_003669F8;
                        }
                        ok = 1;
                        qzero(&tmp);
                        tmp.z = 1.0f;
                        func_00388758(&v10, D_L01_001E1CD0_003669F8, &tmp);
                        func_003886E8((s128 *)&v10, (s128 *)&v10, func_L01_00440918(0.15f, 0.3f));
                        func_L01_00443628(&h, a0, 0x210000, &v10, k);
                        h.x18 = 9;
                        h.x1A = a0->oclass;
                        func_003CF790(&v20, 0, D_L01_002B38F0_003669F8[5] * 1.2f, 0, &h);
                        if (func_L01_00438468(0x11C1, 8) == 0) {
                            ok = 0;
                        } else if (func_003BF5E0(m) || (m->p24 != 0 && m->p24->x46 == 0x16)
                                   || (p = func_0037E0B8(m)) == 0) {
                            if (m == D_L01_001E1D48_003669F8 && D_L01_001DFBC0_003669F8 - D_L01_001E1D4C_003669F8 <= 0x3B) ok = 0;
                        } else if (p->m18 == a0 && p->x1C <= 0x3A) {
                            ok = 0;
                        }
                        if (ok) {
                            D_L01_001E1D48_003669F8 = m;
                            D_L01_001E1D4C_003669F8 = D_L01_001DFBC0_003669F8;
                            func_L01_004A72A8(2, 0, a0, 0x1937);
                        }
                    }
                }
            }
        }
        ((State_003669F8 *)&D_001A4BE0)->p25C0->x98 = ((State_003669F8 *)&D_001A4BE0)->p25C0->p24->x10;
        func_003C26C8(((State_003669F8 *)&D_001A4BE0)->p25C0);
        func_L01_003F15F0(0);
        if (D_L01_001E1D60_003669F8.state != 1) {
            if (D_L01_001E1D60_003669F8.state == 2) D_L01_001E1D60_003669F8.timer = 0;
            else D_L01_001E1D60_003669F8.timer = D_L01_001DFBC0_003669F8;
            D_L01_001E1D60_003669F8.state = 1;
        }
    } else if (D_L01_001E1D60_003669F8.state != 0) {
        D_L01_001E1D60_003669F8.pos = D_L01_001E1CC0_003669F8[0];
        func_00388830(&D_L01_001E1D60_003669F8.v, D_L01_001E1CD0_003669F8, D_001D545C == 11 ? 80.0f : 40.0f);
        vec_add_ab(&D_L01_001E1D60_003669F8.v, &D_L01_001E1D60_003669F8.v, &D_L01_001E1D60_003669F8.pos);
        func_L01_00409940(&D_L01_001E1D60_003669F8.pos, &D_L01_001E1D60_003669F8.v);
        func_L01_00366808();
        if (func_003CE740(&D_L01_001E1D60_003669F8.pos, &D_L01_001E1D60_003669F8.v, 0, ((State_003669F8 *)&D_001A4BE0)->p25C0, 0)) {
            vu0_v4 *tv = &D_L01_001EAA80_003669F8.v20;
            D_L01_001E1D60_003669F8.v = *tv;
        }
        if (D_L01_001E1D60_003669F8.state == 1) {
            D_L01_001E1D60_003669F8.state = 2;
            D_L01_001E1D60_003669F8.timer = D_L01_001DFBC0_003669F8;
        }
    }
    if (func_00388398(&D_L01_001E1D50_003669F8)) D_L01_001E1CA0_003669F8 = 0.0f;
    D_L01_001E1CA4_003669F8 = 0;
}
/* localdecomp:end func_L01_003669F8 */
