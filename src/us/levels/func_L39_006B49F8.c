#include "common.h"

/* NTSC-U counterpart of func_L39_006B7410 (src/levels/39_multiplayer_menu/L39_006B6A80.c) */
extern s32 D_L39_002415C0;
extern void func_L01_00513928(s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_00686EC8(void);
extern s32 D_L39_002415C0;
extern s32 D_001DDA34_sda;

/* localdecomp:start func_L39_006B49F8 */
typedef struct V_006B7410 {
    char _p0[0xF0];
    void (*fF0)(void *);
} V_006B7410;
typedef struct S_006B7410 {
    char _p0[0x60];
    V_006B7410 *f60;
} S_006B7410;

extern void func_L01_00513928(s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_00686EC8(void);
extern s32 D_001A4568 __attribute__((section(".data")));
extern s32 D_L39_002415C0;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_001DDA34_sda;

void func_L39_006B49F8(S_006B7410 *arg0) {
    if (D_001A4568 == 2) {
        func_L01_00513928(0xA);
        func_L39_005BD7D8(0x12, 1, 3, 0, 0);
        D_L39_002415C0 = 7;
        arg0->f60->fF0(arg0);
        func_L39_00686EC8();
    }
    D_001DDA34_sda = 2;
}
/* localdecomp:end func_L39_006B49F8 */
