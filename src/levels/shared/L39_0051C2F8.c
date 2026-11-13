#include "common.h"

/* localdecomp:start func_L39_0051C2F8 */
#include "vu0.h"

typedef struct {
    char _p0[0x20];
    u8 f20;
    char _p21[0x68 - 0x21];
    void *f68;
    char _p6C[0xAA - 0x6C];
    s16 fAA;
    char _pAC[0xF0 - 0xAC];
    vu0_q fF0;
} O_0051C2F8;
typedef struct {
    O_0051C2F8 *f0;
    f32 f4;
    s32 f8;
    f32 fC;
} V_0051C2F8;
typedef struct {
    char _p0[0x10];
    f32 f10[4];
    char _p20[0x23 - 0x20];
    u8 f23;
    char _p24[0x2C - 0x24];
    f32 f2C;
    char _p30[0x68 - 0x30];
    V_0051C2F8 *f68;
    char _p6C[0xF0 - 0x6C];
    vu0_q fF0;
} M_0051C2F8;

extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_0038D000(void *, void *, void *);

void func_L39_0051C2F8(M_0051C2F8 *self) {
    V_0051C2F8 *v = self->f68;
    O_0051C2F8 *o;
    void *b;

    v->f4 += 0.32000002f;
    if (func_0038CAD0(&v->f8) || v->f4 >= 8.8f || (o = v->f0) == 0 || o->fAA != 0xA5D
        || o->f20 == 0xFE || o->f20 == 0xFD) {
        func_003C2880(self);
        return;
    }
    b = o->f68;
    qzero(self->f10);
    self->f10[1] = -v->f4;
    func_0038D000(self->f10, self->f10, (u8 *)v->f0 + 0xC0);
    vec_add_ba(self->f10, self->f10, b);
    self->fF0 = v->f0->fF0;
    if (v->f4 > 8.0f) {
        self->f23 = (1.0f - (v->f4 - 8.0f) * 10.0f) * 127.0f;
    }
    self->f2C = v->fC * 0.1f + v->fC * v->f4 * 0.125f;
}
/* localdecomp:end func_L39_0051C2F8 */
