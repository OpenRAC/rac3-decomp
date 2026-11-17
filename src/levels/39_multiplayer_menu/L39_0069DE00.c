#include "common.h"

/* localdecomp:start func_L39_0069DE00 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069DE00(void *);

extern void func_L39_0067F168();
void func_L39_0069DE00(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069DE00 */

/* localdecomp:start func_L39_0069DE30 */
typedef struct O_0069DE30 O_0069DE30;
typedef struct {
    u8 pad0[0x30];
    void (*f30)(O_0069DE30 *, f32 *, f32 *);
    u8 pad34[0x50 - 0x34];
    void (*f50)(O_0069DE30 *, s32);
    u8 pad54[0x64 - 0x54];
    s32 (*f64)(O_0069DE30 *);
    u8 pad68[0x88 - 0x68];
    void (*f88)(O_0069DE30 *, s32);
    s32 (*f8C)(O_0069DE30 *);
    u8 pad90[0xA8 - 0x90];
    void (*fA8)(O_0069DE30 *, s32);
    s32 (*fAC)(O_0069DE30 *);
} V_0069DE30;
struct O_0069DE30 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x60 - 8];
    V_0069DE30 *vt;
};
typedef struct {
    u8 b0;
    u8 b1;
    s32 f4;
} E_0069DE30;
typedef struct {
    u8 f4;
    u8 f5;
    s32 f8;
} QE_0069DE30;
typedef struct {
    u8 pad0[4];
    QE_0069DE30 e[3];
    u8 f1C;
    u8 pad1D[0x171 - 0x1D];
    u8 f171;
} Q_0069DE30;
typedef struct {
    u8 pad0[0x110];
    O_0069DE30 *objs[6];
    u8 pad128[0];
    O_0069DE30 *f128;
    u8 pad12C[0x290 - 0x12C];
    s32 f290;
    u8 pad294[0x2A8 - 0x294];
    s32 f2A8;
    u8 f2AC;
    u8 pad2AD[3];
    E_0069DE30 e[3];
    Q_0069DE30 *f2C8;
} S_0069DE30;

extern s32 D_001DCC24_sda;
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
s32 func_L39_00688340(s32, s32, s32);
s32 func_L39_0068AEF8(void *, s32);
void func_L39_0069E1B0(void *);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

s32 func_L39_0069DE30(S_0069DE30 *this, s32 arg1) {
    this->f128->vt->f50(this->f128, D_001DCC24_sda);
    if (arg1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        if (this->f2C8 != 0) {
            s32 i;
            this->f2C8->f1C = this->f2A8;
            this->f2C8->f171 = this->f2AC;
            for (i = 0; i < 3; i++) {
                this->f2C8->e[i].f8 = this->e[i].f4;
                this->f2C8->e[i].f4 = this->e[i].b0;
                this->f2C8->e[i].f5 = this->e[i].b1;
            }
        }
        D_L39_00247914[0x284 / 4] = 0x2C;
        return 1;
    }
    if (func_L39_0068AEF8(this, arg1) != 0) {
        if (this->f290 == 0) {
            this->f2A8 = this->objs[0]->vt->f8C(this->objs[0]);
            this->objs[1]->vt->f88(this->objs[1], this->e[this->f2A8].b1);
            if (this->f2A8 == 0) {
                this->objs[2]->vt->f88(this->objs[2], this->e[0].b0 ^ 1);
            } else {
                this->objs[2]->vt->f88(this->objs[2], this->e[this->f2A8].b0);
            }
            this->objs[3]->vt->fA8(this->objs[3], this->e[this->f2A8].f4);
            func_L39_0069E1B0(this);
        }
        if (this->f290 == 1) {
            this->e[this->f2A8].b1 = this->objs[1]->vt->f8C(this->objs[1]) != 0;
        }
        if (this->f290 == 2) {
            if (this->f2A8 == 0) {
                this->e[this->f2A8].b0 = (this->objs[2]->vt->f8C(this->objs[2]) ^ 1) != 0;
            } else {
                this->e[this->f2A8].b0 = this->objs[2]->vt->f8C(this->objs[2]) != 0;
            }
        }
        if (this->f290 == 3) {
            this->e[this->f2A8].f4 = this->objs[3]->vt->fAC(this->objs[3]);
        }
        if (this->f290 == 5) {
            this->f2AC = this->objs[5]->vt->f64(this->objs[5]);
        }
        return 1;
    }
    if (this->f290 != -1) {
        f32 x;
        f32 y;
        s32 first;
        s32 last;
        s32 i;
        s32 t;
        this->objs[this->f290]->vt->f30(this->objs[this->f290], &x, &y);
        first = -1;
        last = -1;
        for (i = 0; i < 6; i++) {
            if ((t = this->objs[i]->f4) == 3 || t == 4 || t == 5) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        func_L39_0068A2D0(this, (this->f290 != first) | (this->f290 != last ? 2 : 0), 3, 3, 0.5f, y);
    }
    return 0;
}
/* localdecomp:end func_L39_0069DE30 */
