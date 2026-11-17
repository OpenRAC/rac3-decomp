#include "common.h"

/* localdecomp:start func_L08_003BAB88 */
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
extern s32 D_00142C34[];
extern void func_003C2880(void *);

void func_L08_003BAB88(void *obj) {
    if (D_001D545C == 8 && (D_00142C34[0] & 0x200000) != 0) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L08_003BAB88 */
