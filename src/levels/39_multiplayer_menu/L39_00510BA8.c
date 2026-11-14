#include "common.h"

/* localdecomp:start func_L39_00510BA8 */
typedef struct S_00510BA8_Obj S_00510BA8_Obj;
typedef struct {
    s32 (*fn0)(S_00510BA8_Obj *, void *, u32);
} S_00510BA8_Vt;
struct S_00510BA8_Obj {
    S_00510BA8_Vt *vt;
    s32 unk4;
    s32 pad8;
    s32 unkC;
    u32 unk10;
    void *unk14;
    s32 pad18;
    S_00510BA8_Obj *unk1C;
};

extern s32 func_L39_0050CEE0(u32 *, s32 *, s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void *func_L39_004F75B0(void *, u32);
extern void func_L39_0050D0C0(void *, u32 *, u32, s32 *, s32, s32);
extern void func_L39_00515C70(s32, s32);

s32 func_L39_00510BA8(S_00510BA8_Obj *arg0) {
    u32 size;
    s32 info;
    s32 ret;
    void *p;

    if (arg0->unk4 == 0) {
        return 0;
    }
    ret = func_L39_0050CEE0(&size, &info, arg0->unkC);
    if (ret != 0) {
        return ret;
    }
    if (arg0->unk10 < size) {
        if (arg0->unk14 != 0) {
            func_L39_004F74E8(arg0->unk14, 0, arg0->unk10);
        }
        p = func_L39_004F75B0(arg0->unk14, size);
        arg0->unk14 = p;
        if (p == 0) {
            return 0x803;
        }
        arg0->unk10 = size;
    }
    func_L39_0050D0C0(arg0->unk14, &size, size, &info, arg0->unkC, arg0->unk4 - 1);
    func_L39_00515C70(*(s32 *)arg0, 1);
    arg0->unk4 = 0;
    return arg0->unk1C->vt->fn0(arg0->unk1C, arg0->unk14, size);
}
/* localdecomp:end func_L39_00510BA8 */

INCLUDE_ASM("asm/levels", func_L39_00510C84);

INCLUDE_ASM("asm/levels", func_L39_00510CA0);

INCLUDE_ASM("asm/levels", func_L39_00510DB8);

INCLUDE_ASM("asm/levels", func_L39_00510EB0);

/* localdecomp:start func_L39_00510EF0 */
typedef struct { s32 cap; s32 n; long *d; } S_00510EF0;
extern s32 func_L39_00512A40(s32, S_00510EF0 *);
extern void func_L39_004F7510(void *, void *, s32);
s32 func_L39_00510EF0(S_00510EF0 *a, S_00510EF0 *b) {
    s32 n = a->n;
    s32 r;
    if (b->cap < n) {
        r = func_L39_00512A40(n, b);
        if (r != 0) return r;
    }
    func_L39_004F7510(b->d, a->d, n * 8);
    b->n = n;
    return 0;
}
/* localdecomp:end func_L39_00510EF0 */

INCLUDE_ASM("asm/levels", func_L39_00510F60);

INCLUDE_ASM("asm/levels", func_L39_00510FF0);

INCLUDE_ASM("asm/levels", func_L39_00511188);

INCLUDE_ASM("asm/levels", func_L39_00511268);

INCLUDE_ASM("asm/levels", func_L39_00511480);

/* localdecomp:start func_L39_00511540 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00511540;
s32 func_L39_00511540(S_00511540 *s) {
    unsigned long *d = s->d;
    if (d != 0) {
        s32 i = s->n - 1;
        s32 c = 1;
        unsigned long v = d[i] >> 1;
        while (v != 0) { v >>= 1; c++; }
        return i * 64 + c;
    }
    return 0;
}
/* localdecomp:end func_L39_00511540 */

LINKER_REMNANT("asm/levels", func_L39_005115A0);

INCLUDE_ASM("asm/levels", func_L39_005115B8);

INCLUDE_ASM("asm/levels", func_L39_00511750);

INCLUDE_ASM("asm/levels", func_L39_00511848);

INCLUDE_ASM("asm/levels", func_L39_005119F0);

INCLUDE_ASM("asm/levels", func_L39_00511A50);

INCLUDE_ASM("asm/levels", func_L39_00511BA8);

INCLUDE_ASM("asm/levels", func_L39_00511DB0);

/* localdecomp:start func_L39_00512018 */
typedef struct { s32 a, b, c; } S_00512018;
typedef struct { S_00512018 p, q; } P_00512018;
extern void func_L39_005120B0(s32, s32, P_00512018 *, P_00512018 *, s32, s32, s32);
void func_L39_00512018(s32 a0, S_00512018 *p, S_00512018 *q, S_00512018 *r, S_00512018 *s, s32 x, s32 y, s32 z) {
    P_00512018 u;
    P_00512018 v;
    u.p = *p;
    u.q = *q;
    v.p = *r;
    v.q = *s;
    func_L39_005120B0(a0, 2, &u, &v, x, y, z);
}
/* localdecomp:end func_L39_00512018 */

INCLUDE_ASM("asm/levels", func_L39_005120B0);

INCLUDE_ASM("asm/levels", func_L39_00512488);

INCLUDE_ASM("asm/levels", func_L39_00512510);

INCLUDE_ASM("asm/levels", func_L39_00512620);

/* localdecomp:start func_L39_00512778 */
s32 func_L39_00512778(s32 arg0)
{
    if (arg0 >= 0x3FC) {
        return 6;
    }
    if (arg0 >= 0x17E) {
        return 5;
    }
    if (arg0 >= 0x50) {
        return 4;
    }
    if (arg0 >= 0x13) {
        return 3;
    }
    return 2;
}
/* localdecomp:end func_L39_00512778 */

INCLUDE_ASM("asm/levels", func_L39_005127B8);
