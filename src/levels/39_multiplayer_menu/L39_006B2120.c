#include "common.h"

/* localdecomp:start func_L39_006B2120 */
typedef struct O_006B2120 O_006B2120;
typedef struct {
    u8 pad0[0x78];
    s32 (*f78)(O_006B2120 *);
    u8 pad7C[0x88 - 0x7C];
    void (*f88)(O_006B2120 *, s32);
    s32 (*f8C)(O_006B2120 *);
} V_006B2120;
struct O_006B2120 {
    u8 pad0[0x60];
    V_006B2120 *vt;
};
typedef struct {
    u8 pad0[0x110];
    O_006B2120 *f110[(0x290 - 0x110) / 4];
    s32 f290;
    u8 pad294[0x2B0 - 0x294];
    s32 f2B0;
    u8 pad2B4[0x494 - 0x2B4];
    s32 f494;
} S_006B2120;
void func_L39_0068B2F8();

s32 func_L39_006B2120(S_006B2120 *this, s32 arg1) {
    if (arg1 == 3 || arg1 == 4) {
        if (this->f290 == 10) {
            func_L39_0068B2F8(this, this->f2B0, 0);
            return 1;
        }
        if (this->f494 > 0) {
            func_L39_0068B2F8(this, 10, 0);
            return 1;
        }
    }
    if (arg1 == 1 && this->f290 == 0) {
        func_L39_0068B2F8(this, 6, 0);
        return 1;
    }
    if (arg1 == 2 && this->f290 == 6) {
        func_L39_0068B2F8(this, 0, 0);
        return 1;
    }
    if (this->f290 == 10) {
        if (arg1 == 1 && this->f110[this->f290]->vt->f8C(this->f110[this->f290]) == 0) {
            this->f110[this->f290]->vt->f88(this->f110[this->f290], this->f494 - 1);
            return 1;
        }
        if (arg1 == 2 && this->f110[this->f290]->vt->f8C(this->f110[this->f290]) ==
                             this->f110[this->f290]->vt->f78(this->f110[this->f290]) - 1) {
            this->f110[this->f290]->vt->f88(this->f110[this->f290], 0);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006B2120 */

/* localdecomp:start func_L39_006B22B0 */
typedef struct {
    u8 pad0[0x199];
    u8 f199;
} P_006B22B0;
typedef struct {
    u8 pad0[0x4C];
    P_006B22B0 *f4C;
} G_006B22B0;

__asm__(".extern D_L39_0024D760_006B22B0, 16");
extern G_006B22B0 *D_L39_0024D760_006B22B0;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_00195410(void);
void func_L39_006DC148(s32, s32);
s32 func_L39_006DAFC8(P_006B22B0 *);
s32 func_L39_006DB948(P_006B22B0 *, s32, s32, s32, s32);
void func_L04_00523E58(P_006B22B0 *);

s32 func_L39_006B22B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ok = 1;
    P_006B22B0 *p = D_L39_0024D760_006B22B0->f4C;
    s32 i;

    {
        s32 start = (s32)func_00130760(func_0012DCB0(), 0x24000);
        while (p->f199 != 0) {
            func_00195410();
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) {
        ok = ((s32 (*)(P_006B22B0 *, s32))func_L39_006DC148)(p, arg3);
    }
    for (i = 2; i != 0; i--) {
        if (ok) {
            ok = func_L39_006DAFC8(p);
            if (ok) {
                s32 start = (s32)func_00130760(func_0012DCB0(), 0x24000);
                while (p->f199 != 0) {
                    func_00195410();
                    if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ok = func_L39_006DB948(p, arg3, arg2, -1, 0);
                    if (ok) {
                        break;
                    }
                }
            }
        }
    }
    func_L04_00523E58(p);
    return ok;
}
/* localdecomp:end func_L39_006B22B0 */

/* localdecomp:start func_L39_006B2450 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern char *D_001DC204_sda;
void func_L39_006BD408(s32);

s32 func_L39_006B2450(s32 arg0, s32 arg1, s32 arg2) {
    func_L39_006BD408(D_L39_00247914[0xE0 / 4]);
    if (arg2 != 0) {
        *(s32 *)(D_001DC204_sda + 0x284) = 0x1F;
    }
    return 1;
}
/* localdecomp:end func_L39_006B2450 */

INCLUDE_ASM("asm/levels", func_L39_006B2498);
