#include "common.h"

/* NTSC-U counterpart of func_L39_0066D9A8 (src/levels/shared/L39_0066D938.c) */
/* localdecomp:start func_L39_0066B0A0 */
extern s32 func_L39_0066AF80(void *, s32, s32);
extern void func_L39_0061BB00(void *);
extern s32 D_001A5E58[];

void func_L39_0066B0A0(u8 *obj, u8 a1, u8 a2) {
    if (func_L39_0066AF80(obj, a1, a2) != 0) {
        obj[0x50] = a1;
        if (*(s32 *)(obj + 0x34) == D_001A5E58[0]) {
            func_L39_0061BB00(obj);
        }
        *(s32 *)(obj + 0x34) = -1;
        *(s32 *)(obj + 4) = -1;
    }
}
/* localdecomp:end func_L39_0066B0A0 */
