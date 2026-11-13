#include "common.h"

typedef struct { char pad[0x70]; char *f70; } T;

/* declared by functions of L39_006A0E68.c, which this file was cut from */
extern T *D_L39_0024D760;
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L39_006A21B8 */
typedef struct O_006A21B8 O_006A21B8;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(O_006A21B8 *, s32, s32);
    void (*f20)(O_006A21B8 *, s32, s32);
    u8 pad24[0x30 - 0x24];
    void (*f30)(O_006A21B8 *, f32 *, f32 *);
    u8 pad34[0x6C - 0x34];
    s32 (*f6C)(O_006A21B8 *, s32, void *);
    u8 pad70[0x8C - 0x70];
    s32 (*f8C)(O_006A21B8 *);
    u8 pad90[0x9C - 0x90];
    void (*f9C)(O_006A21B8 *, f32 *, f32 *);
    void (*fA0)(O_006A21B8 *, f32 *, f32 *);
    s32 (*fA4)(O_006A21B8 *);
} V_006A21B8;
struct O_006A21B8 { u8 pad[0x60]; V_006A21B8 *vt; };
typedef struct S_006A21B8 S_006A21B8;
struct S_006A21B8 {
    u8 pad0[0x110];
    O_006A21B8 *f110[13];
    u8 pad144[0x284 - 0x144];
    s32 f284;
    u8 pad288[0x290 - 0x288];
    s32 f290;
    u8 pad294[0x2A8 - 0x294];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    u8 f2B8;
    u8 f2B9;
    u8 f2BA;
    u8 pad2BB[0x2C4 - 0x2BB];
    s32 f2C4[224];
    s32 f644[224];
    s32 f9C4[224];
    s32 fD44[224];
    u8 pad10C4[0x1640 - 0x10C4];
    void *f1640;
};
typedef struct {
    u8 pad0[0x38];
    s32 *f38;
} G_006A21B8;
typedef struct {
    u8 pad0[0xA4];
    S_006A21B8 *fA4;
    u8 padA8[0x284 - 0xA8];
    s32 f284;
} H_006A21B8;
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");
extern H_006A21B8 *D_L39_00247914;
extern G_006A21B8 *D_001E2050_sda;
extern void *D_001DC204_sda;
__asm__(".extern D_001E1AA8_sda, 8");
__asm__(".extern D_001E1AE8_sda, 8");
extern u8 D_001E1AA8_sda[] __attribute__((section(".sdata")));
extern u8 D_001E1AE8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DCEC4_sda, 4");
__asm__(".extern D_001DCEC8_sda, 4");
extern f32 D_001DCEC4_sda;
extern f32 D_001DCEC8_sda;
extern void func_L39_006A2A58(void *);
extern s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_0068B2F8(void *, s32, s32);
extern s32 func_L39_006877B0(void *, s32);
extern s32 func_L39_006A29D0(void *, s32);
extern void func_L39_006CC918(void *, s32);
extern void func_L39_006CC8F0(void *, s32, s32, s32);
extern s32 func_L39_006CC930(void *);
extern void func_L39_006A2038(void *);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_006A2138(void *, s32, s32);
extern void func_L39_005958A0(void *, void *, s32);
extern s32 func_00120884(void *);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_006A21B8(S_006A21B8 *a, s32 b) {
    s32 r19;
    s32 s18;
    s32 loc0[1];
    void *loc4[1];
    void *loc8[1];
    O_006A21B8 *o;
    O_006A21B8 **pp;
    f32 l_C, l_10, l_14, l_18;

    func_L39_006A2A58(a);
    if (a->f290 == 8 && (u32)(b - 3) < 2) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(a, 6, 0);
        return 1;
    } else if (a->f290 == 6 && b == 4) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(a, 8, 0);
        return 1;
    } else if (b == 1 && a->f290 == 0) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(a, 6, 0);
        return 1;
    } else if (b == 2 && a->f290 == 6) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(a, 0, 0);
        return 1;
    }
    if (a->f290 == 3) {
        if (b == 3 || b == 7) {
            a->f2B4 = a->f2B4 + 1;
            if (a->f2B4 >= 5) a->f2B4 = 0;
            func_L39_00688340(3, 0, 0);
        }
        if (b == 4) {
            a->f2B4 = a->f2B4 - 1;
            if (a->f2B4 < 0) a->f2B4 = 4;
            func_L39_00688340(3, 0, 0);
        }
    }
    if (b == 7 && a->f290 == 5) {
        s32 m = func_L39_006877B0(D_001DC204_sda, 2);
        if (m != -1) {
            a->f2B0 = m;
            if (m == 99) a->f2B0 = 40;
            loc0[0] = func_L39_006A29D0(a, a->f2B0);
            a->f110[5]->vt->f6C(a->f110[5], 1, loc0);
            if (a->f2B0 == 0) {
                func_L39_006CC918(a->f1640, 0xD);
            } else {
                func_L39_006CC8F0(a->f1640, 0xD, 2, a->f2B0);
            }
            func_L39_006CC918(a->f1640, 0xE);
        }
    }
    func_L39_006A2038(a);
    {
        s32 n = a->f110[0]->vt->f8C(a->f110[0]);
        if (n == 0) {
            a->f110[5]->vt->f20(a->f110[5], 3, 0);
        } else if (n == 1) {
            a->f110[5]->vt->f20(a->f110[5], 0, 0);
        }
    }
    if (a->f110[4]->vt->fA4(a->f110[4])) {
        s32 n = a->f110[4]->vt->f8C(a->f110[4]);
        if (n > 0) {
            func_L39_006CC8F0(a->f1640, 1, 2, n + 1);
        } else {
            func_L39_006CC918(a->f1640, 1);
        }
    }
    r19 = func_L39_0068AEF8(a, b);
    if (a->f110[1]->vt->fA4(a->f110[1])) {
        s32 n = a->f110[1]->vt->f8C(a->f110[1]);
        if (n > 0) {
            func_L39_006CC8F0(a->f1640, 0x10, 2, n);
        } else {
            func_L39_006CC918(a->f1640, 0x10);
        }
    }
    if (a->f110[2]->vt->fA4(a->f110[2])) {
        s32 n = a->f110[2]->vt->f8C(a->f110[2]);
        if (n == 1) {
            func_L39_006CC8F0(a->f1640, 0x11, 2, 0);
        } else if (n == 2) {
            func_L39_006CC8F0(a->f1640, 0x11, 2, 1);
        } else if (n == 3) {
            func_L39_006CC8F0(a->f1640, 0x11, 2, 2);
        } else {
            func_L39_006CC918(a->f1640, 0x11);
        }
    }
    if (a->f110[0]->vt->fA4(a->f110[0])) {
        s32 n = a->f110[0]->vt->f8C(a->f110[0]);
        if (n == 0) {
            if (a->f1640 != (u8 *)a + 0x1298) {
                func_L39_006A2138(a, 1, a->f2B0);
            }
            func_L39_006CC8F0(a->f1640, 0xC, 2, 0);
        } else if (n == 1) {
            if (((G_006A21B8 *)D_L39_0024D760)->f38[0] != -1) {
                if (a->f1640 != (u8 *)a + 0x146C) {
                    func_L39_006A2138(a, 2, ((G_006A21B8 *)D_L39_0024D760)->f38[0]);
                }
                func_L39_006CC8F0(a->f1640, 0xC, 2, 1);
                }
        }
    }
    s18 = 1;
    if (r19 == s18) return 1;
    if (b == 7) {
        if (a->f290 == 8) {
            s32 n = a->f110[8]->vt->f8C(a->f110[8]);
            if (n >= 0) {
                s18 = a->f2C4[n];
                if (s18 >= 0) {
                    S_006A21B8 *t;
                    func_L39_00688340(4, 0, 0);
                    {
                        s32 y = a->f9C4[n];
                        s32 z = a->fD44[n];
                        s32 x = a->f644[n];
                        t = D_L39_00247914->fA4;
                        t->f2A8 = s18;
                        t->f2AC = z;
                        t->f2B0 = y;
                        t->f2B4 = x;
                    }
                    D_L39_00247914->f284 = 0x10;
                    return 1;
                }
            }
        } else if (a->f290 == 6) {
            func_L39_00688340(4, 0, 0);
            loc4[0] = (void *)func_00381FF0(0x1008);
            {
                void *s16 = (void *)func_00381FF0(0x1008);
                func_L39_005958A0(D_001E1AA8_sda, s16, func_00120884((void *)func_00381FF0(0x1008)));
            }
            loc4[0] = D_001E1AA8_sda;
            a->f110[8]->vt->f6C(a->f110[8], 1, loc4);
            a->f110[8]->vt->f1C(a->f110[8], 2, 0);
            if (a->f110[0]->vt->f8C(a->f110[0]) == 0) {
                if (a->f2B0 == 0) {
                    func_L39_006CC918(a->f1640, 0xD);
                } else {
                    func_L39_006CC8F0(a->f1640, 0xD, 2, a->f2B0);
                }
                func_L39_006CC918(a->f1640, 0xE);
                func_L39_006CC930(a->f1640);
                a->f2B9 = 0;
                a->f2B8 = 1;
                a->f2BA = 0;
            } else if (D_001E2050_sda->f38[0] != -1) {
                func_L39_006CC930(a->f1640);
                a->f2B8 = s18;
                a->f2B9 = 0;
                a->f2BA = 0;
            } else {
                loc8[0] = (void *)func_00381FF0(0x131C);
                {
                    void *s16 = (void *)func_00381FF0(0x1008);
                    func_L39_005958A0(D_001E1AE8_sda, s16, func_00120884((void *)func_00381FF0(0x1008)));
                }
                loc8[0] = D_001E1AE8_sda;
                a->f110[8]->vt->f6C(a->f110[8], 1, loc8);
            }
        }
    }
    if (a->f290 == 8) {
        pp = a->f110;
        a->f110[8]->vt->f9C(a->f110[8], &l_C, &l_10);
        pp += a->f290;
        (*pp)->vt->fA0(*pp, &l_14, &l_18);
        l_18 = l_18 * 0.54f;
        func_L39_00689F00(a, 0, 3, 3, l_C + l_14 * 0.5f, l_10, l_14, l_18, D_001DCEC4_sda, D_001DCEC8_sda);
    } else {
        a->f110[a->f290]->vt->f30(a->f110[a->f290], &l_C, &l_10);
        func_L39_00689F00(a, 0, 3, 3, 0.3f, l_10, 0.4f, 0.055f, 0.035f, 0.22f);
    }
    return 0;
}
/* localdecomp:end func_L39_006A21B8 */
