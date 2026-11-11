#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *f1C;
    u8 pad20[0x38];
    s32 f58;
    u8 pad5C[0x24];
} E_005F2FF8;

/* localdecomp:start func_L39_005F35D8 */
extern int D_L39_0024BB68;
__asm__(".extern D_L39_0024BB68, 16");
__asm__(".extern D_L39_0024BB6C, 4");
extern int D_L39_0024BB6C;
extern char D_001FE020[];

int func_L39_005F35D8(int index, int a1, int a2, int a3)
{
    int r;
    char *p;
    if (index >= D_L39_0024BB68)
        return -1;
    if (index == 0xFFFFFFFFU) {
        return -1;
    } else {
        r = func_L39_005F3138((char *)(D_L39_0024BB6C + index * 32), a1, 0, a2 + 0x40, a3);
        if (r >= 0) {
            p = D_001FE020 + r * 128;
            *(int *)(p + 256) = a2;
            *(short *)(p + 202) = index;
        }
        return r;
    }
}
/* localdecomp:end func_L39_005F35D8 */
