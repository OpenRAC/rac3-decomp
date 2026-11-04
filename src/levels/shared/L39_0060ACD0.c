#include "common.h"

typedef struct {
    s32 f0;
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_0060ACD0;

/* localdecomp:start func_L39_0060ACD0 */
extern void func_12CD60(void *);
extern void func_12CDB0(void);


void func_L39_0060ACD0(S_0060ACD0 *p) {
    func_12CD60(p);
    *(s32 *)(p->f4 + p->f8 * 0x27E40) = 2;
    *(volatile s32 *)&p->fC += 1;
    *(volatile s32 *)&p->f8 = (*(volatile s32 *)&p->f8 + 1) % p->f10;
    func_12CDB0();
}
/* localdecomp:end func_L39_0060ACD0 */
