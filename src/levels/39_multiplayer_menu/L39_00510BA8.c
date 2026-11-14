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

INCLUDE_ASM("asm/levels", func_L39_00511848);

INCLUDE_ASM("asm/levels", func_L39_005119F0);

INCLUDE_ASM("asm/levels", func_L39_00511A50);

/* localdecomp:start func_L39_00511BA8 */
typedef struct { s32 cap; s32 n; long *d; } S_00511BA8;

extern void func_L39_005128F8(void *);
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7620(void *);
extern s32 func_L39_00512CB0(void *, void *, void *);
extern s32 func_L39_00512F78(void *, void *, void *, void *);
extern s32 func_L39_00515F90(void *);
extern s32 func_L39_00513178(void *, void *, void *, void *, void *);
extern s32 func_L39_00511DB0(void *, s32, s32 *, s32, void *, void *, void *, void *, void *);

s32 func_L39_00511BA8(void *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, void *arg7, void *arg8) {
    S_00511BA8 tmp;
    S_00511BA8 *buf;
    s32 count;
    s32 ret;
    s32 i;

    func_L39_005128E8((s32 *) &tmp);
    do {
        count = 1 << (arg3 - 1);
        buf = func_L39_004F7590(count * sizeof(S_00511BA8));
        if (buf == 0) {
            count = 0;
            ret = 0x100;
            break;
        }
        for (i = 0; i < count; i++) {
            func_L39_005128E8((s32 *) &buf[i]);
        }
        ret = func_L39_00512CB0(arg0, arg5, buf);
        if (ret != 0) break;
        if (arg4 != 1) {
            ret = func_L39_00512F78(buf, arg5, arg6, &tmp);
            if (ret != 0) break;
            ret = func_L39_00515F90(arg8);
            if (ret != 0) break;
            for (i = 1; i < count && 2 * i + 1 <= arg4; i++) {
                ret = func_L39_00513178(&buf[i - 1], &tmp, arg5, arg6, &buf[i]);
                if (ret != 0) break;
            }
            if (ret != 0) break;
        }
        ret = func_L39_00511DB0(buf, count, arg1, arg2, arg6, &tmp, arg5, arg7, arg8);
    } while (0);
    if (buf != 0) {
        for (i = 0; i < count; i++) {
            func_L39_005128F8(&buf[i]);
        }
        func_L39_004F7620(buf);
    }
    func_L39_005128F8(&tmp);
    return ret;
}
/* localdecomp:end func_L39_00511BA8 */

/* localdecomp:start func_L39_00511DB0 */
extern s32 func_L39_00515F90(void *);
extern s32 func_L39_00512F78(void *, void *, void *, void *);
extern s32 func_L39_00513178(void *, void *, void *, void *, void *);
extern s32 func_L39_00512E18(void *, void *, void *, void *);

typedef struct { s32 cap; s32 n; long *d; } S_00511DB0;

s32 func_L39_00511DB0(void *arg0, s32 count, s32 *tbl, s32 n, void *arg4, void *tmp, void *arg6, void *out, void *arg8) {
    S_00511DB0 *buf = arg0;
    s32 ret;
    s32 i;
    s32 a;
    s32 b;
    s32 flag;

    do {
        ret = func_L39_00515F90(arg8);
        if (ret != 0) break;
        ret = func_L39_00510EF0((S_00510EF0 *)buf, tmp);
        if (ret != 0) break;
        a = tbl[0];
        b = tbl[1];
        flag = 0;
        for (i = 2;;) {
            ret = func_L39_00515F90(arg8);
            if (ret != 0) goto out;
            if (flag == 1) {
                ret = func_L39_00512F78(out, arg6, arg4, tmp);
                if (ret != 0) goto out;
                a--;
                flag = 0;
            }
            while (a > 0) {
                ret = func_L39_00512F78(tmp, arg6, arg4, out);
                if (ret != 0) break;
                a--;
                flag = 1;
                if (a <= 0) break;
                ret = func_L39_00512F78(out, arg6, arg4, tmp);
                if (ret != 0) break;
                a--;
                flag = 0;
            }
            if (ret != 0) goto out;
            if (b != 0) {
                b = (b - 1) >> 1;
                if (flag == 0) {
                    ret = func_L39_00513178(&buf[b], tmp, arg6, arg4, out);
                    if (ret != 0) goto out;
                    flag = 1;
                } else {
                    ret = func_L39_00513178(&buf[b], out, arg6, arg4, tmp);
                    if (ret != 0) goto out;
                    flag = 0;
                }
            }
            if (i >= n) break;
            a = tbl[i];
            b = tbl[i + 1];
            i += 2;
            if (a == 0) break;
        }
        if (ret != 0) break;
        if (flag == 0) {
            ret = func_L39_00512E18(tmp, arg6, arg4, out);
        } else {
            ret = func_L39_00512E18(out, arg6, arg4, tmp);
            if (ret != 0) break;
            ret = func_L39_00510EF0(tmp, out);
        }
    } while (0);
out:
    return ret;
}
/* localdecomp:end func_L39_00511DB0 */

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

/* localdecomp:start func_L39_00512488 */
extern s32 func_L39_005119F0(s32, s32);
extern s32 func_L39_00512510(s32, s32, s32, s32);
extern s32 func_L39_00512B20(s32, s32, s32, s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s64 *unk8;
} S_00512488;

s32 func_L39_00512488(s32 arg0, S_00512488 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    if (arg4 < 2) {
        if (*arg1->unk8 == 0) {
            return func_L39_005119F0(1, arg3);
        }
        return func_L39_00510EF0((S_00510EF0 *)arg0, (S_00510EF0 *)arg3);
    }
    if (*arg1->unk8 == 3) {
        return func_L39_00512510(arg0, arg2, arg3, arg5);
    }
    return func_L39_00512B20(arg0, arg0, arg2, arg3);
}
/* localdecomp:end func_L39_00512488 */

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
