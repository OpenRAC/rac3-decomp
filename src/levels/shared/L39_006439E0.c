#include "common.h"

/* declared by functions of L39_0063EE68.c, which this file was cut from */
extern void func_L39_006439E0(u8 *);

/* localdecomp:start func_L39_006439E0 */
/* same code as func_L01_004ED188 (src/levels/shared/L01_004E7338.c), the single-player levels' copy */
typedef struct { u8 p0[0xC]; u8 bC; } T_006439E0;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[3]; T_006439E0 *w24; u8 p28[0x1B]; u8 b43; u8 p44[0x1C]; u8 b60; u8 p61[3]; void (*w64)(void *); } O_006439E0;
typedef struct { u8 p0[0x3C]; void (*f3C)(void *, s32); } V_006439E0;
typedef struct { u8 p0[0x450]; O_006439E0 *obj; u8 p454[0x17]; u8 b46B; u8 p46C[4]; s32 w470; s32 w474; s32 w478; } L_006439E0;
typedef struct { u8 p0[0x14]; V_006439E0 *vt; u8 p18[0x12F8]; s32 w1310; u8 p1314[0x700]; u8 b1A14; } S_006439E0;
extern s32 D_L39_0024B9C8;
extern void func_L39_00640738(void *, s32);
extern void func_L39_00644448(u8 *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L39_006439E0(u8 *a) {
    S_006439E0 *s = (S_006439E0 *)a;
    s32 i;
    for (i = 0; i < 6; i++) {
        L_006439E0 *l = (L_006439E0 *)((u8 *)s + i * 0x50);
        O_006439E0 *o = l->obj;
        if (o != 0) {
            switch (l->w474) {
            case 2:
                l->w470++;
                func_L39_00640738(s, i);
                if ((o->b60 & 2) && o->b43 == 0 && o->w24->bC >= 2)
                    func_003C3A10(o, 1, 0, 2);
                break;
            case 3:
                l->b46B++;
                if ((o->b60 & 2) || i == 1 || i == 0)
                    func_L39_00644448((u8 *)s, i, D_L39_0024B9C8 + 2);
                break;
            }
            s->vt->f3C(s, i);
            if (s->w1310 == 2 && s->b1A14 != 0 && i == 0 && ((L_006439E0 *)s)->w478 != 10)
                continue;
            if (o != 0 && o->b20 != 0xFE && o->b20 != 0xFD && i != 5 && o->w64 != 0)
                o->w64(o);
        } else {
            func_L39_00640738(s, i);
        }
    }
}
/* localdecomp:end func_L39_006439E0 */

INCLUDE_ASM("asm/levels", func_L39_00643B98);

INCLUDE_ASM("asm/levels", func_L39_00643F50);
