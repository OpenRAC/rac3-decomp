#include "common.h"

/* localdecomp:start func_L39_005E6B08 */
__asm__(".extern D_001D8448_sda, 4");
__asm__(".extern D_001D8478_sda, 4");
typedef struct { s32 f0; u8 f4; u8 pad5[3]; void (*f8)(void); s32 fC; } S_005E6B08;
extern s32 D_001D8448_sda[] __attribute__((section(".sdata")));
extern S_005E6B08 D_001D8478_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00243B90, 16");
extern s32 D_L39_00243B90[][4] __attribute__((section(".sdata")));
extern s32 func_L01_00517688(void);
extern s32 func_L01_004910C0(s32);
extern s32 func_L01_00517748(s32);
extern s32 func_L01_0049F168(s32);
extern void func_L01_00353C80(s32);
extern s32 func_L39_005F3548(s32, s32, s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);

void func_L39_005E6B08(s32 arg0, s32 arg1) {
    s32 v;
    s32 i;
    if (arg1 & 0x40) {
        if (D_001D8478_sda[D_001D8448_sda[func_L01_00517688()]].f4 != 0
            && (i = D_001D8448_sda[func_L01_00517688()], D_L39_00243B90[i][0] != 0)) {
            S_005E6B08 *e = &D_001D8478_sda[D_001D8448_sda[func_L01_00517688()]];
            e->f8();
        } else {
            func_L39_005F3548(5, 0, 0);
        }
    }
    if (arg1 & 0x900) {
        func_L39_0061C0E0(func_L01_00517688(), 0);
        func_L39_005D6468(func_L01_00517688(), 0);
        func_L01_00353C80(arg0);
    } else if (arg1 & 0x10) {
        v = func_L01_00517688();
        func_L39_005F3548(4, 0, 0);
        func_L01_00517748(func_L01_004910C0(func_L01_00517688()));
        func_L01_00353C80(func_L01_0049F168(v));
    }
}
/* localdecomp:end func_L39_005E6B08 */

/* localdecomp:start func_L39_005E6C78 */
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 D_001D8448_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8448_sda, 8");
extern s32 D_001D8458_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8458_sda, 8");
extern s32 D_001D84B8_sda;

void func_L39_005E6C78(void) {
    s32 k = 0;

    switch (func_L01_00517688()) {
    case 0:
        break;
    case 1:
        k = 1;
        break;
    case 2:
        k = 2;
        break;
    case 3:
        k = 3;
        break;
    }
    D_001D8448_sda[func_L01_00517688()] = func_003B9C58(func_003B9BD0(k));
    if (D_001D8458_sda[func_L01_00517688()] != D_001D8448_sda[func_L01_00517688()]) {
        D_001D84B8_sda = 30;
    }
    if (D_001D84B8_sda != 0) {
        D_001D84B8_sda--;
    }
    D_001D8458_sda[func_L01_00517688()] = D_001D8448_sda[func_L01_00517688()];
}
/* localdecomp:end func_L39_005E6C78 */
