#include "common.h"

/* NTSC-U counterpart of func_L39_006B7340 (src/levels/39_multiplayer_menu/L39_006B6A80.c) */
extern u8 D_L39_0037C948[];
extern u8 D_L39_0037C948[];
extern s32 D_L39_002415C0;

/* localdecomp:start func_L39_006B4928 */
typedef struct V_006B7340 {
    char _p0[0xF0];
    void (*fF0)(void *);
} V_006B7340;
typedef struct S_006B7340 {
    char _p0[0x60];
    V_006B7340 *f60;
    char _p1[0x259];
    u8 f2BD;
} S_006B7340;

extern void func_L01_00513928(s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_00686EC8(void);
extern void func_L39_006B42E0(void *);
extern void func_L39_006B6010(void *, s32);
extern s32 D_001A4568 __attribute__((section(".data")));
extern s32 D_L39_00240578;
__asm__(".extern D_L39_00240578, 16");
extern s32 D_L39_002415C0;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_001DDA04_sda;
extern s32 D_001DDA34_sda;
extern u8 D_L39_0037C948[];

void func_L39_006B4928(S_006B7340 *arg0) {
    s32 v;
    arg0->f2BD = 0;
    v = D_001A4568;
    if (v == 2) {
        if (D_L39_00240578 == 1) {
            func_L01_00513928(0xA);
            func_L39_005BD7D8(0x12, 1, 3, 0, 0);
            D_L39_002415C0 = 7;
            arg0->f60->fF0(arg0);
            func_L39_00686EC8();
        }
        D_001DDA34_sda = v;
    } else {
        func_L39_006B42E0(D_L39_0037C948 + D_001DDA04_sda * 0x1F0);
        func_L39_006B6010(arg0, 0);
        D_001DDA34_sda = 3;
    }
}
/* localdecomp:end func_L39_006B4928 */
