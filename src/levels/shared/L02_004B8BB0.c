#include "common.h"

typedef struct {
    u8 pad0[0x740];
    f32 f740;
    f32 f744;
    u8 pad748[0x25C0 - 0x748];
    u8 *p25C0;
    s32 w25C4;
} S_4B8BB0;

/* localdecomp:start func_L02_004B8BB0 */
extern S_4B8BB0 D_001A4BE0;
extern void func_L01_0044EBA0(u8 *, f32 *, f32 *, f32, f32, f32);

void func_L02_004B8BB0(void) {
    S_4B8BB0 *s = &D_001A4BE0;
    if (s->w25C4 != 0x81 && s->w25C4 != 0x50) {
        return;
    }
    func_L01_0044EBA0(s->p25C0, &s->f740, &s->f744, 0.1745329252f, 0.0314159265f, 0.0418879057f);
}
/* localdecomp:end func_L02_004B8BB0 */
