#include "common.h"

/* NTSC-U counterpart of func_L07_003323F8; retail voice calls use 120, not PAL's 100. */
/* localdecomp:start func_L07_00331CB8 */
typedef struct { u8 pad[4]; u8 *rows; u8 gap[8]; } T_331CB8;
typedef struct { u8 pad[0x44]; s32 groups[3]; u8 gap[0x4E]; u8 mode, index; } V_331CB8;
extern T_331CB8 D_L07_002B0D40[];
extern u8 D_L07_001DCEF8;
__asm__(".extern D_L07_001DCEF8, 1");
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 *D_L07_001DF41C;
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L07_003A0BC0(u8, void *, s32, s32);
extern u8 *func_L07_003333E0(u8 *);
void func_L07_00331CB8(u8 *self) {
    V_331CB8 *v = *(V_331CB8 **)(self + 0x68);
    u8 *row = D_L07_002B0D40[v->mode].rows + v->index * 12;
    u8 *values = &D_L07_001DCEF8 + row[1] * 3;
    s32 said = 0;
    s32 i;
    for (i = 0; i < 3; i++) {
        u16 *p;
        if (v->index && values[i] != 1) {
            u8 *previous = &D_L07_001DCEF8 + (D_L07_002B0D40[v->mode].rows + v->index * 12)[-11] * 3;
            if (values[i] != previous[i] && !said && func_0037E1D8(2)) {
                switch (i) {
                    case 0:
                        if (values[0] == 2)
                            func_L07_003A0BC0(func_0037E208(35,36), self, 0,120);
                        else
                            func_L07_003A0BC0(func_0037E208(29,30), self, 0,120);
                        break;
                    case 1:
                        func_L07_003A0BC0(func_0037E208(31,32), self, 0,120);
                        break;
                    case 2:
                        func_L07_003A0BC0(func_0037E208(33,34), self, 0,120);
                        break;
                }
                said = 1;
            }
        }
        for (p = D_L07_0021C020[v->groups[i]];
             (v->groups[i] & 255) != 255 && v->groups[i] <= D_L07_001DF458 && p;
             p++) {
            u8 *obj;
            u8 *r;
            if (((s16 *)p)[-1] < 0 && p != D_L07_0021C020[v->groups[i]]) break;
            obj = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
            if (!obj) break;
            r = (u8 *)func_L07_003333E0(obj);
            r[8] = values[i];
        }
    }
}
/* localdecomp:end func_L07_00331CB8 */
