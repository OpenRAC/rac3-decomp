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

/* localdecomp:start func_L39_00662748 */
extern u8 D_1A5CD0[];
__asm__(".extern D_L39_0024D75C, 16");
extern s32 D_L39_0024D75C;
extern void func_L39_006629B0(u8 *a0);

void func_L39_00662748(void) {
    N_65FDA0 *p = D_L39_002461F4;
    N_65FDA0 *prev = 0;
    N_65FDA0 *rem = 0;
    while (p) {
        u8 *g = D_1A5CD0;
        if (p->b55 == 0 && p->w4 + (s32)(p->w0 >> 13) <= *(s32 *)(g + 0x128)) {
            N_65FDA0 *n = p->next;
            if (prev == 0) {
                D_L39_002461F4 = n;
            } else {
                prev->next = n;
            }
            p->next = rem;
            rem = p;
            p = n;
        } else {
            prev = p;
            p = p->next;
        }
    }
    while (rem) {
        p = rem;
        if (*(s32 *)((u8 *)rem + 0x50) == -1 || *(s32 *)((u8 *)rem + 0x50) == D_L39_0024D75C) {
            func_L39_006629B0((u8 *)rem);
        }
        rem = rem->next;
        func_L39_00662A18((u8 *)p);
    }
}
/* localdecomp:end func_L39_00662748 */

/* localdecomp:start func_L39_00662830 */
typedef struct S_00662830G { u8 pad0[4]; s32 f4; u8 pad8[0x120]; s32 f128; u8 pad12C[0x44]; s32 f170; u8 pad174[0x660]; u8 b7D4; } S_00662830G;
typedef struct N_00662830 { u8 pad0[0x4C]; s32 f4C; s32 f50; u8 pad54; u8 b55; u8 pad56[2]; struct N_00662830 *next; } N_00662830;
extern N_00662830 *D_001DAAE4_sda;
extern u8 D_1A5CD0[];
__asm__(".extern D_L39_0024D75C, 16");
extern s32 D_L39_0024D75C;
__asm__(".extern D_L39_002405D8, 16");
extern s32 D_L39_002405D8;
extern u32 func_L39_00662BC8(u32 *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00662830(void) {
    N_00662830 *n = D_001DAAE4_sda;
    while (n != 0) {
        if (n->b55 != 0 && ((S_00662830G *)D_1A5CD0)->f128 >= n->f4C) {
            if (n->f50 != D_L39_0024D75C && ((S_00662830G *)D_1A5CD0)->f170 == 0) {
                s32 a = ((S_00662830G *)D_1A5CD0)->b7D4 | 0x40;
                func_0014AD08(a, ((S_00662830G *)D_1A5CD0)->f4, n->f50, D_L39_002405D8, func_L39_00662BC8((u32 *)n), n);
            }
            n->b55 = 0;
        }
        n = n->next;
    }
}
/* localdecomp:end func_L39_00662830 */

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
