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
extern u8 *func_00382348(void *);
extern u8 D_001A4C60[];
extern f32 D_L01_001DCA34;
extern f32 D_L01_001DCA38;

/* localdecomp:start func_L01_00328598 */
/* from func_L09_00317890 (src/levels/09_tyhrranosis/L09_00317890.c) */
#include "vu0.h"
extern u8 D_001A4C60[];
extern u8 D_001D5477;
extern f32 D_L01_001DC0E8;
extern f32 D_L01_001DC0EC;
__asm__(".extern D_L01_001DC0E8, 16");
__asm__(".extern D_L01_001DC0EC, 16");
extern f32 D_L01_001DCA34;
__asm__(".extern D_L01_001DCA34, 4");
extern f32 D_L01_001DCA38;
__asm__(".extern D_L01_001DCA38, 4");
extern f32 D_L01_001DCA44;
__asm__(".extern D_L01_001DCA44, 4");
extern f32 D_L01_001DCA48;
__asm__(".extern D_L01_001DCA48, 4");
extern f32 D_L01_001DCA4C;
__asm__(".extern D_L01_001DCA4C, 4");
extern f32 D_L01_001DCA50;
__asm__(".extern D_L01_001DCA50, 4");
extern f32 D_L01_001DCA54;
__asm__(".extern D_L01_001DCA54, 4");
extern f32 D_L01_001DCA58;
__asm__(".extern D_L01_001DCA58, 4");
extern f32 D_L01_001DCA5C;
__asm__(".extern D_L01_001DCA5C, 4");
extern f32 D_L01_001DCA60;
__asm__(".extern D_L01_001DCA60, 4");
extern f32 D_L01_001DCA64;
__asm__(".extern D_L01_001DCA64, 4");
extern f32 D_L01_001DCA68;
__asm__(".extern D_L01_001DCA68, 4");
extern s32 D_L01_001DCA80;
__asm__(".extern D_L01_001DCA80, 4");
__asm__(".extern D_L01_001DCA88, 8");
extern s32 D_L01_001DCA88[] __attribute__((section(".sdata")));
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

void func_L01_00328598(u8 *a0, s32 mode, void *a2, void *a3, long a4) {
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 g;
    f32 k;
    f32 len;
    f32 s;
    u8 *p;

    k = D_L01_001DCA5C;
    p = func_00382348(a0);
    if (p != 0) {
        switch (p[8]) {
        case 0:
            k = D_L01_001DCA58;
            break;
        case 2:
            k = D_L01_001DCA60;
            break;
        case 3:
            k = D_L01_001DCA64;
            break;
        }
    }
    if (mode == 3) {
        k += D_L01_001DCA68;
    }
    vec_sub_ab(&d, a0 + 0x10, D_001A4C60);
    s = func_0038CE68(&d, a2);
    func_0038CE20(&e, a2, s);
    vec_sub_ab(&d, &d, &e);
    len = func_0038CEA8(&d);
    if (len > D_L01_001DCA44) {
        len = D_L01_001DCA44;
    } else if (len < D_L01_001DCA48) {
        len = D_L01_001DCA48;
    }
    s = len * (1.0f / D_L01_001DCA44);
    func_0038D000(&d, &d, a3);
    func_0038CF68(&g, &d, s * D_L01_001DCA54);
    if (D_001D5477) {
        g.x = -g.x;
    }
    g.x = g.x * D_L01_001DCA4C + D_L01_001DCA34 - k;
    g.y = g.y * D_L01_001DCA50 + D_L01_001DCA38 - k;
    func_0038B4D0((s32)(g.x * D_L01_001DC0E8), (s32)(g.y * D_L01_001DC0EC), (s32)((k + k) * D_L01_001DC0E8),
                  (s32)((k + k) * D_L01_001DC0EC), 0, 0, D_L01_001DCA80, D_L01_001DCA80, D_L01_001DCA88[mode], a4);
}
/* localdecomp:end func_L01_00328598 */

/* localdecomp:start func_L01_003287D8 */
typedef union {
    vu0_v4 v;
    s32 w[4];
} Col_003287D8;
typedef struct {
    u8 p0[8];
    s32 (*fn8)(void *);
    u8 pC[4];
    s32 (*fn10)(void *);
} Vt_003287D8;
typedef struct {
    u8 p0[0x30];
    unsigned long fl30;
    u8 p38[0x60];
    s32 w98;
} Mo_003287D8;
typedef struct {
    u8 p0[0x60];
    Mo_003287D8 *w60;
    u8 p64[0x160 - 0x64];
    Vt_003287D8 *vt[16];
    u8 p1A0[0x2A0 - 0x1A0];
    Mo_003287D8 *head[16];
} St_003287D8;
extern void func_0038CB78(void *, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_0040EE50(void *, void *);
extern long func_00389598(s32);
extern s32 func_00396968(s32, s32);
extern void func_003972A0(s32, s32 *, f32, f32, f32, f32, f32);
extern s32 func_L01_00449050(void *);
extern s32 func_L01_003257E8(void);
extern void *func_L01_00326D98(void);
extern u8 *func_L01_003B3508(void);
extern u8 *D_001A71A0[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
__asm__(".extern D_001D4BC0, 16");
__asm__(".extern D_001D4BC4, 16");
extern vu0_q D_L01_001E2DD0;
__asm__(".extern D_L01_001E2DD0, 16");
extern f32 D_L01_001DCA6C;
extern f32 D_L01_001DCA70;
extern f32 D_L01_001DCA74;
extern f32 D_L01_001DCA78;
extern s32 D_L01_001DCA7C;
extern f32 D_L01_001DCA5C;
extern s32 D_L01_001DCA8C;
__asm__(".extern D_L01_001DCA8C, 16");
extern s32 D_L01_001DCA94;
__asm__(".extern D_L01_001DCA94, 16");
extern s32 D_L01_001DCA98[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DCA98, 8");
__asm__(".extern D_L01_001DCA6C, 4");
__asm__(".extern D_L01_001DCA70, 4");
__asm__(".extern D_L01_001DCA74, 4");
__asm__(".extern D_L01_001DCA78, 4");
__asm__(".extern D_L01_001DCA7C, 4");

void func_L01_003287D8(void) {
    s32 usedA[4];
    s32 usedB[16][4];
    s32 usedC[4];
    vu0_v4 cam;
    vu0_v4 ang;
    vu0_v4 mat[3];
    vu0_v4 v180;
    vu0_v4 v190;
    vu0_v4 v1A0;
    Col_003287D8 d;
    vu0_v4 e;
    vu0_v4 g;
    long tex;
    St_003287D8 *vars;
    s32 i;
    s32 j;
    s32 k;
    s32 kind;
    Mo_003287D8 *o;
    Mo_003287D8 *q;
    Vt_003287D8 *vt;
    u8 *node;
    u8 *p;

    func_0038CB78(usedA, 0, sizeof(usedA));
    func_0038CB78(usedB, 0, sizeof(usedB));
    func_0038CB78(usedC, 0, sizeof(usedC));
    vars = *(St_003287D8 **)(func_L01_003257E8() + 0x68);
    tex = func_00389598(D_L01_001DCA7C);
    qzero(&ang);
    ang.z = -1.5707964f;
    func_0038D308(mat, &ang);
    *(vu0_q *)&cam = *(vu0_q *)(D_001A71A0[0] + 0xE0);
    *(vu0_q *)&v190 = D_L01_001E2DD0;
    *(vu0_q *)&v1A0 = *(vu0_q *)&cam;
    func_0038CE90(&v180, &v190, &v1A0);
    func_0038CF68(&v180, &v180, 1.0f);
    func_0038D5F0(&v180, &v180, mat);
    func_L01_0040EE50(&v180, &v180);
    {
        f32 w;
        f32 h;
        w = (D_L01_001DCA6C + D_L01_001DCA6C) * (f32)D_001D4BC0;
        h = (D_L01_001DCA70 + D_L01_001DCA70) * (f32)D_001D4BC4;
        e.x = (D_L01_001DCA74 - D_L01_001DCA6C) * (f32)D_001D4BC0;
        e.y = (D_L01_001DCA78 - D_L01_001DCA70) * (f32)D_001D4BC4;
        d.w[3] = D_L01_001DCA8C;
        d.w[2] = D_L01_001DCA8C;
        d.w[1] = D_L01_001DCA8C;
        d.w[0] = D_L01_001DCA8C;
        func_003972A0(func_00396968(0xE99A, 3), d.w, e.x, e.y, w, h, 0.0f);
    }
    k = D_L01_001DCA98[0];
    for (i = 0; i < 16; i++) {
        q = vars->head[i];
        if (q != 0) {
            vt = vars->vt[i];
            if (vt->fn10 != 0) {
                o = q;
                do {
                    node = (u8 *)func_L01_00449050(o);
                    kind = vt->fn10(o);
                    if (kind != 0) {
                        if (vt->fn8(o) == 0) {
                            if ((o->fl30 & (0x8208UL << 29)) != (0x8200UL << 23) || o->w98 != 0) {
                                if (kind == k) {
                                    func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                                } else {
                                    usedA[kind] = 1;
                                    usedB[i][kind] = 1;
                                }
                            }
                        }
                    }
                    o = *(Mo_003287D8 **)(node + 4);
                } while (o != 0);
            }
        }
    }
    if (vars->w60 != 0) {
        vt = func_L01_00326D98();
        o = vars->w60;
        if (o != 0) {
            do {
                node = (u8 *)func_L01_00449050(o);
                kind = vt->fn10(o);
                if (kind != 0) {
                    if (vt->fn8(o) == 0) {
                        if (kind == k) {
                            func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                        } else {
                            usedC[kind] = 1;
                        }
                    }
                }
                o = *(Mo_003287D8 **)(node + 4);
            } while (o != 0);
        }
    }
    for (j = 1; j < 4; j++) {
        k = D_L01_001DCA98[j];
        if (usedA[k] != 0) {
            for (i = 0; i < 16; i++) {
                if (usedB[i][k] != 0) {
                    o = vars->head[i];
                    vt = vars->vt[i];
                    if (o != 0) {
                        do {
                            node = (u8 *)func_L01_00449050(o);
                            kind = vt->fn10(o);
                            if (kind == k) {
                                if (vt->fn8(o) == 0) {
                                    if ((o->fl30 & (0x8208UL << 29)) != (0x8200UL << 23) || o->w98 != 0) {
                                        func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                                    }
                                }
                            }
                            o = *(Mo_003287D8 **)(node + 4);
                        } while (o != 0);
                    }
                }
            }
        }
    }
    if (vars->w60 != 0) {
        vt = func_L01_00326D98();
        for (j = 1; j < 4; j++) {
            k = D_L01_001DCA98[j];
            if (usedC[k] != 0) {
                o = vars->w60;
                if (o != 0) {
                    do {
                        node = (u8 *)func_L01_00449050(o);
                        kind = vt->fn10(o);
                        if (kind != 0) {
                            if (vt->fn8(o) == 0) {
                                if (kind == k) {
                                    func_L01_00328598((u8 *)o, kind, &cam, &v180, tex);
                                } else {
                                    usedC[kind] = 1;
                                }
                            }
                        }
                        o = *(Mo_003287D8 **)(node + 4);
                    } while (o != 0);
                }
            }
        }
    }
    p = func_L01_003B3508();
    if (p != 0) {
        f32 len;
        f32 s;
        f32 kk;
        s32 sz;
        vec_sub_ab(&d.v, p, D_001A4C60);
        s = func_0038CE68(&d.v, &cam);
        func_0038CE20(&e, &cam, s);
        vec_sub_ab(&d.v, &d.v, &e);
        len = func_0038CEA8(&d.v);
        if (len > D_L01_001DCA44) {
            len = D_L01_001DCA44;
        } else if (len < D_L01_001DCA48) {
            len = D_L01_001DCA48;
        }
        s = len * (1.0f / D_L01_001DCA44);
        func_0038D000(&d.v, &d.v, &v180);
        func_0038CF68(&g, &d.v, s * D_L01_001DCA54);
        sz = D_L01_001DCA80;
        g.x = g.x * D_L01_001DCA4C + D_L01_001DCA34 - D_L01_001DCA5C;
        g.y = g.y * D_L01_001DCA50 + D_L01_001DCA38 - D_L01_001DCA5C;
        kk = D_L01_001DCA5C;
        func_0038B4D0((s32)(g.x * D_L01_001DC0E8), (s32)(g.y * D_L01_001DC0EC), (s32)((kk + kk) * D_L01_001DC0E8),
                      (s32)((kk + kk) * D_L01_001DC0EC), 0, 0, sz, sz, D_L01_001DCA94, tex);
    }
}
/* localdecomp:end func_L01_003287D8 */
