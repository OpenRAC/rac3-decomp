#include "common.h"

/* localdecomp:start func_L39_006AD978 */
extern u8 D_L39_0047DDA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006AD978(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DDA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006AD978 */

/* localdecomp:start func_L39_006AD9A0 */
typedef struct O_006AD9A0 O_006AD9A0;
typedef struct V_006AD9A0 {
    u8 pad0[0x1C];
    void (*f1C)(O_006AD9A0 *, s32, s32);
    u8 pad20[4];
    void (*f24)(O_006AD9A0 *, s32);
    u8 pad28[0x18];
    void (*f40)(O_006AD9A0 *, s32);
    void (*f44)(O_006AD9A0 *, s32, f32, f32);
    void (*f48)(O_006AD9A0 *, s32, s32);
    u8 pad4C[0x90];
    s32 (*fDC)(O_006AD9A0 *, s32);
} V_006AD9A0;
struct O_006AD9A0 {
    u8 pad[0x60];
    V_006AD9A0 *vt;
};
typedef struct T_006AD9A0 {
    u8 pad0[0x110];
    O_006AD9A0 *f110;
    O_006AD9A0 *f114;
    O_006AD9A0 *f118;
    u8 pad11C[4];
    O_006AD9A0 *f120;
    O_006AD9A0 *f124;
    O_006AD9A0 *f128;
    O_006AD9A0 *f12C;
    O_006AD9A0 *grid[4][4];
    u8 pad170[0x138];
    s32 a2A8[4];
    s32 a2B8[8];
    u8 a2D8[4];
    char a2DC[4][32];
    s32 a35C[4];
    s32 a36C[4];
    s32 a37C[4];
    u8 pad38C_[0];
    s32 f38C;
    s32 f390;
} T_006AD9A0;
typedef struct G_006AD9A0 {
    u8 pad[0x17C];
    s16 f17C;
    u8 pad17E[2];
    s32 f180;
    u8 pad184[0x19];
    s8 f19D;
} G_006AD9A0;
typedef struct N_006AD9A0 { s32 s[10]; } N_006AD9A0;
typedef union U_006AD9A0 { char buf[0x50]; N_006AD9A0 n; } U_006AD9A0;

typedef struct Net_006AD9A0 { s32 w[4]; } Net_006AD9A0;
extern Net_006AD9A0 D_L39_00240628 __attribute__((section(".sdata")));
__asm__(".extern D_L39_00241640, 16");
extern G_006AD9A0 *D_L39_00241640;
extern f32 D_001DD3F4_sda;
extern f32 D_001DD3F8_sda;
extern f32 D_001DD3FC_sda;
extern f32 D_001DD400_sda;
extern f32 D_001DD404_sda;
extern f32 D_001DD408_sda;
extern f32 D_001DD40C_sda;
extern f32 D_001DD410_sda;
extern f32 D_001DD414_sda;
extern f32 D_001DD418_sda;
extern f32 D_001DD41C_sda;
extern f32 D_001DD420_sda;
extern f32 D_001DD424_sda;
extern f32 D_001DD428_sda;
extern f32 D_001DD42C_sda;
extern f32 D_001DD430_sda;
extern f32 D_001DD434_sda;
extern f32 D_001DD438_sda;
extern f32 D_001DD43C_sda;
extern f32 D_001DD440_sda;
extern f32 D_001DD444_sda;
extern f32 D_001DD44C_sda;
extern f32 D_L39_00248B74[] __attribute__((section(".sdata")));
extern f32 D_L39_00248B78[] __attribute__((section(".sdata")));
extern f32 D_001DD460_sda;
extern char D_L39_00248B90[];
extern char D_L39_00248B98[];
extern char D_L39_00248BA0[];
extern char D_L39_00248BA8[];
extern char D_L39_00248BB0[];
extern char D_001A5D8E[];
extern s32 func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(T_006AD9A0 *, s32);
extern void func_L39_00689D28(T_006AD9A0 *, s32);
extern void func_L39_00689E58(T_006AD9A0 *, char *, u32, f32, f32);
extern void func_L39_00689DB8(T_006AD9A0 *, s32);
extern void func_L39_0068A6D0(T_006AD9A0 *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068A4A8(T_006AD9A0 *, s32, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(T_006AD9A0 *);
extern s32 func_00120048(char *, const char *, ...);
extern void func_0038CBC8(char *, s32);
extern void func_00120D28(char *, s32, s32);
extern void func_L39_006AE8F8(T_006AD9A0 *, s32, s32);
extern void func_L39_006AEF20(u8 *);
extern void func_L39_005C1A60(s32, s32, s32);

static __inline__ void label_006AD9A0(O_006AD9A0 **slot, char *fmt, s32 id) {
    char buf[0x50];
    func_00120048(buf, fmt, func_00381FF0(id));
    (*slot)->vt->f24(*slot, (s32)buf);
}

void func_L39_006AD9A0(T_006AD9A0 *this) {
    s32 s;
    f32 d;
    s32 i;
    s32 j;
    s32 k;
    O_006AD9A0 **p;

    func_L39_0067F100(0x410000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(this, func_00381FF0(0xFF4));
    func_L39_00689D28(this, func_00381FF0(0x124));
    func_L39_00689E58(this, D_L39_00248B90, 0x706EC8FF, 1.0f, 1.0f);
    func_L39_00689DB8(this, func_00381FF0(0xCD5));
    func_L39_0068A6D0(this, 0, 0x332299DE, D_001DD3F4_sda, D_001DD3F8_sda, D_001DD3FC_sda, D_001DD400_sda);
    func_L39_0068A6D0(this, 1, 0x332299DE, D_001DD404_sda, D_001DD408_sda, D_001DD40C_sda, D_001DD410_sda);
    func_L39_0068A6D0(this, 2, 0x332299DE, D_001DD414_sda, D_001DD418_sda, D_001DD41C_sda, D_001DD420_sda);
    func_L39_0068A6D0(this, 3, 0x332299DE, D_001DD424_sda, D_001DD428_sda, D_001DD42C_sda, D_001DD430_sda);
    func_L39_0068A6D0(this, 4, 0x332299DE, D_001DD434_sda, D_001DD438_sda, D_001DD43C_sda, D_001DD440_sda);
    d = D_001DD440_sda - D_001DD444_sda;
    func_L39_0068A4A8(this, 1, 4, 0x332299DE, D_001DD434_sda,
                      D_001DD438_sda + d * -1.5f / 5.0f + D_001DD44C_sda,
                      (D_001DD438_sda + -d / 5.0f) - (D_001DD438_sda + d * -2.0f / 5.0f),
                      D_001DD43C_sda - (D_001DD444_sda + D_001DD444_sda));
    func_L39_0068AAB8(this);

    label_006AD9A0(&this->f124, D_L39_00248B98, 0x1332);
    label_006AD9A0(&this->f128, D_L39_00248BA0, 0x1631);
    label_006AD9A0(&this->f12C, D_L39_00248BA8, 0x1632);

    for (p = this->grid[3], j = 0; j < 4; j++, p++) {
        p[-12]->vt->f1C(p[-12], 0, 0);
        p[-4]->vt->f1C(p[-4], 0, 0);
        p[-8]->vt->f1C(p[-8], 0, 0);
        p[0]->vt->f1C(p[0], 0, 0);
        p[-12]->vt->f48(p[-12], 1, 3);
        p[0]->vt->f48(p[0], 3, 3);
        p[-12]->vt->f44(p[-12], 1, D_001DD460_sda, 0.0f);
        p[0]->vt->f44(p[0], 1, D_L39_00248B78[0], 0.0f);
        p[-12]->vt->f40(p[-12], 1);
        p[0]->vt->f40(p[0], 1);
    }

    this->f120->vt->fDC(this->f120, D_L39_00241640->f17C % 10 + 0x25);
    this->f110->vt->f1C(this->f110, 1, 0);
    this->f114->vt->f1C(this->f114, 1, 0);
    this->f114->vt->f40(this->f114, 1);
    this->f118->vt->f1C(this->f118, 1, 0);
    this->f118->vt->f40(this->f118, 1);
    this->f124->vt->f48(this->f124, 1, 3);
    this->f124->vt->f1C(this->f124, 1, 0);
    this->f124->vt->f40(this->f124, 1);
    this->f124->vt->f44(this->f124, 1, D_001DD460_sda, 0.0f);
    this->f128->vt->f1C(this->f128, 1, 0);
    this->f128->vt->f40(this->f128, 1);
    this->f128->vt->f44(this->f128, 1, D_L39_00248B74[0], 0.0f);
    this->f12C->vt->f1C(this->f12C, 1, 0);
    this->f12C->vt->f40(this->f12C, 1);
    this->f12C->vt->f44(this->f12C, 1, D_L39_00248B78[0], 0.0f);

    {
    N_006AD9A0 names = {{
        func_00381FF0(0xBB1), func_00381FF0(0xBB2), func_00381FF0(0xDA),
        func_00381FF0(0xBB4), func_00381FF0(0xD8), func_00381FF0(0xD4),
        func_00381FF0(0x18C4), func_00381FF0(0x18C5), func_00381FF0(0x18C6),
        func_00381FF0(0x18C7)
    }};
    s = names.s[D_L39_00241640->f17C % 10];
    this->f114->vt->f24(this->f114, s);
    }

    s = func_00381FF0(0x1328);
    switch (D_L39_00240628.w[0]) {
    case 0: s = func_00381FF0(0x1024); break;
    case 1: s = func_00381FF0(0x10E2); break;
    case 2: s = func_00381FF0(0x1026); break;
    }
    this->f118->vt->f24(this->f118, s);
    this->f110->vt->f24(this->f110, func_00381FF0(0xF58));
    func_0038CBC8(D_001A5D8E, 0x40);
    func_00120D28(D_001A5D8E, func_00381FF0(0xF58), 0x10);

    for (i = 0; i < 4; i++) {
        this->a2D8[i] = 0;
        func_00120048(this->a2DC[i], D_L39_00248BB0, func_00381FF0(0x1424), i + 1);
        this->a35C[i] = 0;
        if (D_L39_00241640->f180 == 2 && D_L39_00241640->f19D == 0) {
            this->a36C[i] = i;
        } else {
            this->a36C[i] = i % 2;
        }
        this->a2A8[i] = -1;
        this->a37C[i] = -1;
    }
    for (k = 7; k >= 0; k--) {
        this->a2B8[k] = -1;
    }
    this->a2A8[0] = 0;
    this->a2D8[0] = 1;
    this->a2B8[0] = 0;
    if (D_L39_00241640->f180 == 2) {
        this->f390 = 8;
    } else {
        this->f390 = 2;
    }
    this->f38C = 0x16;
    func_L39_006AE8F8(this, 1, -1);
    func_L39_006AEF20((u8 *)this);
    func_L39_005C1A60(1, 1, 0x400);
}
/* localdecomp:end func_L39_006AD9A0 */

/* localdecomp:start func_L39_006AE208 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006AE208(void *);

extern void func_L39_0067F168();
void func_L39_006AE208(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006AE208 */

/* localdecomp:start func_L39_006AE238 */
typedef struct S_006AE238_Vtbl {
    u8 pad[0x30];
    void (*f30)(void *, s32 *, f32 *);
} S_006AE238_Vtbl;
typedef struct S_006AE238_Item {
    s32 f0;
    s32 type;
} S_006AE238_Item;
typedef struct S_006AE238_Obj {
    u8 pad[0x60];
    S_006AE238_Vtbl *vtbl;
} S_006AE238_Obj;
typedef struct S_006AE238_This {
    u8 pad[0x110];
    S_006AE238_Obj *items[4];
    u8 pad120[0x170];
    s32 f290;
} S_006AE238_This;
extern void func_L39_006AEF20(u8 *);
extern void func_L39_006AED18(void *);
extern void func_L39_006AF070(void *);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_006AEF70(void *, s32, s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_006AE3D8(void *);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern f32 D_001DD414_sda;
extern f32 D_001DD41C_sda;
extern f32 D_001DD444_sda;
extern f32 D_001DD474_sda;
extern f32 D_001DD478_sda;

s32 func_L39_006AE238(S_006AE238_This *this, s32 cmd) {
    s32 a;
    f32 b;
    s32 first;
    s32 last;
    s32 i;
    s32 type;
    s32 sel;
    S_006AE238_Obj *obj;

    func_L39_006AEF20((u8 *)this);
    func_L39_006AED18(this);
    if (cmd == 7 && this->f290 == 3) {
        func_L39_006AF070(this);
        return 1;
    }
    if (cmd == 5) {
        func_L39_00688340(0x17, 0, 0);
        func_L39_006AEF70(this, 0, 1, -1);
        return 1;
    }
    if (func_L39_0068AEF8(this, cmd)) {
        return 1;
    }
    func_L39_006AE3D8(this);
    obj = this->items[this->f290];
    obj->vtbl->f30(obj, &a, &b);
    first = -1;
    last = -1;
    for (i = 3; i < 4; i++) {
        if ((type = ((S_006AE238_Item *)this->items[i])->type) == 3 || type == 4 || type == 5) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    sel = this->f290 != first;
    if (this->f290 != last) {
        sel |= 2;
    }
    func_L39_00689F00(this, sel, 3, 3, D_001DD414_sda, b, D_001DD41C_sda - D_001DD444_sda, D_001DD474_sda, D_001DD478_sda, 1.0f);
    return 0;
}
/* localdecomp:end func_L39_006AE238 */
