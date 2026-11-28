#include "common.h"

/* localdecomp:start func_L39_004D4700 */
extern s32 func_L39_004D1DC8(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004D4700(s32 arg0, s32 arg1, s32 arg2)
{
    return func_L39_004D1DC8(arg1, arg2, arg2 + 8, arg2 + 16, arg0, arg2 + 24, 1);
}
/* localdecomp:end func_L39_004D4700 */

/* localdecomp:start func_L39_004D4730 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004D0C78(void);
extern s32 func_L39_004D1C18(s32, s32, s32, s32);
extern s32 func_L39_004D1EF8(s32, s32, s32, s32, s32, s32);
extern u8 D_L39_0046A240[];
extern u8 D_L39_0046A260[];

static __inline__ void copy_004D4730(u8 *dst, u8 *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

s32 func_L39_004D4730(u8 *out, u32 size, u32 *outlen, u8 *in, u32 len, s32 key, s32 a6, s32 a7, s32 a8, u8 a9)
{
    u8 buf[size];
    u8 k1[32];
    u8 k2[32];
    s32 ret;
    u32 pad;
    u8 *p;
    u8 *q;
    u8 *d;
    u8 *e;
    u8 *k2p;
    s32 i;
    u32 j;
    s32 k;
    u32 l;

    ret = -1;
    DNAS_BEGIN(func_L39_004D4730, 0, func_L39_004F7890);
    pad = (len + 7) / 8 * 8;
    *outlen = pad + 0x18;
    if (size < pad + 0x18) {
        *outlen = 0;
        goto wipe;
    }
    p = buf;
    q = buf;
    for (i = 0; i < 8; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    p[0] = p[0] * 4 + a9;
    p += 8;
    for (i = 0; i < 8; i++) {
        p[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    p += 8;
    if (func_L39_004D4700((s32)p, a6, a7) < 0) {
        ret = -1;
        goto wipe;
    }
    d = p + 8;
    for (l = 0; l < len; l++) {
        d[l] = in[l];
    }
    if (func_L39_004D1C18(key, a8, (s32)k1, 4) < 0) {
        ret = -1;
        goto wipe;
    }
    e = buf + 8;
    if (func_L39_004D1DC8((s32)e, (s32)(k1 + 0x18), (s32)(k1 + 8), (s32)(k1 + 0x10), (s32)e, (s32)k1, (*outlen - 8) / 8) < 0) {
        ret = -1;
        goto wipe;
    }
    for (k = 0; k < 8; k++) {
        out[k] = buf[k];
    }
    p = out + 8;
    copy_004D4730(p, buf + 16, pad + 8);
    d = out + pad + 16;
    for (k = 0; k < 8; k++) {
        d[k] = e[k];
    }
    if (func_L39_004D1EF8((s32)(out + 0x18), (s32)out, (s32)(out + 0x10), (s32)(out + 0x18), (s32)p, (*outlen - 0x18) / 8) < 0) {
        ret = -1;
        goto wipe;
    }
    k2p = k2;
    ret = -1;
    if (func_L39_004D1C18((s32)D_L39_0046A240, (s32)D_L39_0046A260, (s32)k2p, 4) < 0) {
        goto wipe;
    }
    if (func_L39_004D1DC8((s32)p, (s32)k2p, (s32)(k2p + 0x10), (s32)(k2p + 8), (s32)p, (s32)(k2p + 0x18), (*outlen - 8) / 8) >= 0) {
        ret = 0;
    }
wipe:
    for (j = 0; j < size; j++) {
        buf[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    q = k1;
    for (i = 0; i < 32; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    k2p = k2;
    for (j = 0; j < 32; j++) {
        k2p[j] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    DNAS_END(func_L39_004D4730, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D4730 */

LINKER_REMNANT("asm/levels", func_L39_004D4D10);

/* localdecomp:start func_L39_004D4D18 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_0012AA38(char *, s32);
extern s32 func_0012AE40(s32, s32, s32);
extern s32 func_0012ACC8(s32);

s32 func_L39_004D4D18(char *path) {
    s32 ret = -1;
    s32 fd;
    s32 size;

    DNAS_BEGIN(func_L39_004D4D18, 0, func_L39_004F7890);
    fd = func_0012AA38(path, 1);
    if (fd >= 0) {
        size = func_0012AE40(fd, 0, 2);
        if (size >= 0 && func_0012ACC8(fd) >= 0) {
            ret = size;
            fd = -1;
        }
        if (fd >= 0) {
            func_0012ACC8(fd);
        }
    }
    DNAS_END(func_L39_004D4D18, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D4D18 */

/* localdecomp:start func_L39_004D4E68 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004D1CA0(void *, void *, void *, s32);
extern s32 func_L39_004D1F30(void *, void *, void *, void *, s32);
extern s32 func_L39_004D0C78(void);
extern u8 D_L39_0046A270[];
extern u8 D_L39_0046A268[];

s32 func_L39_004D4E68(void *a0) {
    u8 buf[16];
    s32 ret = -1;
    u32 i;
    u8 *p;

    DNAS_BEGIN(func_L39_004D4E68, 0, func_L39_004F7890);
    if (func_L39_004D1CA0(D_L39_0046A270, D_L39_0046A268, buf, 1) >= 0) {
        if (func_L39_004D1F30(a0, buf, a0, D_L39_0046A268, 4) >= 0) {
            ret = 0;
        }
    }
    p = buf;
    for (i = 0; i < 8; i++) {
        p[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    DNAS_END(func_L39_004D4E68, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D4E68 */

/* localdecomp:start func_L39_004D5030 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004D4D18(char *);
extern s32 func_0012AA38(char *, s32);
extern s32 func_0012AE40(s32, s32, s32);
extern s32 func_0012B080(s32, void *, s32);
extern s32 func_0012ACC8(s32);

s32 func_L39_004D5030(char *path, void *a1, void *a2) {
    s32 fd = -1;
    s32 ret = -1;
    s32 size;

    DNAS_BEGIN(func_L39_004D5030, 0, func_L39_004F7890);
    size = func_L39_004D4D18(path);
    if (size >= 0) {
        fd = func_0012AA38(path, 1);
        if (fd >= 0 && func_0012AE40(fd, size - 0xA0, 0) >= 0
            && func_0012B080(fd, a1, 0x20) == 0x20
            && func_0012AE40(fd, size - 0x80, 0) >= 0
            && func_0012B080(fd, a2, 0x80) == 0x80
            && func_0012ACC8(fd) >= 0) {
            fd = -1;
            ret = 0;
        }
    }
    if (fd >= 0) {
        func_0012ACC8(fd);
    }
    DNAS_END(func_L39_004D5030, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004D5030 */

LINKER_REMNANT("asm/levels", func_L39_004D51E8);

/* localdecomp:start func_L39_004D51F0 */
extern s32 func_00129C38(s32, s32, s32);
extern s32 func_00127108(s32);

s32 func_L39_004D51F0(s32 *obj, s32 a1, s32 a2) {
    s32 i;
    s32 ret;

    i = 0;
    while (1) {
        if (++i > 1000) {
            ret = -1;
            break;
        }
        if (func_00129C38((s32)obj, a1, a2) < 0) {
            if (func_00127108(10000) < 0) {
                ret = -1;
                break;
            }
            continue;
        }
        if (obj[0x24 / 4] != 0) {
            ret = 0;
            break;
        }
        if (func_00127108(10000) < 0) {
            ret = -1;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004D51F0 */

/* localdecomp:start func_L39_004D5288 */
extern s32 func_00129E18(void *, s32, s32, s32, s32, void *, s32, s32, s32);
extern s32 func_00127108(s32);

/* call the RPC, retrying up to 100 times with a 10 ms delay between tries */
s32 func_L39_004D5288(void *cd, s32 fno, s32 mode, s32 send, s32 ssize, void *recv, s32 rsize, s32 end, s32 arg) {
    s32 i;
    s32 ret;

    i = 0;
    for (;;) {
        i++;
        if (i > 100) {
            ret = -1;
            break;
        }
        if (func_00129E18(cd, fno, mode, send, ssize, recv, rsize, end, arg) == 0) {
            ret = 0;
            break;
        }
        if (func_00127108(10000) < 0) {
            ret = -1;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004D5288 */

/* localdecomp:start func_L39_004D5370 */
extern u8 D_L39_00453FB0[];
extern s32 func_001262A0(s32);
extern s32 func_L39_004D5488(s32, s32, s32);

void func_L39_004D5370(s32 arg0, s32 arg1)
{
    u8 *p = D_L39_00453FB0;
    u8 *q = p + 0x10544;
    u32 i;

    (*(void (**)(void))(p + 0x10720))();
    for (i = 0; i < 0x20; i++) {
        q[i] = 0;
    }
    p = D_L39_00453FB0;
    func_001262A0(*(s32 *)(p + 0x106D4));
    func_L39_004D5488(0, arg1 ? -1 : *(s32 *)(p + 0x106B4), arg0);
}
/* localdecomp:end func_L39_004D5370 */

/* localdecomp:start func_L39_004D5420 */
extern u8 D_L39_00453FB0[];
extern void func_L39_004D5370(s32, s32);
extern void func_001262B0(s32);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);

void func_L39_004D5420(void)
{
    u8 *p = D_L39_00453FB0;

    func_L39_004D5370(0, 1);
    func_001262B0(*(s32 *)(p + 0x106C4));
    func_001262A0(*(s32 *)(p + 0x106C8));
    *(s32 *)(p + 0x106F4) = 0;
    func_00126280(*(s32 *)(p + 0x106C8));
}
/* localdecomp:end func_L39_004D5420 */

/* localdecomp:start func_L39_004D5488 */
extern u8 D_L39_00453FB0[];
extern void func_001262B0(s32);

typedef struct {
    u8 pad0[0x10684];
    u8 b0;
    u8 b1;
    u8 b2;
    u8 pad1[0x106B4 - 0x10687];
    s32 state;
    s32 pad2;
    s32 semB;
    s32 pad3;
    s32 semA;
    s32 lock;
} S_004D5488;

typedef struct {
    s32 count;
    s32 maxCount;
    s32 initCount;
    s32 waitThreads;
    s32 attr;
    u32 option;
} SEMA_004D5488;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} O_004D5488;


extern O_004D5488 D_L39_004646B0;
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern s32 func_001262D0(s32, SEMA_004D5488 *);


static __inline__ s32 word_004D5488(s32 c) {
    s32 b0 = ((S_004D5488 *)D_L39_00453FB0)->b0;
    s32 b1 = ((S_004D5488 *)D_L39_00453FB0)->b1;
    s32 b2 = ((S_004D5488 *)D_L39_00453FB0)->b2;

    return (((b1 << 4) | (b0 << 8)) & 0x3F0) | ((c << 24) | (b2 << 2));
}

s32 func_L39_004D5488(s32 op, s32 a1, s32 a2) {
    s32 ret = 0;
    SEMA_004D5488 sema;
    s32 i;
    s32 c;
    O_004D5488 *o = &D_L39_004646B0;

    func_001262A0(((S_004D5488 *)D_L39_00453FB0)->lock);
    switch (op) {
    case 0:
        ret = func_001262D0(((S_004D5488 *)D_L39_00453FB0)->semA, &sema);
        if (ret < 0) goto out;
        for (i = 0; i < sema.count; i++) ((s32 (*)(s32))func_001262B0)(((S_004D5488 *)D_L39_00453FB0)->semA);
        ret = func_001262D0(((S_004D5488 *)D_L39_00453FB0)->semB, &sema);
        if (ret < 0) goto out;
        for (i = 0; i < sema.count; i++) ((s32 (*)(s32))func_001262B0)(((S_004D5488 *)D_L39_00453FB0)->semB);
        if (a1 < 0) {
            o->f0 = 2;
            o->f4 = 0;
        } else if (a1 == 10 || a1 == 11) {
            if (a1 == 10) {
                o->f0 = 6;
            } else if (a1 == 11) {
                o->f0 = 7;
            }
            o->f4 = a2;
        } else {
            switch (a1) {
            case 4: c = 1; o->f0 = 5; break;
            case 8: c = 2; o->f0 = 5; break;
            case 7: c = 3; o->f0 = 5; break;
            case 13: c = 4; o->f0 = 5; break;
            default: ret = -1; goto out;
            }
            o->f4 = word_004D5488(c);
        }
        o->f8 = 0;
        break;
    case 1:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 0) { ret = -1; goto out; }
        break;
    case 2:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 1) { ret = -1; goto out; }
        break;
    case 3:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 2) { ret = -1; goto out; }
        o->f8 = 2;
        break;
    case 4:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 3) { ret = -1; goto out; }
        break;
    case 5:
        switch (((S_004D5488 *)D_L39_00453FB0)->state) {
        case 4:
            o->f8 = 3;
            break;
        case 7:
            o->f0 = 8;
            o->f8 = 7;
            o->f4 = word_004D5488(3);
            break;
        default:
            ret = -1;
            goto out;
        }
        break;
    case 7:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 5) { ret = -1; goto out; }
        o->f8 = 5;
        break;
    case 12:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 4) { ret = -1; goto out; }
        o->f8 = 3;
        break;
    case 13:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 12) { ret = -1; goto out; }
        o->f8 = 8;
        break;
    case 6:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 4) { ret = -1; goto out; }
        o->f8 = 3;
        break;
    case 8:
        if (((S_004D5488 *)D_L39_00453FB0)->state != 6) { ret = -1; goto out; }
        o->f8 = 4;
        break;
    }
    ((S_004D5488 *)D_L39_00453FB0)->state = op;
out:
    func_00126280(((S_004D5488 *)D_L39_00453FB0)->lock);
    return ret;
}
/* localdecomp:end func_L39_004D5488 */

/* localdecomp:start func_L39_004D58E0 */
extern s32 D_L39_00464694[];

s32 func_L39_004D58E0(void) {
    return D_L39_00464694[0] > 0;
}
/* localdecomp:end func_L39_004D58E0 */

/* localdecomp:start func_L39_004D58F0 */
extern s32 D_L39_00464698[];

s32 func_L39_004D58F0(void) {
    return D_L39_00464698[0] > 0;
}
/* localdecomp:end func_L39_004D58F0 */

/* localdecomp:start func_L39_004D5900 */
extern s32 D_L39_00464670[];
extern void func_00126280(s32);

s32 func_L39_004D5900(void) {
    s32 r;

    do {
        func_00126280(D_L39_00464670[0]);
        r = 0;
    } while (0);
    return r;
}
/* localdecomp:end func_L39_004D5900 */

/* localdecomp:start func_L39_004D5928 */
extern s32 D_L39_00464674[];
extern void func_00126280(s32);

s32 func_L39_004D5928(void) {
    do {
        func_00126280(D_L39_00464674[0]);
    } while (0);
    return 0;
}
/* localdecomp:end func_L39_004D5928 */

/* localdecomp:start func_L39_004D5950 */
extern void func_L39_004B4AA0(void *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D5950(s32 arg) {
    u8 buf[16];
    u8 *p;
    u32 i;
    s32 ok;
    func_L39_004B4AA0(buf);
    ok = ((*(u16 *)buf >> 11) & 7) == arg;
    p = buf;
    for (i = 0; i < 2; i++) {
        p[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    return ok;
}
/* localdecomp:end func_L39_004D5950 */

/* localdecomp:start func_L39_004D5A40 */
extern void func_L39_004B4AA0(void *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D5A40(s32 arg) {
    u8 buf[16];
    u8 *p;
    u32 i;
    s32 ok;
    func_L39_004B4AA0(buf);
    ok = ((*(u16 *)buf >> 8) & 7) == arg;
    p = buf;
    for (i = 0; i < 2; i++) {
        p[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    return ok;
}
/* localdecomp:end func_L39_004D5A40 */

/* localdecomp:start func_L39_004D5B30 */
extern s32 D_L39_004646A0[];

s32 func_L39_004D5B30(void) {
    return D_L39_004646A0[0] > 0;
}
/* localdecomp:end func_L39_004D5B30 */

/* localdecomp:start func_L39_004D5B40 */
extern s32 D_L39_004646A4[];

s32 func_L39_004D5B40(void) {
    return D_L39_004646A4[0] > 0;
}
/* localdecomp:end func_L39_004D5B40 */

/* localdecomp:start func_L39_004D5B50 */
typedef struct S_004D5B50 {
    u8 pad0[0x106C8];
    s32 x106C8;
    u8 pad106CC[0x106D8 - 0x106CC];
    s32 x106D8;
    u8 pad106DC[0x106F8 - 0x106DC];
    s32 x106F8;
} S_004D5B50;
extern S_004D5B50 D_L39_00453FB0_004D5B50;
extern s32 func_00126150(void);
extern s32 func_L01_003EC898_004D5B50(s32);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern s32 func_L39_004B3E10(void);

s32 func_L39_004D5B50(void) {
    S_004D5B50 *g;

    if (func_L01_003EC898_004D5B50(func_00126150()) < 0) {
        return 0;
    }
    g = &D_L39_00453FB0_004D5B50;
    for (;;) {
        func_001262A0(g->x106D8);
        func_001262A0(g->x106C8);
        g->x106F8 = 1;
        func_00126280(g->x106C8);
        func_L39_004B3E10();
    }
}
/* localdecomp:end func_L39_004D5B50 */

/* localdecomp:start func_L39_004D5BE8 */
/* The DNAS client's worker loop: three start-up calls through the context's function table, then a
   state machine on the context's state (0x106B4), with one error handler and one cancel path. */
typedef struct S_004D5BE8 {
    u8 pad0[0x200];
    s32 x200;
    u8 pad204[0x10684 - 0x204];
    u8 b10684;
    u8 b10685;
    u8 b10686;
    u8 pad10687;
    union {
        u64 d;
        struct {
            s32 lo;
            s32 hi;
        } w;
    } x10688;
    s32 x10690;
    s32 x10694;
    u8 pad10698[0x106B4 - 0x10698];
    s32 state;
    s32 pad106B8;
    s32 sema[8];
    s32 err;
    s32 x106E0;
    s32 x106E4;
    s32 x106E8;
    u8 pad106EC[0x106F8 - 0x106EC];
    s32 x106F8;
    s32 pad106FC;
    s32 x10700;
    s32 x10704;
    u8 pad10708[0x10710 - 0x10708];
    void *fn[9];
} S_004D5BE8;

typedef struct SEMA_004D5BE8 {
    s32 count;
    s32 maxCount;
    s32 initCount;
    s32 waitThreads;
    s32 attr;
    u32 option;
} SEMA_004D5BE8;

extern S_004D5BE8 D_L39_00453FB0_004D5BE8;

s32 func_L39_004D5BE8(void) {
    extern s32 func_001262B0_004D5BE8(s32);
    extern s32 func_001262D0_004D5BE8(s32, SEMA_004D5BE8 *);
    extern s32 func_L39_004D5B30(void);
    extern s32 func_L39_004D5B40(void);
    extern void func_L39_004D5370(s32, s32);
    extern void func_L39_004D5420(void);
    extern s32 func_L39_004D5A40(s32);
    extern s32 func_L39_004D7B38(s32, s32, s32);
    extern s32 func_L39_004D98F8(s32, s32, s32);
    SEMA_004D5BE8 sema;
    s32 ret;
    s32 err;
    s32 i;

    err = 0;
    ret = ((s32 (*)(void))D_L39_00453FB0_004D5BE8.fn[0])();
    if (ret < 0) {
        D_L39_00453FB0_004D5BE8.err = ret;
        func_00126280(D_L39_00453FB0_004D5BE8.sema[0]);
        return ret;
    }
    ret = ((s32 (*)(S_004D5BE8 *, s32))D_L39_00453FB0_004D5BE8.fn[7])(&D_L39_00453FB0_004D5BE8, 0x1BB);
    if (ret < 0) {
        D_L39_00453FB0_004D5BE8.err = ret;
        func_00126280(D_L39_00453FB0_004D5BE8.sema[0]);
        return ret;
    }
    ret = ((s32 (*)(s32))D_L39_00453FB0_004D5BE8.fn[8])(1);
    if (ret < 0) {
        D_L39_00453FB0_004D5BE8.err = ret;
        func_00126280(D_L39_00453FB0_004D5BE8.sema[0]);
        return ret;
    }
    D_L39_00453FB0_004D5BE8.x200 = 1;
    for (;;) {
        switch ((u32)D_L39_00453FB0_004D5BE8.state) {
        case 0:
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[3]);
            D_L39_00453FB0_004D5BE8.x106E4++;
            func_00126280(D_L39_00453FB0_004D5BE8.sema[3]);
            if (func_001262D0_004D5BE8(D_L39_00453FB0_004D5BE8.sema[6], &sema) < 0) {
                goto error;
            }
            for (i = 0; i < sema.count; i++) {
                func_001262B0_004D5BE8(D_L39_00453FB0_004D5BE8.sema[6]);
            }
            func_00126280(D_L39_00453FB0_004D5BE8.sema[6]);
            func_00126280(D_L39_00453FB0_004D5BE8.sema[0]);
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[1]);
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[3]);
            D_L39_00453FB0_004D5BE8.x106E4--;
            func_00126280(D_L39_00453FB0_004D5BE8.sema[3]);
            if (func_L39_004D5B30() > 0) {
                goto exit;
            }
            if (func_L39_004D5B40() > 0) {
                func_L39_004D5420();
                break;
            }
            if (func_L39_004D5488(1, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 1:
            if (D_L39_00453FB0_004D5BE8.x10704 == -0x25B) {
                func_001262A0(D_L39_00453FB0_004D5BE8.sema[3]);
                D_L39_00453FB0_004D5BE8.x10704 = 0;
                func_00126280(D_L39_00453FB0_004D5BE8.sema[3]);
            }
            err = func_L39_004D7B38(0, 0, 0);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            if (func_L39_004D5488(2, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 2:
            err = func_L39_004D98F8(5, 0, 0);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err == -0x6E) {
                if (func_L39_004D5488(0, 4, 0) < 0) {
                    err = -0x6B;
                    goto error;
                }
                if (func_L39_004D5950(1) > 0) {
                    goto error;
                }
                D_L39_00453FB0_004D5BE8.b10686 = 1;
                D_L39_00453FB0_004D5BE8.b10684 = 1;
                D_L39_00453FB0_004D5BE8.b10685 = 2;
                D_L39_00453FB0_004D5BE8.x10704 = 0x1000124;
                break;
            }
            if (err == -0x6D) {
                D_L39_00453FB0_004D5BE8.x10688.d &= ~0xC000;
                D_L39_00453FB0_004D5BE8.state = 0;
                if (func_L39_004D5488(1, 0, 0) < 0) {
                    err = -0x6B;
                    goto error;
                }
                break;
            }
            if (err < 0) {
                goto error;
            }
            if (func_L39_004D5488(3, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 3:
            if (func_L39_004D5950(2) == 0 && func_L39_004D5950(3) == 0) {
                err = func_L39_004D7B38(1, 0, 0);
                if (func_L39_004D5B40() > 0) {
                    err = -0x259;
                    func_L39_004D5420();
                    break;
                }
                if (err < 0) {
                    goto error;
                }
            } else {
                err = func_L39_004D7B38(1, 0, D_L39_00453FB0_004D5BE8.x106E0);
                if (func_L39_004D5B40() > 0) {
                    err = -0x259;
                    func_L39_004D5420();
                    break;
                }
                if (err < 0) {
                    goto error;
                }
            }
            if (func_L39_004D5488(4, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 4:
            if (func_L39_004D5950(2) == 0 && func_L39_004D5950(3) == 0) {
                err = func_L39_004D98F8(6, 0, 0);
                if (func_L39_004D5B40() > 0) {
                    err = -0x259;
                    func_L39_004D5420();
                    break;
                }
                if (err < 0) {
                    goto error;
                }
            } else {
                err = func_L39_004D98F8(6, 0, 1);
                if (func_L39_004D5B40() > 0) {
                    err = -0x259;
                    func_L39_004D5420();
                    break;
                }
                if (err < 0) {
                    goto error;
                }
            }
            if (func_L39_004D5950(2) > 0) {
                func_L39_004D5370(0, 0);
                break;
            }
            if (func_L39_004D5950(3) > 0) {
                func_L39_004D5370(0, 0);
                break;
            }
            if (func_L39_004D5950(4) > 0) {
                if (func_L39_004D5488(5, 0, 0) < 0) {
                    err = -0x6B;
                    goto error;
                }
                break;
            }
            if (func_L39_004D5950(1) > 0) {
                if (func_L39_004D5488(12, 0, 0) < 0) {
                    err = -0x6B;
                    goto error;
                }
                break;
            }
            if (func_L39_004D5950(5) > 0) {
                if (func_L39_004D5488(6, 0, 0) < 0) {
                    err = -0x6B;
                    goto error;
                }
            }
            break;
        case 5:
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[3]);
            D_L39_00453FB0_004D5BE8.x106E8++;
            func_00126280(D_L39_00453FB0_004D5BE8.sema[3]);
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[2]);
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[3]);
            D_L39_00453FB0_004D5BE8.x106E8--;
            func_00126280(D_L39_00453FB0_004D5BE8.sema[3]);
            if (func_L39_004D5B30() > 0) {
                goto exit;
            }
            if (func_L39_004D5B40() > 0) {
                func_L39_004D5420();
                break;
            }
            if (func_L39_004D5A40(2) == 0) {
                break;
            }
            err = func_L39_004D7B38(3, D_L39_00453FB0_004D5BE8.x10690, D_L39_00453FB0_004D5BE8.x106E0);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            if (func_L39_004D5488(7, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 7:
            err = func_L39_004D98F8(7, D_L39_00453FB0_004D5BE8.x10690, D_L39_00453FB0_004D5BE8.x106E0);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            if (D_L39_00453FB0_004D5BE8.x106E0 > 0) {
                func_L39_004D5370(0, 0);
                break;
            }
            if (func_L39_004D5488(5, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 12:
            err = func_L39_004D7B38(8, D_L39_00453FB0_004D5BE8.x10694, 1);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            if (func_L39_004D5488(13, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 13:
            err = func_L39_004D98F8(13, D_L39_00453FB0_004D5BE8.x10694, 1);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            func_L39_004D5370(0, 0);
            break;
        case 6:
            err = func_L39_004D7B38(2, D_L39_00453FB0_004D5BE8.x10688.w.hi, 1);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            if (func_L39_004D5488(8, 0, 0) < 0) {
                err = -0x6B;
                goto error;
            }
            break;
        case 8:
            err = func_L39_004D98F8(12, D_L39_00453FB0_004D5BE8.x10688.w.hi, 1);
            if (func_L39_004D5B40() > 0) {
                err = -0x259;
                func_L39_004D5420();
                break;
            }
            if (err < 0) {
                goto error;
            }
            func_L39_004D5370(0, 0);
            break;
        case 10:
        case 11:
            func_L39_004D5370(err, 0);
            break;
        case 9:
            break;
        }
        if (D_L39_00453FB0_004D5BE8.x106F8 != 0) {
            func_001262A0(D_L39_00453FB0_004D5BE8.sema[3]);
            D_L39_00453FB0_004D5BE8.x10700 = 7;
            D_L39_00453FB0_004D5BE8.x10704 = -0x25B;
            D_L39_00453FB0_004D5BE8.x106F8 = 0;
            func_00126280(D_L39_00453FB0_004D5BE8.sema[3]);
        }
        continue;
    error:
        if ((err >= -0x2BB && err <= -0x258) || err >= -0x63) {
            func_L39_004D5488(11, 0, 0);
        } else {
            if (err == -0x6E) {
                err = -0x2C0;
            }
            func_L39_004D5488(10, 0, 0);
        }
    }
exit:
    ret = ((s32 (*)(void))D_L39_00453FB0_004D5BE8.fn[5])();
    func_00126280(D_L39_00453FB0_004D5BE8.sema[4]);
    return ret;
}
/* localdecomp:end func_L39_004D5BE8 */
