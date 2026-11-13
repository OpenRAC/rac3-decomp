#include "common.h"

/* localdecomp:start func_L39_006A5AA0 */
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);
void func_L39_006A5AA0(void *a0)
{
    s32 v[4];
    ((void (*)(void *, void *, void *, void *, void *, void *, f32, f32, f32, f32, f32))func_L39_00688460)(a0, v, v, v, v, v, 0.5f, 0.5f, 1.0f, 1.0f, 1.21f);
}
/* localdecomp:end func_L39_006A5AA0 */

/* localdecomp:start func_L39_006A5AF0 */
typedef struct S_006A5AF0_vt {
    char pad0[0x1C];
    void (*f1C)(void *, s32, s32);
    char pad20[0x2C];
    void (*f4C)(void *, s32, s32);
} S_006A5AF0_vt;

typedef struct S_006A5AF0_obj {
    char pad0[0x60];
    S_006A5AF0_vt *vt;
} S_006A5AF0_obj;

typedef struct S_006A5AF0_g {
    char pad0[0x38];
    void *f38;
} S_006A5AF0_g;

typedef struct S_006A5AF0 {
    char pad0[0x110];
    S_006A5AF0_obj *f110[5];
    char pad124[0x18C];
    u8 f2B0;
    u8 f2B1;
    char pad2B2[0xA0A];
    u8 fCBC;
    char padCBD[0xA0B];
    u8 f16C8;
} S_006A5AF0;

extern S_006A5AF0_g *D_L39_0024D760;
extern void func_L39_0067F100(s32);
extern void func_L39_0068AAB8(S_006A5AF0 *);
extern void func_L39_0068A4A8(S_006A5AF0 *, f32, f32, f32, s32, s32, f32, s32);
extern void func_L39_00689F00(S_006A5AF0 *, f32, f32, f32, f32, f32, f32, s32, s32, s32);
extern void func_L39_0068B2F8(S_006A5AF0 *, s32, s32);
extern s32 func_L39_006CEA18(u8 *, s32);

void func_L39_006A5AF0(S_006A5AF0 *this)
{
    s32 i;
    S_006A5AF0_obj **p;
    f32 k;

    func_L39_0067F100(0x320000);
    k = 0.5f - 0.045f;
    func_L39_0068AAB8(this);
    func_L39_0068A4A8(this, 0.502f, 0.4171f, 0.4757f - 0.4171f, 0, 4, k, 0x332299DE);
    func_L39_00689F00(this, 1.5f, 1.5f, k, 0.044f, 0.044f, 0.1f, 0, 3, 3);
    p = this->f110;
    for (i = 4; i >= 0; i--) {
        (*p)->vt->f1C(*p, 3, 0);
        (*p)->vt->f4C(*p, 0x40, 1);
        p++;
    }
    if (this->f2B0) {
        this->f110[0]->vt->f1C(this->f110[0], 2, 0);
        this->f110[2]->vt->f1C(this->f110[2], 2, 0);
        this->f110[3]->vt->f1C(this->f110[3], 2, 0);
        func_L39_0068B2F8(this, 1, 0);
    } else {
        func_L39_0068B2F8(this, 0, 0);
    }
    func_L39_006CEA18(D_L39_0024D760->f38, 0);
    this->fCBC = 1;
    this->f2B1 = 1;
    this->f16C8 = 1;
}
/* localdecomp:end func_L39_006A5AF0 */
