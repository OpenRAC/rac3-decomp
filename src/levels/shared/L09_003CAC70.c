#include "common.h"

typedef int Q_003CAE68 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    void *pDC;
} Slot_003CAE68;
typedef struct {
    u8 pad0[0xC0];
    f32 v270[4];
    u8 padD0[0x58];
    s16 h128;
} Obj_003CAE68;
typedef struct {
    u8 pad0[0x6B0];
    f32 f6B0[4];
    u8 pad6C0[0x10];
    Obj_003CAE68 *p6D0;
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
} Sub_003CAE68;
typedef struct {
    u8 pad0[0x68];
    Sub_003CAE68 *sub;
    u8 pad6C[0x50];
    u8 bBC;
    u8 padBD[0x3B];
    f32 fF8;
} Self_003CAE68;

INCLUDE_ASM("asm/levels", func_L09_003CAC70);

/* localdecomp:start func_L09_003CACB0 */
extern u8 D_001A4BE0[];
extern s32 D_L09_001DFBC0;
extern s32 D_L09_001DFBC8;
extern f32 D_L09_001DF9D0;
__asm__(".extern D_L09_001DFBC0, 16");
__asm__(".extern D_L09_001DFBC8, 16");
__asm__(".extern D_L09_001DF9D0, 16");
extern s32 D_L09_002D1E30[];
extern s32 D_L09_001D6694[];
extern s32 D_L09_001D6694_003CACB0;
extern s32 D_L09_001D6690;
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L09_003C7B78(u8 *);
extern void func_L09_005164C0(s32, s32);
extern void func_L09_003CAC70(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L09_003CACB0(u8 *self) {
    s32 v;
    f32 d;
    u8 *p;
    u8 *hero;

    d = func_L01_0040E548(D_001A4BE0 + 0x80, self + 0x10);
    p = *(u8 **)(self + 0x68);
    if (d < 12.0f) {
        if (D_L09_001DFBC0 < 4 || D_L09_001DFBC8 < 4) {
            return;
        }
        hero = D_001A4BE0;
        if (*(s32 *)(hero + 0x25CC) != 0x1F
            && *(f32 *)(p + 0x30) > 0.0f && hero[0x25E4] == 0 && D_L09_001DF9D0 == 0.0f) {
            s32 st = *(s32 *)(hero + 0x25C4);
            if (st == 0x1D || st == 0x74 || st == 1) {
                return;
            }
            if (D_L09_002D1E30[0] != 4) {
                if (D_L09_002D1E30[0] != 0) {
                    return;
                }
                v = D_L09_001D6694[0];
            } else {
                v = D_L09_001D6694_003CACB0;
            }
            if (v == 2 || D_L09_001D6690 == 2) {
                return;
            }
            if (*(s16 *)(hero + 0x288C) == 0) {
                func_L01_00452560(0, 4, 0x8C2, 1, 0, 0, 0);
                if (*(u32 *)(*(u8 **)0x1D52FC + 0x1A4) & 0x10) {
                    func_L09_003C7B78(self);
                    func_L09_005164C0(0x31, 1);
                    func_L09_003CAC70(self);
                    func_L01_004450F0(self, 2, -1);
                    *(u16 *)(*(u8 **)(self + 0x68) + 0x710) |= 4;
                }
            }
        }
    }
}
/* localdecomp:end func_L09_003CACB0 */

/* localdecomp:start func_L09_003CAE58 */
s32 func_L09_003CAE58(u8 *obj) {
    return obj[32] == 2;
}
/* localdecomp:end func_L09_003CAE58 */

/* localdecomp:start func_L09_003CAE68 */
extern u8 D_001A30B0[];

extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_004AB048(s32, s32);
extern void func_003A53E8(s32, s32);
extern s32 func_0038CB00(s16 *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

void func_L09_003CAE68(Self_003CAE68 *self) {
    Sub_003CAE68 *s = self->sub;
    s32 a;
    s32 b;
    f32 t;
    f32 f;
    f32 d;
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    s32 i;

    if (s->state788 == 1) {
        if (func_L09_003CAE58((u8 *)self)) {
            func_003A52A0(4, 0, self);
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->state788 = 0;
            s->h77C = -1;
            return;
        }
        if (self->bBC == 10) {
            func_003A52A0(9, 0, self);
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h778 = -1;
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h77C = -1;
            {
                s32 h = s->h780;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h780 = -1;
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h784 = -1;
            s->state788 = 2;
            return;
        }
        {
            s32 h = s->h780;
            if (!(h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0)) {
                s->h780 = func_003A52A0(5, 4, self);
            }
        }
        if (func_0038CB00(&s->h7A2) == 0) {
            t = (f32)s->h7A2 * 0.016666668f;
            a = (s32)(t * (f32)(s->h7A0 + 0x17D)) - 0x17D;
            b = (s32)(t * 1024.0f);
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_L01_004AB048(h, a);
                    func_003A53E8(s->h77C, b);
                }
            }
            {
                s32 h = s->h780;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A53E8(h, 0x400 - b);
                }
            }
            return;
        }
        {
            s32 h = s->h77C;
            if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                func_003A4F28(h);
            }
        }
        s->h77C = -1;
        return;
    }
    if (s->state788 == 0) {
        if (func_L09_003CAE58((u8 *)self) == 0) {
            s->h7A2 = 0x3C;
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h778 = -1;
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h784 = -1;
            s->state788 = 1;
            return;
        }
        if (self->bBC == 10) {
            func_003A52A0(9, 0, self);
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h778 = -1;
            {
                s32 h = s->h77C;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h77C = -1;
            {
                s32 h = s->h780;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h780 = -1;
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h784 = -1;
            s->state788 = 2;
            return;
        }
        {
            s32 h = s->h780;
            if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                func_003A4F28(h);
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
                if (!(h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0)) {
                    s->h778 = func_003A52A0(7, 4, self);
                }
            }
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_L01_004AB048(h, b);
                    func_003A53E8(s->h778, 400);
                }
            }
        } else {
            {
                s32 h = s->h778;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h778 = -1;
        }
        f = func_0038CEA8(s->p6D0->v270);
        {
            s32 h = s->h77C;
            if (!(h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0)) {
                s->h77C = func_003A52A0(6, 4, self);
            }
        }
        if (s->p6D0->h128 == 0) {
            s->h7A0 = (s32)(f * 3429.0f) - 0x17D;
        }
        {
            s32 h = s->h77C;
            if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                func_L01_004AB048(h, s->h7A0);
            }
        }
        func_00382760(v0, 1.0f, func_0038DAB8(self->fF8, s->f74C), 0.0f);
        func_0038CF68(v1, s->p6D0->v270, 1.0f);
        d = __builtin_fabsf(func_0038CE68(v0, v1));
        if (f > 0.1f && s->p6D0->h128 == 0 && d < 0.5f) {
            {
                s32 h = s->h784;
                if (!(h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0)) {
                    s32 n = func_003A52A0(8, 4, self);
                    s->h784 = n;
                    if (n != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (n << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (n << 7)))->bD0 != 0) {
                        func_L01_004AB048(n, -0x3F8);
                    }
                }
            }
        } else {
            {
                s32 h = s->h784;
                if (h != -1 && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->pDC == self && ((Slot_003CAE68 *)(D_001A30B0 + (h << 7)))->bD0 != 0) {
                    func_003A4F28(h);
                }
            }
            s->h784 = -1;
        }
        for (i = 0; i < 4; i++) {
            if (__builtin_fabsf(s->f6B0[i] - s->f790[i]) > 0.25f) {
                func_003A52A0(1, 0, self);
                break;
            }
        }
        *(Q_003CAE68 *)s->f790 = *(Q_003CAE68 *)s->f6B0;
        return;
    }
    if (s->state788 == 2) {
        if (self->bBC != 10 && self->bBC != 7 && self->bBC != 8) {
            s->state788 = 1;
        }
    }
}
/* localdecomp:end func_L09_003CAE68 */

INCLUDE_ASM("asm/levels", func_L09_003CB6C0);

INCLUDE_ASM("asm/levels", func_L09_003CB7B0);
