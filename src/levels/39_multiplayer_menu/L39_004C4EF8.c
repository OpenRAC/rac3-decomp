#include "common.h"

/* localdecomp:start func_L39_004C4EF8 */
extern s32 D_L39_00465100[];

s32 func_L39_004C4EF8(void) {
    D_L39_00465100[0] = 0;
    return 1;
}
/* localdecomp:end func_L39_004C4EF8 */

INCLUDE_ASM("asm/levels", func_L39_004C4F08);

/* localdecomp:start func_L39_004C4F30 */
extern s32 D_L39_00465100[];

s32 func_L39_004C4F30(s64 arg0) {
    return D_L39_00465100[0] & arg0;
}
/* localdecomp:end func_L39_004C4F30 */

INCLUDE_ASM("asm/levels", func_L39_004C4F48);

INCLUDE_ASM("asm/levels", func_L39_004C5000);

INCLUDE_ASM("asm/levels", func_L39_004C50B8);

INCLUDE_ASM("asm/levels", func_L39_004C52B0);

INCLUDE_ASM("asm/levels", func_L39_004C57B0);

INCLUDE_ASM("asm/levels", func_L39_004C59D8);

INCLUDE_ASM("asm/levels", func_L39_004C5B80);

INCLUDE_ASM("asm/levels", func_L39_004C5C88);

INCLUDE_ASM("asm/levels", func_L39_004C5F70);

INCLUDE_ASM("asm/levels", func_L39_004C6020);

/* localdecomp:start func_L39_004C6098 */
s32 func_L39_004C6098(s32 arg0) {
    switch (arg0) {
    case 1: return 0xCB;
    case 2: return 0xCA;
    case 4: return 0xC9;
    case 6: return 0xCC;
    }
    return 0xFD;
}
/* localdecomp:end func_L39_004C6098 */

INCLUDE_ASM("asm/levels", func_L39_004C6100);

INCLUDE_ASM("asm/levels", func_L39_004C6120);

INCLUDE_ASM("asm/levels", func_L39_004C6250);

INCLUDE_ASM("asm/levels", func_L39_004C6BA0);

INCLUDE_ASM("asm/levels", func_L39_004C6E08);

INCLUDE_ASM("asm/levels", func_L39_004C70F8);

INCLUDE_ASM("asm/levels", func_L39_004C74F8);

INCLUDE_ASM("asm/levels", func_L39_004C7CD0);

INCLUDE_ASM("asm/levels", func_L39_004C8088);

INCLUDE_ASM("asm/levels", func_L39_004C8110);

INCLUDE_ASM("asm/levels", func_L39_004C8568);

INCLUDE_ASM("asm/levels", func_L39_004C8748);

INCLUDE_ASM("asm/levels", func_L39_004C8950);

INCLUDE_ASM("asm/levels", func_L39_004C8C10);

INCLUDE_ASM("asm/levels", func_L39_004C8E30);

INCLUDE_ASM("asm/levels", func_L39_004C91C0);

INCLUDE_ASM("asm/levels", func_L39_004C9368);

INCLUDE_ASM("asm/levels", func_L39_004C9568);

INCLUDE_ASM("asm/levels", func_L39_004C9678);

INCLUDE_ASM("asm/levels", func_L39_004C9E08);

INCLUDE_ASM("asm/levels", func_L39_004C9F50);

INCLUDE_ASM("asm/levels", func_L39_004CA000);

INCLUDE_ASM("asm/levels", func_L39_004CA180);

/* localdecomp:start func_L39_004CA1F8 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* from rac4-decomp's func_L00_00505FF8, renamed */
s32 func_L39_004CA1F8(void) {
    func_L39_004BC6C8(0x10, 0x6D, 0xE, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004CA1F8 */

/* localdecomp:start func_L39_004CA228 */
extern s32 func_L39_004CA268(s32);
extern s32 *func_L01_003E4008(s32);

/* from rac4-decomp's func_L00_00506028 */
s32 func_L39_004CA228(s32 arg0) {
    s32 c = (u32)(arg0 + 1) < 2U;
    s32 r;
    if (c) {
        r = func_L39_004CA268(*func_L01_003E4008(c));
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_004CA228 */

INCLUDE_ASM("asm/levels", func_L39_004CA268);

INCLUDE_ASM("asm/levels", func_L39_004CA328);

INCLUDE_ASM("asm/levels", func_L39_004CA3D0);

/* localdecomp:start func_L39_004CA568 */
typedef struct N_4CA568 {
    u8 pad0[0xC];
    struct N_4CA568 *next;
    struct N_4CA568 *prev;
} N_4CA568;

/* from rac4-decomp's func_L00_00506368 */
void func_L39_004CA568(N_4CA568 **head, N_4CA568 *node, N_4CA568 **tail) {
    N_4CA568 *prev;
    N_4CA568 *next;
    if (node != *tail) {
        if (node == *head) {
            *head = node->next;
        }
        prev = node->prev;
        if (prev != 0) {
            prev->next = node->next;
        }
        next = node->next;
        if (next != 0) {
            next->prev = node->prev;
        }
        (*tail)->next = node;
        node->prev = *tail;
        node->next = 0;
        *tail = node;
    }
}
/* localdecomp:end func_L39_004CA568 */

INCLUDE_ASM("asm/levels", func_L39_004CA5D0);

INCLUDE_ASM("asm/levels", func_L39_004CB680);

INCLUDE_ASM("asm/levels", func_L39_004CB698);

INCLUDE_ASM("asm/levels", func_L39_004CB730);

INCLUDE_ASM("asm/levels", func_L39_004CB8D0);

INCLUDE_ASM("asm/levels", func_L39_004CBA18);

INCLUDE_ASM("asm/levels", func_L39_004CBAA8);

INCLUDE_ASM("asm/levels", func_L39_004CBB38);

INCLUDE_ASM("asm/levels", func_L39_004CBCF0);

INCLUDE_ASM("asm/levels", func_L39_004CBDC0);

/* localdecomp:start func_L39_004CBE68 */
typedef struct S_004CBE68 {
    u8 pad0[0x28];
    struct S_004CBE68 *f28;
    struct S_004CBE68 *f2C;
    u8 pad30[0xC4 - 0x30];
    struct S_004CBE68 *fC4;
    struct S_004CBE68 *fC8;
} S_004CBE68;

void func_L39_004CBE68(S_004CBE68 *a0, S_004CBE68 *a1)
{
    S_004CBE68 *next = a1->fC8;
    S_004CBE68 *prev;

    if (next != 0 && (prev = a1->fC4) != 0) {
        if (next == (S_004CBE68 *)&a0->f2C) {
            if (prev == (S_004CBE68 *)&a0->f28) {
                a0->f28 = 0;
                a0->f2C = 0;
            } else {
                a0->f2C = prev;
                a1->fC4->fC8 = next;
            }
        } else if (prev == (S_004CBE68 *)&a0->f28) {
            a0->f28 = next;
            a1->fC8->fC4 = prev;
        } else {
            next->fC4 = prev;
            a1->fC4->fC8 = a1->fC8;
        }
        a1->fC8 = 0;
        a1->fC4 = 0;
    }
}
/* localdecomp:end func_L39_004CBE68 */

INCLUDE_ASM("asm/levels", func_L39_004CBEE0);

INCLUDE_ASM("asm/levels", func_L39_004CBF60);

INCLUDE_ASM("asm/levels", func_L39_004CBF70);

INCLUDE_ASM("asm/levels", func_L39_004CBFC8);

INCLUDE_ASM("asm/levels", func_L39_004CC018);

INCLUDE_ASM("asm/levels", func_L39_004CC088);

INCLUDE_ASM("asm/levels", func_L39_004CC0B0);

INCLUDE_ASM("asm/levels", func_L39_004CC178);

INCLUDE_ASM("asm/levels", func_L39_004CC190);

INCLUDE_ASM("asm/levels", func_L39_004CC228);

INCLUDE_ASM("asm/levels", func_L39_004CC2C8);

INCLUDE_ASM("asm/levels", func_L39_004CC3E0);

/* localdecomp:start func_L39_004CC408 */
s32 func_L39_004EEFF0(s32, s32);
s32 func_L39_004CC408(s32 *arg0) {
    s32 temp_a1;

    if ((arg0 == 0) || (temp_a1 = *arg0, (temp_a1 <= 0))) {
        return 0;
    }
    return func_L39_004EEFF0((s32) arg0, temp_a1 - 1);
}
/* localdecomp:end func_L39_004CC408 */

INCLUDE_ASM("asm/levels", func_L39_004CC440);

INCLUDE_ASM("asm/levels", func_L39_004CC480);

INCLUDE_ASM("asm/levels", func_L39_004CC510);

INCLUDE_ASM("asm/levels", func_L39_004CC538);

INCLUDE_ASM("asm/levels", func_L39_004CC5B8);

INCLUDE_ASM("asm/levels", func_L39_004CC718);

INCLUDE_ASM("asm/levels", func_L39_004CC7A8);

INCLUDE_ASM("asm/levels", func_L39_004CC800);

INCLUDE_ASM("asm/levels", func_L39_004CC810);

INCLUDE_ASM("asm/levels", func_L39_004CCBD8);

INCLUDE_ASM("asm/levels", func_L39_004CCD18);
