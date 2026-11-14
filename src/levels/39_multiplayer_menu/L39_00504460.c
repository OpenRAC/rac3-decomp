#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

/* declared by functions of L39_00504410.c, which this file was cut from */
extern S_00504410 *func_L39_004DBA08(void);

/* localdecomp:start func_L39_00504460 */
void func_L39_00504460(s32 arg0) {
    S_00504410 *p = func_L39_004DBA08();
    p->f28 = arg0;
}
/* localdecomp:end func_L39_00504460 */
