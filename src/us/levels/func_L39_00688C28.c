#include "common.h"

/* NTSC-U counterpart of func_L39_0068B828 (src/levels/39_multiplayer_menu/L39_0068B768.c) */
/* localdecomp:start func_L39_00688C28 */
typedef void (*Fn_00688C28)(void *);
typedef struct {
    u8 pad0[0x60];
    Fn_00688C28 *vt;
} Obj_00688C28;

extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_00686EC8(void);
extern s32 D_001A4568 __attribute__((section(".data")));
extern s32 D_L39_002415C0;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_001DC3D4_sda;

void func_L39_00688C28(Obj_00688C28 *a) {
    s32 mode = D_001A4568;

    if (mode == 2) {
        func_L39_005BD7D8(0x12, 1, 3, 0, 0);
        D_L39_002415C0 = mode;
        a->vt[60](a);
        func_L39_00686EC8();
    }
    D_001DC3D4_sda = 2;
}
/* localdecomp:end func_L39_00688C28 */
