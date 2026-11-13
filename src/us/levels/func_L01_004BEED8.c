#include "common.h"

/* NTSC-U counterpart of func_L01_004C2A80 (src/levels/shared/L01_004C21D0.c) */
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[15];
} E_004BF8A0;
typedef struct {
    u8 pad0[92];
    s32 w92;
    u8 pad96[32];
    s32 w128;
    s32 w132;
    u8 pad136[184];
    E_004BF8A0 e[1];
} G_004BF8A0;
typedef struct {
    u8 pad0[132];
    u16 h132;
    u16 h134;
    u8 pad136[104];
} M_004BF8A0;

/* localdecomp:start func_L01_004BEED8 */
typedef struct {
    u8 p0;
    u8 level;         /* 0x01 */
    u8 p2[2];
    s32 name;         /* 0x04 */
    u8 p8[0x30];
    u16 icon;         /* 0x38 */
    u8 p3A[4];
    s16 desc;         /* 0x3E */
    u8 p40[0x44];
    u16 round_price;  /* 0x84 */
    u16 h86;
    u8 p88[2];
    u16 max_ammo;     /* 0x8A */
    u8 p8C[0x48];
    s16 hD4;          /* 0xD4 */
    s16 hD6;          /* 0xD6 */
    u8 pD8[0x18];
} Row_4C2A80;
typedef struct {
    s32 id;
    u8 kind;          /* 0x04: 1 = rounds row */
    u8 p5[12];
    u8 x11;
    u8 buy_all;       /* 0x12 */
    u8 x13;
} Entry_4C2A80;
typedef struct {
    u8 p0[4];
    s32 timer;        /* 0x04 */
    u8 p8[0x48];
    s32 w50;          /* 0x50 */
    u8 p54[8];
    s32 w5C;          /* 0x5C */
    u8 p60[0x20];
    s32 sel;          /* 0x80 */
    u8 p84[0xBC];
    Entry_4C2A80 e[77]; /* 0x140 */
    s32 w744;         /* 0x744 */
    u8 p748[0xC];
    s32 total;        /* 0x754 */
} Vendor_4C2A80;
typedef struct {
    s32 type;
    u8 p4[8];
    s32 val;
    u8 p10[0x90];
} PadE_4C2A80;
typedef struct {
    u8 p0[8];
    PadE_4C2A80 pad[2];
    u8 p148[0x14];
    s32 w15C;
    u8 p160[4];
    s32 w164;
} Pads_4C2A80;

typedef struct {
    u8 p0[4];
    s16 h4;
    u8 p6[0x1A];
} Cam_4C2A80;

__asm__(".extern D_L01_001DAE50, 4");
extern G_004BF8A0 D_L01_00244740;
extern M_004BF8A0 D_L01_002C5640[];
extern u8 D_001425C0[];
extern s32 D_00142660[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern u8 D_00143950[];
extern Pads_4C2A80 D_00142430;
extern Cam_4C2A80 D_001CCFD0;
extern s32 D_001D545C;
extern s32 D_L01_001DAE50;
extern s32 D_L01_001E0FFC;
extern s32 D_L01_001E1000;
extern s32 D_L01_001E0FF8;
extern u8 D_L01_001E10D0_004BEED8;
extern u8 D_L01_001E10B8[8];
extern u8 D_L01_001E1070_004BEED8[8];
extern char D_L01_0024DED0_004BEED8[];
extern char D_L01_001DADE8[];
extern char D_L01_001E0580[];
extern u8 D_L01_002F1D58[];
extern s32 func_L01_00417810(Row_4C2A80 *, s32, s32);
extern void func_L01_004BDC90(void);
extern void func_L01_004BB0F0_004BEED8(char *, s32);
extern s32 func_L01_005131A0(s32, s32);
extern void func_L01_004BD8B8(s32);
extern void func_L01_005130C8_004BEED8(s32, s32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern void func_L01_00512828(s32, f32);
extern void func_L01_00513548(s32, f32, f32);
extern char *func_0037DF98(s32);
extern void func_0011B754(char *, char *);
extern void func_0011B2E8(char *, char *, char *, s32);
extern void func_L01_00512FE8(s32, char *);
extern s32 func_L01_004B6C98(void);
extern void func_L01_00512D70(s32, s32);
extern s32 func_003E29B8(s32, s32);
extern void func_L01_004BD430(u8 *, s32, u32);
extern void func_L01_004BEB70(s32);

void func_L01_004BEED8(void)
{
    Row_4C2A80 row;
    s32 can_afford;
    s32 available;
    Entry_4C2A80 *e;
    Vendor_4C2A80 *v;
    Vendor_4C2A80 *vt;
    Vendor_4C2A80 *vs;
    s32 id;
    s32 sel;
    s32 i;
    s32 a;
    s32 b;
    u32 color;

    can_afford = 1;
    available = 1;
    e = &((Vendor_4C2A80 *)&D_L01_00244740)->e[((Vendor_4C2A80 *)&D_L01_00244740)->sel];
    id = e->id;
    func_L01_00417810(&row, id, ((Row_4C2A80 *)D_L01_002C5640)[D_001425C0[id]].level);
    if (e->x11) {
        func_L01_00417810(&row, e->id, 5);
    }
    /* these callees return a value; the file's void prototypes would change the register allocation */
    ((s32 (*)(void))func_L01_004BDC90)();
    func_L01_004BB0F0_004BEED8((char *)D_L01_001E10B8, D_00142660[0]);
    if (e->buy_all) {
        func_L01_005131A0(0x48001F, 0xED41);
    } else if (e->x13) {
        func_L01_005131A0(0x48001F, 0x755D);
    } else {
        func_L01_005131A0(0x48001F, row.icon);
    }
    vt = (Vendor_4C2A80 *)&D_L01_00244740;
    if (vt->timer < 15) {
        D_L01_001E0FFC = vt->timer;
        func_L01_004BD8B8(0);
        if (vt->timer >= 2) {
            return;
        }
    } else {
        D_L01_001E1000 = 0;
        func_L01_005130C8_004BEED8(0x480026, 0x8066CCFF);
        func_L01_00512AB0(0x480026, 1, 1);
        func_L01_00512AB0(0x48002B, 1, 1);
        func_L01_00512AB0(0x48002A, 1, 1);
        func_L01_00512AB0(0x480029, 1, 1);
    }
    v = (Vendor_4C2A80 *)&D_L01_00244740;
    sel = v->sel;
    if (D_L01_001DAE50 != sel) {
        D_L01_001E10D0_004BEED8 = 1;
        D_L01_001DAE50 = sel;
        D_L01_001E0FF8 = 120;
    }
    if (D_00143950[0xB7] >= 2) {
        func_L01_00512828(0x480026, 0.7f);
    }
    func_L01_00513548(0x480023, 1.1f, 1.1f);
    if (e->buy_all == 1) {
        v->total = 0;
        for (i = 0; i < 156; i++) {
            if (D_00142CA0[i] != 0) {
                Row_4C2A80 *m = &((Row_4C2A80 *)D_L01_002C5640)[D_001425C0[i]];
                if (m->round_price != 0) {
                    s32 max = m->max_ammo;
                    s32 ammo = D_001427F0[i];
                    if (ammo < max) {
                        if (((Vendor_4C2A80 *)&D_L01_00244740)->w5C != 0) {
                            if (i == 16 || i == 17 || i == 19 || i == 21 || i == 22) {
                                continue;
                            }
                        }
                        ((Vendor_4C2A80 *)&D_L01_00244740)->total += m->round_price * (max - ammo);
                    }
                }
            }
        }
        func_0011B754(D_L01_0024DED0_004BEED8, func_0037DF98(0xBF0));
        if (D_00143950[0xB7] >= 2) {
            func_L01_00513548(0x480023, 0.8f, 0.8f);
        }
        vs = (Vendor_4C2A80 *)&D_L01_00244740;
        func_L01_00512FE8(0x480026, func_0037DF98(0x135A));
        func_L01_00512FE8(0x480027, 0);
        func_L01_004BB0F0_004BEED8((char *)D_L01_001E1070_004BEED8, vs->total);
        if (D_00142660[0] < vs->total) {
            can_afford = 0;
        }
        if (vs->total == 0) {
            available = 0;
            D_L01_001E0FF8 = 120;
        }
        if (D_001CCFD0.h4 == 0) {
            func_L01_005131A0(0x48001E, 0x29);
        }
    } else if (e->x13 == 1) {
        if (v->w744 != 0) {
            ((s32 (*)(s32, char *))func_L01_00512FE8)(0x480026, func_0037DF98(0x18CF));
            if (D_001CCFD0.h4 == 0) {
                func_L01_005131A0(0x48001E, 0x2E);
            }
            func_0011B754(D_L01_0024DED0_004BEED8, func_0037DF98(0x1808));
        } else {
            ((s32 (*)(s32, char *))func_L01_00512FE8)(0x480026, func_0037DF98(0x17FA));
            if (D_001CCFD0.h4 == 0) {
                func_L01_005131A0(0x48001E, 0x2D);
            }
            func_0011B754(D_L01_0024DED0_004BEED8, func_0037DF98(0x1807));
        }
        available = 0;
    } else if (e->kind == 1) {
        if (D_001427F0[id] >= row.max_ammo) {
            available = 0;
        }
        ((s32 (*)(char *, char *, char *, s32))func_0011B2E8)(D_L01_0024DED0_004BEED8, D_L01_001DADE8, func_0037DF98(row.name), (s32)func_0037DF98(0x178));
        func_L01_00512FE8(0x480026, func_0037DF98(row.desc));
        func_L01_00512FE8(0x480027, D_L01_001E0580);
        func_L01_004BB0F0_004BEED8((char *)D_L01_001E1070_004BEED8, ((Row_4C2A80 *)D_L01_002C5640)[D_001425C0[v->e[v->sel].id]].round_price);
        if (D_00142660[0] < ((Row_4C2A80 *)D_L01_002C5640)[D_001425C0[v->e[v->sel].id]].round_price) {
            can_afford = 0;
        }
        if (id != 0 && D_001CCFD0.h4 == 0) {
            func_L01_005131A0(0x48001E, row.hD6 + 1);
        }
    } else {
        func_0011B754(D_L01_0024DED0_004BEED8, func_0037DF98(row.name));
        func_L01_00512FE8(0x480026, func_0037DF98(row.desc));
        func_L01_004BB0F0_004BEED8((char *)D_L01_001E1070_004BEED8, func_L01_004B6C98());
        if (D_00142660[0] < func_L01_004B6C98()) {
            can_afford = 0;
        }
        if (id != 0 && D_001CCFD0.h4 == 0) {
            func_L01_005131A0(0x48001E, row.hD4 + 1);
        }
        func_L01_00512FE8(0x480027, 0);
        D_L01_001E0FF8 = 0;
    }
    func_L01_00512AB0(0x480024, 1, available);
    func_L01_00512AB0(0x480021, 1, available);
    func_L01_00512AB0(0x480025, 1, available);
    func_L01_00512AB0(0x48002B, 1, (u8)(available ^ 1));
    if (e->x13) {
        a = 0;
        if (D_00142430.w15C < 3 && D_00142430.w164 < 0 && D_00142430.pad[0].type == 2) {
            a = D_00142430.pad[0].val != 0;
        }
        b = 0;
        if (D_00142430.w15C < 3 && D_00142430.w164 < 0 && D_00142430.pad[1].type == 2) {
            b = D_00142430.pad[1].val != 0;
        }
        func_L01_00512D70(0x48002B, a | b);
        func_003E29B8(0x48002B, 1);
        func_L01_00512FE8(0x48002B, func_0037DF98(0x17FB));
    } else {
        func_L01_00512FE8(0x48002B, func_0037DF98(0x8CD));
        func_003E29B8(0x48002B, 1);
    }
    if (D_00143950[0xB7] == 3) {
        func_L01_00513548(0x48002B, 0.75f, 0.9f);
    }
    if (D_001D545C == 3 && ((Vendor_4C2A80 *)&D_L01_00244740)->w5C == 0 && ((Vendor_4C2A80 *)&D_L01_00244740)->e[((Vendor_4C2A80 *)&D_L01_00244740)->sel].buy_all == 0 && ((Vendor_4C2A80 *)&D_L01_00244740)->e[((Vendor_4C2A80 *)&D_L01_00244740)->sel].x13 == 0
        && ((Vendor_4C2A80 *)&D_L01_00244740)->e[((Vendor_4C2A80 *)&D_L01_00244740)->sel].id != 0x67 && ((Vendor_4C2A80 *)&D_L01_00244740)->e[((Vendor_4C2A80 *)&D_L01_00244740)->sel].id != 0x16 && ((Vendor_4C2A80 *)&D_L01_00244740)->w50 == 0) {
        if (D_L01_001E1000 == 0) {
            func_L01_00512AB0(0x48002C, 1, 1);
        }
        func_L01_00512AB0(0x480016, 1, 1);
    } else {
        func_L01_00512AB0(0x48002C, 1, 0);
        func_L01_00512AB0(0x480016, 1, 0);
    }
    if (available == 0 || can_afford == 0) {
        func_L01_00512AB0(0x480029, 1, 0);
    } else {
        func_L01_00512AB0(0x480029, 1, 1);
    }
    color = 0x80707070;
    if (can_afford) {
        color = 0x8066CCFF;
    }
    func_L01_004BD430(D_L01_002F1D58, 0x480021, color);
    func_L01_004BD430(D_L01_002F1D58, 0x480025, color);
    func_L01_004BEB70(available);
}
/* localdecomp:end func_L01_004BEED8 */
