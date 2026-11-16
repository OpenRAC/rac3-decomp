#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_0035B3B8);

/* localdecomp:start func_L07_0035C880 */
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L07_0035C880(u8 *a0)
{
    u8 buf[0x10];
    s32 v;

    v = a0[0x20] == 5 ? 0x40202080 : 0x40802020;
    func_003C2F58(a0, 2, buf);
    func_003D9508(buf, 0xB, v, 1, 0.1f, 0.08f, 0.0f);
    func_003C2F58(a0, 3, buf);
    func_003D9508(buf, 0xB, v, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L07_0035C880 */

/* localdecomp:start func_L07_0035C958 */
typedef unsigned int Q_35C958 __attribute__((mode(TI)));
typedef struct { u8 pad[0x140]; void *f140; u8 gap[0x8C]; void *f1D0; } V_35C958;
typedef struct { u8 pad[0x10]; Q_35C958 pos; u8 state; u8 gap[0x21]; u8 anim; u8 gap43[5]; f32 speed; u8 gap4C[0x1C]; V_35C958 *vars; } M_35C958;
extern void *func_L01_00450010(void *, s32, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L07_0035C880(u8 *);
extern s32 D_001DD6B0;
__asm__(".extern D_001DD6B0, 4");
s32 func_L07_0035C958(M_35C958 *self) {
    Q_35C958 pos;
    V_35C958 *v = self->vars;
    if (self->state != 5) {
        void *p;
        pos = self->pos;
        p = func_L01_00450010(&pos, 0, 1.5707964f, 20.0f, -1.0f, -1.0f);
        v->f140 = p;
        if (p && self->state != 8 && self->state != 7) {
            v->f1D0 = p;
            func_L01_004450F0(self, 5, -1);
            if (D_001DD6B0 == 2) {
                func_003C3A10(self, 0, 0, 0);
                self->speed = 2.0f;
            } else {
                func_003C3A10(self, 3, 0, 8);
                self->speed = 2.0f;
            }
        }
    }
    if (self->anim == 2) self->speed = 0.5f;
    else self->speed = 1.0f;
    func_L01_00404808(func_L07_0035C880, self);
    return 0;
}
/* localdecomp:end func_L07_0035C958 */
