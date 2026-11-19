#include "common.h"

/* localdecomp:start func_L39_006AAA08 */
typedef struct {
    u8 pad[0x110];
    void *items[0x40];
} M_006AAA08;
typedef struct {
    u8 pad[0x60];
    struct {
        u8 pad[0x30];
        void (*f30)(void *, f32 *, f32 *);
        void (*f34)(void *, f32 *, f32 *);
    } *vt;
} E_006AAA08;

extern void func_L39_006B7E90(s32, s32, s32, s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_006AB780(void *, s32, s32);
extern void func_L39_006AB098(void *);
extern void func_L39_006AB8A8(void *);
extern void func_L39_006AB7E0(void *, s32);
extern s32 func_L39_006A90F0(s32);
extern s32 func_L39_006A8FB0(s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern void func_L39_006AB300(void *, s32, s32);
extern void func_L39_006AB8F8(void *);
extern void func_L39_00689F00(void *, f32, f32, f32, f32, f32, f32, s32, s32, s32);
extern void *func_L39_006ABBB8(void *);
extern void *func_001206F4(void *, void *);
extern s32 D_001A43E8 __attribute__((section(".data")));
extern u8 *D_001DC204_sda;

extern s32 D_L39_0024D158;
extern s32 D_L39_0024D15C[] __attribute__((section(".sdata")));

/* the menu manager's next state (D_L39_00247914->f284 in L39_006992D8.c) */
static __inline__ void setMenuState_006AAA08(s32 id) {
    *(s32 *)(D_001DC204_sda + 0x284) = id;
}

s32 func_L39_006AAA08(u8 *p, s32 cmd) {
    s32 i;
    s32 v;
    s32 n;
    s32 c;
    s32 r;
    s32 lo;
    u8 hi;
    s32 t;
    u8 *q;
    E_006AAA08 *o;
    f32 x;
    f32 y;
    f32 w;
    f32 h;

    func_L39_006B7E90(1, 0, 0x190, 0, 0x82);
    (*(s32 *)(p + 0x398))++;
    if (func_L39_0068AEF8(p, cmd)) {
        return 1;
    }
    if (p[0x3BC] != 0 && D_001A43E8 != 2) {
        setMenuState_006AAA08(0x2C);
        return 1;
    }
    if (D_L39_0024D158 != 0) {
        for (i = 0; i < D_L39_0024D158; i++) {
            v = D_L39_0024D15C[i];
            if (v == (s32)0x80000039) {
                func_L39_006AB780(p, p[0x2A9], p[0x2A8] ^ 1);
            } else if (v == (s32)0x800000E1) {
                func_L39_006AB780(p, p[0x2A9] ^ 1, p[0x2A8]);
            } else if (v == (s32)0x800000E2) {
                n = *(s32 *)(p + 0x2B4);
                if (n >= 3) {
                    c = *(s32 *)(p + 0x2B0);
                    if (c < 2) {
                        *(s32 *)(p + 0x2B0) = 2;
                    } else {
                        *(s32 *)(p + 0x2B0) = c + 1;
                        if (c + 1 >= n) {
                            *(s32 *)(p + 0x2B0) = 0;
                        }
                    }
                }
                func_L39_006AB098(p);
            } else if (v == 8) {
                func_L39_006AB8A8(p);
            } else if (v == 0x1B) {
                setMenuState_006AAA08(0x2C);
            } else if (v == 9) {
                func_L39_006AB7E0(p, 0x20);
                func_L39_006AB7E0(p, 0x20);
            } else if (v == 10) {
                *(s16 *)(p + 0x2B8) = 1;
                func_001206F4(*(void **)(p + 0x2C4), func_L39_006ABBB8(p));
                setMenuState_006AAA08(0x2C);
                return 1;
            } else if (v >= 0) {
                if ((u32)(v - 0x20) < 0xE1) {
                    if (func_L39_006A90F0(v) || D_L39_0024D15C[i] == 0x20) {
                        r = func_L39_006A8FB0(*(s16 *)&D_L39_0024D15C[i]);
                        lo = r & 0xFF;
                        r >>= 8;
                        hi = r;
                        if (hi & 0x80) {
                            func_L39_006AB7E0(p, hi);
                        }
                        func_L39_006AB7E0(p, lo);
                    }
                }
            }
        }
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x2F) || cmd == 0xB) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB780(p, p[0x2A9] ^ 1, 0);
        return 1;
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x30) || cmd == 0xC) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB780(p, 0, p[0x2A8] ^ 1);
        return 1;
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x31) || cmd == 0xE) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB7E0(p, 0x20);
        return 1;
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x32) || cmd == 6) {
        func_L39_00688340(3, 0, 0);
        *(s16 *)(p + 0x2B8) = 1;
        func_001206F4(*(void **)(p + 0x2C4), func_L39_006ABBB8(p));
        setMenuState_006AAA08(0x2C);
        return 1;
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x33) || cmd == 8) {
        func_L39_00688340(5, 0, 0);
        func_L39_006AB8A8(p);
        return 1;
    }
    if (cmd == 7) {
        if (*(s32 *)(p + 0x290) >= 2) {
            if (*(s32 *)(p + 0x290) < 0x2F) {
                func_L39_00688340(4, 0, 0);
                q = ((M_006AAA08 *)p)->items[*(s32 *)(p + 0x290)];
                {
                    s32 k0 = q[0x14];
                    s32 k1 = q[0x15];
                    func_L39_006AB7E0(p, k0);
                    if (k0 & 0x80) {
                        func_L39_006AB7E0(p, k1);
                    }
                }
                return 1;
            }
        }
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x34) || cmd == 5) {
        if (cmd == 7) {
            func_L39_00688340(4, 0, 0);
        } else {
            func_L39_00688340(0x17, 0, 0);
        }
        setMenuState_006AAA08(0x2C);
        return 1;
    }
    if ((cmd == 7 && *(s32 *)(p + 0x290) == 0x35) || cmd == 0xF) {
        func_L39_00688340(3, 0, 0);
        return 1;
    }
    if (cmd == 3) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB300(p, 0, -1);
        return 1;
    }
    if (cmd == 4) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB300(p, 0, 1);
        return 1;
    }
    if (cmd == 1) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB300(p, -1, 0);
        return 1;
    }
    if (cmd == 2) {
        func_L39_00688340(3, 0, 0);
        func_L39_006AB300(p, 1, 0);
        return 1;
    }
    func_L39_006AB8F8(p);
    t = *(s32 *)(p + 0x290);
    if ((u32)(t - 2) < 0x32) {
        o = ((M_006AAA08 *)p)->items[t];
        o->vt->f30(o, &x, &y);
        o = ((M_006AAA08 *)p)->items[*(s32 *)(p + 0x290)];
        o->vt->f34(o, &w, &h);
        func_L39_00689F00(p, x, y, w, h, 0.026f, 0.25f, 0, 3, 3);
    } else {
        func_L39_00689F00(p, 2.0f, 2.0f, 0.0f, 0.0f, 0.026f, 0.25f, 0, 3, 3);
    }
    return 0;
}
/* localdecomp:end func_L39_006AAA08 */
