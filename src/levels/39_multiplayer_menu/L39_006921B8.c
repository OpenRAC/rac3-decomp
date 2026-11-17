#include "common.h"

/* localdecomp:start func_L39_006921B8 */
extern u8 D_L39_0047C968[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006921B8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C968;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006921B8 */

/* localdecomp:start func_L39_006921E0 */
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068AAB8(void *);
extern s32 func_L39_006CEA18(void *, s32);

struct W_006921E0;
typedef struct {
    u8 pad0[0x1C];
    void (*show)(struct W_006921E0 *, s32, void *);
    u8 pad20[0x6C - 0x20];
    s32 (*set)(struct W_006921E0 *, s32, void *);
    u8 pad70[0xB4 - 0x70];
    void (*reset)(struct W_006921E0 *);
} VT_006921E0;
typedef struct W_006921E0 {
    u8 pad[0x60];
    VT_006921E0 *vt;
} W_006921E0;
typedef struct {
    s32 a;
    u8 b;
    u8 c;
    u8 pad2AE[2];
    s32 d;
    u8 rest[0x24C - 0xC];
} P_006921E0;
typedef struct {
    u8 pad0[0x110];
    W_006921E0 *w[5];
    u8 pad124[0x2A8 - 0x124];
    P_006921E0 p[3];
} S_006921E0;
typedef struct {
    u8 pad[0x34];
    u8 on;
} M_006921E0;
typedef struct {
    u8 pad[0x38];
    M_006921E0 *mgr;
} G_006921E0;
__asm__(".extern D_L39_0024D760, 16");
extern G_006921E0 *D_L39_0024D760;

void func_L39_006921E0(S_006921E0 *self) {
    s32 text[3];
    M_006921E0 *mgr;

    func_L39_0067F100(0x260000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xFCF));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068AAB8(self);

    text[0] = func_00381FF0(0x1011);
    self->w[0]->vt->set(self->w[0], 1, &text[0]);
    self->w[0]->vt->show(self->w[0], 2, 0);
    text[1] = func_00381FF0(0x1012);
    self->w[1]->vt->set(self->w[1], 1, &text[1]);
    self->w[1]->vt->show(self->w[1], 2, 0);
    text[2] = func_00381FF0(0x1013);
    self->w[2]->vt->set(self->w[2], 1, &text[2]);
    self->w[2]->vt->show(self->w[2], 2, 0);

    self->w[3]->vt->reset(self->w[3]);
    self->w[3]->vt->show(self->w[3], 0, 0);
    self->w[4]->vt->show(self->w[4], 0, 0);

    self->p[0].b = 0;
    self->p[0].c = 0;
    self->p[0].d = 0;
    self->p[0].a = 0;
    self->p[1].b = 0;
    self->p[1].c = 0;
    self->p[1].d = 0;
    self->p[1].a = 0;
    self->p[2].b = 0;
    self->p[2].c = 0;
    self->p[2].d = 0;
    self->p[2].a = 0;

    mgr = D_L39_0024D760->mgr;
    func_L39_006CEA18(mgr, 0);
    if (mgr->on) {
        self->w[3]->vt->show(self->w[3], 2, 0);
        self->w[4]->vt->show(self->w[4], 2, 0);
    }
    self->p[0].b = 1;
    self->p[1].b = 1;
    self->p[2].b = 1;
}
/* localdecomp:end func_L39_006921E0 */

/* localdecomp:start func_L39_006923F0 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006923F0(void *);

extern void func_L39_0067F168();
void func_L39_006923F0(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006923F0 */
