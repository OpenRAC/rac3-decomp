#include "common.h"

/* NTSC-U counterpart of func_L01_003FF240 (src/levels/shared/L01_003FE908.c) */
typedef struct {
    s32 v[10];
} S_003FF4E8;
extern s32 D_L01_001E6540[];
extern f32 D_L01_001DF9D0;
extern s32 D_L01_001E6540[];

/* localdecomp:start func_L01_003FD2F0 */
typedef struct {
    s32 buffers[7];     /* 0x00 */
    u16 buffer;         /* 0x1C: the buffer drawn last */
    u8 pad1E[0x22 - 0x1E];
    s16 layout;         /* 0x22: index into D_L01_001E68D0 */
    u8 pad24[0x26 - 0x24];
    s16 active;         /* 0x26 */
    u8 pad28[0x2C - 0x28];
    s32 timer;          /* 0x2C */
    u8 pad30[0x370 - 0x30];
    s32 delay;          /* 0x370 */
    s32 fade;           /* 0x374 */
} TextScreen_003FF240;
extern S_003FF4E8 D_L01_001E68D0[];
extern s32 D_001A1ED4[];
extern s32 D_L01_001D60C0_003FD2F0;
__asm__(".extern D_L01_001D60C0_003FD2F0, 4");
extern void func_00384B68(s32);
extern long func_003A42E0(s32, s32, s32, s32);
extern void func_L01_003FDF60(void);
extern void func_L01_003FDD18(s32, f32);
extern void func_L01_003FD600(s32, f32);
extern void func_00384C98(void);
extern void func_003866E8(s32, s32, s32, s32);

void func_L01_003FD2F0(void)
{
    TextScreen_003FF240 *g = (TextScreen_003FF240 *)D_L01_001E6540;
    s32 i, fade;
    f32 t;

    if (g->active) {
        func_00384B68(0);
        func_003A42E0(g->buffers[(s16)(g->buffer ^ 1)] + 16, D_001A1ED4[0], 512, 416);
        func_L01_003FDF60();
        switch (D_L01_001E68D0[g->layout].v[6]) {
        case 0:
            for (i = 0; i < D_L01_001E68D0[g->layout].v[7]; i++) {
                if (g->timer < D_L01_001D60C0_003FD2F0)
                    t = (f32)g->timer / (f32)D_L01_001D60C0_003FD2F0;
                else if (D_L01_001E68D0[g->layout].v[9] - D_L01_001D60C0_003FD2F0 < g->timer)
                    t = (f32)(D_L01_001E68D0[g->layout].v[9] - g->timer) / (f32)D_L01_001D60C0_003FD2F0;
                else
                    t = 1.0f;
                func_L01_003FDD18(i, t);
            }
            break;
        case 1:
        case 2: {
            TextScreen_003FF240 *s;
            s32 j, n;
            for (j = 0; j < D_L01_001E68D0[((TextScreen_003FF240 *)D_L01_001E6540)->layout].v[7]; j = n) {
                n = j + 1;
                s = (TextScreen_003FF240 *)D_L01_001E6540;
                func_L01_003FD600(j, 1.0f - ((f32)s->timer - (f32)(D_L01_001E68D0[s->layout].v[7] - n) * (f32)s->delay) / (f32)s->fade);
            }
            break;
        }
        }
        func_00384C98();
    }
    func_003866E8(0, 0, 0, (s32)(D_L01_001DF9D0 * 128.0f));
}
/* localdecomp:end func_L01_003FD2F0 */
