#include "common.h"

/* localdecomp:start func_L39_006CB8D8 */
extern void func_L39_00688460(void *, void *, void *, void *, void *, void *, f32, f32, f32, f32, f32);

void func_L39_006CB8D8(void *object)
{
    u8 buf[16];

    func_L39_00688460(object, buf, buf, buf, buf, buf, 0.6f, 0.5f, 1.0f, 1.0f, 1.5f);
}
/* localdecomp:end func_L39_006CB8D8 */

/* localdecomp:start func_L39_006CB930 */
typedef struct S_006CB930V {
    u8 pad[0x1C];
    void (*f1C)(void *, s32, s32);
    void (*f20)(void *, s32, s32);
    u8 pad2[0x40 - 0x24];
    void (*f40)(void *, s32);
    void (*f44)(void *, s32, f32, f32);
    u8 pad3[0x4C - 0x48];
    void (*f4C)(void *, s32, s32);
    u8 pad4[0x6C - 0x50];
    s32 (*f6C)(void *, u32, void *);
    u8 pad5[0x88 - 0x70];
    void (*f88)(void *, s32);
} S_006CB930V;
typedef struct S_006CB930D { u8 pad[0x60]; S_006CB930V *vt; } S_006CB930D;
typedef struct S_006CB930C { s32 v[8]; } S_006CB930C;
typedef struct S_006CB930O {
    u8 pad[0x110];
    S_006CB930D *dev[2];
    u8 pad2[0x2A8 - 0x118];
    s32 *p2A8;
    s32 *p2AC;
    s32 pad3;
    u32 n2B4;
    u8 b2B8;
} S_006CB930O;

extern s32 func_L39_0066C7D8(s32);
extern void func_L39_0067F100(s32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0068A6D0(void *, s32, s32, f32, f32, f32, f32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_006B7E68(void *);
extern s32 D_001DE380_sda;
__asm__(".extern D_001DE380_sda, 4");

void func_L39_006CB930(S_006CB930O *object)
{
    S_006CB930C colors;
    S_006CB930C src;
    S_006CB930D **dev;
    s32 i;

    src.v[0] = func_L39_0066C7D8(0);
    src.v[1] = func_L39_0066C7D8(1);
    src.v[2] = func_L39_0066C7D8(2);
    src.v[3] = func_L39_0066C7D8(3);
    src.v[4] = func_L39_0066C7D8(4);
    src.v[5] = func_L39_0066C7D8(5);
    src.v[6] = func_L39_0066C7D8(6);
    src.v[7] = func_L39_0066C7D8(7);
    colors = src;
    func_L39_0067F100(0x420000);
    func_L39_0068AAB8(object);
    func_L39_0068A4A8(object, 0, 1, 0.602f, 0.666f, 0.065f, 0.435f, 0x332299DE);
    func_L39_00689F00(object, 0, 3, 3, 1.5f, 1.5f, 0.435f, 0.048f, 0.05f, 0.1f);
    func_L39_0068A6D0(object, 0, 0x332299DE, 0.602f, 0.667f, 0.455f, 0.15f);

    dev = object->dev;
    for (i = 1; i >= 0; i--) {
        (*dev)->vt->f4C(*dev, 0x40, 1);
        (*dev)->vt->f40(*dev, 1);
        (*dev)->vt->f44(*dev, 1, 0.41500002f, 0.0f);
        dev++;
    }

    if (object->b2B8 != 0) {
        object->dev[0]->vt->f1C(object->dev[0], 3, 0);
        func_L39_0068B2F8(object, 0, 0);
    } else {
        object->dev[0]->vt->f1C(object->dev[0], 2, 0);
        func_L39_0068B2F8(object, 1, 0);
    }
    object->dev[0]->vt->f6C(object->dev[0], (object->n2B4 > 8) ? 8 : object->n2B4, &colors);
    if (object->p2A8 != 0) {
        object->dev[0]->vt->f88(object->dev[0], *object->p2A8);
    }
    if (object->p2AC != 0) {
        object->dev[1]->vt->f88(object->dev[1], *object->p2AC);
    }
    func_L39_006B7E68(&D_001DE380_sda);
}
/* localdecomp:end func_L39_006CB930 */
