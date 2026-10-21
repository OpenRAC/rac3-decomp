#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00462978);

LINKER_REMNANT("asm/levels", func_L01_00463030);

INCLUDE_ASM("asm/levels", func_L01_00463038);

INCLUDE_ASM("asm/levels", func_L01_00463218);

INCLUDE_ASM("asm/levels", func_L01_004632D0);

INCLUDE_ASM("asm/levels", func_L01_00463378);

INCLUDE_ASM("asm/levels", func_L01_00463538);

INCLUDE_ASM("asm/levels", func_L01_004637C0);

INCLUDE_ASM("asm/levels", func_L01_004637C8);

INCLUDE_ASM("asm/levels", func_L01_004638C8);

LINKER_REMNANT("asm/levels", func_L01_004639C0);

INCLUDE_ASM("asm/levels", func_L01_004639C8);

LINKER_REMNANT("asm/levels", func_L01_00463A68);

INCLUDE_ASM("asm/levels", func_L01_00463A70);

INCLUDE_ASM("asm/levels", func_L01_00464178);

INCLUDE_ASM("asm/levels", func_L01_00464210);

INCLUDE_ASM("asm/levels", func_L01_004642F0);

LINKER_REMNANT("asm/levels", func_L01_004643F8);

INCLUDE_ASM("asm/levels", func_L01_00464400);

LINKER_REMNANT("asm/levels", func_L01_00464550);

INCLUDE_ASM("asm/levels", func_L01_00464558);

INCLUDE_ASM("asm/levels", func_L01_00464690);

INCLUDE_ASM("asm/levels", func_L01_00464910);

INCLUDE_ASM("asm/levels", func_L01_00464EC8);

INCLUDE_ASM("asm/levels", func_L01_00465168);

INCLUDE_ASM("asm/levels", func_L01_004653B8);

INCLUDE_ASM("asm/levels", func_L01_00465520);

LINKER_REMNANT("asm/levels", func_L01_00465648);

INCLUDE_ASM("asm/levels", func_L01_00465650);

INCLUDE_ASM("asm/levels", func_L01_00465738);

INCLUDE_ASM("asm/levels", func_L01_00465878);

/* localdecomp:start func_L01_00465B30 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v;
    s32 w16;
    s32 w20;
    s16 h24;
    s16 h26;
    f32 f28;
} Sub_00462578;

extern f32 D_L01_001DFB4C;
extern u8 *D_L01_002210D8[];
extern s32 func_00382468(s32);
extern u8 *func_L01_004618E0(s32);
extern u8 func_0013D3E0(void);

u8 *func_L01_00465B30(s128 *a0, s128 *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    u8 *o;
    Sub_00462578 *e;
    u8 *p;

    if (t0 == 0) {
        return 0;
    }
    {
        if (0.9f < D_L01_001DFB4C) {
            if (func_00382468(3) == 0) {
                return 0;
            }
        }
        if (0.95f < D_L01_001DFB4C) {
            if (func_00382468(2) == 0) {
                return 0;
            }
        }
        if (1.0f < D_L01_001DFB4C) {
            if (func_00382468(1) == 0) {
                return 0;
            }
        }
    }
    o = func_L01_004618E0(16);
    if (o != 0) {
        *(s128 *)(o + 16) = *a0;
        *(s32 *)(o + 4) = a2;
        o[1] = 0;
        *(f32 *)(o + 12) = f12;
        o[9] = 68;
        o[3] = 68;
        o[8] = func_0013D3E0();
        p = D_L01_002210D8[0] + t1;
        if (t1 == 3) {
            p = D_L01_002210D8[0];
        }
        e = (Sub_00462578 *)(o + 32);
        o[2] = *p;
        *(s16 *)(o + 10) = t0;
        e->h24 = t0;
        e->f28 = f12;
        e->w16 = a2;
        e->w20 = a3;
        e->h26 = t1;
        e->v = *a1;
        ((f32 *)e)[3] = ((f32 *)a0)[2] - 0.5f;
    }
    return o;
}
/* localdecomp:end func_L01_00465B30 */

INCLUDE_ASM("asm/levels", func_L01_00465CD0);

INCLUDE_ASM("asm/levels", func_L01_00465F88);

INCLUDE_ASM("asm/levels", func_L01_00465F90);

INCLUDE_ASM("asm/levels", func_L01_004660F8);

INCLUDE_ASM("asm/levels", func_L01_004661F0);

INCLUDE_ASM("asm/levels", func_L01_00466290);

/* localdecomp:start func_L01_00466588 */
extern u8 *func_L01_004618E0(s32);
typedef int s128_00462FD0 __attribute__((mode(TI)));
typedef struct {
    s128_00462FD0 v;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 f1A;
    f32 f1C;
} Sub_00462FD0;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00462FD0 f10;
    Sub_00462FD0 sub;
} Part_00462FD0;
extern u8 *D_L01_002210EC[];
extern u8 func_0013D3E0(void);
Part_00462FD0 *func_L01_00466588(s128_00462FD0 *pos, s128_00462FD0 *v2, s32 a2, s32 a3, s32 t0, s32 t1, f32 f) {
    Part_00462FD0 *p;
    Sub_00462FD0 *q;
    if (t0 == 0) {
        return 0;
    }
    p = ((Part_00462FD0 * (*)(s32))func_L01_004618E0)(21);
    if (p != 0) {
        p->f10 = *pos;
        p->f4 = a2;
        p->f1 = 0;
        p->fC = f;
        p->f9 = 164;
        p->f3 = 72;
        p->f8 = func_0013D3E0();
        p->f2 = *D_L01_002210EC[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        q->f1C = f;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        q->v = *v2;
    }
    return p;
}
/* localdecomp:end func_L01_00466588 */

INCLUDE_ASM("asm/levels", func_L01_00466678);

INCLUDE_ASM("asm/levels", func_L01_004668A0);

INCLUDE_ASM("asm/levels", func_L01_004669B0);

INCLUDE_ASM("asm/levels", func_L01_00466B78);

LINKER_REMNANT("asm/levels", func_L01_00466E38);

INCLUDE_ASM("asm/levels", func_L01_00466E40);

INCLUDE_ASM("asm/levels", func_L01_00466F50);

INCLUDE_ASM("asm/levels", func_L01_004670C8);

LINKER_REMNANT("asm/levels", func_L01_004674D0);

INCLUDE_ASM("asm/levels", func_L01_004674D8);

INCLUDE_ASM("asm/levels", func_L01_00467608);

INCLUDE_ASM("asm/levels", func_L01_00467688);

INCLUDE_ASM("asm/levels", func_L01_00467910);

INCLUDE_ASM("asm/levels", func_L01_00467B20);

LINKER_REMNANT("asm/levels", func_L01_00467DC0);

INCLUDE_ASM("asm/levels", func_L01_00467DC8);

LINKER_REMNANT("asm/levels", func_L01_004682B0);

INCLUDE_ASM("asm/levels", func_L01_004682B8);

LINKER_REMNANT("asm/levels", func_L01_00468460);

INCLUDE_ASM("asm/levels", func_L01_00468468);

/* localdecomp:start func_L01_00468640 */
extern s32 func_0038CB00(u8 *);
extern void func_003CD250(u8 *);
void func_L01_00468640(u8 *a0) {
    if (func_0038CB00(a0 + 10)) {
        func_003CD250(a0);
    }
}
/* localdecomp:end func_L01_00468640 */

INCLUDE_ASM("asm/levels", func_L01_00468678);

INCLUDE_ASM("asm/levels", func_L01_00468828);

INCLUDE_ASM("asm/levels", func_L01_00468A68);

INCLUDE_ASM("asm/levels", func_L01_00468B70);

INCLUDE_ASM("asm/levels", func_L01_00468D98);

LINKER_REMNANT("asm/levels", func_L01_00468F00);

INCLUDE_ASM("asm/levels", func_L01_00468F08);

LINKER_REMNANT("asm/levels", func_L01_00469010);

INCLUDE_ASM("asm/levels", func_L01_00469018);

LINKER_REMNANT("asm/levels", func_L01_00469128);

INCLUDE_ASM("asm/levels", func_L01_00469130);

INCLUDE_ASM("asm/levels", func_L01_00469210);

INCLUDE_ASM("asm/levels", func_L01_004693D8);

/* localdecomp:start func_L01_00469BD0 */
extern void func_003CD250(u8 *);
extern s32 func_0038CB00(u8 *);
typedef struct { u8 pad[0xA]; s16 h; } S_466558;

void func_L01_00469BD0(S_466558 *p) {
    if (p->h != -1 && ((s32 (*)(s16 *))func_0038CB00)(&p->h) != 0) {
        ((void (*)(S_466558 *))func_003CD250)(p);
    }
}
/* localdecomp:end func_L01_00469BD0 */

INCLUDE_ASM("asm/levels", func_L01_00469C18);

INCLUDE_ASM("asm/levels", func_L01_00469D88);

LINKER_REMNANT("asm/levels", func_L01_0046A428);

INCLUDE_ASM("asm/levels", func_L01_0046A430);

INCLUDE_ASM("asm/levels", func_L01_0046A610);

INCLUDE_ASM("asm/levels", func_L01_0046A798);
