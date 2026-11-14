#include "common.h"

/* NTSC-U counterpart of func_L39_006679A0 (src/levels/shared/L39_00667908.c) */
typedef struct {
    s32 count;
} T_00667908;
extern T_00667908 *D_L39_002412A0;

/* localdecomp:start func_L39_006650C8 */
typedef struct { s32 w0; u8 pad4[0x252C - 4]; void *x252C; u8 pad2530[0x254C - 0x2530]; s32 x254C; } P_006679A0;
typedef struct { u8 pad[0xBC]; u8 xBC; } M_006679A0;
typedef struct { u8 pad[0x2D0]; M_006679A0 *x2D0; u8 pad2D4[0x308 - 0x2D4]; f32 x308; u8 pad30C[0x324 - 0x30C]; s32 x324; u8 pad328[0x340 - 0x328]; } Q_006679A0;
typedef struct { u8 pad[0x16C]; s32 w16C; } S_006679A0;
extern s32 D_L39_00246378;
extern char D_L39_00337800[];
extern void func_L39_00664930(void *, u32, s32, s32);
__asm__(".extern D_L39_00246378, 4");
extern P_006679A0 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern S_006679A0 D_001A5E50;
void func_L39_006650C8(void) {
    s32 i;
    Q_006679A0 *o;
    s32 s;
    s32 r;
    for (i = 0; i < D_L39_002412A0->count; i++) {
        if (D_L39_0024CF20[i] != 0 && *((u8 *)D_L39_0024CF20[i] + 0x1A14) != 0) {
            r = 0;
            switch (D_L39_0024CF20[i]->x254C) {
            case 1:
            case 4:
                r = 0;
                break;
            case 2:
            case 3:
                r = 1;
                break;
            }
            if (r != 0) {
                if (D_L39_0024CF20[i]->x252C != 0) {
                    func_L39_00664930(D_L39_0024CF20[i]->x252C, D_L39_0024CF20[i]->w0, r, D_001A5E50.w16C);
                } else {
                    D_L39_0024CF20[i]->x254C = 0;
                }
            }
        }
    }
    for (i = 0; i < D_L39_00246378; i++) {
        o = &((Q_006679A0 *)D_L39_00337800)[i];
        if (o != 0 && o->x2D0 != 0 && o->x308 <= 0.0f) {
            s = o->x2D0->xBC;
            if (s != 7 && s != 9 && s != 11 && s != 10) {
                o->x324 = 0;
                func_L39_00664930(o, 0xFFFFFFFF, 6, D_001A5E50.w16C);
            }
        }
    }
}
/* localdecomp:end func_L39_006650C8 */
