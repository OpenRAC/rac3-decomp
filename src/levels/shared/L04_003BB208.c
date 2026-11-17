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

/* localdecomp:start func_L04_003BB208 */
extern void func_0038CC88(void *, void *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00366EA8(u8 *, u8 *, u8 *, s32, s32);

void func_L04_003BB208(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *p;
    if ((*(u16 *)(a0 + 0x34) & 0x80) == 0) {
        if (a0[0x20] == 0) {
            *(s32 *)(pv + 8) = 0;
        }
        if (func_L01_00456250(*(u8 **)(a0 + 0xB8)) != 0) {
            if (*(s32 *)(pv + 8) == 0) {
                func_003A52A0(0, 0, a0);
                *(s32 *)(pv + 8) = 1;
            }
        } else {
            *(s32 *)(pv + 8) = 0;
        }
        p = *(u8 **)(a0 + 0xB8);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
        *(u128_t *)(a0 + 0xF0) = *(u128_t *)(p + 0xF0);
        func_0038CC88(a0 + 0xC0, p + 0xC0, 0x30);
        func_L01_00366EA8(pv, pv + 4, pv + 0x10, 0, func_L01_00456250(*(u8 **)(a0 + 0xB8)));
    }
}
/* localdecomp:end func_L04_003BB208 */

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

/* localdecomp:start func_L04_003BB378 */
extern void func_0038CC88(void *, void *, s32);
extern void func_003C3A10(Moby *, int, int, int);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern u8 D_L04_001E2840[];

void func_L04_003BB378(u8 *a0) {
    u8 *p;
    if ((*(u16 *)(a0 + 0x34) & 0x80) == 0) {
        p = *(u8 **)(a0 + 0xB8);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
        *(u128_t *)(a0 + 0xF0) = *(u128_t *)(p + 0xF0);
        func_0038CC88(a0 + 0xC0, p + 0xC0, 0x30);
        if (*(s32 *)(*(u8 **)(*(u8 **)(a0 + 0xB8) + 0x68) + 0x18) != 0) {
            if (a0[0x43] != 1) {
                func_003C3A10((Moby *)a0, 1, 0, 8);
            }
        } else {
            if (a0[0x43] != 0) {
                func_003C3A10((Moby *)a0, 0, 0, 8);
            }
        }
        if (a0[0x31] != 0) {
            if (func_L01_0040E548(D_L04_001E2840, a0 + 0x10) < 576.0f) {
                func_L01_004472C0(a0);
                a0[0x6F] = 0x16;
            }
        }
    }
}
/* localdecomp:end func_L04_003BB378 */

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

/* localdecomp:start func_L04_003BB4F8 */
extern void func_0038CC88(void *, void *, s32);

void func_L04_003BB4F8(u8 *a0) {
    u8 *p;
    if ((*(u16 *)(a0 + 0x34) & 0x80) == 0) {
        p = *(u8 **)(a0 + 0xB8);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x10);
        *(u128_t *)(a0 + 0xF0) = *(u128_t *)(p + 0xF0);
        func_0038CC88(a0 + 0xC0, p + 0xC0, 0x30);
        if (*(s32 *)(*(u8 **)(*(u8 **)(a0 + 0xB8) + 0x68) + 0x18) != 0) {
            if (a0[0x43] != 1) {
                func_003C3A10((Moby *)a0, 1, 0, 8);
            }
        } else {
            if (a0[0x43] != 0) {
                func_003C3A10((Moby *)a0, 0, 0, 8);
            }
        }
    }
}
/* localdecomp:end func_L04_003BB4F8 */

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
