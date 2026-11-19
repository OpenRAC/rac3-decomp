#include "common.h"

/* declared by functions of L39_0050F5B8.c, which this file was cut from */
typedef struct {
    u8 *a;
    u32 b;
} P_0050F5B8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    P_0050F5B8 pr;
    s32 f14;
    s32 f18;
    s32 f1C;
} A_0050F5B8;
typedef struct {
    s32 flags;
    s32 (*handler)(A_0050F5B8 *, void *);
    s32 f8;
    s32 tag;
    char *name;
} I_0050F5B8;
extern s32 func_L39_00510220(I_0050F5B8 *);

/* localdecomp:start func_L39_00510220 */
s32 func_L39_00510220(I_0050F5B8 *p)
{
    s32 n = 0;
    s32 v;
    s32 t;

    for (;;) {
        v = p->flags;
        p++;
        t = v & ~0x200;
        if (v & 0x8800) {
            return 1;
        }
        if (v & 0x20) {
            if ((u32)(t - 0x30) < 2 || (v & 0x1400) == 0x1000) {
                n++;
            } else {
                continue;
            }
        } else if (t == 0x103) {
            n--;
        }
        if (n <= 0) {
            return 0;
        }
    }
}
/* localdecomp:end func_L39_00510220 */

/* localdecomp:start func_L39_00510298 */
extern void func_L39_004F74E8(void *, int, int);
extern int func_L39_00515BD8(void *);

void func_L39_00510298(char *a, int b)
{
    func_L39_004F74E8(a + 4, 0, 0x18);
    if (func_L39_00515BD8(a) == 0)
        *(int *)(a + 0x1C) = b;
}
/* localdecomp:end func_L39_00510298 */

/* localdecomp:start func_L39_005102E8 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 count;
    void **items;
    s32 size;
    void *buf;
} S_005102E8;

extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
extern void func_L39_00515C28(void *);

void func_L39_005102E8(S_005102E8 *a0) {
    u32 i;

    if (a0->buf != 0) {
        func_L39_004F74E8(a0->buf, 0, a0->size);
        func_L39_004F7620(a0->buf);
    }
    for (i = 0; i < a0->count; i++) {
        func_L39_004F7620(a0->items[i]);
    }
    func_L39_004F7620(a0->items);
    if (a0->f0 != 0) {
        func_L39_00515C28(a0);
    }
}
/* localdecomp:end func_L39_005102E8 */
