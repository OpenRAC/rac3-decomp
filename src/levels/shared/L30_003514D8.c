#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern void func_003C2880(u8 *p);

/* localdecomp:start func_L30_003514D8 */
extern void func_003C2880(u8 *p);
typedef struct {
    u8 pad[0x80];
} S_1A30B0;

extern S_1A30B0 D_001A30B0[];
extern s32 D_001A71A0[];
extern void func_003A4F28(s32);

void func_L30_003514D8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i = *(s32 *)(v + 0x20);

    if (i != -1) {
        u8 *p = (u8 *)&D_001A30B0[i];
        if (*(s32 *)(p + 0xDC) == D_001A71A0[0] && *(p + 0xD0) != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 0x20) = -1;
    ((void (*)(void *))func_003C2880)(m);
}
/* localdecomp:end func_L30_003514D8 */
