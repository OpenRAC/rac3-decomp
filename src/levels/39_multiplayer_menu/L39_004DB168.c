#include "common.h"

/* localdecomp:start func_L39_004DB168 */
typedef struct {
    s32 f0;
    void *data;
    s32 size;
} S_004DB168;

extern void func_0011D534(void *, s32, s32);
extern void func_L39_004BEF28(void *);

/* clear and free a buffer holder (memset then Free) */
void func_L39_004DB168(S_004DB168 *p) {
    if (p != 0) {
        if (p->data != 0) {
            func_0011D534(p->data, 0, p->size);
            func_L39_004BEF28(p->data);
        }
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_004DB168 */

INCLUDE_ASM("asm/levels", func_L39_004DB1C0);

LINKER_REMNANT("asm/levels", func_L39_004DB288);

/* localdecomp:start func_L39_004DB298 */
typedef struct {
    u32 f0;
    s32 f4;
    s32 f8;
} S_004DB298_src;

typedef struct {
    s32 f0;
    s32 f4;
    u64 f8;
    s32 f10;
} S_004DB298_out;

extern S_004DB298_src *func_L39_004F16B0(void *);

s32 func_L39_004DB298(void *a, S_004DB298_out *out) {
    S_004DB298_src *p;
    s32 r = 0;

    p = func_L39_004F16B0(a);
    if (p != 0 && out != 0) {
        out->f8 = p->f0;
        out->f10 = p->f8;
        out->f0 = p->f4;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_004DB298 */

/* localdecomp:start func_L39_004DB300 */
typedef s32 (*F_004DB300)(void *, s32, s32);

s32 func_L39_004DB300(void *a, s32 *args, F_004DB300 fn) {
    s32 r = 0;
    if (fn != 0) {
        r = fn(a, args[1], args[0]);
    }
    return r;
}
/* localdecomp:end func_L39_004DB300 */

INCLUDE_ASM("asm/levels", func_L39_004DB330);

INCLUDE_ASM("asm/levels", func_L39_004DB408);

INCLUDE_ASM("asm/levels", func_L39_004DB470);

INCLUDE_ASM("asm/levels", func_L39_004DB4D8);

/* localdecomp:start func_L39_004DB558 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004DB558_a;

typedef struct {
    u32 f0;
    s32 f4;
    s32 f8;
} S_004DB558_b;

typedef struct {
    s32 f0;
    S_004DB558_a *f4;
    S_004DB558_b *f8;
} S_004DB558;

typedef struct {
    s32 f0;
    s32 f4;
    s64 f8;
    s32 f10;
} S_004DB558_out;

s32 func_L39_004DB558(S_004DB558 *p, S_004DB558_out *a, S_004DB558_out *b) {
    s32 r = 0;
    if (a != 0) {
        a->f0 = 6;
        r = 1;
        a->f10 = p->f4->f10;
        a->f8 = p->f4->fC;
    }
    if (b != 0) {
        r = 1;
        b->f0 = p->f8->f4;
        b->f10 = p->f8->f8;
        b->f8 = p->f8->f0;
    }
    return r;
}
/* localdecomp:end func_L39_004DB558 */

/* localdecomp:start func_L39_004DB5C0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_004DB5C0;

s32 func_L39_004DB5C0(S_004DB5C0 *p, s32 v) {
    p->f10 = v;
    return 1;
}
/* localdecomp:end func_L39_004DB5C0 */

INCLUDE_ASM("asm/levels", func_L39_004DB5D0);
