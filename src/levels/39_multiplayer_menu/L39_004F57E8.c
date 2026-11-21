#include "common.h"

/* declared by functions of L39_004F4FD8.c, which this file was cut from */
extern void func_L39_004F63B8(void);
extern void func_L39_004F6420(void *schedule, void *key);

/* localdecomp:start func_L39_004F57E8 */
s32 func_L39_004F57E8(u8 *s, u8 *key) {
    func_L39_004F6420(s, key);
    ((void (*)(void *, void *))func_L39_004F63B8)(s + 0x80, key + 8);
    func_L39_004F6420(s + 0x100, key + 0x10);
    return 0;
}
/* localdecomp:end func_L39_004F57E8 */
