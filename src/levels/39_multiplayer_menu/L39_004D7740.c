#include "common.h"

/* localdecomp:start func_L39_004D7740 */
u32 func_L39_004B5910(u32);

typedef struct S_004D7740 { char pad[0x24]; u32 val; } S_004D7740;

void func_L39_004D7740(S_004D7740 *arg0, u32 arg1) {
    arg0->val = func_L39_004B5910(arg1);
}
/* localdecomp:end func_L39_004D7740 */

/* localdecomp:start func_L39_004D7770 */
typedef struct S_004D7770 {
    /* 0x00000 */ u8 pad0[0x1069C];
    /* 0x1069C */ s32 f1069C;
    /* 0x106A0 */ s32 f106A0;
    /* 0x106A4 */ s32 f106A4;
    /* 0x106A8 */ s32 f106A8;
} S_004D7770;

extern S_004D7770 D_L39_00453FB0;
extern s32 func_L39_004D7508(s32, s32, s32);
extern s32 func_L39_004D7568(s32);
extern s32 func_L39_004D7658(s32);
extern s32 func_L39_004D76B0(s32, s32);
extern s32 func_L39_004D7700(s32, s32);
extern s32 func_L39_004D7720(s32, s32);
extern s32 func_L39_004D6E78(s32, s32, s32);
extern s32 func_L39_004D0C78(void);

static __inline__ void wipe_004D7770(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D7770(s32 op, s32 arg1, s32 arg2) {
    s32 a;
    s32 ret;
    s32 c;
    s32 d;
    s32 result;
    S_004D7770 *p;

    ret = 0;
    d = D_L39_00453FB0.f106A4;
    c = 0;
    a = func_L39_004D7508(op, arg2, d);
    d += a;
    c += a;
    switch (op) {
    case 0:
        ret = func_L39_004D7568(d);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 1:
        ret = func_L39_004D7658(d);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 3:
        ret = func_L39_004D76B0(d, arg1);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 8:
        ret = func_L39_004D7700(d, arg1);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    case 2:
        ret = func_L39_004D7720(d, arg1);
        if (ret < 0) {
            result = ret;
            goto wipe;
        }
        d += ret;
        c += ret;
        break;
    default:
        result = -0x6B;
        goto wipe;
    }
    p = &D_L39_00453FB0;
    d = p->f106A4;
    func_L39_004D7740((S_004D7740 *)d, ret);
    p->f106A8 = a + ret;
    ret = func_L39_004D6E78(op, c, p->f1069C);
    if (ret < 0) {
        result = ret;
        goto wipe;
    }
    p->f106A0 = ret;
    result = ret + c;
wipe:
    wipe_004D7770(&a, sizeof(a));
    wipe_004D7770(&ret, sizeof(ret));
    wipe_004D7770(&c, sizeof(c));
    wipe_004D7770(&d, sizeof(d));
    return result;
}
/* localdecomp:end func_L39_004D7770 */

/* localdecomp:start func_L39_004D7B38 */
typedef struct S_004D7B38 {
    u8 pad0[0x1069C];
    u8 *src;       /* 1069C */
    s32 len1;      /* 106A0 */
    u8 *buf2;      /* 106A4 */
    s32 len2;      /* 106A8 */
    u8 *dst;       /* 106AC */
    s32 off;       /* 106B0 */
    u8 pad1[0x106D0 - 0x106B4];
    s32 sema;      /* 106D0 */
    u8 pad2[0x1070C - 0x106D4];
    s32 arg;       /* 1070C */
    u8 pad3[4];
    s32 (*fn1)(void);   /* 10714 */
    s32 (*fn2)(u8 *, s32, s32);   /* 10718 */
    u8 pad4[4];
    s32 (*fn3)(void);   /* 10720 */
} S_004D7B38;

extern S_004D7B38 D_L39_00453FB0_004D7B38;
s32 func_L39_004D7770(s32 op, s32 arg1, s32 arg2);
extern s32 func_L39_004D5B40(void);
extern s32 func_L39_004D0C78(void);
extern void func_00126280(s32);
extern s32 func_001262B0(s32);

s32 func_L39_004D7B38(s32 op, s32 arg1, s32 arg2) {
    s32 ret;
    s32 k;
    u8 *s;
    u8 *d;
    u8 *s2;
    u8 *d2;

    ret = func_L39_004D7770(op, arg1, arg2);
    if (ret < 0) {
        return ret;
    }
    if (func_L39_004D5B40() > 0) {
        return -0x259;
    }
    func_00126280(D_L39_00453FB0_004D7B38.sema);
    ret = D_L39_00453FB0_004D7B38.fn1();
    func_001262B0(D_L39_00453FB0_004D7B38.sema);
    if (ret >= 0) {
        d = D_L39_00453FB0_004D7B38.dst;
        s = D_L39_00453FB0_004D7B38.src;
        for (k = 0; k < D_L39_00453FB0_004D7B38.len1; k++) {
            d[k] = s[k];
        }
        D_L39_00453FB0_004D7B38.off = D_L39_00453FB0_004D7B38.len1;
        d2 = D_L39_00453FB0_004D7B38.dst + D_L39_00453FB0_004D7B38.off;
        s2 = D_L39_00453FB0_004D7B38.buf2;
        for (k = 0; k < D_L39_00453FB0_004D7B38.len2; k++) {
            d2[k] = s2[k];
        }
        D_L39_00453FB0_004D7B38.off = D_L39_00453FB0_004D7B38.off + D_L39_00453FB0_004D7B38.len2;
        {
            u8 *q = D_L39_00453FB0_004D7B38.src;
            s32 n;
            for (n = 0; n < 0x400; n++) {
                q[n] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
            }
        }
        {
            u8 *q = D_L39_00453FB0_004D7B38.buf2;
            u32 n;
            for (n = 0; n < 0x8033; n++) {
                q[n] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
            }
        }
        func_00126280(D_L39_00453FB0_004D7B38.sema);
        ret = D_L39_00453FB0_004D7B38.fn2(D_L39_00453FB0_004D7B38.dst, D_L39_00453FB0_004D7B38.off, D_L39_00453FB0_004D7B38.arg);
        func_001262B0(D_L39_00453FB0_004D7B38.sema);
        if (ret >= 0) {
            if (ret != D_L39_00453FB0_004D7B38.off) {
                ret = -0x6B;
            } else {
                {
                    u8 *q = D_L39_00453FB0_004D7B38.dst;
                    u32 n;
                    for (n = 0; n < 0x8433; n++) {
                        q[n] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
                    }
                }
                return ret;
            }
        }
    }
    {
        u8 *q = D_L39_00453FB0_004D7B38.src;
        s32 n;
        for (n = 0; n < 0x400; n++) {
            q[n] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = D_L39_00453FB0_004D7B38.buf2;
        u32 n;
        for (n = 0; n < 0x8033; n++) {
            q[n] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    {
        u8 *q = D_L39_00453FB0_004D7B38.dst;
        u32 n;
        for (n = 0; n < 0x8433; n++) {
            q[n] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
        }
    }
    func_00126280(D_L39_00453FB0_004D7B38.sema);
    D_L39_00453FB0_004D7B38.fn3();
    func_001262B0(D_L39_00453FB0_004D7B38.sema);
    return ret;
}
/* localdecomp:end func_L39_004D7B38 */

/* localdecomp:start func_L39_004D8110 */
s32 func_L39_004D8110(u8 *arg0, u8 *arg1, u32 arg2) {
    u32 i;

    for (i = 0; i < arg2; i++) {
        if (arg0[i] < arg1[i]) {
            return -1;
        }
        if (arg1[i] < arg0[i]) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004D8110 */

/* localdecomp:start func_L39_004D8168 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);
extern void func_00126280(s32);
extern s32 func_001262B0(s32);

typedef struct S_004D8168 {
    /* 0x00000 */ u8 pad0[0x106D0];
    /* 0x106D0 */ s32 sema;
    /* 0x106D4 */ u8 pad1[0x1071C - 0x106D4];
    /* 0x1071C */ s32 (*recv)(char *, s32);
} S_004D8168;

extern S_004D8168 D_L39_00453FB0_004D8168;

/* overwrites a local with random bytes before returning (as wipe_004D7770 does) */
static __inline__ void wipe_004D8168(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D8168(u8 *buf, char *str, s32 arg2, s32 *count) {
    s32 ret = 0;
    char *p;
    s32 n;
    s32 len;

    DNAS_BEGIN(func_L39_004D8168, 0, func_L39_004BD350);
    p = (char *)buf;
    len = 1;
    if (arg2) {
        if (*p != *str) {
            ret = p - (char *)buf;
            goto out;
        }
        str += len;
        p += len;
    }
    do {
        if (*count + 1 > 0x400) {
            ret = -0x6A;
            goto out;
        }
        func_00126280(D_L39_00453FB0_004D8168.sema);
        n = D_L39_00453FB0_004D8168.recv(p, len);
        func_001262B0(D_L39_00453FB0_004D8168.sema);
        ret = n;
        if (n < 0) goto out;
        if (n != len) {
            ret = -0x6B;
            goto out;
        }
        *count += n;
        if (*p != *str) {
            ret = p - (char *)buf;
            goto out;
        }
        str += n;
        p += n;
    } while (*str != 0);
    ret = p - (char *)buf;
out:
    wipe_004D8168(&p, sizeof(p));
    DNAS_END(func_L39_004D8168, 0, func_L39_004BD350);
    return ret;
}
/* localdecomp:end func_L39_004D8168 */

/* localdecomp:start func_L39_004D83E0 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);
extern void func_00126280(s32);
extern s32 func_001262B0(s32);

typedef struct S_004D83E0 {
    /* 0x00000 */ u8 pad0[0x106D0];
    /* 0x106D0 */ s32 sema;
    /* 0x106D4 */ u8 pad1[0x1071C - 0x106D4];
    /* 0x1071C */ s32 (*recv)(s8 *, s32);
} S_004D83E0;

extern S_004D83E0 D_L39_00453FB0_004D83E0;

/* overwrites a local with random bytes before returning (as wipe_004D7770 does) */
static __inline__ void wipe_004D83E0(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

u8 *func_L39_004D83E0(u8 *buf, void *delim, s32 *count) {
    s32 ret;
    s8 *p;
    s32 n;
    s32 i;

    DNAS_BEGIN(func_L39_004D83E0, 0, func_L39_004BD350);
    p = (s8 *)buf;
    for (;;) {
        if (*count + 1 > 0x400) {
            ret = -0x6A;
            goto out;
        }
        func_00126280(D_L39_00453FB0_004D83E0.sema);
        n = D_L39_00453FB0_004D83E0.recv(p, 1);
        func_001262B0(D_L39_00453FB0_004D83E0.sema);
        ret = n;
        if (n < 0) goto out;
        (*count)++;
        for (i = 0; ((s8 *)delim)[i] != 0 && *p != ((s8 *)delim)[i]; i++) {
        }
        if (((s8 *)delim)[i] == 0) {
            ret = (s32)p;
            goto out;
        }
        p++;
    }
out:
    wipe_004D83E0(&p, sizeof(p));
    DNAS_END(func_L39_004D83E0, 0, func_L39_004BD350);
    return (u8 *)ret;
}
/* localdecomp:end func_L39_004D83E0 */

/* localdecomp:start func_L39_004D8660 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);
extern void func_00120D28(void *, void *, s32);
extern s32 func_00120884(void *);
extern void func_001209C0(void *, void *, s32);
extern long func_001221D0(void *, void *, s32);
extern s32 func_L39_004D8168(u8 *, char *, s32, s32 *);
extern u8 *func_L39_004D83E0(u8 *, void *, s32 *);
extern s32 func_L39_004D0C78(void);
extern u8 D_L39_00476150[];

static __inline__ void wipe_004D8660(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D8660(u8 *arg0, s32 *arg1) {
    char buf[0x100];
    s32 st = 0;
    char *p;
    char *s;
    u8 *q;
    s32 len;
    s32 n;
    s32 flag;

    DNAS_BEGIN(func_L39_004D8660, 0, func_L39_004BD350);
    func_00120D28(buf, DNAS_STRING("HTTP/1.0 200 OK\r\n"), 0x100);
    len = func_00120884(buf);
    DNAS_END(func_L39_004D8660, 0, func_L39_004BD350);
    n = func_L39_004D8168(arg0, buf, 0, &st);
    if (n < 0) {
        return n;
    }
    if (n == 0) {
        return -0x6A;
    }
    if (n < len) {
        return -0x6A;
    }
    q = arg0 + n;

    DNAS_BEGIN(func_L39_004D8660, 1, func_L39_004BD350);
    func_00120D28(buf, DNAS_STRING("Content-Length: "), 0x100);
    p = buf;
    len = func_00120884(buf);
    DNAS_END(func_L39_004D8660, 1, func_L39_004BD350);
    flag = 0;
    for (;;) {
        n = func_L39_004D8168(q, p, flag, &st);
        if (n < 0) {
            return n;
        }
        if (n == len) {
            q += n;
            break;
        }
        flag = 1;
        if (n == 0) {
            flag = 0;
            q++;
        } else {
            q += n;
        }
    }
    p = (char *)func_L39_004D83E0(q, D_L39_00476150, &st);
    n = func_001221D0(q, 0, 10);
    *arg1 = n;
    if (n > 0x8033) {
        return -0x6A;
    }
    q = (u8 *)p;

    DNAS_BEGIN(func_L39_004D8660, 2, func_L39_004BD350);
    s = DNAS_STRING("\r\n");
    func_00120D28(buf, s, 0x100);
    func_001209C0(buf, s, func_00120884(s));
    p = buf;
    len = func_00120884(buf);
    DNAS_END(func_L39_004D8660, 2, func_L39_004BD350);
    flag = 1;
    for (;;) {
        n = func_L39_004D8168(q, p, flag, &st);
        if (n < 0) {
            return n;
        }
        if (n == len) {
            q += n;
            break;
        }
        flag = 1;
        if (n == 0) {
            flag = 0;
            q++;
        } else {
            q += n;
        }
    }
    wipe_004D8660(buf, sizeof(buf));
    wipe_004D8660(p, sizeof(p));
    return q - arg0;
}
/* localdecomp:end func_L39_004D8660 */

/* localdecomp:start func_L39_004D8BC0 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);
extern u8 D_L39_00464638[];

s32 func_L39_004D8BC0(s32 arg0) {
    s32 ret;

    DNAS_BEGIN(func_L39_004D8BC0, 0, func_L39_004BD350);
    ret = func_L39_004D8110((u8 *)arg0, D_L39_00464638, 2) ? -1 : 0;
    DNAS_END(func_L39_004D8BC0, 0, func_L39_004BD350);
    return ret;
}
/* localdecomp:end func_L39_004D8BC0 */

/* localdecomp:start func_L39_004D8CB0 */
#include "dnas.h"

typedef struct {
    u16 lo : 7;
    u16 f : 1;
    u16 t : 4;
    u16 hi : 4;
} S_004D8CB0;

extern void func_L39_004BD350(s32, s32, s32, u32);

s32 func_L39_004D8CB0(s32 arg0, s32 arg1, s32 arg2) {
    S_004D8CB0 *p = (S_004D8CB0 *)(arg2 + 2);
    u8 h[2];
    s32 ret;

    DNAS_BEGIN(func_L39_004D8CB0, 0, func_L39_004BD350);
    ret = 0;
    if (p->t != 4) {
        ret = -1;
        if ((arg1 & ~1) == 0) {
            h[0] = 0;
            h[1] = 0;
            ((S_004D8CB0 *)h)->t = arg0;
            ((S_004D8CB0 *)h)->f = arg1;
            if (func_L39_004D8110((u8 *)p, h, 2) == 0) {
                ret = 1;
            }
        }
    }
    DNAS_END(func_L39_004D8CB0, 0, func_L39_004BD350);
    return ret;
}
/* localdecomp:end func_L39_004D8CB0 */

/* localdecomp:start func_L39_004D8E10 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);
extern u8 D_L39_004644F4[];

s32 func_L39_004D8E10(s32 arg0) {
    u8 *p = (u8 *)arg0 + 4;
    s32 ret;

    DNAS_BEGIN(func_L39_004D8E10, 0, func_L39_004BD350);
    ret = func_L39_004D8110(p, D_L39_004644F4, 0x20) ? -1 : 0;
    DNAS_END(func_L39_004D8E10, 0, func_L39_004BD350);
    return ret;
}
/* localdecomp:end func_L39_004D8E10 */

/* localdecomp:start func_L39_004D8F00 */
extern s32 func_L39_004D8BC0(s32);
extern s32 func_L39_004D8CB0(s32, s32, s32);
extern void func_L39_004B4520(s32);
extern s32 func_L39_004D8E10(s32);

s32 func_L39_004D8F00(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 *arg4) {
    s32 n;
    if (func_L39_004D8BC0(arg3) < 0) return -0x6A;
    n = func_L39_004D8CB0(arg0, arg1, arg3);
    if (n < 0) return -0x6A;
    if (n == 0) *arg4 = 1;
    if (arg0 == 5) {
        func_L39_004B4520(arg3 + 4);
    } else if (func_L39_004D8E10(arg3) < 0) {
        return -0x6A;
    }
    *arg2 = func_L39_004B5910(*(u32 *)(arg3 + 0x24));
    return 0x28;
}
/* localdecomp:end func_L39_004D8F00 */

/* localdecomp:start func_L39_004D8FD0 */
extern s32 D_L39_00464668[];
s32 func_L39_004CDC00(void);
s32 func_L39_004B4620(u8 *);
s32 func_L39_004B4700(u8 *);
s32 func_L39_004D8FD0(u8 *arg0, s32 arg1) {
    s32 ret = func_L39_004CDC00();
    u8 *p = arg0;
    s32 n;
    if (ret < 0) return ret;
    if (ret != 0 && !(D_L39_00464668[0] & 1)) p = arg0 + func_L39_004B4620(arg0);
    p += func_L39_004B4700(p);
    n = p - arg0;
    if (arg1 != n) return -0x6A;
    return n;
}
/* localdecomp:end func_L39_004D8FD0 */

INCLUDE_ASM("asm/levels", func_L39_004D9058);

/* localdecomp:start func_L39_004D9168 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);

typedef struct S_004D9168 {
    /* 0x00000 */ u8 pad0[0x10699];
    /* 0x10699 */ u8 f10699;
} S_004D9168;

extern S_004D9168 D_L39_00453FB0_004D9168;
s32 func_L39_004B49C0(u8 *);
s32 func_L39_004B4D90(u8 *, s32);
s32 func_L39_004B4E98(u8 *, s32);
s32 func_L39_004B5000(u8 *, s32);

s32 func_L39_004D9168(u8 *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    S_004D9168 *g;
    u8 *p = arg0 + func_L39_004B49C0(arg0);
    s32 n;
    s32 r;

    g = &D_L39_00453FB0_004D9168;
    if (g->f10699) {
        DNAS_BEGIN(func_L39_004D9168, 0, func_L39_004BD350);
        switch (g->f10699) {
        case 1:
            *arg3 = -0xC9;
            break;
        case 2:
            *arg3 = -0xCA;
            break;
        case 3:
            *arg3 = -0xCB;
            break;
        case 4:
            *arg3 = -0xCC;
            break;
        }
        DNAS_END(func_L39_004D9168, 0, func_L39_004BD350);
    } else {
        p += func_L39_004B4D90(p, arg2);
        r = func_L39_004B4E98(p, arg2);
        if (r < 0) return r;
        p += r;
        p += func_L39_004B5000(p, arg2);
    }
    n = p - arg0;
    if (arg1 != n) return -0x6A;
    return n;
}
/* localdecomp:end func_L39_004D9168 */

/* localdecomp:start func_L39_004D9330 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);

typedef struct S_004D9330 {
    /* 0x00000 */ u8 pad0[0x1069A];
    /* 0x1069A */ u8 f1069A;
} S_004D9330;

typedef struct S2_004D9330 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 fC;
} S2_004D9330;

extern S_004D9330 D_L39_00453FB0_004D9330;
s32 func_L39_004B5308(u8 *);
s32 func_L39_004B54C8(u8 *, S2_004D9330 *);
s32 func_L39_004B5630(u8 *, S2_004D9330 *);

s32 func_L39_004D9330(u8 *arg0, s32 arg1, S2_004D9330 *arg2, s32 *arg3) {
    S_004D9330 *g;
    u8 *p = arg0 + func_L39_004B5308(arg0);
    s32 n;
    s32 r;

    g = &D_L39_00453FB0_004D9330;
    if (g->f1069A >= 2) {
        DNAS_BEGIN(func_L39_004D9330, 0, func_L39_004BD350);
        switch (g->f1069A) {
        case 2:
            *arg3 = -0x2BD;
            break;
        case 3:
            *arg3 = -0x2BE;
            break;
        case 4:
            *arg3 = -0x2BF;
            break;
        }
        DNAS_END(func_L39_004D9330, 0, func_L39_004BD350);
    } else {
        switch (g->f1069A) {
        case 0:
            arg2->fC = 1;
            break;
        case 1:
            arg2->fC = 2;
            break;
        }
        r = func_L39_004B54C8(p, arg2);
        if (r < 0) return r;
        p += r;
        p += func_L39_004B5630(p, arg2);
    }
    n = p - arg0;
    if (arg1 != n) return -0x6A;
    return n;
}
/* localdecomp:end func_L39_004D9330 */

/* localdecomp:start func_L39_004D9508 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);
extern u8 D_L39_00464648;
s32 func_L39_004B53E8(u8 *);

s32 func_L39_004D9508(u8 *arg0, s32 arg1) {
    u8 *p = arg0 + func_L39_004B53E8(arg0);
    s32 n;

    if (D_L39_00464648) {
        DNAS_BEGIN(func_L39_004D9508, 0, func_L39_004BD350);
        DNAS_END(func_L39_004D9508, 0, func_L39_004BD350);
    }
    n = p - arg0;
    if (arg1 != n) return -0x6A;
    return n;
}
/* localdecomp:end func_L39_004D9508 */
