#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* localdecomp:start func_L39_00662678 */
extern N_65FDA0 *D_L39_002461F4;
N_65FDA0 *func_L39_00662678(s32 *key, u32 type, s32 flag) {
    N_65FDA0 *p;
    s32 k = *key;
    for (p = D_L39_002461F4; p != 0; p = p->next) {
        if (p->w8 == k && (p->w0 & 0xF) == type) {
            if (flag == 0 || p->b55 != 0) {
                break;
            }
        }
    }
    return p;
}
/* localdecomp:end func_L39_00662678 */

/* localdecomp:start func_L39_006626C8 */
extern N_65FDA0 *func_L39_00662678_006626C8(s32 *key, u32 type, s32 flag);
s32 func_L39_006626C8(void *p, s32 b) {
    return ((s32 (*)(void *, s32, s32))func_L39_00662678_006626C8)(p, b, 0) != 0;
}
/* localdecomp:end func_L39_006626C8 */

/* localdecomp:start func_L39_006626E8 */
extern void func_L39_00662A18(u8 *a0);
extern N_65FDA0 *D_L39_002461F4;
void func_L39_006626E8(N_65FE10 *n) {
    N_65FE10 *prev = 0;
    N_65FE10 *c = (*(N_65FE10 * *)&D_L39_002461F4);
    while (c) {
        if (c == n) {
            if (prev == 0) {
                (*(N_65FE10 * *)&D_L39_002461F4) = n->next;
            } else {
                prev->next = n->next;
            }
            n->next = 0;
            ((void (*)(N_65FE10 *))func_L39_00662A18)(n);
            break;
        }
        prev = c;
        c = c->next;
    }
}
/* localdecomp:end func_L39_006626E8 */

INCLUDE_ASM("asm/levels", func_L39_00662748);

INCLUDE_ASM("asm/levels", func_L39_00662830);

/* localdecomp:start func_L39_006628F0 */
extern u8 D_1A5CD0[];
extern u8 *func_L39_006629F8(void);
extern void func_0038CC88(void *dst, void *src, s32 n);
extern void func_L39_00662BE0(u8 *a0);

u32 func_L39_006628F0(s32 a0, s32 a1, s32 a2, u32 *a3) {
    u8 *p;
    u8 *g = D_1A5CD0;
    u32 w0;
    u32 n = ((*a3 >> 4) & 0x3f) + 12;

    if (*(s32 *)(g + 8) != a2) {
        p = func_L39_006629F8();
        func_0038CC88(p, a3, n);
        w0 = *(u32 *)p;
        *(s32 *)(p + 0x50) = -1;
        if (*(s32 *)(p + 4) + (s32)(w0 >> 13) - *(s32 *)(g + 0x128) < 0) {
            if (w0 & 0xFFFFE000) {
                func_L39_00662BE0(p);
            }
        }
    }
    return n;
}
/* localdecomp:end func_L39_006628F0 */

/* localdecomp:start func_L39_006629B0 */
extern u8 *func_L39_0061D1D8(s32 a0);
void func_L39_006629B0(u8 *a0) {
    u8 *o = func_L39_0061D1D8(*(s32 *)(a0 + 8));
    a0[84] = 0;
    if (o) {
        (*(Fn_6600D8 *)(*(u8 **)(o + 20) + 20))(o, a0);
    }
}
/* localdecomp:end func_L39_006629B0 */

/* localdecomp:start func_L39_006629F8 */
extern N_65FDA0 *D_L39_002461F4;
extern u8 *D_L39_002461F0;

u8 *func_L39_006629F8(void) {
    u8 *p = D_L39_002461F0;
    D_L39_002461F0 = *(u8 **)(p + 88);
    *(u8 **)(p + 88) = (*(u8 * *)&D_L39_002461F4);
    (*(u8 * *)&D_L39_002461F4) = p;
    return p;
}
/* localdecomp:end func_L39_006629F8 */

/* localdecomp:start func_L39_00662A18 */
extern void func_L39_00662A48(s32 *p);
extern u8 *D_L39_002461F0;
void func_L39_00662A18(u8 *a0) {
    ((void (*)(void *))func_L39_00662A48)(a0);
    *(void **)(a0 + 88) = (*(void * *)&D_L39_002461F0);
    (*(void * *)&D_L39_002461F0) = a0;
}
/* localdecomp:end func_L39_00662A18 */

/* localdecomp:start func_L39_00662A48 */
extern void func_0038CB78(void *, s32, s32);

void func_L39_00662A48(s32 *p) {
    p[2] = 0;
    p[1] = 0;
    p[0] = 0;
    func_0038CB78(&p[3], 0xCDCDCDCD, 64);
    p[19] = 0;
    ((u8 *)p)[84] = 0;
    p[20] = -1;
    ((u8 *)p)[85] = 0;
}
/* localdecomp:end func_L39_00662A48 */

/* localdecomp:start func_L39_00662AA0 */
extern void func_0038CC88(void *dst, void *src, s32 n);
void func_L39_00662AA0(u8 *a0, void *a1, s32 a2) {
    func_0038CC88(a0 + 12 + a0[84], a1, a2);
    a0[84] += a2;
    if (((S_6601C8 *)a0)->cap < (u32)a0[84]) {
        ((S_6601C8 *)a0)->cap = a0[84];
    }
}
/* localdecomp:end func_L39_00662AA0 */

/* localdecomp:start func_L39_00662B18 */
typedef struct Buf {
    char pad0[0x54];
    u8 used;
} Buf;

/* from rac4-decomp's func_0053CB20, renamed */
void func_L39_00662B18(Buf *b, void *a, s32 n) {
    func_0038CC88(a, (s32)((char *)b + (b->used + 0xC)), n);
    b->used = b->used + n;
}
/* localdecomp:end func_L39_00662B18 */

/* localdecomp:start func_L39_00662B68 */
typedef struct {
    u32 f0;
    u32 f4;
    char p8[0x44];
    u32 f4C;
} S_662B68_A;
typedef struct {
    u8 pad[0x128];
    u32 tick;
} S_662B68_P;
extern S_662B68_P D_001A5CD0;

/* from rac4-decomp's func_0053CB70 */
void func_L39_00662B68(S_662B68_A *a, s32 b, s32 c)
{
    u32 p = D_001A5CD0.tick;
    a->f4 = p;
    if (c > 0)
        a->f0 = (a->f0 & 0x1fff) |
                ((D_001A5CD0.tick + b + c - p) << 13);
    else
        a->f0 &= 0x1fff;
    a->f4C = D_001A5CD0.tick + b;
}
/* localdecomp:end func_L39_00662B68 */

/* localdecomp:start func_L39_00662BC8 */
u32 func_L39_00662BC8(u32 *p) {
    return ((*p >> 4) & 0x3f) + 12;
}
/* localdecomp:end func_L39_00662BC8 */

/* localdecomp:start func_L39_00662BE0 */
void func_L39_00662BE0(u8 *a0) {
    u32 w = *(u32 *)a0;
    u32 n;
    s32 i;
    if (w & 0x3F0) {
        n = w >> 4;
        n &= 0x3F;
        if (n > 16) {
            n = 16;
        }
        for (i = 0; i < (s32)n; i++) {
        }
    }
}
/* localdecomp:end func_L39_00662BE0 */

/* localdecomp:start func_L39_00662C30 */
extern void func_0038CB78(void *, s32, s32);
extern void *func_L39_00662510(u8 *p);
extern u8 D_L39_0047B338[];

void func_L39_00662C30(u8 *a0) {
    u8 *q;
    func_0038CB78(a0, 0, 0x4DC0);
    func_L39_00662510(a0);
    q = a0 + 0x4760;
    *(u8 **)(a0 + 0x14) = D_L39_0047B338;
    *(u8 **)(a0 + 0x2530) = a0 + 0x4300;
    *(u8 **)(a0 + 0x2534) = q;
    q[0x557] = 0xFF;
    *(s32 *)(a0 + 0x24AC) = 0;
}
/* localdecomp:end func_L39_00662C30 */

INCLUDE_ASM("asm/levels", func_L39_00662C90);

/* localdecomp:start func_L39_00663900 */
extern void func_L39_005C34A8(u8 *a, u8 *b, int c);

void func_L39_00663900(u8 *a0)
{
    *(int *)(*(u8 **)(a0 + 9524) + 428) = *(int *)(*(u8 **)(a0 + 9524) + 840);
    *(int *)(*(u8 **)(a0 + 9524) + 416) = 0;
    *(int *)(*(u8 **)(a0 + 9524) + 444) = *(int *)(*(u8 **)(a0 + 9524) + 432);
    *(int *)(*(u8 **)(a0 + 9524) + 432) = 0;
    func_L39_005C34A8(*(u8 **)(a0 + 9524), *(u8 **)(a0 + 9560) + 3148, 20);
}
/* localdecomp:end func_L39_00663900 */

INCLUDE_ASM("asm/levels", func_L39_00663950);

INCLUDE_ASM("asm/levels", func_L39_00663C80);

INCLUDE_ASM("asm/levels", func_L39_00663DA8);

INCLUDE_ASM("asm/levels", func_L39_00664760);

INCLUDE_ASM("asm/levels", func_L39_00665568);

/* localdecomp:start func_L39_00665C18 */
void func_L39_00665C18(u8 *a0, s32 a1) {
    s32 off = a1 * 0x50;
    if (*(u32 *)(*(u8 **)(a0 + 0x2534) + 0x1A0) & *(u32 *)(a0 + off + 0x460)) {
        a0[off + 0x458] = 1;
    } else {
        a0[off + 0x458] = 0;
    }
}
/* localdecomp:end func_L39_00665C18 */

INCLUDE_ASM("asm/levels", func_L39_00665C50);

/* localdecomp:start func_L39_00665C80 */
s32 func_L39_00665C80(u8 *a0) {
    if ((a0[9567] != 255 && a0[9565] == 23) || (u32)(*(s32 *)(a0 + 19852) - 23) < 3) return 1;
    return 0;
}
/* localdecomp:end func_L39_00665C80 */

/* localdecomp:start func_L39_00665CC0 */
s32 func_L39_00665CC0(u8 *a, s32 k) {
    if ((a[9567] != 255 && a[9565] == 57) || k == *(s32 *)(a + 19852)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00665CC0 */

INCLUDE_ASM("asm/levels", func_L39_00665CF8);

INCLUDE_ASM("asm/levels", func_L39_00666160);

INCLUDE_ASM("asm/levels", func_L39_00666518);

INCLUDE_ASM("asm/levels", func_L39_00666E48);

INCLUDE_ASM("asm/levels", func_L39_00666F58);

/* localdecomp:start func_L39_00666F70 */
s32 func_L39_00666F70(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x32C) == a1;
}
/* localdecomp:end func_L39_00666F70 */
