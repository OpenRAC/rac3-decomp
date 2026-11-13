#include "common.h"

/* NTSC-U counterpart of func_L39_0069B960 (src/levels/39_multiplayer_menu/L39_0069B960.c) */
/* localdecomp:start func_L39_00699150 */
extern u8 D_001A5F0E[];
extern u8 D_L39_002483B8[];
extern void func_L39_006C9CA8(void *, void *);
extern void func_001206F4(void *, void *);
extern void func_001200E0(void *, void *, void *);

typedef struct S_0069B960 {
    u8 pad0[0x2A8];
    s32 f2A8;
    u8 pad1[0x2B8 - 0x2AC];
    s32 f2B8;
    u8 pad2[0x2EC - 0x2BC];
    s32 f2EC;
    s32 f2F0;
    s32 f2F4;
    u8 pad3[0x2FC - 0x2F8];
    s32 f2FC;
    s32 f300;
    u8 pad4[0x344 - 0x304];
    u8 f344[0x18];
    u8 pad5[0x35E - 0x35C];
    u8 f35E[0x384 - 0x35E];
    u8 f384[1];
} S_0069B960;

void func_L39_00699150(S_0069B960 *self, s32 mode, s32 a, s32 b, s32 c)
{
    s32 i;
    u8 *p;

    self->f2A8 = mode;
    self->f300 = 0;
    self->f2B8 = (mode == 3) ? 1 : self->f2B8;
    if (mode == 3) {
        self->f2EC = a;
        self->f2F0 = b;
        self->f2F4 = c;
    } else if (mode == 4) {
        func_L39_006C9CA8(self->f384, &D_001A5F0E[0x3CE]);
        self->f2FC = *(s32 *)&D_001A5F0E[0x3CE + 0x14];
        func_001206F4(self->f344, D_001A5F0E);
        func_001200E0(self->f35E, D_L39_002483B8, &self->f300);
        self->f300++;
        if (self->f344[0] == '#' || self->f344[0] == '@') {
            p = &self->f344[1];
            for (i = 15; i >= 0; i--) {
                p[-1] = p[0];
                p++;
            }
            self->f344[0x11] = ' ';
        }
        self->f344[0x12] = 0;
    }
}
/* localdecomp:end func_L39_00699150 */
