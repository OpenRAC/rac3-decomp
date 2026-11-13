#include "common.h"

/* NTSC-U counterpart of func_L39_006BBB38 (src/levels/39_multiplayer_menu/L39_006BBB38.c) */
void func_L39_006C9668(void *, s32);

/* localdecomp:start func_L39_006B9028 */
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_0024D864, 16");
extern u8 D_L39_0024D864;
extern u8 *D_L39_0024D860;
void func_L39_006C9630(void *);
void func_L39_006C9E40(void *);
void func_L39_00687728(void *, s32, s32, s32, f32, f32);
void func_L39_00688750(void *, s32, s32);
void func_L39_0067C648(void);
void func_L39_00688220(void *);
void func_L39_006C9668(void *, s32);

void func_L39_006B9028(u8 *arg0) {
    u8 buf[0x1E0];

    D_L39_0024D864 = 0;
    func_L39_006C9630(buf);
    func_L39_006C9E40(buf);
    *(u8 *)(*(u8 **)(D_L39_0024D860 + 0x4C) + 0x168) = 0;
    *(u8 *)(*(u8 **)(D_L39_0024D860 + 0x70) + 0x10) = 0;
    func_L39_00687728(arg0, 0, 3, 3, 0.0f, 0.0f);
    func_L39_00688750(arg0, 4, 0);
    func_L39_0067C648();
    func_L39_00688220(arg0);
    func_L39_006C9668(buf, 2);
}
/* localdecomp:end func_L39_006B9028 */
