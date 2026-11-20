#include "common.h"

/* localdecomp:start func_L20_003FF358 */
typedef int u128_003FF358 __attribute__((mode(TI)));
typedef struct { u8 pad[0x30]; u128_003FF358 v30; u8 pad40[0x40]; } E_003FF358;
typedef struct {
    u8 pad0[0x350];
    u128_003FF358 v350;
    u8 pad360[0x380 - 0x360];
    s32 i380;
    s32 i384;
    s32 i388;
    s32 i38C;
    u8 pad390[0x398 - 0x390];
    s32 i398;
    u8 pad39C[0x3A4 - 0x39C];
    s32 i3A4;
    u8 pad3A8[0x3E0 - 0x3A8];
    s32 i3E0;
    u8 pad3E4[0x3FC - 0x3E4];
    s32 i3FC;
} S_003FF358;
typedef struct { u8 pad0[0x10]; u128_003FF358 v10; u8 pad20[0x48]; S_003FF358 *p68; } A_003FF358;
extern E_003FF358 *D_L20_001E0380;
typedef struct { s16 h0; s16 h2; u8 pad4[0x2C]; } R_003FF358;
typedef struct { u8 hdr[0x30]; R_003FF358 e[1]; } Q_003FF358;
extern Q_003FF358 *D_L20_001DFE4C __attribute__((section(".data")));

void func_L20_003FF358(A_003FF358 *a0) {
    S_003FF358 *s = a0->p68;
    s->i3E0 = 1;
    if (s->i384 != -1) {
        s->i3E0 = 2;
    } else if (s->i388 != -1) {
        s->i3E0 = 5;
        s->v350 = D_L20_001E0380[s->i388].v30;
    } else if (s->i380 != -1) {
        s->i3E0 = 3;
    } else if (s->i38C != -1 && D_L20_001DFE4C->e[s->i38C].h2 != 0) {
        s->i3E0 = 6;
    } else if (s->i398 != 0 || s->i3FC != 0) {
        s->i3E0 = 4;
        s->v350 = a0->v10;
    }
    if (s->i3A4 != -1 && *(long *)&s->i380 == -1 && *(long *)&s->i388 == -1) {
        s->i3E0 = 5;
    }
}
/* localdecomp:end func_L20_003FF358 */
