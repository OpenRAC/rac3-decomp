#include "common.h"

/* NTSC-U counterpart of func_L02_0039CE20 (src/levels/02_florana/L02_0039C730.c) */
#include "vu0.h"

/* localdecomp:start func_L02_0039B1E0 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_39CE20;
typedef struct B_39CE20 {
    char pad0[0x6C];
    int f6C;
    float f70;
    int f74;
    short f78;
    short f7A;
    short f7C;
    short f7E;
    float f80, f84, f88, f8C;
} B_39CE20;
typedef struct S_39CE20 {
    char pad0[0x10];
    float f10, f14, f18, f1C;
    unsigned char f20;
    char pad21[0x47];
    B_39CE20 *p68;
    char pad6C[0x84];
    float fF0;
} S_39CE20;
typedef struct G_39CE20 {
    char pad0[0x35C];
    struct S_39CE20 *f35C;
    int f360;
} G_39CE20;
extern G_39CE20 D_001A4BE0_39CE20;
__asm__(".extern D_001A4BE0_39CE20, 16");
extern void func_L02_0039B4E0();
extern int func_L01_004A6D20(void *, int);
extern int func_0039FE80(int, int, void *);
extern int func_003883C8(void *);
extern void func_L01_00440A88(V4_39CE20 *v, float a, float b);
extern float func_003BE6A8(float a, float b, float c);

void func_L02_0039B1E0(S_39CE20 *self) {
    B_39CE20 *p = self->p68;
    V4_39CE20 tmp;
    func_L02_0039B4E0(self);
    if (self->f20 != 0) {
        if (func_L01_004A6D20(self, p->f74) == 0) {
            p->f74 = func_0039FE80(0, 4, self);
        }
    }
    switch (self->f20) {
    case 1:
        if (D_001A4BE0_39CE20.f35C == self && D_001A4BE0_39CE20.f360 >= 2) {
            self->f20 = 2;
            p->f78 = p->f7C;
            p->f70 = 1.0f / p->f78;
            func_0039FE80(2, 0, self);
        }
        break;
    case 2:
        if (func_003883C8(&p->f78)) {
            p->f6C &= -2;
            self->f20 = 3;
            p->f78 = p->f7E;
            p->f70 = 1.0f / p->f78;
            self->f10 = p->f80;
            self->f14 = p->f84;
            self->f18 = p->f88;
            self->f1C = p->f8C;
            p->f7A = 1;
            func_0039FE80(3, 0, self);
        } else if (p->f7A != 0) {
            p->f80 = self->f10;
            p->f84 = self->f14;
            p->f88 = self->f18;
            p->f8C = self->f1C;
            func_L01_00440A88(&tmp, 0.0f, 0.1f);
            vec_add_ab(&self->f10, &self->f10, &tmp);
            p->f7A = 0;
        } else {
            self->f10 = p->f80;
            self->f14 = p->f84;
            self->f18 = p->f88;
            self->f1C = p->f8C;
            p->f7A = 1;
        }
        break;
    case 3:
        if (func_003883C8(&p->f78)) {
            p->f78 = 300;
            self->f20 = 4;
        } else {
            self->fF0 = func_003BE6A8(1.3089969f, 0.0f, p->f78 * p->f70);
        }
        break;
    case 4:
        if (func_003883C8(&p->f78)) {
            func_0039FE80(3, 0, self);
            p->f78 = p->f7E * 3;
            p->f70 = 1.0f / p->f78;
            self->f20 = 5;
        }
        break;
    case 5:
        if (func_003883C8(&p->f78)) {
            self->f20 = 1;
        } else {
            self->fF0 = func_003BE6A8(0.0f, 1.3089969f, p->f78 * p->f70);
        }
        break;
    case 6:
        break;
    }
}
/* localdecomp:end func_L02_0039B1E0 */
