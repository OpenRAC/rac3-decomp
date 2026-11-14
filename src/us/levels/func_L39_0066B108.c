#include "common.h"

/* NTSC-U counterpart of func_L39_0066D938 (src/levels/shared/L39_0066D938.c) */
/* localdecomp:start func_L39_0066B108 */
extern u8 D_001A5E50[];
extern void func_L39_0061BB00(void);
extern void func_L39_0066B188(void *, s32, u8, u8);

void func_L39_0066B108(u8 *s, s32 a1, u8 a2, u8 a3) {
    if (*(s32 *)(s + 0x34) == *(s32 *)(D_001A5E50 + 8)) {
        func_L39_0061BB00();
    }
    func_L39_0066B188(s, a1, a2, a3);
    *(s32 *)(s + 0x34) = -1;
    *(s32 *)(s + 4) = -1;
}
/* localdecomp:end func_L39_0066B108 */
