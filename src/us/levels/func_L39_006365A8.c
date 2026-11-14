#include "common.h"

/* NTSC-U counterpart of func_L39_00638DF0 (src/levels/shared/L39_00638DF0.c) */
/* localdecomp:start func_L39_006365A8 */
typedef struct {
    u8 pad0[12];
    s16 h12;
    u8 pad1[33 - 14];
    s8 b33;
    u8 pad2[128 - 34];
} Ent_00638DF0;
typedef struct {
    s32 pad0[13];
    s32 (*fn34)(void *, s32, s32, s32, s32);
} Vt_00638DF0;
extern Ent_00638DF0 D_L39_0049C950[];
extern void func_L39_0061FAE8(u8 *);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_003BF640(void *, f32);
extern void func_L39_00628CD0(void *, s32, s32, s32, f32);

s32 func_L39_006365A8(u8 *p) {
    s32 i;
    s32 v;
    Ent_00638DF0 *e;

    if (p[0x1A07] != 0 && p[0x1A05] != 0 && p[0x1A08] == 0) {
        i = -1;
        if (*(s32 *)(p + 0x474) == 2) i = *(s32 *)(p + 0x478);
        if (i != *(s32 *)(p + 0x244C)) {
            func_L39_0061FAE8(p);
        } else if (*(s32 *)(p + 0x3FC) >= 5) {
            if (func_L39_00646268(p, i)) {
                e = &D_L39_0049C950[D_L39_0049C950[i].b33];
            } else {
                e = &D_L39_0049C950[i];
            }
            v = e->h12;
            if (((Vt_00638DF0 *)*(void **)(p + 0x14))->fn34(p, 0, 0, 0, 1) != 0) {
                func_003BF640(p + 0x190, 0.025000002f);
                if (*(f32 *)(p + 0xFB4) > 0.025000002f) *(f32 *)(p + 0xFB4) = 0.025000002f;
                func_L39_00628CD0(p, v, 0, 0, 11.0f);
                if (*(s32 *)(p + 0x748) != 0) *(s32 *)(p + 0x754) = 1;
                *(s32 *)(p + 0x2448) = v;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006365A8 */
