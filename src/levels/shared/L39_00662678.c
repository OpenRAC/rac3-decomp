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
extern N_65FDA0 *D_L39_001DAAE4;
N_65FDA0 *func_L39_00662678(s32 *key, u32 type, s32 flag) {
    N_65FDA0 *p;
    s32 k = *key;
    for (p = D_L39_001DAAE4; p != 0; p = p->next) {
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
extern N_65FDA0 *D_L39_001DAAE4;
void func_L39_006626E8(N_65FE10 *n) {
    N_65FE10 *prev = 0;
    N_65FE10 *c = (*(N_65FE10 * *)&D_L39_001DAAE4);
    while (c) {
        if (c == n) {
            if (prev == 0) {
                (*(N_65FE10 * *)&D_L39_001DAAE4) = n->next;
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

INCLUDE_ASM("asm/levels", func_L39_006628F0);

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
extern N_65FDA0 *D_L39_001DAAE4;
extern u8 *D_L39_001DAAE0;

u8 *func_L39_006629F8(void) {
    u8 *p = D_L39_001DAAE0;
    D_L39_001DAAE0 = *(u8 **)(p + 88);
    *(u8 **)(p + 88) = (*(u8 * *)&D_L39_001DAAE4);
    (*(u8 * *)&D_L39_001DAAE4) = p;
    return p;
}
/* localdecomp:end func_L39_006629F8 */

/* localdecomp:start func_L39_00662A18 */
extern void func_L39_00662A48(s32 *p);
extern u8 *D_L39_001DAAE0;
void func_L39_00662A18(u8 *a0) {
    ((void (*)(void *))func_L39_00662A48)(a0);
    *(void **)(a0 + 88) = (*(void * *)&D_L39_001DAAE0);
    (*(void * *)&D_L39_001DAAE0) = a0;
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

INCLUDE_ASM("asm/levels", func_L39_00662B18);

INCLUDE_ASM("asm/levels", func_L39_00662B68);

/* localdecomp:start func_L39_00662BC8 */
u32 func_L39_00662BC8(u32 *p) {
    return ((*p >> 4) & 0x3f) + 12;
}
/* localdecomp:end func_L39_00662BC8 */

INCLUDE_ASM("asm/levels", func_L39_00662BE0);

INCLUDE_ASM("asm/levels", func_L39_00662C30);

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

INCLUDE_ASM("asm/levels", func_L39_00665C18);

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
