#include "common.h"

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
