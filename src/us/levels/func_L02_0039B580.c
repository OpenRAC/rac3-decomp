#include "common.h"

/* localdecomp:start func_L02_0039B580 */
typedef struct {
    s32 f0;
    s16 f4;
    s16 f6;
    float f8;
    float fC;
    float v10[4];
    u8 pad20[0x54];
    float f74;
    u8 pad78[0x18];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    s32 fA4;
} B_39B580;
typedef struct {
    u8 pad0[0x18];
    float f18;
    u8 pad1C[4];
    u8 f20;
    u8 pad21[0x47];
    B_39B580 *p68;
    u8 pad6C[0x44];
    u8 fB0;
    u8 padB1[0x43];
    float fF4;
} S_39B580;
typedef struct {
    u8 pad0[0xD0];
    u8 fD0;
    u8 padD1[0xB];
    S_39B580 *fDC;
} E_39B580;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C_sda_0039B580;
__asm__(".extern D_001D545C_sda_0039B580, 4");
extern u8 D_001BBC40[][16];
__asm__(".extern D_001BBC40, 16");
extern u8 D_001A4C60[];
extern s16 *D_L02_0021B4E0[];
extern u8 D_001A30B0[];
extern void func_L01_0044B5C8(void *a, void *b, int c, float x, float y);
extern void func_L02_0039BA00(S_39B580 *);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_003EAB30(s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_003883C8(void *);
extern float func_003BE6A8(float, float, float);
extern s32 func_L01_004A6D20(void *, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern s32 func_0037E0F0(void *, s32, s32);

void func_L02_0039B580(S_39B580 *self) {
    B_39B580 *p = self->p68;
    float one, t, a;
    E_39B580 *e;
    s32 i;
    func_L02_0039BA00(self);
    switch (self->f20) {
    case 1:
        if (p->f0 == -1) break;
        if (func_L01_00453210(D_001A4C60, p->f0) == 0) break;
        if (p->fA4 != 0 && (D_001BBC40[D_001D545C_sda_0039B580][self->fB0] & 0x80)) break;
        if (p->fA0 != -1) func_L01_003EAB30(p->fA0);
        self->f20 = 3;
        p->f74 = 0;
        p->f4 = 120;
        one = 1.0f;
        t = p->f74;
        func_L01_0044B5C8(self, p->v10, 0, one, t);
        break;
    case 2:
        if (p->f0 != -1 && func_L01_00453210(D_001A4C60, p->f0) != 0) {
            self->f20 = 4;
            p->f74 = 0;
            p->f4 = 120;
            one = 1.0f;
            t = p->f74;
            func_L01_0044B5C8(self, p->v10, 0, one, t);
        }
        if (p->f98 != 0xFF && D_L02_0021B4E0[p->f98] != 0) {
            if (func_L01_00442998(p->f98, -1, 0) == 0) {
                self->f20 = 4;
                p->f74 = 0;
                p->f4 = 120;
                one = 1.0f;
                t = p->f74;
                func_L01_0044B5C8(self, p->v10, 0, one, t);
            } else {
                if (D_001BBC40[D_001D545C_sda_0039B580][self->fB0] & 0x80) {
                    self->f20 = 4;
                    p->f74 = 0;
                    p->f4 = 120;
                    one = 1.0f;
                    t = p->f74;
                    func_L01_0044B5C8(self, p->v10, 0, one, t);
                }
                break;
            }
        }
        if (D_001BBC40[D_001D545C][self->fB0] & 0x80) {
            self->f20 = 4;
            p->f74 = 0;
            p->f4 = 120;
            one = 1.0f;
            t = p->f74;
            func_L01_0044B5C8(self, p->v10, 0, one, t);
        }
        break;
    case 3:
        if (func_003883C8(&p->f4)) {
            self->f20 = 6;
            break;
        }
        a = (float)p->f4 * p->f8;
        if (p->f90 != 0) {
            p->f74 = func_003BE6A8(6.2831855f, 0.0f, a);
            func_L01_0044B5C8(self, p->v10, 0, 1.0f, 0.0f);
            self->fF4 = func_003BE6A8(-1.5707964f, 0.0f, a);
            self->f18 = func_003BE6A8(p->fC + 10.0f, p->fC, a);
        } else {
            self->fF4 = func_003BE6A8(1.5707964f, 0.0f, a);
        }
        goto tail;
    case 4:
        if (func_003883C8(&p->f4)) {
            self->f20 = 5;
            break;
        }
        a = (float)p->f4 * p->f8;
        if (p->f90 != 0) {
            p->f74 = func_003BE6A8(0.0f, 6.2831855f, a);
            func_L01_0044B5C8(self, p->v10, 0, 1.0f, 0.0f);
            self->fF4 = func_003BE6A8(0.0f, -1.5707964f, a);
            self->f18 = func_003BE6A8(p->fC, p->fC + 10.0f, a);
        } else {
            self->fF4 = func_003BE6A8(0.0f, 1.5707964f, a);
        }
    tail:
        if (func_L01_004A6D20(self, p->f94) == 0) {
            p->f94 = func_0039FE80(0, 4, self);
        }
        break;
    case 5:
    case 6:
        p->f74 = 0;
        one = 1.0f;
        t = p->f74;
        func_L01_0044B5C8(self, p->v10, 0, one, t);
        i = p->f94;
        if (i != -1) {
            e = (E_39B580 *)&D_001A30B0[i << 7];
            if (e->fDC == self && e->fD0 != 0) func_0039FB08(i);
        }
        p->f94 = -1;
        if (self->f20 == 6) {
            if (func_0037E0F0(D_001A4C60, p->f9C, 0) != 0) {
                self->f20 = 4;
                p->f74 = 0;
                p->f4 = 120;
                one = 1.0f;
                t = p->f74;
                func_L01_0044B5C8(self, p->v10, 0, one, t);
            }
        }
        break;
    }
}

/* localdecomp:end func_L02_0039B580 */
