#include "common.h"

/* NTSC-U version of func_L39_005FBE08 (src/levels/shared/L39_005FB708.c): 0x2EE -> 0x384 (15 s at 60 Hz) */
/* localdecomp:start func_L39_005F9670 */
typedef struct S_005FBE08 {
    u8 pad00[0x100];
    f32 f100;
    f32 f104;
    f32 f108;
    f32 f10C;
    u8 pad110[0x90];
    s32 i1A0;
} S_005FBE08;

extern S_005FBE08 *D_L39_002412E4;
extern s32 D_001D9718_sda_005F9670;
__asm__(".extern D_001D9718_sda_005F9670, 4");
extern s32 D_L39_002412AC;
extern s32 D_L39_00240508_005F9670;
extern s32 D_001D4C78_sda_005F9670;
__asm__(".extern D_001D4C78_sda_005F9670, 4");
extern s32 D_L39_00242B14;
extern s32 D_001D5BCC_sda_005F9670;
__asm__(".extern D_001D5BCC_sda_005F9670, 4");
extern s32 D_L39_002019F8[];
extern s32 D_L39_0024C118;
extern s32 D_L39_002433A0;

void func_L39_005F9670(void) {
    S_005FBE08 *p = D_L39_002412E4;

    if (p->i1A0 != 0 || p->f108 != 0.0f || p->f10C != 0.0f || p->f100 != 0.0f || p->f104 != 0.0f) {
        D_001D9718_sda_005F9670 = 0;
    } else {
        D_001D9718_sda_005F9670 = D_001D9718_sda_005F9670 + 1;
    }
    D_L39_002412AC = D_L39_002412AC + 1;
    D_001D4C78_sda_005F9670 = D_L39_00240508_005F9670 + 1;
    if (D_L39_00242B14 != 0 && D_001D9718_sda_005F9670 < 0x384) {
        D_L39_002019F8[D_001D5BCC_sda_005F9670]++;
    }
    if (D_L39_0024C118 != D_L39_00240508_005F9670 - 1) {
        D_L39_002433A0 = -1;
    }
}
/* localdecomp:end func_L39_005F9670 */
