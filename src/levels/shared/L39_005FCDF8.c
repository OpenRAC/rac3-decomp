#include "common.h"

/* localdecomp:start func_L39_005FCDF8 */
/* The max store goes through $gp to the same word the lui loads read (0x24CAE0 in level 39, 0x248F60 in 45):
 * level data, so it is the per-function alias D_L39_0024CAE0_005FCDF8 (D_001E13D0_sda failed in level 45). */
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024CAD8, 16");
__asm__(".extern D_L39_0024CADC, 16");
__asm__(".extern D_L39_0024CAE0, 16");
extern s32 *D_L39_0024CAC8[];
extern s32 *D_L39_0024CAD0;
extern s32 D_L39_0024CAD8;
extern s32 D_L39_0024CADC;
extern s32 D_L39_0024CAE0;

__asm__(".extern D_001D9794_sda, 8");
extern s32 D_001D9794_sda[2];
__asm__(".extern D_L39_0024CAE0_005FCDF8, 4");
extern s32 D_L39_0024CAE0_005FCDF8;
extern u32 *func_0013AB50(s32);
extern void func_0013AE38(u32 *, s32 *);
extern void func_001264E0(s32);
extern void func_L39_005FCF18(s32);
extern void func_L39_005FCD78(void);
extern void func_L39_005F64F8(void);

void func_L39_005FCDF8(void) {
    s32 base = (s32)D_L39_0024CAC8[D_L39_0024CADC];
    s32 used = (s32)D_L39_0024CAD0 - base;
    u32 *p;
    s32 over;
    D_001D9794_sda[1] |= 0x1F;
    D_L39_0024CAE0_005FCDF8 = used < D_L39_0024CAE0 ? D_L39_0024CAE0 : used;
    over = D_L39_0024CAD8 < used;
    if (!over || D_L39_0024CADC == 0) {
        D_L39_0024CAD0[0] = 0x70000000;
        D_L39_0024CAD0[1] = 0;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0;
        p = func_0013AB50(1);
        p[0] |= 0xC0;
        func_001264E0(0);
        func_0013AE38(p, D_L39_0024CAC8[D_L39_0024CADC]);
        if (over) {
            func_L39_005FCF18(1);
            func_L39_005FCD78();
        }
    } else {
        D_001D9794_sda[1] = 0;
        func_L39_005F64F8();
    }
}
/* localdecomp:end func_L39_005FCDF8 */
