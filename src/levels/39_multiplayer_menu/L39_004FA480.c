#include "common.h"

/* localdecomp:start func_L39_004FA480 */
typedef struct Node_004FA480 { s32 f0; s32 f4; s32 f8; s32 padC; s64 f10; } Node_004FA480;
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
Node_004FA480 *func_L39_004FA480(s32 type) {
    Node_004FA480 *p = func_L39_004BEED8(0x18);
    if (p == 0) {
        func_L39_004BC6C8(0xD, 0x74, 0x21, 0, 0);
        return 0;
    }
    p->f4 = type;
    p->f0 = 0;
    p->f8 = 0;
    *(long *)&p->f10 = 0;
    return p;
}
/* localdecomp:end func_L39_004FA480 */
