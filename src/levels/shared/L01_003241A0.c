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

INCLUDE_ASM("asm/levels", func_L01_003241A0);

INCLUDE_ASM("asm/levels", func_L01_00324E50);

/* localdecomp:start func_L01_003250A8 */
extern s32 D_001D545C;
extern E_00329038 D_L01_002AEA10[];

s32 func_L01_003250A8(s32 *a0) {
    u8 *e = (u8 *)D_L01_002AEA10;
    s32 i = 0;
    while (*(s32 *)e > 0) {
        if (*(s32 *)e == D_001D545C && *(s32 *)(e + 4) == *a0) {
            break;
        }
        e += 56;
        i++;
    }
    return *(s32 *)e < 0 ? 0xFF : i;
}
/* localdecomp:end func_L01_003250A8 */

INCLUDE_ASM("asm/levels", func_L01_00325110);

/* localdecomp:start func_L01_00325438 */

extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_L01_00449050(void *);
extern u8 *func_00382348(void *);

s32 func_L01_00325438(void *a, S_324F38 *b, u8 *c) {
    s32 i;
    s32 r;
    u8 *q;

    for (i = 0; b->x120[i] != -1 && i < 16; i++) {
        if (*(s16 *)(c + 0xAA) == b->x120[i]) {
            return i;
        }
    }
    if (i == 16) {
        return -1;
    }
    r = func_L01_0043B568(*(s16 *)(c + 0xAA), 1, 28);
    b->x160[i] = r;
    if (r == 0 || func_L01_00449050(c) == 0) {
        return -1;
    }
    b->x120[i] = *(s16 *)(c + 0xAA);
    q = func_00382348(c);
    if (q != 0) {
        b->x2E0[i] = *(u16 *)(q + 4);
        b->x300[i][0] = q[20];
        b->x300[i][1] = q[21];
        b->x300[i][2] = q[22];
    } else {
        b->x2E0[i] = 0;
        b->x300[i][0] = 0;
        b->x300[i][1] = 0;
        b->x300[i][2] = 0;
    }
    return i;
}
/* localdecomp:end func_L01_00325438 */

/* localdecomp:start func_L01_00325570 */
typedef struct { u8 pad[0x120]; s32 ids[16]; s32 classes[16]; s32 heads[16]; s32 counts[16]; s32 totals[16]; s32 a260[16]; s32 a2A0[16]; } State_00325570;
extern u8 *D_L01_001E001C;
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
void func_L01_00325570(void *a, S_324F38 *b) {
    extern s32 func_L01_00325438(void *, S_324F38 *, u8 *);
    State_00325570 *state = (State_00325570 *)b;
    s32 i;
    s32 *heads = state->heads;
    s32 *counts = state->counts;
    s32 *totals = state->totals;
    u16 *q;
    u8 *e;
    s32 n;
    for (i = 0; i < 16; i++) {
        state->ids[i] = -1;
        state->classes[i] = 0;
        state->heads[i] = 0;
        state->counts[i] = 0;
        state->totals[i] = 0;
        state->a260[i] = 0;
        state->a2A0[i] = 0;
    }
    if (*(s32 *)((u8 *)b + 0x34) != -1) {
        for (q = D_L01_0021DE20[*(s32 *)((u8 *)b + 0x34)];
             (*(s32 *)((u8 *)b + 0x34) & 0xFF) != 0xFF &&
             *(s32 *)((u8 *)b + 0x34) <= D_L01_001E0058 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L01_0021DE20[*(s32 *)((u8 *)b + 0x34)]); q++) {
            e = D_L01_001E001C + ((*q & 0x7FFF) << 8);
            if (e == 0) break;
            i = func_L01_00325438(a, b, e);
            if (i != -1) {
                n = func_L01_00449050(e);
                *(s32 *)(n + 4) = *(s32 *)((u8 *)heads + (i << 2));
                *(s32 *)((u8 *)heads + (i << 2)) = (s32)e;
                *(s32 *)((u8 *)counts + (i << 2)) += 1;
                *(s32 *)((u8 *)totals + (i << 2)) += 1;
            }
        }
    }
}
/* localdecomp:end func_L01_00325570 */

/* localdecomp:start func_L01_00325708 */
extern u8 *D_L01_001E0028;
__asm__(".extern D_L01_001E0028, 4");
void func_L01_00325708(s32 unused, u8 *save) {
    extern s32 func_L01_0043B568(s32, s32, s32);
    extern s32 func_003C4B50(void *);
    extern s32 func_L01_00456500(void *, s32);
    extern s32 func_L01_00449050(void *);
    extern void func_L01_00327430(M_326F30 *);
    u8 *p, *vars, *node;
    *(u8 **)(save + 0x6C) = 0;
    if (func_L01_0043B568(500, 1, 28) != 0) {
        p = D_L01_001E0028;
        while (p != 0) {
            if (func_003C4B50(p) != 0 && func_L01_00456500(p + 0x10, *(s32 *)(save + 0x24)) != 0) {
                vars = *(u8 **)(p + 0x68);
                if (*(s32 *)(vars + 0xB0) == 0) {
                    node = (u8 *)func_L01_00449050(p);
                    *(u8 **)(node + 4) = *(u8 **)(save + 0x6C);
                    *(u8 **)(save + 0x6C) = p;
                    vars = *(u8 **)(p + 0x68);
                    *(u128_t *)(vars + 0x100) = *(u128_t *)(p + 0x10);
                    *(u128_t *)(vars + 0x110) = *(u128_t *)(p + 0xF0);
                    *(s32 *)(vars + 0xB0) = -2;
                    vars[0xBE] = 7;
                    func_L01_00327430((M_326F30 *)p);
                }
            }
            p = *(u8 **)(p + 0x28);
        }
    }
}
/* localdecomp:end func_L01_00325708 */

/* localdecomp:start func_L01_003257E8 */
extern s32 D_L01_001DCA10;
s32 func_L01_003257E8(void) {
    return D_L01_001DCA10;
}
/* localdecomp:end func_L01_003257E8 */

/* localdecomp:start func_L01_003257F0 */
void func_L01_003257F0(void *arg, u8 *save) {
    extern s32 func_L01_00449050(void *);
    extern void func_L01_003B6370(void *, void *);
    extern void func_L01_00326348(s32 a0, S_00325E48 *s, s32 i);
    extern void func_L01_003B2928(void *);
    s32 i;
    s32 current;
    u8 *node;
    VT_00325E48 *vt;
    S_00325E48 *s = (S_00325E48 *)save;
    for (i = 0; i < 16; i++) {
        s32 first = s->head[i];
        if (first != 0) {
            current = first;
            vt = s->vt[i];
            do {
                node = (u8 *)func_L01_00449050((void *)current);
                if (vt->check(current) == 0) {
                    func_L01_003B6370(*(void **)(node + 8), (void *)current);
                }
                current = *(s32 *)(node + 4);
            } while (current != 0);
            func_L01_00326348((s32)arg, s, i);
        }
    }
    func_L01_003B2928(*(void **)(save + 0x30));
}
/* localdecomp:end func_L01_003257F0 */

/* localdecomp:start func_L01_003258E8 */
extern s32 func_L01_00449050(void *);
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern void func_0038D308(u8 *a0, u8 *a1);
extern void func_L01_003B6848(s32 a0, u8 *a1, s32 a2);
extern void func_003C7C38(u8 *a0);
void func_L01_003258E8(s32 a0, u8 *a1) {
    u8 *m;
    u8 *n;
    u8 *p;
    u8 *c;
    if (func_L01_0043B568(500, 1, 28) != 0) {
        m = *(u8 **)(a1 + 108);
        while (m != 0) {
            n = ((u8 * (*)(u8 *a0))func_L01_00449050)(m);
            p = *(u8 **)(m + 104);
            *(u128_t *)(m + 16) = *(u128_t *)(p + 256);
            *(u128_t *)(m + 240) = *(u128_t *)(p + 272);
            func_0038D308(m + 192, m + 240);
            func_L01_003B6848(0, m, 0);
            *(u16 *)(m + 52) &= 0xFFBE;
            c = *(u8 **)(m + 36);
            *(u16 *)(m + 52) |= *(u16 *)(c + 68) & 0x1000;
            *(s32 *)(m + 152) = *(s32 *)(c + 16);
            func_003C7C38(m);
            m = *(u8 **)(n + 4);
        }
    }
}
/* localdecomp:end func_L01_003258E8 */

/* localdecomp:start func_L01_003259A8 */
extern s32 func_L01_00449050(void *);
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
void func_L01_003259A8(s32 a0, u8 *a1) {
    Vt003254A8 *vt;
    u8 *m;
    u8 *n;
    vt = ((Vt003254A8 * (*)(s32 a0, s32 a1, s32 a2))func_L01_0043B568)(500, 1, 28);
    if (vt != 0) {
        m = *(u8 **)(a1 + 108);
        while (m != 0) {
            n = ((u8 * (*)(u8 *a0))func_L01_00449050)(m);
            if (m[32] != 7) {
                vt->fn(m);
            }
            m = *(u8 **)(n + 4);
        }
    }
}
/* localdecomp:end func_L01_003259A8 */

/* localdecomp:start func_L01_00325A40 */
extern s32 func_L01_00456500(void *, s32);

void func_L01_00325A40(u8 *a0) {
    u8 *vars = *(u8 **)((u8 *)func_L01_003257E8() + 0x68);

    func_L01_00456500(a0 + 0x10, *(s32 *)(vars + 0x24));
}
/* localdecomp:end func_L01_00325A40 */

/* localdecomp:start func_L01_00325A78 */
extern void func_L01_004596E8();
extern void func_L01_00325A40();

void func_L01_00325A78(void) {
    func_L01_004596E8(func_L01_00325A40, 0);
}
/* localdecomp:end func_L01_00325A78 */

/* localdecomp:start func_L01_00325AA0 */
int func_L01_00325AA0(char *a0, int a1) {
    int i;
    for (i = 0; i < 16; i++) {
        if (a1 == ((int *)(a0 + 288))[i]) {
            break;
        }
    }
    return i;
}
/* localdecomp:end func_L01_00325AA0 */

/* localdecomp:start func_L01_00325AD8 */
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    u8 pad1C[0x38 - 0x1C];
} E_00325AD8;

extern E_00325AD8 D_L01_002AEA10_00325AD8[];
extern s32 D_L01_001D7BE0;
extern s32 D_L01_001E0118;
extern s32 D_001D4C38_sda;
__asm__(".extern D_001D4C38_sda, 4");

void func_L01_00325AD8(s32 a0, u8 *a1) {
    s32 i = *(s32 *)(a1 + 0x5C);
    s32 v;

    if (i >= 0) {
        v = ((E_00325AD8 *)((u8 *)D_L01_002AEA10_00325AD8 + i * 56))->w18;
        if (v != 0) {
            D_L01_001D7BE0 = v;
            D_L01_001E0118 = D_001D4C38_sda;
        }
    }
}
/* localdecomp:end func_L01_00325AD8 */

typedef struct {
    u8 pad0[0x24];
    s32 cuboid;        /* 0x24 */
    s32 spawn;         /* 0x28: its spawn point among D_L01_001E0100's */
    u8 pad2C[4];
    u8 *moby;          /* 0x30: the checkpoint reached */
    u8 pad34[0x4C];
    u8 last_area;      /* 0x80 */
    u8 pad81[3];
    s32 x84;
    s32 x88;
    s32 x8C;
    s32 x90[16];
    u8 padD0[0x260];
    u8 x330[32];
} Save_00325F60;

/* localdecomp:start func_L01_00325B18 */
typedef struct {
    u8 pad[0x30];
    s32 reached;
    u8 pad34[0x1F];
    u8 gate;
    u8 pad54[4];
    f32 factor;
} Vars_00325B18;
typedef struct {
    s32 level;
    u8 pad04[0x14];
    s32 index;
    u8 pad1C[4];
    s32 health;
    s32 maximum;
    u8 pad28[0x10];
} Gate_00325B18;
extern E_00329038 D_L01_002AEA10[];
extern u16 D_L01_002C4FE8[];
extern u16 D_L01_002C4F60[];
void func_L01_00325B18(u8 *checkpoint, Save_00325F60 *save, u8 *moby) {
    extern s32 func_L01_003B2A08(u8 *);
    s32 *state = (s32 *)save;
    Vars_00325B18 *vars = *(Vars_00325B18 **)(moby + 0x68);
    Gate_00325B18 *gate;
    if (vars->reached != 0) {
        state[23] = -1;
        return;
    }
    if (state[22] <= 0) {
        state[23] = -1;
        return;
    }
    if (vars->factor <= 0.0f) {
        state[23] = -1;
        return;
    }
    if (vars->gate == 0xFF) {
        state[23] = -1;
        return;
    }
    gate = (Gate_00325B18 *)((u8 *)D_L01_002AEA10 + vars->gate * 56);
    if (gate->level <= 0) {
        state[23] = -1;
        return;
    }
    state[23] = vars->gate;
    if (gate->health < 0 || gate->maximum < 0) {
        gate->health = func_L01_003B2A08(moby);
        gate->maximum = (s32)((f32)state[22] * vars->factor / (f32)gate->health * 32.0f);
    }
    D_L01_002C4F60[gate->index] = gate->health;
    D_L01_002C4FE8[gate->index] = gate->maximum;
}
/* localdecomp:end func_L01_00325B18 */

/* localdecomp:start func_L01_00325C40 */
extern s32 func_L01_00449050(void *);
s32 func_L01_00325C40(s32 a0, u8 *a1, s32 a2) {
    s32 x = *(s32 *)(a1 + 96);
    while (x) {
        if (x == a2) {
            return 1;
        }
        x = *(s32 *)(((u8 * (*)(s32 a0))((u8 * (*)(u8 *a0))func_L01_00449050))(x) + 4);
    }
    return 0;
}
/* localdecomp:end func_L01_00325C40 */

INCLUDE_ASM("asm/levels", func_L01_00325C88);

/* localdecomp:start func_L01_00325F60 */

typedef struct {
    s32 id;            /* 0x00 */
    u8 pad4[0x2C];
    s32 reached;       /* 0x30 */
    u8 pad34[0x1F];
    u8 gate;           /* 0x53: its entry in D_L01_002AEA10, 0xFF for none */
} CheckpointVars_00325F60;

__asm__(".extern D_L01_001D67B4, 4");
__asm__(".extern D_L01_001D67C0, 4");
__asm__(".extern D_L01_001DCA14, 4");
extern s32 D_L01_001D67B4;
extern s32 D_L01_001D67C0;
extern s32 D_L01_001DCA14;
extern s32 D_001D545C;
extern s32 D_001C5290[][16];
extern u8 D_001A4BE0[];
extern E_00329038 D_L01_002AEA10[];
extern u8 D_001426E0[];
extern S_001CCFD0 D_001CCFD0;
extern s32 D_L01_00237800[];
extern u8 *D_L01_001E0100;
extern s32 func_L01_00400490(s32 area);
extern void func_L01_00325B18(u8 *checkpoint, Save_00325F60 *save, u8 *moby);
extern void func_0039EF28(void);
extern void func_L01_00325C88(u8 *checkpoint, Save_00325F60 *save, u8 *moby);
extern void func_L01_003B2728(u8 *moby);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_004A3610(u8 *pos, u8 *rotation);
extern void func_L01_00451F60(s32, s32, s32);

/* checkpoint_reached: makes the checkpoint's area (its +0xB0) the hero's and, at one other
   than the last, takes help_checkpoint_refund off that area's deaths (at least 0); then
   resets the level's state and sets the respawn point. */
void func_L01_00325F60(u8 *checkpoint, Save_00325F60 *save, u8 *moby)
{
    CheckpointVars_00325F60 *vars = *(CheckpointVars_00325F60 **)(moby + 0x68);
    s32 i;
    u8 *gate;
    u8 *spawn;
    S_001CCFD0 *camera;

    if (D_001D545C == 12) {
        D_L01_001D67B4 = 0;
    } else if (D_001D545C == 18) {
        D_L01_001D67C0 = 0;
    }
    if (vars->reached == 0) {
        if (D_001A4BE0[0x25F7] != checkpoint[0xB0]) {
            save->last_area = D_001A4BE0[0x25F7];
            D_001A4BE0[0x25F7] = checkpoint[0xB0];
        }
        if (D_L01_001DCA14 != vars->id) {
            D_001C5290[D_001D545C][checkpoint[0xB0]] -= func_L01_00400490(checkpoint[0xB0]);
            if (D_001C5290[D_001D545C][checkpoint[0xB0]] < 0) {
                D_001C5290[D_001D545C][checkpoint[0xB0]] = 0;
            }
            D_L01_001DCA14 = vars->id;
        }
    }
    for (i = 0; i < 16; i++) {
        save->x90[i] = -1;
    }
    save->x84 = -1;
    save->x8C = 0;
    save->x88 = 0;
    camera = &D_001CCFD0;
    if ((u32)(*(u16 *)&camera->h118 - 6) >= 2) {
        *(u16 *)&camera->h118 = 5;
    }
    if ((u32)(*(u16 *)&camera->h158 - 6) >= 2) {
        *(u16 *)&camera->h158 = 5;
    }
    for (i = 0; i < 32; i++) {
        save->x330[i] = 0xFF;
    }
    save->moby = moby;
    func_L01_00325B18(checkpoint, save, moby);
    gate = (u8 *)D_L01_002AEA10 + vars->gate * 56;
    if (gate != 0) {
        switch (*(s32 *)(gate + 0x30)) {
        case 0:
            break;
        case 1:
            D_001426E0[*(s32 *)(gate + 0x34)] = 1;
            func_0039EF28();
            break;
        }
    }
    func_L01_00325C88(checkpoint, save, moby);
    func_L01_003258E8((s32)checkpoint, (u8 *)save);
    func_L01_003B2728(moby);
    if (D_L01_00237800[0] != 0 && func_L01_00456500(&D_L01_00237800[4], save->cuboid) != 0) {
        return;
    }
    spawn = D_L01_001E0100 + save->spawn * 128;
    func_L01_004A3610(spawn + 0x30, spawn + 0x70);
    func_L01_00451F60(0x25A, 0x5A, 0);
}
/* localdecomp:end func_L01_00325F60 */

/* localdecomp:start func_L01_003261E8 */
extern void func_L01_003295D8(s32 x, O_329180 *o);
extern void func_L01_00328428(s32 a0, char *a1);
extern void func_L01_003259A8(s32 a0, u8 *a1);
extern void func_L01_00325A78(void);

extern void func_L01_003B2900(void *);
extern void func_L01_003257F0(void *, u8 *);
extern s32 func_L01_00326840(void *, u8 *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 D_L01_001DF950 __attribute__((section(".sdata")));
extern s32 D_001A71A4[];
extern u8 D_001A71D7[];

void func_L01_003261E8(void *arg0, u8 *arg1, void *arg2, u8 *arg3) {
    u8 *s2;

    s2 = *(u8 **)(*(u8 **)(arg1 + 48) + 104);
    ((void (*)(void *, u8 *))func_L01_003295D8)(arg0, arg1);
    func_L01_003B2900(*(void **)(arg1 + 48));
    ((void (*)(void *, u8 *))func_L01_00328428)(arg0, arg1);
    func_L01_003257F0(arg0, arg1);
    ((void (*)(void *, u8 *))func_L01_003259A8)(arg0, arg1);
    ((void (*)(void *, u8 *))func_L01_00325A78)(arg0, arg1);
    if (*(s32 *)(arg1 + 64) == 0 && func_L01_00326840(arg0, arg1) != 0) {
        func_L01_005003D0(116, 1);
        func_L01_004450F0(arg0, 3, -1);
        D_L01_001DF950 = 2.0f;
        if (arg2 != 0) {
            (*(Func00325CE8Cb *)(arg3 + 40))(arg2, *(s32 *)(arg1 + 24), 0);
        }
    } else {
        if (*(s32 *)(s2 + 48) == 0 || *(f32 *)(s2 + 44) == 0.0f) {
            if (D_001A71A4[0] != 176) {
                func_L01_005003D0(0, 1);
            }
        }
        func_L01_004450F0(arg0, 1, -1);
    }
    *(s32 *)(arg1 + 48) = 0;
    if (*(s32 *)(s2 + 48) == 0) {
        D_001A71D7[0] = arg1[128];
    }
}
/* localdecomp:end func_L01_003261E8 */

/* localdecomp:start func_L01_00326348 */
extern s32 func_L01_00449050(void *);



extern s32 D_L01_001DFB40;

void func_L01_00326348(s32 a0, S_00325E48 *s, s32 i)
{
    s32 prev;
    s32 cur;
    s32 next;
    Node_00325E48 *node;
    VT_00325E48 *vt;

    if (s->head[i] == 0) {
        return;
    }
    if (s->stamp[i] == D_L01_001DFB40) {
        return;
    }
    s->stamp[i] = D_L01_001DFB40;
    prev = 0;
    cur = s->head[i];
    vt = s->vt[i];
    while (cur != 0) {
        node = ((Node_00325E48 * (*)(s32))((u8 * (*)(s32 a0))((u8 * (*)(u8 *a0))func_L01_00449050)))(cur);
        next = node->next;
        if (vt->check(cur) != 0) {
            if (prev != 0) {
                ((Node_00325E48 * (*)(s32))((u8 * (*)(s32 a0))((u8 * (*)(u8 *a0))func_L01_00449050)))(prev)->next = next;
            } else {
                s->head[i] = next;
            }
            node->next = s->free[i];
            s->free[i] = cur;
            s->count[i]++;
            cur = next;
        } else {
            prev = cur;
            cur = next;
        }
    }
}
/* localdecomp:end func_L01_00326348 */

/* localdecomp:start func_L01_00326468 */

extern S_00325F68 D_L01_001E2A40[];
extern u8 D_001A4C60[];
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8C28(s32, f32, f32);
extern void func_L01_003E8C70(s32, s32, f32, f32);

void func_L01_00326468(void *a0, A_00325F68 *a1) {
    S_00325F68 *s = &D_L01_001E2A40[0];
    f32 t;
    f32 k;

    if (s->p50->h86 != 0) {
        return;
    }
    if (a1->w70 != -1 && func_L01_00456500(D_001A4C60, a1->w70) != 0) {
        return;
    }
    k = 0.003f;
    func_L01_003E8BD0(0, 0, 8.0f, k);
    func_L01_003E8C28(0, 4.0f, k);
    if (s->f14 < 0.15f) {
        t = (s->f14 - 0.15f) / -0.3f;
        if (t > 1.0f) {
            t = 1.0f;
        } else if (t < 0.0f) {
            t = 0.0f;
        }
        func_L01_003E8C70(0, 0, t * -1.5f + 2.5f, 0.005f);
    } else {
        func_L01_003E8C70(0, 0, 2.5f, 0.005f);
    }
}
/* localdecomp:end func_L01_00326468 */

/* localdecomp:start func_L01_003265C8 */



extern S_001CCFD0 D_001CCFD0;
extern S_002E5F70 D_L01_002E5F30;
extern void func_0038CAD0(s32 *);
extern s32 func_003A1798(void);
extern void func_003A2B68(s32, s32);

void func_L01_003265C8(void *a0, Obj_003260C8 *a1) {
    s32 i;

    if (a1->w136 == 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        if (a1->arr144[i] != -1) {
            func_0038CAD0(&a1->arr208[i]);
        }
    }
    if (a1->w140 != 0) {
        if (D_001CCFD0.h118 != 0 || D_001CCFD0.h158 != 3 || D_001CCFD0.h152 >= 7000) {
            return;
        }
        func_003A1798();
        a1->w140 = 0;
        a1->w132 = -1;
    } else if (a1->w132 != -1) {
        if (D_001CCFD0.w108 == 0 && D_001CCFD0.w36 == -1 && D_001CCFD0.w148 == 0
            && D_L01_002E5F30.w0 == 0 && D_L01_002E5F30.w36 == D_001CCFD0.w36) {
            func_003A2B68((a1->w132 & 0x3FFF) + 6000, 0);
            a1->w140 = 1;
        }
    } else {
        a1->w136 = 0;
        for (i = 0; i < 16; i++) {
            if (a1->arr144[i] != -1) {
                a1->w136 = 1;
                if (a1->arr208[i] == 0) {
                    a1->w132 = a1->arr144[i];
                    a1->arr144[i] = -1;
                    return;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_003265C8 */

/* localdecomp:start func_L01_00326770 */
void func_L01_00326770(void) {
    extern void func_0039EF28(void);
    switch(D_001D545C) {
    case 1:
        D_001426E0[0xCC]=1;
        func_0039EF28();
        break;
    case 4:
        D_001426E0[0xCD]=1;
        func_0039EF28();
        break;
    case 12:
        D_001426E0[0xCF]=1;
        func_0039EF28();
        break;
    case 18:
        D_001426E0[0xD1]=1;
        func_0039EF28();
        break;
    case 26:
        D_001426E0[0xD0]=1;
        func_0039EF28();
        break;
    case 29:
        D_001426E0[0xCE]=1;
        func_0039EF28();
        break;
    }
}
/* localdecomp:end func_L01_00326770 */

/* localdecomp:start func_L01_00326840 */
extern u8 D_001A4C60[];
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00511A98(void);
s32 func_L01_00326840(void *a0, u8 *a1) {
    if (func_L01_00456500(D_001A4C60, *(s32 *)(a1 + 0x24)) != 0 && *(s32 *)(D_001A4C60 + 0x2544) != 0xB0) {
        return func_L01_00511A98() == 0;
    }
    return 0;
}
/* localdecomp:end func_L01_00326840 */

INCLUDE_ASM("asm/levels", func_L01_00326898);

/* localdecomp:start func_L01_00326A10 */
s32 func_L01_00326A10(s32 arg) {
    extern s32 func_L01_003257E8(void);
    extern int func_L01_00325AA0(char *, int);
    extern void func_L01_00326348(s32, S_00325E48 *, s32);
    extern s32 func_L01_00449050(void *);
    s32 owner = func_L01_003257E8();
    S_00325E48 *s = *(S_00325E48 **)(owner + 0x68);
    s32 i = func_L01_00325AA0((char *)s, arg);
    s32 value;
    Node_00325E48 *node;
    if (s->free[i] == 0) {
        func_L01_00326348(owner, s, i);
        if (s->free[i] == 0) {
            return 0;
        }
    }
    value = s->free[i];
    node = (Node_00325E48 *)func_L01_00449050((void *)value);
    s->free[i] = node->next;
    s->count[i]--;
    node->next = s->head[i];
    s->head[i] = value;
    return value;
}
/* localdecomp:end func_L01_00326A10 */

/* localdecomp:start func_L01_00326AF0 */
void func_L01_00326AF0(u8 *moby, u8 *out) {
    extern s32 func_L01_003257E8(void);
    extern int func_L01_00325AA0(char *, int);
    extern s32 func_L01_00400430(s32);
    s32 owner = func_L01_003257E8();
    S_324F38 *vars = *(S_324F38 **)(owner + 0x68);
    s32 index = func_L01_00325AA0((char *)vars, *(s16 *)(moby + 0xAA));
    s16 health = (s16)vars->x2E0[index];
    u8 color[3];
    u8 *link = *(u8 **)(moby + 0x24);
    color[0] = vars->x300[index][0];
    color[1] = vars->x300[index][1];
    color[2] = vars->x300[index][2];
    if (link != 0 && link[0x46] == 5) {
        switch (func_L01_00400430(*(u8 *)(owner + 0xB0))) {
        case 2:
            health *= *(f32 *)((u8 *)vars + 0x110);
            color[0] *= *(f32 *)((u8 *)vars + 0x118);
            color[1] *= *(f32 *)((u8 *)vars + 0x118);
            color[2] *= *(f32 *)((u8 *)vars + 0x118);
            break;
        case 1:
            health *= *(f32 *)((u8 *)vars + 0x114);
            color[0] *= *(f32 *)((u8 *)vars + 0x11C);
            color[1] *= *(f32 *)((u8 *)vars + 0x11C);
            color[2] *= *(f32 *)((u8 *)vars + 0x11C);
            break;
        }
    }
    if ((s16)vars->x2E0[index] != 0 && health < 1) health = 1;
    if (vars->x300[index][0] != 0 && color[0] == 0) color[0] = 1;
    if (vars->x300[index][1] != 0 && color[1] == 0) color[1] = 1;
    if (vars->x300[index][2] != 0 && color[2] == 0) color[2] = 1;
    *(s16 *)(out + 4) = health;
    out[0x14] = color[0];
    out[0x15] = color[1];
    out[0x16] = color[2];
}
/* localdecomp:end func_L01_00326AF0 */

/* localdecomp:start func_L01_00326D78 */
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
void func_L01_00326D78(s32 a0) {
    ((void (*)(s32, s32, s32))((Vt003254A8 * (*)(s32 a0, s32 a1, s32 a2))func_L01_0043B568))(a0, 1, 28);
}
/* localdecomp:end func_L01_00326D78 */

/* localdecomp:start func_L01_00326D98 */
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
void func_L01_00326D98(void) {
    ((void (*)(s32, s32, s32))((Vt003254A8 * (*)(s32 a0, s32 a1, s32 a2))func_L01_0043B568))(6476, 1, 28);
}
/* localdecomp:end func_L01_00326D98 */

LINKER_REMNANT("asm/levels", func_L01_00326DC0);

/* localdecomp:start func_L01_00326DD0 */
extern s32 func_L01_003257E8(void);
extern int func_L01_00325AA0();
extern void func_L01_00326348();

typedef struct {
    u8 pad0[0x220];
    s32 arr220[16];
} S_00326DD0;

s32 func_L01_00326DD0(s32 a0, s32 a1) {
    s32 v;
    S_00326DD0 *s;
    s32 idx;
    s32 cur;

    v = func_L01_003257E8();
    s = *(S_00326DD0 **)(v + 0x68);
    idx = func_L01_00325AA0(s, a0);
    cur = s->arr220[idx];
    if (cur < a1) {
        func_L01_00326348(v, s, idx);
        cur = s->arr220[idx];
    }
    return cur;
}
/* localdecomp:end func_L01_00326DD0 */

INCLUDE_ASM("asm/levels", func_L01_00326E50);

/* localdecomp:start func_L01_00327038 */
typedef struct { u8 p0[0x6C]; u8 reset; u8 p6D[0x43]; s32 ids[4], times[4], flags[4], mobys[4]; } State_00327038;
extern S_001CCFD0 D_001CCFD0;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 *D_L01_001E001C;
void func_L01_00327038(u8 *obj)
{
    extern s32 func_L01_003257E8(void);
    extern s32 func_L01_003B5B40(u8 *);
    extern f32 func_L01_003B5C80(u8 *, s32, s32, s32, s32);
    extern s32 func_L01_003B5F00(u8 *);
    extern s32 func_L01_003B5F30(u8 *, s32);
    u8 *owner = (u8 *)func_L01_003257E8();
    State_00327038 *in = *(State_00327038 **)(obj + 0x68);
    Obj_003260C8 *save = *(Obj_003260C8 **)(owner + 0x68);
    s32 i, j;
    S_001CCFD0 *camera;
    u8 *moby;
    if (in->reset) {
        for (j = 15; j >= 0; j--) save->arr144[j] = -1;
        save->w132 = -1;
        save->w140 = 0;
        save->w136 = 0;
        camera = &D_001CCFD0;
        if ((u32)(*(u16 *)&camera->h118 - 6) >= 2) *(u16 *)&camera->h118 = 5;
        if ((u32)(*(u16 *)&camera->h158 - 6) >= 2) *(u16 *)&camera->h158 = 5;
    }
    for (i = 0; i < 4; i++) {
        if (in->ids[i] == -1) continue;
        if (in->flags[i] != -1 && (D_001BBC40[in->flags[i] + (D_001D545C << 4)] & 0x80)) continue;
        if (in->mobys[i] != -1) {
            moby = D_L01_001E001C + (in->mobys[i] << 8);
            if (*(s16 *)(moby + 0xAA) == 0x19E5) {
                if (func_L01_003B5B40(moby)) {
                    if (func_L01_003B5C80(moby, 0, 0, 0, 0) == 1.0f) continue;
                } else if (func_L01_003B5F00(moby)) {
                    if (func_L01_003B5F30(moby, 0)) continue;
                }
            } else if (moby == 0 || moby[0x20] == 0xFE || moby[0x20] == 0xFD) continue;
        }
        for (j = 0; j < 16; j++) {
            if (save->arr144[j] == -1) {
                save->arr144[j] = in->ids[i];
                save->arr208[j] = in->times[i] * 50;
                break;
            }
        }
        save->w136 = 1;
    }
}
/* localdecomp:end func_L01_00327038 */

/* localdecomp:start func_L01_003272A8 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_0043B930(s32);

u8 func_L01_003272A8(s32 a0) {
    u8 *q = *(u8 **)(func_L01_003257E8() + 0x68) + 0x330;
    u8 *p = q + a0;
    if (func_L01_0043B930(*p) != 0) {
        *p = 0xFF;
    }
    return *p;
}
/* localdecomp:end func_L01_003272A8 */

/* localdecomp:start func_L01_003272F0 */
void func_L01_003272F0(s32 a0, u8 a1) {
    *(u8 *)(*(s32 *)(func_L01_003257E8() + 104) + a0 + 0x330) = a1;
}
/* localdecomp:end func_L01_003272F0 */

/* localdecomp:start func_L01_00327330 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_00449050(void *);

s32 func_L01_00327330(void) {
    S_00325E48 *s;
    s32 i;
    s32 p;
    s32 cur;
    u8 *sub;
    VT_00325E48 *vt;

    s = *(S_00325E48 **)(func_L01_003257E8() + 104);
    for (i = 0; i < 16; i++) {
        cur = s->head[i];
        if (cur == 0) {
            continue;
        }
        p = cur;
        sub = *(u8 **)(cur + 36);
        if (sub == 0) {
            continue;
        }
        if (sub[70] != 5) {
            continue;
        }
        vt = s->vt[i];
        do {
            if (vt->check(p) == 0) {
                return 1;
            }
            p = ((Node_00325E48 *)func_L01_00449050(p))->next;
        } while (p != 0);
    }
    return 0;
}
/* localdecomp:end func_L01_00327330 */

/* localdecomp:start func_L01_003273E8 */
extern s32 func_L01_003257E8(void);

s32 func_L01_003273E8(void) {
    return *(u8 *)((u8 *)func_L01_003257E8() + 0xB0);
}
/* localdecomp:end func_L01_003273E8 */

/* localdecomp:start func_L01_00327408 */
extern s32 func_L01_003257E8(void);

s32 func_L01_00327408(void) {
    return *(s32 *)(*(u8 **)((u8 *)func_L01_003257E8() + 0x68) + 0x40);
}
/* localdecomp:end func_L01_00327408 */

/* localdecomp:start func_L01_00327430 */
extern void func_L01_004AA7E8(M_326F30 *, s32);
void func_L01_00327430(M_326F30 *m) {
    m->b20 = 253;
    m->h34 |= 2;
    if (m->w24 != 0) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
    }
}
/* localdecomp:end func_L01_00327430 */

/* localdecomp:start func_L01_00327480 */
extern s32 func_L01_00449050(void *);
extern void func_L01_003B61A0(void *, void *);
void func_L01_00327480(void *a0) {
    u8 *v = (u8 *)func_L01_00449050(a0);
    void *p = *(void **)(v + 8);

    if (p != 0) {
        func_L01_003B61A0(p, a0);
    }
}
/* localdecomp:end func_L01_00327480 */

/* localdecomp:start func_L01_003274B8 */
extern s32 func_L01_00449050(void *);
extern void func_L01_003B6250(u8 *, u8 *, s32);

void func_L01_003274B8(u8 *a0, s32 a1) {
    u8 *p = *(u8 **)(((u8 * (*)(void *))func_L01_00449050)(a0) + 8);
    if (p != 0) {
        func_L01_003B6250(p, a0, a1);
    }
}
/* localdecomp:end func_L01_003274B8 */

/* localdecomp:start func_L01_00327500 */
extern s32 func_L01_00449050(void *);
extern void func_L01_003B62E0(u8 *, u8 *);

void func_L01_00327500(u8 *a0) {
    u8 *p = ((u8 * (*)(void *))func_L01_00449050)(a0);
    func_L01_003B62E0(*(u8 **)(p + 8), a0);
}
/* localdecomp:end func_L01_00327500 */

/* localdecomp:start func_L01_00327530 */
extern void func_L01_003B6370(void *, void *);

void func_L01_00327530(void *a0) {
    func_L01_003B6370(*(void **)(((u8 * (*)(void *))func_L01_00449050)(a0) + 8), a0);
}
/* localdecomp:end func_L01_00327530 */

/* localdecomp:start func_L01_00327560 */
extern void func_L01_0042B068(s32, s32);

void func_L01_00327560(s32 a0) {
    s32 *p = *(s32 **)(func_L01_003257E8() + 0x68);

    if (a0 < 0) {
        func_L01_0042B068(*p, 0);
    } else {
        func_L01_0042B068(a0, 0);
    }
}
/* localdecomp:end func_L01_00327560 */

/* localdecomp:start func_L01_003275B0 */
extern s32 func_L01_003257E8(void);
extern void func_L01_003257F0(void *, u8 *);
void func_L01_003275B0(void) {
    u8 *o = (u8 *)func_L01_003257E8();

    func_L01_003257F0(o, *(u8 **)(o + 0x68));
}
/* localdecomp:end func_L01_003275B0 */

/* localdecomp:start func_L01_003275D8 */
s32 func_L01_003275D8(void) {
    u8 *obj = (u8 *)func_L01_003257E8();
    return *(s32 *)(*(u8 **)(obj + 0x68) + 0x14) != -1;
}
/* localdecomp:end func_L01_003275D8 */

/* localdecomp:start func_L01_00327608 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern u8 *D_L01_001E001C;

s32 func_L01_00327608(void) {
    u8 *s0 = *(u8 **)(((u8 * (*)(void))func_L01_003257E8)() + 0x68);

    if (*(s32 *)(s0 + 0x14) == -1) {
        return -1;
    }
    {
        Vt_00327608 *vt = ((Vt_00327608 * (*)(s32, s32, s32))func_L01_0043B568)(0x1ADD, 0, 0x68);
        return vt->fn20(D_L01_001E001C + (*(s32 *)(s0 + 0x14) << 8));
    }
}
/* localdecomp:end func_L01_00327608 */

/* localdecomp:start func_L01_00327678 */
extern s32 func_L01_003257E8(void);
extern u8 *D_L01_001E001C;


void func_L01_00327678(s32 arg, s32 a1) {
    Obj_00327678 *o = (Obj_00327678 *)func_L01_003257E8();
    Vars_00327678 *v = o->vars;
    Iface_00327678 *it;

    if (v->index != -1) {
        it = (Iface_00327678 *)((s32 (*)(s32, s32, s32))func_L01_0043B568)(0x1ADD, 0, 0x68);
        if (arg == -2) {
            it->fn((*(s32 *)&D_L01_001E001C) + (v->index << 8), v->w18, a1);
        } else {
            it->fn((*(s32 *)&D_L01_001E001C) + (v->index << 8), arg, a1);
        }
    }
}
/* localdecomp:end func_L01_00327678 */

/* localdecomp:start func_L01_00327728 */
typedef struct Fn_00327728 {
    u8 pad0[0x10];
    void (*f10)(u8 *, s32, u8 *);
} Fn_00327728;
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 16");

void func_L01_00327728(s32 a0) {
    u8 *v = (u8 *)func_L01_003257E8();
    u8 *vars = *(u8 **)(v + 0x68);
    Fn_00327728 *fn;

    if (*(s32 *)(vars + 0x14) != -1) {
        fn = ((Fn_00327728 * (*)(s32, s32, s32))func_L01_0043B568)(0x1ADD, 0, 0x68);
        fn->f10(D_L01_001E001C + (*(s32 *)(vars + 0x14) << 8), a0, D_L01_001E001C);
    }
}
/* localdecomp:end func_L01_00327728 */

/* localdecomp:start func_L01_00327798 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern u8 *D_L01_001E001C;

typedef struct {
    u8 p0[0x14];
    s32 index;
} Vars_00327798;
typedef struct {
    u8 p0[0x68];
    Vars_00327798 *vars;
} Obj_00327798;
typedef struct {
    u8 p0[0x38];
    void (*fn)(s32, s32, f32);
} Iface_00327798;

void func_L01_00327798(s32 a0, f32 f) {
    Obj_00327798 *o = (Obj_00327798 *)func_L01_003257E8();
    Vars_00327798 *v = o->vars;
    Iface_00327798 *it;

    if (v->index != -1) {
        it = (Iface_00327798 *)((s32 (*)(s32, s32, s32))func_L01_0043B568)(0x1ADD, 0, 0x68);
        it->fn((*(s32 *)&D_L01_001E001C) + (v->index << 8), a0, f);
    }
}
/* localdecomp:end func_L01_00327798 */

/* localdecomp:start func_L01_00327818 */
typedef struct { u8 pad[0x20]; s32 (*first)(u8 *); s32 (*second)(u8 *); } Table_00327818;
extern u8 *D_L01_001E001C;
s32 func_L01_00327818(s32 arg) {
    extern s32 func_L01_003257E8(void);
    extern s32 func_L01_0043B568(s32, s32, s32);
    u8 *vars;
    Table_00327818 *table;
    s32 value;
    if (arg == -3) return 0;
    vars = *(u8 **)((u8 *)func_L01_003257E8() + 0x68);
    if (*(s32 *)(vars + 0x14) == -1) return -1;
    table = (Table_00327818 *)func_L01_0043B568(0x1ADD, 0, 0x68);
    value = table->first(D_L01_001E001C + (*(s32 *)(vars + 0x14) << 8));
    if (value == -1 && arg != -1) {
        value = table->second(D_L01_001E001C + (*(s32 *)(vars + 0x14) << 8));
    }
    if (arg == -2) return value == *(s32 *)(vars + 0x18);
    return value == arg;
}
/* localdecomp:end func_L01_00327818 */

/* localdecomp:start func_L01_003278F8 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_0043B568(s32, s32, s32);
extern u8 *D_L01_001E001C;

s32 func_L01_003278F8(void) {
    u8 *s0 = *(u8 **)((u8 *)func_L01_003257E8() + 0x68);
    u8 *o;
    s32 base;

    if (*(s32 *)(s0 + 0x14) == -1) {
        return 0;
    }
    o = (u8 *)func_L01_0043B568(0x1ADD, 0, 0x68);
    base = (s32)D_L01_001E001C;
    return ((s32 (*)(s32))(*(s32 *)(o + 0x3C)))(
        base + (*(s32 *)(s0 + 0x14) << 8));
}
/* localdecomp:end func_L01_003278F8 */

/* localdecomp:start func_L01_00327968 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_L01_003257E8(void);
extern u8 *D_L01_001E001C;

s32 func_L01_00327968(void) {
    u8 *o = *(u8 **)(((u8 * (*)(void))func_L01_003257E8)() + 104);
    Vt_00327968 *vt;

    if (*(s32 *)(o + 20) == -1) {
        return 1;
    }
    vt = ((Vt_00327968 * (*)(s32, s32, s32))func_L01_0043B568)(6877, 0, 104);
    return vt->fn40(D_L01_001E001C + (*(s32 *)(o + 20) << 8));
}
/* localdecomp:end func_L01_00327968 */

/* localdecomp:start func_L01_003279D8 */
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern s32 func_L01_003257E8(void);
extern u8 *D_L01_001E001C;

s32 func_L01_003279D8(s32 a0) {
    O_003279D8 *o = ((O_003279D8 * (*)(s32))func_L01_003257E8)(a0);
    V_003279D8 *v = o->vars;
    I_003279D8 *it;

    if (v->index == -1) {
        return 0;
    }
    it = (I_003279D8 *)func_L01_0043B568(6877, 0, 104);
    if (a0 == -2) {
        return it->fn44((s32)(D_L01_001E001C + (v->index << 8)), v->w18);
    }
    return it->fn44((s32)(D_L01_001E001C + (v->index << 8)), a0);
}
/* localdecomp:end func_L01_003279D8 */

/* localdecomp:start func_L01_00327A78 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern u8 *D_L01_001E001C;

s32 func_L01_00327A78(void) {
    Vars_00327A78 *v = ((Obj_00327A78 *)func_L01_003257E8())->vars;
    Iface_00327A78 *it;

    if (v->index == -1) {
        return 1;
    }
    it = (Iface_00327A78 *)func_L01_0043B568(6877, 0, 104);
    return it->fn48((s32)(D_L01_001E001C + (v->index << 8)));
}
/* localdecomp:end func_L01_00327A78 */

/* localdecomp:start func_L01_00327AE8 */
extern s32 func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern s32 func_L01_003257E8(void);
extern u8 *D_L01_001E001C;




void func_L01_00327AE8(int arg) {
    Vars *v = ((Obj * (*)(int))((u8 * (*)(void *))func_L01_003257E8))(arg)->vars;
    Iface *it;

    if (v->index != -1) {
        it = ((Iface * (*)(int, int, int))func_L01_0043B568)(6877, 0, 104);
        it->fn96((*(int *)&D_L01_001E001C) + v->index * 256);
        if (arg != 0) {
            it->fn88((*(int *)&D_L01_001E001C) + v->index * 256);
        }
    }
}
/* localdecomp:end func_L01_00327AE8 */

/* localdecomp:start func_L01_00327B78 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_00449050(void *);
extern s32 func_L01_003B3470(s32, s32);

s32 func_L01_00327B78(void) {
    u8 *p = ((u8 * (*)(void))func_L01_00449050)();

    if (p == 0) return 0;
    if (*(s32 *)(*(u8 **)(((u8 * (*)(void))func_L01_003257E8)() + 104) + 48) == 0) return 0;
    return func_L01_003B3470(*(s32 *)(p + 8), 1);
}
/* localdecomp:end func_L01_00327B78 */

/* localdecomp:start func_L01_00327BD8 */
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_003257E8(void);
extern u8 D_001A4C60[];
void func_L01_00327BD8(void) {
    char *v = ((char * (*)(void))func_L01_003257E8)();
    ((void (*)(void *, s32))func_L01_00456500)(((char *)&D_001A4C60), *(s32 *)(*(char **)(v + 104) + 36));
}
/* localdecomp:end func_L01_00327BD8 */

/* localdecomp:start func_L01_00327C08 */
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_003257E8(void);
void func_L01_00327C08(u8 *a0) {
    u8 *v = ((u8 * (*)(void *))func_L01_003257E8)(a0);
    ((void (*)(void *, s32))func_L01_00456500)(a0, *(s32 *)(*(u8 **)(v + 104) + 36));
}
/* localdecomp:end func_L01_00327C08 */

/* localdecomp:start func_L01_00327C40 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_00329638(u8 *, u8 *);
extern s32 func_L01_00329700(u8 *a0, u8 *a1);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L01_00327C40(void) {
    u8 *m = (u8 *)func_L01_003257E8();
    u8 *v = *(u8 **)(m + 0x68);
    if (func_L01_00329638(m, v) != 0) {
        func_003A5348(0x14, 0, 0);
        func_L01_004450F0(m, 8, -1);
        return 1;
    }
    if (func_L01_00329700(m, v) != 0) {
        func_L01_004450F0(m, 5, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00327C40 */

/* localdecomp:start func_L01_00327CD0 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_00328F00(u8 *);

s32 func_L01_00327CD0(void) {
    s32 n = 0;
    u8 *o = *(u8 **)(*(u8 **)(((u8 * (*)(void))func_L01_003257E8)() + 104) + 4);

    while (o) {
        u8 *b = *(u8 **)(o + 104);
        if (func_L01_00328F00(o)) n++;
        o = *(u8 **)(b + 108);
    }
    return n;
}
/* localdecomp:end func_L01_00327CD0 */

/* localdecomp:start func_L01_00327D30 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_00328F00(u8 *);
extern s32 func_L01_00329338(u8 *);
extern s32 *func_003B9BD0(s32);
extern char *func_003B9E30(s32 *, s32, s32);
extern void func_L01_00498948(s32 *, s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern char D_L01_001DCA18[];
extern char D_L01_001DCA20[];

void func_L01_00327D30(void) {
    u8 *obj;
    u8 *vars;
    s32 i;
    char *buf;

    i = 0;
    obj = *(u8 **)(*(u8 **)(((u8 * (*)(void))func_L01_003257E8)() + 104) + 4);
    while (obj != 0) {
        vars = *(u8 **)(obj + 104);
        if (func_L01_00328F00(obj) == 0) {
            obj = *(u8 **)(vars + 108);
            continue;
        }
        if (*(s32 *)(vars + 28) != 0) {
            buf = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(buf, D_L01_001DCA18, func_00381FF0(*(s32 *)(vars + 28)));
        } else {
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001DCA20);
        }
        if (func_L01_00329338(obj) != 0) {
            func_L01_00498948(func_003B9BD0(0), i, 4);
        } else {
            func_L01_00498948(func_003B9BD0(0), i, 0);
        }
        obj = *(u8 **)(vars + 108);
        i++;
    }
}
/* localdecomp:end func_L01_00327D30 */

/* localdecomp:start func_L01_00327E70 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_00328F00(u8 *);
s32 func_L01_00327E70(void) {
    s32 n = 0;
    u8 *l = *(u8 **)(((u8 * (*)(void))func_L01_003257E8)() + 104);
    u8 *o = *(u8 **)(l + 4);
    while (o) {
        u8 *b = *(u8 **)(o + 104);
        if (!func_L01_00328F00(o)) {
            o = *(u8 **)(b + 108);
        } else {
            if (o == *(u8 **)(l + 8)) {
                return n;
            }
            o = *(u8 **)(b + 108);
            n++;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00327E70 */

/* localdecomp:start func_L01_00327F00 */
typedef struct { u8 pad[0x18]; s32 (*first)(u8 *); s32 (*second)(u8 *); } I_00327F00;
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern char D_L01_001DCA20[], D_L01_001DCA28[], D_L01_001DCA30[];
extern char D_L01_001E1860[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1860, 4");
void func_L01_00327F00(void) {
    extern s32 func_L01_003257E8(void);
    extern s32 *func_003B9BD0(s32);
    extern s32 func_003B9C58(s32 *);
    extern s32 func_L01_00328F00(u8 *);
    extern s32 func_L01_00517190(s32, s32);
    extern char *func_00381FF0(s32);
    extern s32 func_L01_00516FD8(s32, char *);
    extern void func_L01_00516AA0(s32, s32, s32);
    extern s32 func_L01_003291D0(u8 *);
    extern s32 func_0011B2E8(char *, char *, ...);
    extern s32 func_L01_0043B568(s32, s32, s32);
    u8 *state;
    u8 *obj;
    u8 *vars;
    s32 i=0;
    s32 selected;
    I_00327F00 *iface;
    state=*(u8 **)((u8 *)func_L01_003257E8()+0x68);
    selected=func_003B9C58(func_003B9BD0(0));
    obj=*(u8 **)(state+4);
    while(obj) {
        if(func_L01_00328F00(obj)) {
            if(i==selected)break;
            i++;
        }
        obj=*(u8 **)(obj+0x68);
        obj=*(u8 **)(obj+0x6C);
    }
    *(u8 **)(state+8)=obj;
    if(obj) {
        vars=*(u8 **)(obj+0x68);
        func_L01_00517190(0x1A0014,*(s32 *)(vars+0x28));
        if(*(s32 *)(vars+0x1C)) {
            func_L01_00516FD8(0x1A0010,func_00381FF0(*(s32 *)(vars+0x20)));
            if(*(s32 *)(vars+0x30))func_L01_00516FD8(0x1A000F,0);
            else func_L01_00516FD8(0x1A000F,func_00381FF0(0xCA8));
        } else {
            func_L01_00516FD8(0x1A000F,D_L01_001DCA28);
            func_L01_00516FD8(0x1A0010,D_L01_001DCA20);
        }
        if(*(s32 *)(vars+0x24))
            func_L01_00516FD8(0x1A0011,func_00381FF0(*(s32 *)(vars+0x24)));
        else func_L01_00516FD8(0x1A0011,0);
        if(*(s32 *)(vars+0x54)) {
            func_L01_00516AA0(0x1A0015,1,1);
            func_L01_00516AA0(0x1A0017,1,1);
            func_0011B2E8(D_L01_001E1860,D_L01_001DCA30,func_L01_003291D0(*(u8 **)(state+8)));
            func_L01_00516FD8(0x1A0016,D_L01_001E1860);
        } else {
            func_L01_00516AA0(0x1A0015,1,0);
            func_L01_00516AA0(0x1A0017,1,0);
            func_L01_00516FD8(0x1A0016,0);
        }
    } else {
        func_L01_00516FD8(0x1A000F,0);
        func_L01_00516FD8(0x1A0011,0);
        func_L01_00516AA0(0x1A0015,1,0);
        func_L01_00516AA0(0x1A0017,1,0);
        func_L01_00516FD8(0x1A0016,0);
    }
    if(D_001D545C==12 || D_001D545C==18) {
        func_L01_00516AA0(0x1A0008,1,1);
        func_L01_00516FD8(0x1A0008,func_00381FF0(0x100));
    } else if(D_001D545C==20 || D_001D545C==26 || D_001D545C==29) {
        func_L01_00516AA0(0x1A0008,1,0);
    } else if(*(s32 *)(state+0x14)!=-1) {
        u8 *moby=D_L01_001E001C+(*(s32 *)(state+0x14)<<8);
        iface=(I_00327F00 *)func_L01_0043B568(0x1ADD,0,0x68);
        if(iface->first(moby) || iface->second(moby)) {
            func_L01_00516AA0(0x1A0008,1,1);
            func_L01_00516FD8(0x1A0008,func_00381FF0(0x177));
        } else func_L01_00516AA0(0x1A0008,1,0);
    } else func_L01_00516AA0(0x1A0008,1,0);
}
/* localdecomp:end func_L01_00327F00 */

/* localdecomp:start func_L01_00328248 */
extern s32 func_L01_003257E8(void);
extern s32 func_L01_003294A0(s32, List_003290D8 *, s32);

void func_L01_00328248(s32 a0) {
    s32 v = func_L01_003257E8();
    func_L01_003294A0(v, *(List_003290D8 **)(v + 0x68), a0);
}
/* localdecomp:end func_L01_00328248 */

INCLUDE_ASM("asm/levels", func_L01_00328280);

/* localdecomp:start func_L01_00328428 */
extern void func_L01_00517918(s32);
void func_L01_00328428(s32 a0, char *a1) {
    if (*(s32 *)(*(char **)(*(char **)(a1 + 48) + 104) + 48) == 0) {
        func_L01_00517918(21);
    }
}
/* localdecomp:end func_L01_00328428 */

INCLUDE_ASM("asm/levels", func_L01_00328458);

INCLUDE_ASM("asm/levels", func_L01_00328598);

INCLUDE_ASM("asm/levels", func_L01_003287D8);

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

INCLUDE_ASM("asm/levels", func_L01_003290D0);

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

INCLUDE_ASM("asm/levels", func_L01_003291D0);

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

INCLUDE_ASM("asm/levels", func_L01_003298C8);

INCLUDE_ASM("asm/levels", func_L01_00329AD0);

/* localdecomp:start func_L01_00329E70 */
extern void func_L01_004450F0(void *, s32, s32);



void func_L01_00329E70(Obj_00329E70 *obj) {
    Sub *p;
    int i, j;

    if (obj->b32 == 0) {
        p = obj->p104;
        if (p->b33 != 0) {
            j = 0;
            for (i = 0; i < 4; i++) {
                if (p->w[i] != -1) {
                    p->b160[j] = i;
                    j++;
                }
            }
            p->w164 = 0;
        }
        obj->b48 = 255;
        obj->h52 |= 2;
        ((void (*)(Obj_00329E70 *, int, int))func_L01_004450F0)(obj, 1, -1);
    }
}
/* localdecomp:end func_L01_00329E70 */

/* localdecomp:start func_L01_00329F00 */
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0100;
extern void func_L01_003362B0(u8 *a0, s32 a1);
extern void func_L01_00335F28(u8 *a0, s32 a1);
void func_L01_00329F00(u8 *a0, u8 *a1) {
    u8 *pv;
    u8 *pv1;
    s8 *list;
    u8 *f;
    u8 *src;
    u8 *dst;
    s32 i;
    s32 k;

    pv = *(u8 **)(a0 + 104);
    pv1 = *(u8 **)(a1 + 104);
    list = (s8 *)(pv + 160);
    for (i = 0, f = pv + 16; i < 24; i++, f++) {
        if (*f == 0) {
            continue;
        }
        if (i == 17) {
            k = *(s32 *)(pv + 164);
            if (k >= 4 || list[k] == -1) {
                *(s32 *)(pv + 164) = 0;
            }
            if (*(s32 *)(pv + 164) != -1) {
                func_L01_00329F00(D_L01_001E001C + (((s32 *)pv)[list[*(s32 *)(pv + 164)]] << 8), a1);
                *(s32 *)(pv + 164) += 1;
            }
        } else if (i == 18) {
            if (*(s32 *)(pv1 + 76) != -1) {
                func_L01_00329F00(D_L01_001E001C + (*(s32 *)(pv1 + 76) << 8), a1);
            }
        } else if (i == 19) {
            func_L01_003362B0(a1, 0);
            return;
        } else if (i == 21) {
            k = *(s32 *)(pv + 100);
            if (k != -1) {
                src = D_L01_001E0100 + (k << 7);
                dst = D_L01_001E001C + (*(s32 *)(pv1 + 80) << 8);
                *(s128_329AA8 *)(dst + 16) = *(s128_329AA8 *)(src + 48);
                *(s128_329AA8 *)(dst + 240) = *(s128_329AA8 *)(src + 112);
            }
            func_L01_00329F00(D_L01_001E001C + (*(s32 *)pv << 8), a1);
        } else {
            *(s32 *)(pv1 + 76) = (*(u8 **)(a1 + 184) - D_L01_001E001C) >> 8;
            *(u8 **)(a1 + 184) = a0;
            func_L01_00335F28(a1, i);
            return;
        }
    }
}
/* localdecomp:end func_L01_00329F00 */

/* localdecomp:start func_L01_0032A0C8 */
/* The integer abs is the game's abs_asm (include/vu0.h): retail runs it on a value it has just
   tested, which the compiler would fold away. */
#include "vu0.h"
extern u8 *D_L01_001E001C;

void func_L01_0032A0C8(void *arg0, u8 *arg1, s32 arg2) {
    u8 *pv = *(u8 **)((u8 *)arg0 + 0x68);
    s32 n = *(s8 *)(pv + arg2 + 0x30);

    if (n > 0) {
        n = abs_asm(n);
        func_L01_00329F00(D_L01_001E001C + (*(s32 *)(pv + n * 4 - 4) << 8), arg1);
    }
}
/* localdecomp:end func_L01_0032A0C8 */

/* localdecomp:start func_L01_0032A118 */
/* The integer abs is the game's abs_asm (include/vu0.h): retail runs it on a value it has just
   tested, which the compiler would fold away. */
#include "vu0.h"
extern u8 *D_L01_001E001C;

void func_L01_0032A118(void *arg0, u8 *arg1, s32 arg2) {
    u8 *pv = *(u8 **)((u8 *)arg0 + 0x68);
    s32 n = *(s8 *)(pv + arg2 + 0x30);

    if (n < 0) {
        n = abs_asm(n);
        func_L01_00329F00(D_L01_001E001C + (*(s32 *)(pv + n * 4 - 4) << 8), arg1);
    }
}
/* localdecomp:end func_L01_0032A118 */

INCLUDE_ASM("asm/levels", func_L01_0032A168);

/* localdecomp:start func_L01_0032AD70 */
extern s32 D_001D545C;
extern s16 **D_L01_002AF350[];

s32 func_L01_0032AD70(u8 *a0) {
    s16 **tbl = D_L01_002AF350[D_001D545C];
    u8 *v = *(u8 **)(a0 + 0x68);
    s16 *p;

    if (tbl != 0) {
        p = tbl[v[8]];
        if (p != 0) {
            return *p;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0032AD70 */

/* localdecomp:start func_L01_0032ADC0 */
extern u8 D_L01_001DCE18;
__asm__(".extern D_L01_001DCE18, 4");

u8 *func_L01_0032ADC0(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return &D_L01_001DCE18;
    }
    return 0;
}
/* localdecomp:end func_L01_0032ADC0 */

LINKER_REMNANT("asm/levels", func_L01_0032ADE0);

/* localdecomp:start func_L01_0032ADE8 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_0032ADE8(void) {
}
/* localdecomp:end func_L01_0032ADE8 */
