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
extern void func_003C7C38(u8 *a0);

/* localdecomp:start func_L01_003298C8 */
typedef int Q_003298C8 __attribute__((mode(TI)));
typedef struct {
    Q_003298C8 origin;
    f32 f10;
    f32 f14;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
    u32 colours[4];
    s32 kind;
    s32 w34;
    s32 w38;
    s16 h3C;
    s16 h3E;
} Vars_003298C8;
typedef struct {
    u8 p0[0x10];
    Q_003298C8 pos;
    u8 p20[3];
    u8 b23;
    u8 p24[8];
    f32 scale;
    u8 b30;
    u8 b31;
    s16 h32;
    u8 p34[0x34];
    Vars_003298C8 *vars;
    u8 p6C[0xC];
    s32 w78;
} Moby_003298C8;
extern Moby_003298C8 *func_003C24B0(s32, s32);
extern void func_0038CC88(void *, void *, s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
u8 *func_L01_003298C8(Q_003298C8 *pos, Q_003298C8 *origin, s32 life, s32 kind, s32 a4, s32 a5, void *colours, s32 a7, s16 a8, s16 a9, f32 scale, f32 opacity) {
    Moby_003298C8 *moby = func_003C24B0(0x1A50, 0x80);
    Vars_003298C8 *vars;
    s32 size;
    if (moby) {
        vars = moby->vars;
        moby->b30 = 0xFF;
        moby->h32 = 0xFF;
        moby->b31 = 1;
        moby->b23 = 0x80;
        vars->w34 = a4;
        vars->w38 = a7;
        moby->scale *= scale;
        vars->h3C = a8;
        vars->h3E = a9;
        if (colours) func_0038CC88(vars->colours, colours, 0x10);
        else {
            vars->colours[0] = 0x2FFFFFFF;
            vars->colours[1] = 0x2F808080;
            vars->colours[2] = 0x2FC0C0C0;
            vars->colours[3] = 0x2F404040;
        }
        func_L01_0043B9E8(moby, 0x7F, 0x7F, 0x7F);
        moby->pos = *pos;
        vars->origin = *origin;
        vars->f10 = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        vars->f14 = func_003824E0(0.12566371262073517f, 0.25132742524147034f);
        vars->h18 = life;
        vars->h1A = life;
        vars->kind = kind;
        if (kind == 3) vars->kind = func_00382468(3);
        size = moby->scale * 128.0f;
        vars->h1E = opacity * 128.0f;
        vars->h1C = size;
        moby->w78 = a5;
        func_003C7C38((u8 *)moby);
    }
    return (u8 *)moby;
}
/* localdecomp:end func_L01_003298C8 */
