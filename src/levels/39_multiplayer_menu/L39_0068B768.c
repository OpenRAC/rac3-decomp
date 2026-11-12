#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

INCLUDE_ASM("asm/levels", func_L39_0068B768);

INCLUDE_ASM("asm/levels", func_L39_0068B828);

/* localdecomp:start func_L39_0068B8A0 */
extern s32 D_001DC3F4_sda;

void func_L39_0068B8A0(void) {
    D_001DC3F4_sda = 3;
}
/* localdecomp:end func_L39_0068B8A0 */
