#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_0040E918 */
extern vu0_v4 D_L14_001E20C0;
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L14_0040E918(u8 *p) {
    vu0_v4 off;
    vu0_v4 out;
    vu0_v4 a;
    vu0_v4 b;
    *(vu0_q *)&off = 0;
    off.y = 2.0f;
    off.z = 6.0f;
    if (p != 0) {
        a = D_L14_001E20C0;
        b = *(vu0_v4 *)(p + 0x10);
        func_003C4098(&out, &a, &b, 0.5f);
        vec_add_ab(&out, &out, &off);
        func_003D9508(&out, 0xB, 0x30406080, 1, 15.0f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L14_0040E918 */

/* localdecomp:start func_L14_0040E9D0 */
extern int D_L14_001EEC50[];

int func_L14_0040E9D0(void)
{
    int i;
    int *base = D_L14_001EEC50;
    int *p = base + 4;
    for (i = 0; i < 0x28; i++) {
        if (*p <= 0)
            return i;
        p += 8;
    }
    return -1;
}
/* localdecomp:end func_L14_0040E9D0 */

/* localdecomp:start func_L14_0040EA08 */
extern s32 D_L14_001E64B4[];
extern u8 D_L14_001EF150[];
void func_L14_0040EA08(void) {
    s32 i;
    u8 *p;
    u8 *base;
    if (D_L14_001E64B4[0] == 1) {
        p = (u8 *)D_L14_001EEC50;
        for (i = 39; i >= 0; i--) {
            qzero(p);
            *(s32 *)(p + 0x10) = 0;
            p += 0x20;
        }
        base = D_L14_001EF150;
        for (i = 0; i < 14; i++) {
            p = base + i * 0x30;
            qzero(p);
            qzero(p + 0x10);
            *(s32 *)(p + 0x24) = 0;
        }
    }
}
/* localdecomp:end func_L14_0040EA08 */

INCLUDE_ASM("asm/levels", func_L14_0040EA78);

INCLUDE_ASM("asm/levels", func_L14_0040EC48);

INCLUDE_ASM("asm/levels", func_L14_0040EF88);

INCLUDE_ASM("asm/levels", func_L14_0040F1B8);
