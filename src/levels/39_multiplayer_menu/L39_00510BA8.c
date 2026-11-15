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

LINKER_REMNANT("asm/levels", func_L39_00510C88);

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

/* localdecomp:start func_L39_00510F60 */
typedef struct {
    s32 f0;
    s32 top;
    u64 *d;
} BN_00510F60;

s32 func_L39_00510F60(void *va, void *vb) {
    BN_00510F60 *a = va;
    BN_00510F60 *b = vb;
    s32 na = a->top;
    s32 nb = b->top;
    u64 *ad = a->d;
    u64 *bd = b->d;
    s32 i;
    s32 ret;

    ret = (nb < na) ? 1 : -1;
    if (na == nb) {
        for (i = na - 1; i >= 0; i--) {
            if (ad[i] != bd[i]) {
                break;
            }
        }
        if (i < 0) {
            return 0;
        }
        return (ad[i] > bd[i]) ? 1 : -1;
    }
    return ret;
}
/* localdecomp:end func_L39_00510F60 */

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

/* localdecomp:start func_L39_00511750 */
extern s32 func_L39_00511848(void *, u32, u32 *, u8 *);

s32 func_L39_00511750(void *arg0, u32 len, u32 size, u32 *outLen, u8 *buf) {
    u32 k;
    s32 i;

    if (len > size) {
        return 0x10C;
    }
    k = (func_L39_00511540(arg0) + 7) / 8;
    if (len < k) {
        return 0x10C;
    }
    if (k < len) {
        for (i = 0; i < (s32)(len - k); i++) {
            buf[i] = 0;
        }
        *outLen = len;
        return func_L39_00511848(arg0, size, &k, buf + i);
    }
    return func_L39_00511848(arg0, size, outLen, buf);
}
/* localdecomp:end func_L39_00511750 */
