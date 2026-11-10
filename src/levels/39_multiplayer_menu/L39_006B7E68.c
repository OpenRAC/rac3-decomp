#include "common.h"

/* localdecomp:start func_L39_006B7E68 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_006B7E68;

extern Vec4_006B7E68 D_001DDBC0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DDBC0_sda, 8");

void func_L39_006B7E68(Vec4_006B7E68 *p) {
    Vec4_006B7E68 v;
    v = *p;
    D_001DDBC0_sda = v;
}
/* localdecomp:end func_L39_006B7E68 */
