#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3B9B00;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3B9B00 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3B9B00;
typedef struct { u8 b[256]; } C_3B9B00;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3B9D08;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3B9D08 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3B9D08;
typedef struct { u8 b[256]; } C_3B9D08;
typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003B9F08;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003B9F08 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003B9F08;
typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003BA0F8;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003BA0F8 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003BA0F8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA2E8;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA2E8 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA2E8;
typedef struct { u8 b[256]; } C_3BA2E8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA4F0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA4F0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA4F0;
typedef struct { u8 b[256]; } C_3BA4F0;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA6D0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA6D0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA6D0;
typedef struct { u8 b[256]; } C_3BA6D0;
typedef struct {
    u8 pad0[28];
    f32 phase;
    u8 pad20[136 - 32];
    f32 size;
    u8 pad8C[168 - 140];
    s32 range;
    u8 padAC[4];
    u8 trail0[32];
    u8 trail1[32];
} Vars_003BA8B0;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 group;
    u8 pad22[49 - 34];
    u8 visible;
    u8 pad32[2];
    u16 flags;
    u8 pad36[104 - 54];
    Vars_003BA8B0 *vars;
    u8 pad6C[170 - 108];
    s16 oclass;
    u8 padAC[84];
} Moby_003BA8B0;
typedef struct {
    u8 pad[0x1C];
    f32 f1C;
    u8 pad2[0x88 - 0x20];
    f32 f88;
    u8 pad3[0xA8 - 0x8C];
    int xA8;
    u8 pad4[0xB0 - 0xAC];
    u8 xB0[4];
} S_3BAAD8v;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x31 - 0x22];
    u8 b31;
    u8 pad3[0x34 - 0x32];
    u16 h34;
    u8 pad4[0x68 - 0x36];
    S_3BAAD8v *v;
    u8 pad5[0xAA - 0x6C];
    s16 hAA;
} S_3BAAD8m;

typedef struct {
    u8 pad[0x24];
    f32 f24;
} P_003B8B50;
typedef struct {
    u8 pad[0xC];
    s32 iC;
    u8 pad2[0xAC - 0x10];
    s16 hAC;
} V_003B8B50;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x24 - 0x22];
    P_003B8B50 *p24;
    u8 pad3[0x2C - 0x28];
    f32 f2C;
    u8 pad4[0x34 - 0x30];
    u16 h34;
    u8 pad5[0x68 - 0x36];
    V_003B8B50 *v;
    u8 pad6[0xAA - 0x6C];
    s16 hAA;
} M_003B8B50;

typedef struct {
    u8 pad0[0x84];
    s16 h84;
    u8 pad86[0x9C - 0x86];
    s32 i9C;
} V_003BB258;
typedef struct {
    u8 pad0[0x68];
    V_003BB258 *vars;
    u8 pad6C[0x78 - 0x6C];
    s32 i78;
    u8 pad7C[0xAA - 0x7C];
    s16 hAA;
} M_003BB258;

/* localdecomp:start func_L01_003B84E8 */
void func_L01_003B84E8(void) {

}
/* localdecomp:end func_L01_003B84E8 */

INCLUDE_ASM("asm/levels", func_L01_003B84F0);

INCLUDE_ASM("asm/levels", func_L01_003B8878);

INCLUDE_ASM("asm/levels", func_L01_003B89F8);

/* localdecomp:start func_L01_003B8AD8 */
extern s32 D_001D545C;
extern s32 D_L01_001E6DB0[];
extern s32 func_L01_004BA800(void);
extern void func_L01_003B89F8(void *a0, s32 a1);

void func_L01_003B8AD8(void *a0, s32 a1, s32 a2) {
    if (D_001D545C == a1) {
        if (func_L01_004BA800() != 0) {
            if (D_L01_001E6DB0[0] == a2) {
                func_L01_003B89F8(a0, 0);
            }
        } else {
            func_L01_003B89F8(a0, 1);
        }
    }
}
/* localdecomp:end func_L01_003B8AD8 */

/* localdecomp:start func_L01_003B8B50 */
extern f32 D_001A4C68[];
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001E29C0[];
extern s16 *D_L01_0021DE20[];
extern int D_L01_001E001C;
extern int D_L01_001E0058;
extern void func_L01_00445F40(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38(void *);
extern void func_L01_003B8E60(void *, s32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003B9BB8(void *);
extern void func_L01_003BB2E0(void *);
extern void func_L01_00404808(void (*)(void *), void *);

void func_L01_003B8B50(M_003B8B50 *o) {
    V_003B8B50 *v = o->v;

    if (o->h34 & 2) {
        return;
    }
    if (o->hAA != 0x1D3E && *(u8 *)0x1D5476 != 0) {
        func_L01_00445F40(o, 0x1D3E);
        o->f2C = o->p24->f24 * 1.5f;
        func_003C3A10(o, 5, 0, 0);
        func_003C7C38(o);
    }
    if (D_001D545C == 9) {
        if (D_L01_001F3F40[0] != 2) {
            return;
        }
    } else if (D_L01_001F3F40[0] != 0) {
        return;
    }
    func_L01_003B8AD8(o, 9, 1);
    func_L01_003B8AD8(o, 0x16, 0);
    switch (o->b20) {
    case 0:
        func_L01_003B8E60(o, o->b21);
        v->hAC = 0;
        break;
    case 1:
        if (v->iC != -1 && func_L01_00456500(D_L01_001E29C0, v->iC) != 0) {
            s16 *q;
            u8 *e;

            q = D_L01_0021DE20[o->b21];
            while (o->b21 != 0xFF && o->b21 <= D_L01_001E0058 && q != 0 &&
                   ((q != 0 && q[-1] >= 0) || q == D_L01_0021DE20[o->b21])) {
                e = (u8 *)(D_L01_001E001C + ((*q & 0x7FFF) << 8));
                if (e == 0)
                    break;
                e[0x31] = 0;
                *(u16 *)(e + 0x34) |= 1;
                q++;
            }
            func_L01_004450F0(o, 2, -1);
        }
        func_L01_003B9BB8(o);
        if (D_001D545C != 13 || !(89.0f < D_001A4C68[0]))
            func_L01_00404808(func_L01_003BB2E0, o);
        break;
    case 2:
        if (func_L01_00456500(D_L01_001E29C0, v->iC) == 0) {
            s16 *q;
            u8 *e;

            q = D_L01_0021DE20[o->b21];
            while (o->b21 != 0xFF && o->b21 <= D_L01_001E0058 && q != 0 &&
                   ((q != 0 && q[-1] >= 0) || q == D_L01_0021DE20[o->b21])) {
                e = (u8 *)(D_L01_001E001C + ((*q & 0x7FFF) << 8));
                if (e == 0)
                    break;
                e[0x31] = 1;
                *(u16 *)(e + 0x34) &= 0xFFFE;
                q++;
            }
            func_L01_004450F0(o, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L01_003B8B50 */

INCLUDE_ASM("asm/levels", func_L01_003B8E60);

INCLUDE_ASM("asm/levels", func_L01_003B9BB8);

INCLUDE_ASM("asm/levels", func_L01_003BA358);

/* localdecomp:start func_L01_003BB258 */
extern s32 func_0038CB00(void *p);
extern s32 func_0038DBD8(s32 a, s32 b, f32 f);

void func_L01_003BB258(M_003BB258 *a0) {
    V_003BB258 *v = a0->vars;

    if (a0->hAA != 0x9B0) {
        return;
    }
    if (func_0038CB00(&v->h84) != 0) {
        v->h84 = 0x2A;
        v->i9C = (v->i9C == 0);
    }
    a0->i78 = func_0038DBD8(a0->i78, v->i9C != 0 ? 0x50787878 : 0x50141414, 0.18f);
}
/* localdecomp:end func_L01_003BB258 */

/* localdecomp:start func_L01_003BB2E0 */
extern void func_L01_003BC320(S_3BAAD8m *o);
extern void func_L01_003BC0F8(Moby_003BA8B0 *self);
extern void func_L01_003BBF18(M_3BA6D0 *a0);
extern void func_L01_003BBD38(M_3BA4F0 *a0);
extern void func_L01_003BBB30(M_3BA2E8 *a0);
extern void func_L01_003BB348(M_3B9B00 *a0);
extern void func_L01_003BB550(M_3B9D08 *a0);
extern void func_L01_003BB750(M_003B9F08 *o);
extern void func_L01_003BB940(M_003BA0F8 *o);

void func_L01_003BB2E0(void *a0)
{
    ((void (*)(void *a))func_L01_003BB348)(a0);
    ((void (*)(void *a))func_L01_003BB750)(a0);
    ((void (*)(void *a))func_L01_003BB940)(a0);
    ((void (*)(void *a))func_L01_003BBB30)(a0);
    ((void (*)(void *a))func_L01_003BBD38)(a0);
    ((void (*)(void *a))func_L01_003BBF18)(a0);
    ((void (*)(void *a))func_L01_003BC0F8)(a0);
    ((void (*)(void *a))func_L01_003BC320)(a0);
    ((void (*)(void *a))func_L01_003BB550)(a0);
}
/* localdecomp:end func_L01_003BB2E0 */

/* localdecomp:start func_L01_003BB348 */



extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern int D_L01_001E001C;
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);
extern int func_L01_0040AF60(void);
extern int func_0038DC20(f32 *, f32);
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);

void func_L01_003BB348(M_3B9B00 *a0) {
    s16 *p;
    M_3B9B00 *m;
    V_3B9B00 *v;
    f32 buf[4];
    int flag;

    if (a0->b21 == 255) {
        return;
    }
    flag = func_L01_0040AF60();
    for (p = D_L01_0021DE20[a0->b21];
         a0->b21 != 255 && a0->b21 <= D_L01_001E0058 && p != 0 &&
         (p[-1] >= 0 || p == D_L01_0021DE20[a0->b21]); p++) {
        m = (M_3B9B00 *)(D_L01_001E001C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b31 == 0) {
            continue;
        }
        func_0038CE50(buf, m, 0.0009765625f);
        buf[3] *= 1.1f;
        if (func_0038DC20(buf, (f32)v->iA8) == -1) {
            continue;
        }
        if (m->h34 & 1) {
            continue;
        }
        if (m->hAA != 2480) {
            continue;
        }
        if (m->b20 != 1) {
            continue;
        }
        if (flag) {
            v->f1C -= 0.1f;
            if (v->f1C <= -8.0f) {
                v->f1C += 8.0f;
            }
        }
        func_L01_0040A4A0(m, v->bB0, 3, 0x60804040, 0x204090, 23, v->f88 * 0.8f, v->f88 * 5.0f, v->f1C);
    }
}
/* localdecomp:end func_L01_003BB348 */

/* localdecomp:start func_L01_003BB550 */
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);



extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern int D_L01_001E001C;
extern int func_L01_0040AF60(void);
extern int func_0038DC20(f32 *, f32);

void func_L01_003BB550(M_3B9D08 *a0) {
    s16 *p;
    M_3B9D08 *m;
    V_3B9D08 *v;
    f32 buf[4];
    int flag;

    if (a0->b21 == 255) {
        return;
    }
    flag = func_L01_0040AF60();
    for (p = D_L01_0021DE20[a0->b21];
         a0->b21 != 255 && a0->b21 <= D_L01_001E0058 && p != 0 &&
         (p[-1] >= 0 || p == D_L01_0021DE20[a0->b21]); p++) {
        m = (M_3B9D08 *)(D_L01_001E001C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b31 == 0) {
            continue;
        }
        ((void (*)(f32 *, M_3B9D08 *, f32))func_0038CE50)(buf, m, 0.0009765625f);
        buf[3] *= 1.1f;
        if (func_0038DC20(buf, (f32)v->iA8) == -1) {
            continue;
        }
        if (m->h34 & 1) {
            continue;
        }
        if (m->hAA != 7572) {
            continue;
        }
        if (m->b20 != 1) {
            continue;
        }
        if (flag) {
            v->f1C -= 0.1f;
            if (v->f1C <= -8.0f) {
                v->f1C += 8.0f;
            }
        }
        ((void (*)(M_3B9D08 *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0)(m, v->bB0, 4, 0x605696FF, 192, 23, v->f88 * 2.4f, v->f88 * 10.0f, v->f1C);
    }
}
/* localdecomp:end func_L01_003BB550 */

/* localdecomp:start func_L01_003BB750 */
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);
extern int D_L01_001E001C;


extern s16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern s32 func_L01_0040AF60(void);
extern s32 func_0038DC20(f32 *, f32);

void func_L01_003BB750(M_003B9F08 *o) {
    f32 vec[4];
    s32 flag;
    s16 *list;
    M_003B9F08 *m;
    V_003B9F08 *v;

    if (o->b33 == 255) {
        return;
    }
    flag = func_L01_0040AF60();
    list = D_L01_0021DE20[o->b33];
    while (o->b33 != 255 && o->b33 <= D_L01_001E0058 && list != 0 && (list[-1] >= 0 || list == D_L01_0021DE20[o->b33])) {
        m = &(*(M_003B9F08 * *)&D_L01_001E001C)[*list & 0x7FFF];
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b49 != 0) {
            ((void (*)(f32 *, M_003B9F08 *, f32))((void (*)(f32 *, M_3B9D08 *, f32))func_0038CE50))(vec, m, 0.0009765625f);
            vec[3] *= 1.1f;
            if (func_0038DC20(vec, (f32)v->i168) != -1 && !(m->h52 & 1) && m->oclass == 7303 && m->state == 1) {
                if (flag != 0) {
                    v->f28 -= 0.1f;
                    if (v->f28 <= -8.0f) {
                        v->f28 += 8.0f;
                    }
                }
                ((void (*)(M_003B9F08 *, void *, s32, s32, s32, s32, f32, f32, f32))((void (*)(M_3B9D08 *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0))(m, v->v176, 2, 0x605696FF, 192, 23, v->f136, v->f136 * 7.0f, v->f28);
            }
        }
        list++;
    }
}
/* localdecomp:end func_L01_003BB750 */

/* localdecomp:start func_L01_003BB940 */
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);
extern int D_L01_001E001C;


extern s16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern s32 func_L01_0040AF60(void);
extern s32 func_0038DC20(f32 *, f32);

void func_L01_003BB940(M_003BA0F8 *o) {
    f32 vec[4];
    s32 flag;
    s16 *list;
    M_003BA0F8 *m;
    V_003BA0F8 *v;

    if (o->b33 == 255) {
        return;
    }
    flag = func_L01_0040AF60();
    list = D_L01_0021DE20[o->b33];
    while (o->b33 != 255 && o->b33 <= D_L01_001E0058 && list != 0 && (list[-1] >= 0 || list == D_L01_0021DE20[o->b33])) {
        m = &(*(M_003BA0F8 * *)&(*(M_003B9F08 * *)&D_L01_001E001C))[*list & 0x7FFF];
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b49 != 0) {
            ((void (*)(f32 *, M_003BA0F8 *, f32))((void (*)(f32 *, M_003B9F08 *, f32))((void (*)(f32 *, M_3B9D08 *, f32))func_0038CE50)))(vec, m, 0.0009765625f);
            vec[3] *= 1.1f;
            if (func_0038DC20(vec, (f32)v->i168) != -1 && !(m->h52 & 1) && m->oclass == 6776 && m->state == 1) {
                if (flag != 0) {
                    v->f28 -= 0.1f;
                    if (v->f28 <= -8.0f) {
                        v->f28 += 8.0f;
                    }
                }
                ((void (*)(M_003BA0F8 *, void *, s32, s32, s32, s32, f32, f32, f32))((void (*)(M_003B9F08 *, void *, s32, s32, s32, s32, f32, f32, f32))((void (*)(M_3B9D08 *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0)))(m, v->v176, 2, 0x6096FF56, 0xC000, 23, v->f136, v->f136 * 7.0f, v->f28);
            }
        }
        list++;
    }
}
/* localdecomp:end func_L01_003BB940 */

/* localdecomp:start func_L01_003BBB30 */
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);
extern int D_L01_001E001C;



extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern int func_L01_0040AF60(void);
extern int func_0038DC20(f32 *, f32);

void func_L01_003BBB30(M_3BA2E8 *a0) {
    s16 *p;
    M_3BA2E8 *m;
    V_3BA2E8 *v;
    f32 buf[4];
    int flag;

    if (a0->b21 == 255) {
        return;
    }
    flag = func_L01_0040AF60();
    for (p = D_L01_0021DE20[a0->b21];
         a0->b21 != 255 && a0->b21 <= D_L01_001E0058 && p != 0 &&
         (p[-1] >= 0 || p == D_L01_0021DE20[a0->b21]); p++) {
        m = (M_3BA2E8 *)((*(int *)&(*(M_003BA0F8 * *)&(*(M_003B9F08 * *)&D_L01_001E001C))) + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b31 == 0) {
            continue;
        }
        ((void (*)(f32 *, M_3BA2E8 *, f32))((void (*)(f32 *, M_003BA0F8 *, f32))((void (*)(f32 *, M_003B9F08 *, f32))((void (*)(f32 *, M_3B9D08 *, f32))func_0038CE50))))(buf, m, 0.0009765625f);
        buf[3] *= 1.1f;
        if (func_0038DC20(buf, (f32)v->iA8) == -1) {
            continue;
        }
        if (m->h34 & 1) {
            continue;
        }
        if (m->hAA != 7238) {
            continue;
        }
        if (m->b20 != 1) {
            continue;
        }
        if (flag) {
            v->f1C -= 0.1f;
            if (v->f1C <= -8.0f) {
                v->f1C += 8.0f;
            }
        }
        ((void (*)(M_3BA2E8 *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0)(m, v->bB0, 2, 0x60804040, 0x204090, 23, v->f88 * 0.3f, v->f88 * 7.0f * 0.3f, v->f1C);
    }
}
/* localdecomp:end func_L01_003BBB30 */

/* localdecomp:start func_L01_003BBD38 */
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);



extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern int D_L01_001E001C;
extern int func_0038DC20(f32 *, f32);

void func_L01_003BBD38(M_3BA4F0 *a0) {
    s16 *p;
    M_3BA4F0 *m;
    V_3BA4F0 *v;
    f32 buf[4];

    if (a0->b21 == 255) {
        return;
    }
    for (p = D_L01_0021DE20[a0->b21];
         a0->b21 != 255 && a0->b21 <= D_L01_001E0058 && p != 0 &&
         (p[-1] >= 0 || p == D_L01_0021DE20[a0->b21]); p++) {
        m = (M_3BA4F0 *)(D_L01_001E001C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b31 == 0) {
            continue;
        }
        ((void (*)(f32 *, M_3BA4F0 *, f32))func_0038CE50)(buf, m, 0.0009765625f);
        buf[3] *= 1.1f;
        if (func_0038DC20(buf, (f32)v->iA8) == -1) {
            continue;
        }
        if (m->h34 & 1) {
            continue;
        }
        if (m->hAA != 4733) {
            continue;
        }
        if (m->b20 != 1) {
            continue;
        }
        v->f1C -= 0.1f;
        if (v->f1C <= -8.0f) {
            v->f1C += 8.0f;
        }
        ((void (*)(M_3BA4F0 *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0)(m, v->bB0, 2, 0x605696FF, 192, 23, v->f88 * 0.4f, v->f88 * 4.0f, v->f1C);
    }
}
/* localdecomp:end func_L01_003BBD38 */

/* localdecomp:start func_L01_003BBF18 */
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);



extern s16 *D_L01_0021DE20[];
extern int D_L01_001E0058;
extern int D_L01_001E001C;
extern int func_0038DC20(f32 *, f32);

void func_L01_003BBF18(M_3BA6D0 *a0) {
    s16 *p;
    M_3BA6D0 *m;
    V_3BA6D0 *v;
    f32 buf[4];

    if (a0->b21 == 255) {
        return;
    }
    for (p = D_L01_0021DE20[a0->b21];
         a0->b21 != 255 && a0->b21 <= D_L01_001E0058 && p != 0 &&
         (p[-1] >= 0 || p == D_L01_0021DE20[a0->b21]); p++) {
        m = (M_3BA6D0 *)(D_L01_001E001C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b31 == 0) {
            continue;
        }
        ((void (*)(f32 *, M_3BA6D0 *, f32))func_0038CE50)(buf, m, 0.0009765625f);
        buf[3] *= 1.1f;
        if (func_0038DC20(buf, (f32)v->iA8) == -1) {
            continue;
        }
        if (m->h34 & 1) {
            continue;
        }
        if (m->hAA != 7245) {
            continue;
        }
        if (m->b20 != 1) {
            continue;
        }
        v->f1C -= 0.1f;
        if (v->f1C <= -8.0f) {
            v->f1C += 8.0f;
        }
        ((void (*)(M_3BA6D0 *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0)(m, v->bB0, 2, 0x605696FF, 192, 23, v->f88 * 0.4f, v->f88 * 3.0f, v->f1C);
    }
}
/* localdecomp:end func_L01_003BBF18 */

/* localdecomp:start func_L01_003BC0F8 */
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);
extern int D_L01_001E001C;
extern s16 *D_L01_0021DE20[];


extern s32 D_L01_001E0058 __attribute__((section(".sdata")));

extern s32 func_0038DC20(f32 *, f32);

void func_L01_003BC0F8(Moby_003BA8B0 *self) {
    f32 sphere[4];
    u16 *p;
    Moby_003BA8B0 *m;
    Vars_003BA8B0 *v;
    f32 a;
    f32 b;

    if (self->group != 255) {
        p = ((u16 * *)&D_L01_0021DE20)[self->group];
        while (self->group != 255 && self->group <= D_L01_001E0058 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == ((u16 * *)&D_L01_0021DE20)[self->group])) {
            m = &(*(Moby_003BA8B0 * *)&D_L01_001E001C)[*p & 0x7FFF];
            if (m == 0) break;
            v = m->vars;
            if (m->visible != 0) {
                ((void (*)(f32 *, Moby_003BA8B0 *, f32))func_0038CE50)(sphere, m, 0.0009765625f);
                sphere[3] *= 1.1f;
                if (func_0038DC20(sphere, (f32)v->range) != -1 && !(m->flags & 1) &&
                    m->oclass == 4752 && m->state == 1) {
                    v->phase -= 0.1f;
                    if (v->phase <= -8.0f) {
                        v->phase += 8.0f;
                    }
                    a = v->size * 0.4f;
                    b = v->size * 3.0f;
                    ((void (*)(Moby_003BA8B0 *, void *, s32, u32, u32, s32, f32, f32, f32))func_L01_0040A4A0)(m, v->trail0, 2, 0x60804020, 0xC00000, 23, a, b, v->phase);
                    ((void (*)(Moby_003BA8B0 *, void *, s32, u32, u32, s32, f32, f32, f32))func_L01_0040A4A0)(m, v->trail1, 1, 0x60804020, 0xC00000, 23, a * 1.5f, b * 1.5f, v->phase);
                }
            }
            p++;
        }
    }
}
/* localdecomp:end func_L01_003BC0F8 */

/* localdecomp:start func_L01_003BC320 */
extern int D_L01_001E001C;
extern s16 *D_L01_0021DE20[];
extern void func_L01_0040A4A0(M_3B9B00 *, void *, int, int, int, int, f32, f32, f32);
extern void func_0038CE50(f32 *, M_3B9B00 *, f32);

extern int func_L01_0040AF60(void);
extern int func_0038DC20(f32 *, f32);
extern int D_L01_001E0058;

void func_L01_003BC320(S_3BAAD8m *o) {
    u16 *p;
    int k;
    S_3BAAD8m *m;
    S_3BAAD8v *v;
    f32 buf[4];

    if (o->b21 == 255) {
        return;
    }
    k = func_L01_0040AF60();
    p = ((u16 * *)&D_L01_0021DE20)[o->b21];
    while (o->b21 != 255 && o->b21 <= D_L01_001E0058 && p != 0
           && (((s16 *)p)[-1] >= 0 || p == ((u16 * *)&D_L01_0021DE20)[o->b21])) {
        m = (S_3BAAD8m *)((*(u8 * *)&D_L01_001E001C) + (*p & 0x7FFF) * 256);
        if (m == 0) {
            return;
        }
        v = m->v;
        if (m->b31 != 0) {
            ((void (*)(f32 *, S_3BAAD8m *, f32))func_0038CE50)(buf, m, 0.0009765625f);
            buf[3] *= 1.1f;
            if (func_0038DC20(buf, v->xA8) != -1 && !(m->h34 & 1) && m->hAA == 4928 && m->b20 == 1) {
                if (k != 0) {
                    v->f1C -= 0.1f;
                    if (v->f1C <= -8.0f) {
                        v->f1C += 8.0f;
                    }
                }
                ((void (*)(S_3BAAD8m *, void *, int, int, int, int, f32, f32, f32))func_L01_0040A4A0)(m, v->xB0, 2, 0x605696FF, 192, 23, v->f88, v->f88 * 7.0f, v->f1C);
            }
        }
        p++;
    }
}
/* localdecomp:end func_L01_003BC320 */
