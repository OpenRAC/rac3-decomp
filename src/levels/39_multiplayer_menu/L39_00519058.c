#include "common.h"

/* localdecomp:start func_L39_00519058 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 pC[2];
    void *w14;
    s32 w18;
    s32 w1C;
} S_00519058;

extern s32 D_L39_0046F540[];
extern u8 D_L39_00479AC8[];
extern s32 func_00126260(void *);
extern s32 func_001262A0(s32);

s32 func_L39_00519058(void) {
    S_00519058 st;
    if (D_L39_0046F540[0] < 0) {
        st.w8 = 1;
        st.w14 = D_L39_00479AC8;
        st.w4 = 1;
        D_L39_0046F540[0] = func_00126260(&st);
        if (D_L39_0046F540[0] < 0) {
            return -1;
        }
    }
    return func_001262A0(D_L39_0046F540[0]) >= 0 ? 0 : -1;
}
/* localdecomp:end func_L39_00519058 */

INCLUDE_ASM("asm/levels", func_L39_005190C8);

/* localdecomp:start func_L39_005190E8 */
typedef struct S_005190E8 S_005190E8;
struct S_005190E8 {
    S_005190E8 *next;
    S_005190E8 *prev;
    s32 key;
    s32 flag;
    s32 _p10;
    u8 sub[0x3C];
    void *buf;
    s32 aligned;
    s32 size;
    s32 a5C;
    s32 a60;
};

extern S_005190E8 *D_L39_0046F548 __attribute__((section(".data")));
extern S_005190E8 *D_L39_0046F54C __attribute__((section(".data")));
extern s32 D_L39_0046F544 __attribute__((section(".data")));
extern void func_L39_00518FE0(void);
extern s32 func_00126150(void);
extern s32 func_L39_00519058(void);
extern void func_L39_00519018(void *);
extern void func_L39_005190C8(void);
extern void func_00148CF0(void *);
extern s32 func_00148C20(void *, s32, s32, s32);

S_005190E8 *func_L39_005190E8(s32 arg0) {
    S_005190E8 *p;
    S_005190E8 *q;
    S_005190E8 *n;
    S_005190E8 *pv;
    u32 mask;
    s32 key = func_00126150();

    if (func_L39_00519058() < 0) {
        return 0;
    }
    for (p = D_L39_0046F548; p != 0; p = p->next) {
        if (key == p->key) {
            goto found;
        }
    }
    if (++D_L39_0046F544 >= 0x100) {
        p = D_L39_0046F54C;
        n = p->next;
        pv = p->prev;
        if (pv != 0) {
            pv->next = p->next;
            n = p->next;
            pv = p->prev;
        } else {
            D_L39_0046F548 = n;
        }
        if (n != 0) {
            n->prev = pv;
        } else {
            D_L39_0046F54C = pv;
        }
        func_00148CF0(p->sub);
        func_L39_00519018(p->buf);
        func_L39_00519018(p);
        D_L39_0046F544--;
    }
    p = ((S_005190E8 *(*)(s32))func_L39_00518FE0)(100);
    if (p == 0) {
        goto found;
    }
    mask = 0xFFFFFFC0;
    p->key = key;
    p->size = 0x800;
    p->a5C = 0x2000;
    p->a60 = 0x20;
    p->buf = ((void *(*)(s32))func_L39_00518FE0)(0x87F);
    if (p->buf != 0) {
        p->aligned = ((s32)p->buf + 0x3F) & ~0x3F;
        if (func_00148C20(p->sub, (p->size + 0x63) & mask, p->a5C, p->a60) >= 0) {
            goto link;
        }
        func_L39_00519018(p->buf);
    }
    func_L39_00519018(p);
    D_L39_0046F544--;
    func_L39_005190C8();
    return 0;
link:
    q = D_L39_0046F548;
    p->next = q;
    if (q != 0) {
        q->prev = p;
    } else {
        D_L39_0046F54C = p;
    }
    D_L39_0046F548 = p;
    p->prev = 0;
found:
    if (arg0 == 0) {
        p->flag = 0;
    }
    return p;
}
/* localdecomp:end func_L39_005190E8 */

INCLUDE_ASM("asm/levels", func_L39_005192A8);
