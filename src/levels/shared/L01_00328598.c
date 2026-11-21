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

INCLUDE_ASM("asm/levels", func_L01_003287D8);
