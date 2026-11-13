#include "common.h"

/* localdecomp:start func_L39_00531668 */
typedef int Q_00531668 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *pDC;
} Slot_00531668;

typedef struct {
    u8 pad0[0x270];
    f32 v270[4];
    u8 pad280[0x80];
    u8 b300;
} Obj_00531668;

typedef struct {
    u8 pad0[0x6B0];
    f32 f6B0[4];
    u8 pad6C0[0x10];
    Obj_00531668 *p6D0;
    u8 pad6D4[0x78];
    f32 f74C;
    u8 pad750[0x28];
    s32 h778;
    s32 h77C;
    s32 h780;
    s32 h784;
    s32 state788;
    s16 h78C;
    u8 pad78E[2];
    f32 f790[4];
    s16 h7A0;
    s16 h7A2;
} Sub_00531668;

typedef struct {
    u8 pad0[0x68];
    Sub_00531668 *sub;
    u8 pad6C[0x50];
    u8 bBC;
    u8 padBD[0x3B];
    f32 fF8;
} Self_00531668;

extern u8 D_001FE020[];
extern s32 func_L39_00531640(s32 a0);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);
extern void func_L39_005F3788(s32, s32);
extern void func_L39_005F3760(s32, s32);
extern s32 func_0038CB00(s16 *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

void func_L39_00531668(Self_00531668 *self) {
    Sub_00531668 *s = self->sub;
    s32 a;
    s32 b;
    f32 t;
    f32 f;
    f32 d;
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    s32 i;

    if (s->state788 == 1) {
        if (func_L39_00531640((s32)self)) {
            func_L39_005F33E0(4, 0, self);
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->state788 = 0;
            s->h77C = -1;
            return;
        }
        if (self->bBC == 10) {
            func_L39_005F33E0(9, 0, self);
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h778 = -1;
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h77C = -1;
            {
                s32 h = s->h780;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h780 = -1;
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h784 = -1;
            s->state788 = 2;
            return;
        }
        {
            s32 h = s->h780;
            if (!(h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0)) {
                s->h780 = func_L39_005F33E0(5, 4, self);
            }
        }
        if (func_0038CB00(&s->h7A2) == 0) {
            t = (f32)s->h7A2 * 0.016666668f;
            a = (s32)(t * (f32)(s->h7A0 + 0x17D)) - 0x17D;
            b = (s32)(t * 1024.0f);
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3788(h, a);
                    func_L39_005F3760(s->h77C, b);
                }
            }
            {
                s32 h = s->h780;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3760(h, 0x400 - b);
                }
            }
            return;
        }
        {
            s32 h = s->h77C;
            if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                func_L39_005F3088(h);
            }
        }
        s->h77C = -1;
        return;
    }
    if (s->state788 == 0) {
        if (func_L39_00531640((s32)self) == 0) {
            s->h7A2 = 0x3C;
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h778 = -1;
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h784 = -1;
            s->state788 = 1;
            return;
        }
        if (self->bBC == 10) {
            func_L39_005F33E0(9, 0, self);
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h778 = -1;
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h77C = -1;
            {
                s32 h = s->h780;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h780 = -1;
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h784 = -1;
            s->state788 = 2;
            return;
        }
        {
            s32 h = s->h780;
            if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                func_L39_005F3088(h);
            }
        }
        s->h780 = -1;
        if (s->h78C > 20) {
            s->h78C = 20;
        }
        if (s->h78C < 0) {
            s->h78C = 0;
        }
        t = (f32)s->h78C * 0.05f;
        t = t * t;
        if (s->h78C != 0) {
            b = (s32)(t * 1016.0f) - 0xFE;
            {
                s32 h = s->h778;
                if (!(h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0)) {
                    s->h778 = func_L39_005F33E0(7, 4, self);
                }
            }
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3788(h, b);
                    func_L39_005F3760(s->h778, 400);
                }
            }
        } else {
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h778 = -1;
        }
        f = func_0038CEA8(s->p6D0->v270);
        {
            s32 h = s->h77C;
            if (!(h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0)) {
                s->h77C = func_L39_005F33E0(6, 4, self);
            }
        }
        if (s->p6D0->b300 == 0) {
            s->h7A0 = (s32)(f * 3429.0f) - 0x17D;
        }
        {
            s32 h = s->h77C;
            if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                func_L39_005F3788(h, s->h7A0);
            }
        }
        func_00382760(v0, 1.0f, func_0038DAB8(self->fF8, s->f74C), 0.0f);
        func_0038CF68(v1, s->p6D0->v270, 1.0f);
        d = __builtin_fabsf(func_0038CE68(v0, v1));
        if (f > 0.1f && s->p6D0->b300 == 0 && d < 0.5f) {
            {
                s32 h = s->h784;
                if (!(h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0)) {
                    s32 n = func_L39_005F33E0(8, 4, self);
                    s->h784 = n;
                    if (n != -1 && ((Slot_00531668 *)(D_001FE020 + (n << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (n << 7)))->bD0 != 0) {
                        func_L39_005F3788(n, -0x3F8);
                    }
                }
            }
        } else {
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->pDC == self && ((Slot_00531668 *)(D_001FE020 + (h << 7)))->bD0 != 0) {
                    func_L39_005F3088(h);
                }
            }
            s->h784 = -1;
        }
        for (i = 0; i < 4; i++) {
            if (__builtin_fabsf(s->f6B0[i] - s->f790[i]) > 0.25f) {
                func_L39_005F33E0(1, 0, self);
                break;
            }
        }
        *(Q_00531668 *)s->f790 = *(Q_00531668 *)s->f6B0;
        return;
    }
    if (s->state788 == 2) {
        if (self->bBC != 10 && self->bBC != 7 && self->bBC != 8) {
            s->state788 = 1;
        }
    }
}
/* localdecomp:end func_L39_00531668 */
