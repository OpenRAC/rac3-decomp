#include "common.h"

/* NTSC-U counterpart of func_L39_0068B768 (src/levels/39_multiplayer_menu/L39_0068B768.c) */
/* localdecomp:start func_L39_00688B68 */
extern s32 D_001A4560[];
extern s32 D_001D4CE8_sda_00688B68;
extern s32 D_001DC3D4_sda;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_L39_002415C0;
extern s32 func_L01_00513928(s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_00686EC8(void);

typedef void (*Fn_0068B768)(void *);
typedef struct {
    u8 pad0[0x60];
    Fn_0068B768 *vt;
} Obj_0068B768;

void func_L39_00688B68(Obj_0068B768 *a) {
    s32 mode = D_001A4560[2];
    s32 x;

    if (mode == 2) {
        if (D_001A4560[4] != 0 || (x = D_001D4CE8_sda_00688B68) == 0x12) {
            func_L01_00513928(10);
            D_001DC3D4_sda = 1;
            return;
        }
        if (x == 1) {
            func_L39_005BD7D8(0x12, 1, 3, 0, 0);
            D_L39_002415C0 = x;
            a->vt[60](a);
            func_L39_00686EC8();
            D_001DC3D4_sda = mode;
            return;
        }
    }
    D_001DC3D4_sda = 3;
}
/* localdecomp:end func_L39_00688B68 */
