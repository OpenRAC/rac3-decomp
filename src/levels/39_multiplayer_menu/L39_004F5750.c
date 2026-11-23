#include "common.h"

/* declared by functions of L39_004F4FD8.c, which this file was cut from */
extern void func_L39_004F63B8(void);
extern void func_L39_004F6420(void *schedule, void *key);

/* localdecomp:start func_L39_004F5750 */
extern void func_L39_004F63B8_004F5750(void *, void *);
extern void func_L39_004F6420(void *schedule, void *key);
s32 func_L39_004F5750(u8 *p, u8 *q) {
    func_L39_004F63B8_004F5750(p + 0x100, q);
    func_L39_004F6420(p + 0x80, q + 8);
    func_L39_004F63B8_004F5750(p, q + 0x10);
    return 0;
}
/* localdecomp:end func_L39_004F5750 */
