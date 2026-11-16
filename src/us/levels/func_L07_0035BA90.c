#include "common.h"

/* NTSC-U counterpart of func_L07_0035C958; retail uses animation argument 10, not PAL's 8. */
/* localdecomp:start func_L07_0035BA90 */
typedef unsigned int Q_35BA90 __attribute__((mode(TI)));
typedef struct { u8 pad[0x140]; void *f140; u8 gap[0x8C]; void *f1D0; } V_35BA90;
typedef struct { u8 pad[0x10]; Q_35BA90 pos; u8 state; u8 gap[0x21]; u8 anim; u8 gap43[5]; f32 speed; u8 gap4C[0x1C]; V_35BA90 *vars; } M_35BA90;
extern void *func_L01_0044CD90(void *, s32, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L07_0035B9B8(u8 *);
extern s32 D_L07_001DD6F0;
__asm__(".extern D_L07_001DD6F0, 4");
s32 func_L07_0035BA90(M_35BA90 *self) {
    Q_35BA90 pos;
    V_35BA90 *v = self->vars;
    if (self->state != 5) {
        void *p;
        pos = self->pos;
        p = func_L01_0044CD90(&pos, 0, 1.5707964f, 20.0f, -1.0f, -1.0f);
        v->f140 = p;
        if (p && self->state != 8 && self->state != 7) {
            v->f1D0 = p;
            func_L01_00441FB8(self, 5, -1);
            if (D_L07_001DD6F0 == 2) {
                func_003BE4F0(self, 0, 0, 0);
                self->speed = 2.0f;
            } else {
                func_003BE4F0(self, 3, 0, 10);
                self->speed = 2.0f;
            }
        }
    }
    if (self->anim == 2) self->speed = 0.5f;
    else self->speed = 1.0f;
    func_L01_00402498(func_L07_0035B9B8, self);
    return 0;
}
/* localdecomp:end func_L07_0035BA90 */
