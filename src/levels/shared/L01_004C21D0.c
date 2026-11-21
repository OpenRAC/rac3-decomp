#include "common.h"

typedef struct VObj_4BEB00 VObj_4BEB00;
typedef struct { u8 p0[12]; void (*f)(VObj_4BEB00 *); } VT_4BEB00;
struct VObj_4BEB00 { s32 p0; VT_4BEB00 *vt; };
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
typedef struct {
    u8 p0[4];
    s32 val;
    s32 idx;
    u8 pC[4];
} E_4BFEA0;
typedef struct {
    u8 p0[4];
    s32 w4;
    u8 p8[0x78];
    s32 sel;
    u8 p84[0xBC];
    E_4BFEA0 ent[1];
} G_4BFEA0;
typedef struct {
    s32 w0;
    u8 p4[0x74];
    s32 w78;
} H_4BFEA0;
typedef struct {
    s32 a[5];
} T_4BFEA0;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_4C01C8;
typedef struct { u8 p0[0x80]; s32 f80; s32 f84; u8 p88[0xBC]; E_4C01C8 e[1]; } S_4C01C8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6A38 - 0x4958];
    u8 fX[1];
} S_func_004C07D8;
typedef struct {
    u8 p0[0x20];
    s32 w32;
} E_4C0BF8;
typedef struct {
    u8 p0[0x80];
    s32 idx;
    s32 active;
    u8 p88[0x9C];
    E_4C0BF8 e[1];
} B_4C0BF8;
typedef struct {
    s32 w0;
    s32 w4;
    u8 p8[8];
} T_4C1638;
typedef struct {
    u8 p0[4];
    s32 val;
    u8 p8[4];
    s32 idx;
} E_4C1638;
typedef struct {
    u8 p0[4];
    s32 w4;
    u8 p8[0x78];
    s32 sel;
    u8 p84[0xBC];
    E_4C1638 ent[1];
} G_4C1638;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_4C1988;
typedef struct { u8 p0[0x80]; s32 f80; s32 f84; u8 p88[0xBC]; E_4C1988 e[1]; } S_4C1988;

/* localdecomp:start func_L01_004C21D0 */
typedef struct {
    s32 mode;
    u8 pad4[0x34];
    s32 state;
    u8 pad3C[0x740];
    s32 active;
} Vendor_004C21D0;
typedef struct {
    s32 type;
    u8 p4[8];
    s32 val;
    u8 p10[0x90];
} PadE_004C21D0;
typedef struct {
    u8 p0[8];
    PadE_004C21D0 pad[2];
    u8 p148[0x14];
    s32 w15C;
    u8 p160[4];
    s32 w164;
    s32 w168;
} Pads_004C21D0;
extern G_004BF8A0 D_L01_002446C0;
extern Pads_004C21D0 D_00142430_004C21D0;
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern u32 D_L01_001E0F60;
extern s32 func_L01_004C1E78(void);
extern s32 func_L01_004C1D38(s32);
extern s32 func_L01_004BF660(void);
extern void func_L01_004BB140(void);
extern void func_L01_004BAA20(s32);
extern s32 func_0039EF28(void);
extern s32 func_L01_004BB0F0(s32);
extern void func_L01_004BB120_004C21D0(u32);

void func_L01_004C21D0(void) {
    switch (((Vendor_004C21D0 *)&D_L01_002446C0)->state) {
    case 0:
    case 1: {
        Pads_004C21D0 *p;
        if (((Vendor_004C21D0 *)&D_L01_002446C0)->active) { ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 6; break; }
        p = &D_00142430_004C21D0;
        if (p->w15C < 3 && p->w164 < 0 && p->pad[0].type == 2 && p->pad[0].val && func_L01_004C1E78()) {
            if (p->w164 < 0) {
                p->w168 = 0;
                p->w164 = 24;
            }
            func_L01_004C1D38(0x17F4);
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = ((Vendor_004C21D0 *)&D_L01_002446C0)->state == 1 ? 3 : 2;
        } else {
            if (((Vendor_004C21D0 *)&D_L01_002446C0)->state == 1) func_L01_004C1D38(0x5C5);
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 6;
        }
        break;
    }
    case 2:
    case 3: {
        Vendor_004C21D0 *v;
        Pads_004C21D0 *p = &D_00142430_004C21D0;
        if (p->w15C >= 3 || p->w164 >= 0 || !func_L01_004C1E78()) return;
        if (func_L01_004BF660()) {
            if (((Vendor_004C21D0 *)&D_L01_002446C0)->mode == 5) func_L01_004BB140();
            else func_L01_004BAA20(0);
        }
        v = (Vendor_004C21D0 *)&D_L01_002446C0;
        if (v->state == 3) {
            if (!(D_00142660[18] & 0x40)) {
                func_L01_004C1D38(0x5C5);
                goto state_six;
            }
            if (v->active == 0) {
                func_L01_004C1D38(0x17F8);
                v->state = 7;
            } else {
                func_L01_004C1D38(0x17F7);
                v->state = 7;
            }
        } else {
            if (!v->active || D_001426E0[0xE2]) {
                goto state_six;
            } else if (func_L01_004C1D38(0x17F7)) {
                D_001426E0[0xE2] |= 1;
                func_0039EF28();
                v->state = 7;
            } else {
                goto state_six;
            }
        }
        break;
    }
    case 4: {
        Pads_004C21D0 *p = &D_00142430_004C21D0;
        if (p->w15C >= 3 || p->w164 >= 0) return;
        if (p->pad[1].type == 2 && p->pad[1].val) {
            p->w164 = 24;
            p->w168 = 1;
            func_L01_004C1D38(0x1B90);
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 5;
        } else {
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 1;
        }
        break;
    }
    case 5: {
        Pads_004C21D0 *p = &D_00142430_004C21D0;
        Vendor_004C21D0 *v;
        if (p->w15C >= 3 || p->w164 >= 0 || !func_L01_004C1E78()) return;
        if (func_L01_004BF660()) func_L01_004BAA20(0);
        if (!(D_00142660[18] & 0x40)) {
            ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 1;
            break;
        }
        v = (Vendor_004C21D0 *)&D_L01_002446C0;
        if (v->active) {
            func_L01_004C1D38(0x17F7);
            v->state = 7;
        }
        break;
    }
    case 6: break;
    case 7:
        if (func_L01_004BB0F0(5)) goto state_six;
        else if (D_L01_001E0F60 < 2 && func_L01_004C1D38(0x17F9)) {
            func_L01_004BB120_004C21D0(5);
            goto state_six;
        }
        break;
    }
    return;
state_six:
    ((Vendor_004C21D0 *)&D_L01_002446C0)->state = 6;
}
/* localdecomp:end func_L01_004C21D0 */

/* localdecomp:start func_L01_004C2548 */
extern u8 D_L01_002F1D18[];
extern S_func_004C07D8 D_00160C40[];
extern u8 D_L01_00244E50[];
extern s32 D_L01_001E15E0[];
extern s32 D_L01_001DC1B0;
typedef struct Obj_004C2548 Obj_004C2548;
typedef struct { u8 pad[16]; s32 (*test)(Obj_004C2548 *, s32); } Vt_004C2548;
struct Obj_004C2548 { u8 pad[8]; Vt_004C2548 *vt; u8 padC[0x44]; VObj_4BEB00 *object; };
static __inline__ s32 *root_004C2548(void) {
    extern s32 *func_003E6C08(void);
    if (D_L01_001E15E0[1] == 0) return func_003E6C08();
    return D_L01_001E15E0;
}
static __inline__ Obj_004C2548 *test_004C2548(Obj_004C2548 *p) {
    if (p && p->vt->test(p, D_L01_001DC1B0)) return p;
    return 0;
}
void func_L01_004C2548(void) {
    extern void func_L01_00516468_004C2548(s32);
    extern s32 func_L01_0047B3D8(void);
    extern s32 func_L01_00479248(void);
    extern s32 func_L01_0047B948(void);
    extern void func_L01_004C1028(void *);
    extern VObj_4BEB00 *func_003B42F8(s32);
    extern s32 func_003B4528(void *, s32, s32, s32, s32);
    extern s32 *func_003E6C08(void);
    extern void *func_003E6DE8(s32 *);
    extern Obj_004C2548 *func_003E6378(void *, s32);
    extern s32 func_L01_00516AA0(s32, s32, s32);
    extern s32 func_003E8348(s32, s32);
    extern void func_L01_004C13B0(s32, u8 *);
    extern void func_L01_004C17E8(s32, s32, s32, s32, s32, s32, f32);
    s32 *root;
    Obj_004C2548 *object;
    func_L01_00516468_004C2548(1);
    func_L01_0047B3D8();
    func_L01_00479248();
    func_L01_0047B948();
    func_L01_004C1028(D_L01_002F1D18);
    func_003B4528(func_003B42F8(0), (s32)D_L01_00244E50, 0, D_00160C40[0].f4954, (s32)D_00160C40[0].fX);
    root = root_004C2548();
    object = func_003E6378(func_003E6DE8(root), 0x48001E);
    object = test_004C2548(object);
    object->object = func_003B42F8(0);
    func_L01_00516AA0(0x48001E, 0x8000, 1);
    func_003E8348(27, 0x480000);
    func_L01_004C13B0(0, D_L01_002F1D18);
    func_L01_004C17E8(0x480033, 0x480034, 0x480035, 0x480036, 0x480037, 0x480032, 0.03f);
    func_L01_00516468_004C2548(0);
}
/* localdecomp:end func_L01_004C2548 */

/* localdecomp:start func_L01_004C26A8 */
extern s32 func_003B9BD0(s32);
extern void func_003B9E90(s32);
extern void func_L01_00517918(s32);
extern VObj_4BEB00 *func_003B42F8(s32);
extern void func_003A2750(s32);
void func_L01_004C26A8(void) {
    VObj_4BEB00 *o;
    func_003B9E90(func_003B9BD0(0));
    func_L01_00517918(27);
    o = func_003B42F8(0);
    o->vt->f(o);
    o = func_003B42F8(1);
    o->vt->f(o);
    func_003A2750(1);
}
/* localdecomp:end func_L01_004C26A8 */

/* localdecomp:start func_L01_004C2718 */
typedef struct { s32 id; u8 pad4[14]; u8 all; u8 pad13; } Entry_004C2718;
typedef struct { u8 pad0[0x5C]; s32 mode; u8 pad60[0x20]; s32 selected; u8 pad84[0xBC]; Entry_004C2718 entries[77]; u8 pad744[0x10]; s32 total; } Vendor_004C2718;
typedef struct { u8 pad0[0x84]; u16 price; u16 unit; u8 pad88[2]; u16 max; u8 pad8C[0x64]; } Row_004C2718;
extern G_004BF8A0 D_L01_002446C0;
extern M_004BF8A0 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 D_00142660[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern char D_L01_001E1020[8];
void func_L01_004C2718(s32 show) {
    extern void func_L01_00516D60(s32,s32);
    extern void func_L01_004BEC88(char *,s32);
    extern void func_L01_00516EC8(s32,f32 *,f32 *,f32 *,f32 *);
    extern void func_L01_00516470(s32,f32,f32);
    extern void func_L01_00517538(s32,f32,f32);
    extern s32 func_L01_005170B8(s32,u32);
    f32 x,y,z;
    Vendor_004C2718 *v=(Vendor_004C2718 *)&D_L01_002446C0;
    Entry_004C2718 *entries=v->entries;
    Entry_004C2718 *entry=&entries[v->selected];
    Row_004C2718 *row;
    s32 visible=0;
    u32 enabled=1;
    s32 i;
    s32 color;
    if(v->mode) visible=show;
    func_L01_00516D60(0x48002E,visible);
    func_L01_00516D60(0x480030,visible);
    func_L01_00516D60(0x48002F,visible);
    if(!visible) return;
    if(entry->all==1) {
        ((Vendor_004C2718 *)&D_L01_002446C0)->total=0;
        for(i=0;i<156;i++) {
            if(D_00142CA0[i]) {
                row=(Row_004C2718 *)&D_L01_002C5600[D_001425C0[i]];
                if(row->price!=0 && D_001427F0[i]<row->max) {
                    if(((Vendor_004C2718 *)&D_L01_002446C0)->mode && (i==16 || i==17 || i==19 || i==21 || i==22)) continue;
                    ((Vendor_004C2718 *)&D_L01_002446C0)->total+=row->unit*(row->max-D_001427F0[i]);
                }
            }
        }
        func_L01_004BEC88(D_L01_001E1020,((Vendor_004C2718 *)&D_L01_002446C0)->total);
        if(D_00142660[0]<((Vendor_004C2718 *)&D_L01_002446C0)->total) enabled=0;
    } else {
        row=(Row_004C2718 *)&D_L01_002C5600[D_001425C0[entries[((Vendor_004C2718 *)&D_L01_002446C0)->selected].id]];
        enabled=D_00142660[0]>row->unit;
        func_L01_004BEC88(D_L01_001E1020,row->unit);
    }
    func_L01_00516EC8(0x480025,&x,&y,&z,&y);
    color=0x80707070;
    func_L01_00516470(0x48002E,z+0.05f,0.565f);
    func_L01_00516470(0x48002F,x-0.03f,0.566f);
    func_L01_00517538(0x48002F,z-x+0.04f,0.006f);
    func_L01_00516EC8(0x48002E,&x,&y,&y,&y);
    func_L01_00516470(0x480030,x-0.015f,0.565f);
    func_L01_005170B8(0x480021,0x80707070);
    func_L01_005170B8(0x480025,0x80707070);
    if(enabled) color=0x8066CCFF;
    func_L01_005170B8(0x480030,color);
    func_L01_005170B8(0x48002E,color);
}
/* localdecomp:end func_L01_004C2718 */

/* localdecomp:start func_L01_004C2A80 */
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

__asm__(".extern D_L01_001DAE10, 4");
extern G_004BF8A0 D_L01_002446C0;
extern M_004BF8A0 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 D_00142660[];
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern u8 D_00143950[];
extern Pads_4C2A80 D_00142430;
extern s16 D_001CCFD4[];
extern Cam_4C2A80 D_001CCFD0;
extern s32 D_001D545C;
extern s32 D_L01_001DAE10;
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;
extern s32 D_L01_001E0F78;
extern u8 D_L01_001E1050;
extern u8 D_L01_001E1038[8];
extern u8 D_L01_001E0FF0[8];
extern char D_L01_0024DE50[];
extern char D_L01_001DADA8[];
extern char D_L01_001E0500[];
extern u8 D_L01_002F1D18[];
extern s32 func_L01_00419E60(Row_4C2A80 *, s32, s32);
extern void func_L01_004C1838(void);
extern void func_L01_004BEC88(char *, s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_L01_004C1460(s32);
extern void func_L01_005170B8_004C2A80(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern char *func_00381FF0(s32);
extern void func_0011B754(char *, char *);
extern void func_0011B2E8(char *, char *, char *, s32);
extern void func_L01_00516FD8(s32, char *);
extern s32 func_L01_004BA830(void);
extern void func_L01_00516D60(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern void func_L01_004C0FD8(u8 *, s32, u32);
extern void func_L01_004C2718(s32);

void func_L01_004C2A80(void)
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
    e = &((Vendor_4C2A80 *)&D_L01_002446C0)->e[((Vendor_4C2A80 *)&D_L01_002446C0)->sel];
    id = e->id;
    func_L01_00419E60(&row, id, ((Row_4C2A80 *)D_L01_002C5600)[D_001425C0[id]].level);
    if (e->x11) {
        func_L01_00419E60(&row, e->id, 5);
    }
    /* these callees return a value; the file's void prototypes would change the register allocation */
    ((s32 (*)(void))func_L01_004C1838)();
    func_L01_004BEC88((char *)D_L01_001E1038, D_00142660[0]);
    if (e->buy_all) {
        func_L01_00517190(0x48001F, 0xED41);
    } else if (e->x13) {
        func_L01_00517190(0x48001F, 0x755D);
    } else {
        func_L01_00517190(0x48001F, row.icon);
    }
    vt = (Vendor_4C2A80 *)&D_L01_002446C0;
    if (vt->timer < 15) {
        D_L01_001E0F7C = vt->timer;
        func_L01_004C1460(0);
        if (vt->timer >= 2) {
            return;
        }
    } else {
        D_L01_001E0F80 = 0;
        func_L01_005170B8_004C2A80(0x480026, 0x8066CCFF);
        func_L01_00516AA0(0x480026, 1, 1);
        func_L01_00516AA0(0x48002B, 1, 1);
        func_L01_00516AA0(0x48002A, 1, 1);
        func_L01_00516AA0(0x480029, 1, 1);
    }
    v = (Vendor_4C2A80 *)&D_L01_002446C0;
    sel = v->sel;
    if (D_L01_001DAE10 != sel) {
        D_L01_001E1050 = 1;
        D_L01_001DAE10 = sel;
        D_L01_001E0F78 = 100;
    }
    if (D_00143950[0xB7] >= 2) {
        func_L01_00516818(0x480026, 0.7f);
    }
    func_L01_00517538(0x480023, 1.1f, 1.1f);
    if (e->buy_all == 1) {
        v->total = 0;
        for (i = 0; i < 156; i++) {
            if (D_00142CA0[i] != 0) {
                Row_4C2A80 *m = &((Row_4C2A80 *)D_L01_002C5600)[D_001425C0[i]];
                if (m->round_price != 0) {
                    s32 max = m->max_ammo;
                    s32 ammo = D_001427F0[i];
                    if (ammo < max) {
                        if (((Vendor_4C2A80 *)&D_L01_002446C0)->w5C != 0) {
                            if (i == 16 || i == 17 || i == 19 || i == 21 || i == 22) {
                                continue;
                            }
                        }
                        ((Vendor_4C2A80 *)&D_L01_002446C0)->total += m->round_price * (max - ammo);
                    }
                }
            }
        }
        func_0011B754(D_L01_0024DE50, func_00381FF0(0xBF0));
        if (D_00143950[0xB7] >= 2) {
            func_L01_00517538(0x480023, 0.8f, 0.8f);
        }
        vs = (Vendor_4C2A80 *)&D_L01_002446C0;
        func_L01_00516FD8(0x480026, func_00381FF0(0x135A));
        func_L01_00516FD8(0x480027, 0);
        func_L01_004BEC88((char *)D_L01_001E0FF0, vs->total);
        if (D_00142660[0] < vs->total) {
            can_afford = 0;
        }
        if (vs->total == 0) {
            available = 0;
            D_L01_001E0F78 = 100;
        }
        if (D_001CCFD0.h4 == 0) {
            func_L01_00517190(0x48001E, 0x29);
        }
    } else if (e->x13 == 1) {
        if (v->w744 != 0) {
            ((s32 (*)(s32, char *))func_L01_00516FD8)(0x480026, func_00381FF0(0x1B94));
            if (D_001CCFD0.h4 == 0) {
                func_L01_00517190(0x48001E, 0x2E);
            }
            func_0011B754(D_L01_0024DE50, func_00381FF0(0x1808));
        } else {
            ((s32 (*)(s32, char *))func_L01_00516FD8)(0x480026, func_00381FF0(0x17FA));
            if (D_001CCFD0.h4 == 0) {
                func_L01_00517190(0x48001E, 0x2D);
            }
            func_0011B754(D_L01_0024DE50, func_00381FF0(0x1807));
        }
        available = 0;
    } else if (e->kind == 1) {
        if (D_001427F0[id] >= row.max_ammo) {
            available = 0;
        }
        ((s32 (*)(char *, char *, char *, s32))func_0011B2E8)(D_L01_0024DE50, D_L01_001DADA8, func_00381FF0(row.name), (s32)func_00381FF0(0x178));
        func_L01_00516FD8(0x480026, func_00381FF0(row.desc));
        func_L01_00516FD8(0x480027, D_L01_001E0500);
        func_L01_004BEC88((char *)D_L01_001E0FF0, ((Row_4C2A80 *)D_L01_002C5600)[D_001425C0[v->e[v->sel].id]].round_price);
        if (D_00142660[0] < ((Row_4C2A80 *)D_L01_002C5600)[D_001425C0[v->e[v->sel].id]].round_price) {
            can_afford = 0;
        }
        if (id != 0 && D_001CCFD0.h4 == 0) {
            func_L01_00517190(0x48001E, row.hD6 + 1);
        }
    } else {
        func_0011B754(D_L01_0024DE50, func_00381FF0(row.name));
        func_L01_00516FD8(0x480026, func_00381FF0(row.desc));
        func_L01_004BEC88((char *)D_L01_001E0FF0, func_L01_004BA830());
        if (D_00142660[0] < func_L01_004BA830()) {
            can_afford = 0;
        }
        if (id != 0 && D_001CCFD0.h4 == 0) {
            func_L01_00517190(0x48001E, row.hD4 + 1);
        }
        func_L01_00516FD8(0x480027, 0);
        D_L01_001E0F78 = 0;
    }
    func_L01_00516AA0(0x480024, 1, available);
    func_L01_00516AA0(0x480021, 1, available);
    func_L01_00516AA0(0x480025, 1, available);
    func_L01_00516AA0(0x48002B, 1, (u8)(available ^ 1));
    if (e->x13) {
        a = 0;
        if (D_00142430.w15C < 3 && D_00142430.w164 < 0 && D_00142430.pad[0].type == 2) {
            a = D_00142430.pad[0].val != 0;
        }
        b = 0;
        if (D_00142430.w15C < 3 && D_00142430.w164 < 0 && D_00142430.pad[1].type == 2) {
            b = D_00142430.pad[1].val != 0;
        }
        func_L01_00516D60(0x48002B, a | b);
        func_003E7F20(0x48002B, 1);
        func_L01_00516FD8(0x48002B, func_00381FF0(0x17FB));
    } else {
        func_L01_00516FD8(0x48002B, func_00381FF0(0x8CD));
        func_003E7F20(0x48002B, 1);
    }
    if (D_00143950[0xB7] == 3) {
        func_L01_00517538(0x48002B, 0.75f, 0.9f);
    }
    if (D_001D545C == 3 && ((Vendor_4C2A80 *)&D_L01_002446C0)->w5C == 0 && ((Vendor_4C2A80 *)&D_L01_002446C0)->e[((Vendor_4C2A80 *)&D_L01_002446C0)->sel].buy_all == 0 && ((Vendor_4C2A80 *)&D_L01_002446C0)->e[((Vendor_4C2A80 *)&D_L01_002446C0)->sel].x13 == 0
        && ((Vendor_4C2A80 *)&D_L01_002446C0)->e[((Vendor_4C2A80 *)&D_L01_002446C0)->sel].id != 0x67 && ((Vendor_4C2A80 *)&D_L01_002446C0)->e[((Vendor_4C2A80 *)&D_L01_002446C0)->sel].id != 0x16 && ((Vendor_4C2A80 *)&D_L01_002446C0)->w50 == 0) {
        if (D_L01_001E0F80 == 0) {
            func_L01_00516AA0(0x48002C, 1, 1);
        }
        func_L01_00516AA0(0x480016, 1, 1);
    } else {
        func_L01_00516AA0(0x48002C, 1, 0);
        func_L01_00516AA0(0x480016, 1, 0);
    }
    if (available == 0 || can_afford == 0) {
        func_L01_00516AA0(0x480029, 1, 0);
    } else {
        func_L01_00516AA0(0x480029, 1, 1);
    }
    color = 0x80707070;
    if (can_afford) {
        color = 0x8066CCFF;
    }
    func_L01_004C0FD8(D_L01_002F1D18, 0x480021, color);
    func_L01_004C0FD8(D_L01_002F1D18, 0x480025, color);
    func_L01_004C2718(available);
}
/* localdecomp:end func_L01_004C2A80 */

/* localdecomp:start func_L01_004C3448 */



extern G_004BF8A0 D_L01_002446C0;
extern char D_L01_0024DED0[];
extern char D_L01_001DAE18[];
extern s32 D_L01_001E0F94;
extern char D_L01_001E1008[8];
extern char D_L01_001E1009;
extern u8 D_001425C0[];
extern M_004BF8A0 D_L01_002C5600[];
extern s32 D_00142660[];
extern char *func_00381FF0(s32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00518670(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_0011B2E8(char *, char *, char *, s32);
extern void func_L01_004BEC88(char *, s32);
extern s32 func_0011B868(char *);
extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_L01_004BA830(void);

void func_L01_004C3448(void)
{
    f32 v[2];
    s32 i;

    if (D_L01_002446C0.w132 == 0) {
        func_L01_00516FD8(0x480029, func_00381FF0(2252));
        func_L01_00516FD8(0x48002A, func_00381FF0(256));
        func_L01_00516818(0x480026, 1.0f);
        func_L01_00516470(0x480026, 0.3025f, 0.325f);
        func_L01_00518670(0x480026, 0, 0);
        func_L01_00516AA0(0x48002D, 1, 0);
        func_L01_00516AA0(0x480022, 1, 0);
        return;
    }
    if (D_L01_002446C0.e[D_L01_002446C0.w128].b4 == 1) {
        func_0011B2E8(D_L01_0024DED0, D_L01_001DAE18, func_00381FF0(2254), D_L01_001E0F94);
        func_L01_00516FD8(0x480026, D_L01_0024DED0);
        func_L01_00516818(0x480026, 1.0f);
        func_L01_00518670(0x480026, 1, 1);
        func_L01_00516470(0x480026, 0.3f, 0.27f);
        func_L01_00516FD8(0x48002A, func_00381FF0(2251));
        func_L01_00516AA0(0x48002D, 1, 1);
        func_L01_00516AA0(0x480022, 1, 1);
        if (D_L01_002446C0.w92 == 0) {
            func_L01_004BEC88(D_L01_001E1008, D_L01_001E0F94 * ((M_004BF8A0 *)((u8 *)D_L01_002C5600 + D_001425C0[D_L01_002446C0.e[D_L01_002446C0.w128].w0] * 240))->h132);
        } else {
            func_L01_004BEC88(D_L01_001E1008, D_L01_001E0F94 * ((M_004BF8A0 *)((u8 *)D_L01_002C5600 + D_001425C0[D_L01_002446C0.e[D_L01_002446C0.w128].w0] * 240))->h134);
        }
        for (i = func_0011B868(D_L01_001E1008); i >= 0; i--) {
            D_L01_001E1008[i + 2] = D_L01_001E1008[i];
        }
        D_L01_001E1009 = ' ';
        D_L01_001E1008[0] = ' ';
        func_L01_00516EC8(0x48002D, &v[0], &v[1], &v[1], &v[1]);
        func_L01_00516470(0x480022, v[0], 0.33f);
    } else if (func_L01_004BA830() <= D_00142660[0]) {
        func_L01_00516FD8(0x480026, func_00381FF0(2256));
        func_L01_00516818(0x480026, 1.0f);
        func_L01_00518670(0x480026, 1, 1);
        func_L01_00516470(0x480026, 0.3f, 0.25f);
        func_L01_00516FD8(0x480029, func_00381FF0(2274));
        func_L01_00516FD8(0x48002A, func_00381FF0(2271));
        func_L01_00516AA0(0x48002D, 1, 0);
        func_L01_00516AA0(0x480022, 1, 0);
    }
}
/* localdecomp:end func_L01_004C3448 */

/* localdecomp:start func_L01_004C3840 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 D_L01_001E0F80;
extern s32 D_L01_001E0F7C;
extern u8 D_L01_002F2798[];

extern f32 func_L01_004451A8(f32 f12);
extern void func_L01_004C13B0(s32 a0, u8 *a1);

void func_L01_004C3840(s32 arg0) {
    f32 f;

    D_L01_001E0F80 = 1;
    ((void (*)(s32 a0, s32 a1, s32 a2))func_L01_00516AA0)(0x48000C, 1, 0);
    f = (f32)D_L01_001E0F7C / 15.0f;
    if (arg0 != 0) {
        f = 1.0f - f;
    }
    if (1.0f < f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    func_L01_004C13B0((s32)(func_L01_004451A8(f) * 128.0f), D_L01_002F2798);
}
/* localdecomp:end func_L01_004C3840 */

/* localdecomp:start func_L01_004C3910 */
typedef struct Obj_004C3910 Obj_004C3910;
typedef struct {
    u8 pad[16];
    s32 (*isA)(Obj_004C3910 *, s32);
} Vt_004C3910;
struct Obj_004C3910 {
    u8 pad0[8];
    Vt_004C3910 *vt;
    u8 padC[0x44];
    VObj_4BEB00 *f50;
};
extern u8 D_L01_002F2798[];
extern S_func_004C07D8 D_00160C40[];
extern u8 D_L01_00244E50[];
extern s16 D_001CCFD4[];
extern s32 D_L01_001DC1B0_004C3910;
extern s32 D_L01_001E15E0[];
void func_L01_004C3910(void) {
    extern void func_L01_00516468_004C3910(s32);
    extern s32 func_L01_0047B3D8(void);
    extern s32 func_L01_00479248(void);
    extern s32 func_L01_0047B948(void);
    extern void func_L01_004C1028(void *);
    extern s32 func_003E8348(s32, s32);
    extern void func_L01_004C13B0(s32 a0, u8 *a1);
    extern VObj_4BEB00 *func_003B42F8(s32);
    extern s32 func_003B4528(void *, s32, s32, s32, s32);
    extern s32 *func_003E6C08(s32 *);
    extern void *func_003E6DE8(s32 *);
    extern Obj_004C3910 *func_003E6378(void *, s32);
    extern s32 func_L01_00517190(s32, s32);
    extern s32 func_L01_00516AA0(s32, s32, s32);
    extern void func_L01_004C3A48(void);
    extern void func_L01_004C3D70(void);
    s32 *manager;
    Obj_004C3910 *obj;
    func_L01_00516468_004C3910(1);
    func_L01_0047B3D8();
    func_L01_00479248();
    func_L01_0047B948();
    func_L01_004C1028(D_L01_002F2798);
    func_003E8348(27, 0x480000);
    func_L01_004C13B0(0, D_L01_002F2798);
    func_L01_00516468_004C3910(0);
    func_003B4528(func_003B42F8(0), (s32)D_L01_00244E50, 0, D_00160C40[0].f4954, (s32)D_00160C40[0].fX);
    manager = D_L01_001E15E0[1] ? D_L01_001E15E0 : func_003E6C08(D_L01_001E15E0);
    obj = func_003E6378(func_003E6DE8(manager), 0x480019);
    if (obj == 0 || !obj->vt->isA(obj, D_L01_001DC1B0_004C3910)) obj = 0;
    obj->f50 = func_003B42F8(0);
    if (D_001CCFD4[0] == 0) func_L01_00517190(0x480019, 42);
    func_L01_00516AA0(0x480019, 0x8000, 1);
    func_L01_004C3A48();
    func_L01_004C3D70();
}
/* localdecomp:end func_L01_004C3910 */

/* localdecomp:start func_L01_004C3A48 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern G_004BF8A0 D_L01_002446C0;
extern char *func_00381FF0(s32);
extern s32 D_00142660[];
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_004BEC88(char *, s32);




extern T_4BFEA0 D_L01_001DAE28;
extern u8 D_L01_001E1038[8];
extern u8 D_L01_001E0FF0[8];
extern u8 D_L01_002F2798[];
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;

extern s32 func_L01_00419D00(s32);
extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_L01_004C0FD8(u8 *, s32, u32);
extern void func_L01_004C3840(s32);
extern void func_L01_00516D60(s32, s32);

void func_L01_004C3A48(void) {
    G_4BFEA0 *g;
    T_4BFEA0 t;
    s32 idx;
    s32 val;
    s32 lt;
    s32 on;
    s32 n;
    u32 col;
    f32 sc;
    f32 x;
    f32 y;

    g = &(*(G_4BFEA0 *)&D_L01_002446C0);
    idx = g->ent[g->sel].idx;
    if (idx == 0) {
        idx = (*(H_4BFEA0 *)&D_00142660).w78;
    }
    t = D_L01_001DAE28;
    col = 0x80707070;
    sc = 0.563f;
    ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000B, ((s32 (*)(s32))func_00381FF0)(func_L01_00419D00(idx)));
    ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000C, ((s32 (*)(s32))func_00381FF0)(t.a[idx]));
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E1038, (*(H_4BFEA0 *)&D_00142660).w0);
    func_L01_00516EC8(0x480011, &x, &y, &y, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001B, x - 0.015f, 0.64f);
    val = g->ent[g->sel].val;
    lt = val < (*(H_4BFEA0 *)&D_00142660).w0;
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E0FF0, val);
    func_L01_00516EC8(0x48000E, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001A, x + 0.012f, sc);
    func_L01_00516EC8(0x48001A, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48000F, x + 0.01f, sc);
    if (lt) {
        col = 0x8066CCFF;
    }
    func_L01_004C0FD8(D_L01_002F2798, 0x48001A, col);
    func_L01_004C0FD8(D_L01_002F2798, 0x48000F, col);
    n = g->w4;
    if (n < 15) {
        D_L01_001E0F7C = n;
        func_L01_004C3840(0);
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 0);
    } else {
        D_L01_001E0F80 = 0;
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 1);
    }
    if (val == 0) {
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000B, ((s32 (*)(s32))func_00381FF0)(1196));
    }
    on = val != 0;
    func_L01_00516D60(0x480011, on);
    func_L01_00516D60(0x48001B, on);
    func_L01_00516D60(0x48000E, on);
    func_L01_00516D60(0x48001A, on);
    func_L01_00516D60(0x48000F, on);
    func_L01_00516D60(0x480012, on);
    if (val != 0) {
        func_L01_00516D60(0x480012, lt);
    }
}
/* localdecomp:end func_L01_004C3A48 */

/* localdecomp:start func_L01_004C3D70 */
extern char *func_00381FF0(s32);
extern G_004BF8A0 D_L01_002446C0;
extern s32 D_00142660[];
extern void func_L01_00516FD8(s32, char *);
extern s32 D_L01_001E0F80;
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L01_004C3D70(void) {
    S_4C01C8 *b = ((S_4C01C8 *)&(*(G_4BFEA0 *)&D_L01_002446C0));

    if (b->f84 == 0) {
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2252));
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(256));
        func_L01_00516AA0(0x48000D, 1, 0);
        if (D_L01_001E0F80 == 0) {
            func_L01_00516AA0(0x48000C, 1, 1);
        }
    } else {
        if (((s32 *)&(*(H_4BFEA0 *)&D_00142660))[0] >= b->e[b->f80].f0) {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2274));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(2271));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2256));
        } else {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2255));
        }
        func_L01_00516AA0(0x48000D, 1, 1);
        func_L01_00516AA0(0x48000C, 1, 0);
    }
}
/* localdecomp:end func_L01_004C3D70 */

INCLUDE_ASM("asm/levels", func_L01_004C3EB8);

/* localdecomp:start func_L01_004C42D0 */
extern u8 D_L01_002F2CD8[];

void func_L01_004C42D0(s32 arg0) {
    f32 f;

    D_L01_001E0F80 = 1;
    f = (f32)D_L01_001E0F7C / 15.0f;
    if (arg0 != 0) {
        f = 1.0f - f;
    }
    if (1.0f < f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    func_L01_004C13B0((s32)(func_L01_004451A8(f) * 128.0f), D_L01_002F2CD8);
}
/* localdecomp:end func_L01_004C42D0 */

/* localdecomp:start func_L01_004C4380 */
extern VObj_4BEB00 *func_003B42F8(s32);
extern void func_L01_004C13B0(s32 a0, u8 *a1);
extern S_func_004C07D8 D_00160C40[];
extern u8 D_L01_002F2CD8[];
extern s16 D_001CCFD4[];
extern u8 D_L01_00244E50[];
extern u8 D_L01_00249650[];
extern void func_L01_00516468_004C4380(s32);
extern s32 func_L01_0047B3D8(void);
extern s32 func_L01_00479248(void);
extern s32 func_L01_0047B948(void);
extern void func_L01_004C1028(void *);
extern s32 func_003E8348(s32, s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004C44D8(void);
extern void func_L01_004C47A0(void);
void func_L01_004C4380(void) {
    func_L01_00516468_004C4380(1);
    func_L01_0047B3D8();
    func_L01_00479248();
    func_L01_0047B948();
    func_L01_004C1028(D_L01_002F2CD8);
    func_003E8348(27, 0x480000);
    ((void (*)(s32, void *))func_L01_004C13B0)(0, D_L01_002F2CD8);
    if (D_001CCFD4[0] == 0) {
        func_003B4528(((void * (*)(s32))func_003B42F8)(0), (s32)D_L01_00244E50, 0, D_00160C40->f4954, (s32)D_00160C40->fX);
        func_003E8710(0x480019, (s32)((void * (*)(s32))func_003B42F8)(0));
        func_003B4528(((void * (*)(s32))func_003B42F8)(1), (s32)D_L01_00249650, 0, D_00160C40->f4954, (s32)D_00160C40->fX);
        func_003E8710(0x48001A, (s32)((void * (*)(s32))func_003B42F8)(1));
        func_L01_00517190(0x480019, 43);
        func_L01_00517190(0x48001A, 44);
        func_L01_00516AA0(0x480019, 0x8000, 1);
        func_L01_00516AA0(0x48001A, 0x8000, 1);
    }
    func_L01_00516468_004C4380(0);
    func_L01_004C44D8();
    func_L01_004C47A0();
}
/* localdecomp:end func_L01_004C4380 */

/* localdecomp:start func_L01_004C44D8 */
typedef struct { s32 id; s32 price; u8 p8[12]; char *label; u8 p18[8]; u8 flag; u8 p21[3]; } E_004C44D8;
typedef struct { u8 p0[4]; s32 timer; u8 p8[0x78]; s32 sel; u8 p84[0xBC]; E_004C44D8 e[1]; } V_004C44D8;
extern char D_L01_001DAE40[];
extern s32 func_L01_00517F50(s32, s32, s32);
static __inline__ s32 ready_004C44D8(s32 i) { return func_003B42F8(i)->p0 == 2; }
static __inline__ void enable_004C44D8(s32 id, u8 on) { ((s32 (*)(s32, s32))func_L01_00516D60)(id, on); }
void func_L01_004C44D8(void) {
    s32 price;
    s32 hide;
    s32 rich;
    u32 col;
    f32 x;
    f32 y;

    ((s32 (*)(char *, char *, char *))func_0011B2E8)(D_L01_0024DE50, D_L01_001DAE40, ((V_004C44D8 *)&D_L01_002446C0)->e[((V_004C44D8 *)&D_L01_002446C0)->sel].label);
    if (((V_004C44D8 *)&D_L01_002446C0)->timer < 15) {
        D_L01_001E0F7C = ((V_004C44D8 *)&D_L01_002446C0)->timer;
        func_L01_004C42D0(0);
    } else {
        D_L01_001E0F80 = 0;
    }
    price = ((V_004C44D8 *)&D_L01_002446C0)->e[((V_004C44D8 *)&D_L01_002446C0)->sel].price;
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E0FF0, price);
    ((s32 (*)(s32, f32 *, f32 *, f32 *, f32 *))func_L01_00516EC8)(0x48000C, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48000F, x + 0.015f, 0.645f);
    ((s32 (*)(s32, f32 *, f32 *, f32 *, f32 *))func_L01_00516EC8)(0x48000F, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48000D, x + 0.015f, 0.645f);
    hide = ((V_004C44D8 *)&D_L01_002446C0)->e[((V_004C44D8 *)&D_L01_002446C0)->sel].flag ^ 1;
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000F, hide);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000C, hide);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000D, hide);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x480017, hide ^ 1);
    if (ready_004C44D8(0) && ready_004C44D8(1)) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480019, 1);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001A, 1);
    } else {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480019, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001A, 0);
    }
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E1038, D_00142660[0]);
    col = 0x80707070;
    rich = price < D_00142660[0];
    if (rich) {
        col = 0x8066CCFF;
    }
    func_L01_004C0FD8(D_L01_002F2CD8, 0x48000D, col);
    func_L01_004C0FD8(D_L01_002F2CD8, 0x48000F, col);
    func_L01_00517F50(0x48000E, 0xEA97, ((V_004C44D8 *)&D_L01_002446C0)->e[((V_004C44D8 *)&D_L01_002446C0)->sel].id);
    enable_004C44D8(0x480014, rich && hide);
}
/* localdecomp:end func_L01_004C44D8 */

/* localdecomp:start func_L01_004C47A0 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern G_004BF8A0 D_L01_002446C0;


extern s32 D_00142660[];
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);

void func_L01_004C47A0(void) {
    B_4C0BF8 *b = &(*(B_4C0BF8 *)&D_L01_002446C0);
    s32 idx = b->idx;

    if (b->active == 0) {
        func_L01_00516FD8(0x480014, func_00381FF0(2252));
        func_L01_00516FD8(0x480015, func_00381FF0(256));
        ((void (*)(s32 id, s32 a, s32 b))func_L01_00516AA0)(0x480016, 1, 0);
        return;
    }
    if (b->e[idx].w32 <= D_00142660[0]) {
        func_L01_00516FD8(0x480014, func_00381FF0(2274));
        func_L01_00516FD8(0x480015, func_00381FF0(2271));
        func_L01_00516FD8(0x480016, func_00381FF0(2256));
    } else {
        func_L01_00516FD8(0x480016, func_00381FF0(2255));
        func_L01_00516FD8(0x480015, func_00381FF0(2251));
    }
    ((void (*)(s32 id, s32 a, s32 b))func_L01_00516AA0)(0x480016, 1, 1);
}
/* localdecomp:end func_L01_004C47A0 */

INCLUDE_ASM("asm/levels", func_L01_004C48D0);

/* localdecomp:start func_L01_004C4D90 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 D_L01_001E0F80;
extern s32 D_L01_001E0F7C;
extern u8 D_L01_002F3218[];

extern f32 func_L01_004451A8(f32 f12);
extern void func_L01_004C13B0(s32 a0, u8 *a1);

void func_L01_004C4D90(s32 arg0) {
    f32 f;

    D_L01_001E0F80 = 1;
    ((void (*)(s32 a0, s32 a1, s32 a2))func_L01_00516AA0)(0x48000C, 1, 0);
    f = (f32)D_L01_001E0F7C / 15.0f;
    if (arg0 != 0) {
        f = 1.0f - f;
    }
    if (1.0f < f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    func_L01_004C13B0((s32)(func_L01_004451A8(f) * 128.0f), D_L01_002F3218);
}
/* localdecomp:end func_L01_004C4D90 */

/* localdecomp:start func_L01_004C4E60 */
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } E_004C4E60;
extern T_4C1638 D_L01_002F1C20[];
extern char D_L01_001DAE40[];
extern s32 D_L01_001DABD0;
extern s32 D_L01_001DABCC;
extern u8 D_L01_001DABC9;
__asm__(".extern D_L01_001DABD0, 4");
__asm__(".extern D_L01_001DABCC, 4");
__asm__(".extern D_L01_001DABC9, 1");
extern char *func_003B9E30(s32, s32, s32);
extern s32 func_L01_004BB0F0(s32);
extern void func_L01_00498948(s32, s32, s32);
extern char *func_00381FF0(s32);
extern void func_0011B2E8(char *, char *, char *, s32);
void func_L01_004C4E60(void) {
    E_004C4E60 *base = (E_004C4E60 *)D_L01_002F1C20;
    s32 n = 0;
    s32 off = 0;
    s32 none = 0xFF;
    do {
        if (((E_004C4E60 *)((u8 *)base + off))->w8 != none) {
            char *text = func_003B9E30(func_003B9BD0(0), 0, n);
            ((void (*)(char *, char *, char *))func_0011B2E8)(text, D_L01_001DAE40, func_00381FF0(((E_004C4E60 *)((u8 *)D_L01_002F1C20 + off))->w0));
            if (func_L01_004BB0F0(((E_004C4E60 *)((u8 *)D_L01_002F1C20 + off))->wC)) {
                func_L01_00498948(func_003B9BD0(0), n, 0);
            } else {
                func_L01_00498948(func_003B9BD0(0), n, 2);
            }
            if (D_L01_001DABD0 < 5 && ((E_004C4E60 *)((u8 *)D_L01_002F1C20 + off))->wC == -1) {
                D_L01_001DABC9 = 0;
                D_L01_001DABCC = 0;
                func_L01_00498948(func_003B9BD0(0), n, 3);
            } else if (((E_004C4E60 *)((u8 *)D_L01_002F1C20 + off))->wC == D_L01_001DABD0) {
                D_L01_001DABCC = ((E_004C4E60 *)((u8 *)D_L01_002F1C20 + off))->wC;
                D_L01_001DABC9 = 1;
                func_L01_00498948(func_003B9BD0(0), n, 3);
            }
            n++;
        }
        off += 16;
    } while ((E_004C4E60 *)((u8 *)D_L01_002F1C20 + off) < base + 10);
}
/* localdecomp:end func_L01_004C4E60 */

/* localdecomp:start func_L01_004C4FE8 */
extern S_func_004C07D8 D_00160C40[];
extern u8 D_L01_00244E50[];
extern u8 D_L01_002F3218[];
extern s32 D_L01_001E15E0[];
extern s32 D_L01_001DC1B0;
extern s16 D_001CCFD4[];
static __inline__ s32 *root_004C4FE8(void) {
    extern s32 *func_003E6C08(void);
    if (D_L01_001E15E0[1] == 0) return func_003E6C08();
    return D_L01_001E15E0;
}
void func_L01_004C4FE8(void) {
    extern void func_L01_00516468_004C4FE8(s32);
    extern s32 func_L01_0047B3D8(void);
    extern s32 func_L01_00479248(void);
    extern s32 func_L01_0047B948(void);
    extern void func_L01_004C1028(void *);
    extern s32 func_003E8348(s32, s32);
    extern void func_L01_004C13B0(s32, u8 *);
    extern VObj_4BEB00 *func_003B42F8(s32);
    extern s32 func_003B4528(void *, s32, s32, s32, s32);
    extern s32 *func_003E6C08(void);
    extern void *func_003E6DE8(s32 *);
    extern Obj_004C2548 *func_003E6378(void *, s32);
    extern s32 func_L01_00517190(s32, s32);
    extern s32 func_L01_00516AA0(s32, s32, s32);
    extern void func_L01_005169C8(s32, f32);
    extern void func_L01_00516B90(s32, s32, s32);
    extern void func_L01_004C17E8(s32, s32, s32, s32, s32, s32, f32);
    extern void func_L01_004C51E0(void);
    extern void func_L01_004C5530(void);
    Obj_004C2548 *object;
    s32 *root;
    func_L01_00516468_004C4FE8(1);
    func_L01_0047B3D8();
    func_L01_00479248();
    func_L01_0047B948();
    func_L01_004C1028(D_L01_002F3218);
    func_003E8348(27, 0x480000);
    func_L01_004C13B0(0, D_L01_002F3218);
    func_L01_00516468_004C4FE8(0);
    func_003B4528(func_003B42F8(0), (s32)D_L01_00244E50, 0, D_00160C40[0].f4954, (s32)D_00160C40[0].fX);
    root = root_004C4FE8();
    object = func_003E6378(func_003E6DE8(root), 0x480019);
    if (object == 0 || !object->vt->test(object, D_L01_001DC1B0)) object = 0;
    object->object = func_003B42F8(0);
    if (D_001CCFD4[0] == 0) func_L01_00517190(0x480019, 42);
    func_L01_00516AA0(0x480019, 0x8000, 1);
    func_L01_005169C8(0x480004, 8.1f);
    func_L01_005169C8(0x480005, 8.1f);
    func_L01_005169C8(0x480006, 8.1f);
    func_L01_005169C8(0x480007, 8.1f);
    func_L01_00516B90(0x480012, 2, 3);
    func_L01_00516B90(0x480012, 1, 3);
    func_L01_004C17E8(0x480033, 0x480034, 0x480035, 0x480036, 0x480037, 0x480032, 0.03f);
    func_L01_004C51E0();
    func_L01_004C5530();
}
/* localdecomp:end func_L01_004C4FE8 */

/* localdecomp:start func_L01_004C51E0 */
extern void func_L01_00516D60(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_004BEC88(char *, s32);
extern void func_L01_00516FD8(s32 id, char *s);
extern char *func_00381FF0(s32 id);
extern G_004BF8A0 D_L01_002446C0;



extern T_4C1638 D_L01_002F1C20[];
extern u8 D_L01_001E1038[8];
extern u8 D_L01_001E0FF0[8];
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;

extern void func_L01_004C1838(void);
extern s32 func_L01_004526F8(void);
extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_L01_005170B8_004C51E0(s32, u32);
extern void func_L01_004C4D90(s32);

void func_L01_004C51E0(void) {
    G_4C1638 *g;
    s32 idx;
    s32 val;
    s32 en;
    s32 on;
    s32 n;
    u32 col;
    f32 sc;
    f32 x;
    f32 y;

    g = &(*(G_4C1638 *)&D_L01_002446C0);
    col = 0x80707070;
    sc = 0.563f;
    idx = g->ent[g->sel].idx;
    ((void (*)(s32, s32))func_L01_00516FD8)(0x48000B, ((s32 (*)(s32))func_00381FF0)(D_L01_002F1C20[idx].w0));
    ((void (*)(s32, s32))func_L01_00516FD8)(0x48000C, ((s32 (*)(s32))func_00381FF0)(D_L01_002F1C20[idx].w4));
    func_L01_004C1838();
    n = func_L01_004526F8();
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E1038, n);
    func_L01_00516EC8(0x480011, &x, &y, &y, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001B, x - 0.015f, 0.64f);
    val = g->ent[g->sel].val;
    en = func_L01_004526F8() >= val;
    if (val == 255) {
        en = 0;
    }
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E0FF0, val);
    func_L01_00516EC8(0x48000E, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001A, x + 0.012f, sc);
    func_L01_00516EC8(0x48001A, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48000F, x + 0.01f, sc);
    if (en) {
        col = 0x8066CCFF;
    }
    func_L01_005170B8_004C51E0(0x48001A, col);
    func_L01_005170B8_004C51E0(0x48000F, col);
    n = g->w4;
    if (n < 15) {
        D_L01_001E0F7C = n;
        func_L01_004C4D90(0);
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 0);
    } else {
        D_L01_001E0F80 = 0;
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 1);
    }
    if (val == 0) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480012, 1);
        ((void (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(268));
    } else {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480012, 0);
    }
    on = val != 0;
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x480011, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001B, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000E, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001A, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000F, on);
    if (val == 255) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480011, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001B, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000E, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001A, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000F, 0);
    }
    if (val != 0) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480012, en);
    }
}
/* localdecomp:end func_L01_004C51E0 */

/* localdecomp:start func_L01_004C5530 */
extern void func_L01_00516FD8(s32 id, char *s);
extern char *func_00381FF0(s32 id);
extern G_004BF8A0 D_L01_002446C0;
extern s32 D_L01_001E0F80;
extern s32 func_L01_004526F8(void);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L01_004C5530(void) {
    S_4C1988 *b = ((S_4C1988 *)&D_L01_002446C0);
    s32 n = b->e[b->f80].f0;

    if (b->f84 == 0) {
        if (n != 0) {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2252));
        }
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(256));
        func_L01_00516AA0(0x48000D, 1, 0);
        if (D_L01_001E0F80 == 0) {
            func_L01_00516AA0(0x48000C, 1, 1);
        }
    } else {
        if (func_L01_004526F8() >= n) {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2274));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(2271));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2256));
        } else {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2255));
        }
        func_L01_00516AA0(0x48000D, 1, 1);
        func_L01_00516AA0(0x48000C, 1, 0);
    }
}
/* localdecomp:end func_L01_004C5530 */

LINKER_REMNANT("asm/levels", func_L01_004C5688);
