#include "common.h"

/* localdecomp:start func_L39_0052B740 */
typedef struct { u8 pad0[0x170]; s32 w170; u8 pad174[0x604 - 0x174]; s32 w604; u8 pad608[0x638 - 0x608]; s16 h638; } G_0052BCA8;
typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0xF]; u8 b30; u8 pad31[0x37]; u8 *p68; } O_0052BCA8;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; u8 pad10[0x10]; s32 f20; } N_0052BCA8;
typedef struct { s32 f0; u8 pad4[0x214]; } T_0052BCA8;
extern G_0052BCA8 D_001A5E50;
extern T_0052BCA8 D_L39_00352A40;
extern N_0052BCA8 D_L39_002407A8 __attribute__((section(".sdata")));
extern void func_L39_0066CCD8(s32, void *, s32, void *);
extern void func_L39_0061A4F8(void);

void func_L39_0052B740(O_0052BCA8 *o) {
    s32 v;
    s32 a;
    G_0052BCA8 *g = &D_001A5E50;

    if (g->h638 != 0) {
        D_L39_00352A40.f0 = -1;
    }
    if (o->b20 == 0) {
        if (g->w170 == 0) {
            v = (g->w604 & 7) * 300000;
        } else {
            v = D_L39_002407A8.f8 * 60000;
        }
        a = -1;
        if (v != 0) {
            a = v;
        }
        func_L39_0066CCD8(a, o->p68, (s32)(o->p68 + 0x1B0), o->p68 + 0x200);
        o->b20 = 1;
        o->b30 = 0xFF;
    } else {
        func_L39_0061A4F8();
    }
}
/* localdecomp:end func_L39_0052B740 */
