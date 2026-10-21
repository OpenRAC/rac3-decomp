#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int q128 __attribute__((mode(TI)));
typedef struct Moby {
    char pad0[0x10];
    q128 pos;
    unsigned char state;
    char pad21[0x30 - 0x21];
    unsigned char b48;
    unsigned char b49;
    unsigned short h50;
    char pad34[0x38 - 0x34];
    unsigned long d56;
    char pad40[0xB8 - 0x40];
    struct Moby *parent;
} Moby;

INCLUDE_ASM("asm/levels", func_L04_003BB208);

/* localdecomp:start func_L04_003BB2E0 */

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00366E48(u8 *, u8 *, void *, void *, s32);
extern void func_003C7C38(u8 *);

u8 *func_L04_003BB2E0(u8 *parent)
{
    u8 *obj = func_003C24B0(6449, 128);

    if (obj != 0) {
        u8 *vars = *(u8 **)(obj + 104);

        *(s32 *)(vars + 8) = 0;
        *(u8 **)(obj + 184) = parent;
        obj[48] = parent[48];
        *(u16 *)(obj + 50) = *(u16 *)(parent + 50);
        obj[49] = parent[49];
        obj[32] = 1;
        *(long *)(obj + 56) = *(long *)(parent + 56);
        *(u128_t *)(obj + 16) = *(u128_t *)(parent + 16);
        func_L01_00366E48(obj, vars, vars + 4, vars + 16, 0);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L04_003BB2E0 */

INCLUDE_ASM("asm/levels", func_L04_003BB378);

/* localdecomp:start func_L04_003BB468 */
extern void func_003C7C38(u8 *);
extern u8 *func_003C24B0(s32, s32);


extern void func_003C3A10(Moby *, int, int, int);

Moby *func_L04_003BB468(Moby *src) {
    Moby *m = ((Moby * (*)(int, int))func_003C24B0)(6450, 128);

    if (m != 0) {
        m->parent = src;
        m->b48 = src->b48;
        m->h50 = src->h50;
        m->b49 = src->b49;
        m->state = 1;
        m->d56 = src->d56;
        m->pos = src->pos;
        func_003C3A10(m, 0, 0, 0);
        ((void (*)(Moby *))func_003C7C38)(m);
    }
    return m;
}
/* localdecomp:end func_L04_003BB468 */

INCLUDE_ASM("asm/levels", func_L04_003BB4F8);

/* localdecomp:start func_L04_003BB5A0 */
extern void func_003C7C38(u8 *);
extern u8 *func_003C24B0(s32, s32);


extern void func_003C3A10(Moby *, int, int, int);

Moby *func_L04_003BB5A0(Moby *src) {
    Moby *m = ((Moby * (*)(int, int))func_003C24B0)(6455, 128);

    if (m != 0) {
        m->parent = src;
        m->b48 = src->b48;
        m->h50 = src->h50;
        m->b49 = src->b49;
        m->state = 1;
        m->d56 = src->d56;
        m->pos = src->pos;
        func_003C3A10(m, 0, 0, 0);
        ((void (*)(Moby *))func_003C7C38)(m);
    }
    return m;
}
/* localdecomp:end func_L04_003BB5A0 */
