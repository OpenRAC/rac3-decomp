#include "common.h"

/* declared by functions of L39_00639350.c, which this file was cut from */
extern s32 func_0038CB00(s16 *timer);
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_0063BDE0 */
typedef struct { u8 pad[0xAA]; s16 t; } S639;
s32 func_L39_0063BDE0(s32 unused, S639 *p) {
    if (p == 0) return 0;
    return p->t == 0x18AB;
}
/* localdecomp:end func_L39_0063BDE0 */

INCLUDE_ASM("asm/levels", func_L39_0063BE00);

/* localdecomp:start func_L39_0063BF40 */
extern s32 func_0038CB00(s16 *timer);
typedef struct {
    char pad0[452];
    int a;
    int b;
} Pad006396F8;

typedef struct {
    char pad0[996];
    unsigned short count;
    char pad3E6[9524 - 998];
    Pad006396F8 *pad;
} Obj006396F8;

extern int func_L39_00639D90(Obj006396F8 *);

void func_L39_0063BF40(Obj006396F8 *o)
{
    if (func_L39_00639D90(o)) {
        ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        return;
    }
    if (o->pad->a & 3) {
        if (o->pad->a & 2)
            o->count++;
        if (o->pad->a & 1)
            o->count++;
    }
    if (o->pad->b & 3) {
        if (o->pad->b & 2)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        if (o->pad->b & 1)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
    }
}
/* localdecomp:end func_L39_0063BF40 */

INCLUDE_ASM("asm/levels", func_L39_0063C000);

INCLUDE_ASM("asm/levels", func_L39_0063C468);

INCLUDE_ASM("asm/levels", func_L39_0063C840);

/* localdecomp:start func_L39_0063D0F0 */
s32 func_L39_0063D0F0(s32 arg0, s32 arg1) {
    return arg1;
}
/* localdecomp:end func_L39_0063D0F0 */

INCLUDE_ASM("asm/levels", func_L39_0063D0F8);

/* localdecomp:start func_L39_0063D240 */
void func_L39_006770F8(u8);

void func_L39_0063D240(void *arg0, s32 arg1) {
    if ((((*(u8 *)((u8 *)arg0 + 0x1A14)) != 0) || (arg1 != 0)) && ((*(s32 *)((u8 *)arg0 + 0x251C)) != 0)) {
        *(s32 *)((u8 *)arg0 + 0x251C) = 0;
        *(s8 *)((u8 *)arg0 + 0x24AA) = 1;
        func_L39_006770F8((*(u8 *)((u8 *)arg0 + 0x24C9)));
        if ((*(s16 *)((u8 *)arg0 + 0x24A8)) == 0) {
            *(s16 *)((u8 *)arg0 + 0x24A8) = 0x11;
        }
    }
}
/* localdecomp:end func_L39_0063D240 */

INCLUDE_ASM("asm/levels", func_L39_0063D2A8);

INCLUDE_ASM("asm/levels", func_L39_0063E3D0);
