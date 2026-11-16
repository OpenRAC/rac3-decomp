#include "common.h"

/* localdecomp:start func_L24_0041CE48 */
typedef struct { s32 a,b; } E_0041CE48;
typedef struct { u8 pad[0x24DF0]; E_0041CE48 rows[4]; } P_0041CE48;
extern P_0041CE48 *D_L24_001D67C8;
__asm__(".extern D_L24_001D67C8, 16");
s32 func_L24_0041CE48(s32 a,s32 b,u32 n) {
    P_0041CE48 *p=D_L24_001D67C8;
    if(p && n<4) {p->rows[n].a=a;p->rows[n].b=b;return 1;}
    return 0;
}
/* localdecomp:end func_L24_0041CE48 */
