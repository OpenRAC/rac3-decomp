#include "common.h"

/* localdecomp:start func_L40_0041B2D0 */
typedef struct {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} SVt_0041B2D0;

typedef struct {
    u8 pad0[0x40];
    s32 w40;
} SC_0041B2D0;

typedef struct {
    u8 pad0[4];
    SC_0041B2D0 *c;
} SB_0041B2D0;

typedef struct {
    u8 pad0[0x14];
    SVt_0041B2D0 *vt;
    u8 pad18[0x1A14 - 0x18];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 pad24CA[0x2544 - 0x24CA];
    s32 w2544;
    u8 pad2548[0x10];
    SB_0041B2D0 *p2558;
} SP_0041B2D0;

typedef struct {
    f32 f0;
    f32 f4;
    s32 w8;
    s32 wC;
    u8 pad10[4];
    s32 w14;
    f32 f18;
    u8 pad1C[4];
    s32 w20;
    s32 w24;
    f32 f28;
    f32 f2C;
    f32 f30;
    s32 w34;
    u8 pad38[0x18];
    s32 w50;
    u8 pad54[8];
    s32 w5C;
} SV_0041B2D0;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31[0x37];
    SV_0041B2D0 *vars;
} SM_0041B2D0;

typedef struct {
    u32 w0;
    s32 w4;
} SMsg_0041B2D0;

extern SP_0041B2D0 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern u8 D_L40_00249FC0[];
extern u8 *D_L40_00248500;
extern void func_L39_00662B18(void *, void *, s32);
extern void func_L40_0041B820(void *, s32);
extern void func_L39_00570200(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB350(s32, void *);
extern void func_L04_003FDBF0(s32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L40_0041B2D0(SM_0041B2D0 *m, SMsg_0041B2D0 *msg) {
    SV_0041B2D0 *vars;
    s32 kind;
    SP_0041B2D0 *p;
    s32 doit;
    u8 reset;
    s32 a;
    s32 b;
    f32 f;
    s32 g;
    s32 h;

    kind = msg->w0 & 0xF;
    vars = m->vars;
    switch (kind) {
    case 1:
        func_L39_00662B18(msg, &a, 4);
        func_L39_00662B18(msg, &b, 4);
        if (a == -1) {
            if (b > vars->wC) {
                vars->wC = b;
                func_L40_0041B820(m, 0);
            }
            break;
        }
        doit = 0;
        if (vars->w50 == -1) {
            doit = 1;
        } else if (vars->w50 != a) {
            if (b > vars->wC) {
                doit = 1;
            } else if (b == vars->wC && a < vars->w50) {
                doit = 1;
            }
            if (doit) {
                func_L40_0041B820(m, 0);
            }
        }
        p = D_L40_00249330[a];
        if (doit && p != 0) {
            vars->wC = b;
            vars->w14 = 0;
            vars->w50 = p->w2544;
            p->vt->fn34(p, 0x37, 1, 1, 1);
            m->b30 = 0xFF;
            if (p->b1A14) {
                func_L39_00570200(p->b24C9, D_L40_00249FC0 + p->b24C9 * 0x460, D_L40_00249FC0 + p->b24C9 * 0x460 + 0x10, 3, 0x96, 0);
                func_L01_003EB3C0(p->b24C9, D_L40_00248500 + vars->w20 * 128 + 0x70);
                func_L01_003EB350(p->b24C9, D_L40_00248500 + vars->w20 * 128 + 0x30);
                func_L04_003FDBF0(p->b24C9, vars->f28, vars->f2C);
            }
            if (vars->w34 == 0) {
                func_L01_004450F0(m, 3, -1);
                if (p->p2558->c->w40 == 0) {
                    func_L01_004450F0(m, 4, -1);
                }
            } else {
                func_L01_004450F0(m, 3, -1);
            }
            vars->w24 = 0;
            vars->f18 = vars->f0 * (vars->f30 * 6.28318548f);
        } else {
            m->b30 = 0x20;
        }
        break;
    case 0:
        func_L39_00662B18(msg, &f, 4);
        func_L39_00662B18(msg, &g, 4);
        func_L39_00662B18(msg, &h, 4);
        func_L39_00662B18(msg, &reset, 1);
        if (reset) {
            func_L40_0041B820(m, 0);
        }
        if (vars->w8 < (s32)(msg->w4 + (msg->w0 >> 13))) {
            SP_0041B2D0 *q = 0;
            if (vars->w50 >= 0) {
                q = D_L40_00249330[vars->w50];
            }
            if (g != 0 || q == 0 || q->b1A14 == 0) {
                vars->f0 = f;
            }
            vars->w8 = msg->w4 + (msg->w0 >> 13);
            vars->f4 = f;
            if (vars->f0 == 0.0f || vars->f0 == 1.0f) {
                vars->w5C = h;
            }
            if (vars->w34 != 0 && g != 0) {
                if (vars->f0 == 1.0f) {
                    func_L01_004450F0(m, 5, -1);
                } else if (m->b20 == 5) {
                    func_L01_004450F0(m, 1, -1);
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L40_0041B2D0 */
