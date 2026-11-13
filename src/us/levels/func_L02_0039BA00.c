#include "common.h"

/* NTSC-U counterpart of func_L02_0039D680 (src/levels/02_florana/L02_0039C730.c): 0.01 -> 0.00833333 */
/* localdecomp:start func_L02_0039BA00 */
typedef struct {
    u8 pad0[4];
    s16 f4;
    s16 f6;
    float f8;
    float fC;
    float v10[4];
    u8 pad20[0x54];
    float f74;
    u8 pad78[0x18];
    s32 f90;
    u8 pad94[0x10];
    s32 fA4;
} B_39D680;
typedef struct {
    u8 pad0[0x18];
    float f18;
    u8 pad1C[4];
    u8 f20;
    u8 pad21[0x47];
    B_39D680 *p68;
    u8 pad6C[0x44];
    u8 fB0;
    u8 padB1[0x43];
    float fF4;
} S_39D680;
extern s32 D_001D545C_sda_0039BA00;
__asm__(".extern D_001D545C_sda_0039BA00, 4");
extern u8 D_001BBC40[][16];
__asm__(".extern D_001BBC40, 16");
extern void func_L01_0044B5C8(void *a, void *b, int c, float x, float y);

void func_L02_0039BA00(S_39D680 *self) {
    B_39D680 *p;
    float t;
    u8 st;
    float one;
    if (self->f20 == 0) {
        p = self->p68;
        p->fC = self->f18;
        p->f74 = 0;
        p->f8 = 0.00833333377f;
        one = 1.0f;
        t = p->f74;
        func_L01_0044B5C8(self, p->v10, 0, one, t);
        p->f74 = t;
        func_L01_0044B5C8(self, p->v10, 0, one, t);
        if (p->f6 != 0) {
            if (p->fA4 == 0 || (D_001BBC40[D_001D545C_sda_0039BA00][self->fB0] & 0x80) == 0) {
                if (p->f90 != 0) {
                    self->fF4 = -1.5707964f;
                    self->f18 = p->fC + 10.0f;
                } else {
                    self->fF4 = 1.5707964f;
                }
            }
            st = 2;
        } else st = 1;
        self->f20 = st;
    }
}
/* localdecomp:end func_L02_0039BA00 */
