#include "common.h"

typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_001CCFD0_003AFF18;

/* declared by functions of L03_003AFC08.c, which this file was cut from */
void func_L03_003B0ED8(int, int);

/* localdecomp:start func_L03_003B0ED8 */
extern s32 D_L03_001DE858;

void func_L03_003B0ED8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_L03_001DE858 |= 1 << arg0;
        return;
    }
    D_L03_001DE858 &= ~(1 << arg0);
}
/* localdecomp:end func_L03_003B0ED8 */
