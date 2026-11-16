/* NTSC-U draft (Claude wave K): C of func_L39_006CE648, the NTSC-U twin of func_L39_006D0DD0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 15 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L39_006CE648", whose code is not the PAL one).
 * Worker's note: 15 diff (delay-slot fill / register choice only): s32 f(S *self): if self->b3EC: s0 = *(D_L39_0024D860[0]+0x50) (unsized array = lui form), func_0014B008(buf[0x10] at sp+0x70), branch on self->b34 building block A (size 0x30 at sp+0: h0 = D_L39_00249D58[0], ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006D08E8 (src/levels/39_multiplayer_menu/L39_006D08E8.c) */
/* localdecomp:start func_L39_006CE648 */
typedef struct {
    u16 h0;
    u8 pad2[0x13];
    u8 str15[0x13];
    s32 w28;
    s32 w2C;
} LocA_006CE648;
typedef struct {
    u16 h0;
    u8 pad2[0x13];
    u8 str15[0x13];
    s32 w28;
    s32 w2C;
    s32 w30;
} LocB_006CE648;
typedef struct {
    u8 pad0[0x34];
    u8 b34;
    u8 pad35[0x3EC - 0x35];
    u8 b3EC;
    u8 pad3ED[7];
    u8 b3F4;
    u8 pad3F5[3];
    s32 w3F8;
    u8 pad3FC[4];
    s32 w400;
} S_006CE648;
extern u8 *D_L39_0024D860[];
extern u16 D_L39_00249D58[];
extern void func_0014B008(void *);
extern s32 func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017D780(void *, void *, s32);
extern s32 func_0017D2F8(void *, void *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern u8 D_00197948[];
extern u8 D_00197A38[];

s32 func_L39_006CE648(S_006CE648 *self) {
    LocA_006CE648 a;
    LocB_006CE648 b;
    u8 buf[0x10];
    u8 *s0;
    s32 r;
    s32 t;

    r = 1;
    if (self->b3EC != 0) {
        s0 = *(u8 **)(D_L39_0024D860[0] + 0x50);
        self->b3F4 = 1;
        func_0014B008(buf);
        if (self->b34 != 0) {
            a.h0 = D_L39_00249D58[0];
            func_001206F4(a.str15, s0);
            a.w28 = 1;
            a.w2C = self->w400;
            self->w3F8 = (s32)func_00130760(func_0012DCB0(), 0x24000);
            t = func_0017D780(&a, D_00197948, 0);
        } else {
            b.h0 = D_L39_00249D58[0];
            func_001206F4(b.str15, s0);
            b.w28 = *(s32 *)self;
            b.w2C = 1;
            b.w30 = self->w400;
            self->w3F8 = (s32)func_00130760(func_0012DCB0(), 0x24000);
            t = func_0017D2F8(&b, D_00197A38, 0);
        }
        func_001962D8(t);
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CE648 */
