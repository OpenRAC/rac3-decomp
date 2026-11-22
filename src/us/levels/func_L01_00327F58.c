#include "common.h"

/* NTSC-U counterpart of func_L01_00328458 (src/levels/shared/L01_003241A0.c): 360 ticks (6 s at 60 Hz) instead of 300, data at NTSC-U addresses */
/* localdecomp:start func_L01_00327F58 */
extern s32 D_001A71A4[];
extern s32 D_001D545C;
extern s32 D_L01_001DFDB4_00327F58[] __attribute__((section(".sdata")));
extern s32 D_L01_001DF9DC;
extern s32 D_L01_001E1660[];
extern s32 D_L01_001DFBC0_00327F58;
typedef struct { u8 pad[0x951C]; u16 flag; } State_00327F58;
extern State_00327F58 D_001A7E18;
extern s32 func_L01_00327578(void);
extern s32 func_L01_00327468(void);
extern s32 *func_003E16B8(void);
extern void func_L01_00511CA0(s32 *, void *);
extern s32 func_L01_00417F60(s32, s32);
extern void func_L01_003282D8(void);

void func_L01_00327F58(s32 unused, u8 *arg) {
    u8 *v = *(u8 **)(*(u8 **)(arg + 0x30) + 0x68);
    s32 *p;
    State_00327F58 *state;
    s32 t;

    if (*(s32 *)(v + 0x30) != 0) return;
    if (!func_L01_00327578()) return;
    if (!func_L01_00327468()) return;
    if (D_001A71A4[0] == 116) return;
    if (D_001A71A4[0] == 101) return;
    if (D_L01_001DFDB4_00327F58[1] != 0) return;
    if (D_L01_001DF9DC != 0) return;
    p = D_L01_001E1660;
    if (p[1] == 0) p = func_003E16B8();
    func_L01_00511CA0(p, func_L01_003282D8);
    if (D_001D545C != 4) return;
    if (*(s32 *)v != 500) return;
    state = &D_001A7E18;
    if (state->flag != 0) return;
    t = *(s32 *)(v + 0x60);
    if (t == 0) return;
    if (D_L01_001DFBC0_00327F58 - t < 361) return;
    if (!func_L01_00417F60(3181, 87)) return;
    if (state->flag != 0) return;
    state->flag = 1;
}
/* localdecomp:end func_L01_00327F58 */
