#include "common.h"

/* localdecomp:start func_L39_006B66B8 */
typedef struct O_006B66B8 O_006B66B8;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(O_006B66B8 *, s32, s32);
    u8 pad20[0x40 - 0x20];
    void (*f40)(O_006B66B8 *, s32);
    void (*f44)(O_006B66B8 *, s32, f32, f32);
    u8 pad48[0x4C - 0x48];
    void (*f4C)(O_006B66B8 *, s32, s32);
} V_006B66B8;
struct O_006B66B8 {
    s32 f0;
    s32 f4;
    u8 pad8[0x60 - 0x8];
    V_006B66B8 *vt;
};
typedef struct {
    u8 pad0[0x110];
    O_006B66B8 *f110;
    O_006B66B8 *f114;
    O_006B66B8 *f118[4];
} S_006B66B8;

s32 func_L39_0067F100(s32);
void func_L39_0068AAB8(void *);
void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);
s32 func_L39_0068B2F8(void *, s32, s32);

void func_L39_006B66B8(S_006B66B8 *this) {
    s32 i;
    f32 x;
    f32 y;

    func_L39_0067F100(0x3C0000);
    y = 0.0f;
    x = 0.44f;
    func_L39_0068AAB8(this);
    func_L39_0068A4A8(this, 0, 1, 0.5f, 0.36f, y, x, 0x332299DE);
    this->f110->vt->f1C(this->f110, 1, 0);
    this->f110->vt->f4C(this->f110, 0x40, 1);
    this->f110->vt->f44(this->f110, 1, x, y);
    this->f114->vt->f1C(this->f114, 1, 0);
    this->f114->vt->f40(this->f114, 1);
    for (i = 0; i < 4; i++) {
        this->f118[i]->vt->f4C(this->f118[i], 0x40, 1);
        this->f118[i]->vt->f44(this->f118[i], 1, 0.18f, 0.0f);
    }
    if (this->f118[1]->f4 == 3) {
        func_L39_0068B2F8(this, 3, 0);
    }
    if (this->f118[3]->f4 == 3) {
        func_L39_0068B2F8(this, 5, 0);
    }
}
/* localdecomp:end func_L39_006B66B8 */
