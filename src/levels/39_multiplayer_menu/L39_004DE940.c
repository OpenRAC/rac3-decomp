#include "common.h"

/* localdecomp:start func_L39_004DE940 */
typedef struct S_004DE940 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004DE940;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_00505068(void *);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004DE940(void) {
    void *mem;
    S_004DE940 *p;

    mem = func_L39_004BEED8(0x10);
    p = mem;
    if (p != 0) {
        p->f0 = 0;
        p->fC = 0;
        p->f8 = 0;
        if (func_L39_00505068(p) != 0) {
            return (s32)p;
        }
    }
    if (mem != 0) {
        func_L39_004BEF28(mem);
    }
    func_L39_004BC6C8(6, 0x75, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DE940 */

/* localdecomp:start func_L39_004DE9B8 */
extern void func_11D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);

typedef struct S_004DE9B8 {
    s32 f0;
    s32 f4;
    s32 len;
    void *buf;
} S_004DE9B8;

void func_L39_004DE9B8(S_004DE9B8 *p) {
    if (p->buf != 0) {
        func_11D534(p->buf, 0, p->len);
        func_L39_004BEF28(p->buf);
    }
    func_L39_004BEF28(p);
}
/* localdecomp:end func_L39_004DE9B8 */
