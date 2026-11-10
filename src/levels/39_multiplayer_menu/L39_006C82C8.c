#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C82C8 */
typedef struct O_006C82C8 O_006C82C8;
typedef struct {
    u8 pad[0x1C];
    void (*f1C)(O_006C82C8 *, s32, s32);
    u8 pad20[0x40 - 0x20];
    void (*f40)(O_006C82C8 *, s32);
    u8 pad44[0x48 - 0x44];
    void (*f48)(O_006C82C8 *, s32, s32);
    void (*f4C)(O_006C82C8 *, s32, s32);
    u8 pad50[0x6C - 0x50];
    void (*f6C)(O_006C82C8 *, s32, s32 *);
    u8 pad70[0x84 - 0x70];
    void (*f84)(O_006C82C8 *, s32);
    u8 pad88[0x90 - 0x88];
    void (*f90)(O_006C82C8 *, f32);
} Vt_006C82C8;
struct O_006C82C8 { u8 pad[0x60]; Vt_006C82C8 *vt; };
typedef struct {
    u8 pad[0x110];
    O_006C82C8 *a;
    O_006C82C8 *b;
    O_006C82C8 *c;
    u8 pad11C[0x29C - 0x11C];
    u8 flag;
    u8 pad29D[0x2A8 - 0x29D];
    s32 unk2A8;
    s32 pad2AC;
    s32 unk2B0;
} S_006C82C8;
s32 func_L39_0067F100(s32);
void func_L39_0068A9B8(s32);
void func_L39_00689BD8(void *, s32);
void func_L39_00689D28(void *, s32);
void func_L39_0068AAB8(void *);
extern s32 func_00381FF0();

void func_L39_006C82C8(S_006C82C8 *self) {
    s32 names[1];

    func_L39_0067F100(0x440000);
    if (self->flag == 0) {
        func_L39_0068A9B8(0);
        func_L39_00689BD8(self, func_00381FF0(0xFB6));
        func_L39_00689D28(self, func_00381FF0(0x124));
        self->a->vt->f1C(self->a, 0, 0);
        self->c->vt->f1C(self->c, 0, 0);
    } else {
        self->a->vt->f1C(self->a, 1, 0);
        self->c->vt->f1C(self->c, 0, 0);
    }
    func_L39_0068AAB8(self);
    names[0] = func_00381FF0(0x100B);
    self->b->vt->f6C(self->b, 1, names);
    self->b->vt->f1C(self->b, 2, 0);
    self->b->vt->f84(self->b, 1);
    self->b->vt->f4C(self->b, 0x40, 1);
    self->b->vt->f40(self->b, 1);
    self->a->vt->f4C(self->a, 0x40, 1);
    self->c->vt->f4C(self->c, 0x40, 1);
    if (self->flag != 0) {
        self->b->vt->f48(self->b, 1, 0);
    }
    self->b->vt->f90(self->b, 0.05f);
    self->unk2B0 = -1;
    self->unk2A8 = -1;
}
/* localdecomp:end func_L39_006C82C8 */
