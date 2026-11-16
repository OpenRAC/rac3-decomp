/* PAL near miss (Claude wave S/pal): near miss: 15 words differ with "@ps2as needed (0.5f lui/mtc1); with --as ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: 15 diff (best, near/ file; needs @ps2as added to L18_00350FB0.c anyway): prologue and the p=&D.q110 / D=p-0x110 / q=&D.q80 (s1-0x90) address chain match retail; left: register/schedule order of the middle block (retail loads D.x25C0 into $a1 with 1 in $a2 and ...
 */
#include "common.h"

/* localdecomp:start func_L18_00350FB0 */
typedef int Quad_00350FB0 __attribute__((mode(TI)));
typedef union QF_00350FB0 {
    Quad_00350FB0 q;
    f32 f[4];
} QF_00350FB0;
typedef struct Obj_00350FB0 {
    u8 pad00[0x10];
    Quad_00350FB0 q10;
    u8 pad20[0x68 - 0x20];
    u8 *vars;
    u8 pad6C[0xF0 - 0x6C];
    Quad_00350FB0 qF0;
} Obj_00350FB0;
typedef struct G_00350FB0 {
    u8 pad00[0x80];
    Quad_00350FB0 q80;
    Quad_00350FB0 q90;
    u8 padA0[0x30];
    QF_00350FB0 qD0;
    u8 padE0[0x110 - 0xE0];
    Quad_00350FB0 q110;
    u8 pad120[0x25C0 - 0x120];
    Obj_00350FB0 *x25C0;
    u8 pad25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} G_00350FB0;

extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00430118(void *);
extern G_00350FB0 D_001A4BE0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

void func_L18_00350FB0(Obj_00350FB0 *self) {
    Quad_00350FB0 *p = &D_001A4BE0.q110;
    Quad_00350FB0 *q;

    *p = *(Quad_00350FB0 *)(self->vars + 0x290);
    func_003C2F58(self, 8, (u8 *)D_001A4BE0.x25C0 + 0x10);
    q = &D_001A4BE0.q80;
    *q = D_001A4BE0.x25C0->q10;
    D_001A4BE0.x25C0->qF0 = self->qF0;
    D_001A4BE0.q90 = D_001A4BE0.x25C0->qF0;
    D_001A4BE0.b25E5 = 1;
    D_001A4BE0.qD0.q = self->q10;
    D_001A4BE0.qD0.f[2] += 0.5f;
    if (D_001D545C == 0x1A) {
        func_L01_00430118(q);
    }
}
/* localdecomp:end func_L18_00350FB0 */
