#include "common.h"

/* localdecomp:start func_L39_00607418 */
__asm__(".extern D_L39_00242A50, 16");
typedef struct { u8 pad0[0xB0]; f32 xB0; } S_00607418;
extern S_00607418 D_L39_0025D6C0;
extern s32 D_L39_00241118;
extern u8 *D_L39_00242A50;
extern void func_L39_005872D8(void);
extern u8 *func_L39_0061BF38(s32);

void func_L39_00607418(void) {
    f32 saved = D_L39_0025D6C0.xB0;
    u8 *p;
    D_L39_0025D6C0.xB0 = 0.62f;
    func_L39_005872D8();
    func_L39_0061BF38(D_L39_00241118);
    p = D_L39_00242A50;
    *(s32 *)(p + 0x24DA8) = *(s32 *)(p + 0x24DA4) = 0;
    D_L39_0025D6C0.xB0 = saved;
    func_L39_005872D8();
}
/* localdecomp:end func_L39_00607418 */
