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
typedef struct O_0050F5B8 {
    s32 (**vt)(struct O_0050F5B8 *, s32 *, s32 *);
    u8 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} O_0050F5B8;
extern s32 func_L39_0050FDC8(s32 *, s32 *, s32 *, P_0050F5B8 *, s32, s32);
extern void func_L39_0050D780(s32 *);
extern s32 func_L39_00510008(s32 *, I_0050F5B8 *, void **, s32, s32, O_0050F5B8 *, s32, P_0050F5B8 *, s32 *);

/* localdecomp:start func_L39_0050FDC8 */
s32 func_L39_0050FDC8(s32 *total, s32 *tag, s32 *pos, P_0050F5B8 *out, s32 data, s32 size) {
    u8 *buf = (u8 *)data;
    u32 i;
    u32 j;
    u8 *p;
    u8 c;

    if (size == 0) {
        return 0x800;
    }
    *tag = buf[0];
    *pos = 0;
    if ((*tag & 0x1F) == 0x1F) {
        do {
            j = *pos;
            if ((u32)size < j + 2) {
                return 0x800;
            }
            c = buf[j + 1];
            *pos = j + 1;
        } while (c & 0x80);
    }
    i = *pos;
    if ((u32)size < i + 2) {
        return 0x800;
    }
    p = buf + i + 1;
    if ((s8)*p >= 0) {
        out->b = *p;
        *total = out->b + *pos + 2;
        out->a = buf + i + 2;
    } else if (*p == 0x80) {
        if (!(*tag & 0x20)) {
            return 0x801;
        }
        out->b = 0;
        out->a = buf + i + 2;
        *total = 0;
    } else if (*p == 0x81) {
        if ((u32)size < i + 3) {
            return 0x800;
        }
        out->b = p[1];
        *total = out->b + *pos + 3;
        out->a = buf + i + 3;
    } else if (*p == 0x82) {
        if ((u32)size < i + 4) {
            return 0x800;
        }
        out->b = (p[1] << 8) | p[2];
        *total = out->b + *pos + 4;
        out->a = buf + i + 4;
    } else if (*p == 0x83) {
        if ((u32)size < i + 5) {
            return 0x800;
        }
        out->b = (p[1] << 16) | (p[2] << 8) | p[3];
        *total = out->b + *pos + 5;
        out->a = buf + i + 5;
    } else if (*p == 0x84) {
        if ((u32)size < i + 6) {
            return 0x800;
        }
        out->b = (p[1] << 24) | (p[2] << 16) | (p[3] << 8) | p[4];
        *total = out->b + *pos + 6;
        out->a = buf + i + 6;
    } else {
        return 0x801;
    }
    if ((u32)size < (u32)*total) {
        return 0x800;
    }
    return 0;
}
/* localdecomp:end func_L39_0050FDC8 */

/* localdecomp:start func_L39_00510008 */
extern void func_L39_0050D780(s32 *);

s32 func_L39_00510008(s32 *len, I_0050F5B8 *h, void **tbl, s32 pos, s32 avail, O_0050F5B8 *s, s32 flags,
                      P_0050F5B8 *pin, s32 *out) {
    A_0050F5B8 st;
    u32 want = *len;
    u32 done = 0;
    u32 rem;
    s32 r;
    s32 err;
    s32 ret;

    *out = 0;
    if (s == 0) {
        return 0x808;
    }
    avail = s->f10 - s->f14;
    if ((h->flags & 0x820) != 0x800 || tbl[h->tag] == 0 || h->handler == 0) {
        return 0x804;
    }
    if ((u32)avail < (u32)*len) {
        *len = avail;
    }
    st.f0 = flags | 0x800;
    st.f4 = pos + 1;
    st.pr.a = pin->a;
    st.pr.b = *len - ((s32)pin->a - pos);
    st.f14 = pos;
    st.f18 = *len;
    st.f1C = 0;
    for (;;) {
        r = h->handler(&st, tbl[h->tag]);
        if (r != 0) {
            if (st.f1C != 0) {
                *out = st.f1C;
                func_L39_0050D780(out);
            }
            return r;
        }
        s->f14 += *len;
        pos += *len;
        done += *len;
        err = (*s->vt)(s, &pos, &avail);
        if (err != 0) {
            return err;
        }
        rem = want - done;
        if (st.f0 & 0x800) {
            if ((u32)avail < rem) {
                *len = avail;
            } else {
                st.f0 &= ~0x800;
                *len = rem;
            }
            st.f14 = pos;
            st.f18 = *len;
            st.pr.a = (u8 *)pos;
            st.pr.b = *len;
        } else {
            ret = 0x804;
            if (done == want) {
                *len = want;
                ret = 0;
            }
            return ret;
        }
    }
}
/* localdecomp:end func_L39_00510008 */
