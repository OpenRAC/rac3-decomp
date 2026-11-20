#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

/* localdecomp:start func_L39_006AF168 */
typedef struct {
    s32 type;
    u8 text[0x34];
    f32 color[4];
} Label_006AF168;
typedef struct {
    Label_006AF168 base;
    u8 f48;
    u8 pad49[3];
    s32 f4C;
} S1_006AF168;
typedef struct {
    Label_006AF168 base;
    u8 text[0x400];
} S2_006AF168;
typedef struct {
    Label_006AF168 base;
    s32 f48;
    s32 f4C;
    void *f50;
    void *f54;
    u8 pad58[0x1D0 - 0x58];
} S3_006AF168;
extern u8 D_L39_0047DEA0[];
extern u8 D_L39_00248C28[];
extern u8 D_L39_00248C30[];
extern void *func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);
extern u8 *func_00381FF0(s32);
extern void func_00120D28(void *, void *, s32);

/* construct a label with its text and colour */
static __inline__ void label_init_006AF168(Label_006AF168 *l, u8 *text, f32 r, f32 g, f32 b, f32 a)
{
    l->type = 0;
    func_L39_0068CD28((u8 *)l, (s32)text, r, g, b, a);
}

void *func_L39_006AF168(u8 *self) {
    S1_006AF168 s1;
    S2_006AF168 s2;
    S3_006AF168 s3;
    S3_006AF168 *p;
    u8 *str;
    s32 style = 0x21;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047DEA0;
    *(void **)(self + 0x2A4) = self + 0x2AC;
    label_init_006AF168(&s1.base, D_L39_00248C28, 0.5f, 0.235f, 0.8f, 0.165f);
    s1.f4C = style;
    s1.base.type = 4;
    s1.f48 = 0;
    str = func_00381FF0(0x117C);
    s2.base.type = 0;
    func_L39_0068CD28((u8 *)&s2, (s32)D_L39_00248C30, 0.5f, 0.6f, 0.78f, 0.44f);
    s2.base.type = 9;
    if (str == 0) {
        s2.text[0] = 0;
    } else {
        func_00120D28(s2.text, str, 0x3FF);
        s2.text[0x3FF] = 0;
    }
    p = &s3;
    label_init_006AF168(&p->base, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->f48 = 0x2E;
    s3.f4C = 0;
    s3.base.color[0] = 0.0f;
    s3.base.color[1] = 0.0f;
    p->base.color[2] = 1.0f;
    p->base.color[3] = 1.0f;
    s3.f54 = &s2;
    s3.f4C = 2;
    s3.f50 = &s1;
    func_L39_00689670(self, p);
    return self;
}
/* localdecomp:end func_L39_006AF168 */

LINKER_REMNANT("asm/levels", func_L39_006AF2E8);
