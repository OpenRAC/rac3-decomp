#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FC370 */
/* OpenSSL BN_init: clears the 0x14-byte BIGNUM */
typedef struct BN_004FC370 {
    void *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BN_004FC370;
extern void func_0011D534(void *, s32, s32);

void func_L39_004FC370(BN_004FC370 *a) {
    func_0011D534(a, 0, sizeof(BN_004FC370));
}
/* localdecomp:end func_L39_004FC370 */
