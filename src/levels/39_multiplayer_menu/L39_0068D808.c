#include "common.h"

/* localdecomp:start func_L39_0068D808 */
typedef struct {
    s32 type;
    u8 text[0x34];
    f32 color[4];
} Label_0068D808;
typedef struct {
    Label_0068D808 base;
    u8 f48;
    u8 pad49[3];
    s32 f4C;
} S1_0068D808;
typedef struct {
    Label_0068D808 base;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[8];
} S2_0068D808;
typedef struct {
    Label_0068D808 base;
    s32 f48;
    s32 f4C;
    void *f50;
    void *f54;
    u8 pad58[0x1D0 - 0x58];
} S3_0068D808;
extern u8 D_L39_0047C620[];
extern u8 D_L39_00247C20[];
extern u8 D_L39_00247C28[];
extern void *func_L39_00688388(void *);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

/* construct a label with its text and colour */
static __inline__ void label_init_0068D808(Label_0068D808 *l, u8 *text, f32 r, f32 g, f32 b, f32 a)
{
    l->type = 0;
    func_L39_0068CD28((u8 *)l, (s32)text, r, g, b, a);
}

void *func_L39_0068D808(u8 *self) {
    S1_0068D808 s1;
    S2_0068D808 s2;
    S3_0068D808 s3;
    S2_0068D808 *q;
    S3_0068D808 *p;
    s32 r1;
    s32 r2;
    s32 n = 8;
    s32 m = -1;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047C620;
    *(void **)(self + 0x2A4) = self + 0x778;
    r1 = func_L39_005B43C8(0x1B, 0x20);
    label_init_0068D808(&s1.base, D_L39_00247C20, 0.5f, 0.27f, 0.8f, 0.25f);
    s1.base.type = 4;
    s1.f4C = r1;
    s1.f48 = 0;
    r2 = func_00381FF0(0x1020);
    q = &s2;
    s2.base.type = 0;
    func_L39_0068CD28((u8 *)q, (s32)D_L39_00247C28, 0.5f, 0.635f, 0.78f, 0.37f);
    s2.base.type = 5;
    s2.f50 = r2;
    s2.f48 = 0;
    s2.f4C = 0;
    q->f54 = n;
    s2.f58 = 0;
    s2.f5C = 0;
    q->f60 = m;
    s2.f64 = 0;
    p = &s3;
    label_init_0068D808(&p->base, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    p->f48 = 0x2E;
    s3.f4C = 0;
    s3.base.color[0] = 0.0f;
    s3.base.color[1] = 0.0f;
    p->base.color[2] = 1.0f;
    p->base.color[3] = 1.0f;
    s3.f54 = q;
    s3.f4C = 2;
    s3.f50 = &s1;
    func_L39_00689670(self, p);
    return self;
}
/* localdecomp:end func_L39_0068D808 */

LINKER_REMNANT("asm/levels", func_L39_0068D9A8);
