#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* localdecomp:start func_L39_00667908 */
typedef struct {
    u8 pad0[0x252C];
    s32 *x252C;
    u8 pad2530[0x254C - 0x2530];
    s32 x254C;
} S_00667908;

typedef struct {
    s32 count;
} T_00667908;

extern T_00667908 *D_L39_00241120;
extern S_00667908 *func_L39_0061BF38(s32);

void func_L39_00667908(s32 a, s32 b)
{
    s32 i;
    S_00667908 *p;

    for (i = 0; i < D_L39_00241120->count; i++) {
        p = func_L39_0061BF38(i);
        if (p->x254C == a && p->x252C != 0 && *p->x252C == b) {
            p->x254C = 0;
        }
    }
}
/* localdecomp:end func_L39_00667908 */

/* localdecomp:start func_L39_006679A0 */
typedef struct { s32 w0; u8 pad4[0x252C - 4]; void *x252C; u8 pad2530[0x254C - 0x2530]; s32 x254C; } P_006679A0;
typedef struct { u8 pad[0xBC]; u8 xBC; } M_006679A0;
typedef struct { u8 pad[0x2D0]; M_006679A0 *x2D0; u8 pad2D4[0x308 - 0x2D4]; f32 x308; u8 pad30C[0x324 - 0x30C]; s32 x324; u8 pad328[0x340 - 0x328]; } Q_006679A0;
typedef struct { u8 pad[0x16C]; s32 w16C; } S_006679A0;
extern s32 D_L39_002461F8;
extern char D_L39_00337700[];
extern void func_L39_00667208(void *, u32, s32, s32);
__asm__(".extern D_L39_002461F8, 4");
extern P_006679A0 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern S_006679A0 D_001A5CD0;
void func_L39_006679A0(void) {
    s32 i;
    Q_006679A0 *o;
    s32 s;
    s32 r;
    for (i = 0; i < D_L39_00241120->count; i++) {
        if (D_L39_0024CE20[i] != 0 && *((u8 *)D_L39_0024CE20[i] + 0x1A14) != 0) {
            r = 0;
            switch (D_L39_0024CE20[i]->x254C) {
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
                if (D_L39_0024CE20[i]->x252C != 0) {
                    func_L39_00667208(D_L39_0024CE20[i]->x252C, D_L39_0024CE20[i]->w0, r, D_001A5CD0.w16C);
                } else {
                    D_L39_0024CE20[i]->x254C = 0;
                }
            }
        }
    }
    for (i = 0; i < D_L39_002461F8; i++) {
        o = &((Q_006679A0 *)D_L39_00337700)[i];
        if (o != 0 && o->x2D0 != 0 && o->x308 <= 0.0f) {
            s = o->x2D0->xBC;
            if (s != 7 && s != 9 && s != 11 && s != 10) {
                o->x324 = 0;
                func_L39_00667208(o, 0xFFFFFFFF, 6, D_001A5CD0.w16C);
            }
        }
    }
}
/* localdecomp:end func_L39_006679A0 */

INCLUDE_ASM("asm/levels", func_L39_00667B68);
