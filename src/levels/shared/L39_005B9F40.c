#include "common.h"

/* localdecomp:start func_L39_005B9F40 */
extern u8 D_002413B0[] __attribute__((section(".sdata")));
extern int D_001A5000[];

void func_L39_005B9F40(int index)
{
    int i;
    int j;
    int sum;
    int count;
    if (D_002413B0[index] != 0)
        return;
    sum = 0;
    for (j = 0; j < 60; j++)
        if (D_002413B0[j] != 0)
            sum += j;
    D_002413B0[index] = 1;
    if (index >= 0x1e || index == 24)
        return;
    count = 0;
    for (i = 0; i < 60; i++)
        if (D_001A5000[i] != 0)
            count++;
    D_001A5000[count] = index;
}
/* localdecomp:end func_L39_005B9F40 */

/* localdecomp:start func_L39_005B9FD8 */
typedef struct Moby_005B9FD8 {
    u8 pad0[0xAA];
    s16 oClass;
    u8 padAC[0xB8 - 0xAC];
    struct Moby_005B9FD8 *fB8;
} Moby_005B9FD8;

typedef struct P_005B9FD8 {
    u8 pad0[0x450];
    Moby_005B9FD8 *f450;
    u8 pad454[0x478 - 0x454];
    s32 f478;
} P_005B9FD8;

typedef struct T_005B9FD8 {
    u8 pad0[4];
    s16 f4;
    u8 pad6[0x80 - 6];
} T_005B9FD8;

extern P_005B9FD8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern T_005B9FD8 D_L39_0049C890[];

s32 func_L39_005B9FD8(Moby_005B9FD8 *moby) {
    s32 i;
    s32 j;
    P_005B9FD8 *p;

    switch (moby->oClass) {
    case 0x1095: return 1;
    case 0x108E:
    case 0x108F:
    case 0x1090: return 5;
    case 0x1087: return 2;
    case 0x1097: return 3;
    case 0x108C: return 4;
    case 0x1099: return 6;
    case 0x10A4: return 7;
    }
    for (i = 0; i < 8; i++) {
        p = D_L39_0024CE20[i];
        if (p != 0) {
            if (moby == p->f450) return p->f478;
            if (moby->fB8 != 0 && moby->fB8 == p->f450) return p->f478;
        }
    }
    for (j = 0; j < 16; j++) {
        if (moby->oClass == D_L39_0049C890[j].f4) return j;
        if (moby->fB8 != 0 && moby->fB8->oClass == D_L39_0049C890[j].f4) return j;
    }
    return 0xFF;
}
/* localdecomp:end func_L39_005B9FD8 */
