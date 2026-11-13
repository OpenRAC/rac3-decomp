#include "common.h"

/* localdecomp:start func_L39_0063EE68 */
void func_L39_0063EE68(void) {

}
/* localdecomp:end func_L39_0063EE68 */

/* localdecomp:start func_L39_0063EE70 */
void func_L39_0063EE70(void) {

}
/* localdecomp:end func_L39_0063EE70 */

INCLUDE_ASM("asm/levels", func_L39_0063EE78);

/* localdecomp:start func_L39_0063F0C0 */
void func_L39_0063F0C0(void) {

}
/* localdecomp:end func_L39_0063F0C0 */

INCLUDE_ASM("asm/levels", func_L39_0063F0C8);

INCLUDE_ASM("asm/levels", func_L39_0063FC90);

INCLUDE_ASM("asm/levels", func_L39_0063FDA8);

/* localdecomp:start func_L39_00640698 */
extern s32 func_L39_0063BDE0(void *, void *);
extern void func_L01_0044E740(void *);
extern void func_003C2880(void *);

void func_L39_00640698(u8 *a)
{
    s32 i;
    for (i = 5; i >= 0; i--) {
        u8 *p = a + (5 - i) * 0x50;
        if (*(void **)(p + 0x450) != 0) {
            if (func_L39_0063BDE0(a, *(void **)(p + 0x450)) != 0) {
                p[0x46A] = 0;
                func_L01_0044E740(a + 0x1780);
            }
            func_003C2880(*(void **)(p + 0x450));
            *(void **)(p + 0x450) = 0;
        }
        if (*(void **)(p + 0x454) != 0) {
            func_003C2880(*(void **)(p + 0x454));
            *(void **)(p + 0x454) = 0;
        }
    }
}
/* localdecomp:end func_L39_00640698 */

LINKER_REMNANT("asm/levels", func_L39_00640728);

INCLUDE_ASM("asm/levels", func_L39_00640738);

INCLUDE_ASM("asm/levels", func_L39_006439E0);

INCLUDE_ASM("asm/levels", func_L39_00643B98);

INCLUDE_ASM("asm/levels", func_L39_00643F50);

/* localdecomp:start func_L39_00644448 */
typedef struct {
    u8 pad0[0x20];
    u8 type20;
} Obj_00644448;

typedef struct {
    u8 pad0[0x450];
    Obj_00644448 *obj;
    void *obj2;
    u8 b8;
    u8 pad459[0xB];
    s32 x14;
    u8 pad468[2];
    u8 b1A;
    u8 pad46B[9];
    s32 x24;
    s32 x28;
} V_00644448;

extern s32 func_L39_0063BDE0(void *, void *);
extern void func_L01_0044E740(void *);
extern void func_003C2880(void *);
extern void func_L01_0040E388(void *);

void func_L39_00644448(u8 *a0, s32 a1, s32 a2) {
    s32 prev;
    s32 v;

    ((V_00644448 *)(a0 + a1 * 0x50))->x14 = a2;
    prev = ((V_00644448 *)(a0 + a1 * 0x50))->x28;
    if (((V_00644448 *)(a0 + a1 * 0x50))->x24 != 3) {
        Obj_00644448 *obj = ((V_00644448 *)(a0 + a1 * 0x50))->obj;
        ((V_00644448 *)(a0 + a1 * 0x50))->x24 = 3;
        if (obj != 0) {
            if (obj->type20 != 0xFE) {
                if (obj->type20 != 0xFD) {
                    void (*fn)(Obj_00644448 *) = *(void (**)(Obj_00644448 *))((u8 *)obj + 0x64);
                    if (fn != 0) {
                        fn(obj);
                    }
                }
            }
        }
    }
    ((V_00644448 *)(a0 + a1 * 0x50))->x24 = 0;
    ((V_00644448 *)(a0 + a1 * 0x50))->x28 = 0;
    ((V_00644448 *)(a0 + a1 * 0x50))->b8 = 0;
    if (a0[0x1A14] != 0) {
        if (a1 == 0) {
            *(s16 *)(a0 + 0x1DAC) = 0;
        }
    }
    if (((V_00644448 *)(a0 + a1 * 0x50))->obj != 0) {
        if (func_L39_0063BDE0(a0, ((V_00644448 *)(a0 + a1 * 0x50))->obj) != 0) {
            ((V_00644448 *)(a0 + a1 * 0x50))->b1A = 0;
            func_L01_0044E740(a0 + 0x1780);
        }
        func_003C2880(((V_00644448 *)(a0 + a1 * 0x50))->obj);
        ((V_00644448 *)(a0 + a1 * 0x50))->obj = 0;
    }
    if (((V_00644448 *)(a0 + a1 * 0x50))->obj2 != 0) {
        if (a1 != 3) {
            func_003C2880(((V_00644448 *)(a0 + a1 * 0x50))->obj2);
            ((V_00644448 *)(a0 + a1 * 0x50))->obj2 = 0;
        }
    }
    if (a1 == 0) {
        s32 hit;
        v = prev;
        if (v == -1) {
            s32 t = -1;
            if (((V_00644448 *)a0)->x24 == 2) {
                t = ((V_00644448 *)a0)->x28;
            }
            v = t;
        }
        if (v == 6 || v == 0xC) {
            hit = 1;
        } else {
            hit = 0;
        }
        if (hit) {
            func_L01_0040E388(a0 + 0xF10);
            return;
        }
    }
    if (a1 == 1) {
        func_L01_0040E388(a0 + 0xA40);
        func_L01_0040E388(a0 + 0xAF0);
    }
}
/* localdecomp:end func_L39_00644448 */
