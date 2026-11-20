#include "common.h"

/* localdecomp:start func_L39_006A4510 */
typedef struct W_006A4510 W_006A4510;
typedef struct V_006A4510 {
    u8 pad0[0x6C];
    void (*setItems)(W_006A4510 *, s32, char **);
    u8 pad70[0x18];
    void (*setSel)(W_006A4510 *, s32);
    s32 (*getSel)(W_006A4510 *);
    u8 pad90[0x28];
    void (*setText)(W_006A4510 *, char *);
} V_006A4510;
struct W_006A4510 {
    u8 pad0[0x60];
    V_006A4510 *vt;
};

typedef struct E_006A4510 {
    s32 pad0[8];
    u8 pad20[2];
    u8 f22;
    u8 pad23;
    s32 pad24[4];
} E_006A4510;

typedef struct R_006A4510 {
    char name[0x20];
    s32 f20;
    E_006A4510 e;
    u8 pad58[0x124 - 0x58];
} R_006A4510;

typedef struct Q_006A4510 {
    u8 f0;
    u8 pad1[0xC];
    u8 fD;
    u8 padE[6];
    u8 f14[1];
} Q_006A4510;

typedef struct G_006A4510 {
    u8 pad0[0x3C];
    void *f3C;
    u8 pad40[0x38];
    Q_006A4510 *f78;
} G_006A4510;

typedef struct S3_006A4510 {
    char *s[3];
} S3_006A4510;

typedef struct T_006A4510 {
    u8 pad0[0x144];
    W_006A4510 *f144;
    W_006A4510 *f148;
    W_006A4510 *f14C;
    W_006A4510 *f150;
    u8 pad154[0xC];
    u8 *f160;
    W_006A4510 *f164;
    u8 pad168[0x2A8 - 0x168];
    s32 f2A8;
    u8 pad2AC[0xC];
    u8 *f2B8;
    s32 f2BC;
    s32 f2C0;
    R_006A4510 *f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0[16];
    s32 f310;
    u8 pad314[4];
    u8 f318[8];
    s32 f320;
    s32 f324;
    s32 f328;
    s32 f32C;
    u8 f330;
    u8 f331;
    u8 pad332[2];
    s32 f334;
    s32 f338;
    u8 f33C;
    u8 f33D;
    u8 f33E;
    u8 f33F;
} T_006A4510;

__asm__(".extern D_L39_0024D760_006A4510, 16");
extern void *D_L39_0024D760_006A4510;
extern char D_L39_00248790[];
extern char D_L39_00248698[];
extern char D_L39_00248798[];
extern char D_L39_002487A8[];
extern char D_L39_002487B0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_00195410(void);
extern s32 func_00120884(void *);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_00381FF0(s32);
extern void *func_L39_006D4380(void *, s32);
extern void *func_L39_006D48C8(void *, s32, s32 *);
extern void *func_L39_006CC120(void *);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_006CC350(s32 *, s32);
void func_L39_006CC158(void *, s32);
struct S_006A55B0_net;
struct S_006A55B0_g;
extern s32 func_L39_006D7018(struct S_006A55B0_net *);
extern void func_L39_006D8B88(struct S_006A55B0_g *);
extern void func_L39_005958F8(u8 *, u8 *, s32);
u8 *func_L39_006A55B0(void);

void func_L39_006A4510(T_006A4510 *this, s32 force) {
    void *list;
    s32 total;
    s32 i;
    s32 id;
    s32 sel;
    s32 selIdx;
    W_006A4510 *w;

    if (!force) {
        s32 now = func_00130760(func_0012DCB0(), 0x24000);
        if (this->f2CC + 5000 >= now) {
            return;
        }
    }
    total = 0;
    this->f2CC = func_00130760(func_0012DCB0(), 0x24000);
    list = ((G_006A4510 *)D_L39_0024D760_006A4510)->f3C;
    this->f2B8 = func_L39_006D4380(list, this->f2A8);
    if (this->f2B8 != 0) {
      {
        char str[0x50];
        s32 buf[0x78];
        u8 *src;
        u8 *s;

        func_L39_006CC120(buf);
        func_L39_006CC4F8(buf, this->f2B8);
        if (func_L39_006CC350(buf, 12) == 0) {
            Q_006A4510 *q = ((G_006A4510 *)D_L39_0024D760_006A4510)->f78;
            void *l = q->fD ? q->f14 : 0;
            while (l == 0) {
                func_L39_006D7018((struct S_006A55B0_net *)q);
                while (q->f0) {
                    func_00195410();
                    if (D_L39_0024D760_006A4510 != 0) {
                        func_L39_006D8B88((struct S_006A55B0_g *)D_L39_0024D760_006A4510);
                    }
                }
                l = q->fD ? q->f14 : 0;
            }
        }
        this->f2C8 = func_L39_006CC350(buf, 16) + 0x27;
        this->f2B8[0x146] = 0;
        {
            u8 name[0x20];
            s32 j;

            {
                src = this->f2B8 + 0x134;
                func_L39_005958F8(name, src, func_00120884(src));
                for (j = 0x11; name[j] == ' '; j--) {
                }
                name[j + 1] = 0;
                this->f144->vt->setText(this->f144, (char *)name);
            }
        }
        switch (this->f2C8) {
        case 0x28:
            func_00120048(str, (char *)func_00381FF0(0xBB1));
            break;
        case 0x29:
            func_00120048(str, (char *)func_00381FF0(0xBB2));
            break;
        case 0x2A:
            func_00120048(str, (char *)func_00381FF0(0xDA));
            break;
        case 0x2B:
            func_00120048(str, (char *)func_00381FF0(0xBB4));
            break;
        case 0x2C:
            func_00120048(str, (char *)func_00381FF0(0xD8));
            break;
        case 0x2D:
            func_00120048(str, (char *)func_00381FF0(0xD4));
            break;
        case 0x2E:
            func_00120048(str, (char *)func_00381FF0(0x18C4));
            break;
        case 0x2F:
            func_00120048(str, (char *)func_00381FF0(0x18C5));
            break;
        case 0x30:
            func_00120048(str, (char *)func_00381FF0(0x18C6));
            break;
        case 0x31:
            func_00120048(str, (char *)func_00381FF0(0x18C7));
            break;
        default:
            func_00120048(str, D_L39_00248790);
            break;
        }
        this->f148->vt->setText(this->f148, str);
        s = ((u8 *(*)(T_006A4510 *, s32))func_L39_006A55B0)(this, func_L39_006CC350(buf, 2));
        if (s != 0) {
            this->f150->vt->setText(this->f150, (char *)s);
        } else {
            this->f150->vt->setText(this->f150, D_L39_00248698);
        }
        this->f330 = func_L39_006CC350(buf, 0x13) == 0;
        this->f331 = func_L39_006CC350(buf, 0x12) == 0;
        this->f324 = func_L39_006CC350(buf, 0xF) * 5;
        this->f328 = func_L39_006CC350(buf, 0x15) * 5;
        this->f32C = func_L39_006CC350(buf, 0x17);
        this->f334 = func_L39_006CC350(buf, 0x18);
        this->f33E = func_L39_006CC350(buf, 0x19) == 1;
        this->f33C = func_L39_006CC350(buf, 0x1A) == 1;
        this->f33D = func_L39_006CC350(buf, 0x1B) == 1;
        this->f33F = func_L39_006CC350(buf, 0x1C) == 1;
        this->f338 = func_L39_006CC350(buf, 0x14);
        {
            char *opts[3] = { (char *)func_00381FF0(0x1024), (char *)func_00381FF0(0x10E2), (char *)func_00381FF0(0x1026) };
            this->f320 = func_L39_006CC350(buf, 0x11);
            if (this->f338 != 0 && this->f320 == 2) {
                this->f14C->vt->setText(this->f14C, (char *)func_00381FF0(0x162A));
            } else {
                this->f14C->vt->setText(this->f14C, opts[this->f320]);
            }
        }
        this->f2C0 = func_L39_006CC350(buf, 1);
        this->f310 = func_L39_006CC350(buf, 3);
        if (this->f310 > 8) {
            this->f310 -= 8;
        }
        this->f318[0] = func_L39_006CC350(buf, 4) == 0;
        this->f318[1] = func_L39_006CC350(buf, 5) == 0;
        this->f318[2] = func_L39_006CC350(buf, 6) == 0;
        this->f318[3] = func_L39_006CC350(buf, 7) == 0;
        this->f318[4] = func_L39_006CC350(buf, 8) == 0;
        this->f318[5] = func_L39_006CC350(buf, 9) == 0;
        this->f318[6] = func_L39_006CC350(buf, 10) == 0;
        this->f318[7] = func_L39_006CC350(buf, 11) == 0;
        func_L39_006CC158(buf, 2);
      }
    }
    this->f2C4 = func_L39_006D48C8(list, this->f2A8, &this->f2BC);
    if (this->f2C4 != 0) {
        char names[8][15];
        char *ptrs[8];
        char **items;
        E_006A4510 e;

        if (this->f2BC > 8) {
            this->f2BC = 8;
        }
        items = ptrs;
        for (i = 7; i >= 0; i--) {
            items[i] = names[i];
        }
        w = this->f164;
        sel = -1;
        id = w->vt->getSel(w);
        if (id != -1) {
            sel = this->f2D0[id];
        }
        total = this->f2BC;
        selIdx = 0;
        for (i = 0; i < this->f2BC; i++) {
            e = this->f2C4[i].e;
            if (e.f22 != 0) {
                total++;
                func_00120048(names[i], D_L39_00248798, i + 1, this->f2C4[i].name);
            } else {
                func_00120048(names[i], D_L39_002487A8, i + 1, this->f2C4[i].name);
            }
            this->f2D0[i] = this->f2C4[i].f20;
            if (this->f2D0[i] == sel) {
                selIdx = i;
            }
        }
        this->f164->vt->setItems(this->f164, this->f2BC, items);
        this->f164->vt->setSel(this->f164, selIdx);
    }
    func_00120048((char *)(this->f160 + 0x14), D_L39_002487B0, func_00381FF0(0x1005), total, this->f2C0);
}
/* localdecomp:end func_L39_006A4510 */

/* localdecomp:start func_L39_006A4CB8 */
/* best: 13 diff with --mode S --as ps2as (190 with the file's default: default mode puts the
 * float literals in $gp, retail builds them with lui/ori, so this file likely wants S+ps2as).
 * Left: (1) retail keeps arg0+0x110 in $s3 from the prologue and starts loop 2 at $s3+0x34
 * (tried plain indexing, a sub-struct at 0x110: no change); (2) D_L39_00248730 (=0.37f,
 * lit.data) is loaded `lui $at; lwc1 ($at)` (a ps2as macro, unsplit) while ours splits via $v0;
 * (3) final 0x17 store uses $v0 not $v1. */
typedef struct VT_006A4CB8 {
    u8 pad0[0x1C];
    void (*fn1C)(void *, s32, s32);
    void (*fn20)(void);
    void (*fn24)(void *, s32);
    void (*fn28)(void *, f32, f32);
    void (*fn2C)(void *, f32, f32);
    u8 pad30[0x38 - 0x30];
    void (*fn38)(void *, f32, f32);
    u8 pad3C[0x40 - 0x3C];
    void (*fn40)(void *, s32);
    u8 pad44[0x4C - 0x44];
    void (*fn4C)(void *, s32, s32);
    u8 pad50[0x90 - 0x50];
    void (*fn90)(void *, f32);
    u8 pad94[0xE4 - 0x94];
    void (*fnE4)(void *, f32);
} VT_006A4CB8;
typedef struct Obj_006A4CB8 {
    u8 pad0[0x60];
    VT_006A4CB8 *vt;
} Obj_006A4CB8;
typedef struct S_006A4CB8 {
    u8 pad0[0x110];
    Obj_006A4CB8 *o[24];
    u8 pad170[0x314 - 0x170];
    s32 f314;
} S_006A4CB8;
extern const f32 D_L39_004B0430[];
extern f32 D_L39_00248728[] __attribute__((section(".sdata")));
extern s32 func_00381FF0(s32);
s32 func_L39_0068B2F8(void *, s32, s32);

void func_L39_006A4CB8(S_006A4CB8 *arg0) {
    s32 i;
    VT_006A4CB8 *vt;

    for (i = 0; i < 8; i++) {
        arg0->o[5 + i]->vt->fn1C(arg0->o[5 + i], 1, 0);
    }
    for (i = 0; i < 7; i++) {
        arg0->o[13 + i]->vt->fn4C(arg0->o[13 + i], 0x40, 1);
        arg0->o[13 + i]->vt->fn1C(arg0->o[13 + i], 1, 0);
        arg0->o[13 + i]->vt->fn40(arg0->o[13 + i], 1);
        arg0->o[13 + i]->vt->fn28(arg0->o[13 + i], D_L39_004B0430[0], i * D_L39_004B0430[5] + D_L39_004B0430[1]);
        arg0->o[13 + i]->vt->fn2C(arg0->o[13 + i], D_L39_004B0430[2], D_L39_004B0430[3]);
    }
    arg0->o[19]->vt->fn1C(arg0->o[19], 3, 0);
    arg0->o[19]->vt->fn28(arg0->o[19], 0.2925f, D_L39_004B0430[5] * 10.0f + D_L39_004B0430[1]);
    arg0->o[20]->vt->fn40(arg0->o[20], 1);
    arg0->o[20]->vt->fn1C(arg0->o[20], 3, 0);
    arg0->o[20]->vt->fn4C(arg0->o[20], 0x40, 1);
    arg0->o[20]->vt->fn28(arg0->o[20], 0.645f, 0.335f);
    arg0->o[20]->vt->fn38(arg0->o[20], 1.0f, 1.0f);
    arg0->o[21]->vt->fn40(arg0->o[21], 1);
    arg0->o[21]->vt->fn28(arg0->o[21], 0.69f, 0.86f);
    arg0->o[21]->vt->fn38(arg0->o[21], 0.335f, 1.0f);
    arg0->o[21]->vt->fn90(arg0->o[21], 0.0505f);
    arg0->o[21]->vt->fn1C(arg0->o[21], 2, 0);
    arg0->o[21]->vt->fn4C(arg0->o[21], 0x200, 1);
    arg0->o[21]->vt->fn4C(arg0->o[21], 0x800, 1);
    arg0->o[21]->vt->fnE4(arg0->o[21], D_L39_00248728[2]);
    arg0->o[22]->vt->fn28(arg0->o[22], 0.5225f, 0.795f);
    arg0->o[22]->vt->fn38(arg0->o[22], 1.0f, 1.0f);
    arg0->o[22]->vt->fn40(arg0->o[22], 1);
    arg0->o[22]->vt->fn1C(arg0->o[22], 3, 0);
    arg0->o[22]->vt->fn4C(arg0->o[22], 0x40, 1);
    arg0->o[23]->vt->fn28(arg0->o[23], 0.695f, 0.834f);
    arg0->o[23]->vt->fn38(arg0->o[23], 1.0f, 1.0f);
    arg0->o[23]->vt->fn1C(arg0->o[23], 3, 0);
    arg0->o[23]->vt->fn4C(arg0->o[23], 0x40, 1);
    arg0->o[23]->vt->fn40(arg0->o[23], 0);
    vt = arg0->o[23]->vt;
    vt->fn24(arg0->o[23], func_00381FF0(0xF8C));

    func_L39_0068B2F8(arg0, 0x17, 0);
    arg0->f314 = 0x17;
}
/* localdecomp:end func_L39_006A4CB8 */

/* localdecomp:start func_L39_006A50F8 */
typedef struct S_006A50F8_Obj S_006A50F8_Obj;
typedef struct S_006A50F8_VT {
    u8 pad00[0x1C];
    void (*setFlags)(S_006A50F8_Obj *, s32, s32);   /* 0x1C */
    u8 pad20[0x8];
    void (*setPos)(S_006A50F8_Obj *, f32, f32);     /* 0x28 */
    void (*setSize)(S_006A50F8_Obj *, f32, f32);    /* 0x2C */
    u8 pad30[0x8];
    void (*setScale)(S_006A50F8_Obj *, f32, f32);   /* 0x38 */
    u8 pad3C[0x4];
    void (*set40)(S_006A50F8_Obj *, s32);           /* 0x40 */
    u8 pad44[0xC];
    s32 (*setColor)(S_006A50F8_Obj *, u32);        /* 0x50 */
    u8 pad54[0x3C];
    void (*set90)(S_006A50F8_Obj *, f32);           /* 0x90 */
    u8 pad94[0x48];
    void (*setDC)(S_006A50F8_Obj *, s32);           /* 0xDC */
} S_006A50F8_VT;
struct S_006A50F8_Obj {
    u8 pad[0x60];
    S_006A50F8_VT *vt;
};
typedef struct S_006A50F8 {
    u8 pad000[0x110];
    S_006A50F8_Obj *o[24];          /* 0x110 */
    u8 pad170[0x2C8 - 0x170];
    s32 sel;                        /* 0x2C8 */
    u8 pad2CC[0x310 - 0x2CC];
    s32 count;                      /* 0x310 */
    u8 pad314[0x4];
    u8 on[8];                       /* 0x318 */
} S_006A50F8;
extern const f32 D_L39_004B0430[];

void func_L39_006A50F8(S_006A50F8 *self) {
    s32 i;
    f32 x;
    f32 y;

    self->o[0]->vt->setSize(self->o[0], 0.815f, 0.15f);
    self->o[0]->vt->setPos(self->o[0], 0.50025f, 0.2175f);
    if (self->sel != -1) {
        self->o[0]->vt->setDC(self->o[0], self->sel + 7);
    }
    x = 0.4625f;
    for (i = 0; i < 4; i++) {
        self->o[1 + i]->vt->setPos(self->o[1 + i], x, D_L39_004B0430[5] * 4.0f + D_L39_004B0430[1]);
        x -= 0.032f;
        self->o[1 + i]->vt->setSize(self->o[1 + i], 0.0275f, 0.035f);
        if (i >= self->count) {
            self->o[1 + i]->vt->setFlags(self->o[1 + i], 0, 0);
        } else {
            self->o[1 + i]->vt->setFlags(self->o[1 + i], 1, 0);
        }
    }
    x = 0.16f;
    y = 0.653f;
    for (i = 0; i < 8; i++) {
        self->o[5 + i]->vt->setPos(self->o[5 + i], x + (i % 4) * 0.09f, y + (i / 4) * 0.095f);
        self->o[5 + i]->vt->setSize(self->o[5 + i], 0.05f, 0.067f);
        self->o[5 + i]->vt->setColor(self->o[5 + i], self->on[i] ? 0x706EC8FF : 0x80404040);
    }
    for (i = 0; i < 7; i++) {
        self->o[13 + i]->vt->setPos(self->o[13 + i], D_L39_004B0430[0], i * D_L39_004B0430[5] + D_L39_004B0430[1]);
        self->o[13 + i]->vt->setSize(self->o[13 + i], D_L39_004B0430[2], D_L39_004B0430[3]);
    }
    self->o[19]->vt->setPos(self->o[19], 0.2925f, D_L39_004B0430[5] * 10.0f + D_L39_004B0430[1]);
    self->o[20]->vt->setPos(self->o[20], 0.645f, 0.335f);
    self->o[20]->vt->setScale(self->o[20], 1.0f, 1.0f);
    self->o[21]->vt->setPos(self->o[21], 0.69f, 0.86f);
    self->o[21]->vt->setScale(self->o[21], 0.335f, 1.0f);
    self->o[21]->vt->set90(self->o[21], 0.0505f);
    self->o[22]->vt->setPos(self->o[22], 0.5225f, 0.795f);
    self->o[22]->vt->setScale(self->o[22], 1.0f, 1.0f);
    self->o[22]->vt->set40(self->o[22], 1);
    self->o[23]->vt->setPos(self->o[23], 0.695f, 0.834f);
    self->o[23]->vt->setScale(self->o[23], 1.0f, 1.0f);
}
/* localdecomp:end func_L39_006A50F8 */

/* localdecomp:start func_L39_006A55B0 */
typedef struct S_006A55B0_item {
    char pad0[0x18];
    s32 f18;
    u8 f1C[4];
} S_006A55B0_item;

typedef struct S_006A55B0_list {
    s32 f0;
    s32 f4;
    S_006A55B0_item **f8;
} S_006A55B0_list;

typedef struct S_006A55B0_net {
    u8 f0;
    char pad1[0xC];
    u8 fD;
    char padE[6];
    S_006A55B0_list f14;
} S_006A55B0_net;

typedef struct S_006A55B0_g {
    char pad0[0x4C];
    void *f4C;
    char pad50[0x28];
    S_006A55B0_net *f78;
} S_006A55B0_g;

extern S_006A55B0_g *D_L39_0024D760;
extern u8 D_L39_00248640[];
extern u8 D_L39_00248648[];
extern u8 *func_L39_006DB750(void *);
extern s32 func_001200E0(void *, void *, ...);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_L39_006D7018(S_006A55B0_net *);
extern void func_00195410(void);
extern void func_L39_006D8B88(S_006A55B0_g *);

u8 *func_L39_006A55B0(void)
{
    s32 x;
    s32 y;
    S_006A55B0_net *net;
    S_006A55B0_list *list;
    u8 *r;
    u8 *name;
    s32 id;
    s32 start;
    s32 i;
    u8 c;
    s32 *px;
    s32 *py;

    net = D_L39_0024D760->f78;
    list = net->fD ? &net->f14 : 0;
    r = func_L39_006DB750(D_L39_0024D760->f4C);
    if (r == 0) {
        return 0;
    }
    name = r + 0x1C;
    px = &x;
    py = &y;
    if (name[0] == 'C') {
        c = name[1];
        if (c == 'Y' || c == 'R') {
            func_001200E0(r + 0x1E, D_L39_00248640, px, py);
        } else if (c == 'C') {
            func_001200E0(r + 0x1E, D_L39_00248648, px);
        }
    } else if (name[0] == 'H') {
        func_001200E0(r + 0x1E, D_L39_00248640, px, py);
    }
    id = x + 0x28;
    start = func_00130760(func_0012DCB0(), 0x24000);
    while (list == 0) {
        func_L39_006D7018(net);
        c = net->f0;
        if (c) {
            do {
                func_00195410();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                    return 0;
                }
                if (D_L39_0024D760 != 0) {
                    func_L39_006D8B88(D_L39_0024D760);
                }
            } while (net->f0);
        }
        list = net->fD ? &net->f14 : 0;
    }
    for (i = 0; i < list->f4; i++) {
        if (list->f8[i]->f18 == id) {
            return list->f8[i]->f1C;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006A55B0 */

LINKER_REMNANT("asm/levels", func_L39_006A57A0);

/* localdecomp:start func_L39_006A57B0 */
typedef struct H_006A57B0 {
    s32 type;
    char name[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006A57B0;
typedef struct I50_006A57B0 {
    H_006A57B0 h;
    s32 f48;
    s32 f4C;
} I50_006A57B0;
typedef struct M_006A57B0 {
    H_006A57B0 h;
    s32 f48;
    s32 f4C;
    void *items[0x60];
} M_006A57B0;
typedef struct E_006A57B0 {
    char pad[0x20];
} E_006A57B0;
typedef struct P_006A57B0 {
    E_006A57B0 elems[64];
    E_006A57B0 *ptrs[64];
    u8 pad[0x10C];
} P_006A57B0;
typedef struct S_006A57B0 {
    char pad0[0x60];
    u8 *f60;
    char pad64[0x240];
    u8 *f2A4;
    char pad2A8[0x114];
    P_006A57B0 f3BC;
    P_006A57B0 fDC8;
} S_006A57B0;

extern u8 D_L39_0047D978[];
void *func_L39_00688388(void *);
void func_L39_00689670(void *, void *);
void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern s32 func_00381FF0(s32);

static __inline__ void *item_006A57B0(void *it, s32 name, f32 x, f32 y, f32 w, f32 h) {
    ((H_006A57B0 *)it)->type = 0;
    func_L39_0068CD28((u8 *)it, name, x, y, w, h);
    return it;
}

void *func_L39_006A57B0(S_006A57B0 *arg0) {
    I50_006A57B0 it0;
    I50_006A57B0 it1;
    I50_006A57B0 it2;
    I50_006A57B0 it3;
    I50_006A57B0 it4;
    M_006A57B0 menu;
    I50_006A57B0 *p0, *p1, *p2, *p3, *p4;
    M_006A57B0 *pm;
    s32 name;
    s32 i;

    func_L39_00688388(arg0);
    arg0->f60 = D_L39_0047D978;
    arg0->f2A4 = (u8 *)arg0 + 0x1728;

    name = func_00381FF0(0xFC1);
    p0 = &it0;
    item_006A57B0(p0, name, 0.502f, 0.3878f, 0.435f, 0.05f);
    it0.h.type = 1;
    name = func_00381FF0(0xFCD);
    p1 = &it1;
    item_006A57B0(p1, name, 0.502f, 0.4464f, 0.435f, 0.05f);
    it1.h.type = 1;
    name = func_00381FF0(0x10ED);
    p2 = &it2;
    item_006A57B0(p2, name, 0.502f, 0.505f, 0.435f, 0.05f);
    it2.h.type = 1;
    name = func_00381FF0(0xFD0);
    p3 = &it3;
    item_006A57B0(p3, name, 0.502f, 0.5636f, 0.435f, 0.05f);
    it3.h.type = 1;
    name = func_00381FF0(0x1030);
    p4 = &it4;
    item_006A57B0(p4, name, 0.502f, 0.6222f, 0.435f, 0.05f);
    it4.h.type = 1;

    pm = &menu;
    item_006A57B0(pm, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    pm->f48 = 0x2E;
    menu.f4C = 0;
    menu.h.x = 0;
    menu.h.y = 0;
    pm->h.w = 1.0f;
    pm->h.h = 1.0f;
    menu.f4C = 5;
    menu.items[1] = p1;
    menu.items[2] = p2;
    menu.items[3] = p3;
    menu.items[4] = p4;
    menu.items[0] = p0;
    func_L39_00689670(arg0, pm);

    for (i = 63; i >= 0; i--) {
        arg0->fDC8.ptrs[i] = &arg0->fDC8.elems[i];
    }
    for (i = 63; i >= 0; i--) {
        arg0->f3BC.ptrs[i] = &arg0->f3BC.elems[i];
    }
    return arg0;
}
/* localdecomp:end func_L39_006A57B0 */

LINKER_REMNANT("asm/levels", func_L39_006A5A70);
