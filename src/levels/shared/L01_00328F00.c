#include "common.h"

typedef struct {
    u8 pad0[0x120];
    s32 x120[16];
    s32 x160[16];
    u8 pad1[0x140];
    u16 x2E0[16];
    u8 x300[16][3];
} S_324F38;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[12];
    void (*fn)(u8 *);
} Vt003254A8;
typedef void (*Func00325CE8Cb)(void *, s32, s32);
typedef struct {
    u8 pad0[8];
    s32 (*check)(s32);
} VT_00325E48;
typedef struct {
    s32 unk0;
    s32 next;
} Node_00325E48;
typedef struct {
    u8 pad0[352];
    VT_00325E48 *vt[16];
    s32 free[32];
    s32 count[16];
    s32 stamp[16];
    s32 head[16];
} S_00325E48;
typedef struct { u8 p0[0x86]; s16 h86; } P_00325F68;
typedef struct { u8 p0[0x14]; f32 f14; u8 p18[0x50 - 0x18]; P_00325F68 *p50; } S_00325F68;
typedef struct { u8 p0[0x70]; s32 w70; } A_00325F68;
typedef struct {
    u8 pad0[36];
    s32 w36;
    u8 pad28[68];
    s32 w108;
    u8 pad70[6];
    s16 h118;
    u8 pad78[28];
    s32 w148;
    s16 h152;
    u8 pad9A[4];
    s16 h158;
} S_001CCFD0;
typedef struct {
    s32 w0;
    u8 pad4[32];
    s32 w36;
} S_002E5F70;
typedef struct {
    u8 pad0[132];
    s32 w132;
    s32 w136;
    s32 w140;
    s32 arr144[16];
    s32 arr208[16];
} Obj_003260C8;
typedef struct { u8 p0[0x20]; u8 b20; u8 p1[3]; s32 w24; u8 p2[0xC]; u16 h34; u8 p3[0x62]; s32 w98; } M_326F30;
typedef struct {
    char pad0[0x58];
    void (*fn88)(int);
    char pad5C[0x60 - 0x5C];
    void (*fn96)(int);
} Iface;
typedef struct {
    char pad0[0x14];
    int index;
} Vars;
typedef struct {
    char pad0[0x68];
    Vars *vars;
} Obj;
typedef struct Node_003290D8 {
    u8 pad[104];
    struct Node_003290D8 *link;
    struct Node_003290D8 *next;
} Node_003290D8;
typedef struct {
    s32 pad0;
    Node_003290D8 *head;
    Node_003290D8 *found;
    s32 index;
} List_003290D8;
typedef struct { u8 pad[0x30]; s32 x30; } O_329180;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x13]; u16 h34; } M_329358;
typedef struct {
    int w[4];
    char pad10[0x21 - 0x10];
    unsigned char b33;
    char pad22[0xA0 - 0x22];
    unsigned char b160[4];
    int w164;
} Sub;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
    char pad21[0x30 - 0x21];
    unsigned char b48;
    char pad31[0x34 - 0x31];
    unsigned short h52;
    char pad36[0x68 - 0x36];
    Sub *p104;
} Obj_00329E70;
typedef int s128_329AA8 __attribute__((mode(TI)));

typedef struct {
    u8 pad[0x20];
    s32 (*fn20)(u8 *);
} Vt_00327608;

typedef struct {
    u8 p0[0x14];
    s32 index;
    s32 w18;
} Vars_00327678;
typedef struct {
    u8 p0[0x68];
    Vars_00327678 *vars;
} Obj_00327678;
typedef struct {
    u8 p0[0x28];
    void (*fn)(s32, s32, s32);
} Iface_00327678;

typedef struct {
    u8 pad0[0x40];
    s32 (*fn40)(u8 *);
} Vt_00327968;

typedef struct { u8 pad0[0x14]; s32 index; s32 w18; } V_003279D8;
typedef struct { u8 pad0[0x68]; V_003279D8 *vars; } O_003279D8;
typedef struct { u8 pad0[0x44]; s32 (*fn44)(s32, s32); } I_003279D8;

typedef struct { u8 p0[0x14]; s32 index; } Vars_00327A78;
typedef struct { u8 p0[0x68]; Vars_00327A78 *vars; } Obj_00327A78;
typedef struct { u8 p0[0x48]; s32 (*fn48)(s32); } Iface_00327A78;

typedef struct {
    u8 p0[8];
    s32 w8;
    u8 p12[0x53 - 12];
    u8 b53;
} L_00329038;
typedef struct {
    u8 p0[12];
    s32 w12;
    u8 p16[40];
} E_00329038;

/* declared by functions of L01_003241A0.c, which this file was cut from */
extern u8 *D_L01_001E001C;
extern s32 D_001D545C;
extern E_00329038 D_L01_002AEA10[];
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_L01_00449050(void *);
extern u8 *func_00382348(void *);
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern u8 D_001426E0[];
extern void func_L01_003295D8(s32 x, O_329180 *o);
extern void func_L01_005003D0(s32, s32);
extern s32 D_001A71A4[];
extern void func_0038CAD0(s32 *);
extern s32 func_L01_003294A0(s32 a, List_003290D8 *l, s32 key);
extern s32 func_L01_003294A0(s32, List_003290D8 *, s32);
extern u8 D_001BBC40[];
extern s32 func_L01_00329638(u8 *, u8 *);
extern s32 func_L01_00329700(u8 *a0, u8 *a1);
extern s32 func_L01_00328F00(u8 *);
extern s32 func_L01_00329338(u8 *);

/* localdecomp:start func_L01_00328F00 */
extern s32 D_001D545C;
extern s32 D_001D545C_00328F00;
__asm__(".extern D_001D545C_00328F00, 16");
extern u8 D_001BBC40[];
extern u8 D_001426E0[];
extern E_00329038 D_L01_002AEA10[];
s32 func_L01_00328F00(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *entry;
    s32 key;
    s32 flag;
    if (p[0x53] == 0xFF) {
        s32 k = *(s32 *)(p + 4);
        if (k == -1) return 1;
        return D_001BBC40[k + D_001D545C * 16] >> 7;
    }
    key = *(s32 *)(p + 4);
    entry = (u8 *)&D_L01_002AEA10[p[0x53]];
    if (key == -1) {
        s32 f = *(s32 *)(entry + 8);
        if (f == 0) return 1;
        return D_001426E0[f] != 0;
    }
    if (D_001BBC40[key + D_001D545C_00328F00 * 16] & 0x80) return 1;
    flag = *(s32 *)(entry + 8);
    if (flag != 0 && D_001426E0[flag] != 0) return 1;
    return 0;
}
/* localdecomp:end func_L01_00328F00 */

/* localdecomp:start func_L01_00328FE8 */
s32 func_L01_00328FE8(u8 *a0) {
    L_00329038 *l = *(L_00329038 **)(a0 + 0x68);
    E_00329038 *e;
    u8 b;

    if (l->w8 != -1) {
        return 1;
    }
    if (l->b53 == 0xFF) {
        return 0;
    }
    b = l->b53;
    e = (E_00329038 *)((u8 *)D_L01_002AEA10 + b * 56);
    return e->w12 != 0;
}
/* localdecomp:end func_L01_00328FE8 */

/* localdecomp:start func_L01_00329038 */
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern E_00329038 D_L01_002AEA10[];
extern u8 D_001426E0[];

s32 func_L01_00329038(u8 *a0) {
    L_00329038 *l = *(L_00329038 **)(a0 + 0x68);
    u8 b;
    E_00329038 *e;
    if (l->w8 != -1) {
        if (D_001BBC40[l->w8 + D_001D545C * 16] & 0x80) {
            return 1;
        }
    }
    if (l->b53 == 0xFF) {
        return 0;
    }
    b = l->b53;
    e = (E_00329038 *)((u8 *)D_L01_002AEA10 + b * 56);
    if (e->w12 == 0) {
        return 0;
    }
    return D_001426E0[e->w12] != 0;
}
/* localdecomp:end func_L01_00329038 */

/* localdecomp:start func_L01_003290D0 */
extern s32 D_001D545C;
extern E_00329038 D_L01_002AEA10[];
extern u8 D_001426E0[];
extern u8 D_001BBC40[];
extern u8 D_L01_001DFE80[] __attribute__((section(".sdata")));
s32 func_L01_003290D0(s32 arg) {
    L_00329038 *v = *(L_00329038 **)((u8 *)arg + 0x68);
    s32 i;
    u8 b;
    E_00329038 *e;
    if (v->b53 != 255) {
        b = v->b53;
        e = (E_00329038 *)((u8 *)D_L01_002AEA10 + b * 56);
        if (e->w12 != 0 && D_001426E0[e->w12] == 1) return 1;
    }
    i = v->w8;
    if (i != -1 && (D_001BBC40[i + D_001D545C * 16] & 128) && !(D_L01_001DFE80[i] & 128)) return 1;
    return 0;
}
/* localdecomp:end func_L01_003290D0 */

/* localdecomp:start func_L01_00329180 */
extern E_00329038 D_L01_002AEA10[];

s32 func_L01_00329180(u8 *a0) {
    u8 *l = *(u8 **)(a0 + 0x68);
    u8 b;
    u8 *e;

    if (*(s32 *)(l + 0xC) != -1) {
        return 1;
    }
    if (l[0x53] == 0xFF) {
        return 0;
    }
    b = l[0x53];
    e = (u8 *)D_L01_002AEA10 + b * 56;
    return *(s32 *)(e + 0x10) != 0;
}
/* localdecomp:end func_L01_00329180 */

/* localdecomp:start func_L01_003291D0 */
extern s32 D_001D545C;
extern f32 D_L01_001DAA3C;
extern u8 D_001426E0[];
extern f32 D_L01_002F17E0[];
extern u8 D_001BBC40[];
extern E_00329038 D_L01_002AEA10[];
extern s32 func_L01_0041A4F0(void);
s32 func_L01_003291D0(u8 *m) {
    u8 *vars = *(u8 **)(m + 0x68);
    s32 value = *(s32 *)(vars + 0x54);
    s32 divisor = 1;
    if (func_L01_0041A4F0()) {
        s32 scaled = value * (D_001D545C == 7 && D_001426E0[0x7B] ? D_L01_001DAA3C : D_L01_002F17E0[D_001D545C]);
        value = scaled;
        if (D_001D545C == 4) value = scaled * 15;
    }
    if (vars[0x53] == 255 || D_L01_002AEA10[vars[0x53]].w12 == 0) {
        s32 key = *(s32 *)(vars + 8);
        if (key != -1) {
            if (D_001BBC40[key + D_001D545C * 16] & 128) divisor = 10;
        }
    } else {
        E_00329038 *entry = &D_L01_002AEA10[vars[0x53]];
        u8 flag = D_001426E0[entry->w12];
        if (flag >= 2) divisor = 10;
        else if (flag == 1) divisor = 3;
    }
    if (divisor >= 2) {
        s32 result = value / divisor;
        result -= result % 100;
        if (result == 0) result = 100;
        return result;
    }
    return value;
}
/* localdecomp:end func_L01_003291D0 */

/* localdecomp:start func_L01_00329338 */
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001426E0[];
extern E_00329038 D_L01_002AEA10[];
s32 func_L01_00329338(u8 *self) {
    extern s32 func_L01_00328FE8(u8 *);
    extern s32 func_L01_00329180(u8 *);
    extern s32 func_L01_00329038(u8 *);
    u8 *p=*(u8 **)(self+0x68);
    s32 key,ok,flag;
    u8 *e;
    if(!func_L01_00328FE8(self) || !func_L01_00329180(self) || !func_L01_00329038(self)) return 0;
    key=*(s32 *)(p+0xC);
    ok=1;
    if(key!=-1) {
        if(D_001BBC40[key+D_001D545C*16]&0x80) ok=0;
    }
    if(p[0x53]==255) return ok;
    e=(u8 *)D_L01_002AEA10+p[0x53]*56;
    flag=*(s32 *)(e+0x10);
    if(!flag) return ok;
    if(key!=-1) return ok && D_001426E0[flag]==0;
    return D_001426E0[flag]==0;
}
/* localdecomp:end func_L01_00329338 */

/* localdecomp:start func_L01_00329438 */
extern s32 func_L01_00328F00(u8 *);
void func_L01_00329438(void *a0, u8 *a1) {
    s32 n = 0;
    u8 *p = *(u8 **)(a1 + 4);
    while (p != 0 && !func_L01_00328F00(p)) {
        n++;
        p = *(u8 **)(*(u8 **)(p + 104) + 108);
    }
    *(u8 **)(a1 + 8) = p;
    *(s32 *)(a1 + 12) = n;
}
/* localdecomp:end func_L01_00329438 */

/* localdecomp:start func_L01_003294A0 */
extern s32 func_L01_00328F00(u8 *);

s32 func_L01_003294A0(s32 a, List_003290D8 *l, s32 key) {
    s32 n = 0;
    Node_003290D8 *p;
    Node_003290D8 *b;

    p = l->head;
    while (p != 0) {
        do {
            b = p->link;
        } while (0);
        if (func_L01_00328F00((u8 *)p) != 0) {
            if (*(s32 *)b == key) {
                l->found = p;
                l->index = n;
                return 1;
            }
        }
        do {
            p = b->next;
        } while (0);
        do {
            n++;
        } while (0);
    }
    return 0;
}
/* localdecomp:end func_L01_003294A0 */

/* localdecomp:start func_L01_00329530 */
extern void func_L01_00329438(void *a0, u8 *a1);
extern s32 func_L01_00329038(u8 *a0);
extern s32 func_L01_00328FE8(u8 *);
extern s32 func_L01_00328F00(u8 *);
void func_L01_00329530(s32 a, List_003290D8 *l) {
    Node_003290D8 *n;
    Node_003290D8 *link;
    s32 i = 0;
    n = l->head;
    goto check;
next:
    i++;
check:
    if (n == 0) goto fail;
    link = n->link;
    if (((s32 (*)(Node_003290D8 *))func_L01_00328F00)(n) == 0) {
        n = link->next;
        goto next;
    }
    if (((s32 (*)(Node_003290D8 *))func_L01_00328FE8)(n) == 0) {
        n = link->next;
        goto next;
    }
    if (((s32 (*)(Node_003290D8 *))func_L01_00329038)(n) == 0) {
        l->found = n;
        l->index = i;
        return;
    }
    n = link->next;
    goto next;
fail:
    ((void (*)(s32, List_003290D8 *))func_L01_00329438)(a, l);
}
/* localdecomp:end func_L01_00329530 */

/* localdecomp:start func_L01_003295D8 */
extern void func_L01_00329530(s32 a, List_003290D8 *l);
extern s32 func_L01_00328FE8(u8 *);
extern s32 func_L01_003290D0(s32);
void func_L01_003295D8(s32 x, O_329180 *o) {
    if (o->x30 != 0 && ((s32 (*)(s32))func_L01_00328FE8)(o->x30) && func_L01_003290D0(o->x30)) {
        ((void (*)(s32, O_329180 *))func_L01_00329530)(x, o);
    }
}
/* localdecomp:end func_L01_003295D8 */

/* localdecomp:start func_L01_00329638 */
typedef struct {
    u8 pad[0x18];
    s32 (*check18)(u8 *);
    s32 (*check1C)(u8 *);
} Iface_00329638;
extern u8 *D_001D52FC;
extern u8 *D_L01_001E001C;
extern s32 D_001D545C;

s32 func_L01_00329638(u8 *a0, u8 *vars) {
    extern s32 func_L01_0043B568(s32, s32, s32);
    Iface_00329638 *iface;
    u8 *moby;
    if (*(s32 *)(vars + 0x14) != -1) {
        iface = (Iface_00329638 *)func_L01_0043B568(0x1ADD, 0, 0x68);
        moby = D_L01_001E001C + (*(s32 *)(vars + 0x14) << 8);
        if ((*(s32 *)(D_001D52FC + 0x1C4) & 0x10) != 0 &&
            (iface->check18(moby) != 0 || iface->check1C(moby) != 0) &&
            D_001D545C != 12 && D_001D545C != 18 && D_001D545C != 20 &&
            D_001D545C != 26 && D_001D545C != 29) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00329638 */

/* localdecomp:start func_L01_00329700 */
extern void func_0038CAD0(s32 *);
extern s32 D_001A71A4[];
extern u8 *D_001D52FC;
extern s32 func_L01_0045A6F0(u8 *a0);
extern void func_L01_005003D0(s32 a0, s32 a1);

s32 func_L01_00329700(u8 *a0, u8 *a1) {
    if (func_L01_0045A6F0(a0) == 5) {
        return 0;
    }
    if (D_001A71A4[0] != 116) {
        func_L01_005003D0(116, 1);
    }
    ((s32 (*)(u8 *a0))func_0038CAD0)(a1 + 72);
    ((s32 (*)(u8 *a0))func_0038CAD0)(a1 + 76);
    if (((s32 (*)(u8 *a0))func_0038CAD0)(a1 + 68) != 0 && (*(s32 *)(D_001D52FC + 452) & 0x40)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00329700 */

/* localdecomp:start func_L01_00329780 */
extern void func_L01_003B4718(s32);
s32 func_L01_00329780(u8 *a0) {
    if (a0[32] == 7) {
        func_L01_003B4718(0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00329780 */

/* localdecomp:start func_L01_003297B0 */
extern s32 func_L01_00449050(void *);

s32 func_L01_003297B0(M_329358 *m) {
    if (!(m->h34 & 2)) return 0;
    ((void (*)(void))func_L01_00449050)();
    return m->b20 == 0xFD;
}
/* localdecomp:end func_L01_003297B0 */

/* localdecomp:start func_L01_003297F8 */
extern u8 *func_00382348(void *);
extern s32 func_L01_00449050(void *);
s32 func_L01_003297F8(void *a0) {
    u8 *p = ((u8 * (*)(void *))func_L01_00449050)(a0);
    f32 *f;
    if (p[13] != 255) {
        return p[13];
    }
    f = ((f32 * (*)(void *))func_00382348)(a0);
    if (f == 0) {
        return 2;
    }
    if (*f <= 0.0f) {
        return 0;
    }
    return 2;
}
/* localdecomp:end func_L01_003297F8 */

/* localdecomp:start func_L01_00329860 */
extern u8 *func_00382348(void *);
extern s32 func_L01_00449050(void *);
s32 func_L01_00329860(void *a0) {
    u8 *p = ((u8 * (*)(void *))func_L01_00449050)(a0);
    f32 *f;
    if (p[13] != 255) {
        return p[13];
    }
    f = ((f32 * (*)(void *))func_00382348)(a0);
    if (f == 0) {
        return 1;
    }
    if (*f <= 0.0f) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00329860 */
