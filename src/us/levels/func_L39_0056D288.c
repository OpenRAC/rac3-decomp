#include "common.h"

/* NTSC-U counterpart of func_L39_0056DF80 (src/levels/shared/L39_0056DF80.c) */
/* localdecomp:start func_L39_0056D288 */
typedef struct { u8 p0[0x100]; f32 f100; f32 f104; } H_0056DF80;
typedef struct { u8 p0[0x134]; H_0056DF80 *w134; u8 p138[0x460 - 0x138]; } E_0056DF80;
typedef struct { u8 p0[0x10]; s32 w10; f32 f14; u8 p18[4]; f32 f1C; u8 p20[4]; f32 f24; } Q_0056DF80;
typedef struct { u8 p0[0x1E0]; Q_0056DF80 q; } W_0056DF80;
typedef struct { u8 p0[0x70]; W_0056DF80 *w70; u8 p74[0x20]; s32 w94; } O_0056DF80;
typedef struct { u8 pad[0xA4]; u8 flags[0x100]; } Tab_0056DF80;
extern E_0056DF80 D_L39_0024E0D0[];
extern Tab_0056DF80 D_001A5990;
extern s32 D_001A5AB0[][8];
extern s32 D_001A5A50[][8];
extern f32 D_L39_00242518[];
extern u8 *func_L39_006197C0(s32);

void func_L39_0056D288(O_0056DF80 *o, f32 *a1, f32 *a2) {
    Q_0056DF80 *q = &o->w70->q;
    E_0056DF80 *e = &D_L39_0024E0D0[o->w94];
    s32 idx = *(s32 *)(func_L39_006197C0(o->w94) + 0x2544);
    f32 f;
    f32 k = 0.6981317f;

    if (q->w10 & 1) {
        *a1 = 0;
    } else {
        *a1 = e->w134->f100;
        if (D_001A5AB0[D_001A5990.flags[idx]][idx] == 0) *a1 = -*a1;
    }
    if (*a1 == 0) {
        if (q->f1C != 0) *a1 = q->f1C;
    } else {
        q->f14 = D_L39_00242518[o->w94];
    }
    if (q->w10 & 2) {
        *a2 = 0;
        if (*a2 == 0) *a2 = q->f24 / k;
    } else {
        f = e->w134->f104;
        *a2 = -f;
        if (D_001A5A50[D_001A5990.flags[idx]][idx] == 0) *a2 = f;
        if (*a2 == 0) *a2 = q->f24 / 0.6981317f;
    }
}
/* localdecomp:end func_L39_0056D288 */
