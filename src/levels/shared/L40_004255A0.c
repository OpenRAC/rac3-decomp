#include "common.h"

/* declared by functions of L40_00424920.c, which this file was cut from */
extern s32 func_L40_00424B10(void *arg0);
extern u8 *D_L40_0024845C;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[0x2A0]; s32 f2A0; } V_424328;
typedef struct { u8 pad[0x20]; u8 state; u8 p21[0x47]; V_424328 *vars; } S_424328;
extern void func_L01_004450F0(S_424328 *, s32, s32);

/* localdecomp:start func_L40_004255A0 */
typedef struct { u32 target; u8 p4[4]; s32 state; } S220_004255A0;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 p34[0x70 - 0x34];
    u8 f70[0x220 - 0x70];
    S220_004255A0 s220;
    u8 p22C[4];
    s32 f230;
    s32 f234;
    s32 f238;
    u8 p23C[0x27C - 0x23C];
    s32 f27C;
    u8 p280[0x2A0 - 0x280];
    s32 f2A0;
} V_004255A0;
typedef struct {
    u8 pad[0x1C];
    u8 (*f1C)(void *, s32);
} VT_004255A0;
typedef struct {
    u8 pad[3];
    u8 type;
    u8 p4[0x14 - 4];
    VT_004255A0 *vt;
    u8 p18[0x2544 - 0x18];
    s32 f2544;
} O_004255A0;

extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
typedef struct { u8 pad[0x1F8]; f32 f1F8[1]; } T_004255A0;
extern T_004255A0 D_L40_00357260;
extern u8 D_L40_00242930[8];
__asm__(".extern D_001D5F30_sda, 4");
extern s8 *D_001D5F30_sda;

extern s32 func_L39_005B4398(s32);
extern s32 func_L40_00426F68(u8 *);
extern s32 func_L40_00426CC0(u8 *, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, s32);
extern O_004255A0 *func_L39_0061CEA0(void *);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L40_00424E68(u8 *, void *, f32);
extern s32 func_L40_00424B10(void *arg0);
extern s32 func_L40_00425050(s32 a0);
extern void func_L40_00424F88(s32 a0, s32 a1);
extern f32 func_L40_00424E00(s32 a0, void *a1);
extern s32 func_L40_00425078(s32 a0);
extern void func_L40_00424FD0(s32 id, s32 value);

s32 func_L40_004255A0(u8 *m, s32 msg) {
    V_004255A0 *v = *(V_004255A0 **)(m + 0x68);
    S220_004255A0 *s = &v->s220;
    s32 p;
    s32 r;
    s32 t;
    f32 h;
    f32 extra;
    f32 d;
    f32 c;
    O_004255A0 *o;
    O_004255A0 *q;
    u8 buf[8];
    Vec4 pos;
    u8 ok;
    u8 *pp;

    if (msg != 0) {
        return 0;
    }
    switch (s->state) {
    case 0:
        t = D_L40_0024112C[0];
        if (v->f234 < t && (t & 7) == (((s32)m >> 8) & 7)) {
            v->f234 = D_L40_0024112C[0] + 30 + func_L39_005B4398(15);
            if (func_L40_00425050((s32)m) == 0) {
                if (v->s220.target != 0xFFFFFFFF) {
                    r = func_L40_00426F68(m);
                    if (r != v->s220.target) {
                        func_L40_00424F88((s32)m, r);
                    }
                } else {
                    r = func_L40_00426CC0(m, 0);
                    if (r != v->s220.target) {
                        func_L40_00424F88((s32)m, r);
                    }
                }
            }
        }
        p = func_L01_00447490(m, 0x10000, 0);
        h = func_L01_004474E8(m, p);
        h = h - h * (D_L40_00357260.f1F8[v->f27C] * 0.5f);
        if (p != 0 && *(void **)(p + 0x20) != 0 && D_001D5F30_sda[0x18E] == 0) {
            q = 0;
            o = func_L39_0061CEA0(*(void **)(p + 0x20));
            ok = v->f230 != 0 && v->f2A0 == 0;
            if (ok) {
                if (o != 0) {
                    ok = o->vt->f1C(o, v->f27C) ^ 1;
                }
            }
            if (ok) {
                if (o != 0 && (o->type & 0xF) == 0) {
                    q = o;
                }
                func_0038CB78(buf, 0, 8);
                extra = func_L40_00424E00((s32)m, buf);
                func_003C4A40(m, v->f70);
                if (q != 0) {
                    buf[q->f2544] += (s32)h;
                }
                h = h + extra;
                d = v->f30 - h;
                if (d > 0.0f) {
                    c = d;
                } else {
                    c = 0.0f;
                }
                if (c == 0.0f) {
                    func_L01_004450F0((S_424328 *)m, 5, -1);
                    pp = m + 0x10;
                    v->s220.state = 1;
                    pos.q = *(u128_t *)(m + 0x10);
                    pos.f[3] = 3.5f;
                    if (func_L39_005BE900(&pos, 0, (f32)m[0x30]) != -1) {
                        func_L39_005F33E0(1, 0, m);
                        func_L01_003303B8(pp, 1, 25, 20, 20, 20, 45, 2, 2.0f, 0.0f, 0.0f, 2.0f,
                                          1, 1, 1, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                                          0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                        func_L01_00452310(m, 0x1FF, D_L40_00242930, 1, 0x23, -1.0f, 3.0f, 7.0f, 6.0f, 12.0f,
                                          0xFF, -1.0f, -1.0f, 0xB4, 0);
                    }
                    if (func_L40_00425078((s32)m) == 0) {
                        func_L40_00424FD0((s32)m, (s32)buf);
                    }
                } else {
                    func_L40_00424E68(m, buf, h);
                }
            }
        }
        m[0xA8] = 0xFF;
        break;
    case 1:
        func_L40_00424B10(D_L40_0024845C + (v->f238 << 8));
        break;
    }
    return 0;
}
/* localdecomp:end func_L40_004255A0 */
