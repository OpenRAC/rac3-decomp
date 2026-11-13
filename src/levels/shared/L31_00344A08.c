#include "common.h"

/* localdecomp:start func_L31_00344A08 */
typedef struct {
    u8 pad0[0x180];
    s16 x180[12];
    s32 x198;
    s32 x19C;
    s32 x1A0;
    u8 x1A4;
    u8 x1A5;
    u8 x1A6;
    u8 x1A7;
    u8 x1A8;
    u8 x1A9;
    u8 pad1AA[2];
    s32 x1AC;
    s32 x1B0;
} V_344A08;

extern s32 D_L31_001DF340;
extern u8 *D_L31_001DF79C;
extern f32 D_001A4C60[];
extern void func_L31_00344F00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00456230(void *, s32);
extern void func_003C2880(void *);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L31_00347CB8(s32, s32, s32, void *);
extern void *func_L31_00344FC8(void *);
extern void func_L31_00344C30(void *, void *, void *);
extern void func_L31_00345398(void *, void *, void *);

void func_L31_00344A08(u8 *o) {
    V_344A08 *p = *(V_344A08 **)(o + 0x68);
    u8 buf[16];
    void *q;
    s32 sum;
    s32 i;

    switch (o[0x20]) {
    case 0:
        func_L31_00344F00(o);
        func_L01_004450F0(o, 2, -1);
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            p->x1AC = D_L31_001DF340;
        }
        if (p->x1A8 != 0 && p->x1AC + p->x1A0 < D_L31_001DF340) {
            if (p->x1B0 != -1) {
                func_L01_00456230(D_L31_001DF79C + (p->x1B0 << 8), 1);
            }
            func_003C2880(o);
            break;
        }
        if (func_L01_00456500(D_001A4C60, p->x19C) != 0 || p->x1A8 != 0) {
            sum = 0;
            for (i = 0; i < p->x1A5; i++) {
                sum += p->x180[i];
                if (func_L31_00347CB8(p->x1A0, p->x1AC + sum, 5, &p->x198) != 0) {
                    q = func_L31_00344FC8(o);
                    func_L31_00344C30(o, q, buf);
                    func_L31_00345398(o, q, buf);
                    p->x198 = D_L31_001DF340;
                }
            }
        } else if (p->x1A9 != 0) {
            p->x1AC = D_L31_001DF340;
        }
        break;
    case 2:
        if (p->x1A7 != 0 && func_L01_00456250(o) == 0) {
            break;
        }
        if (p->x1A8 != 0 && func_L01_00456500(D_001A4C60, p->x19C) == 0) {
            break;
        }
        func_L01_004450F0(o, 1, -1);
        break;
    }
}
/* localdecomp:end func_L31_00344A08 */

INCLUDE_ASM("asm/levels", func_L31_00344C30);
