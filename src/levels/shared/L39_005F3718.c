#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *f1C;
    u8 pad20[0x38];
    s32 f58;
    u8 pad5C[0x24];
} E_005F2FF8;


/* localdecomp:start func_L39_005F3718 */
extern u8 D_001FE020[];
typedef int Q_005F3718 __attribute__((mode(TI)));

s32 func_L39_005F3718(s32 h, void *v) {
    u8 *p;

    if ((u32)h < 0x34) {
        p = D_001FE020 + (h << 7);
        *(u32 *)(p + 0x118) |= 0x40;
        *(Q_005F3718 *)(D_001FE020 + (h << 7) + 0xF0) = *(Q_005F3718 *)v;
    }
    return 1;
}
/* localdecomp:end func_L39_005F3718 */
