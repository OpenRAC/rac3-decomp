/* Wave 13 (r26, 2026-11-28) replaces the earlier draft of this function (k6 agent 2, from its functional C). */
/* PAL near miss (wave 13 r26). Against the k6 draft: self is a struct (S_006025F0, alignment 4), so the
 * line-table stores take gcc's BLKmode array path (base register self+0x1B8 first in the addu, the [n - 1]
 * index not folded into a -4 offset), the text is walked as self->text[i] with &self->text[i + 1] for
 * the next line, the character test is (u8)c on an int c (retail's lbu + andi 0xff), and the k >= 2
 * callee is func_L01_00480A78 (0x594858 at level 39; the draft called its same-hash twin
 * func_L01_00447470, 0x5B6AB0). 83 diff under the file's line (draft 198). Still differs: the file's
 * line saves s0-fp with sq in a 0x1A0 frame where retail has sd in 0x160 (-fopt-stack, see the old
 * header); the text pointer is a reduced giv copied from self+0x88 (retail keeps the pre-loop pointer
 * in s1) and the line base stays self+0x1B8 inside the loop (retail hoists it: move s6, s3), so
 * saved (D_L39_00241470) gets fp instead of retail's stack slot 0x100 and the registers shift.
 * build/codex/wr26/v7.c is closer in structure (aligned 35 rows, every body instruction but the
 * hoisted constant 1 in fp and the saved spill) but 183 here: a user pointer p, a Lines_006025F0
 * sub-struct reached through a pointer taken inside the loop, &self->text[cnt + 1].
 */
#include "common.h"

/* localdecomp:start func_L39_006025F0 */
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_00241470;
extern f32 D_L39_00241150[] __attribute__((section(".sdata")));

typedef struct {
    f32 *pos;
    f32 *scale;
    u8 pad8[0x80];
    u8 text[0x100];
    u8 pad188[0x8];
    s32 n;
    u8 pad194[0x4];
    s32 f198;
    u8 pad19C[0x8];
    s32 mode;
    u8 pad1A8[0xC];
    s32 maxw;
    u8 *lines[30];
} S_006025F0;

void func_L39_006025F0(S_006025F0 *self, s32 mode, f32 x, f32 y, s32 a4) {
    extern void func_0011D534(void *, s32, s32);
    extern void func_0038E150(s32);
    extern s32 func_L01_00412750(u8 *, s32);
    extern s32 func_L01_00412708(u8 *, s32);
    extern s32 func_L01_00480A78(u8 *, s32, f32);
    u8 buf[256];
    s32 saved;
    s32 w = 1;
    s32 idx = 0;
    s32 i;
    s32 nobreak = 1;
    s32 k;
    s32 c;

    self->pos[0] = x;
    self->pos[1] = y;
    self->f198 = a4;
    self->mode = mode;
    self->text[0xFF] = 0;
    self->n = 1;
    self->maxw = 0;
    func_0011D534(buf, 0, 0x100);
    func_0011D534(self->lines, 0, 0x78);
    saved = D_L39_00241470;
    self->lines[self->n - 1] = self->text;
    func_0038E150(1);
    for (i = 0; i < 0xFF && self->text[i] != 0; i++) {
        c = self->text[i];
        if ((u8)c == 1) {
            self->text[i] = 0;
            buf[idx] = 0;
            nobreak = 0;
            self->lines[self->n] = &self->text[i + 1];
            self->n += 1;
            switch (self->mode) {
            case 0:
                w = func_L01_00412750(buf, -1);
                break;
            case 1:
                k = *D_L39_00241120;
                if (k >= 2) {
                    w = func_L01_00480A78(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
                } else {
                    w = func_L01_00412708(buf, -1);
                }
                break;
            case 2:
                break;
            }
            idx = 0;
            self->maxw = self->maxw < w ? w : self->maxw;
        } else {
            buf[idx] = c;
            idx++;
        }
    }
    if (nobreak != 0) {
        switch (self->mode) {
        case 0:
            self->maxw = func_L01_00412750(buf, -1);
            break;
        case 1:
            k = *D_L39_00241120;
            if (k >= 2) {
                self->maxw = func_L01_00480A78(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
            } else {
                self->maxw = func_L01_00412708(buf, -1);
            }
            break;
        case 2:
            break;
        }
    } else {
        switch (self->mode) {
        case 0:
            w = func_L01_00412750(buf, -1);
            break;
        case 1:
            k = *D_L39_00241120;
            if (k >= 2) {
                w = func_L01_00480A78(buf, -1, D_L39_00241150[k - 1] / D_L39_00241150[0]);
            } else {
                w = func_L01_00412708(buf, -1);
            }
            break;
        case 2:
            break;
        }
        self->maxw = self->maxw < w ? w : self->maxw;
    }
    func_0038E150(saved);
    self->scale[0] = 1.0f;
}
/* localdecomp:end func_L39_006025F0 */
