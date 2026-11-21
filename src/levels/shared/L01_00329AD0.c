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
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_001D545C;
extern u8 *D_L01_001E0100;

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
