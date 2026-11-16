#include "common.h"
/* localdecomp:start func_L01_005002B8 */
typedef struct { u8 pad[0x25CC]; s32 state; u8 pad2[0x2850-0x25D0]; s32 flag; } Hero_005002B8;
extern Veldin1A4BE0 D_001A4BE0;
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001D6694, 4");
s32 func_L01_005002B8(s32 state, s32 mode) {
    if (mode == 3) return 1;
    if (((Hero_005002B8 *)&D_001A4BE0)->state == 20 && (state != 101 || mode != 2)) return 0;
    if ((D_L01_001D6694 == 2 || D_L01_001D6694 == 6) && mode != 2) return 0;
    return ((Hero_005002B8 *)&D_001A4BE0)->flag != 0 ||
        (((Hero_005002B8 *)&D_001A4BE0)->state != 2 && ((Hero_005002B8 *)&D_001A4BE0)->state != 7) ||
        state == 6 || state == 57 || state == 67 || state == 86 || state == 99 ||
        state == 159 || state == 160 || state == 121 || state == 125 || state == 126 ||
        state == 129 || state == 80 || state == 108 || state == 130 || state == 132;
}
/* localdecomp:end func_L01_005002B8 */
