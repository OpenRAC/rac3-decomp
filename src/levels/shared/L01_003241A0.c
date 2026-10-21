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

INCLUDE_ASM("asm/levels", func_L01_003241A0);

INCLUDE_ASM("asm/levels", func_L01_00324E50);

INCLUDE_ASM("asm/levels", func_L01_003250A8);

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

INCLUDE_ASM("asm/levels", func_L01_00325570);

INCLUDE_ASM("asm/levels", func_L01_00325708);

/* localdecomp:start func_L01_003257E8 */
extern s32 D_L01_001DCA10;
s32 func_L01_003257E8(void) {
    return D_L01_001DCA10;
}
/* localdecomp:end func_L01_003257E8 */

INCLUDE_ASM("asm/levels", func_L01_003257F0);

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

INCLUDE_ASM("asm/levels", func_L01_00325A40);

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

INCLUDE_ASM("asm/levels", func_L01_00325AD8);

INCLUDE_ASM("asm/levels", func_L01_00325B18);

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

INCLUDE_ASM("asm/levels", func_L01_00325F60);

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

INCLUDE_ASM("asm/levels", func_L01_00326770);

INCLUDE_ASM("asm/levels", func_L01_00326840);

INCLUDE_ASM("asm/levels", func_L01_00326898);

INCLUDE_ASM("asm/levels", func_L01_00326A10);

INCLUDE_ASM("asm/levels", func_L01_00326AF0);

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

INCLUDE_ASM("asm/levels", func_L01_00326DD0);

INCLUDE_ASM("asm/levels", func_L01_00326E50);

INCLUDE_ASM("asm/levels", func_L01_00327038);

INCLUDE_ASM("asm/levels", func_L01_003272A8);

INCLUDE_ASM("asm/levels", func_L01_003272F0);

INCLUDE_ASM("asm/levels", func_L01_00327330);

INCLUDE_ASM("asm/levels", func_L01_003273E8);

INCLUDE_ASM("asm/levels", func_L01_00327408);

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

INCLUDE_ASM("asm/levels", func_L01_00327480);

INCLUDE_ASM("asm/levels", func_L01_003274B8);

INCLUDE_ASM("asm/levels", func_L01_00327500);

INCLUDE_ASM("asm/levels", func_L01_00327530);

INCLUDE_ASM("asm/levels", func_L01_00327560);

INCLUDE_ASM("asm/levels", func_L01_003275B0);

INCLUDE_ASM("asm/levels", func_L01_003275D8);

INCLUDE_ASM("asm/levels", func_L01_00327608);

INCLUDE_ASM("asm/levels", func_L01_00327678);

INCLUDE_ASM("asm/levels", func_L01_00327728);

INCLUDE_ASM("asm/levels", func_L01_00327798);

INCLUDE_ASM("asm/levels", func_L01_00327818);

INCLUDE_ASM("asm/levels", func_L01_003278F8);

INCLUDE_ASM("asm/levels", func_L01_00327968);

INCLUDE_ASM("asm/levels", func_L01_003279D8);

INCLUDE_ASM("asm/levels", func_L01_00327A78);

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

INCLUDE_ASM("asm/levels", func_L01_00327C40);

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

INCLUDE_ASM("asm/levels", func_L01_00327F00);

INCLUDE_ASM("asm/levels", func_L01_00328248);

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

INCLUDE_ASM("asm/levels", func_L01_00328F00);

INCLUDE_ASM("asm/levels", func_L01_00328FE8);

INCLUDE_ASM("asm/levels", func_L01_00329038);

INCLUDE_ASM("asm/levels", func_L01_003290D0);

INCLUDE_ASM("asm/levels", func_L01_00329180);

INCLUDE_ASM("asm/levels", func_L01_003291D0);

INCLUDE_ASM("asm/levels", func_L01_00329338);

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

INCLUDE_ASM("asm/levels", func_L01_003294A0);

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

INCLUDE_ASM("asm/levels", func_L01_00329638);

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

INCLUDE_ASM("asm/levels", func_L01_0032A0C8);

INCLUDE_ASM("asm/levels", func_L01_0032A118);

INCLUDE_ASM("asm/levels", func_L01_0032A168);

INCLUDE_ASM("asm/levels", func_L01_0032AD70);

INCLUDE_ASM("asm/levels", func_L01_0032ADC0);

LINKER_REMNANT("asm/levels", func_L01_0032ADE0);

INCLUDE_ASM("asm/levels", func_L01_0032ADE8);
