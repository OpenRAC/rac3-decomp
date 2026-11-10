#include "common.h"

/* localdecomp:start func_L39_006B2FF0 */
typedef struct V_006B2FF0 V_006B2FF0;
typedef struct {
    char pad0[0x60];
    V_006B2FF0 *f60;
} O_006B2FF0;
struct V_006B2FF0 {
    char pad0[0x1C];
    void (*f1C)(O_006B2FF0 *, s32, s32);
    char pad20[0x28 - 0x20];
    void (*f28)(O_006B2FF0 *, f32, f32);
    char pad2C[0x48 - 0x2C];
    void (*f48)(O_006B2FF0 *, s32, s32);
    void (*f4C)(O_006B2FF0 *, s32, s32);
    char pad50[0xB4 - 0x50];
    void (*fB4)(O_006B2FF0 *);
};
typedef struct {
    char pad0[0x110];
    O_006B2FF0 *f110;
    O_006B2FF0 *f114;
} S_006B2FF0;

void func_L39_0067F100(s32);
void func_L39_0068AAB8(void *);

void func_L39_006B2FF0(S_006B2FF0 *self) {
    func_L39_0067F100(0x3A0000);
    func_L39_0068AAB8(self);
    self->f110->f60->f1C(self->f110, 1, 0);
    self->f110->f60->f4C(self->f110, 0x40, 1);
    self->f110->f60->f48(self->f110, 3, 3);
    self->f110->f60->f28(self->f110, 0.5f, 0.3f);
    self->f114->f60->fB4(self->f114);
    self->f114->f60->f1C(self->f114, 3, 0);
    self->f114->f60->f4C(self->f114, 0x40, 1);
}
/* localdecomp:end func_L39_006B2FF0 */
